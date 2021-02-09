  /***************** Les includes ********************/
  #include <pthread.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include "displayMatrix.h"
  #include "funcThread.h"

/*****************Declaration & initialisation ********************/
  int  **a;
  int  **b;
  int **mult_p ; 
  double tempsParalleleArchitectureRow=0;
  extern int N;
  int NumThr;
  int *VecteurNumDesThreads;
  void* funcaoR(void* arg);

/*****************************************************************/



  void initialisation(int nbTH){

  /*****************Declaration & initialisation ********************/
  pthread_t *thread=(pthread_t*)malloc(sizeof(pthread_t)*nbTH);
  long i;
  clock_t beginP = clock();
  /***************************************************************/

  /**********************Traitment******************************/
  for(i=0;i<nbTH;i++)
    {
      
      pthread_create(&thread[i], NULL, funcaoR, (void*)i);
    }
    
    for(i=0;i<nbTH;i++)
    {
       pthread_join(thread[i],NULL); 
    }
/********************************************************/
clock_t ENDp = clock();

/**********************Calcul Temps ******************************/
tempsParalleleArchitectureRow = (double)(ENDp- beginP )/(CLOCKS_PER_SEC);
printf("\nTemps Parallèle %f en secondes architecture en ligne\n", tempsParalleleArchitectureRow);

  }
/***************************************************/


  void* funcaoR(void *arg) 
  {
  /************  Declaration & initialisation *************/
  int   endRow;
  int i,j,x;
  //int id = *((int *)arg); 
  int id = arg; 
  int quantiteDeLigne = N/NumThr;
  int somme;
  /*******************************************************/

/************ Calcul fin *************/
  if((id+1)==NumThr){

       endRow=N-1;

  }else{

      endRow=((id*quantiteDeLigne)+(quantiteDeLigne))-1;
  }
/*************************************/

/**********************Traitment******************************/

  for(i=id*quantiteDeLigne;i<=endRow;i++)
  {
    for(j=0;j<N;j++)
    {   mult_p[i][j]=0;   
        for(x=0; x<N; x++)
        {

            mult_p[i][j]  += a[i][x] * b[x][j];
        } 
     }
  }
/********************************************************/
return (NULL);
  
  }




