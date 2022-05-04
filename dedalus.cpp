#include "dedalus.hpp"
  
/*
Respecto al algoritmo para generar los laberintos, hemos decidido desde el primer momento implementar Kruskal, porque es lo que se recomendó en clase y mirando los apuntes de teoría pensamos que es el más eficiente, ya que te da la opción de utilizar los MFSet(la Clase partición) de forma más cómoda.
Kruskal permite crear el laberinto a partir de la unión de las cámaras añadiéndolas a un mismo grupo; todas las cámaras se van recorriendo con el propósito final de que todas las cámaras estén en el mismo_grupo, y así se habrá creado el laberinto perfecto, sin ciclos y que se podrá ir de una cámara a cualquier cámara.
*/

//Coste : O(1) constante
bool consulta_puerta(cambra C){
//Pre: Una cambra C
//Post: Retorna TRUE si todas las puesrtas de la cambra estan cerradas, FALSE en caso contrario. 
	if(C.porta_oberta(paret::NORD) or C.porta_oberta(paret::EST) or C.porta_oberta(paret::SUD) or C.porta_oberta(paret::OEST)) return true;
	return false;
}
  
//Coste : O(n) siendo n el numero de cambras del laberinto --> n = num_filas * num_columnas del laberinto
void dedalus::construir(laberint & M) throw(error){
	
	nat f = M.num_files();
	nat c = M.num_columnes();
	nat num_camb = f*c; 				//numero de cambras que tiene el laberinto

	particio < posicio > p(num_camb); 	//crear una particio con f*c cambras 
	cambra C;
	
	posicio pos;
	
	for(nat i = 1; i <= f; i++){		//Crear una particion con las posiciones de cambras
		for(nat j = 1; j <= c; j++){
			
			pos.first = i;
			pos.second = j;
			C = M(pos);
			
			if(consulta_puerta(C)) throw error(EstaExcavat);

			p.afegir( pos );	//afegir la cambra de la posicion i,j correpondiente en la particion
		}
	}
	
	util::Random R;
	
	nat f_rand = R(1, f);	//coger una fila random
	nat c_rand = R(1, c);	//coger una columna random
	
	//guardar la fila y columna randoms en posicion
	pos.first = f_rand;	
	pos.second = c_rand;
	
	nat recorre = 1;	//variable que almazena el numero de cambras visitadas
	nat i = f_rand;	//guardar fila random 
	nat j = c_rand;	//guardar fila random 
	posicio p1, p2;
	
	while(recorre < num_camb){
		
		int paret_ran = R(0, 3); //crea pared random
		
		if( not (i == 1 and paret_ran == 0) and  not(j == c and paret_ran == 1) and  not(i == f and paret_ran == 2) and  not(j == 1 and paret_ran == 3)){	//mientras la pared random no sea una pared exterior 

			p1.first = i;
			p1.second = j;

			cambra Cambra1; 
			if(paret_ran == 0){		// NORD
								
				p2.first = i-1;
				p2.second = j;
				
				Cambra1 = M(p2); 
				
				//que la cambra actual y la cambra del norte no sean del mismo grupo y la cambra actual tenga todas sus puertas acerradad
				if(not p.mateix_grup( p1, p2) and not consulta_puerta(Cambra1)){	
					
					p.unir(p1, p2);			//unir cambra actual y cambra del norte en el mismo grupo
					M.obre_porta(paret::NORD, p1);	//abrir la puerta del norte
					
					++recorre;				//iterar el contador de cambras visitadas
				}
				
				--i;
			}
			else if(paret_ran == 1){ 	// EST
				
				p2.first = i;
				p2.second = j+1;
				
				Cambra1 = M(p2); 
				
				if(not p.mateix_grup( p1, p2 ) and not consulta_puerta(Cambra1)){
					
					p.unir(p1, p2);
					M.obre_porta(paret::EST, p1);
		
					++recorre;
				}
				
				++j;
			}
			else if(paret_ran == 2){ 	// SUD
				
				p2.first = i+1;
				p2.second = j;
				Cambra1 = M(p2); 
				if(not p.mateix_grup( p1, p2 ) and not consulta_puerta(Cambra1)){
					
					p.unir(p1, p2);
					M.obre_porta(paret::SUD, p1);
					
					++recorre;
				}
				
				++i;
			}
			else if(paret_ran == 3){ 	// OEST
				
				p2.first = i;
				p2.second = j-1;
				Cambra1 = M(p2); 
				if(not p.mateix_grup( p1, p2 ) and not consulta_puerta(Cambra1)){
					
					p.unir(p1, p2);
					M.obre_porta(paret::OEST, p1);

					++recorre;
				}
				
				--j;
			}
				
		}
		
	}

}

