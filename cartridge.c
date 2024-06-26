#include <stdio.h>
#include <string.h>
#include "cartridge.h"
#include "fc1004.h"
#include "md.h"
#include "savestate.h"

unsigned short rom[ROM_SIZE * 2];   // *2 to support sega mapper (up to 8mb games)

int mapper_enable;
int mapper_pages[8];

int m3_mapper_enable;
int m3_mapper_data;
int m3_mapper_page[3];
unsigned char m3_mapper_ram[0x4000];

extern fc1004_t ym;
extern md_state md;

int cart_load_game_rom(char *filename, int _m3)
{
    size_t i, ret;
    FILE* romfile;

    romfile = fopen(filename, "rb");
    if (!romfile)
        return 1;

    fseek(romfile, 0, SEEK_END);
    size_t siz = ftell(romfile);
    rewind(romfile);

    if (!_m3)
    {
        if (siz > ROM_SIZE * 2)
        {
            mapper_enable = 1;
            if (siz > ROM_SIZE * 4)
                siz = ROM_SIZE * 4;
            for (i = 0; i < 8; i++)
                mapper_pages[i] = (int)i;
        }
        else
        {
            mapper_enable = 0;
        }
    }
    else
    {
        if (siz > 0x8000)
        {
            m3_mapper_enable = 1;
            m3_mapper_page[0] = 0;
            m3_mapper_page[1] = 1 << 14;
            m3_mapper_page[2] = 2 << 14;
        }
        else
        {
            m3_mapper_enable = 0;
        }
    }

    memset(rom, 0, sizeof(rom));
    ret = fread(rom, 1, siz, romfile);
    if (ret < siz)
    {
        fclose(romfile);
        return 1;
    }
    for (i = 0; i < ROM_SIZE * 2; i++)
        rom[i] = short_swap(rom[i]);
    fclose(romfile);
    return 0;
}

void cart_handle_md(void)
{               
    // MD
    if (!ym.o_ce0)
    {
        if (!ym.o_cas0)
        {
            if (mapper_enable)
            {
                int address = md.vaddress & 0x3ffff;
                int page = (md.vaddress >> 18) & 7;
                int mapped_address = address | (mapper_pages[page] << 18);
                mapped_address &= 0x3fffff;
                md.vdata = rom[mapped_address];
            }
            else
                md.vdata = rom[md.vaddress & 0x1fffff];
        }
    }
    // mapper
    if (mapper_enable)
    {
        if (!ym.arb.ext_time && !ym.o_lwr)
        {
            switch (md.vaddress & 0x7f)
            {
                case 0x79:
                    mapper_pages[1] = md.vdata & 255;
                    break;
                case 0x7a:
                    mapper_pages[2] = md.vdata & 255;
                    break;
                case 0x7b:
                    mapper_pages[3] = md.vdata & 255;
                    break;
                case 0x7c:
                    mapper_pages[4] = md.vdata & 255;
                    break;
                case 0x7d:
                    mapper_pages[5] = md.vdata & 255;
                    break;
                case 0x7e:
                    mapper_pages[6] = md.vdata & 255;
                    break;
                case 0x7f:
                    mapper_pages[7] = md.vdata & 255;
                    break;
            }
        }
    }
}

void cart_handle_m3(void)
{
    // M3
    md.vaddress &= ~0x700000;
    md.vaddress |= 0x500000;
    if (!(md.vaddress & 0x20000)) // cart chip enable
    {
        if (!ym.o_cas0)
        {
            int address;
            int enable = 0;
            if (!m3_mapper_enable)
            {
                address = md.vaddress & 0x7fff;
                enable = !ym.o_ce0;
            }
            else
            {
                address = md.vaddress & 0x3fff;
                if (!ym.o_ce0)
                {
                    address |= m3_mapper_page[(md.vaddress >> 14) & 1];
                    enable = 1;
                }
                else if (!ym.arb.ext_cas2)
                {
                    if (m3_mapper_data & 8)
                    {
                        md.vdata &= ~0xff;
                        md.vdata |= m3_mapper_ram[address];
                    }
                    else
                    {
                        address |= m3_mapper_page[2];
                        enable = 1;
                    }
                }
                address &= 0x3fffff;
            }
            if (enable)
            {
                md.vdata &= ~0xff;
                if (address & 1)
                    md.vdata |= rom[address >> 1] & 255;
                else
                    md.vdata |= (rom[address >> 1] >> 8) & 255;
            }
        }
        if (!ym.o_lwr)
        {
            if (m3_mapper_enable)
            {
                if (!ym.arb.ext_cas2)
                {
                    if (m3_mapper_data & 8)
                    {
                        m3_mapper_ram[md.vaddress & 0x3fff] = md.vdata & 0xff;
                    }
                }
                if ((md.vaddress & 0xffff) >= 0xfffc)
                {
                    int page;

                    // GPGX
                    page = md.vdata & 15;
                    if (m3_mapper_data & 3)
                        page = (page + ((4 - (m3_mapper_data & 3)) << 3)) & 15;
                    if ((md.vaddress & 3) == 0)
                        m3_mapper_data = md.vdata & 0xff;
                    if ((md.vaddress & 3) == 1)
                        m3_mapper_page[0] = page << 14;
                    if ((md.vaddress & 3) == 2)
                        m3_mapper_page[1] = page << 14;
                    if ((md.vaddress & 3) == 3)
                        m3_mapper_page[2] = page << 14;
                }
            }
        }
    }
}

int cart_save(FILE* f)
{
    if (save_blob(&rom, sizeof(rom), f))
        return -1;
    if (save_blob(&mapper_enable, sizeof(mapper_enable), f))
        return -1;
    if (save_blob(&mapper_pages, sizeof(mapper_pages), f))
        return -1;
    if (save_blob(&m3_mapper_enable, sizeof(m3_mapper_enable), f))
        return -1;
    if (save_blob(&m3_mapper_data, sizeof(m3_mapper_data), f))
        return -1;
    if (save_blob(&m3_mapper_page, sizeof(m3_mapper_page), f))
        return -1;
    if (save_blob(&m3_mapper_ram, sizeof(m3_mapper_ram), f))
        return -1;
    return 0;
}

int cart_load(FILE* f)
{
    if (load_blob(&rom, sizeof(rom), f))
        return -1;
    if (load_blob(&mapper_enable, sizeof(mapper_enable), f))
        return -1;
    if (load_blob(&mapper_pages, sizeof(mapper_pages), f))
        return -1;
    if (load_blob(&m3_mapper_enable, sizeof(m3_mapper_enable), f))
        return -1;
    if (load_blob(&m3_mapper_data, sizeof(m3_mapper_data), f))
        return -1;
    if (load_blob(&m3_mapper_page, sizeof(m3_mapper_page), f))
        return -1;
    if (load_blob(&m3_mapper_ram, sizeof(m3_mapper_ram), f))
        return -1;
    return 0;
}
