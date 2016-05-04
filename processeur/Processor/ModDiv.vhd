----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:46:56 04/15/2016 
-- Design Name: 
-- Module Name:    ModDiv - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;
use IEEE.numeric_std.all;

entity ModDiv is
	port(
		INS 	: in std_logic_vector(31 downto 0);
		A 		: out std_logic_vector(7 downto 0);
		OP		: out std_logic_vector(7 downto 0);
		B 		: out std_logic_vector(7 downto 0);
		C 		: out std_logic_vector(7 downto 0)
		);
end ModDiv;

architecture Behavioral of ModDiv is
begin
	C <= INS(7 downto 0);
	B <= INS(15 downto 8);
	OP<= INS(23 downto 16);
	A <= INS(31 downto 24);
end Behavioral;
