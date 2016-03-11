%{
    #include "symtab.h"
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    
}%

%%
// Places in text file
//Ex:
/*------------
 | 1    2   5    \
 | 3    4         \
 | 12   1   6   9  \
 |                  |
 |                  |
 |                  |
 |__________________*/

^1 {return tAFC;}
^2  /***********/
^3  /***********/


[0-9]+ {yyval=atof(yytext); return tNUM;}
[ \n] {;}
%%