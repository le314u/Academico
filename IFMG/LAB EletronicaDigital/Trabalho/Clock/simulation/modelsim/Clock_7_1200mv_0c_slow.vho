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

-- DATE "06/23/2019 07:45:18"

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

ENTITY 	Clock IS
    PORT (
	Clock_100Hz : OUT std_logic;
	Clock_50Mhz : IN std_logic;
	Clock_10Hz : OUT std_logic;
	Clock_1Khz : OUT std_logic
	);
END Clock;

-- Design Ports Information
-- Clock_100Hz	=>  Location: PIN_A8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Clock_10Hz	=>  Location: PIN_C8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Clock_1Khz	=>  Location: PIN_E10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Clock_50Mhz	=>  Location: PIN_G11,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF Clock IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_Clock_100Hz : std_logic;
SIGNAL ww_Clock_50Mhz : std_logic;
SIGNAL ww_Clock_10Hz : std_logic;
SIGNAL ww_Clock_1Khz : std_logic;
SIGNAL \inst6~q\ : std_logic;
SIGNAL \inst9~q\ : std_logic;
SIGNAL \inst17~q\ : std_logic;
SIGNAL \inst5~q\ : std_logic;
SIGNAL \inst16~q\ : std_logic;
SIGNAL \inst4~q\ : std_logic;
SIGNAL \inst15~q\ : std_logic;
SIGNAL \inst3~q\ : std_logic;
SIGNAL \inst14~q\ : std_logic;
SIGNAL \inst2~q\ : std_logic;
SIGNAL \inst13~q\ : std_logic;
SIGNAL \inst1~q\ : std_logic;
SIGNAL \inst~q\ : std_logic;
SIGNAL \inst11~0_combout\ : std_logic;
SIGNAL \inst18~0_combout\ : std_logic;
SIGNAL \inst6~0_combout\ : std_logic;
SIGNAL \inst9~0_combout\ : std_logic;
SIGNAL \inst17~0_combout\ : std_logic;
SIGNAL \inst5~0_combout\ : std_logic;
SIGNAL \inst16~0_combout\ : std_logic;
SIGNAL \inst4~0_combout\ : std_logic;
SIGNAL \inst15~0_combout\ : std_logic;
SIGNAL \inst3~0_combout\ : std_logic;
SIGNAL \inst14~0_combout\ : std_logic;
SIGNAL \inst2~0_combout\ : std_logic;
SIGNAL \inst13~0_combout\ : std_logic;
SIGNAL \inst1~0_combout\ : std_logic;
SIGNAL \inst~0_combout\ : std_logic;
SIGNAL \Clock_50Mhz~input_o\ : std_logic;
SIGNAL \inst6~feeder_combout\ : std_logic;
SIGNAL \inst17~feeder_combout\ : std_logic;
SIGNAL \inst5~feeder_combout\ : std_logic;
SIGNAL \inst4~feeder_combout\ : std_logic;
SIGNAL \inst15~feeder_combout\ : std_logic;
SIGNAL \inst2~feeder_combout\ : std_logic;
SIGNAL \inst13~feeder_combout\ : std_logic;
SIGNAL \inst1~feeder_combout\ : std_logic;
SIGNAL \Clock_100Hz~output_o\ : std_logic;
SIGNAL \Clock_10Hz~output_o\ : std_logic;
SIGNAL \Clock_1Khz~output_o\ : std_logic;
SIGNAL \inst7~0_combout\ : std_logic;
SIGNAL \inst7~q\ : std_logic;
SIGNAL \inst8~0_combout\ : std_logic;
SIGNAL \inst8~feeder_combout\ : std_logic;
SIGNAL \inst8~q\ : std_logic;
SIGNAL \inst11~feeder_combout\ : std_logic;
SIGNAL \inst11~q\ : std_logic;
SIGNAL \inst12~0_combout\ : std_logic;
SIGNAL \inst12~q\ : std_logic;
SIGNAL \inst18~feeder_combout\ : std_logic;
SIGNAL \inst18~q\ : std_logic;
SIGNAL \inst19~0_combout\ : std_logic;
SIGNAL \inst19~q\ : std_logic;

BEGIN

