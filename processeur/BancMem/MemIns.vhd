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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

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
begin
	process(CLK,Adr)
	begin
		if(CLK'event and CLK='1') then
			counter <= counter + 1;
		elsif(counter = '255') then
			counter <= 0;
		end if;
		DummyQ <= Adr(counter);
	end process;
	OUTs <= DummyQ;
end Behavioral;

