----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:40:32 05/04/2016 
-- Design Name: 
-- Module Name:    Mult2 - Behavioral 
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

entity Mult2 is
	port(
		OP 	: in  std_logic_vector(7 downto 0);
		B  	: in  std_logic_vector(7 downto 0);
		ALU 	: in  std_logic_vector(7 downto 0);
		OutB 	: out std_logic_vector(7 downto 0)
		);
end Mult2;

architecture Behavioral of Mult2 is
begin
	process(OP,B,ALU)
	begin
		case OP is
            when "00001010" => OutB <= ALU; --Addition
			when "00001100" => OutB <= ALU; --Soustraction
			when "00001011" => OutB <= ALU; --Multiplicat
			when others => OutB <= B;
		end case;
	end process;
end Behavioral;

