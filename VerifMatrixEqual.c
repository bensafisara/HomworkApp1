
/*
 * Sara B
 */
#include <stdio.h>

#include "VerifMatrixEqual.h"

#include <stdbool.h>  


void VerifEquality( int** matrix1 , int** matrix2 , int n ){

bool  flag ;




            for(int i = 0; i < n; ++i){  
            for(int j = 0; j < n; ++j){ 
            
            if(matrix1[i][j]!= matrix2[i][j]){  
                  flag = false ; 
                  break;  
           
            }else{
              
              flag = true; 


            }
        }  
    }
          
        if(flag==true)  {
            printf("Matrices equal\n");  
        }
        else {
            printf("Matrices are not  equal\n");  
    
        }

    }