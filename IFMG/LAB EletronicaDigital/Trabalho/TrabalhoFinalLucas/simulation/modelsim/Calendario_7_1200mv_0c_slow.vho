-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.1.0 Build 162 10/23/2013 SJ Web Edition"

-- DATE "06/29/2019 10:33:42"

-- 
-- Device: Altera EP4CE115F29C7 Package FBGA780
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	Calendario IS
    PORT (
	A_MinutoU : OUT std_logic;
	CTRL_MSB : IN std_logic;
	CTRL_LSB : IN std_logic;
	Plus : IN std_logic;
	CLK_MSB : IN std_logic;
	CLK_LSB : IN std_logic;
	ClockInterno : IN std_logic;
	ClockManual : IN std_logic;
	Reset : IN std_logic;
	B_MinutoU : OUT std_logic;
	C_MinutoU : OUT std_logic;
	D_MinutoU : OUT std_logic;
	E_MinutoU : OUT std_logic;
	F_MinutoU : OUT std_logic;
	G_MinutoU : OUT std_logic;
	A_MinutoD : OUT std_logic;
	B_MinutoD : OUT std_logic;
	C_MinutoD : OUT std_logic;
	D_MinutoD : OUT std_logic;
	E_MinutoD : OUT std_logic;
	F_MinutoD : OUT std_logic;
	G_MinutoD : OUT std_logic;
	A_HoraU : OUT std_logic;
	B_HoraU : OUT std_logic;
	C_HoraU : OUT std_logic;
	D_HoraU : OUT std_logic;
	E_HoraU : OUT std_logic;
	F_HoraU : OUT std_logic;
	G_HoraU : OUT std_logic;
	A_HoraD : OUT std_logic;
	B_HoraD : OUT std_logic;
	C_HoraD : OUT std_logic;
	D_HoraD : OUT std_logic;
	E_HoraD : OUT std_logic;
	F_HoraD : OUT std_logic;
	G_HoraD : OUT std_logic;
	A_DiaU : OUT std_logic;
	B_DiaU : OUT std_logic;
	C_DiaU : OUT std_logic;
	D_DiaU : OUT std_logic;
	E_DiaU : OUT std_logic;
	F_DiaU : OUT std_logic;
	G_DiaU : OUT std_logic;
	A_DiaD : OUT std_logic;
	B_DiaD : OUT std_logic;
	C_DiaD : OUT std_logic;
	D_DiaD : OUT std_logic;
	E_DiaD : OUT std_logic;
	F_DiaD : OUT std_logic;
	G_DiaD : OUT std_logic
	);
END Calendario;

