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
-- VERSION "Version 13.0.0 Build 156 04/24/2013 SJ Web Edition"

-- DATE "06/22/2019 22:30:29"

-- 
-- Device: Altera EP4CE115F29C7 Package FBGA780
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	Mux IS
    PORT (
	Saida : OUT std_logic;
	Controle : IN std_logic;
	Entrada2 : IN std_logic;
	Entrada1 : IN std_logic
	);
END Mux;

-- Design Ports Information
-- Saida	=>  Location: PIN_L5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Entrada2	=>  Location: PIN_J4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Entrada1	=>  Location: PIN_K2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Controle	=>  Location: PIN_J3,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF Mux IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_Saida : std_logic;
SIGNAL ww_Controle : std_logic;
SIGNAL ww_Entrada2 : std_logic;
SIGNAL ww_Entrada1 : std_logic;
SIGNAL \Saida~output_o\ : std_logic;
SIGNAL \Entrada2~input_o\ : std_logic;
SIGNAL \Entrada1~input_o\ : std_logic;
SIGNAL \Controle~input_o\ : std_logic;
SIGNAL \inst3~0_combout\ : std_logic;

BEGIN

Saida <= ww_Saida;
ww_Controle <= Controle;
ww_Entrada2 <= Entrada2;
ww_Entrada1 <= Entrada1;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X0_Y58_N16
\Saida~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst3~0_combout\,
	devoe => ww_devoe,
	o => \Saida~output_o\);

-- Location: IOIBUF_X0_Y57_N15
\Entrada2~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Entrada2,
	o => \Entrada2~input_o\);

-- Location: IOIBUF_X0_Y55_N22
\Entrada1~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Entrada1,
	o => \Entrada1~input_o\);

-- Location: IOIBUF_X0_Y57_N22
\Controle~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Controle,
	o => \Controle~input_o\);

-- Location: LCCOMB_X1_Y57_N0
\inst3~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst3~0_combout\ = (\Controle~input_o\ & (\Entrada2~input_o\)) # (!\Controle~input_o\ & ((\Entrada1~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Entrada2~input_o\,
	datac => \Entrada1~input_o\,
	datad => \Controle~input_o\,
	combout => \inst3~0_combout\);

ww_Saida <= \Saida~output_o\;
END structure;


