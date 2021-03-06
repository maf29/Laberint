#init lab_unic laberint ./laberint_3x3.txt
#init lab_cicle laberint ./laberint_3x3_cicles.txt
#init lab_sense_portes laberint ./laberint_3x3_senseportes.txt
#init lab_gran laberint ./laberint_100x100.txt
#init lab1 laberint ./laberint_7x15.txt
#init lab2 laberint ./laberint_12x3.txt
#init lab3 laberint 1 1
#init lab4 laberint 20 2
#init lab5 laberint ./laberint_3x3_senseportes.txt
###!------------------------------------------------------------------
###5 Laberint: obre_porta
###!------------------------------------------------------------------
###!
###!------------------------------------------------------------------
###5.1 Obertura erronia
###!------------------------------------------------------------------
###!
#lab1 obre_porta_l Norte 2 2
Error::cambra:20:La paret no existeix.
##Error::cambra:20:La paret no existeix.
#lab1 obre_porta_l N 0 0
Error::laberint:31:La posicio no existeix.
##Error::laberint:31:La posicio no existeix.
#lab1 obre_porta_l S 7 16
Error::laberint:31:La posicio no existeix.
##Error::laberint:31:La posicio no existeix.
#lab1 obre_porta_l S 8 15
Error::laberint:31:La posicio no existeix.
##Error::laberint:31:La posicio no existeix.
#lab3 obre_porta_l E 1 2
Error::laberint:31:La posicio no existeix.
##Error::laberint:31:La posicio no existeix.
###!
#lab1 obre_porta_l N 1 1
Error::laberint:32:No es pot obrir una porta a l'exterior.
##Error::laberint:32:No es pot obrir una porta a l'exterior.
#lab1 obre_porta_l N 1 8
Error::laberint:32:No es pot obrir una porta a l'exterior.
##Error::laberint:32:No es pot obrir una porta a l'exterior.
#lab1 obre_porta_l S 7 14
Error::laberint:32:No es pot obrir una porta a l'exterior.
##Error::laberint:32:No es pot obrir una porta a l'exterior.
#lab1 obre_porta_l O 3 1
Error::laberint:32:No es pot obrir una porta a l'exterior.
##Error::laberint:32:No es pot obrir una porta a l'exterior.
#lab1 obre_porta_l E 2 15
Error::laberint:32:No es pot obrir una porta a l'exterior.
##Error::laberint:32:No es pot obrir una porta a l'exterior.
###!
#lab3 obre_porta_l N 1 1
Error::laberint:32:No es pot obrir una porta a l'exterior.
##Error::laberint:32:No es pot obrir una porta a l'exterior.
#lab3 obre_porta_l S 1 1
Error::laberint:32:No es pot obrir una porta a l'exterior.
##Error::laberint:32:No es pot obrir una porta a l'exterior.
#lab3 obre_porta_l E 1 1
Error::laberint:32:No es pot obrir una porta a l'exterior.
##Error::laberint:32:No es pot obrir una porta a l'exterior.
#lab3 obre_porta_l O 1 1
Error::laberint:32:No es pot obrir una porta a l'exterior.
##Error::laberint:32:No es pot obrir una porta a l'exterior.
###!
###!------------------------------------------------------------------
###5.2 Obertura correcta
###!------------------------------------------------------------------
###!
###! les seguents operacions es realitzen amb lab5 (3x3)
#sel_curr_obj lab5
#obre_porta_l S 1 1
#print
3 3
*******
* * * *
* *****
* * * *
*******
* * * *
*******
##3 3
##*******
##* * * *
##* *****
##* * * *
##*******
##* * * *
##*******
#obre_porta_l S 1 1
#print
3 3
*******
* * * *
* *****
* * * *
*******
* * * *
*******
##3 3
##*******
##* * * *
##* *****
##* * * *
##*******
##* * * *
##*******
#obre_porta_l N 2 1
#print
3 3
*******
* * * *
* *****
* * * *
*******
* * * *
*******
##3 3
##*******
##* * * *
##* *****
##* * * *
##*******
##* * * *
##*******
#obre_porta_l O 2 2
#print
3 3
*******
* * * *
* *****
*   * *
*******
* * * *
*******
##3 3
##*******
##* * * *
##* *****
##*   * *
##*******
##* * * *
##*******
#obre_porta_l O 3 3
#print
3 3
*******
* * * *
* *****
*   * *
*******
* *   *
*******
##3 3
##*******
##* * * *
##* *****
##*   * *
##*******
##* *   *
##*******
#obre_porta_l E 3 1
#print
3 3
*******
* * * *
* *****
*   * *
*******
*     *
*******
##3 3
##*******
##* * * *
##* *****
##*   * *
##*******
##*     *
##*******
###!
###!
###!------------------------------------------------------------------
###6 Laberint: operator() 
###!------------------------------------------------------------------
###!
###!------------------------------------------------------------------
###6.1 Consultes correctes
###!------------------------------------------------------------------
###!
#obt_cambra 1 1
***
* *
* *
##***
##* *
##* *
#obt_cambra 3 3
***
  *
***
##***
##  *
##***
#obt_cambra 2 1
* *
*  
***
##* *
##*  
##***
#obt_cambra 1 2
***
* *
***
##***
##* *
##***
#obt_cambra 2 2
***
  *
***
##***
##  *
##***
###!
###!------------------------------------------------------------------
###6.2 Consultes incorrectes
###!------------------------------------------------------------------
###!
#lab3 obt_cambra 4 1
Error::laberint:31:La posicio no existeix.
##Error::laberint:31:La posicio no existeix.
#lab5 obt_cambra 0 2
Error::laberint:31:La posicio no existeix.
##Error::laberint:31:La posicio no existeix.
###!
###!
###!------------------------------------------------------------------
###7 Laberint:tanca_porta
###!------------------------------------------------------------------
###!
###!------------------------------------------------------------------
###7.1 Tancaments correctes
###!------------------------------------------------------------------
###!
#sel_curr_obj lab5
#tanca_porta_l N 1 1
#obt_cambra 1 1
***
* *
* *
##***
##* *
##* *
#tanca_porta_l S 1 1
#obt_cambra 1 1
***
* *
***
##***
##* *
##***
#obt_cambra 2 1
***
*  
***
##***
##*  
##***
#tanca_porta_l O 3 3
#print
3 3
*******
* * * *
*******
*   * *
*******
*   * *
*******
##3 3
##*******
##* * * *
##*******
##*   * *
##*******
##*   * *
##*******
#tanca_porta_l E 3 3
#print
3 3
*******
* * * *
*******
*   * *
*******
*   * *
*******
##3 3
##*******
##* * * *
##*******
##*   * *
##*******
##*   * *
##*******
#tanca_porta_l E 2 1
#print
3 3
*******
* * * *
*******
* * * *
*******
*   * *
*******
##3 3
##*******
##* * * *
##*******
##* * * *
##*******
##*   * *
##*******
#tanca_porta_l S 2 2
#print
3 3
*******
* * * *
*******
* * * *
*******
*   * *
*******
##3 3
##*******
##* * * *
##*******
##* * * *
##*******
##*   * *
##*******
#tanca_porta_l S 3 2
#print
3 3
*******
* * * *
*******
* * * *
*******
*   * *
*******
##3 3
##*******
##* * * *
##*******
##* * * *
##*******
##*   * *
##*******
###!
#lab1 destroy
#lab2 destroy
#lab3 destroy
#lab4 destroy
#lab5 destroy
###!
###! Fi del joc de proves de laberint
###! 
