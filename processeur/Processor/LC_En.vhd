----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:25:04 05/13/2016 
-- Design Name: 
-- Module Name:    LC_En - Behavioral 
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

entity LC_En is
	port(
		OPIn : in  std_logic_vector(7 downto 0);
		En   : out std_logic
		);
end LC_En;

architecture Behavioral of LC_En is

begin
	process(OPIn)
	begin
		case OPIn is
			when "00001010" => En <= '1';
            when "00001011" => En <= '1';
            when "00001100" => En <= '1';
            when "00001101" => En <= '1';
            when "00001110" => En <= '1';
            when "00001111" => En <= '1';
            when "10111100" => En <= '1';
			when others => En <= '0';
		end case;
	end process;

end Behavioral;

