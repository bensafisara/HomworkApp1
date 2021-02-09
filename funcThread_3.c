  /***************** Les includes ********************/
  #include <pthread.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include "displayMatrix.h"
  #include <math.h>
  #include "funcThread_3.h"  
  #include <stdbool.h> 

/*****************Declaration & initialisation ********************/
  int  **a;
  int  **b;
  int **mult_p_3 ; 
  extern int N;
  int NumThr;
  int *VecteurNumDesThreads;
  double tempsParalleleArchitecture3=0;
  void* funcaoR_3(void* arg);
  /***********************************************************/

                                    

  void initialisation_3(int nbTH){

  /************  Declaration & initialisation *************/

  pthread_t *thread=(pthread_t*)malloc(sizeof(pthread_t)*nbTH);
  long i;
  
  /***********************************************************/

/**********************Traitment******************************/
clock_t beginP = clock();
  for(i=0;i<nbTH;i++)
    {
  
       pthread_create(&thread[i], NULL, funcaoR_3, (void*)i);
    }
    

    for(i=0;i<nbTH;i++)
    {
       pthread_join(thread[i],NULL); 
    }
clock_t ENDp = clock();
/********************************************************/

/**********************Calcul Temps ******************************/
tempsParalleleArchitecture3 = (double)(ENDp- beginP )/(CLOCKS_PER_SEC);
printf("\nTemps Parallèle %f en secondes architecture 3 \n", tempsParalleleArchitecture3);
}
/***************************************************/

void* funcaoR_3(void *arg3){

/************  Declaration & initialisation *************/

int i,j,id,x, w ,sqrt_p, quantiteDeLigne,quantiteRestante;
int jdebut ,idebut ,iend,jend;
id = arg3; 
quantiteDeLigne = N/sqrt(NumThr);
sqrt_p=sqrt(NumThr);
w=id/sqrt(NumThr);
quantiteRestante = N % sqrt_p;

/******************************************************/



/****************Calcul j-Debut & Calcul i-Debut **********/
if(id<sqrt_p){

jdebut = id * quantiteDeLigne;

}else{

jdebut = (id % sqrt_p) *  quantiteDeLigne ;

}

idebut = w * quantiteDeLigne;

/*********************************************************/


/********************Calcul Fin**************************/
    iend = idebut + quantiteDeLigne -1 + quantiteRestante;
    jend= jdebut + quantiteDeLigne - 1 + quantiteRestante;
/*******************************************************/


/**********************Traitment******************************/

  for(i=idebut;i<=iend;i++)
  {
    for(j=jdebut;j<=jend;j++)
    {
        mult_p_3[i][j]=0;   
        for(x=0; x<N; x++)
        {

          mult_p_3[i][j]  += a[i][x] * b[x][j];
        
      } 
    
    }
  }


/************************************************/
   return (NULL);
  }



