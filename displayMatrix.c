/***************** Les includes ********************/
#include <stdio.h>
#include "displayMatrix.h"


void printMatrix(int** matrix, int n){
	/*****************Declaration & initialisation ********************/
	int i, j;
	  /**********************Traitment******************************/
	for (i = 0; i < n; ++i) {
                
		for (j = 0; j < n; ++j) {
	         printf(" %d\t ", matrix[i][j] );
		}
		printf("\n");
	}



}






