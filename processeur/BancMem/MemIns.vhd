----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:36:51 04/08/2016 
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
	generic(
		n : integer := 8
		);
	port(
		Adr : in  std_logic_vector(n-1 downto 0);
		CLK : in  std_logic;
		OUTs: out std_logic-vector(n*4-1 downto 0)
		);
end MemIns;

architecture Behavioral of MemIns is

begin
	


end Behavioral;

