all : tpAppFinale

tpAppFinale : mmm.o initMatrix.o displayMatrix.o funcThread.o funThreadC.o funcThread_3.o sequentiel.o VerifMatrixEqual.o  VrifierPuissanceDeux.o  
	cc mmm.o initMatrix.o displayMatrix.o funcThread.o funThreadC.o funcThread_3.o sequentiel.o VerifMatrixEqual.o  VrifierPuissanceDeux.o  -lpthread -lm -o tpAppFinale




initMatrix.o : initMatrix.c  
	cc  -c initMatrix.c 

displayMatrix.o : displayMatrix.c 
	cc -c displayMatrix.c 

funcThread.o : funcThread.c 
	cc -c funcThread.c 

funThreadC.o : funThreadC.c 
	cc -c funThreadC.c 

funcThread_3.o : funcThread_3.c 
	cc -c funcThread_3.c 

funcThread_4.o : funcThread_4.c 
	cc -c funcThread_4.c 

sequentiel.o : sequentiel.c 
	cc -c sequentiel.c 

VerifMatrixEqual.o : VerifMatrixEqual.c   
	cc -c VerifMatrixEqual.c 

VrifierPuissanceDeux.o : VrifierPuissanceDeux.c  
	cc -c VrifierPuissanceDeux.c 
	
mmm.o : mmm.c 
	cc  -c mmm.c 

clean: 
	rm *.o tpAppFinale


