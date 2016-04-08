----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:27:36 04/01/2016 
-- Design Name: 
-- Module Name:    Somme - Behavioral 
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
use IEEE.STD_LOGIC_arith.ALL;
use IEEE.STD_LOGIC_unsigned.ALL;
use IEEE.NUMERIC_STD.ALL;

entity Somme is
	generic(
		n : integer := 8
		);
	port(
		A:        in  std_logic_vector(n-1 downto 0);
		B:        in  std_logic_vector(n-1 downto 0);
		S:        out std_logic_vector(n-1 downto 0);
		N:        out std_logic;
		O:        out std_logic;
		Z:        out std_logic;
		C:        out std_logic
		);
end Somme;

architecture Behavioral of Somme is
	signal Ze: std_logic_vector(n-1 downto 0);
	signal Q:  std_logic_vector(n-1 downto 0);
begin
	process(A,B,Ze,Q)
		variable Somme :  unsigned (n downto 0);
	begin
		Somme := unsigned('0'& A) + unsigned('0'& B);
		S <= std_logic_vector(Somme(n-1 downto 0));
		C <= std_logic(Somme(n));
		N <= std_logic(Somme(n-1));
		O <= (A(n-1) AND B(n-1) AND
						 (NOT std_logic(Somme(n-1))))
						 OR
						 ((NOT A(n-1)) AND NOT B(n-1))
						 AND std_logic(Somme(n-1))));
		Ze <= std_logic_vector(Somme(n-1 downto 0));
		
		Q(0) <= Ze(0);
		for i in 1 to n-1 loop
			Q(i) <= Ze(i) OR Q(i-1);
		end loop;
		Z <= NOT(Q(n-1));
	end process;
							

end Behavioral;


