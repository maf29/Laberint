#include "laberint.hpp"
#include <sstream>

//Coste : O(_pos.first) siendo _pos.first el numero de filas del laberinto
laberint::laberint(nat num_fil, nat num_col) throw(error){
	
	if(num_fil == 0 or num_col == 0) throw error(FilsColsIncorrecte);
	else {
		_pos.first = num_fil;
		
		_lab = new cambra*[_pos.first]; //crear columna
		
		_pos.second = num_col;
		for (nat i = 0; i < _pos.first; i++){	//crear filas de columnas
    			_lab[i] = new cambra[_pos.second];
    		}
	}
}


//Coste : O(f*c) siendo f el numero de filas introducidas por is y c = f.size()-1  (f.size() == numero de columnas que tiene la fila introducida)
laberint::laberint(std::istream & is) throw(error){	
	
	string num;
	getline(is, num);
	
	std::istringstream s(num);
	s>>_pos.first;		//el primer numero introducido es el nº de filas
	s>>_pos.second;		//el segundo numero introducido es el nº de columnas
	
	_lab = new cambra*[_pos.first];	//crea columnas
	for (nat i = 0; i < _pos.first; i++){
		_lab[i] = new cambra[_pos.second];	//crea filas
	}
	
	//hay que hacer un getline de los asteriscos para a posterior mirar si hay que abrir o cerrar alguna puerta
	string pared;
	getline(is, pared);	//ignoramos la primera fila porque como es una cambra perfecta, no hay ninguna pared exterior abierta
	
	int l = 1;	//line contador
	
	while(getline(is, pared)){
		
		if(l%2 == 0 ){	//si estamos en la fila par, hay que tratar el norte de una cambra y el sur de la de abajo
			for(nat i = 1; i < pared.size(); i+=2){	//vamos de 2 en dos para ver las paredes nortes
				if(pared[i] == ' '){
					nat fila= l/2, columna=i/2;	//se calcula en que fila y columna esta la cambra que se trata
					if(l%2==0) --fila;
					
					paret p("S");
					_lab[fila][columna].obre_porta(p);	//modificar la sur
					
					paret p2("N");
					_lab[fila+1][columna].obre_porta(p2);	//modificar la norte
				}
			}
		}
		else{		//si estamos en la fila impar, hay que tratar el este de una cambra y el oeste de la de derecha
			for(nat i = 2; i < pared.size(); i+=2){	//vamos de 2 en dos para ver las paredes nortes
				if(pared[i] == ' '){
					nat fila= l/2, columna=i/2;	//se calcula en que fila y columna esta la cambra que se trata
					if(l%2==0) --fila;
					if(i%2==0) --columna;
					
					paret p("E");
					_lab[fila][columna].obre_porta(p);	//modificar la este
					
					paret p2("O");
					_lab[fila][columna+1].obre_porta(p2);	//modificar la norte
				}
			}
		}
		
		++l;
	}

}


//Coste : O(_pos.first*_pos.second), hay que acceder a todas las cambras del laberinto para realizar la copia
laberint::laberint(const laberint & l) throw(error){		// Constructora per còpia
	
	_pos.first = l._pos.first;
	_pos.second = l._pos.second;
	_lab = new cambra*[_pos.first];	//crea filas
	for (nat i = 0; i < _pos.first; i++){
		_lab[i] = new cambra[_pos.second];	//crea columnas por fila
		for(nat j = 0; j < _pos.second; j++){
			_lab[i][j] = l._lab[i][j];	//hacer la copia
		}
	}
	
}

//Coste : O(_pos.first*_pos.second) 
laberint & laberint::operator=(const laberint & l) throw(error){	// Constructora per assignació
	
	_pos.first = l._pos.first;
	_pos.second = l._pos.second;
	_lab = new cambra*[_pos.first];	//crea filas
	for (nat i = 0; i < _pos.first; i++){
		_lab[i] = new cambra[_pos.second];	//crea columnas por fila
		for(nat j = 0; j < _pos.second; j++){
			_lab[i][j] = l._lab[i][j];	//hacer la copia
		}
	}
	
	return *this;
}

//Coste : O(0)
laberint::~laberint() throw(){}	// Constructora per destructora.


//Coste : O(1) constante
nat laberint::num_files() const throw(){								
	return _pos.first;
}

//Coste : O(1) constante
nat laberint::num_columnes() const throw(){								
	return _pos.second;
}


//Coste : O(1) constante
cambra laberint::operator()(const posicio & pos) const throw(error){
	//posicio es un pair
	nat f = pos.first, c = pos.second;
	cambra n;
	
	if(f > _pos.first or c > _pos.second or f == 0 or c == 0) throw error(PosicioInexistent);
	else{
		n = _lab[f-1][c-1];
	}
	
	return n;
}

