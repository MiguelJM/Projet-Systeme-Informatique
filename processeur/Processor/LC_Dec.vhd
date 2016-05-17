----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:01:25 05/13/2016 
-- Design Name: 
-- Module Name:    LC_Dec - Behavioral 
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

entity LC_Dec is
	 port(
		OPIn  : in  std_logic_vector(7 downto 0);
		OPOut : out std_logic_vector(1 downto 0)
		);
end LC_Dec;

architecture Behavioral of LC_Dec is

begin
	process(OPIn)
	begin
		case OPIn is
			when "00001010" => OPOut <= "01"; --Addition
			when "00001100" => OPOut <= "10"; --Soustraction
			when "00001011" => OPOut <= "11"; --Multiplication
			when others => OPOut <= "00";
		end case;
	end process;


end Behavioral;

