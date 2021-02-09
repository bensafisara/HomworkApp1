  /***************** Les includes ********************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "displayMatrix.h"
#include "funThreadC.h"
/*****************Declaration & initialisation ********************/
  int  **a;
  int  **b;
  int **mult_p1; 
  double tempsParalleleArchitectureColmun=0;
  extern int N;
  int NumThr;
  int *VecteurNumDesThreads;
  void* funcaoC(void* arg1);
   /***********************************************************/

  void initialisationC(int nbTH1){

  /************  Declaration & initialisation *************/

  pthread_t *thread=(pthread_t*)malloc(sizeof(pthread_t)*nbTH1);
  long i;
/***********************************************************/

/**********************Traitment******************************/
  clock_t beginP1 = clock();

  for(i=0;i<nbTH1;i++)
    {
     
      pthread_create(&thread[i], NULL, funcaoC, (void*)i);
    }
    

    for(i=0;i<nbTH1;i++)
    {
      pthread_join(thread[i],NULL); 
    }

    clock_t ENDp1 = clock();
    /********************************************************/

/**********************Calcul Temps ******************************/
   tempsParalleleArchitectureColmun = (double)(ENDp1- beginP1 )/(CLOCKS_PER_SEC) ;
    printf("\nTemps Parallèle %f en seconde architecture colonne\n",tempsParalleleArchitectureColmun );
  }

/***************************************************/

  void* funcaoC(void *arg1) {
/************  Declaration & initialisation *************/
  int   endcol;
  int i,j,x;
  //int id = *((int *)arg1); 
  int id = arg1; 
  int quantiteDecol = N/NumThr;

/******************************************************/

/************ Calcul fin *************/
  if((id+1)==NumThr){

  endcol=N-1;

  }else{

  endcol=((id*quantiteDecol)+(quantiteDecol))-1;


  }
/*************************************/

/**********************Traitment******************************/
int f, h, v;
  for(f=id*quantiteDecol;f<=endcol;f++)
  {
    for(h=0;h<N;h++)
    {
       mult_p1[h][f]=0;   
        for(v=0; v<N; v++)
        {

         mult_p1[h][f]  += a[h][v] * b[v][f];
        
      } 
    
    }
  }
/********************************************************/

   return (NULL);
  }