Clock_100Hz <= ww_Clock_100Hz;
ww_Clock_50Mhz <= Clock_50Mhz;
Clock_10Hz <= ww_Clock_10Hz;
Clock_1Khz <= ww_Clock_1Khz;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: FF_X20_Y72_N29
inst6 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst5~q\,
	d => \inst6~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst6~q\);

-- Location: FF_X19_Y72_N27
inst9 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst8~q\,
	asdata => \inst9~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst9~q\);

-- Location: FF_X18_Y71_N7
inst17 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst16~q\,
	d => \inst17~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst17~q\);

-- Location: FF_X21_Y72_N7
inst5 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst4~q\,
	d => \inst5~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst5~q\);

-- Location: FF_X17_Y71_N9
inst16 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst15~q\,
	asdata => \inst16~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst16~q\);

-- Location: FF_X23_Y72_N13
inst4 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst3~q\,
	d => \inst4~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst4~q\);

-- Location: FF_X17_Y71_N17
inst15 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst14~q\,
	d => \inst15~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst15~q\);

-- Location: FF_X24_Y72_N5
inst3 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst2~q\,
	asdata => \inst3~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst3~q\);

-- Location: FF_X17_Y72_N31
inst14 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst13~q\,
	asdata => \inst14~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst14~q\);

-- Location: FF_X24_Y72_N29
inst2 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst1~q\,
	d => \inst2~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst2~q\);

-- Location: FF_X17_Y72_N29
inst13 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst12~q\,
	d => \inst13~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst13~q\);

-- Location: FF_X25_Y72_N5
inst1 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst~q\,
	d => \inst1~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst1~q\);

-- Location: FF_X25_Y72_N19
inst : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Clock_50Mhz~input_o\,
	asdata => \inst~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst~q\);

-- Location: LCCOMB_X18_Y72_N12
\inst11~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst11~0_combout\ = !\inst11~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst11~q\,
	combout => \inst11~0_combout\);

-- Location: LCCOMB_X19_Y71_N30
\inst18~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst18~0_combout\ = !\inst18~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst18~q\,
	combout => \inst18~0_combout\);

-- Location: LCCOMB_X20_Y72_N12
\inst6~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst6~0_combout\ = !\inst6~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst6~q\,
	combout => \inst6~0_combout\);

-- Location: LCCOMB_X19_Y72_N4
\inst9~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst9~0_combout\ = !\inst9~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst9~q\,
	combout => \inst9~0_combout\);

-- Location: LCCOMB_X18_Y71_N0
\inst17~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst17~0_combout\ = !\inst17~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst17~q\,
	combout => \inst17~0_combout\);

-- Location: LCCOMB_X21_Y72_N0
\inst5~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst5~0_combout\ = !\inst5~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst5~q\,
	combout => \inst5~0_combout\);

-- Location: LCCOMB_X17_Y71_N26
\inst16~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst16~0_combout\ = !\inst16~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst16~q\,
	combout => \inst16~0_combout\);

-- Location: LCCOMB_X23_Y72_N20
\inst4~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst4~0_combout\ = !\inst4~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst4~q\,
	combout => \inst4~0_combout\);

-- Location: LCCOMB_X17_Y71_N20
\inst15~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst15~0_combout\ = !\inst15~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst15~q\,
	combout => \inst15~0_combout\);

-- Location: LCCOMB_X24_Y72_N26
\inst3~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst3~0_combout\ = !\inst3~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst3~q\,
	combout => \inst3~0_combout\);

-- Location: LCCOMB_X17_Y72_N26
\inst14~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst14~0_combout\ = !\inst14~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst14~q\,
	combout => \inst14~0_combout\);

-- Location: LCCOMB_X24_Y72_N24
\inst2~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2~0_combout\ = !\inst2~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst2~q\,
	combout => \inst2~0_combout\);

-- Location: LCCOMB_X17_Y72_N12
\inst13~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst13~0_combout\ = !\inst13~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst13~q\,
	combout => \inst13~0_combout\);

-- Location: LCCOMB_X25_Y72_N6
\inst1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1~0_combout\ = !\inst1~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst1~q\,
	combout => \inst1~0_combout\);

-- Location: LCCOMB_X25_Y72_N10
\inst~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst~0_combout\ = !\inst~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst~q\,
	combout => \inst~0_combout\);

-- Location: IOIBUF_X25_Y73_N15
\Clock_50Mhz~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Clock_50Mhz,
	o => \Clock_50Mhz~input_o\);

