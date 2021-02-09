#include <stdio.h>
#include <math.h>
#include "VrifierPuissanceDeux.h"
#include <stdbool.h>

int puissanceDeDEUX(int number)
{
    int Var1;
    float Var2;
 
 Var2=sqrt((double)number);
 Var1=Var2;
 
    if(Var1==Var2)
         return 1 ;
    
    else
        return 0  ;

}