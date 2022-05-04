#include "teseus.hpp"

/*
Miramos las posibles opciones de implementaciones que podíamos hacer: Dijkstra, DFS, Prim, Lee y BFS. Entre todos estos hemos decidido escoger BFS (Breadth First Search), también conocido como recorrido en anchura, el cual va visitando todos los sucesores de sucesores y por último, comprueba si queda algún otro nodo por visitar. Si el algoritmo encuentra una solución, la devuelve y detiene la búsqueda, de lo contrario amplía el nodo y continúa el proceso de búsqueda.
El objetivo de este algoritmo es visitar todos los nodos del grafo, es decir, todos los cuartos del laberinto. Más concretamente, el algoritmo devuelve la solución que está más cercana a la raíz (posición de inicio), por lo que para los problemas de la transición de un nodo hasta sus nodos hijos costará 1. Como BFS considera todos los caminos que parten de la fuente, y avanza una unidad en todos esos caminos a la vez, asegura que la primera vez que se visita el destino, es el camino más corto.
*/

//Coste : O(1) constante
bool consulta_porta(cambra C){
//Pre: Una cambra C
//Post: Retorna TRUE si todas las puesrtas de la cambra estan cerradas, FALSE en caso contrario. 
	if(C.porta_oberta(paret::NORD) or C.porta_oberta(paret::EST) or C.porta_oberta(paret::SUD) or C.porta_oberta(paret::OEST)) return true;
	return false;
}

//Coste : O(1) constante
bool es_valid(const laberint & M, nat fila, nat col){
//Pre: -
//Post: Retorna true si la fila y col son filas y columnas del laberinto M, false en caso contrario

	return (fila > 0 and fila <= M.num_files()) and (col > 0 and col <= M.num_columnes());
}

//Cost peor:  O(f*c)+A. Siendo f*c el numero de Vertices (Cambras) del laberinto y A el numero de puertas abiertas por cada vertice (cambras adyacente)
void teseus::buscar(const laberint & M, const posicio & inici, const posicio & final, std::list<posicio> & L) throw(error){
	nat f = M.num_files();
	nat c = M.num_columnes();
	
	if(inici.first == 0 or inici.second == 0 or inici.first > f or inici.second > c or final.first == 0 or final.second == 0 or final.first > f or final.second > c){
		throw error(IniciFinalNoValid);
	}
	else if(inici == final){	//si el punto de partida y el final es la misma posicion, solo se accede a esa cambra 
		L.push_back(inici);
	}	
	else{

		bool visitats[f][c];		//matriz para poner a true las cambras ya visitadas y no crear ciclos
		posicio predecesor[f][c];	//matriz para poner la posicion de la cambra anterior a la posicion correspondiente de la matriz 
		
		posicio pos;
		pos.first = 0; pos.second = 0;
		
		for(nat i = 0; i < f; i++){		//buscles para recorrer todas las posiciones de las matrices de arrays e inicializarlos
			for(nat j = 0; j < c; j++){
				visitats[i][j] = false;
				predecesor[i][j] = pos;
			}
		} 
		
		visitats[inici.first-1][inici.second-1] = true;		//posicion inciial se pone a true
		predecesor[inici.first-1][inici.second-1] = inici;		//el predecesor de la posicion inicial es ella porpia 


		std::list< posicio> q;		//crear una lista auxiliar para recorrer BFS (en amplada)
		cambra C;
		
		q.push_back(inici);	//se hace push_back de la posicion inicial para comenzar a recorrer en amplada
		posicio pt;
		
		while(!q.empty()){	//mientras la lista de posiciones no sea vacia
		
			pt  = *q.begin();	//curr es donde se guardara la primera posicion que esta en la lista q
			
			q.pop_front();		//borrar el primer elemento de la lista para seguir tratando los siguientes elementos 
			
			C = M(pt);		//guardar la cambra de la posicion actual
			
			
			if(not consulta_porta(C)) throw error(SenseSolucio);		//si retorna true, es porque tiene todas sus puertas cerradas por lo tanto no tiene solucion
			
			if(pt.first == final.first and pt.second == final.second) break;	//Si pt es la posicion final, no seguir recorriendo 
			
			posicio nord, est, sud, oest;		//crear auxiliares que correrponden a las posiciones nord, est, oest y sud de la posicion pt
			nord = est = sud = oest = pt;
			
			nord.first=nord.first-1;
			
			est.second=est.second+1;
			
			sud.first=sud.first+1;
			
			oest.second=oest.second-1;
			
			
			if(es_valid(M, nord.first, nord.second) and not visitats[nord.first-1][nord.second-1] and C.porta_oberta(paret::NORD)){	//NORD
				visitats[nord.first-1][nord.second-1] = true;		//si no se habia visitado anteriormente la posicion, ponerla a true
				
				predecesor[nord.first-1][nord.second-1] = pt;		//poner su predecesor, que es pt
				
				q.push_back(nord);	//añadir la posicion 
				
			}
			if(es_valid(M, est.first, est.second) and not visitats[est.first-1][est.second-1] and C.porta_oberta(paret::EST)){	//EST
				visitats[est.first-1][est.second-1] = true;
				
				predecesor[est.first-1][est.second-1] = pt;
				
				q.push_back(est);
			}
			if(es_valid(M, sud.first, sud.second) and not visitats[sud.first-1][sud.second-1] and  C.porta_oberta(paret::SUD)){	//SUD
				visitats[sud.first-1][sud.second-1] = true;

				predecesor[sud.first-1][sud.second-1] = pt;
				
				q.push_back(sud);
			}
			
			
			if(es_valid(M, oest.first, oest.second) and not visitats[oest.first-1][oest.second-1] and C.porta_oberta(paret::OEST) ){	//OEST
				visitats[oest.first-1][oest.second-1] = true;

				predecesor[oest.first-1][oest.second-1] = pt;
				
				q.push_back(oest);
			}
			
		}
		
		if(pt.first != final.first or pt.second != final.second) throw error(SenseSolucio);
		else{
			nat i = pt.first-1;
			nat j = pt.second-1;
			
			
			while(i+1 != inici.first or j+1 != inici.second){		//bucle para llenar la lista L con las posiciones visitadas
				pos.first = i+1; pos.second = j+1;
				L.push_front(pos);
				
				posicio p = predecesor[i][j];
				
				i = p.first-1;
				
				j = p.second-1;
			}
			
			pos.first = i+1; pos.second = j+1;	// añadir ultima posicion
			L.push_front(pos);
			
		}
		
	}

}
