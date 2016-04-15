----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:11:11 04/08/2016 
-- Design Name: 
-- Module Name:    Multiplication - Behavioral 
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
use IEEE.STD_LOGIC_arith.ALL;
use IEEE.STD_LOGIC_unsigned.ALL;
use IEEE.NUMERIC_STD.ALL;

entity Multiplication is
	generic(
		n: integer :=8;
		m: integer :=8
		);
	port(
		A : in	std_logic_vector(n-1 downto 0);
		B : in 	std_logic_vector(n-1 downto 0);
		S : out 	std_logic_vector(n+m-1 downto 0)
		);
end Multiplication;

architecture Behavioral of Multiplication is

begin
	process(A,B)
	variable P : signed(n+m-& downto 0);
		begin
		P := signed(A)*signed(B);
		R <= std_logic_vector(P);
	end process;
	
end Behavioral;

