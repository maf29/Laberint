###!------------------------------------------------------------------
###! JOC DE PROVES DE CAMBRA
###!------------------------------------------------------------------
###!
###!
###!------------------------------------------------------------------
###1 Cambra: Constructora
###!------------------------------------------------------------------
###!
###!------------------------------------------------------------------
###1.1 Constructora basica
###!------------------------------------------------------------------
###!
#init c cambra
#print_c
***
* *
***
##***
##* *
##***
###!
###!------------------------------------------------------------------
###1.2 Constructora 1 orientacio
###!------------------------------------------------------------------
###!
#init cN cambra N
#print_c
* *
* *
***
##* *
##* *
##***
#init cE cambra E
#print_c
***
*  
***
##***
##*  
##***
#init cO cambra O
#print_c
***
  *
***
##***
##  *
##***
#init cS cambra S
#print_c
***
* *
* *
##***
##* *
##* *
###!
###!------------------------------------------------------------------
###1.3 Constructora 2 orientacions
###!------------------------------------------------------------------
###!
#init cNS cambra N S
#print_c
* *
* *
* *
##* *
##* *
##* *
#init cEO cambra E O
#print_c
***
   
***
##***
##   
##***
#init cNE cambra N E
#print_c
* *
*  
***
##* *
##*  
##***
#init cNO cambra N O
#print_c
* *
  *
***
##* *
##  *
##***
#init cES cambra E S
#print_c
***
*  
* *
##***
##*  
##* *
#init cSO cambra S O
#print_c
***
  *
* *
##***
##  *
##* *
###!
###!------------------------------------------------------------------
###1.4 Constructora 3 orientacions
###!------------------------------------------------------------------
###!
#init cNES cambra N E S
#print_c
* *
*  
* *
##* *
##*  
##* *
#init cESO cambra E S O
#print_c
***
   
* *
##***
##   
##* *
#init cSON cambra S O N
#print_c
* *
  *
* *
##* *
##  *
##* *
#init cNEO cambra N E O
#print_c
* *
   
***
##* *
##   
##***
###!
###!------------------------------------------------------------------
###1.5 Constructora 4 orientacions
###!------------------------------------------------------------------
###!
#init cNESO cambra N E O S
#print_c
* *
   
* *
##* *
##   
##* *
###!
###!
###!------------------------------------------------------------------
###2 Cambra: constructora per copia i destructora
###!------------------------------------------------------------------
###!
#initcopy ccopia = c
#ccopia print_c
***
* *
***
##***
##* *
##***
#ccopia destroy
#initcopy ccopia = cNEO
#ccopia print_c
* *
   
***
##* *
##   
##***
#ccopia destroy
###!
###!
###!------------------------------------------------------------------
###3 Cambra: copia
###!------------------------------------------------------------------
###!
#init ccopia cambra
#ccopia = cNEO
#ccopia print_c
* *
   
***
##* *
##   
##***
#ccopia destroy
###!
###!
###!------------------------------------------------------------------
###4 Cambra: porta_oberta
###!------------------------------------------------------------------
###!
#c porta_oberta N
false
##false
#c porta_oberta E
false
##false
#c porta_oberta O
false
##false
#c porta_oberta S
false
##false
###!
#cN porta_oberta N
true
##true
#cN porta_oberta E
false
##false
#cN porta_oberta O
false
##false
#cN porta_oberta S
false
##false
###!
#cE porta_oberta N
false
##false
#cE porta_oberta E
true
##true
#cE porta_oberta O
false
##false
#cE porta_oberta S
false
##false
###!
#cO porta_oberta N
false
##false
#cO porta_oberta E
false
##false
#cO porta_oberta O
true
##true
#cO porta_oberta S
false
##false
###!
#cNES porta_oberta N
true
##true
#cNES porta_oberta E
true
##true
#cNES porta_oberta O
false
##false
#cNES porta_oberta S
true
##true
###!
#cESO porta_oberta N
false
##false
#cESO porta_oberta E
true
##true
#cESO porta_oberta O
true
##true
#cESO porta_oberta S
true
##true
###!
#cNESO porta_oberta N
true
##true
#cNESO porta_oberta E
true
##true
#cNESO porta_oberta O
true
##true
#cNESO porta_oberta S
true
##true
###!
#cNESO porta_oberta norte
false
##false
#cNESO porta_oberta NO_DIR
false
##false
#c porta_oberta NO_DIR
false
##false
###!
###!
###!------------------------------------------------------------------
###5 Cambra: obre_porta_c
###!------------------------------------------------------------------
###!
#c obre_porta_c N
#c print_c
* *
* *
***
##* *
##* *
##***
#c obre_porta_c E
#c print_c
* *
*  
***
##* *
##*  
##***
#c obre_porta_c O
#c print_c
* *
   
***
##* *
##   
##***
#c obre_porta_c S
#c print_c
* *
   
* *
##* *
##   
##* *
#c obre_porta_c S
#c print_c
* *
   
* *
##* *
##   
##* *
#c obre_porta_c Sur
Error::cambra:20:La paret no existeix.
##Error::cambra:20:La paret no existeix.
#c obre_porta_c NO_DIR
Error::cambra:20:La paret no existeix.
##Error::cambra:20:La paret no existeix.
###!
###!
###!------------------------------------------------------------------
###6 Cambra: tanca_porta_c
###!------------------------------------------------------------------
###!
#c tanca_porta_c N
#c print_c
***
   
* *
##***
##   
##* *
#c tanca_porta_c S
#c print_c
***
   
***
##***
##   
##***
#c tanca_porta_c O
#c print_c
***
*  
***
##***
##*  
##***
#c tanca_porta_c E
#c print_c
***
* *
***
##***
##* *
##***
#c tanca_porta_c E
#c print_c
***
* *
***
##***
##* *
##***
#c tanca_porta_c Norte
Error::cambra:20:La paret no existeix.
##Error::cambra:20:La paret no existeix.
#c tanca_porta_c NO_DIR
Error::cambra:20:La paret no existeix.
##Error::cambra:20:La paret no existeix.
###!
###!
###!------------------------------------------------------------------
###7 Cambra: ==
###!------------------------------------------------------------------
###!
#cNE == cNE
true
##true
#cN == cNE
false
##false
#c == c
true
##true
#cNESO == cNESO
true
##true
#initcopy cSOcopia = cSO
#cSOcopia == cSO
true
##true
#cSOcopia obre_porta_c N
#cSOcopia == cSO
false
##false
#cSOcopia == cSON
true
##true
###!
###!
###!------------------------------------------------------------------
###8 Cambra: !=
###!------------------------------------------------------------------
###!
#cNE != cNE
false
##false
#cN != cNE
true
##true
#c != c
false
##false
#cNESO != cNESO
false
##false
#initcopy cSOcopia = cSO
#cSOcopia != cSO
false
##false
#cSOcopia obre_porta_c N
#cSOcopia != cSO
true
##true
#cSOcopia != cSON
false
##false
#cSOcopia destroy
###!
###!
###!------------------------------------------------------------------
###9 Cambra: <
###!------------------------------------------------------------------
###!
#cN < cNE
true
##true
#cNE < cSO
false
##false
###!
###!
###!------------------------------------------------------------------
###10 Cambra: destruccio
###!------------------------------------------------------------------
###!
#c destroy
#cN destroy
#cE destroy
#cS destroy
#cO destroy
#cNE destroy
#cNS destroy
#cNO destroy 
#cES destroy
#cEO destroy
#cSO destroy
#cNES destroy
#cNEO destroy
#cESO destroy
#cSON destroy
#cNESO destroy
###!
###! Fi del joc de proves de cambra
###!
