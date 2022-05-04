###!------------------------------------------------------------------
###! JOC DE PROVES DE TESEUS
###!---------------------------------------------------------------------
###!
###!
###!---------------------------------------------------------------------
###1 Laberints sense portes
###!---------------------------------------------------------------------
###!
#init lab1x1 laberint 1 1
#buscar 0 1 1 1
Error::teseus:61:La cambra inicial o final no es valida.
##Error::teseus:61:La cambra inicial o final no es valida.
#buscar 1 1 1 1
[(1,1)]
##[(1,1)]
###!
#init lab2x5 laberint 2 5
#buscar 1 2 1 1
Error::teseus:60:El laberint no te solucio.
##Error::teseus:60:El laberint no te solucio.
#buscar 1 6 1 1
Error::teseus:61:La cambra inicial o final no es valida.
##Error::teseus:61:La cambra inicial o final no es valida.
#buscar 1 1 1 1
[(1,1)]
##[(1,1)]
#buscar 2 1 2 1
[(2,1)]
##[(2,1)]
###!
#init lab3x3 laberint 3 3
#buscar 1 1 2 1
Error::teseus:60:El laberint no te solucio.
##Error::teseus:60:El laberint no te solucio.
#buscar 1 1 6 1  
Error::teseus:61:La cambra inicial o final no es valida.
##Error::teseus:61:La cambra inicial o final no es valida.
#buscar 1 1 1 1
[(1,1)]
##[(1,1)]
#buscar 3 3 3 3
[(3,3)]
##[(3,3)]
###!
#init lab5x2 laberint 5 2
#buscar 1 1 1 2
Error::teseus:60:El laberint no te solucio.
##Error::teseus:60:El laberint no te solucio.
#buscar 1 1 1 6
Error::teseus:61:La cambra inicial o final no es valida.
##Error::teseus:61:La cambra inicial o final no es valida.
#buscar 1 1 1 1
[(1,1)]
##[(1,1)]
#buscar 2 1 2 1
[(2,1)]
##[(2,1)]
#buscar 3 2 3 2
[(3,2)]
##[(3,2)]
#buscar 5 2 5 2
[(5,2)]
##[(5,2)]
###!
###!
#lab1x1 destroy
#lab2x5 destroy
#lab3x3 destroy
#lab5x2 destroy
###!
###!
###!---------------------------------------------------------------------
###2 Laberint 3x3 sense cicles
###!---------------------------------------------------------------------
###!
#init lab_unic laberint ./laberint_3x3.txt
#buscar 1 1 3 3
[(1,1),(1,2),(2,2),(3,2),(3,3)]
##[(1,1),(1,2),(2,2),(3,2),(3,3)]
#buscar 1 2 2 3
Error::teseus:60:El laberint no te solucio.
##Error::teseus:60:El laberint no te solucio.
#buscar 1 2 2 1
Error::teseus:60:El laberint no te solucio.
##Error::teseus:60:El laberint no te solucio.
#buscar 1 2 1 3
Error::teseus:60:El laberint no te solucio.
##Error::teseus:60:El laberint no te solucio.
#buscar 2 1 3 1
[(2,1),(3,1)]
##[(2,1),(3,1)]
#lab_unic destroy
###!
###!
###!---------------------------------------------------------------------
###3 Laberint 3x3 amb cicles
###!---------------------------------------------------------------------
###!
#init lab_cicle laberint ./laberint_3x3_cicles.txt
#buscar 1 3 3 3
[(1,3),(2,3),(3,3)]
##[(1,3),(2,3),(3,3)]
#buscar 1 2 2 3
[(1,2),(1,3),(2,3)]
##[(1,2),(1,3),(2,3)]
#buscar 1 2 2 1
[(1,2),(2,2),(2,1)]
##[(1,2),(2,2),(2,1)]
#comprova_cami_minim 1 2 3 3
true
##true
#lab_cicle destroy
###!
###!