-- Design Ports Information
-- A_MinutoU	=>  Location: PIN_G18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B_MinutoU	=>  Location: PIN_F22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- C_MinutoU	=>  Location: PIN_E17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D_MinutoU	=>  Location: PIN_L26,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- E_MinutoU	=>  Location: PIN_L25,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F_MinutoU	=>  Location: PIN_J22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- G_MinutoU	=>  Location: PIN_H22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A_MinutoD	=>  Location: PIN_M24,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B_MinutoD	=>  Location: PIN_Y22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- C_MinutoD	=>  Location: PIN_W21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D_MinutoD	=>  Location: PIN_W22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- E_MinutoD	=>  Location: PIN_W25,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F_MinutoD	=>  Location: PIN_U23,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- G_MinutoD	=>  Location: PIN_U24,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A_HoraU	=>  Location: PIN_AA25,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B_HoraU	=>  Location: PIN_AA26,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- C_HoraU	=>  Location: PIN_Y25,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D_HoraU	=>  Location: PIN_W26,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- E_HoraU	=>  Location: PIN_Y26,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F_HoraU	=>  Location: PIN_W27,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- G_HoraU	=>  Location: PIN_W28,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A_HoraD	=>  Location: PIN_V21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B_HoraD	=>  Location: PIN_U21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- C_HoraD	=>  Location: PIN_AB20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D_HoraD	=>  Location: PIN_AA21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- E_HoraD	=>  Location: PIN_AD24,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F_HoraD	=>  Location: PIN_AF23,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- G_HoraD	=>  Location: PIN_Y19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A_DiaU	=>  Location: PIN_AB19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B_DiaU	=>  Location: PIN_AA19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- C_DiaU	=>  Location: PIN_AG21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D_DiaU	=>  Location: PIN_AH21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- E_DiaU	=>  Location: PIN_AE19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F_DiaU	=>  Location: PIN_AF19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- G_DiaU	=>  Location: PIN_AE18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A_DiaD	=>  Location: PIN_AD18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B_DiaD	=>  Location: PIN_AC18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- C_DiaD	=>  Location: PIN_AB18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D_DiaD	=>  Location: PIN_AH19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- E_DiaD	=>  Location: PIN_AG19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F_DiaD	=>  Location: PIN_AF18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- G_DiaD	=>  Location: PIN_AH18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Reset	=>  Location: PIN_AD26,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ClockManual	=>  Location: PIN_M23,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CLK_LSB	=>  Location: PIN_Y24,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CLK_MSB	=>  Location: PIN_Y23,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Plus	=>  Location: PIN_R24,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CTRL_LSB	=>  Location: PIN_AB28,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CTRL_MSB	=>  Location: PIN_AC28,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ClockInterno	=>  Location: PIN_Y2,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF Calendario IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_A_MinutoU : std_logic;
SIGNAL ww_CTRL_MSB : std_logic;
SIGNAL ww_CTRL_LSB : std_logic;
SIGNAL ww_Plus : std_logic;
SIGNAL ww_CLK_MSB : std_logic;
SIGNAL ww_CLK_LSB : std_logic;
SIGNAL ww_ClockInterno : std_logic;
SIGNAL ww_ClockManual : std_logic;
SIGNAL ww_Reset : std_logic;
SIGNAL ww_B_MinutoU : std_logic;
SIGNAL ww_C_MinutoU : std_logic;
SIGNAL ww_D_MinutoU : std_logic;
SIGNAL ww_E_MinutoU : std_logic;
SIGNAL ww_F_MinutoU : std_logic;
SIGNAL ww_G_MinutoU : std_logic;
SIGNAL ww_A_MinutoD : std_logic;
SIGNAL ww_B_MinutoD : std_logic;
SIGNAL ww_C_MinutoD : std_logic;
SIGNAL ww_D_MinutoD : std_logic;
SIGNAL ww_E_MinutoD : std_logic;
SIGNAL ww_F_MinutoD : std_logic;
SIGNAL ww_G_MinutoD : std_logic;
SIGNAL ww_A_HoraU : std_logic;
SIGNAL ww_B_HoraU : std_logic;
SIGNAL ww_C_HoraU : std_logic;
SIGNAL ww_D_HoraU : std_logic;
SIGNAL ww_E_HoraU : std_logic;
SIGNAL ww_F_HoraU : std_logic;
SIGNAL ww_G_HoraU : std_logic;
SIGNAL ww_A_HoraD : std_logic;
SIGNAL ww_B_HoraD : std_logic;
SIGNAL ww_C_HoraD : std_logic;
SIGNAL ww_D_HoraD : std_logic;
SIGNAL ww_E_HoraD : std_logic;
SIGNAL ww_F_HoraD : std_logic;
SIGNAL ww_G_HoraD : std_logic;
SIGNAL ww_A_DiaU : std_logic;
SIGNAL ww_B_DiaU : std_logic;
SIGNAL ww_C_DiaU : std_logic;
SIGNAL ww_D_DiaU : std_logic;
SIGNAL ww_E_DiaU : std_logic;
SIGNAL ww_F_DiaU : std_logic;
SIGNAL ww_G_DiaU : std_logic;
SIGNAL ww_A_DiaD : std_logic;
SIGNAL ww_B_DiaD : std_logic;
SIGNAL ww_C_DiaD : std_logic;
SIGNAL ww_D_DiaD : std_logic;
SIGNAL ww_E_DiaD : std_logic;
SIGNAL ww_F_DiaD : std_logic;
SIGNAL ww_G_DiaD : std_logic;
SIGNAL \A_MinutoU~output_o\ : std_logic;
SIGNAL \B_MinutoU~output_o\ : std_logic;
SIGNAL \C_MinutoU~output_o\ : std_logic;
SIGNAL \D_MinutoU~output_o\ : std_logic;
SIGNAL \E_MinutoU~output_o\ : std_logic;
SIGNAL \F_MinutoU~output_o\ : std_logic;
SIGNAL \G_MinutoU~output_o\ : std_logic;
SIGNAL \A_MinutoD~output_o\ : std_logic;
SIGNAL \B_MinutoD~output_o\ : std_logic;
SIGNAL \C_MinutoD~output_o\ : std_logic;
SIGNAL \D_MinutoD~output_o\ : std_logic;
SIGNAL \E_MinutoD~output_o\ : std_logic;
SIGNAL \F_MinutoD~output_o\ : std_logic;
SIGNAL \G_MinutoD~output_o\ : std_logic;
SIGNAL \A_HoraU~output_o\ : std_logic;
SIGNAL \B_HoraU~output_o\ : std_logic;
SIGNAL \C_HoraU~output_o\ : std_logic;
SIGNAL \D_HoraU~output_o\ : std_logic;
SIGNAL \E_HoraU~output_o\ : std_logic;
SIGNAL \F_HoraU~output_o\ : std_logic;
SIGNAL \G_HoraU~output_o\ : std_logic;
SIGNAL \A_HoraD~output_o\ : std_logic;
SIGNAL \B_HoraD~output_o\ : std_logic;
SIGNAL \C_HoraD~output_o\ : std_logic;
SIGNAL \D_HoraD~output_o\ : std_logic;
SIGNAL \E_HoraD~output_o\ : std_logic;
SIGNAL \F_HoraD~output_o\ : std_logic;
SIGNAL \G_HoraD~output_o\ : std_logic;
SIGNAL \A_DiaU~output_o\ : std_logic;
SIGNAL \B_DiaU~output_o\ : std_logic;
SIGNAL \C_DiaU~output_o\ : std_logic;
SIGNAL \D_DiaU~output_o\ : std_logic;
SIGNAL \E_DiaU~output_o\ : std_logic;
SIGNAL \F_DiaU~output_o\ : std_logic;
SIGNAL \G_DiaU~output_o\ : std_logic;
SIGNAL \A_DiaD~output_o\ : std_logic;
SIGNAL \B_DiaD~output_o\ : std_logic;
SIGNAL \C_DiaD~output_o\ : std_logic;
SIGNAL \D_DiaD~output_o\ : std_logic;
SIGNAL \E_DiaD~output_o\ : std_logic;
SIGNAL \F_DiaD~output_o\ : std_logic;
SIGNAL \G_DiaD~output_o\ : std_logic;
SIGNAL \CTRL_MSB~input_o\ : std_logic;
SIGNAL \CTRL_LSB~input_o\ : std_logic;
SIGNAL \minutos~0_combout\ : std_logic;
SIGNAL \Plus~input_o\ : std_logic;
SIGNAL \CLK_MSB~input_o\ : std_logic;
SIGNAL \ClockManual~input_o\ : std_logic;
SIGNAL \ClockInterno~input_o\ : std_logic;
SIGNAL \inst2|inst~0_combout\ : std_logic;
SIGNAL \inst2|inst~feeder_combout\ : std_logic;
SIGNAL \inst2|inst~q\ : std_logic;
SIGNAL \inst2|inst3~0_combout\ : std_logic;
SIGNAL \inst2|inst3~feeder_combout\ : std_logic;
SIGNAL \inst2|inst3~q\ : std_logic;
SIGNAL \inst2|inst5~0_combout\ : std_logic;
SIGNAL \inst2|inst5~feeder_combout\ : std_logic;
SIGNAL \inst2|inst5~q\ : std_logic;
SIGNAL \inst2|inst6~0_combout\ : std_logic;
SIGNAL \inst2|inst6~feeder_combout\ : std_logic;
SIGNAL \inst2|inst6~q\ : std_logic;
SIGNAL \inst2|inst8~0_combout\ : std_logic;
SIGNAL \inst2|inst8~feeder_combout\ : std_logic;
SIGNAL \inst2|inst8~q\ : std_logic;
SIGNAL \inst2|inst11~0_combout\ : std_logic;
SIGNAL \inst2|inst11~feeder_combout\ : std_logic;
SIGNAL \inst2|inst11~q\ : std_logic;
SIGNAL \inst2|inst13~0_combout\ : std_logic;
SIGNAL \inst2|inst13~feeder_combout\ : std_logic;
SIGNAL \inst2|inst13~q\ : std_logic;
SIGNAL \inst2|inst15~0_combout\ : std_logic;
SIGNAL \inst2|inst15~feeder_combout\ : std_logic;
SIGNAL \inst2|inst15~q\ : std_logic;
SIGNAL \inst2|inst17~0_combout\ : std_logic;
SIGNAL \inst2|inst17~feeder_combout\ : std_logic;
SIGNAL \inst2|inst17~q\ : std_logic;
SIGNAL \inst2|inst19~0_combout\ : std_logic;
SIGNAL \inst2|inst19~feeder_combout\ : std_logic;
SIGNAL \inst2|inst19~q\ : std_logic;
SIGNAL \inst2|inst21~0_combout\ : std_logic;
SIGNAL \inst2|inst21~feeder_combout\ : std_logic;
SIGNAL \inst2|inst21~q\ : std_logic;
SIGNAL \inst2|inst23~0_combout\ : std_logic;
SIGNAL \inst2|inst23~feeder_combout\ : std_logic;
SIGNAL \inst2|inst23~q\ : std_logic;
SIGNAL \inst2|inst25~0_combout\ : std_logic;
SIGNAL \inst2|inst25~feeder_combout\ : std_logic;
SIGNAL \inst2|inst25~q\ : std_logic;
SIGNAL \inst2|inst27~0_combout\ : std_logic;
SIGNAL \inst2|inst27~feeder_combout\ : std_logic;
SIGNAL \inst2|inst27~q\ : std_logic;
SIGNAL \inst2|inst29~0_combout\ : std_logic;
SIGNAL \inst2|inst29~feeder_combout\ : std_logic;
SIGNAL \inst2|inst29~q\ : std_logic;
SIGNAL \inst2|inst31~0_combout\ : std_logic;
SIGNAL \inst2|inst31~feeder_combout\ : std_logic;
SIGNAL \inst2|inst31~q\ : std_logic;
SIGNAL \inst2|inst33~0_combout\ : std_logic;
SIGNAL \inst2|inst33~feeder_combout\ : std_logic;
SIGNAL \inst2|inst33~q\ : std_logic;
SIGNAL \inst2|inst35~0_combout\ : std_logic;
SIGNAL \inst2|inst35~feeder_combout\ : std_logic;
SIGNAL \inst2|inst35~q\ : std_logic;
SIGNAL \inst2|inst37~0_combout\ : std_logic;
SIGNAL \inst2|inst37~feeder_combout\ : std_logic;
SIGNAL \inst2|inst37~q\ : std_logic;
SIGNAL \inst2|inst39~0_combout\ : std_logic;
SIGNAL \inst2|inst39~feeder_combout\ : std_logic;
SIGNAL \inst2|inst39~q\ : std_logic;
SIGNAL \inst2|inst41~0_combout\ : std_logic;
SIGNAL \inst2|inst41~feeder_combout\ : std_logic;
SIGNAL \inst2|inst41~q\ : std_logic;
SIGNAL \inst2|inst45~0_combout\ : std_logic;
SIGNAL \inst2|inst45~q\ : std_logic;
SIGNAL \CLK_LSB~input_o\ : std_logic;
SIGNAL \inst16|inst3~1_combout\ : std_logic;
SIGNAL \inst16|inst3~2_combout\ : std_logic;
SIGNAL \inst16|inst3~0_combout\ : std_logic;
SIGNAL \inst17|inst3~combout\ : std_logic;
SIGNAL \inst7|UniB1~0_combout\ : std_logic;
SIGNAL \Reset~input_o\ : std_logic;
SIGNAL \inst7|UniB4~0_combout\ : std_logic;
SIGNAL \inst7|UniB4~q\ : std_logic;
SIGNAL \inst7|DezB1~0_combout\ : std_logic;
SIGNAL \inst7|DezB1~feeder_combout\ : std_logic;
SIGNAL \inst7|DezB1~q\ : std_logic;
SIGNAL \inst7|DezB2~0_combout\ : std_logic;
SIGNAL \inst7|DezB2~q\ : std_logic;
SIGNAL \inst7|DezB3~0_combout\ : std_logic;
SIGNAL \inst7|DezB3~q\ : std_logic;
SIGNAL \inst7|inst4~combout\ : std_logic;
SIGNAL \inst7|10ou32_4~0_combout\ : std_logic;
SIGNAL \inst7|UniB1~q\ : std_logic;
SIGNAL \inst7|UniB2~0_combout\ : std_logic;
SIGNAL \inst7|UniB2~q\ : std_logic;
SIGNAL \inst7|UniB3~0_combout\ : std_logic;
SIGNAL \inst7|UniB3~feeder_combout\ : std_logic;
SIGNAL \inst7|UniB3~q\ : std_logic;
SIGNAL \MesUnidade12|inst8~0_combout\ : std_logic;
SIGNAL \MesUnidade12|inst13~0_combout\ : std_logic;
SIGNAL \MesUnidade12|inst18~0_combout\ : std_logic;
SIGNAL \MesUnidade12|inst19~0_combout\ : std_logic;
SIGNAL \MesUnidade12|inst27~0_combout\ : std_logic;
SIGNAL \MesUnidade12|inst32~0_combout\ : std_logic;
SIGNAL \MesUnidade12|inst36~0_combout\ : std_logic;
SIGNAL \MesDezena13|inst8~0_combout\ : std_logic;
SIGNAL \MesDezena13|inst13~0_combout\ : std_logic;
SIGNAL \MesDezena13|inst20~0_combout\ : std_logic;
SIGNAL \MesDezena13|inst19~0_combout\ : std_logic;
SIGNAL \MesDezena13|inst27~combout\ : std_logic;
SIGNAL \MesDezena13|inst32~0_combout\ : std_logic;
SIGNAL \MesDezena13|inst36~combout\ : std_logic;
SIGNAL \minutos~1_combout\ : std_logic;
SIGNAL \MesDezena13|inst20~1_combout\ : std_logic;
SIGNAL \inst18|inst3~combout\ : std_logic;
SIGNAL \inst3|UniB1~0_combout\ : std_logic;
SIGNAL \inst3|UniB4~0_combout\ : std_logic;
SIGNAL \inst3|UniB4~feeder_combout\ : std_logic;
SIGNAL \inst3|UniB4~q\ : std_logic;
SIGNAL \inst3|DezB1~0_combout\ : std_logic;
SIGNAL \inst3|DezB1~q\ : std_logic;
SIGNAL \inst3|DezB2~0_combout\ : std_logic;
SIGNAL \inst3|DezB2~q\ : std_logic;
SIGNAL \inst3|inst4~combout\ : std_logic;
SIGNAL \inst3|10ou32_4~0_combout\ : std_logic;
SIGNAL \inst3|UniB1~q\ : std_logic;
SIGNAL \inst3|UniB2~0_combout\ : std_logic;
SIGNAL \inst3|UniB2~q\ : std_logic;
SIGNAL \inst3|UniB3~0_combout\ : std_logic;
SIGNAL \inst3|UniB3~q\ : std_logic;
SIGNAL \MesUnidade11|inst8~0_combout\ : std_logic;
SIGNAL \MesUnidade11|inst13~0_combout\ : std_logic;
SIGNAL \MesUnidade11|inst18~0_combout\ : std_logic;
SIGNAL \MesUnidade11|inst19~0_combout\ : std_logic;
SIGNAL \MesUnidade11|inst27~0_combout\ : std_logic;
SIGNAL \MesUnidade11|inst32~0_combout\ : std_logic;
SIGNAL \MesUnidade11|inst36~0_combout\ : std_logic;
SIGNAL \MesDezena12|inst4~0_combout\ : std_logic;
SIGNAL \MesDezena12|inst4~1_combout\ : std_logic;
SIGNAL \MesDezena12|inst32~combout\ : std_logic;
SIGNAL \inst1|inst1|inst7~0_combout\ : std_logic;
SIGNAL \inst1|DezB1~0_combout\ : std_logic;
SIGNAL \inst1|DezB1~feeder_combout\ : std_logic;
SIGNAL \inst1|DezB1~q\ : std_logic;
SIGNAL \inst1|DezB2~0_combout\ : std_logic;
SIGNAL \inst1|DezB2~q\ : std_logic;
SIGNAL \inst1|inst4~0_combout\ : std_logic;
SIGNAL \inst1|inst4~1_combout\ : std_logic;
SIGNAL \inst1|UniB1~1_combout\ : std_logic;
SIGNAL \minutos~2_combout\ : std_logic;
SIGNAL \inst3|inst19~0_combout\ : std_logic;
SIGNAL \inst19|inst3~combout\ : std_logic;
SIGNAL \inst1|UniB1~3_combout\ : std_logic;
SIGNAL \inst1|UniB1~0_combout\ : std_logic;
SIGNAL \inst1|UniB1~_emulated_q\ : std_logic;
SIGNAL \inst1|UniB1~2_combout\ : std_logic;
SIGNAL \inst1|UniB2~0_combout\ : std_logic;
SIGNAL \inst1|10ou32_2~combout\ : std_logic;
SIGNAL \inst1|UniB2~q\ : std_logic;
SIGNAL \inst1|UniB3~0_combout\ : std_logic;
SIGNAL \inst1|UniB3~q\ : std_logic;
SIGNAL \inst1|UniB4~0_combout\ : std_logic;
SIGNAL \inst1|UniB4~q\ : std_logic;
SIGNAL \MesUnidade|inst8~0_combout\ : std_logic;
SIGNAL \MesUnidade|inst13~0_combout\ : std_logic;
SIGNAL \MesUnidade|inst18~0_combout\ : std_logic;
SIGNAL \MesUnidade|inst19~0_combout\ : std_logic;
SIGNAL \MesUnidade|inst27~0_combout\ : std_logic;
SIGNAL \MesUnidade|inst32~0_combout\ : std_logic;
SIGNAL \MesUnidade|inst36~combout\ : std_logic;
SIGNAL \MesDezena|inst4~0_combout\ : std_logic;
SIGNAL \MesDezena|inst4~1_combout\ : std_logic;
SIGNAL \MesDezena|inst32~combout\ : std_logic;
SIGNAL \inst7|ALT_INV_DezB2~q\ : std_logic;
SIGNAL \inst7|ALT_INV_DezB1~q\ : std_logic;
SIGNAL \inst7|ALT_INV_UniB2~q\ : std_logic;
SIGNAL \inst7|ALT_INV_UniB3~q\ : std_logic;
SIGNAL \inst7|ALT_INV_UniB4~q\ : std_logic;
SIGNAL \inst7|ALT_INV_UniB1~q\ : std_logic;
SIGNAL \ALT_INV_ClockInterno~input_o\ : std_logic;
SIGNAL \inst2|ALT_INV_inst~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst3~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst5~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst6~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst8~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst11~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst13~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst15~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst17~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst19~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst21~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst23~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst31~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst25~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst33~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst39~q\ : std_logic;
SIGNAL \inst19|ALT_INV_inst3~combout\ : std_logic;
SIGNAL \inst2|ALT_INV_inst27~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst35~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst41~q\ : std_logic;
SIGNAL \inst1|ALT_INV_inst4~1_combout\ : std_logic;
SIGNAL \inst1|ALT_INV_UniB1~0_combout\ : std_logic;
SIGNAL \inst18|ALT_INV_inst3~combout\ : std_logic;
SIGNAL \inst17|ALT_INV_inst3~combout\ : std_logic;
SIGNAL \inst2|ALT_INV_inst29~q\ : std_logic;
SIGNAL \inst2|ALT_INV_inst37~q\ : std_logic;
SIGNAL \inst1|ALT_INV_10ou32_2~combout\ : std_logic;
SIGNAL \inst1|ALT_INV_UniB1~2_combout\ : std_logic;
SIGNAL \inst3|ALT_INV_10ou32_4~0_combout\ : std_logic;
SIGNAL \inst3|ALT_INV_inst4~combout\ : std_logic;
SIGNAL \inst7|ALT_INV_10ou32_4~0_combout\ : std_logic;
SIGNAL \inst7|ALT_INV_inst4~combout\ : std_logic;
SIGNAL \inst1|ALT_INV_DezB2~q\ : std_logic;
SIGNAL \inst1|ALT_INV_DezB1~q\ : std_logic;
SIGNAL \inst1|ALT_INV_UniB2~q\ : std_logic;
SIGNAL \inst1|ALT_INV_UniB3~q\ : std_logic;
SIGNAL \inst1|ALT_INV_UniB4~q\ : std_logic;
SIGNAL \inst3|ALT_INV_DezB2~q\ : std_logic;
SIGNAL \inst3|ALT_INV_DezB1~q\ : std_logic;
SIGNAL \inst3|ALT_INV_UniB2~q\ : std_logic;
SIGNAL \inst3|ALT_INV_UniB3~q\ : std_logic;
SIGNAL \inst3|ALT_INV_UniB4~q\ : std_logic;
SIGNAL \inst3|ALT_INV_UniB1~q\ : std_logic;

