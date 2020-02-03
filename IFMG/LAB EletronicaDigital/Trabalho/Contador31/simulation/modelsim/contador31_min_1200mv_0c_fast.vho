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

-- DATE "06/22/2019 20:14:12"

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

ENTITY 	contador31 IS
    PORT (
	UnidaB1 : OUT std_logic;
	reset : IN std_logic;
	UnidaB2 : OUT std_logic;
	UnidaB3 : OUT std_logic;
	UnidaB4 : OUT std_logic;
	DezenaB1 : OUT std_logic;
	DezenaB2 : OUT std_logic;
	clock : IN std_logic
	);
END contador31;

-- Design Ports Information
-- UnidaB1	=>  Location: PIN_Y13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reset	=>  Location: PIN_D1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- UnidaB2	=>  Location: PIN_R28,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- UnidaB3	=>  Location: PIN_AG25,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- UnidaB4	=>  Location: PIN_G11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DezenaB1	=>  Location: PIN_F1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DezenaB2	=>  Location: PIN_AB24,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clock	=>  Location: PIN_G6,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF contador31 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_UnidaB1 : std_logic;
SIGNAL ww_reset : std_logic;
SIGNAL ww_UnidaB2 : std_logic;
SIGNAL ww_UnidaB3 : std_logic;
SIGNAL ww_UnidaB4 : std_logic;
SIGNAL ww_DezenaB1 : std_logic;
SIGNAL ww_DezenaB2 : std_logic;
SIGNAL ww_clock : std_logic;
SIGNAL \reset~input_o\ : std_logic;
SIGNAL \clock~input_o\ : std_logic;
SIGNAL \UnidaB1~output_o\ : std_logic;
SIGNAL \UnidaB2~output_o\ : std_logic;
SIGNAL \UnidaB3~output_o\ : std_logic;
SIGNAL \UnidaB4~output_o\ : std_logic;
SIGNAL \DezenaB1~output_o\ : std_logic;
SIGNAL \DezenaB2~output_o\ : std_logic;

BEGIN

UnidaB1 <= ww_UnidaB1;
ww_reset <= reset;
UnidaB2 <= ww_UnidaB2;
UnidaB3 <= ww_UnidaB3;
UnidaB4 <= ww_UnidaB4;
DezenaB1 <= ww_DezenaB1;
DezenaB2 <= ww_DezenaB2;
ww_clock <= clock;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X52_Y0_N9
\UnidaB1~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \UnidaB1~output_o\);

-- Location: IOOBUF_X115_Y34_N23
\UnidaB2~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \UnidaB2~output_o\);

-- Location: IOOBUF_X91_Y0_N23
\UnidaB3~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \UnidaB3~output_o\);

-- Location: IOOBUF_X25_Y73_N16
\UnidaB4~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \UnidaB4~output_o\);

-- Location: IOOBUF_X0_Y59_N16
\DezenaB1~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \DezenaB1~output_o\);

-- Location: IOOBUF_X115_Y5_N16
\DezenaB2~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \DezenaB2~output_o\);

-- Location: IOIBUF_X0_Y68_N8
\reset~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reset,
	o => \reset~input_o\);

-- Location: IOIBUF_X0_Y67_N15
\clock~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clock,
	o => \clock~input_o\);

ww_UnidaB1 <= \UnidaB1~output_o\;

ww_UnidaB2 <= \UnidaB2~output_o\;

ww_UnidaB3 <= \UnidaB3~output_o\;

ww_UnidaB4 <= \UnidaB4~output_o\;

ww_DezenaB1 <= \DezenaB1~output_o\;

ww_DezenaB2 <= \DezenaB2~output_o\;
END structure;