//Coste : O(1) constante
void laberint::obre_porta(paret p, const posicio & pos) throw(error){

	nat f = pos.first, c = pos.second;
	int pared = int(p);
	if((f > _pos.first or c > _pos.second or f == 0 or c == 0)) throw error(PosicioInexistent);
	else if((f == 1 and int(p) == 0) or (c == _pos.second and int(p) == 1) or (f == _pos.first and int(p) == 2) or (c == 1 and int(p) == 3))throw error(PortaExterior);
	else{
		--f;
		--c;
		
		if(pared == 0){	//Norte
			paret p("N");
			paret p2("S");

			_lab[f][c].obre_porta(p);	//modificar la norte
			_lab[f-1][c].obre_porta(p2);	//modificar la sur de la de arruba
		}
		else if(pared == 1){	//Este
			paret p("E");
			paret p2("O");
			
			_lab[f][c].obre_porta(p);	//modificar la este
			_lab[f][c+1].obre_porta(p2);	//modificar la oeste de la de derecha
		}
		else if(pared == 2){	//Sur
			paret p("S");
			paret p2("N");
			
			_lab[f][c].obre_porta(p);	//modificar la sur
			_lab[f+1][c].obre_porta(p2);	//modificar la norte de la de abajo
		}
		else if(pared == 3){	//Oeste
			paret p("O");
			paret p2("E");
			
			_lab[f][c].obre_porta(p);	//modificar la oeste
			_lab[f][c-1].obre_porta(p2);	//modificar la este de la de izquierda
		}
		else{	//intentar modificar paret NO_DIR
			_lab[f][c].obre_porta(p);	
		}
	
	}
}

//Coste : O(1) constante
void laberint::tanca_porta(paret p, const posicio & pos) throw(error){
	
	nat f = pos.first, c = pos.second;
	
	if(f > _pos.first or c > _pos.second or f == 0 or c == 0)throw error(PosicioInexistent);
	else if((f != 1 or int(p) != 0) and (c != _pos.second or int(p) != 1) and (f != _pos.first or int(p) != 2) and (c != 1 or int(p) != 3)){
		--f;
		--c;
		int pared = int(p);
		if(pared == 0){	//Norte
			paret p("N");
			paret p2("S");
			
			_lab[f][c].tanca_porta(p);	//modificar la norte
			_lab[f-1][c].tanca_porta(p2);	//modificar la sur de la de arruba
		}
		else if(pared == 1){	//Este
			paret p("E");
			paret p2("O");
			
			_lab[f][c].tanca_porta(p);	//modificar la este
			_lab[f][c+1].tanca_porta(p2);	//modificar la oeste de la de derecha
		}
		else if(pared == 2){	//Sur
			paret p("S");
			paret p2("N");
			
			_lab[f][c].tanca_porta(p);	//modificar la sur
			_lab[f+1][c].tanca_porta(p2);	//modificar la norte de la de abajo
		}
		else if(pared == 3){	//Oeste
			paret p("O");
			paret p2("E");
			
			_lab[f][c].tanca_porta(p);	//modificar la oeste
			_lab[f][c-1].tanca_porta(p2);	//modificar la este de la de izquierda
		}
		else{	//intentar modificar paret NO_DIR ==> Salta error : ParetInexistent = 20
			_lab[f][c].tanca_porta(p);	
		}
	}
}

//Coste : O(_pos.first*_pos.second) , hay que acceder a todas las cambras del laberinto para imprimirlo
void laberint::print(std::ostream & os) const throw(){	

	//Imrpimir * del laberinto 
	char caracter = '*', espacio = ' ';
	os << _pos.first << " "<< _pos.second<<"\n";

	nat l = 0;
	while(l < _pos.first){	//recorrer de fila en fila
		
		for (nat c = 0; c < _pos.second; ++c){	//IMPRIMIR TODA LA PARED DEL NORTE
			os << caracter;
			paret p("N");
			if(_lab[l][c].porta_oberta(p)) os << espacio;
			else os << caracter;
		}
		os << caracter << "\n";	//imprimir ultimo asterisco para saltar linea
		
		//IMRPIMIR PARED DEL OESTE
		paret p("O");	
		if(_lab[l][0].porta_oberta(p)) os << espacio;
		else os << caracter;
		
		
		
		for (nat c = 0; c < _pos.second; ++c){ //IMRPIMIR TODA LA PARED DEL ESTE
			os << espacio;
			paret p("E");
			if(_lab[l][c].porta_oberta(p)) os << espacio;
			else os << caracter;
		}
		os << "\n";	// saltar linea al acabar el ultimo este
		
		
		if(l+1 == _pos.first){	//si estamos acabando el laberinto, imprimir la ultima fila

			for (nat c = 0; c < _pos.second; ++c){	//IMRPIMIR ULTIMA PARED DEL SUR
				os << caracter;
				paret p("S");
				if(_lab[l][c].porta_oberta(p)) os << espacio;
				else os << caracter;
			}
			os << caracter << "\n";	//imprimir ultimo asterisco para saltar linea y acabar
		}
		
		++l;
	}
	
}

