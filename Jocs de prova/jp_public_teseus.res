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
###!---------------------------------------------------------------------
###4 Laberint 30x30 sense cicles
###!---------------------------------------------------------------------
###!
#init lab_gran laberint ./laberint_30x30.txt
#buscar 1 3 3 3
[(1,3),(1,4),(1,5),(2,5),(2,4),(2,3),(3,3)]
##[(1,3),(1,4),(1,5),(2,5),(2,4),(2,3),(3,3)]
#buscar 1 2 2 3
[(1,2),(2,2),(2,3)]
##[(1,2),(2,2),(2,3)]
#buscar 1 2 2 1
[(1,2),(1,1),(2,1)]
##[(1,2),(1,1),(2,1)]
#buscar 10 20 22 14
[(10,20),(10,21),(9,21),(9,22),(8,22),(7,22),(6,22),(5,22),(4,22),(3,22),(3,21),(4,21),(5,21),(5,20),(4,20),(4,19),(5,19),(6,19),(6,20),(7,20),(7,19),(8,19),(9,19),(10,19),(11,19),(11,18),(11,17),(12,17),(12,16),(12,15),(13,15),(13,16),(14,16),(14,17),(15,17),(15,16),(15,15),(16,15),(17,15),(18,15),(19,15),(20,15),(21,15),(21,14),(22,14)]
##[(10,20),(10,21),(9,21),(9,22),(8,22),(7,22),(6,22),(5,22),(4,22),(3,22),(3,21),(4,21),(5,21),(5,20),(4,20),(4,19),(5,19),(6,19),(6,20),(7,20),(7,19),(8,19),(9,19),(10,19),(11,19),(11,18),(11,17),(12,17),(12,16),(12,15),(13,15),(13,16),(14,16),(14,17),(15,17),(15,16),(15,15),(16,15),(17,15),(18,15),(19,15),(20,15),(21,15),(21,14),(22,14)]
#buscar 30 30 1 1
[(30,30),(30,29),(30,28),(29,28),(29,27),(29,26),(29,25),(28,25),(28,26),(27,26),(26,26),(26,25),(27,25),(27,24),(27,23),(28,23),(29,23),(29,22),(28,22),(28,21),(29,21),(29,20),(28,20),(27,20),(27,19),(26,19),(26,20),(25,20),(25,19),(24,19),(24,20),(23,20),(22,20),(21,20),(21,19),(20,19),(19,19),(18,19),(17,19),(16,19),(16,18),(16,17),(17,17),(17,16),(17,15),(18,15),(19,15),(19,14),(19,13),(19,12),(19,11),(19,10),(19,9),(20,9),(21,9),(21,10),(22,10),(22,9),(23,9),(23,8),(23,7),(23,6),(22,6),(22,5),(22,4),(22,3),(21,3),(21,4),(21,5),(20,5),(19,5),(19,4),(18,4),(18,5),(17,5),(17,4),(16,4),(16,3),(16,2),(15,2),(15,3),(15,4),(14,4),(14,5),(13,5),(12,5),(12,6),(11,6),(10,6),(9,6),(8,6),(8,7),(7,7),(6,7),(6,6),(5,6),(5,5),(6,5),(7,5),(7,4),(7,3),(7,2),(8,2),(8,1),(7,1),(6,1),(5,1),(4,1),(3,1),(2,1),(1,1)]
##[(30,30),(30,29),(30,28),(29,28),(29,27),(29,26),(29,25),(28,25),(28,26),(27,26),(26,26),(26,25),(27,25),(27,24),(27,23),(28,23),(29,23),(29,22),(28,22),(28,21),(29,21),(29,20),(28,20),(27,20),(27,19),(26,19),(26,20),(25,20),(25,19),(24,19),(24,20),(23,20),(22,20),(21,20),(21,19),(20,19),(19,19),(18,19),(17,19),(16,19),(16,18),(16,17),(17,17),(17,16),(17,15),(18,15),(19,15),(19,14),(19,13),(19,12),(19,11),(19,10),(19,9),(20,9),(21,9),(21,10),(22,10),(22,9),(23,9),(23,8),(23,7),(23,6),(22,6),(22,5),(22,4),(22,3),(21,3),(21,4),(21,5),(20,5),(19,5),(19,4),(18,4),(18,5),(17,5),(17,4),(16,4),(16,3),(16,2),(15,2),(15,3),(15,4),(14,4),(14,5),(13,5),(12,5),(12,6),(11,6),(10,6),(9,6),(8,6),(8,7),(7,7),(6,7),(6,6),(5,6),(5,5),(6,5),(7,5),(7,4),(7,3),(7,2),(8,2),(8,1),(7,1),(6,1),(5,1),(4,1),(3,1),(2,1),(1,1)]
#buscar 1 1 30 30
[(1,1),(2,1),(3,1),(4,1),(5,1),(6,1),(7,1),(8,1),(8,2),(7,2),(7,3),(7,4),(7,5),(6,5),(5,5),(5,6),(6,6),(6,7),(7,7),(8,7),(8,6),(9,6),(10,6),(11,6),(12,6),(12,5),(13,5),(14,5),(14,4),(15,4),(15,3),(15,2),(16,2),(16,3),(16,4),(17,4),(17,5),(18,5),(18,4),(19,4),(19,5),(20,5),(21,5),(21,4),(21,3),(22,3),(22,4),(22,5),(22,6),(23,6),(23,7),(23,8),(23,9),(22,9),(22,10),(21,10),(21,9),(20,9),(19,9),(19,10),(19,11),(19,12),(19,13),(19,14),(19,15),(18,15),(17,15),(17,16),(17,17),(16,17),(16,18),(16,19),(17,19),(18,19),(19,19),(20,19),(21,19),(21,20),(22,20),(23,20),(24,20),(24,19),(25,19),(25,20),(26,20),(26,19),(27,19),(27,20),(28,20),(29,20),(29,21),(28,21),(28,22),(29,22),(29,23),(28,23),(27,23),(27,24),(27,25),(26,25),(26,26),(27,26),(28,26),(28,25),(29,25),(29,26),(29,27),(29,28),(30,28),(30,29),(30,30)]
##[(1,1),(2,1),(3,1),(4,1),(5,1),(6,1),(7,1),(8,1),(8,2),(7,2),(7,3),(7,4),(7,5),(6,5),(5,5),(5,6),(6,6),(6,7),(7,7),(8,7),(8,6),(9,6),(10,6),(11,6),(12,6),(12,5),(13,5),(14,5),(14,4),(15,4),(15,3),(15,2),(16,2),(16,3),(16,4),(17,4),(17,5),(18,5),(18,4),(19,4),(19,5),(20,5),(21,5),(21,4),(21,3),(22,3),(22,4),(22,5),(22,6),(23,6),(23,7),(23,8),(23,9),(22,9),(22,10),(21,10),(21,9),(20,9),(19,9),(19,10),(19,11),(19,12),(19,13),(19,14),(19,15),(18,15),(17,15),(17,16),(17,17),(16,17),(16,18),(16,19),(17,19),(18,19),(19,19),(20,19),(21,19),(21,20),(22,20),(23,20),(24,20),(24,19),(25,19),(25,20),(26,20),(26,19),(27,19),(27,20),(28,20),(29,20),(29,21),(28,21),(28,22),(29,22),(29,23),(28,23),(27,23),(27,24),(27,25),(26,25),(26,26),(27,26),(28,26),(28,25),(29,25),(29,26),(29,27),(29,28),(30,28),(30,29),(30,30)]
#lab_gran destroy
###!
###! Fi del joc de proves de teseus
###!
