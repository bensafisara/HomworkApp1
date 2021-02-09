
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "displayMatrix.h"
#include "sequentiel.h"






            int **a;
	    int  **b;
	    int  **mult_s; 
int **mult_p_col;
int **mult_p_row;
int N;



double tempsSequentiel =0;









void sequentiel(int N){
	




clock_t beginS = clock();

	for(int i=0; i<N; i++){
		
		for(int j=0; j<N; j++){
	          mult_s[i][j]=0;    	
			for(int k=0; k<N; k++){
	                  	 
                             mult_s[i][j]  += a[i][k] * b[k][j];
	               
	        }
           
        }
	 }
clock_t endS = clock();





/*appler foction display*/



tempsSequentiel = (double)(endS- beginS )/(CLOCKS_PER_SEC);

printf("\nTemps sequentiel %f secondes\n", tempsSequentiel);






}