BEGIN

A_MinutoU <= ww_A_MinutoU;
ww_CTRL_MSB <= CTRL_MSB;
ww_CTRL_LSB <= CTRL_LSB;
ww_Plus <= Plus;
ww_CLK_MSB <= CLK_MSB;
ww_CLK_LSB <= CLK_LSB;
ww_ClockInterno <= ClockInterno;
ww_ClockManual <= ClockManual;
ww_Reset <= Reset;
B_MinutoU <= ww_B_MinutoU;
C_MinutoU <= ww_C_MinutoU;
D_MinutoU <= ww_D_MinutoU;
E_MinutoU <= ww_E_MinutoU;
F_MinutoU <= ww_F_MinutoU;
G_MinutoU <= ww_G_MinutoU;
A_MinutoD <= ww_A_MinutoD;
B_MinutoD <= ww_B_MinutoD;
C_MinutoD <= ww_C_MinutoD;
D_MinutoD <= ww_D_MinutoD;
E_MinutoD <= ww_E_MinutoD;
F_MinutoD <= ww_F_MinutoD;
G_MinutoD <= ww_G_MinutoD;
A_HoraU <= ww_A_HoraU;
B_HoraU <= ww_B_HoraU;
C_HoraU <= ww_C_HoraU;
D_HoraU <= ww_D_HoraU;
E_HoraU <= ww_E_HoraU;
F_HoraU <= ww_F_HoraU;
G_HoraU <= ww_G_HoraU;
A_HoraD <= ww_A_HoraD;
B_HoraD <= ww_B_HoraD;
C_HoraD <= ww_C_HoraD;
D_HoraD <= ww_D_HoraD;
E_HoraD <= ww_E_HoraD;
F_HoraD <= ww_F_HoraD;
G_HoraD <= ww_G_HoraD;
A_DiaU <= ww_A_DiaU;
B_DiaU <= ww_B_DiaU;
C_DiaU <= ww_C_DiaU;
D_DiaU <= ww_D_DiaU;
E_DiaU <= ww_E_DiaU;
F_DiaU <= ww_F_DiaU;
G_DiaU <= ww_G_DiaU;
A_DiaD <= ww_A_DiaD;
B_DiaD <= ww_B_DiaD;
C_DiaD <= ww_C_DiaD;
D_DiaD <= ww_D_DiaD;
E_DiaD <= ww_E_DiaD;
F_DiaD <= ww_F_DiaD;
G_DiaD <= ww_G_DiaD;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\inst7|ALT_INV_DezB2~q\ <= NOT \inst7|DezB2~q\;
\inst7|ALT_INV_DezB1~q\ <= NOT \inst7|DezB1~q\;
\inst7|ALT_INV_UniB2~q\ <= NOT \inst7|UniB2~q\;
\inst7|ALT_INV_UniB3~q\ <= NOT \inst7|UniB3~q\;
\inst7|ALT_INV_UniB4~q\ <= NOT \inst7|UniB4~q\;
\inst7|ALT_INV_UniB1~q\ <= NOT \inst7|UniB1~q\;
\ALT_INV_ClockInterno~input_o\ <= NOT \ClockInterno~input_o\;
\inst2|ALT_INV_inst~q\ <= NOT \inst2|inst~q\;
\inst2|ALT_INV_inst3~q\ <= NOT \inst2|inst3~q\;
\inst2|ALT_INV_inst5~q\ <= NOT \inst2|inst5~q\;
\inst2|ALT_INV_inst6~q\ <= NOT \inst2|inst6~q\;
\inst2|ALT_INV_inst8~q\ <= NOT \inst2|inst8~q\;
\inst2|ALT_INV_inst11~q\ <= NOT \inst2|inst11~q\;
\inst2|ALT_INV_inst13~q\ <= NOT \inst2|inst13~q\;
\inst2|ALT_INV_inst15~q\ <= NOT \inst2|inst15~q\;
\inst2|ALT_INV_inst17~q\ <= NOT \inst2|inst17~q\;
\inst2|ALT_INV_inst19~q\ <= NOT \inst2|inst19~q\;
\inst2|ALT_INV_inst21~q\ <= NOT \inst2|inst21~q\;
\inst2|ALT_INV_inst23~q\ <= NOT \inst2|inst23~q\;
\inst2|ALT_INV_inst31~q\ <= NOT \inst2|inst31~q\;
\inst2|ALT_INV_inst25~q\ <= NOT \inst2|inst25~q\;
\inst2|ALT_INV_inst33~q\ <= NOT \inst2|inst33~q\;
\inst2|ALT_INV_inst39~q\ <= NOT \inst2|inst39~q\;
\inst19|ALT_INV_inst3~combout\ <= NOT \inst19|inst3~combout\;
\inst2|ALT_INV_inst27~q\ <= NOT \inst2|inst27~q\;
\inst2|ALT_INV_inst35~q\ <= NOT \inst2|inst35~q\;
\inst2|ALT_INV_inst41~q\ <= NOT \inst2|inst41~q\;
\inst1|ALT_INV_inst4~1_combout\ <= NOT \inst1|inst4~1_combout\;
\inst1|ALT_INV_UniB1~0_combout\ <= NOT \inst1|UniB1~0_combout\;
\inst18|ALT_INV_inst3~combout\ <= NOT \inst18|inst3~combout\;
\inst17|ALT_INV_inst3~combout\ <= NOT \inst17|inst3~combout\;
\inst2|ALT_INV_inst29~q\ <= NOT \inst2|inst29~q\;
\inst2|ALT_INV_inst37~q\ <= NOT \inst2|inst37~q\;
\inst1|ALT_INV_10ou32_2~combout\ <= NOT \inst1|10ou32_2~combout\;
\inst1|ALT_INV_UniB1~2_combout\ <= NOT \inst1|UniB1~2_combout\;
\inst3|ALT_INV_10ou32_4~0_combout\ <= NOT \inst3|10ou32_4~0_combout\;
\inst3|ALT_INV_inst4~combout\ <= NOT \inst3|inst4~combout\;
\inst7|ALT_INV_10ou32_4~0_combout\ <= NOT \inst7|10ou32_4~0_combout\;
\inst7|ALT_INV_inst4~combout\ <= NOT \inst7|inst4~combout\;
\inst1|ALT_INV_DezB2~q\ <= NOT \inst1|DezB2~q\;
\inst1|ALT_INV_DezB1~q\ <= NOT \inst1|DezB1~q\;
\inst1|ALT_INV_UniB2~q\ <= NOT \inst1|UniB2~q\;
\inst1|ALT_INV_UniB3~q\ <= NOT \inst1|UniB3~q\;
\inst1|ALT_INV_UniB4~q\ <= NOT \inst1|UniB4~q\;
\inst3|ALT_INV_DezB2~q\ <= NOT \inst3|DezB2~q\;
\inst3|ALT_INV_DezB1~q\ <= NOT \inst3|DezB1~q\;
\inst3|ALT_INV_UniB2~q\ <= NOT \inst3|UniB2~q\;
\inst3|ALT_INV_UniB3~q\ <= NOT \inst3|UniB3~q\;
\inst3|ALT_INV_UniB4~q\ <= NOT \inst3|UniB4~q\;
\inst3|ALT_INV_UniB1~q\ <= NOT \inst3|UniB1~q\;

-- Location: IOOBUF_X69_Y73_N23
\A_MinutoU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade12|inst8~0_combout\,
	devoe => ww_devoe,
	o => \A_MinutoU~output_o\);

-- Location: IOOBUF_X107_Y73_N23
\B_MinutoU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade12|inst13~0_combout\,
	devoe => ww_devoe,
	o => \B_MinutoU~output_o\);

-- Location: IOOBUF_X67_Y73_N23
\C_MinutoU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade12|inst18~0_combout\,
	devoe => ww_devoe,
	o => \C_MinutoU~output_o\);

-- Location: IOOBUF_X115_Y50_N2
\D_MinutoU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade12|inst19~0_combout\,
	devoe => ww_devoe,
	o => \D_MinutoU~output_o\);

-- Location: IOOBUF_X115_Y54_N16
\E_MinutoU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade12|inst27~0_combout\,
	devoe => ww_devoe,
	o => \E_MinutoU~output_o\);

-- Location: IOOBUF_X115_Y67_N16
\F_MinutoU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade12|inst32~0_combout\,
	devoe => ww_devoe,
	o => \F_MinutoU~output_o\);

-- Location: IOOBUF_X115_Y69_N2
\G_MinutoU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade12|inst36~0_combout\,
	devoe => ww_devoe,
	o => \G_MinutoU~output_o\);

-- Location: IOOBUF_X115_Y41_N2
\A_MinutoD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena13|inst8~0_combout\,
	devoe => ww_devoe,
	o => \A_MinutoD~output_o\);

-- Location: IOOBUF_X115_Y30_N9
\B_MinutoD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena13|inst13~0_combout\,
	devoe => ww_devoe,
	o => \B_MinutoD~output_o\);

-- Location: IOOBUF_X115_Y25_N23
\C_MinutoD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena13|inst20~0_combout\,
	devoe => ww_devoe,
	o => \C_MinutoD~output_o\);

-- Location: IOOBUF_X115_Y30_N2
\D_MinutoD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena13|inst19~0_combout\,
	devoe => ww_devoe,
	o => \D_MinutoD~output_o\);

-- Location: IOOBUF_X115_Y20_N9
\E_MinutoD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena13|inst27~combout\,
	devoe => ww_devoe,
	o => \E_MinutoD~output_o\);

-- Location: IOOBUF_X115_Y22_N2
\F_MinutoD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena13|inst32~0_combout\,
	devoe => ww_devoe,
	o => \F_MinutoD~output_o\);

-- Location: IOOBUF_X115_Y28_N9
\G_MinutoD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena13|inst36~combout\,
	devoe => ww_devoe,
	o => \G_MinutoD~output_o\);

-- Location: IOOBUF_X115_Y17_N9
\A_HoraU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade11|inst8~0_combout\,
	devoe => ww_devoe,
	o => \A_HoraU~output_o\);

