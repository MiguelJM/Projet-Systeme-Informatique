----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:38:14 05/13/2016 
-- Design Name: 
-- Module Name:    Mult4 - Behavioral 
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

entity Mult4 is
	port(
		OP 	: in  std_logic_vector(7 downto 0);
		DON	: in  std_logic_vector(7 downto 0);
		B  	: in  std_logic_vector(7 downto 0);
		OutB 	: out std_logic_vector(7 downto 0)
		);
end Mult4;

architecture Behavioral of Mult4 is
begin
	process(OP,DON,B)
	begin
		case OP is  
			when "01010101" => OutB <= B;
			when others => OutB <= DON;
		end case;
	end process;
end Behavioral;

