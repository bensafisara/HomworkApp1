/***************** Les includes ********************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "displayMatrix.h"
#include "displayMatrix.c"
#include "funcThread.c"
#include "funcThread.h"
#include "funcThread_3.c"
#include "funcThread_3.h"
#include "funcThread_4.c"
#include "funcThread_4.h"
#include "funThreadC.c"
#include "funThreadC.h"
#include "initMatrix.h"
#include "initMatrix.c"
#include "sequentiel.c"
#include "sequentiel.h"
#include "VerifMatrixEqual.c"
#include "VerifMatrixEqual.h"
  #include "VrifierPuissanceDeux.c"
  #include "VrifierPuissanceDeux.h"
 #include <math.h>




/*********************Variables globales******************************/
 int **a;
 int  **b;
int **mult_p , **mult_p1 , **mult_s , **mult_p_3 , **mult_p_4 ;  
int **mult_p_col;
int **mult_p_row;
int N;
int NumThr;
double speedUpArchiRow;
double speedUpArchiCol;
double speedUpArchi_3_Blocs;
char* mode;
int *VecteurNumDesThreads;
double tempsParalleleArchitectureRow;
double tempsParalleleArchitectureColmun;
 double tempsParalleleArchitecture3;
double tempsSequentiel ;

/*********************Fin Variable globales******************************/



