----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:40:32 05/04/2016 
-- Design Name: 
-- Module Name:    Mult1 - Behavioral 
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

entity Mult1 is
	port(
		OP 	: in  std_logic_vector(7 downto 0);
		B  	: in  std_logic_vector(7 downto 0);
		QA 	: in  std_logic_vector(7 downto 0);
		OutB 	: out std_logic_vector(7 downto 0)
		);
end Mult1;

architecture Behavioral of Mult1 is
begin
	process(OP,B,QA)
	begin
		case OP is  
			when "01010101" => OutB <= B;
			when others => OutB <= QA;
		end case;
	end process;
end Behavioral;