-- Location: IOOBUF_X115_Y16_N2
\B_HoraU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade11|inst13~0_combout\,
	devoe => ww_devoe,
	o => \B_HoraU~output_o\);

-- Location: IOOBUF_X115_Y19_N9
\C_HoraU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade11|inst18~0_combout\,
	devoe => ww_devoe,
	o => \C_HoraU~output_o\);

-- Location: IOOBUF_X115_Y19_N2
\D_HoraU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade11|inst19~0_combout\,
	devoe => ww_devoe,
	o => \D_HoraU~output_o\);

-- Location: IOOBUF_X115_Y18_N2
\E_HoraU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade11|inst27~0_combout\,
	devoe => ww_devoe,
	o => \E_HoraU~output_o\);

-- Location: IOOBUF_X115_Y20_N2
\F_HoraU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade11|inst32~0_combout\,
	devoe => ww_devoe,
	o => \F_HoraU~output_o\);

-- Location: IOOBUF_X115_Y21_N16
\G_HoraU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade11|inst36~0_combout\,
	devoe => ww_devoe,
	o => \G_HoraU~output_o\);

-- Location: IOOBUF_X115_Y25_N16
\A_HoraD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena12|inst4~0_combout\,
	devoe => ww_devoe,
	o => \A_HoraD~output_o\);

-- Location: IOOBUF_X115_Y29_N2
\B_HoraD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \B_HoraD~output_o\);

-- Location: IOOBUF_X100_Y0_N2
\C_HoraD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena12|inst4~1_combout\,
	devoe => ww_devoe,
	o => \C_HoraD~output_o\);

-- Location: IOOBUF_X111_Y0_N2
\D_HoraD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena12|inst4~0_combout\,
	devoe => ww_devoe,
	o => \D_HoraD~output_o\);

-- Location: IOOBUF_X105_Y0_N23
\E_HoraD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst3|DezB1~q\,
	devoe => ww_devoe,
	o => \E_HoraD~output_o\);

-- Location: IOOBUF_X105_Y0_N9
\F_HoraD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena12|inst32~combout\,
	devoe => ww_devoe,
	o => \F_HoraD~output_o\);

-- Location: IOOBUF_X105_Y0_N2
\G_HoraD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst3|ALT_INV_DezB2~q\,
	devoe => ww_devoe,
	o => \G_HoraD~output_o\);

-- Location: IOOBUF_X98_Y0_N23
\A_DiaU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade|inst8~0_combout\,
	devoe => ww_devoe,
	o => \A_DiaU~output_o\);

-- Location: IOOBUF_X107_Y0_N9
\B_DiaU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade|inst13~0_combout\,
	devoe => ww_devoe,
	o => \B_DiaU~output_o\);

-- Location: IOOBUF_X74_Y0_N9
\C_DiaU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade|inst18~0_combout\,
	devoe => ww_devoe,
	o => \C_DiaU~output_o\);

-- Location: IOOBUF_X74_Y0_N2
\D_DiaU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade|inst19~0_combout\,
	devoe => ww_devoe,
	o => \D_DiaU~output_o\);

-- Location: IOOBUF_X83_Y0_N23
\E_DiaU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade|inst27~0_combout\,
	devoe => ww_devoe,
	o => \E_DiaU~output_o\);

-- Location: IOOBUF_X83_Y0_N16
\F_DiaU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade|inst32~0_combout\,
	devoe => ww_devoe,
	o => \F_DiaU~output_o\);

-- Location: IOOBUF_X79_Y0_N23
\G_DiaU~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesUnidade|inst36~combout\,
	devoe => ww_devoe,
	o => \G_DiaU~output_o\);

-- Location: IOOBUF_X85_Y0_N9
\A_DiaD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena|inst4~0_combout\,
	devoe => ww_devoe,
	o => \A_DiaD~output_o\);

-- Location: IOOBUF_X87_Y0_N16
\B_DiaD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \B_DiaD~output_o\);

-- Location: IOOBUF_X98_Y0_N16
\C_DiaD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena|inst4~1_combout\,
	devoe => ww_devoe,
	o => \C_DiaD~output_o\);

-- Location: IOOBUF_X72_Y0_N2
\D_DiaD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena|inst4~0_combout\,
	devoe => ww_devoe,
	o => \D_DiaD~output_o\);

-- Location: IOOBUF_X72_Y0_N9
\E_DiaD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst1|DezB1~q\,
	devoe => ww_devoe,
	o => \E_DiaD~output_o\);

-- Location: IOOBUF_X79_Y0_N16
\F_DiaD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \MesDezena|inst32~combout\,
	devoe => ww_devoe,
	o => \F_DiaD~output_o\);

-- Location: IOOBUF_X69_Y0_N2
\G_DiaD~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst1|ALT_INV_DezB2~q\,
	devoe => ww_devoe,
	o => \G_DiaD~output_o\);

-- Location: IOIBUF_X115_Y14_N1
\CTRL_MSB~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CTRL_MSB,
	o => \CTRL_MSB~input_o\);

-- Location: IOIBUF_X115_Y17_N1
\CTRL_LSB~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CTRL_LSB,
	o => \CTRL_LSB~input_o\);

-- Location: LCCOMB_X111_Y22_N10
\minutos~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \minutos~0_combout\ = (!\CTRL_MSB~input_o\ & \CTRL_LSB~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \CTRL_MSB~input_o\,
	datad => \CTRL_LSB~input_o\,
	combout => \minutos~0_combout\);

-- Location: IOIBUF_X115_Y35_N22
\Plus~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Plus,
	o => \Plus~input_o\);

-- Location: IOIBUF_X115_Y14_N8
\CLK_MSB~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CLK_MSB,
	o => \CLK_MSB~input_o\);

-- Location: IOIBUF_X115_Y40_N8
\ClockManual~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_ClockManual,
	o => \ClockManual~input_o\);

-- Location: IOIBUF_X0_Y36_N15
\ClockInterno~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_ClockInterno,
	o => \ClockInterno~input_o\);

-- Location: LCCOMB_X47_Y30_N0
\inst2|inst~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst~0_combout\ = !\inst2|inst~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst~q\,
	combout => \inst2|inst~0_combout\);

-- Location: LCCOMB_X47_Y30_N6
\inst2|inst~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst~feeder_combout\ = \inst2|inst~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst2|inst~0_combout\,
	combout => \inst2|inst~feeder_combout\);

-- Location: FF_X47_Y30_N7
\inst2|inst\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_ClockInterno~input_o\,
	d => \inst2|inst~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst~q\);

-- Location: LCCOMB_X48_Y30_N30
\inst2|inst3~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst3~0_combout\ = !\inst2|inst3~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst3~q\,
	combout => \inst2|inst3~0_combout\);

-- Location: LCCOMB_X48_Y30_N22
\inst2|inst3~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst3~feeder_combout\ = \inst2|inst3~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst3~0_combout\,
	combout => \inst2|inst3~feeder_combout\);

-- Location: FF_X48_Y30_N23
\inst2|inst3\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst~q\,
	d => \inst2|inst3~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst3~q\);

-- Location: LCCOMB_X48_Y30_N26
\inst2|inst5~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst5~0_combout\ = !\inst2|inst5~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst5~q\,
	combout => \inst2|inst5~0_combout\);

-- Location: LCCOMB_X48_Y30_N28
\inst2|inst5~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst5~feeder_combout\ = \inst2|inst5~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst5~0_combout\,
	combout => \inst2|inst5~feeder_combout\);

-- Location: FF_X48_Y30_N29
\inst2|inst5\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst3~q\,
	d => \inst2|inst5~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst5~q\);

-- Location: LCCOMB_X52_Y30_N10
\inst2|inst6~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst6~0_combout\ = !\inst2|inst6~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst6~q\,
	combout => \inst2|inst6~0_combout\);

-- Location: LCCOMB_X52_Y30_N8
\inst2|inst6~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst6~feeder_combout\ = \inst2|inst6~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst2|inst6~0_combout\,
	combout => \inst2|inst6~feeder_combout\);

-- Location: FF_X52_Y30_N9
\inst2|inst6\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst5~q\,
	d => \inst2|inst6~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst6~q\);

-- Location: LCCOMB_X52_Y30_N26
\inst2|inst8~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst8~0_combout\ = !\inst2|inst8~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst8~q\,
	combout => \inst2|inst8~0_combout\);

-- Location: LCCOMB_X52_Y30_N22
\inst2|inst8~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst8~feeder_combout\ = \inst2|inst8~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst8~0_combout\,
	combout => \inst2|inst8~feeder_combout\);

-- Location: FF_X52_Y30_N23
\inst2|inst8\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst6~q\,
	d => \inst2|inst8~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst8~q\);

-- Location: LCCOMB_X55_Y30_N10
\inst2|inst11~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst11~0_combout\ = !\inst2|inst11~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst11~q\,
	combout => \inst2|inst11~0_combout\);

-- Location: LCCOMB_X55_Y30_N20
\inst2|inst11~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst11~feeder_combout\ = \inst2|inst11~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst2|inst11~0_combout\,
	combout => \inst2|inst11~feeder_combout\);

-- Location: FF_X55_Y30_N21
\inst2|inst11\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst8~q\,
	d => \inst2|inst11~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst11~q\);

-- Location: LCCOMB_X55_Y30_N8
\inst2|inst13~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst13~0_combout\ = !\inst2|inst13~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst13~q\,
	combout => \inst2|inst13~0_combout\);

-- Location: LCCOMB_X55_Y30_N4
\inst2|inst13~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst13~feeder_combout\ = \inst2|inst13~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst13~0_combout\,
	combout => \inst2|inst13~feeder_combout\);

-- Location: FF_X55_Y30_N5
\inst2|inst13\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst11~q\,
	d => \inst2|inst13~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst13~q\);

-- Location: LCCOMB_X59_Y28_N30
\inst2|inst15~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst15~0_combout\ = !\inst2|inst15~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst2|inst15~q\,
	combout => \inst2|inst15~0_combout\);

-- Location: LCCOMB_X59_Y28_N26
\inst2|inst15~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst15~feeder_combout\ = \inst2|inst15~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst15~0_combout\,
	combout => \inst2|inst15~feeder_combout\);

-- Location: FF_X59_Y28_N27
\inst2|inst15\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst13~q\,
	d => \inst2|inst15~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst15~q\);

-- Location: LCCOMB_X59_Y28_N28
\inst2|inst17~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst17~0_combout\ = !\inst2|inst17~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst2|inst17~q\,
	combout => \inst2|inst17~0_combout\);

-- Location: LCCOMB_X59_Y28_N24
\inst2|inst17~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst17~feeder_combout\ = \inst2|inst17~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst2|inst17~0_combout\,
	combout => \inst2|inst17~feeder_combout\);

-- Location: FF_X59_Y28_N25
\inst2|inst17\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst15~q\,
	d => \inst2|inst17~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst17~q\);

-- Location: LCCOMB_X87_Y28_N28
\inst2|inst19~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst19~0_combout\ = !\inst2|inst19~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst2|inst19~q\,
	combout => \inst2|inst19~0_combout\);

-- Location: LCCOMB_X87_Y28_N24
\inst2|inst19~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst19~feeder_combout\ = \inst2|inst19~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst2|inst19~0_combout\,
	combout => \inst2|inst19~feeder_combout\);

-- Location: FF_X87_Y28_N25
\inst2|inst19\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst17~q\,
	d => \inst2|inst19~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst19~q\);

-- Location: LCCOMB_X87_Y28_N26
\inst2|inst21~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst21~0_combout\ = !\inst2|inst21~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst21~q\,
	combout => \inst2|inst21~0_combout\);

-- Location: LCCOMB_X87_Y28_N30
\inst2|inst21~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst21~feeder_combout\ = \inst2|inst21~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst21~0_combout\,
	combout => \inst2|inst21~feeder_combout\);

