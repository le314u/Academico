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

-- DATE "06/17/2019 08:37:22"

-- 
-- Device: Altera EP4CE15F23C7 Package FBGA484
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	Se10 IS
    PORT (
	Eh_10 : OUT std_logic;
	Bit1 : IN std_logic;
	Bit2 : IN std_logic;
	Bit3 : IN std_logic;
	Bit4 : IN std_logic
	);
END Se10;

-- Design Ports Information
-- Eh_10	=>  Location: PIN_R18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Bit1	=>  Location: PIN_T17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Bit2	=>  Location: PIN_G18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Bit3	=>  Location: PIN_B1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Bit4	=>  Location: PIN_G5,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF Se10 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_Eh_10 : std_logic;
SIGNAL ww_Bit1 : std_logic;
SIGNAL ww_Bit2 : std_logic;
SIGNAL ww_Bit3 : std_logic;
SIGNAL ww_Bit4 : std_logic;
SIGNAL \Bit1~input_o\ : std_logic;
SIGNAL \Bit2~input_o\ : std_logic;
SIGNAL \Bit3~input_o\ : std_logic;
SIGNAL \Bit4~input_o\ : std_logic;
SIGNAL \Eh_10~output_o\ : std_logic;

BEGIN

Eh_10 <= ww_Eh_10;
ww_Bit1 <= Bit1;
ww_Bit2 <= Bit2;
ww_Bit3 <= Bit3;
ww_Bit4 <= Bit4;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X41_Y9_N23
\Eh_10~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \Eh_10~output_o\);

-- Location: IOIBUF_X41_Y2_N1
\Bit1~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Bit1,
	o => \Bit1~input_o\);

-- Location: IOIBUF_X41_Y25_N8
\Bit2~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Bit2,
	o => \Bit2~input_o\);

-- Location: IOIBUF_X0_Y27_N15
\Bit3~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Bit3,
	o => \Bit3~input_o\);

-- Location: IOIBUF_X0_Y27_N22
\Bit4~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Bit4,
	o => \Bit4~input_o\);

ww_Eh_10 <= \Eh_10~output_o\;
END structure;


