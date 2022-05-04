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
bool consulta_visitat(vector< pair< pair<nat,nat>, bool> > v, posicio pos){
//Pre:
//Post:
	
	for(int i = 0; i < v.size(); i++){
		if(v[i].first.first == pos.first and v[i].first.second == pos.second and v[i].second == true) return true;
		if(v[i].first.first == pos.first and v[i].first.second == pos.second and v[i].second == false) return false;
	
	}
	return false;
}

bool consulta_porta(cambra C){
//Pre:
//Post:
	if(C.porta_oberta(paret::NORD) or C.porta_oberta(paret::EST) or C.porta_oberta(paret::SUD) or C.porta_oberta(paret::OEST)) return true;
	return false;
}

bool puerta_comun(cambra C1, cambra C2, posicio p1, posicio p2){
	
	if(C1.porta_oberta(paret::NORD) and C2.porta_oberta(paret::SUD) and p1.first == p2.first+1 and p1.second == p2.second) return true;
	if(C2.porta_oberta(paret::NORD) and C1.porta_oberta(paret::SUD) and p2.first == p1.first+1 and p2.second == p1.second) return true;
	
	if(C1.porta_oberta(paret::EST) and C2.porta_oberta(paret::OEST) and p1.first == p2.first and p1.second+1 == p2.second) return true;
	if(C2.porta_oberta(paret::EST) and C1.porta_oberta(paret::OEST) and p2.first == p1.first and p2.second == p1.second+1) return true;	
	
	return false;
}

void teseus::buscar(const laberint & M, const posicio & inici, const posicio & final, std::list<posicio> & L) throw(error){
	nat f = M.num_files();
	nat c = M.num_columnes();
	
	//nat num_camb = f*c; 			//numero de cambras que tiene el laberinto
	
	cambra C; 
	
	//nat recorre = 1;	//variable que almazena el numero de cambras visitadas
	posicio actual, auxiliar;
	actual.first = inici.first;
	actual.second = inici.second;
	
	util::vector< pair< pair<nat,nat>, bool> > visitats;
	
	pair< pair<nat,nat>, bool> pos;
	pos.second = false;
	for(int i = 1; i < f; i++){
		for(int j = 1; j < c; j++){
			pos.first.first = i;
			pos.first.second = j;
			//cout<<"push_back"<<endl;
			visitats.push_back(pos);
		}
	}
	
	//cout << "xxxxxxxxdddddddddd"<<endl;
	posicio ant_ant, ant;
	ant = actual;	//crear una variable para tener en cuenta el anterior en caso de tener que retroceder
	
	if(inici.first == 0 or inici.second == 0 or inici.first > f or inici.second > c or final.first == 0 or final.second == 0 or final.first > f or final.second > c){
		throw error(IniciFinalNoValid);
	}
	else if(inici == final){	//si son la misma posicion, solo se accede a esa cambra 
		L.push_back(actual);
	}	
	else{
		nat dist = 0;
		//util::Random R;
		while(actual != final){
			
			//cout << actual.first << "    "<< actual.second << endl; 
			C = M(actual);
			auxiliar = actual;
			//cout << actual.first << "  "<< actual.second << "   : (T = 1, F = 0) -> "<< consulta_porta(C) <<endl;
			if(not consulta_porta(C)) throw error(SenseSolucio);		//si retorna true, es porque tiene todas sus puertas cerradas
			else if(C.porta_oberta(paret::NORD) and (ant.first != auxiliar.first-1 or ant.second != auxiliar.second) ){		// NORD
				//cout <<"NORD"<<endl;
				if(not consulta_visitat(visitats, actual)){			
					ant = actual;	//modificar el anterior al anterior
					L.push_back(actual);
					++dist;
					actual.first -= 1;	// == --i;         si el norte est aabierto, hay que subir a la cambra de arriba
				}
				else if(C.porta_oberta(paret::EST)) actual.second += 1;
				else if(C.porta_oberta(paret::SUD)) actual.first += 1;
				else if(C.porta_oberta(paret::OEST))actual.second -= 1;
			}
			else if(C.porta_oberta(paret::EST) and (ant.first != auxiliar.first or ant.second != auxiliar.second+1)){ 	// EST
				//cout <<"EST"<<endl;
				if(not consulta_visitat(visitats, actual)){	
					ant = actual;
					L.push_back(actual);
					++dist;
					actual.second += 1;	//++j;		si el este esta aabierto, hay que ir a la cambra de la derecha 
				}
				else if(C.porta_oberta(paret::NORD)) actual.first -= 1;
				else if(C.porta_oberta(paret::SUD)) actual.first += 1;
				else if(C.porta_oberta(paret::OEST)) actual.second -= 1;
				
			}
			else if(C.porta_oberta(paret::SUD) and (ant.first != auxiliar.first+1 or ant.second != auxiliar.second)){ 	// SUD
				//cout <<"SUD"<<endl;
				if(not consulta_visitat(visitats, actual)){	
					ant = actual;
					L.push_back(actual);
					++dist;
					actual.first += 1;	//++i;		si el sud esta aabierto, hay que ir a la cambra de abajo 
				}
				else if(C.porta_oberta(paret::NORD)) actual.first -= 1;
				else if(C.porta_oberta(paret::EST)) actual.second += 1;
				else if(C.porta_oberta(paret::OEST)) actual.second -= 1;
				
			}
			else if(C.porta_oberta(paret::OEST) and (ant.first != auxiliar.first or ant.second != auxiliar.second-1)){ 	// OEST
				//cout <<"OEST"<<endl;
				if(not consulta_visitat(visitats, actual)){	
					ant = actual;
					L.push_back(actual);
					++dist;
					actual.second -= 1;	//--j;		si el oeste esta aabierto, hay que ir a la cambra de la izquierda 
				}
				else if(C.porta_oberta(paret::NORD)) actual.first -= 1;
				else if(C.porta_oberta(paret::EST)) actual.second += 1;
				else if(C.porta_oberta(paret::SUD)) actual.first += 1;
				
			}
			else throw error(SenseSolucio);
			//if(actual.first == 3 and actual.second == 3) break;
			//else{ //si ya esta visitado
				//L.pop_back();
			//}
		//	ant = actual;
				
		
		}
		//cout <<" ant : "<< ant.first << "    "<< ant.second << endl;
		if(puerta_comun(M(ant), M(actual), ant, actual)) L.push_back(final);	//una vez se acaba, se pone un push_back de la posicion final
		else throw error(SenseSolucio);
	}

}

/* Gestió d'errors.
 const int SenseSolucio      = 60;
 const int IniciFinalNoValid = 61;
 
 #include "laberint.hpp"
 
 */