-- Location: FF_X87_Y28_N31
\inst2|inst21\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst19~q\,
	d => \inst2|inst21~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst21~q\);

-- Location: LCCOMB_X90_Y27_N20
\inst2|inst23~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst23~0_combout\ = !\inst2|inst23~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst23~q\,
	combout => \inst2|inst23~0_combout\);

-- Location: LCCOMB_X90_Y27_N24
\inst2|inst23~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst23~feeder_combout\ = \inst2|inst23~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst23~0_combout\,
	combout => \inst2|inst23~feeder_combout\);

-- Location: FF_X90_Y27_N25
\inst2|inst23\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst21~q\,
	d => \inst2|inst23~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst23~q\);

-- Location: LCCOMB_X90_Y27_N10
\inst2|inst25~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst25~0_combout\ = !\inst2|inst25~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst25~q\,
	combout => \inst2|inst25~0_combout\);

-- Location: LCCOMB_X90_Y27_N22
\inst2|inst25~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst25~feeder_combout\ = \inst2|inst25~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst25~0_combout\,
	combout => \inst2|inst25~feeder_combout\);

-- Location: FF_X90_Y27_N23
\inst2|inst25\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst23~q\,
	d => \inst2|inst25~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst25~q\);

-- Location: LCCOMB_X112_Y19_N20
\inst2|inst27~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst27~0_combout\ = !\inst2|inst27~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst27~q\,
	combout => \inst2|inst27~0_combout\);

-- Location: LCCOMB_X112_Y19_N22
\inst2|inst27~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst27~feeder_combout\ = \inst2|inst27~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst2|inst27~0_combout\,
	combout => \inst2|inst27~feeder_combout\);

-- Location: FF_X112_Y19_N23
\inst2|inst27\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst25~q\,
	d => \inst2|inst27~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst27~q\);

-- Location: LCCOMB_X112_Y19_N26
\inst2|inst29~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst29~0_combout\ = !\inst2|inst29~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst29~q\,
	combout => \inst2|inst29~0_combout\);

-- Location: LCCOMB_X112_Y19_N8
\inst2|inst29~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst29~feeder_combout\ = \inst2|inst29~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst29~0_combout\,
	combout => \inst2|inst29~feeder_combout\);

-- Location: FF_X112_Y19_N9
\inst2|inst29\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst27~q\,
	d => \inst2|inst29~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst29~q\);

-- Location: LCCOMB_X113_Y19_N30
\inst2|inst31~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst31~0_combout\ = !\inst2|inst31~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst31~q\,
	combout => \inst2|inst31~0_combout\);

-- Location: LCCOMB_X113_Y19_N22
\inst2|inst31~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst31~feeder_combout\ = \inst2|inst31~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst31~0_combout\,
	combout => \inst2|inst31~feeder_combout\);

-- Location: FF_X113_Y19_N23
\inst2|inst31\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst29~q\,
	d => \inst2|inst31~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst31~q\);

-- Location: LCCOMB_X113_Y19_N26
\inst2|inst33~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst33~0_combout\ = !\inst2|inst33~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst33~q\,
	combout => \inst2|inst33~0_combout\);

-- Location: LCCOMB_X113_Y19_N28
\inst2|inst33~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst33~feeder_combout\ = \inst2|inst33~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst33~0_combout\,
	combout => \inst2|inst33~feeder_combout\);

-- Location: FF_X113_Y19_N29
\inst2|inst33\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst31~q\,
	d => \inst2|inst33~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst33~q\);

-- Location: LCCOMB_X114_Y19_N28
\inst2|inst35~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst35~0_combout\ = !\inst2|inst35~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst2|inst35~q\,
	combout => \inst2|inst35~0_combout\);

-- Location: LCCOMB_X114_Y19_N24
\inst2|inst35~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst35~feeder_combout\ = \inst2|inst35~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst2|inst35~0_combout\,
	combout => \inst2|inst35~feeder_combout\);

-- Location: FF_X114_Y19_N25
\inst2|inst35\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst33~q\,
	d => \inst2|inst35~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst35~q\);

-- Location: LCCOMB_X114_Y19_N26
\inst2|inst37~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst37~0_combout\ = !\inst2|inst37~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst37~q\,
	combout => \inst2|inst37~0_combout\);

-- Location: LCCOMB_X114_Y19_N30
\inst2|inst37~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst37~feeder_combout\ = \inst2|inst37~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst2|inst37~0_combout\,
	combout => \inst2|inst37~feeder_combout\);

-- Location: FF_X114_Y19_N31
\inst2|inst37\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst35~q\,
	d => \inst2|inst37~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst37~q\);

-- Location: LCCOMB_X113_Y21_N0
\inst2|inst39~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst39~0_combout\ = !\inst2|inst39~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst2|inst39~q\,
	combout => \inst2|inst39~0_combout\);

-- Location: LCCOMB_X113_Y21_N6
\inst2|inst39~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst39~feeder_combout\ = \inst2|inst39~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst39~0_combout\,
	combout => \inst2|inst39~feeder_combout\);

-- Location: FF_X113_Y21_N7
\inst2|inst39\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst37~q\,
	d => \inst2|inst39~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst39~q\);

-- Location: LCCOMB_X114_Y21_N28
\inst2|inst41~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst41~0_combout\ = !\inst2|inst41~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst41~q\,
	combout => \inst2|inst41~0_combout\);

-- Location: LCCOMB_X114_Y21_N30
\inst2|inst41~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst41~feeder_combout\ = \inst2|inst41~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst2|inst41~0_combout\,
	combout => \inst2|inst41~feeder_combout\);

-- Location: FF_X114_Y21_N31
\inst2|inst41\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst39~q\,
	d => \inst2|inst41~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst41~q\);

-- Location: LCCOMB_X114_Y21_N26
\inst2|inst45~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2|inst45~0_combout\ = !\inst2|inst45~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst2|inst45~q\,
	combout => \inst2|inst45~0_combout\);

-- Location: FF_X114_Y21_N27
\inst2|inst45\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2|ALT_INV_inst41~q\,
	d => \inst2|inst45~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2|inst45~q\);

-- Location: IOIBUF_X115_Y13_N1
\CLK_LSB~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CLK_LSB,
	o => \CLK_LSB~input_o\);

-- Location: LCCOMB_X114_Y21_N0
\inst16|inst3~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst16|inst3~1_combout\ = (\CLK_LSB~input_o\ & ((!\inst2|inst45~q\))) # (!\CLK_LSB~input_o\ & (!\ClockManual~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \ClockManual~input_o\,
	datac => \inst2|inst45~q\,
	datad => \CLK_LSB~input_o\,
	combout => \inst16|inst3~1_combout\);

-- Location: LCCOMB_X112_Y19_N2
\inst16|inst3~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst16|inst3~2_combout\ = (\CLK_LSB~input_o\ & ((!\inst2|inst29~q\))) # (!\CLK_LSB~input_o\ & (!\inst2|inst37~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2|inst37~q\,
	datac => \inst2|inst29~q\,
	datad => \CLK_LSB~input_o\,
	combout => \inst16|inst3~2_combout\);

-- Location: LCCOMB_X111_Y22_N20
\inst16|inst3~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst16|inst3~0_combout\ = (\CLK_MSB~input_o\ & ((\inst16|inst3~2_combout\))) # (!\CLK_MSB~input_o\ & (\inst16|inst3~1_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101001010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \CLK_MSB~input_o\,
	datac => \inst16|inst3~1_combout\,
	datad => \inst16|inst3~2_combout\,
	combout => \inst16|inst3~0_combout\);

-- Location: LCCOMB_X111_Y22_N26
\inst17|inst3\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst17|inst3~combout\ = LCELL((\minutos~0_combout\ & (\Plus~input_o\)) # (!\minutos~0_combout\ & ((!\inst16|inst3~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000011110101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \minutos~0_combout\,
	datac => \Plus~input_o\,
	datad => \inst16|inst3~0_combout\,
	combout => \inst17|inst3~combout\);

-- Location: LCCOMB_X111_Y22_N30
\inst7|UniB1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst7|UniB1~0_combout\ = !\inst7|UniB1~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst7|UniB1~q\,
	combout => \inst7|UniB1~0_combout\);

-- Location: IOIBUF_X115_Y10_N1
\Reset~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Reset,
	o => \Reset~input_o\);

-- Location: LCCOMB_X112_Y22_N4
\inst7|UniB4~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst7|UniB4~0_combout\ = !\inst7|UniB4~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst7|UniB4~q\,
	combout => \inst7|UniB4~0_combout\);

-- Location: FF_X112_Y22_N21
\inst7|UniB4\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst7|ALT_INV_UniB3~q\,
	asdata => \inst7|UniB4~0_combout\,
	clrn => \inst7|ALT_INV_10ou32_4~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst7|UniB4~q\);

-- Location: LCCOMB_X113_Y22_N28
\inst7|DezB1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst7|DezB1~0_combout\ = !\inst7|DezB1~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst7|DezB1~q\,
	combout => \inst7|DezB1~0_combout\);

-- Location: LCCOMB_X113_Y22_N24
\inst7|DezB1~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst7|DezB1~feeder_combout\ = \inst7|DezB1~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst7|DezB1~0_combout\,
	combout => \inst7|DezB1~feeder_combout\);

-- Location: FF_X113_Y22_N25
\inst7|DezB1\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst7|ALT_INV_UniB4~q\,
	d => \inst7|DezB1~feeder_combout\,
	clrn => \inst7|ALT_INV_inst4~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst7|DezB1~q\);

-- Location: LCCOMB_X113_Y22_N30
\inst7|DezB2~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst7|DezB2~0_combout\ = !\inst7|DezB2~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst7|DezB2~q\,
	combout => \inst7|DezB2~0_combout\);

-- Location: FF_X113_Y22_N27
\inst7|DezB2\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst7|ALT_INV_DezB1~q\,
	asdata => \inst7|DezB2~0_combout\,
	clrn => \inst7|ALT_INV_inst4~combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst7|DezB2~q\);

-- Location: LCCOMB_X114_Y22_N22
\inst7|DezB3~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst7|DezB3~0_combout\ = !\inst7|DezB3~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst7|DezB3~q\,
	combout => \inst7|DezB3~0_combout\);

-- Location: FF_X114_Y22_N23
\inst7|DezB3\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst7|ALT_INV_DezB2~q\,
	d => \inst7|DezB3~0_combout\,
	clrn => \inst7|ALT_INV_inst4~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst7|DezB3~q\);

-- Location: LCCOMB_X113_Y22_N18
\inst7|inst4\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst7|inst4~combout\ = (\Reset~input_o\) # ((\inst7|DezB2~q\ & \inst7|DezB3~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \Reset~input_o\,
	datac => \inst7|DezB2~q\,
	datad => \inst7|DezB3~q\,
	combout => \inst7|inst4~combout\);

-- Location: LCCOMB_X112_Y22_N22
\inst7|10ou32_4~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst7|10ou32_4~0_combout\ = (\inst7|inst4~combout\) # ((\inst7|UniB4~q\ & ((\inst7|UniB3~q\) # (\inst7|UniB2~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|inst4~combout\,
	datab => \inst7|UniB3~q\,
	datac => \inst7|UniB2~q\,
	datad => \inst7|UniB4~q\,
	combout => \inst7|10ou32_4~0_combout\);

-- Location: FF_X111_Y22_N17
\inst7|UniB1\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst17|ALT_INV_inst3~combout\,
	asdata => \inst7|UniB1~0_combout\,
	clrn => \inst7|ALT_INV_10ou32_4~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst7|UniB1~q\);

-- Location: LCCOMB_X112_Y22_N24
\inst7|UniB2~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst7|UniB2~0_combout\ = !\inst7|UniB2~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst7|UniB2~q\,
	combout => \inst7|UniB2~0_combout\);

