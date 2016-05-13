----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:17:37 05/13/2016 
-- Design Name: 
-- Module Name:    LC_RW - Behavioral 
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

entity LC_RW is
	port(
		OPIn  : in  std_logic_vector(7 downto 0);
		OPOut : out std_logic
		);
end LC_RW;

architecture Behavioral of LC_RW is

begin
	process(OPIn)
	begin
		case OPIn is
			when "01010101" => OPOut <= "1";
			when others => OPOut <= "0";
		end case;
	end process;

end Behavioral;

