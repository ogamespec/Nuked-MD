#pragma once
#include "common.h"

typedef struct {
    staticcnt_t dff1;
    staticcnt_t dff2;
    staticcnt_t dff3;
    int w1;
    int w2;
    int w3;
    int w4;
    int w5;
    staticcnt_t dff4;
    staticcnt_t dff5;
    staticcnt_t dff6;
    staticcnt_t dff7;
    int w6;
    int w7;
    int w8;
    int w9;
    sdffr2_t dff8;
    int w10;
    int w11;
    sdffr_t dff9;
    int w12;
    delaychain_t d1; // 6 xor
    int w14;
    int w15;
    sdff_t dff10;
    int w16;
    int w17;
    int w18;
    int w19;
    int w20;
    int w21;
    int w22;
    int w23;
    int w24;
    int w25;
    sdff_t dff11;
    sdff_t dff12;
    int w26;
    int w27;
    int w28;
    int w29;
    int w30;
    int w31;
    int w32;
    int w33;
    int w34;
    int w35;
    sdff_t dff13;
    int w36;
    sdffr_t dff14;
    int w37;
    int w38;
    int w39;
    sdffr2_t dff15;
    int w40;
    int w41;
    int w42;
    int w43;
    sdff_t dff16;
    int w44;
    int w45;
    int w46;
    int w47;
    int w48;
    int w49;
    sdffr2_t dff17;
    int w50;
    sdff_t dff18;
    int w51;
    int w52;
    int w53;
    int w54;
    int w55;
    int w56;
    int w57;
    int w58;
    int w59;
    int w60;
    int w61;
    int w62;
    int w63;
    int w64;
    int w65;
    int w66;
    int w67;
    int w68;
    sdffr2_t dff19;
    int w69;
    int w70;
    int w71;
    int w72;
    sdffr2_t dff20;
    int w73;
    int w74;
    int w75;
    int w76;
    int w77;
    int w78;
    int w79;
    sdff_t dff21;
    sdff_t dff22;
    int w80;
    int w81;
    int w82;
    int w83;
    int w84;
    int w85;
    int w86;
    int w87;
    sdffr_t dff23;
    int w88;
    int w89;
    int w90;
    int w91;
    int w92;
    int w93;
    int w94;
    int w95;
    int w96;
    int w97;
    int w98;
    int w99;
    int w100;
    int w101;
    int w102;
    int w103;
    sdff_t dff24;
    sdffr_t dff25;
    int w104;
    int w105;
    int w106;
    int w107;
    int w108;
    int w109;
    int w110;
    int w111;
    int w112;
    int w113;
    int w114;
    int w115;
    int w116;
    int w117;
    int w118;
    int w119;
    int w120;
    int w121;
    int w122;
    int w123;
    int w124;
    int w125;
    int w126;
    int w127;
    int w128;
    int w129;
    int w130;
    sdffr_t dff26;
    sdff_t dff27;
    int w131;
    int w132;
    int w133;
    int w134;
    int w135;
    sdff_t dff28;
    int w136;
    int w137;
    int w138;
    int w139;
    int w140;
    int w141;
    int w142;
    int w143;
    int w144;
    int w145;
    sdff_t dff29;
    int w146;
    int w147;
    int w148;
    int w149;
    int w150;
    int w151;
    int w152;
    int w153;
    int w154;
    int w155;
    int w156;
    int w157;
    int w158;
    int w159;
    int w160;
    int w161;
    int w162;
    int w163;
    int w164;
    int w165;
    int w166;
    int w167;
    sdff_t dff30;
    int w168;
    int w169;
    int w170;
    sdffr_t dff31;
    int w171;
    int w172;
    int w173;
    int w174;
    int w175;
    int w176;
    int w177;
    int w178;
    int w179;
    int w180;
    int w181;
    int w182;
    sdff_t dff32;
    sdffr2_t dff33;
    int w183;
    int w184;
    int w185;
    int w186;
    int w187;
    int w188;
    int w189;
    int w190;
    int w191;
    int w192;
    int w193;
    int w194;
    int w195;
    int w196;
    int w197;
    int w198;
    int w199;
    int w200;
    int w201;
    int w202;
    int w203;
    int w204;
    int w205;
    int w206;
    int w207;
    int w208;
    int w209;
    int w210;
    int w211;
    int w212;
    int w213;
    int w214;
    int w215;
    int w216;
    int w217;
    int w218;
    int w219;
    int w220;
    int w221;
    sdff_t dff34;
    int w222;
    int w223;
    int w224;
    sdffr_t dff35;
    sdffr_t dff36;
    sdffr_t dff37;
    sdffr_t dff38;
    sdffr_t dff39;
    sdffr_t dff40;
    sdffr_t dff41;
    sdffr_t dff42;
    sdffr_t dff43;
    int w225;
    int w226;
    int w227;
    int w228;
    int w229;
    int w230;
    sdff_t dff44;
    int w231;
    int w232;
    int w233;
    int w234;
    int w235;
    int w236;
    int w237;
    int w238;
    int w239;
    int w240;
    int w241;

    int ext_w1;
    int ext_w2;
    int ext_w3;
    int ext_w4;
    int ext_w5;

    int tm_w1;
    int tm_w2;
    int tm_w3;
    int tm_w4;
    int tm_w5;
    int tm_w6;
} arbiter_t;