int main( int argc, char  *argv[]){

/******************vérification des arguments d'entrée **************/

if (argc>3)
  {
    mode = argv[1];
    N=atoi(argv[2]);
    NumThr=atoi(argv[3]);
  }else
  {
    printf("faute \n");
    printf("Utiliser : ./multiplic_matrix [mode de calcul p pour parallel s pour sequentiel] [dimension des matrix nxn * nxn ] [num thread]   \n"); 
    exit(-1);
  }

 if(NumThr > N|| NumThr < 1)
  {
    printf("Erreur verifier le numéro de thread \n");
    exit(-2);
  }
/***********************************************************************/
/******************fonction verifie pair ******************/ 

int VerfPair(int nbr)
{
   if (nbr % 2 == 0)
      return 1 ;
   else
       return 0;
    

}


/************************************************************/ 

    /********allocation des matrix*********/
    int i,j = 0;

	a=(int **)malloc( N*sizeof(int *));     
	for(i=0;i<N;i++){
	a[i]=(int *)malloc( N*sizeof(int ));

	}

	b=(int **)malloc(N*sizeof(int *));
	for(i=0;i<N;i++){
	b[i]=(int *)malloc( N*sizeof(int ));

	}

   mult_p=(int **)malloc( N*sizeof(int *));
	for(i=0;i<N;i++){
	mult_p[i]=(int *)malloc( N*sizeof(int ));
	}

	mult_p1=(int **)malloc( N*sizeof(int *));
	for(i=0;i<N;i++){
	mult_p1[i]=(int *)malloc( N*sizeof(int ));
	}

    mult_s=(int **)malloc( N*sizeof(int *));
    for(i=0;i<N;i++){
    mult_s[i]=(int *)malloc( N*sizeof(int ));
    }

    mult_p_3=(int **)malloc( N*sizeof(int *));
	for(i=0;i<N;i++){
	mult_p_3[i]=(int *)malloc( N*sizeof(int ));
	}
    
    mult_p_4=(int **)malloc( N*sizeof(int *));
	for(i=0;i<N;i++){
	mult_p_4[i]=(int *)malloc( N*sizeof(int ));
	}

     VecteurNumDesThreads =(int *) malloc(NumThr*sizeof(int));
    /*********************************/

/**********le vecteur des id*****************/
for(int h =0;h<NumThr;h++)
  {
    VecteurNumDesThreads[h]=h;
    
  }
/********************************************/


/************creating matrix a and b***********************/

       generateRandomMatrix(a,N,1,2);
       generateRandomMatrix(b,N,1,2);
/********************************************************/

    /**************traitement*****************/

if((!strcmp(mode, "P")) || (!strcmp(mode, "p"))){                                          
	/**************Architecture 1 ************/
	printf("calcul parallele Architecture 1 ligne\n");
	printf("\n=========\n" );
	printf("mode parallel");
	printf("\nNombre de threads = %d\n", NumThr);
	printf("size %d",N);
	printf("\n=========\n" );
	initialisation(NumThr);
	sequentiel(N);
	printf("\nresultat du calcul row\n" );
	printMatrix(mult_p, N);
	printf("\nfin calcul parallele Architecture 1 ligne\n\n\n");

    printf("***************************************" );

   /**************Architecture 2 ************/

	printf("\ncalcul parallele Architecture 2 colonne\n");
	printf("\n=========\n" );
	printf("mode parallel");
	printf("\nNombre de threads = %d\n", NumThr);
	printf("size %d",N);
	printf("\n=========\n" );
	initialisationC(NumThr);
	sequentiel(N);
	printf("\nresultat du calcul col\n" );
	printMatrix(mult_p1, N);
	printf("\nfin calcul parallele Architecture 2 colonne\n\n\n");
 
    printf("***************************************" );

    /*************Architecture 3  ******************/

if(puissanceDeDEUX(NumThr)==1)
{
    printf("calcul parallele l'architecture 3 des Blocs\n");
	printf("\n=========\n" );
	printf("mode parallel");
	printf("\nNombre de threads = %d\n", NumThr);
	printf("size %d",N);
	printf("\n=========\n" );
	initialisation_3(NumThr);
	printf("\nfin calcul parallele l'architecture 3 des Blocs\n\n\n");
    printf("\nresultat du calcul 3 \n" );
	printMatrix(mult_p_3, N);
	printf("\nfin calcul parallele l'architecture 3 des Blocs\n\n\n");


}else{
    
    printf("\n\n Erreur : Le nombre de threads doit etre une puissance de Deux pour pouvoir utliser l'architecture 3 des Blocs \n\n");
      
      }

/***************************************************/


/*************Architecture 4  ******************/
 printf("***************************************\n" );
if(VerfPair(NumThr)==1)
{
    printf("calcul parallele l'architecture 4 des Blocs\n");
	printf("\n=========\n" );
	printf("mode parallel");
	printf("\nNombre de threads = %d\n", NumThr);
	printf("size %d",N);
	printf("\n=========\n" );
	initialisation_4(NumThr);
	printf("\nfin calcul parallele l'architecture 4 \n\n\n");
    printf("\nresultat du calcul 4 \n" );
	printMatrix(mult_p_4, N);
	printf("\nfin calcul parallele l'architecture 4 \n\n\n");	
	
	}else{
    
   printf("l'architecture 4 des Blocs\n");
    printf("\n\n Erreur : Le nombre de thread pair pour pouvoir utliser l'architecture 4  \n\n");
      
      }

/***************************************************/



/****SpeedUp*****/
	printf("\n\n" );
	speedUpArchiRow=tempsSequentiel/tempsParalleleArchitectureRow;
	printf("speedUp entre sequentiel et architecture ligne : %f\n",speedUpArchiRow );
    printf("\n" );
	speedUpArchiCol=tempsSequentiel/tempsParalleleArchitectureColmun;
	printf("speedUp entre sequentiel et architecture colonne : %f\n",speedUpArchiCol );
    printf("\n" );
	speedUpArchi_3_Blocs =tempsSequentiel/tempsParalleleArchitecture3;
	printf("speedUp entre sequentiel et architecture 3 des Blocs : %f\n",speedUpArchi_3_Blocs );
    printf("\n\n" );
/******************/

/**********VerificationMatrix***********/
	printf("\nverification egalité entre matrice Para archi Row et matrice Seq\n" );
	VerifEquality(mult_p,mult_s,N);
	 printf("\n" );
	printf("\nverification egalité entre matrice Para archi col et matrice Seq\n" );
	VerifEquality(mult_p1,mult_s,N);
	 printf("\n" );
	printf("\nverification egalité entre matrice Para architecture 3 des Blocs et matrice Seq\n" );
	VerifEquality(mult_p_3,mult_s,N);
	 printf("\n\n" );

/*************************************/



}else{

if((!strcmp(mode, "S")) || (!strcmp(mode, "s"))){

	/**********************************Sequetiel*********************************************/
	printf("\ncalcul sequentiel \n\n ");
	printf("\n=========\n" );
	printf("mode: sequentiel\n" );
	printf("thread count : 1\n" );
	printf("size %d",N );
	printf("\n=========\n" );
	sequentiel(N);
	printf("resultat du calcul sequentiel\n");
    printMatrix(mult_s, N);

	/*******************************************************************************/

}else{
 
   printf("Specifier le mode sequentiel avec : s\t Specifier le mode parallel avec : p \n");

   }

}


for(i=0;i<N;i++)
  {
	    free(a[i]);
	    free(b[i]);
	    free(mult_s[i]);
	    free(mult_p[i]);
	    free(mult_p1[i]);
	    free(mult_p_3[i]);
	    free(mult_p_4[i]);

  }

return 0;
}






