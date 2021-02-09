  /***************** Les includes ********************/
  #include <pthread.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include "displayMatrix.h"
  #include <math.h>
  #include "funcThread_4.h"  
  #include <stdbool.h> 

/*****************Declaration & initialisation ********************/
  int  **a;
  int  **b;
  int **mult_p_4 ; 
  extern int N;
  int NumThr;
  int *VecteurNumDesThreads;
  double tempsParalleleArchitecture4=0;
  void* funcaoR_4(void* arg);
  /***********************************************************/

                       

  void initialisation_4(int nbTH){

  /************  Declaration & initialisation *************/

  pthread_t *thread=(pthread_t*)malloc(sizeof(pthread_t)*nbTH);
  long i;
  
  /***********************************************************/

/**********************Traitment******************************/
clock_t beginP = clock();
  for(i=0;i<nbTH;i++)
    {
  
       pthread_create(&thread[i], NULL, funcaoR_4, (void*)i);
    }
    

    for(i=0;i<nbTH;i++)
    {
       pthread_join(thread[i],NULL); 
    }
clock_t ENDp = clock();
/********************************************************/

/**********************Calcul Temps ******************************/
tempsParalleleArchitecture4 = (double)(ENDp- beginP )/(CLOCKS_PER_SEC);
printf("\nTemps Parallèle %f en secondes architecture 4 \n", tempsParalleleArchitecture4);
}
/***************************************************/

void* funcaoR_4(void *arg4){

/************  Declaration & initialisation *************/

int i,j,id,x, Psur2 ,cpt,Nsur2, quantiteDeLigne,quantiteRestante;
int jdebut ,idebut ,iend,jend;
id = arg4; 
Nsur2=N/2;
Psur2=NumThr/2;
quantiteDeLigne=Nsur2*(N/Psur2);
cpt=0;

/*******************************************************/

/****************Calcul i-Debut **********/
if(id < NumThr/2){

idebut =0;

}else{

idebut = N/2 ;

}




/********************Calcul i-end **************************/
                iend = idebut + (N/2)-1 ;
/*******************************************************/


/**********************Traitment******************************/

for(i=idebut;i<=iend;i++)
   {
    for(j=(j%(NumThr/2))*(N/(NumThr/2));j<= ((j%(NumThr/2))*(N/(NumThr/2)) + quantiteDeLigne) - 1 + quantiteRestante;j++)
    {
        mult_p_4[i][j]=0;   
        for(x=0; x<N; x++)
        {

           mult_p_4[i][j]  += a[i][x] * b[x][j];
        
      } 
    
    }
  }


/************************************************/
   return (NULL);
  }




