----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:25:28 05/13/2016 
-- Design Name: 
-- Module Name:    Mult3 - Behavioral 
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

entity Mult3 is
	port(
		OP 	: in  std_logic_vector(7 downto 0);
		A		: in  std_logic_vector(7 downto 0);
		B  	: in  std_logic_vector(7 downto 0);
		OutB 	: out std_logic_vector(7 downto 0)
		);
end Mult3;

architecture Behavioral of Mult3 is
begin
	process(OP,A,B)
	begin
		case OP is 
            when "00001010" => OutB <= A; --Addition
			when "00001100" => OutB <= A; --Soustraction
			when "00001011" => OutB <= A; --Multiplication
			when others => OutB <= B;
		end case;
	end process;
end Behavioral;

