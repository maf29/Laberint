#include "teseus.hpp"

#include <iostream>
using namespace std;
// Genera una llista de posicions que conté el camí mínim. El primer element
  // d'aquesta llista serà la posició inici, i l'última la posició final.
  // Una posició respecte a la seva anterior o posterior ha de ser consecutiva.
  // Dues posicions són consecutives si i només si la diferència de les primeres
  // components de les posicions és en valor absolut 1 i les segones components
  // són iguals, o si la diferència de les segones components és en valor
  // absolut 1 i les primeres components són iguals. Es produeix un error si no
  // hi ha cap camí que vagi des de la cambra inicial del laberint a la final,
  // o si la cambra inicial o final no són vàlides.
  
/*
	Algoritmo de dikjstra ==Z> Calcula la distància mínima entre el cambra indicat i tota la resta. (Retorna un vector d'n etiquetes == NO).
*/

nat N;

int posicion(posicio pos){
//Pre:
//Post:
	
	
	if(pos.first != 0){
		int num = N;
		int div = 2;
		while(num % div != 0){
			++div;
		}
		return num / div * (pos.first-1) + (pos.second-1);
	}
	else{
		return pos.second-1;
	}

}


bool consulta_porta(cambra C){
//Pre:
//Post:
	if(C.porta_oberta(paret::NORD) or C.porta_oberta(paret::EST) or C.porta_oberta(paret::SUD) or C.porta_oberta(paret::OEST)) return true;
	return false;
}


bool es_valid(const laberint & M, bool visitats[], nat fila, nat col, int p){
// 	
	
	return (fila > 0 and fila <= M.num_files()) and (col > 0 and col <= M.num_columnes()) and not visitats[p];
}

void teseus::buscar(const laberint & M, const posicio & inici, const posicio & final, std::list<posicio> & L) throw(error){
	nat f = M.num_files();
	nat c = M.num_columnes();
	
	nat num_camb = f*c; 			//numero de cambras que tiene el laberinto
	N = num_camb;
	cambra C; 
	
	posicio actual, auxiliar;
	actual = inici;
	
	posicio ant_ant, ant;
	ant = actual;	//crear una variable para tener en cuenta el anterior en caso de tener que retroceder
	
	if(inici.first == 0 or inici.second == 0 or inici.first > f or inici.second > c or final.first == 0 or final.second == 0 or final.first > f or final.second > c){
		throw error(IniciFinalNoValid);
	}
	else if(inici == final){	//si son la misma posicion, solo se accede a esa cambra 
		L.push_back(actual);
	}	
	else{
		
		//util::vector< pair<bool, bool> > visitats(num_camb);		//primer bool = visitat, segundo bool = camino actual
		bool visitats[num_camb];
		int p = posicion(inici);
		visitats[p] = true;				//posicion inici se pone a true
		//visitats[p].second = true;
		std::list< pair<posicio,int> > q;		//crear una lista para BFS
		
		pair<posicio,int> d;
		d.first = inici;
		d.second = 0;
		
		posicio predecesor[f][c];
		predecesor[inici.first-1][inici.second-1] = inici;
		
		q.push_back(d);	//se hace push_back de la posicion inicial y su distancia 0
		posicio pt;
		
		while(!q.empty()){
			pair<posicio,int> curr = *q.begin();
		
			pt = curr.first;
			p = posicion(pt);
			
			q.erase(q.begin());
			
			C = M(pt);
			posicio nord, est, sud, oest;
			
			
			if(not consulta_porta(C)) throw error(SenseSolucio);		//si retorna true, es porque tiene todas sus puertas cerradas
			
			nord = est = sud = oest = pt;
			
			nord.first=nord.first-1;
			int p_nord = posicion(nord);
			
			est.second=est.second+1;
			int p_est = posicion(est);
			
			sud.first=sud.first+1;
			int p_sud = posicion(sud);
			
			oest.second=oest.second-1;
			int p_oest = posicion(oest);
			
			pair<posicio,int> aux;
			bool afegir = false;
			if(es_valid(M, visitats, nord.first, nord.second, p_nord) and C.porta_oberta(paret::NORD)){	//NORD
				visitats[p_nord] = true;
				if(not afegir){
				
					L.push_back(pt);
					afegir = true;
				}
				
				predecesor[nord.first-1][nord.second-1] = pt;
				
				aux.first = nord;
				aux.second = curr.second+1;
				q.push_back(aux);
				
			}
			if(es_valid(M, visitats, est.first, est.second ,p_est) and C.porta_oberta(paret::EST)){	//EST
				
				visitats[p_est] = true;
				
				if(not afegir){
				
					L.push_back(pt);
					afegir = true;
				}
				predecesor[est.first-1][est.second-1] = pt;
				aux.first = est;
				aux.second = curr.second+1;
				q.push_back(aux);
			}
			if(es_valid(M, visitats, sud.first, sud.second, p_sud) and C.porta_oberta(paret::SUD)){	//SUD
				visitats[p_sud] = true;
				if(not afegir){
				
					L.push_back(pt);
					afegir = true;
				}
				predecesor[sud.first-1][sud.second-1] = pt;
				
				aux.first = sud;
				aux.second = curr.second+1;
				q.push_back(aux);
			}
			if(es_valid(M, visitats, oest.first, oest.second, p_oest) and C.porta_oberta(paret::OEST) ){	//OEST
				
				visitats[p_oest] = true;
				if(not afegir){
				
					L.push_back(pt);
					afegir = true;
				}
				predecesor[oest.first-1][oest.second-1] = pt;
				
				aux.first = oest;
				aux.second = curr.second+1;
				q.push_back(aux);
			}
			
			if(pt.first == final.first and pt.second == final.second and not afegir){
				
				L.push_back(pt);
				break;
			}
			else if(pt.first == final.first and pt.second == final.second) break;
			else if(not afegir) L.pop_back();
			
			
		}
		if(pt.first != final.first or pt.second != final.second) throw error(SenseSolucio);
		else{
			nat i = pt.first-1;
			nat j = pt.second-1;
			std::list<posicio> aux;
			posicio pos;
			
			while(i+1 != inici.first or j+1 != inici.second){ 
				pos.first = i+1; pos.second = j+1;
				aux.push_back(pos);
				
				posicio p = predecesor[i][j];
				
				i = p.first -1;
				
				j = p.second -1;
				
			}
			
			pos.first = i+1; pos.second = j+1;	//posicion pennultim
			aux.push_back(pos);
			
			
			//invertir llista
			//std::list<posicio> tmp;
			std::list<posicio>::iterator e = aux.end();
			e--;
			for(nat x = 0; x < aux.size(); x++){
				tmp.push_back(*e);
				e--;
			}
			
			L = tmp;
		}
			
	}
	
	if(L.size() == 0) throw error(SenseSolucio);

}

/* Gestió d'errors.
 const int SenseSolucio      = 60;
 const int IniciFinalNoValid = 61;
 
 #include "laberint.hpp"
 
 */
