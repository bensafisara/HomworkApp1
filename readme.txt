#Project TP-APP
Bensafi Sarra et Chikh Dounia
09/02/2021

 *** 1/ Introduction
 Ce mini-projet a pour but le calcul du produit matriciel selon la méthode séquentielle classique et la méthode parallele.

 *** 2/ Architecture

     --mmm.c:
                -Appel à "initMatrix", "displayMatrix", "funcThread", "funThreadC", "sequentielle", "verifMatrixequal", "funcThread_3", "VrifierPuissanceDeux" et "funcThread_4".
                -Allocation des matrices.
                -Création et affichage des matrices a et b.
                -Affichage du resultat du calcul parallele (ligne-colonne/colonne-ligne) et séquentiel.
                -Affichage et calcul du temps sequetiel et parallel en secondes.
                -Calcul et affichage du "speedup".
                -Affichage du resultat du calcul avec la methode de l'architecture 3 de bloc .
                -Affichage du resultat du calcul avec la methode de l'architecture 4 de bloc .




     --initMatrix.h:
                -Génére une matrice avec des valeurs aléatoires grace à la fonction "generateRandomMatrix".


     --displayMatrix.h:
                -Affiche la matrice grace à la fonction "printMatrix".


     --funcThread.h:
               -Déclaration variables locales et globales.
               -Appel de "displayMatrix".
               -Création des threads "initialisation".
               -Multiplication matricielle ligne/colonne "funcao".



     --funThreadC.h:
               -Déclaration variables locales et globales.
               -Appelle de "displayMatrix".
               -Création des threads "initialisationC".
               -Multiplication matricielle colonne/ligne "funcaoC".
     

     --verifMatrixequal.h:
               -Vérification de l'égalité de deux matrices.


     --sequentielle.h:
               -Fait le calcul du produit des deux matrices en séquentiel.


     --funcThread_3.h:
               -Déclaration variables locales et globales.
               -Appelle de "displayMatrix".
               -Multiplication matricielle selon l'architecture 3 des blocs.

     --funcThread_4.h:
               -Déclaration variables locales et globales.
               -Appelle de "displayMatrix".
               -Multiplication matricielle selon l'architecture 4 des blocs.


     --VrifierPuissanceDeux.h:
               -Vérifie si le nombre donné est une puissance de 2 ou non.


     


*** 2/ Execution:
                 cc mmm.c -o mmm -lpthread
                 ./mmm [dimension des matrix nxn * nxn ] [num thread] [mode de calcul p pour parallel s pour sequentiel]

*** 3/ Erreur: 

               -Affichage du message d'erreur "Specifier le mode sequentiel avec : s Specifier le mode parallel avec : p" lorsqu'on ne précise pas le mode de calcul.

               -Affichage du message d'erreur "Utiliser : ./mmm [dimension des matrix nxn * nxn ] [num thread] [mode de calcul 0 pour parallel 1 pour sequentiel]" lorsqu'il y'a une erreur de synthaxe lors de la saisie de la commande d'execution.

               -Affichage du message d'erreur "Erreur : Le nombre de threads doit etre une puissance de Deux pour pouvoir utliser l'architecture 3 des Blocs" lorsque l'utilisateur intriduit un nombre qui n'est pas un multiple de 2.


