#pragma once

typedef struct
{
    int i_clk;
    int i_data;
    int i_reset;
} t84c00_input_t;

typedef struct
{
    t84c00_input_t input;

    int clk_p;
    int clk_n;

    int w1;
    int w2;
    int w3;
    int w42;
    int w44;
    int w145;
    int w146;
    int w147;

    int pla[108];

    int w74;
    int w82;
    int w90;
    int w92;
    int w96;
    
    int w55;

    int w41;
    int w131;
    int w127;
    int w107;

    int w50;
    int w51;
    int w52;

    int tm_w1;
    int tm_w2;
    int tm_w3;
    int tm_w4;
    int tm_w5;
    int tm_w6;
    int tm_w7;

    int l1;
    int l14;
    int l15;
    int l19;

    int w56;


    int o_data;
    int o_data_z;

} t84c00_t;


