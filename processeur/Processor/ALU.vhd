----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:47:08 05/04/2016 
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

entity ALU is
    port(
A       : in  std_logic_vector(7 downto 0);
B       : in  std_logic_vector(7 downto 0);
CTRL    : in  std_logic_vector(1 downto 0);
N       : out std_logic;
O       : out std_logic;
Z       : out std_logic;
C       : out std_logic;
S       : out std_logic_vector(7 downto 0)
);
end ALU;

architecture Behavioral of ALU is
signal Q  : std_logic_vector(7 downto 0);
signal Ze : std_logic_vector(7 downto 0);
begin
    process(A,B,Q,Ze)
    variable Somme :  unsigned (8 downto 0);
    variable Sous :  unsigned (8 downto 0);
    variable Mult :  unsigned (15 downto 0);
    begin
        case CTRL is
            when "01" =>
                Somme := unsigned('0'& A) + unsigned('0'& B);
                S <= std_logic_vector(Somme(7 downto 0));
                C <= std_logic(Somme(8));
                N <= std_logic(Somme(7));
                O <= (A(7) AND B(7) AND (NOT std_logic(Somme(7)))) OR ((NOT A(7)) AND (NOT B(7)) AND std_logic(Somme(7)));
                Ze <= std_logic_vector(Somme(7 downto 0));
                Q(0) <= Ze(0);
                for i in 1 to 7 loop
                    Q(i) <= Ze(i) OR Q(i-1);
                end loop;
                Z <= NOT(Q(7));

            when "10" =>
                Sous := unsigned('0'& A) - unsigned('0'& B);
                S <= std_logic_vector(Sous(7 downto 0));
                C <= std_logic(Sous(8));
                N <= std_logic(Sous(7));
                O <= (A(7) AND B(7) AND (NOT std_logic(Sous(7)))) OR ((NOT A(7)) AND (NOT B(7)) AND std_logic(Sous(7)));
                Ze <= std_logic_vector(Sous(7 downto 0));
                Q(0) <= Ze(0);
                for i in 1 to 7 loop
                    Q(i) <= Ze(i) OR Q(i-1);
                end loop;
                Z <= NOT(Q(7));

            when "11" =>
                Mult := signed('0'& A) * signed('0'& B);
                S <= std_logic_vector(Mult(7 downto 0));
                C <= std_logic(Mult(8));
                N <= std_logic(Mult(7));
                O <= (A(7) AND B(7) AND (NOT std_logic(Mult(7)))) OR ((NOT A(7)) AND (NOT B(7)) AND std_logic(Mult(7)));
                Ze <= std_logic_vector(Mult(7 downto 0));
                Q(0) <= Ze(0);
                for i in 1 to 7 loop
                    Q(i) <= Ze(i) OR Q(i-1);
                end loop;
                Z <= NOT(Q(7));

            when others =>
                C <= '0';
                N <= '0';
                O <= '0';
                Z <= '0';
                S <= (others => '0');

        end case;
    end process;

end Behavioral;

