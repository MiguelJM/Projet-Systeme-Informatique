----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:22:15 04/15/2016 
-- Design Name: 
-- Module Name:    LI_DI - Behavioral 
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

entity LI_DI is
	port(
		InA 	: in  std_logic_vector(7 downto 0);
		InOP	: in  std_logic_vector(7 downto 0);
		InB	: in  std_logic_vector(7 downto 0);
		InC	: in  std_logic_vector(7 downto 0);
		OtA	: out std_logic_vector(7 downto 0);
		OtOP	: out std_logic_vector(7 downto 0);
		OtB	: out std_logic_vector(7 downto 0);
		OtC	: out std_logic_vector(7 downto 0)
		);
end LI_DI;

architecture Behavioral of LI_DI is
begin
	OtA <= InA;
	OtOP <= InOP;
	OtB <= InB;
	OtC <= InC;
end Behavioral;

