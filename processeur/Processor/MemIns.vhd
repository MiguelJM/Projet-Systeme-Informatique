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
use IEEE.std_logic_arith.all;
use IEEE.numeric_std.all;

entity MemIns is
	port(
		Adr : in  std_logic_vector(7 downto 0);
		CLK : in  std_logic;
		OUTs: out std_logic-vector(31 downto 0)
		);
end MemIns;

architecture Behavioral of MemIns is
signal counter : std_logic_vector(7 downto 0) := (others => '0');
signal DummyQ  : std_logic_vector(31 downto 0);
type TABLE is array (7 downto 0) of std_logic_vector(31 downto 0);
signal memory : TABLE;
begin
	process(CLK,Adr)
	begin
		if(CLK'event and CLK='1') then
			counter <= counter + 1;
		elsif(to_integer(unsigned(counter)) = '255') then
			counter <= 0;
		end if;
<<<<<<< HEAD
		DummyQ <= memory(to_integer(unsigned(counter)));
=======
		DummyQ <= TABLE(to_integer(unsigned(Adr)));
>>>>>>> 5396c519ae1536c3e311f41c84b954fdbc9017d4
	end process;
	OUTs <= DummyQ;
end Behavioral;


-- Revise with new RAM code