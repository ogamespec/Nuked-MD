#pragma once

enum {
    state_0 = 0,
    state_1,
    state_z
};

typedef struct {
    // input
    int i_int;
    int i_nmi;
    int i_wait;
    int i_reset;
    int i_busrq;

    // output

    int ext_data_i;
    int ext_data_o;
    int o_mreq;
    int o_halt;
    int o_iorq;
    int o_rd;
    int o_wr;
    int o_busak;
    int o_m1;
    int o_rfsh;

    // state
    int w1;
    int w2;
    int l1;
    int w3;
    int w4;
    int w5;
    int w6;
    int w7;
    int w8;
    int w9;
    int l2;
    int w10;
    int w11;
    int w12;
    int l3;
    int halt;
    int w13;
    int w14;
    int w15;
    int w16;
    int l4;
    int w17;
    int w18;
    int w19;
    int w20;
    int w21;
    int w22;
    int w23;
    int l5;
    int w24;
    int l6;
    int w25;
    int w26;
    int w27;
    int w28;
    int l7;
    int w29;
    int w30;
    int w31;
    int l8;
    int w32;
    int l9;
    int w33;
    int l10;
    int l11;
    int w34;
    int l12;
    int w35;
    int w36;
    int w37;
    int w38;
    int w39;
    int w40;
    int w41;
    int w42;
    int w43;
    int l13;
    int w44;
    int l14;
    int l15;
    int w45;
    int w46;
    int w192;
    int w47;
    int l16;
    int w48;
    int l17;
    int l18;
    int w49;
    int w50;
    int w51;
    int w52;
    int l19;
    int w53;
    int l20;
    int w54;
    int w55;
    int w56;
    int w57;
    int w58;
    int w59;
    int w60;
    int l21;
    int w61;
    int w62;
    int l22;
    int w63;
    int l23;
    int l24;
    int w64;
    int w65;
    int w66;
    int w67;
    int w68;
    int l25;
    int w69;
    int w70;
    int w71;
    int l26;
    int w72;
    int w73;
    int w74;
    int w75;
    int l27;
    int w76;
    int w77;
    int w78;
    int w79;
    int l28;
    int w80;
    int w81;
    int w82;
    int w83;
    int w84;
    int w85;
    int w86;
    int w87;
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
    int l29;
    int w104;
    int w105;
    int w106;
    int w107;
    int w108;
    int l30;
    int w109;
    int w110;
    int w111;
    int w112;
    int w113;
    int l31;
    int w114;
    int w115;
    int w116;
    int w117;
    int w118;
    int w119;
    int l32;
    int w120;
    int w121;
    int w122;
    int l33;
    int w123;
    int w124;
    int l34;
    int w125;
    int w126;
    int w127;
    int w128;
    int l35;
    int w129;
    int w130;
    int w131;
    int w132;
    int l36;
    int w133;
    int w134;
    int w135;
    int w136;
    int w137;
    int w138;
    int w139;
    int w140;
    int w141;
    int w142;
    int w143;
    int w144;
    int l37;
    int l38;
    int w145;
    int w146; // bus 1
    int w147;
    int pla[99];
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
    int w168;
    int w169;
    int w170;
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
    int w183;
    int w184;
    int w185;
    int w186;
    int w187;
    int w188;
    int w189;
    int w190;
    int w191;
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
    int l39;
    int w205;
    int w206;
    int w207;
    int w208;
    int w209;
    int l40;
    int w210;
    int w211;
    int w212;
    int w213;
    int w214;
    int l41;
    int w215;
    int w216;
    int w217;
    int w218;
    int w219;
    int w220;
    int w221;
    int w222;
    int w223;
    int w224;
    int w225;
    int w226;
    int w227;
    int l42;
    int w228;
    int w229;
    int w230;
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
    int w242;
    int w243;
    int w244;
    int w245;
    int w246;
    int w247;
    int w248;
    int w249;
    int w250;
    int w251;
    int w252;
    int w253;
    int w254;
    int w255;
    int w256;
    int w257;
    int w258;
    int w259;
    int w260;
    int w261;
    int w262;
    int w263;
    int w264;
    int w265;
    int w266;
    int w267;
    int w268;
    int w269;
    int w270;
    int w271;
    int w272;
    int w273;
    int w274;
    int w275;
    int w276;
    int w277;
    int w278;
    int w279;
    int w280;
    int w281;
    int w282;
    int w283;
    int w284;
    int w285;
    int w286;
    int w287;
    int l43;
    int w288;
    int w289;
    int w290;
    int w291;
    int w292;
    int w293;
    int w294;
    int w295;
    int w296;
    int w297;
    int w298;
    int w299;
    int w300;
    int w301;
    int w302;
    int w303;
    int w304;
    int w305;
    int w306;
    int w307;
    int w308;
    int w309;
    int w310;
    int w311;
    int w312;
    int w313;
    int w314;
    int l44;
    int w315;
    int w316;
    int w317;
    int w318;
    int w319;
    int l45;
    int w320;
    int w321;
    int w322;
    int w323;
    int w324;
    int w325;
    int w326;
    int l46;
    int w327;
    int w328;
    int w329;
    int w330;
    int l47;
    int w331;
    int l48;
    int w332;
    int w333;
    int w334;
    int w335;
    int w336;
    int w337;
    int w338;
    int w339;
    int w340;
    int w341;
    int w342;
    int w343;
    int w344;
    int w345;
    int w346;
    int w347;
    int w348;
    int w349;
    int w350;
    int w351;
    int w352;
    int w353;
    int w354;
    int w355;
    int w356;
    int w357;
    int w358;
    int w359;
    int w360;
    int w361;
    int l49;
    int w362;
    int w363;
    int w364;
    int w365;
    int w366;
    int w367;
    int w368;
    int w369;
    int w370;
    int w371;
    int w372;
    int w373;
    int w374;
    int w375;
    int w376;
    int w377;
    int w378;
    int w379;
    int w380;
    int l50;
    int l51;
    int w381;
    int l52;
    int w382;
    int w383;
    int w384;
    int w385;
    int w386;
    int w387;
    int w388;
    int w389;
    int w390;
    int w391;
    int w392;
    int w393;
    int w394;
    int w395;
    int w396;
    int l53;
    int w397;
    int w398;
    int w399;
    int w400;
    int w401;
    int w402;
    int l54;
    int l55;
    int w403;
    int w404;
    int w405;
    int w406;
    int w407;
    int w408;
    int w409;
    int w410;
    int w411;
    int w412;
    int w413;
    int w414;
    int w415;
    int w416;
    int w417;
    int w418;
    int w419;
    int w420;
    int w421;
    int w422;
    int w423;
    int w424;
    int w425;
    int w426;
    int w427;
    int w428;
    int l56;
    int w429;
    int w430;
    int w431;
    int l57;
    int w432;
    int w433;
    int w434;
    int w435;
    int l58;
    int l59;
    int l60;
    int w436;
    int w437;
    int w438;
    int w439;
    int w440;
    int w441;
    int w442;
    int l61;
    int w443;
    int w444;
    int w445;
    int w446;
    int w447;
    int w448;
    int l62;
    int w449;
    int w450;
    int w451;
    int w452;
    int w453;
    int w454;
    int l63;
    int w455;
    int l64;
    int w456;
    int l65;
    int w457;
    int w458;
    int l66;
    int w459;
    int l67;
    int w460;
    int l68;
    int w461;
    int l69;
    int w462;
    int l70;
    int w463;
    int w464;
    int w465;
    int l71;
    int w466;
    int w467;
    int w468;
    int l72;
    int w469;
    int w470;
    int w471;
    int w472;
    int w473;
    int w474;
    int w475;
    int w476;
    int l73;
    int w477;
    int l74;
    int l75;
    int w478;
    int l76;
    int w479;
    int l77;
    int w480;
    int w481;
    int w482;
    int w483;
    int w484; // bus 2
    int w485;
    int w486;
    int w487;
    int w488;
    int w489;

    // temp wires
    int tm_w1;
    int tm_w2;
    int tm_w3;
    int tm_w4;
    int tm_w5;
    int tm_w6;
    int tm_w7;
    int tm_w8;
    int tm_w9;
    int tm_w10;
    int tm_w11;
    int tm_w12;

} z80_t;