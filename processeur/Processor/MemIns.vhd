----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:40:42 04/13/2016 
-- Design Name: 
-- Module Name:    MemIns - Behavioral 
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
use IEEE.std_logic_unsigned.all;
use IEEE.numeric_std.all;

entity MemIns is
	port(
		Adr : in  std_logic_vector(7 downto 0);
		CLK : in  std_logic;
		OUTs: out std_logic_vector(31 downto 0)
		);
end MemIns;

architecture Behavioral of MemIns is
--signal counter : std_logic_vector(7 downto 0) := (others => '0');
signal DummyQ  : std_logic_vector(31 downto 0);
type TABLE is array (7 downto 0) of std_logic_vector(31 downto 0);
signal memory : TABLE := (
	0 => X"0F011100",
--	1 => X"0E021200",
--	2 => X"0A031323",
--  3 => X"0B041424",
--  4 => X"0C051525",
--  5 => X"BC061626",
	others => (others => '0')
);
begin
	process(CLK,Adr)
	begin
		if(CLK'event and CLK='1') then
			--counter <= counter + 1;
		--elsif(to_integer(unsigned(counter)) = '255') then
			--counter <= 0;
            DummyQ <= memory(to_integer(unsigned(Adr)));
		end if;
		--DummyQ <= memory(to_integer(unsigned(counter)));	
	end process;
	OUTs <= DummyQ;
end Behavioral;
