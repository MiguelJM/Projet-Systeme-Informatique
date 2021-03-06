----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:12:25 04/15/2016 
-- Design Name: 
-- Module Name:    BancReg - Behavioral 
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
--use IEEE.std_logic_arith.all;
use IEEE.numeric_std.all;

entity BancReg is
	port(
		RST 	: in  std_logic;
		CLK 	: in  std_logic;
		AA 	: in  std_logic_vector(3 downto 0) := (others => '0');
		AB 	: in  std_logic_vector(3 downto 0) := (others => '0');
		AW 	: in  std_logic_vector(3 downto 0) := (others => '0');
		W 		: in  std_logic;
		DATA	: in  std_logic_vector(7 downto 0);
		QA		: out std_logic_vector(7 downto 0);
		QB		: out std_logic_vector(7 downto 0)
		);
end BancReg;

architecture Behavioral of BancReg is
signal QAp,QBp : std_logic_vector(7 downto 0);
signal QAn,QBn : std_logic_vector(7 downto 0);
type TABLE is array (0 to 15) of std_logic_vector(7 downto 0);
signal Reg : TABLE;
begin
	Secuential: process(RST,CLK)
	begin
		if(RST = '0') then
			QAp <= (others => '0');
			QBp <= (others => '0');
            Reg <= (others => X"00");
		elsif(CLK'event and CLK = '1') then
			QAp <= QAn;
			QBp <= QBn;
		end if;
	end process Secuential;
	
	Combinatoire: process(W,QAp,QBp,AA,AB,AW)
	begin
		case W is
			when '0' =>			--Lecture
				QAn <= Reg(to_integer(unsigned(AA)));
				QBn <= Reg(to_integer(unsigned(AB)));
			when others =>		--Ecriture
				Reg(to_integer(unsigned(AW))) <= DATA;
                if(AW = AA) then
                    QAn <= DATA;
                else
                    QAn <= Reg(to_integer(unsigned(AA)));
                end if;
                 if(AW = AB) then
                    QBn <= DATA;
                else
                    QBn <= Reg(to_integer(unsigned(AB)));
                end if;
		end case;
	end process Combinatoire;
	QA <= QAp;
	QB <= QBp;
end Behavioral;
