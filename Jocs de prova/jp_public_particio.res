###!---------------------------------------------------------------------
###!
###! JOC DE PROVES DE PARTICIO<T>
###!
###! Provarem la particio amb enters (si funciona correctament
###! amb enters, tambe ho fara amb altres tipus).
###!---------------------------------------------------------------------
###!
###!
###!---------------------------------------------------------------------
###1 Particio de 1, 2 i 9 elements
###!---------------------------------------------------------------------
###!
###!---------------------------------------------------------------------
###1.1 Constructor i insercio
###!---------------------------------------------------------------------
###!
###! Constructor particio buida
#init p0 particio<int> 0
###! Intentem inserir element sobrepassant maxim
#p0 afegir 1
Error::particio<T>:41:Particio plena.
##Error::particio<T>:41:Particio plena.
###!
###! Constructor particio amb 1 element
#init p1 particio<int> 1
#p1 afegir 3
###! Intentem inserir element sobrepassant maxim
#p1 afegir 1
Error::particio<T>:41:Particio plena.
##Error::particio<T>:41:Particio plena.
###!
###! Constructor particio amb 2 elements pero espai per 9 elements
#init p2 particio<int> 9
#p2 afegir 3
#p2 afegir 7
###!
###! Constructor particio amb multiples elements
#init p9 particio<int> 9
#p9 afegir 3
#p9 afegir 79
#p9 afegir 5
#p9 afegir 10
#p9 afegir 2
#p9 afegir 9
#p9 afegir 4
#p9 afegir 12
#p9 afegir 15
###! Intentem inserir element repetit
#p9 afegir 5
###! Intentem inserir element sobrepassant maxim
#p9 afegir 1
Error::particio<T>:41:Particio plena.
##Error::particio<T>:41:Particio plena.
###!
###!---------------------------------------------------------------------
###1.2 Consultora numero blocs
###!---------------------------------------------------------------------
###!
#p0 size
0
##0
#p1 size
1
##1
#p2 size
2
##2
#p9 size
9
##9
###!
###!---------------------------------------------------------------------
###1.3 Consultora numero elements i numero maxim
###!---------------------------------------------------------------------
###!
#p0 num_elems
0
##0
#p0 num_maxim
0
##0
###!
###!
#p1 num_elems
1
##1
#p1 num_maxim
1
##1
###!
###!
#p2 num_elems
2
##2
#p2 num_maxim
9
##9
###!
###!
#p9 num_elems
9
##9
#p9 num_maxim
9
##9
###!
###!---------------------------------------------------------------------
###1.4 Unio de blocs
###!---------------------------------------------------------------------
###!
#p0 unir 0 0
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p0 unir 1 1
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
###!
###!
#p1 unir 0 1
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p1 unir 3 0
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p1 unir 2 3
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p1 unir 3 3
###!
###!
#p2 unir 0 7
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p2 unir 7 4
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p2 unir 7 7
#p2 unir 7 3
#p2 unir 3 7
###!
###!
#p9 unir 0 5
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p9 unir 5 6
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p9 unir 12 3
#p9 unir 5 9
#p9 unir 15 5
###!
###!---------------------------------------------------------------------
###1.5 Elements pertanyen al mateix bloc
###!---------------------------------------------------------------------
###!
#p0 equiv 0 0
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p0 equiv 1 1
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
###!
###!
#p1 equiv 0 1
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p1 equiv 3 0
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p1 equiv 2 3
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p1 equiv 3 3
true
##true
###!
###!
#p2 equiv 0 7
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p2 equiv 7 4
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p2 equiv 7 7
true
##true
#p2 equiv 7 3
true
##true
#p2 equiv 3 7
true
##true
###!
###!
#p9 equiv 0 5
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p9 equiv 5 6
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p9 equiv 12 3
true
##true
#p9 equiv 3 12
true
##true
#p9 equiv 5 9
true
##true
#p9 equiv 15 5
true
##true
#p9 equiv 9 15
true
##true
#p9 equiv 15 9
true
##true
#p9 equiv 2 2
true
##true
#p9 equiv 15 15
true
##true
#p9 equiv 2 3
false
##false
#p9 equiv 5 12
false
##false
#p9 equiv 10 15
false
##false
#p9 equiv 5 4
false
##false
###!
###!---------------------------------------------------------------------
###1.6 Consultora numero blocs (despres de fer unions)
###!---------------------------------------------------------------------
###!
#p0 size
0
##0
#p1 size
1
##1
#p2 size
1
##1
#p9 size
6
##6
###!
###!---------------------------------------------------------------------
###1.7 Consultora numero elements i numero maxim sobre 
###!   copies de particio (despres de fer unions)
###!---------------------------------------------------------------------
###!
#p0 num_elems
0
##0
#p0 num_maxim
0
##0
###!
###!
#p1 num_elems
1
##1
#p1 num_maxim
1
##1
###!
###!
#p2 num_elems
2
##2
#p2 num_maxim
9
##9
###!
###!
#p9 num_elems
9
##9
#p9 num_maxim
9
##9
###!
###!---------------------------------------------------------------------
###2 Constructors per copia, destructores i assignacio
###!---------------------------------------------------------------------
###!
###!---------------------------------------------------------------------
###2.1 Inicialitzacions
###!---------------------------------------------------------------------
###!
#initcopy pp0 = p0
#initcopy pp1 = p1
#initcopy pp2 = p2
#initcopy pp9 = p9
#p0 destroy
#p1 destroy
#p2 destroy
#p9 destroy
#init p0 particio<int> 10
#init p1 particio<int> 10
#init p2 particio<int> 10
#init p9 particio<int> 10
#p0 = pp0
#p1 = pp1
#p2 = pp2
#p9 = pp9
#pp0 destroy
#pp1 destroy
#pp2 destroy
#pp9 destroy
###!
###!---------------------------------------------------------------------
###2.2 Consultora numero blocs sobre copies de particio
###!---------------------------------------------------------------------
###!
#p0 size
0
##0
#p1 size
1
##1
#p2 size
1
##1
#p9 size
6
##6
###!
###!---------------------------------------------------------------------
###2.3 Consultora numero elements i numero maxim sobre copies de particio
###!---------------------------------------------------------------------
###!
#p0 num_elems
0
##0
#p0 num_maxim
0
##0
###!
###!
#p1 num_elems
1
##1
#p1 num_maxim
1
##1
###!
###!
#p2 num_elems
2
##2
#p2 num_maxim
9
##9
###!
###!
#p9 num_elems
9
##9
#p9 num_maxim
9
##9
###!
###!---------------------------------------------------------------------
###2.4 Unio de blocs sobre copies de particio
###!---------------------------------------------------------------------
###!
#p9 unir 0 5
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p9 unir 5 6
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p9 unir 4 2
#p9 unir 2 9
###!
###!---------------------------------------------------------------------
###2.5 Elements pertanyen al mateix bloc sobre copies de particio
###!---------------------------------------------------------------------
###!
#p0 equiv 0 0
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p0 equiv 1 1
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
###!
###!
#p1 equiv 0 1
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p1 equiv 3 0
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p1 equiv 2 3
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p1 equiv 3 3
true
##true
###!
###!
#p2 equiv 0 7
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p2 equiv 7 4
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p2 equiv 7 7
true
##true
#p2 equiv 7 3
true
##true
#p2 equiv 3 7
true
##true
###!
###!
#p9 equiv 0 5
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p9 equiv 5 6
Error::particio<T>:40:L'element no pertany a la particio.
##Error::particio<T>:40:L'element no pertany a la particio.
#p9 equiv 12 3
true
##true
#p9 equiv 3 12
true
##true
#p9 equiv 5 9
true
##true
#p9 equiv 15 5
true
##true
#p9 equiv 9 15
true
##true
#p9 equiv 15 9
true
##true
#p9 equiv 2 2
true
##true
#p9 equiv 15 15
true
##true
#p9 equiv 2 3
false
##false
#p9 equiv 5 12
false
##false
#p9 equiv 10 15
false
##false
#p9 equiv 5 4
true
##true
###!
###!---------------------------------------------------------------------
###2.6 Consultora numero blocs (despres de fer unions)
###!---------------------------------------------------------------------
###!
#p0 size
0
##0
#p1 size
1
##1
#p2 size
1
##1
#p9 size
4
##4
###!
###!---------------------------------------------------------------------
###2.7 Consultora numero elements i numero maxim sobre 
###!   copies de particio (despres de fer unions)
###!---------------------------------------------------------------------
###!
#p0 num_elems
0
##0
#p0 num_maxim
0
##0
###!
###!
#p1 num_elems
1
##1
#p1 num_maxim
1
##1
###!
###!
#p2 num_elems
2
##2
#p2 num_maxim
9
##9
###!
###!
#p9 num_elems
9
##9
#p9 num_maxim
9
##9
###!
#p0 destroy
#p1 destroy
#p2 destroy
#p9 destroy
###!
###! Fi del joc de proves de particio
###!