-- Location: FF_X112_Y22_N31
\inst7|UniB2\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst7|ALT_INV_UniB1~q\,
	asdata => \inst7|UniB2~0_combout\,
	clrn => \inst7|ALT_INV_10ou32_4~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst7|UniB2~q\);

-- Location: LCCOMB_X111_Y22_N0
\inst7|UniB3~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst7|UniB3~0_combout\ = !\inst7|UniB3~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst7|UniB3~q\,
	combout => \inst7|UniB3~0_combout\);

-- Location: LCCOMB_X111_Y22_N6
\inst7|UniB3~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst7|UniB3~feeder_combout\ = \inst7|UniB3~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst7|UniB3~0_combout\,
	combout => \inst7|UniB3~feeder_combout\);

-- Location: FF_X111_Y22_N7
\inst7|UniB3\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst7|ALT_INV_UniB2~q\,
	d => \inst7|UniB3~feeder_combout\,
	clrn => \inst7|ALT_INV_10ou32_4~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst7|UniB3~q\);

-- Location: LCCOMB_X111_Y22_N16
\MesUnidade12|inst8~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade12|inst8~0_combout\ = (\inst7|UniB3~q\ & (!\inst7|UniB2~q\ & (\inst7|UniB4~q\ $ (!\inst7|UniB1~q\)))) # (!\inst7|UniB3~q\ & (\inst7|UniB1~q\ & (\inst7|UniB4~q\ $ (!\inst7|UniB2~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100000010010010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|UniB3~q\,
	datab => \inst7|UniB4~q\,
	datac => \inst7|UniB1~q\,
	datad => \inst7|UniB2~q\,
	combout => \MesUnidade12|inst8~0_combout\);

-- Location: LCCOMB_X111_Y22_N24
\MesUnidade12|inst13~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade12|inst13~0_combout\ = (\inst7|UniB4~q\ & ((\inst7|UniB1~q\ & ((\inst7|UniB2~q\))) # (!\inst7|UniB1~q\ & (\inst7|UniB3~q\)))) # (!\inst7|UniB4~q\ & (\inst7|UniB3~q\ & (\inst7|UniB1~q\ $ (\inst7|UniB2~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100101000101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|UniB3~q\,
	datab => \inst7|UniB4~q\,
	datac => \inst7|UniB1~q\,
	datad => \inst7|UniB2~q\,
	combout => \MesUnidade12|inst13~0_combout\);

-- Location: LCCOMB_X111_Y22_N28
\MesUnidade12|inst18~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade12|inst18~0_combout\ = (\inst7|UniB3~q\ & (\inst7|UniB4~q\ & ((\inst7|UniB2~q\) # (!\inst7|UniB1~q\)))) # (!\inst7|UniB3~q\ & (!\inst7|UniB4~q\ & (!\inst7|UniB1~q\ & \inst7|UniB2~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000100100001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|UniB3~q\,
	datab => \inst7|UniB4~q\,
	datac => \inst7|UniB1~q\,
	datad => \inst7|UniB2~q\,
	combout => \MesUnidade12|inst18~0_combout\);

-- Location: LCCOMB_X112_Y22_N20
\MesUnidade12|inst19~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade12|inst19~0_combout\ = (\inst7|UniB2~q\ & ((\inst7|UniB1~q\ & (\inst7|UniB3~q\)) # (!\inst7|UniB1~q\ & (!\inst7|UniB3~q\ & \inst7|UniB4~q\)))) # (!\inst7|UniB2~q\ & (!\inst7|UniB4~q\ & (\inst7|UniB1~q\ $ (\inst7|UniB3~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001100000000110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|UniB1~q\,
	datab => \inst7|UniB3~q\,
	datac => \inst7|UniB4~q\,
	datad => \inst7|UniB2~q\,
	combout => \MesUnidade12|inst19~0_combout\);

-- Location: LCCOMB_X112_Y22_N30
\MesUnidade12|inst27~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade12|inst27~0_combout\ = (\inst7|UniB2~q\ & (\inst7|UniB1~q\ & ((!\inst7|UniB4~q\)))) # (!\inst7|UniB2~q\ & ((\inst7|UniB3~q\ & ((!\inst7|UniB4~q\))) # (!\inst7|UniB3~q\ & (\inst7|UniB1~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000001010101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|UniB1~q\,
	datab => \inst7|UniB3~q\,
	datac => \inst7|UniB2~q\,
	datad => \inst7|UniB4~q\,
	combout => \MesUnidade12|inst27~0_combout\);

-- Location: LCCOMB_X112_Y22_N0
\MesUnidade12|inst32~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade12|inst32~0_combout\ = (\inst7|UniB1~q\ & (\inst7|UniB4~q\ $ (((\inst7|UniB2~q\) # (!\inst7|UniB3~q\))))) # (!\inst7|UniB1~q\ & (\inst7|UniB2~q\ & (!\inst7|UniB3~q\ & !\inst7|UniB4~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010000010001110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|UniB1~q\,
	datab => \inst7|UniB2~q\,
	datac => \inst7|UniB3~q\,
	datad => \inst7|UniB4~q\,
	combout => \MesUnidade12|inst32~0_combout\);

-- Location: LCCOMB_X112_Y22_N18
\MesUnidade12|inst36~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade12|inst36~0_combout\ = (\inst7|UniB1~q\ & (!\inst7|UniB4~q\ & (\inst7|UniB2~q\ $ (!\inst7|UniB3~q\)))) # (!\inst7|UniB1~q\ & (!\inst7|UniB2~q\ & (\inst7|UniB3~q\ $ (!\inst7|UniB4~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001000010000011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|UniB1~q\,
	datab => \inst7|UniB2~q\,
	datac => \inst7|UniB3~q\,
	datad => \inst7|UniB4~q\,
	combout => \MesUnidade12|inst36~0_combout\);

-- Location: LCCOMB_X114_Y22_N14
\MesDezena13|inst8~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesDezena13|inst8~0_combout\ = (!\inst7|DezB2~q\ & (\inst7|DezB3~q\ $ (\inst7|DezB1~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000010100001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|DezB3~q\,
	datac => \inst7|DezB2~q\,
	datad => \inst7|DezB1~q\,
	combout => \MesDezena13|inst8~0_combout\);

-- Location: LCCOMB_X114_Y22_N8
\MesDezena13|inst13~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesDezena13|inst13~0_combout\ = (\inst7|DezB3~q\ & (\inst7|DezB2~q\ $ (\inst7|DezB1~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|DezB3~q\,
	datac => \inst7|DezB2~q\,
	datad => \inst7|DezB1~q\,
	combout => \MesDezena13|inst13~0_combout\);

-- Location: LCCOMB_X114_Y22_N24
\MesDezena13|inst20~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesDezena13|inst20~0_combout\ = (!\inst7|DezB3~q\ & (\inst7|DezB2~q\ & !\inst7|DezB1~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000001010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|DezB3~q\,
	datac => \inst7|DezB2~q\,
	datad => \inst7|DezB1~q\,
	combout => \MesDezena13|inst20~0_combout\);

-- Location: LCCOMB_X114_Y22_N16
\MesDezena13|inst19~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesDezena13|inst19~0_combout\ = (\inst7|DezB3~q\ & (\inst7|DezB2~q\ $ (!\inst7|DezB1~q\))) # (!\inst7|DezB3~q\ & (!\inst7|DezB2~q\ & \inst7|DezB1~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|DezB3~q\,
	datac => \inst7|DezB2~q\,
	datad => \inst7|DezB1~q\,
	combout => \MesDezena13|inst19~0_combout\);

-- Location: LCCOMB_X114_Y22_N28
\MesDezena13|inst27\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesDezena13|inst27~combout\ = (\inst7|DezB1~q\) # ((\inst7|DezB3~q\ & !\inst7|DezB2~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|DezB3~q\,
	datac => \inst7|DezB2~q\,
	datad => \inst7|DezB1~q\,
	combout => \MesDezena13|inst27~combout\);

-- Location: LCCOMB_X114_Y22_N10
\MesDezena13|inst32~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesDezena13|inst32~0_combout\ = (\inst7|DezB3~q\ & (\inst7|DezB2~q\ & \inst7|DezB1~q\)) # (!\inst7|DezB3~q\ & ((\inst7|DezB2~q\) # (\inst7|DezB1~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111010101010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|DezB3~q\,
	datac => \inst7|DezB2~q\,
	datad => \inst7|DezB1~q\,
	combout => \MesDezena13|inst32~0_combout\);

-- Location: LCCOMB_X114_Y22_N12
\MesDezena13|inst36\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesDezena13|inst36~combout\ = (\inst7|DezB3~q\ & (\inst7|DezB2~q\ & \inst7|DezB1~q\)) # (!\inst7|DezB3~q\ & (!\inst7|DezB2~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100000101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst7|DezB3~q\,
	datac => \inst7|DezB2~q\,
	datad => \inst7|DezB1~q\,
	combout => \MesDezena13|inst36~combout\);

-- Location: LCCOMB_X111_Y22_N18
\minutos~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \minutos~1_combout\ = (\CTRL_MSB~input_o\ & !\CTRL_LSB~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \CTRL_MSB~input_o\,
	datad => \CTRL_LSB~input_o\,
	combout => \minutos~1_combout\);

-- Location: LCCOMB_X113_Y22_N6
\MesDezena13|inst20~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesDezena13|inst20~1_combout\ = (\inst7|DezB2~q\ & \inst7|DezB3~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst7|DezB2~q\,
	datad => \inst7|DezB3~q\,
	combout => \MesDezena13|inst20~1_combout\);

-- Location: LCCOMB_X113_Y22_N22
\inst18|inst3\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst18|inst3~combout\ = LCELL((\minutos~1_combout\ & (\Plus~input_o\)) # (!\minutos~1_combout\ & ((\MesDezena13|inst20~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111010110100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \minutos~1_combout\,
	datac => \Plus~input_o\,
	datad => \MesDezena13|inst20~1_combout\,
	combout => \inst18|inst3~combout\);

-- Location: LCCOMB_X110_Y20_N0
\inst3|UniB1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst3|UniB1~0_combout\ = !\inst3|UniB1~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|UniB1~q\,
	combout => \inst3|UniB1~0_combout\);

-- Location: LCCOMB_X108_Y20_N24
\inst3|UniB4~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst3|UniB4~0_combout\ = !\inst3|UniB4~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst3|UniB4~q\,
	combout => \inst3|UniB4~0_combout\);

-- Location: LCCOMB_X108_Y20_N6
\inst3|UniB4~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst3|UniB4~feeder_combout\ = \inst3|UniB4~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst3|UniB4~0_combout\,
	combout => \inst3|UniB4~feeder_combout\);

-- Location: FF_X108_Y20_N7
\inst3|UniB4\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst3|ALT_INV_UniB3~q\,
	d => \inst3|UniB4~feeder_combout\,
	clrn => \inst3|ALT_INV_10ou32_4~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst3|UniB4~q\);

-- Location: LCCOMB_X108_Y20_N26
\inst3|DezB1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst3|DezB1~0_combout\ = !\inst3|DezB1~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst3|DezB1~q\,
	combout => \inst3|DezB1~0_combout\);

-- Location: FF_X108_Y20_N31
\inst3|DezB1\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst3|ALT_INV_UniB4~q\,
	asdata => \inst3|DezB1~0_combout\,
	clrn => \inst3|ALT_INV_inst4~combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst3|DezB1~q\);

-- Location: LCCOMB_X109_Y20_N24
\inst3|DezB2~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst3|DezB2~0_combout\ = !\inst3|DezB2~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst3|DezB2~q\,
	combout => \inst3|DezB2~0_combout\);

-- Location: FF_X109_Y20_N25
\inst3|DezB2\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst3|ALT_INV_DezB1~q\,
	d => \inst3|DezB2~0_combout\,
	clrn => \inst3|ALT_INV_inst4~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst3|DezB2~q\);

