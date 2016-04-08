----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:20:52 04/08/2016 
-- Design Name: 
-- Module Name:    BancMem - Behavioral 
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

entity BancMem is
	generic(
		n : integer := 8
		);
	port(
		Adr : in std_logic_vector(n-1 downto 0);
		INT : in std_logic_vector(n-1 downto 0);
		RW  : in std_logic;
		OUT
end BancMem;

architecture Behavioral of BancMem is

begin


end Behavioral;

