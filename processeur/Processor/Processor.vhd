----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:51:42 04/15/2016 
-- Design Name: 
-- Module Name:    Processor - Behavioral 
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

entity Processor is
	port(
		RST 	: in  std_logic;
		CLK 	: in  std_logic;
		--Entradas
		--Salidas
		QAp	: out std_logic_vector(7 downto 0);
		QBp	: out std_logic_vector(7 downto 0)
		);	
end Processor;

architecture Behavioral of Processor is

--U01
component MemIns is
	port(
		Adr : in  std_logic_vector(7 downto 0);
		CLK : in  std_logic;
		OUTs: out std_logic-vector(31 downto 0)
		);
end component;

--U02
component ModDiv is
	port(
		INS 	: in std_logic_vector(31 downto 0);
		A 		: out std_logic_vector(7 downto 0);
		OP		: out std_logic_vector(7 downto 0);
		B 		: out std_logic_vector(7 downto 0);
		C 		: out std_logic_vector(7 downto 0)
		);
end component;

--U03
component LI_DI is
	port(
		InA 	: in  std_logic_vector(7 downto 0);
		InOP	: in  std_logic_vector(7 downto 0);
		InB	: in  std_logic_vector(7 downto 0);
		InC	: in  std_logic_vector(7 downto 0);
		OtA	: out std_logic_vector(7 downto 0);
		OtOP	: out std_logic_vector(7 downto 0);
		OtB	: out std_logic_vector(7 downto 0);
		OtC	: out std_logic_vector(7 downto 0)
		);
end component;

--U04
component BancReg is
	port(
		RST 	: in  std_logic;
		CLK 	: in  std_logic;
		AA 	: in  std_logic_vector(3 downto 0);
		AB 	: in  std_logic_vector(3 downto 0);
		AW 	: in  std_logic_vector(3 downto 0);
		W 		: in  std_logic;
		DATA	: in  std_logic_vector(7 downto 0);
		QA		: out std_logic_vector(7 downto 0);
		QB		: out std_logic_vector(7 downto 0)
		);
end component;

--Mulitplexor
--U05

--U06
component DI_EX is
	port(
		InA 	: in  std_logic_vector(7 downto 0);
		InOP	: in  std_logic_vector(7 downto 0);
		InB	: in  std_logic_vector(7 downto 0);
		InC	: in  std_logic_vector(7 downto 0);
		OtA	: out std_logic_vector(7 downto 0);
		OtOP	: out std_logic_vector(7 downto 0);
		OtB	: out std_logic_vector(7 downto 0);
		OtC	: out std_logic_vector(7 downto 0)
		);
end component;

--Modified ALU
--U07

--Multiplexor
--U08

--U09
component EX_Mem is
	port(
		InA 	: in  std_logic_vector(7 downto 0);
		InOP	: in  std_logic_vector(7 downto 0);
		InB	: in  std_logic_vector(7 downto 0);
		OtA	: out std_logic_vector(7 downto 0);
		OtOP	: out std_logic_vector(7 downto 0);
		OtB	: out std_logic_vector(7 downto 0)
		);
end component;

--U10
component MemDonne is
	port(
		RST : in  std_logic;
		CLK : in  std_logic;
		Adr : in  std_logic_vector(7 downto 0);
		INT : in  std_logic_vector(7 downto 0);
		RW  : in  std_logic;
		OUTs: out std_logic_vector(7 downto 0)
	);
end component;

--Multiplexor
--U11

--U12
component Mem_RE is
	port(
		InA 	: in  std_logic_vector(7 downto 0);
		InOP	: in  std_logic_vector(7 downto 0);
		InB	: in  std_logic_vector(7 downto 0);
		OtA	: out std_logic_vector(7 downto 0);
		OtOP	: out std_logic_vector(7 downto 0);
		OtB	: out std_logic_vector(7 downto 0)
		);
end component;		

begin

--Unit Declaration

	U01 : MemIns port map
	U01 : MemIns port map

end Behavioral;
