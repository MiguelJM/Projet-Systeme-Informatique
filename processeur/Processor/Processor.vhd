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
--Memoria de Instrucciones
component MemIns is
	port(
		Adr : in  std_logic_vector(7 downto 0);
		CLK : in  std_logic;
		OUTs: out std_logic-vector(31 downto 0)
		);
end component;

--U02
--Modulo de Division
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
--Pipeline LI/DI
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
--Banco de Registros
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

--U05
--Multiplexor 1
component Mult1 is
	port(
		OP 	: in  std_logic_vector(7 downto 0);
		B  	: in  std_logic_vector(7 downto 0);
		QA 	: in  std_logic_vector(7 downto 0);
		OutB 	: out std_logic_vector(7 downto 0)
		);
end component;

--U06
--Pipeline DI/EX
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

--U08
--Multiplexor 2
component Mult2 is
	port(
		OP 	: in  std_logic_vector(7 downto 0);
		B  	: in  std_logic_vector(7 downto 0);
		ALU 	: in  std_logic_vector(7 downto 0);
		OutB 	: out std_logic_vector(7 downto 0)
		);
end component;

--U09
--Pipeline EX/Mem
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
--Multipexor3
component Mult3 is
	port(
		OP 	: in  std_logic_vector(7 downto 0);
		A		: in  std_logic_vector(7 downto 0);
		B  	: in  std_logic_vector(7 downto 0);
		OutB 	: out std_logic_vector(7 downto 0)
		);
end component;

--U11
-- Memoria de Datos
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

--U12
--Multiplexor4
component Mult4 is
	port(
		OP 	: in  std_logic_vector(7 downto 0);
		DON	: in  std_logic_vector(7 downto 0);
		B  	: in  std_logic_vector(7 downto 0);
		OutB 	: out std_logic_vector(7 downto 0)
		);
end component;

--U13
--Pipeline Mem/RE
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

signal SOUTs : std_logic_vector(31 downto 0);
signal SA,SOP,SB,SC : std_logic_vector(7 downto 0);
signal PA,POP,PB,PC : std_logic_vector(7 downto 0);
signal BROA, BROB : std_logic_vector(7 downto 0);
signal MDON : std_logic_vector(7 downto 0);
signal MO1,MO2,MO3,MO4 : std_logic_vector(7 downto 0);
signal RetA,RetB : std_logic_vector(7 downto 0);		

begin

--Unit Declaration

	U01 : MemIns port map(Adr, CLK, SOUTs);
	U02 : ModDIv port map(SOUTs, SA, SOP, SB, SC);
	U03 : LI_DI port map(SA, SOP, SB, SC, PA, POP, PB, PC);
	U04 : BancReg port map(RST, CLK, PB, PC, RetA, /*FROM LAST LC*/, RetB, BROA, BROB);
	U05 : Mult1 port map(POP, PB, BROA, MO1);
	U06 : DI_EX port map(PA, POP, MO1, BROB, PA, POP, PB, PC);
	--LC Instruction Decoder
	--U07 : ALU
	U08 : Mult2 port map(POP, PB, /*SALIDA ALU*/, MO2);
	U09 : EX_Mem port map(PA, POP, MO2, PA, POP, PB);
	U10 : Mult3 port map(POP, PA, PB, MO3);
	--LC Instruction Decoder
	U11 : MemDonne port map(RST, CLK, MO3, PB, POP, MDON);
	U12 : Mult4 port map(POP, MDON, PB, MO4);
	U13 : Mem_RE port map(PA, POP, MO4, RetA, POP, RetB);
	--LC Instruction Decoder
	
	
	
	QAp <= BROA;
	QBP <= BROB;

end Behavioral;