-- Location: LCCOMB_X109_Y20_N6
\inst3|inst4\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst3|inst4~combout\ = (\Reset~input_o\) # ((\inst3|DezB2~q\ & ((\inst3|UniB4~q\) # (\inst3|UniB3~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Reset~input_o\,
	datab => \inst3|UniB4~q\,
	datac => \inst3|UniB3~q\,
	datad => \inst3|DezB2~q\,
	combout => \inst3|inst4~combout\);

-- Location: LCCOMB_X110_Y20_N24
\inst3|10ou32_4~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst3|10ou32_4~0_combout\ = (\inst3|inst4~combout\) # ((\inst3|UniB4~q\ & ((\inst3|UniB3~q\) # (\inst3|UniB2~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011111000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|UniB3~q\,
	datab => \inst3|UniB4~q\,
	datac => \inst3|inst4~combout\,
	datad => \inst3|UniB2~q\,
	combout => \inst3|10ou32_4~0_combout\);

-- Location: FF_X110_Y20_N7
\inst3|UniB1\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst18|ALT_INV_inst3~combout\,
	asdata => \inst3|UniB1~0_combout\,
	clrn => \inst3|ALT_INV_10ou32_4~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst3|UniB1~q\);

-- Location: LCCOMB_X110_Y20_N18
\inst3|UniB2~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst3|UniB2~0_combout\ = !\inst3|UniB2~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst3|UniB2~q\,
	combout => \inst3|UniB2~0_combout\);

-- Location: FF_X110_Y20_N29
\inst3|UniB2\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst3|ALT_INV_UniB1~q\,
	asdata => \inst3|UniB2~0_combout\,
	clrn => \inst3|ALT_INV_10ou32_4~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst3|UniB2~q\);

-- Location: LCCOMB_X109_Y20_N16
\inst3|UniB3~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst3|UniB3~0_combout\ = !\inst3|UniB3~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|UniB3~q\,
	combout => \inst3|UniB3~0_combout\);

-- Location: FF_X109_Y20_N23
\inst3|UniB3\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst3|ALT_INV_UniB2~q\,
	asdata => \inst3|UniB3~0_combout\,
	clrn => \inst3|ALT_INV_10ou32_4~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst3|UniB3~q\);

-- Location: LCCOMB_X110_Y20_N28
\MesUnidade11|inst8~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade11|inst8~0_combout\ = (\inst3|UniB3~q\ & (!\inst3|UniB2~q\ & (\inst3|UniB4~q\ $ (!\inst3|UniB1~q\)))) # (!\inst3|UniB3~q\ & (\inst3|UniB1~q\ & (\inst3|UniB4~q\ $ (!\inst3|UniB2~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100100100000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|UniB3~q\,
	datab => \inst3|UniB4~q\,
	datac => \inst3|UniB2~q\,
	datad => \inst3|UniB1~q\,
	combout => \MesUnidade11|inst8~0_combout\);

-- Location: LCCOMB_X110_Y20_N6
\MesUnidade11|inst13~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade11|inst13~0_combout\ = (\inst3|UniB2~q\ & ((\inst3|UniB1~q\ & ((\inst3|UniB4~q\))) # (!\inst3|UniB1~q\ & (\inst3|UniB3~q\)))) # (!\inst3|UniB2~q\ & (\inst3|UniB3~q\ & (\inst3|UniB1~q\ $ (\inst3|UniB4~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100101000101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|UniB3~q\,
	datab => \inst3|UniB2~q\,
	datac => \inst3|UniB1~q\,
	datad => \inst3|UniB4~q\,
	combout => \MesUnidade11|inst13~0_combout\);

-- Location: LCCOMB_X110_Y20_N10
\MesUnidade11|inst18~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade11|inst18~0_combout\ = (\inst3|UniB4~q\ & (\inst3|UniB3~q\ & ((\inst3|UniB2~q\) # (!\inst3|UniB1~q\)))) # (!\inst3|UniB4~q\ & (!\inst3|UniB1~q\ & (\inst3|UniB2~q\ & !\inst3|UniB3~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100010000010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|UniB1~q\,
	datab => \inst3|UniB4~q\,
	datac => \inst3|UniB2~q\,
	datad => \inst3|UniB3~q\,
	combout => \MesUnidade11|inst18~0_combout\);

-- Location: LCCOMB_X110_Y20_N30
\MesUnidade11|inst19~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade11|inst19~0_combout\ = (\inst3|UniB2~q\ & ((\inst3|UniB1~q\ & ((\inst3|UniB3~q\))) # (!\inst3|UniB1~q\ & (\inst3|UniB4~q\ & !\inst3|UniB3~q\)))) # (!\inst3|UniB2~q\ & (!\inst3|UniB4~q\ & (\inst3|UniB1~q\ $ (\inst3|UniB3~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000101000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|UniB1~q\,
	datab => \inst3|UniB4~q\,
	datac => \inst3|UniB2~q\,
	datad => \inst3|UniB3~q\,
	combout => \MesUnidade11|inst19~0_combout\);

-- Location: LCCOMB_X110_Y20_N2
\MesUnidade11|inst27~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade11|inst27~0_combout\ = (\inst3|UniB2~q\ & (\inst3|UniB1~q\ & (!\inst3|UniB4~q\))) # (!\inst3|UniB2~q\ & ((\inst3|UniB3~q\ & ((!\inst3|UniB4~q\))) # (!\inst3|UniB3~q\ & (\inst3|UniB1~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010001100101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|UniB1~q\,
	datab => \inst3|UniB4~q\,
	datac => \inst3|UniB2~q\,
	datad => \inst3|UniB3~q\,
	combout => \MesUnidade11|inst27~0_combout\);

-- Location: LCCOMB_X110_Y20_N16
\MesUnidade11|inst32~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade11|inst32~0_combout\ = (\inst3|UniB1~q\ & (\inst3|UniB4~q\ $ (((\inst3|UniB2~q\) # (!\inst3|UniB3~q\))))) # (!\inst3|UniB1~q\ & (!\inst3|UniB4~q\ & (\inst3|UniB2~q\ & !\inst3|UniB3~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010100000110010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|UniB1~q\,
	datab => \inst3|UniB4~q\,
	datac => \inst3|UniB2~q\,
	datad => \inst3|UniB3~q\,
	combout => \MesUnidade11|inst32~0_combout\);

-- Location: LCCOMB_X110_Y20_N22
\MesUnidade11|inst36~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade11|inst36~0_combout\ = (\inst3|UniB1~q\ & (!\inst3|UniB4~q\ & (\inst3|UniB2~q\ $ (!\inst3|UniB3~q\)))) # (!\inst3|UniB1~q\ & (!\inst3|UniB2~q\ & (\inst3|UniB4~q\ $ (!\inst3|UniB3~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010010000000011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|UniB1~q\,
	datab => \inst3|UniB4~q\,
	datac => \inst3|UniB2~q\,
	datad => \inst3|UniB3~q\,
	combout => \MesUnidade11|inst36~0_combout\);

-- Location: LCCOMB_X109_Y20_N22
\MesDezena12|inst4~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesDezena12|inst4~0_combout\ = (\inst3|DezB1~q\ & !\inst3|DezB2~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst3|DezB1~q\,
	datad => \inst3|DezB2~q\,
	combout => \MesDezena12|inst4~0_combout\);

-- Location: LCCOMB_X107_Y7_N16
\MesDezena12|inst4~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesDezena12|inst4~1_combout\ = (\inst3|DezB2~q\ & !\inst3|DezB1~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst3|DezB2~q\,
	datad => \inst3|DezB1~q\,
	combout => \MesDezena12|inst4~1_combout\);

-- Location: LCCOMB_X107_Y7_N18
\MesDezena12|inst32\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesDezena12|inst32~combout\ = (\inst3|DezB2~q\) # (\inst3|DezB1~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst3|DezB2~q\,
	datad => \inst3|DezB1~q\,
	combout => \MesDezena12|inst32~combout\);

-- Location: LCCOMB_X75_Y1_N10
\inst1|inst1|inst7~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|inst1|inst7~0_combout\ = (\inst1|UniB4~q\ & ((\inst1|UniB3~q\) # (\inst1|UniB2~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000011100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|UniB3~q\,
	datab => \inst1|UniB2~q\,
	datac => \inst1|UniB4~q\,
	combout => \inst1|inst1|inst7~0_combout\);

-- Location: LCCOMB_X76_Y1_N26
\inst1|DezB1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|DezB1~0_combout\ = !\inst1|DezB1~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst1|DezB1~q\,
	combout => \inst1|DezB1~0_combout\);

-- Location: LCCOMB_X76_Y1_N10
\inst1|DezB1~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|DezB1~feeder_combout\ = \inst1|DezB1~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst1|DezB1~0_combout\,
	combout => \inst1|DezB1~feeder_combout\);

-- Location: FF_X76_Y1_N11
\inst1|DezB1\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst1|ALT_INV_UniB4~q\,
	d => \inst1|DezB1~feeder_combout\,
	clrn => \inst1|ALT_INV_inst4~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst1|DezB1~q\);

-- Location: LCCOMB_X77_Y1_N22
\inst1|DezB2~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|DezB2~0_combout\ = !\inst1|DezB2~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst1|DezB2~q\,
	combout => \inst1|DezB2~0_combout\);

-- Location: FF_X77_Y1_N23
\inst1|DezB2\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst1|ALT_INV_DezB1~q\,
	d => \inst1|DezB2~0_combout\,
	clrn => \inst1|ALT_INV_inst4~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst1|DezB2~q\);

-- Location: LCCOMB_X75_Y1_N6
\inst1|inst4~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|inst4~0_combout\ = (\inst1|DezB2~q\ & ((\inst1|UniB4~q\) # ((\inst1|UniB3~q\) # (\inst1|UniB2~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|DezB2~q\,
	datab => \inst1|UniB4~q\,
	datac => \inst1|UniB3~q\,
	datad => \inst1|UniB2~q\,
	combout => \inst1|inst4~0_combout\);

-- Location: LCCOMB_X76_Y1_N6
\inst1|inst4~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|inst4~1_combout\ = (\Reset~input_o\) # ((\inst1|inst4~0_combout\ & \inst1|DezB1~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Reset~input_o\,
	datac => \inst1|inst4~0_combout\,
	datad => \inst1|DezB1~q\,
	combout => \inst1|inst4~1_combout\);

-- Location: LCCOMB_X76_Y1_N22
\inst1|UniB1~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|UniB1~1_combout\ = (!\inst1|inst1|inst7~0_combout\ & ((\inst1|inst4~1_combout\) # (\inst1|UniB1~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|inst4~1_combout\,
	datac => \inst1|inst1|inst7~0_combout\,
	datad => \inst1|UniB1~1_combout\,
	combout => \inst1|UniB1~1_combout\);

-- Location: LCCOMB_X111_Y22_N22
\minutos~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \minutos~2_combout\ = (\CTRL_MSB~input_o\ & \CTRL_LSB~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \CTRL_MSB~input_o\,
	datad => \CTRL_LSB~input_o\,
	combout => \minutos~2_combout\);

-- Location: LCCOMB_X109_Y20_N28
\inst3|inst19~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst3|inst19~0_combout\ = (\inst3|DezB2~q\ & ((\inst3|UniB3~q\) # (\inst3|UniB4~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|UniB3~q\,
	datac => \inst3|UniB4~q\,
	datad => \inst3|DezB2~q\,
	combout => \inst3|inst19~0_combout\);

-- Location: LCCOMB_X109_Y20_N2
\inst19|inst3\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst19|inst3~combout\ = LCELL((\minutos~2_combout\ & (\Plus~input_o\)) # (!\minutos~2_combout\ & ((\inst3|inst19~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111110100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Plus~input_o\,
	datac => \minutos~2_combout\,
	datad => \inst3|inst19~0_combout\,
	combout => \inst19|inst3~combout\);

-- Location: LCCOMB_X76_Y1_N16
\inst1|UniB1~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|UniB1~3_combout\ = \inst1|UniB1~1_combout\ $ (!\inst1|UniB1~2_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst1|UniB1~1_combout\,
	datad => \inst1|UniB1~2_combout\,
	combout => \inst1|UniB1~3_combout\);

-- Location: LCCOMB_X76_Y1_N20
\inst1|UniB1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|UniB1~0_combout\ = (\inst1|inst1|inst7~0_combout\) # (\inst1|inst4~1_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst1|inst1|inst7~0_combout\,
	datad => \inst1|inst4~1_combout\,
	combout => \inst1|UniB1~0_combout\);

-- Location: FF_X76_Y1_N17
\inst1|UniB1~_emulated\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst19|ALT_INV_inst3~combout\,
	d => \inst1|UniB1~3_combout\,
	clrn => \inst1|ALT_INV_UniB1~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst1|UniB1~_emulated_q\);

