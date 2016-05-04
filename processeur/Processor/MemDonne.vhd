----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:33:50 04/08/2016 
-- Design Name: 
-- Module Name:    MemDonne - Behavioral 
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

entity MemDonne is
	port(
		RST : in  std_logic;
		CLK : in  std_logic;
		Adr : in  std_logic_vector(7 downto 0);
		INT : in  std_logic_vector(7 downto 0);
		RW  : in  std_logic;
		OUTs: out std_logic_vector(7 downto 0)
	);
end MemDonne;

architecture Behavioral of MemDonne is
signal Qp,Qn : std_logic_vector(7 downto 0);
begin
	Secuencial: process(RST,CLK)
	begin
		if(RST = '0') then
			Qp <= (others => '0');
		elsif(CLK'event and CLK = '1') then
			Qp <= Qn;
		end if;
	end process Secuencial;
	
	--Qn <= INT when RW = '1' else Qp;
	Combinatoire: process(Qp,RW,Adr,INT)
	begin
		case RW is
			when "1" =>	Qn <= INT;		--Ecriture
			when others =>	Qn <= Qp;	--Lecture
		end case;
	end process Combinatoire;
	
	OUTs <= Qp;

end Behavioral;
