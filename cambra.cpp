#include "cambra.hpp"

//Coste : O(1) constante
cambra::cambra(bool n, bool s, bool e, bool o) throw(error){

	_cont_portes = 0;		//inicializar el contador a 0
	
	_camara[0] = n;		// primera posicion --> norte
	if(n) ++_cont_portes;
	
	_camara[1] = e;		// segunda posicion --> este
	if(e) ++_cont_portes;
	
	_camara[2] = s;		// tercera posicion --> sur
	if(s) ++_cont_portes;
	
	_camara[3] = o;		// cuarta posicion --> oeste
	if(o) ++_cont_portes;
	
}

//Coste : O(1) constante
cambra::cambra(const cambra & c) throw(error){
	
	_cont_portes = 0;	//inicializar el contador a 0
	_camara[0] = c._camara[0];		// igualar primera posicion --> norte
	if(_camara[0]) ++_cont_portes;
	
	_camara[1] = c._camara[1];		// igualar segunda posicion --> este
	if(_camara[1]) ++_cont_portes;
	
	_camara[2] = c._camara[2];		// igualar tercera posicion --> sur
	if(_camara[2]) ++_cont_portes;
	
	_camara[3] = c._camara[3];		// igualar cuarta posicion --> oeste
	if(_camara[3]) ++_cont_portes;
}

//Coste : O(1) constante
cambra & cambra::operator=(const cambra & c) throw(error){
	
	_cont_portes = 0;	//inicializar el contador a 0
	_camara[0] = c._camara[0];		// igualar primera posicion --> norte
	if(_camara[0]) ++_cont_portes;
	
	_camara[1] = c._camara[1];		// igualar segunda posicion --> este
	if(_camara[1]) ++_cont_portes;
	
	_camara[2] = c._camara[2];		// igualar tercera posicion --> sur
	if(_camara[2]) ++_cont_portes;
	
	_camara[3] = c._camara[3];		// igualar cuarta posicion --> oeste
	if(_camara[3]) ++_cont_portes;
	
	return *this;
}

//Coste : O(0)
cambra::~cambra() throw(){}

//Coste : O(1) constante
bool cambra::porta_oberta(paret p) const throw(){

	if(p == 0) return _camara[0];
	if(p == 1) return _camara[1];
	if(p == 2) return _camara[2];
	if(p == 3) return _camara[3];
	return false;
}

//Coste : O(1) constante
void cambra::obre_porta(paret p) throw(error){

	
	if(p == paret::NO_DIR){		//no existe pared, lanzar error
		throw error(ParetInexistent);
	}
	else if(not _camara[p]){		//puerta cerrada ==> abrirla
		_camara[p] = true;
		
		++_cont_portes;		//abrimos una puerta ==> incrementamos contador
	}
	
}

//Coste : O(1) constante
void cambra::tanca_porta(paret p) throw(error){
	
	if(p == paret::NO_DIR){		//no existe pared, lanzar error
		throw error(ParetInexistent);
	}
	else if( _camara[p]){			//puerta abierta ==> cerrarla
		_camara[p] = false;
		
		--_cont_portes;		//cerramos una puerta ==> decrementamos contador
	}
	
}

//Coste : O(1) constante
bool cambra::operator==(const cambra & c) const throw(){
	
	return (_camara[0] == c._camara[0] and _camara[1] == c._camara[1] and _camara[2] == c._camara[2] and _camara[3] == c._camara[3]);
	
}

//Coste : O(1) constante
bool cambra::operator!=(const cambra & c) const throw(){
	
	return not (*this == c);
}

//Coste : O(1) constante
bool cambra::operator<(const cambra & c) const throw(){
	
	
	if(_cont_portes > c._cont_portes) return false;
	else if(_cont_portes == c._cont_portes){		//si tienen el mismo numero de puertas
		
		if(not _camara[0] and c._camara[0]) return false;
		if(not _camara[1] and c._camara[1]) return false;
		if(not _camara[2] and c._camara[2]) return false;
		if(not _camara[3] and c._camara[3]) return false;
		
	}
	
	return true;
}