-- Location: LCCOMB_X20_Y72_N28
\inst6~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst6~feeder_combout\ = \inst6~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6~0_combout\,
	combout => \inst6~feeder_combout\);

-- Location: LCCOMB_X18_Y71_N6
\inst17~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst17~feeder_combout\ = \inst17~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst17~0_combout\,
	combout => \inst17~feeder_combout\);

-- Location: LCCOMB_X21_Y72_N6
\inst5~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst5~feeder_combout\ = \inst5~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst5~0_combout\,
	combout => \inst5~feeder_combout\);

-- Location: LCCOMB_X23_Y72_N12
\inst4~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst4~feeder_combout\ = \inst4~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst4~0_combout\,
	combout => \inst4~feeder_combout\);

-- Location: LCCOMB_X17_Y71_N16
\inst15~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst15~feeder_combout\ = \inst15~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst15~0_combout\,
	combout => \inst15~feeder_combout\);

-- Location: LCCOMB_X24_Y72_N28
\inst2~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst2~feeder_combout\ = \inst2~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst2~0_combout\,
	combout => \inst2~feeder_combout\);

-- Location: LCCOMB_X17_Y72_N28
\inst13~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst13~feeder_combout\ = \inst13~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst13~0_combout\,
	combout => \inst13~feeder_combout\);

-- Location: LCCOMB_X25_Y72_N4
\inst1~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1~feeder_combout\ = \inst1~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst1~0_combout\,
	combout => \inst1~feeder_combout\);

-- Location: IOOBUF_X18_Y73_N23
\Clock_100Hz~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst8~q\,
	devoe => ww_devoe,
	o => \Clock_100Hz~output_o\);

-- Location: IOOBUF_X16_Y73_N9
\Clock_10Hz~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst12~q\,
	devoe => ww_devoe,
	o => \Clock_10Hz~output_o\);

-- Location: IOOBUF_X18_Y73_N16
\Clock_1Khz~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst19~q\,
	devoe => ww_devoe,
	o => \Clock_1Khz~output_o\);

-- Location: LCCOMB_X20_Y72_N30
\inst7~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst7~0_combout\ = !\inst7~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst7~q\,
	combout => \inst7~0_combout\);

-- Location: FF_X20_Y72_N27
inst7 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst6~q\,
	asdata => \inst7~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst7~q\);

-- Location: LCCOMB_X19_Y72_N20
\inst8~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst8~0_combout\ = !\inst8~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst8~q\,
	combout => \inst8~0_combout\);

-- Location: LCCOMB_X19_Y72_N18
\inst8~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst8~feeder_combout\ = \inst8~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst8~0_combout\,
	combout => \inst8~feeder_combout\);

-- Location: FF_X19_Y72_N19
inst8 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst7~q\,
	d => \inst8~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst8~q\);

-- Location: LCCOMB_X18_Y72_N28
\inst11~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst11~feeder_combout\ = \inst11~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst11~0_combout\,
	combout => \inst11~feeder_combout\);

-- Location: FF_X18_Y72_N29
inst11 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst9~q\,
	d => \inst11~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst11~q\);

-- Location: LCCOMB_X18_Y72_N30
\inst12~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst12~0_combout\ = !\inst12~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst12~q\,
	combout => \inst12~0_combout\);

-- Location: FF_X18_Y72_N27
inst12 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst11~q\,
	asdata => \inst12~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst12~q\);

-- Location: LCCOMB_X19_Y71_N24
\inst18~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst18~feeder_combout\ = \inst18~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst18~0_combout\,
	combout => \inst18~feeder_combout\);

-- Location: FF_X19_Y71_N25
inst18 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst17~q\,
	d => \inst18~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst18~q\);

-- Location: LCCOMB_X19_Y71_N22
\inst19~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst19~0_combout\ = !\inst19~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst19~q\,
	combout => \inst19~0_combout\);

-- Location: FF_X19_Y71_N23
inst19 : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst18~q\,
	d => \inst19~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst19~q\);

ww_Clock_100Hz <= \Clock_100Hz~output_o\;

ww_Clock_10Hz <= \Clock_10Hz~output_o\;

ww_Clock_1Khz <= \Clock_1Khz~output_o\;
END structure;


