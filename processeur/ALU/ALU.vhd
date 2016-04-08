----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:22:46 04/08/2016 
-- Design Name: 
-- Module Name:    ALU - Behavioral 
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

entity ALU is
	generic(
		n : integer := 8;
		m : integer := 8
		);
	port(
		RST		 in  std_logic;
		CLK       in  std_logic;
		Ctrl_Alu  in  std_logic_vector(1 downto 0);
		Ap:        in  std_logic_vector(n-1 downto 0);
		Bp:        in  std_logic_vector(n-1 downto 0);
		Sp:        out std_logic_vector(n+m-1 downto 0);
		Np:        out std_logic;
		Op:        out std_logic;
		Zp:        out std_logic;
		Cp:        out std_logic
		);
end ALU;

architecture Behavioral of ALU is

component Somme is
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
end component;

component Soustraction is
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
end component;

component Multiplication is
	generic(
		n: integer :=8;
		m: integer :=8
		);
	port(
		A : in	std_logic_vector(n-1 downto 0);
		B : in 	std_logic_vector(n-1 downto 0);
		S : out 	std_logic_vector(n+m-1 downto 0)
		);
end component;

signal Qn,Qp : std_logic_vector(7 downto 0);
begin
	Secuencial: process(RST;CLK)
	begin
		if(RST = '0') then
			Qp <= (others => '0');
		elsif(CLK'event and CLK = '1') then
			Qp <= Qn;
		end if;
	end process Secuencial;
	
	Combinatoire: process(Ctrl_Alu, Ap, Bp)
	begin
	 case Ctrl_Alu is
		when "00" => Suma : Somme port map(Ap,Bp,Sp,Np,Op,Zp,Cp);
		when "01" => Resta : Soustraction port map(Ap,Bp,Sp,Np,Op,Zp,Cp);
		when "10" => Mult : Multiplication port map(Ap,Bp,Sp);
		when others => Sb <= A / B;
	end case;


end Behavioral;

