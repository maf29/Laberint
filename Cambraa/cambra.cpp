#include "cambra.hpp"

/*
		|norte|este|sur|oeste| 
*/

// Construeix una cambra amb les portes als llocs indicats.
cambra::cambra(bool n, bool s, bool e, bool o) throw(error){
	
	_cont_portes = 0;	//inicializar el contador a 0
	
	_camara[0] = n;		// primera posicion --> norte
	if(n) ++_cont_portes;
	
	_camara[1] = e;		// segunda posicion --> este
	if(e) ++_cont_portes;
	
	_camara[2] = s;		// tercera posicion --> sur
	if(s) ++_cont_portes;
	
	_camara[3] = o;		// cuarta posicion --> oeste
	if(o) ++_cont_portes;
	
}

// Constructora per còpia, assignació i destructora.
//Cost lineal
cambra::cambra(const cambra & c) throw(error){
	
	_cont_portes = 0;	//inicializar el contador a 0
	for(int i=0; i < 4; i++){
		_camara[i] = c._camara[i];
		if(_camara[i])	++_cont_portes;		//si cambra[i] es true, es que hay una puerta abierta, incrementamos contador
	}
}

//Cost lineal
cambra & cambra::operator=(const cambra & c) throw(error){
	
	_cont_portes = 0;	//inicializar el contador a 0
	
	for(int i=0; i < 4; i++){
		_camara[i] = c._camara[i];
		if(_camara[i])	++_cont_portes;		//si cambra[i] es true, es que hay una puerta abierta, incrementamos contador
	}
	return *this;
}

//Cost 0
cambra::~cambra() throw(){}

// Retorna si l'habitació té una porta oberta a la paret indicada.
//Cost constante
bool cambra::porta_oberta(paret p) const throw(){
	std::cout << int(p)<<"\n";
	std::cout << _camara[0] <<" "<< _camara[1] <<" "<< _camara[2] <<" "<< _camara[3]<<"\n";
	if(int(p) >=4) return false;
	else return _camara[ int(p) ];
}

// Obre una nova porta a la paret indicada. Si la porta ja està oberta no
// fa res. Es produeix un error si la paret és NO_DIR.
//Cost constante
void cambra::obre_porta(paret p) throw(error){

	if(int(p) < 0 and int(p) >= 4){	//no existe pared, lanzar error
		throw error(ParetInexistent);
	}
	else if(not _camara[p]){	//puerta cerrada ==> abrirla
		_camara[int(p)] = true;
		
		++_cont_portes;		//abrimos una puerta ==> incrementamos contador
	}
}

// Tanca la porta a la paret indicada. Si la porta ja estava tancada no
// fa res. Es produeix un error si la paret és NO_DIR.
//Cost constante
void cambra::tanca_porta(paret p) throw(error){
	
	if(int(p) < 0 and int(p) >= 4){	//no existe pared, lanzar error
		throw error(ParetInexistent);
	}
	else if(_camara[p]){	//puerta abierta ==> cerrarla
		_camara[int(p)] = false;
		
		--_cont_portes;		//cerramos una puerta ==> decrementamos contador
	}
}

// Igualtat i desigualtat entre cambres. Dues cambres es consideren iguals
// si tenen les mateixes portes obertes a les mateixes parets.
//Cost lineal en el caso peor 
bool cambra::operator==(const cambra & c) const throw(){
	
	bool igual = false;
	
	if(_cont_portes == c._cont_portes){	//mismo numero de puertas abiertas
		for(int i = 0; i < 4; ++i){
			if(_camara[i] != c._camara[i]) return false;	//mismas puertas en las mismas paredes
		}
		
		igual = true;
	}
	
	return igual;
	
}

//Cost lineal en el caso peor
bool cambra::operator!=(const cambra & c) const throw(){
	
	if(_cont_portes == c._cont_portes){	//si tiene el mismo numero de puertas, mirar si no hay las mismas puertas en las mismas paredes
		for(int i = 0; i < 4; ++i){
			if(_camara[i] == c._camara[i]) return false;	//mismas puertas en las mismas paredes
		}
	}
	
	return true;
}

// Operador "menor que" entre cambres. Una cambra és més petita que una
// altra si té més portes tancades que l'altra. Tenint en compte que una
// porta tancada és més petita que una porta oberta, en cas que tinguin el
// mateix número de portes tancades, per decidir qui és més petit es miraran
// les portes en aquest ordre NORD, EST, SUD i OEST. Per exemple:
//   cambra c1, c2(true,true), c3(true, false, true);
//   cout << (c1 < c2); // escriu 'true'
//   cout << (c2 < c3); // escriu 'true'
//Cost lineal en el caso peor
bool cambra::operator<(const cambra & c) const throw(){
	
	bool menor = true;
	
	if(_cont_portes > c._cont_portes) menor = false;
	else if(_cont_portes == c._cont_portes){		//_cont_portes == c._cont_portes
		for(int i = 0; i < 4; ++i){
			if(_camara[i] == false and c._camara[i] == true) return false;	// _cambra > c
		}
	}
	
	return menor;
}

// Gestió d'errors.
static const int  ParetInexistent = 20;