-- Location: LCCOMB_X76_Y1_N24
\inst1|UniB1~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|UniB1~2_combout\ = (!\inst1|inst1|inst7~0_combout\ & ((\inst1|inst4~1_combout\) # (\inst1|UniB1~1_combout\ $ (\inst1|UniB1~_emulated_q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101000101010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|inst1|inst7~0_combout\,
	datab => \inst1|UniB1~1_combout\,
	datac => \inst1|inst4~1_combout\,
	datad => \inst1|UniB1~_emulated_q\,
	combout => \inst1|UniB1~2_combout\);

-- Location: LCCOMB_X75_Y1_N30
\inst1|UniB2~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|UniB2~0_combout\ = !\inst1|UniB2~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst1|UniB2~q\,
	combout => \inst1|UniB2~0_combout\);

-- Location: LCCOMB_X75_Y1_N18
\inst1|10ou32_2\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|10ou32_2~combout\ = (\inst1|inst1|inst7~0_combout\) # (\inst1|inst4~1_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|inst1|inst7~0_combout\,
	datad => \inst1|inst4~1_combout\,
	combout => \inst1|10ou32_2~combout\);

-- Location: FF_X75_Y1_N29
\inst1|UniB2\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst1|ALT_INV_UniB1~2_combout\,
	asdata => \inst1|UniB2~0_combout\,
	clrn => \inst1|ALT_INV_10ou32_2~combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst1|UniB2~q\);

-- Location: LCCOMB_X75_Y1_N24
\inst1|UniB3~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|UniB3~0_combout\ = !\inst1|UniB3~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst1|UniB3~q\,
	combout => \inst1|UniB3~0_combout\);

-- Location: FF_X75_Y1_N23
\inst1|UniB3\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst1|ALT_INV_UniB2~q\,
	asdata => \inst1|UniB3~0_combout\,
	clrn => \inst1|ALT_INV_10ou32_2~combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst1|UniB3~q\);

-- Location: LCCOMB_X74_Y1_N18
\inst1|UniB4~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|UniB4~0_combout\ = !\inst1|UniB4~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst1|UniB4~q\,
	combout => \inst1|UniB4~0_combout\);

-- Location: FF_X74_Y1_N7
\inst1|UniB4\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst1|ALT_INV_UniB3~q\,
	asdata => \inst1|UniB4~0_combout\,
	clrn => \inst1|ALT_INV_10ou32_2~combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst1|UniB4~q\);

-- Location: LCCOMB_X76_Y1_N28
\MesUnidade|inst8~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade|inst8~0_combout\ = (\inst1|UniB4~q\ & (\inst1|UniB1~2_combout\ & (\inst1|UniB2~q\ $ (\inst1|UniB3~q\)))) # (!\inst1|UniB4~q\ & (!\inst1|UniB2~q\ & (\inst1|UniB3~q\ $ (\inst1|UniB1~2_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010100100010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|UniB4~q\,
	datab => \inst1|UniB2~q\,
	datac => \inst1|UniB3~q\,
	datad => \inst1|UniB1~2_combout\,
	combout => \MesUnidade|inst8~0_combout\);

-- Location: LCCOMB_X76_Y1_N4
\MesUnidade|inst13~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade|inst13~0_combout\ = (\inst1|UniB4~q\ & ((\inst1|UniB1~2_combout\ & (\inst1|UniB2~q\)) # (!\inst1|UniB1~2_combout\ & ((\inst1|UniB3~q\))))) # (!\inst1|UniB4~q\ & (\inst1|UniB3~q\ & (\inst1|UniB2~q\ $ (\inst1|UniB1~2_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001100011100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|UniB4~q\,
	datab => \inst1|UniB2~q\,
	datac => \inst1|UniB3~q\,
	datad => \inst1|UniB1~2_combout\,
	combout => \MesUnidade|inst13~0_combout\);

-- Location: LCCOMB_X75_Y1_N28
\MesUnidade|inst18~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade|inst18~0_combout\ = (\inst1|UniB4~q\ & (\inst1|UniB3~q\ & ((\inst1|UniB2~q\) # (!\inst1|UniB1~2_combout\)))) # (!\inst1|UniB4~q\ & (!\inst1|UniB1~2_combout\ & (\inst1|UniB2~q\ & !\inst1|UniB3~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010001000010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|UniB4~q\,
	datab => \inst1|UniB1~2_combout\,
	datac => \inst1|UniB2~q\,
	datad => \inst1|UniB3~q\,
	combout => \MesUnidade|inst18~0_combout\);

-- Location: LCCOMB_X75_Y1_N22
\MesUnidade|inst19~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade|inst19~0_combout\ = (\inst1|UniB2~q\ & ((\inst1|UniB1~2_combout\ & (\inst1|UniB3~q\)) # (!\inst1|UniB1~2_combout\ & (!\inst1|UniB3~q\ & \inst1|UniB4~q\)))) # (!\inst1|UniB2~q\ & (!\inst1|UniB4~q\ & (\inst1|UniB1~2_combout\ $ 
-- (\inst1|UniB3~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000001010010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|UniB2~q\,
	datab => \inst1|UniB1~2_combout\,
	datac => \inst1|UniB3~q\,
	datad => \inst1|UniB4~q\,
	combout => \MesUnidade|inst19~0_combout\);

-- Location: LCCOMB_X76_Y1_N14
\MesUnidade|inst27~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade|inst27~0_combout\ = (\inst1|UniB2~q\ & (!\inst1|UniB4~q\ & ((\inst1|UniB1~2_combout\)))) # (!\inst1|UniB2~q\ & ((\inst1|UniB3~q\ & (!\inst1|UniB4~q\)) # (!\inst1|UniB3~q\ & ((\inst1|UniB1~2_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101011100010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|UniB4~q\,
	datab => \inst1|UniB2~q\,
	datac => \inst1|UniB3~q\,
	datad => \inst1|UniB1~2_combout\,
	combout => \MesUnidade|inst27~0_combout\);

-- Location: LCCOMB_X76_Y1_N30
\MesUnidade|inst32~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade|inst32~0_combout\ = (\inst1|UniB2~q\ & (!\inst1|UniB4~q\ & ((\inst1|UniB1~2_combout\) # (!\inst1|UniB3~q\)))) # (!\inst1|UniB2~q\ & (\inst1|UniB1~2_combout\ & (\inst1|UniB4~q\ $ (!\inst1|UniB3~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110010100000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|UniB4~q\,
	datab => \inst1|UniB2~q\,
	datac => \inst1|UniB3~q\,
	datad => \inst1|UniB1~2_combout\,
	combout => \MesUnidade|inst32~0_combout\);

-- Location: LCCOMB_X76_Y1_N18
\MesUnidade|inst36\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesUnidade|inst36~combout\ = (\inst1|UniB1~2_combout\ & (!\inst1|UniB4~q\ & (\inst1|UniB2~q\ $ (!\inst1|UniB3~q\)))) # (!\inst1|UniB1~2_combout\ & (!\inst1|UniB2~q\ & (\inst1|UniB4~q\ $ (!\inst1|UniB3~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100000100100001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|UniB4~q\,
	datab => \inst1|UniB2~q\,
	datac => \inst1|UniB3~q\,
	datad => \inst1|UniB1~2_combout\,
	combout => \MesUnidade|inst36~combout\);

-- Location: LCCOMB_X77_Y1_N30
\MesDezena|inst4~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesDezena|inst4~0_combout\ = (\inst1|DezB1~q\ & !\inst1|DezB2~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101000001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|DezB1~q\,
	datac => \inst1|DezB2~q\,
	combout => \MesDezena|inst4~0_combout\);

-- Location: LCCOMB_X77_Y1_N20
\MesDezena|inst4~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesDezena|inst4~1_combout\ = (!\inst1|DezB1~q\ & \inst1|DezB2~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101000001010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|DezB1~q\,
	datac => \inst1|DezB2~q\,
	combout => \MesDezena|inst4~1_combout\);

-- Location: LCCOMB_X77_Y1_N24
\MesDezena|inst32\ : cycloneive_lcell_comb
-- Equation(s):
-- \MesDezena|inst32~combout\ = (\inst1|DezB1~q\) # (\inst1|DezB2~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1|DezB1~q\,
	datac => \inst1|DezB2~q\,
	combout => \MesDezena|inst32~combout\);

ww_A_MinutoU <= \A_MinutoU~output_o\;

ww_B_MinutoU <= \B_MinutoU~output_o\;

ww_C_MinutoU <= \C_MinutoU~output_o\;

ww_D_MinutoU <= \D_MinutoU~output_o\;

ww_E_MinutoU <= \E_MinutoU~output_o\;

ww_F_MinutoU <= \F_MinutoU~output_o\;

ww_G_MinutoU <= \G_MinutoU~output_o\;

ww_A_MinutoD <= \A_MinutoD~output_o\;

ww_B_MinutoD <= \B_MinutoD~output_o\;

ww_C_MinutoD <= \C_MinutoD~output_o\;

ww_D_MinutoD <= \D_MinutoD~output_o\;

ww_E_MinutoD <= \E_MinutoD~output_o\;

ww_F_MinutoD <= \F_MinutoD~output_o\;

ww_G_MinutoD <= \G_MinutoD~output_o\;

ww_A_HoraU <= \A_HoraU~output_o\;

ww_B_HoraU <= \B_HoraU~output_o\;

ww_C_HoraU <= \C_HoraU~output_o\;

ww_D_HoraU <= \D_HoraU~output_o\;

ww_E_HoraU <= \E_HoraU~output_o\;

ww_F_HoraU <= \F_HoraU~output_o\;

ww_G_HoraU <= \G_HoraU~output_o\;

ww_A_HoraD <= \A_HoraD~output_o\;

ww_B_HoraD <= \B_HoraD~output_o\;

ww_C_HoraD <= \C_HoraD~output_o\;

ww_D_HoraD <= \D_HoraD~output_o\;

ww_E_HoraD <= \E_HoraD~output_o\;

ww_F_HoraD <= \F_HoraD~output_o\;

ww_G_HoraD <= \G_HoraD~output_o\;

ww_A_DiaU <= \A_DiaU~output_o\;

ww_B_DiaU <= \B_DiaU~output_o\;

ww_C_DiaU <= \C_DiaU~output_o\;

ww_D_DiaU <= \D_DiaU~output_o\;

ww_E_DiaU <= \E_DiaU~output_o\;

ww_F_DiaU <= \F_DiaU~output_o\;

ww_G_DiaU <= \G_DiaU~output_o\;

ww_A_DiaD <= \A_DiaD~output_o\;

ww_B_DiaD <= \B_DiaD~output_o\;

ww_C_DiaD <= \C_DiaD~output_o\;

ww_D_DiaD <= \D_DiaD~output_o\;

ww_E_DiaD <= \E_DiaD~output_o\;

ww_F_DiaD <= \F_DiaD~output_o\;

ww_G_DiaD <= \G_DiaD~output_o\;
END structure;


