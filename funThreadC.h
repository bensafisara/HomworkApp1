 #ifndef funcaoC_H_
  #define funcaoC_H_
 
 int  **a;
  int  **b;
  int **mult_p1 ; 
  extern int N;
  int NumThr;
  int *VecteurNumDesThreads;

void* funcaoC(void* arg1);
void initialisationC(int nbTH1);
  

#endif
