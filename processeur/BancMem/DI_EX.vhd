----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:29:15 04/15/2016 
-- Design Name: 
-- Module Name:    DI_EX - Behavioral 
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

entity DI_EX is
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
end DI_EX;

architecture Behavioral of DI_EX is
begin
	OtA <= InA;
	OtOP <= InOP;
	OtB <= InB;
	OtC <= InC;
end Behavioral;

