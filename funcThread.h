
  #ifndef funcao_H_
  #define funcao_H_

  
  int  **a;
  int  **b;
  int **mult_p ; 


  extern int N;
  int NumThr;
  int *VecteurNumDesThreads;

  void* funcaoR(void* arg);
  void initialisation(int nbTH);


  



#endif
