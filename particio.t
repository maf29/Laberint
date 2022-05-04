#include "particio.hpp"

//Coste : O(1) constante
template <typename T>
particio<T>::particio(nat n) throw(error){
	_max = n;
	_elem = 0;
	_size = 0;
	_arrel = NULL;
	
}

//Coste : O(1) constante
template <typename T>
particio<T>::particio(const particio & p) throw(error){
	_arrel = copia_tot(p._arrel);
	_elem = p._elem;
	_size = p._size;
	_max = p._max;
}

//Coste : O(1) constante
template <typename T>
particio<T> & particio<T>::operator=(const particio & p) throw(error){
	_arrel = copia_tot(p._arrel);
	_elem = p._elem;
	_size = p._size;
	_max = p._max;
	return *this;
}

//Coste : O(0)
template <typename T>
particio<T>::particio::~particio() throw(){
}

//Coste : O(1) constante
template <typename T>
void particio<T>::afegir(const T &x) throw(error){
	if(_elem == _max and consulta(_arrel, x) == NULL) throw error(ParticioPlena);
	else _arrel = afegir_aux(_arrel, x);
}

//Coste : O(log(n)) siendo n el numero de elementos de la partición 
template <typename T>
void particio<T>::unir(const T &x, const T &y) throw(error){	
	
	if(x != y){
		node *aux_x = consulta(_arrel,x);
		node *aux_y = consulta(_arrel,y);
	
		node *lider_grupo_x = find(aux_x);
		node *lider_grupo_y = find(aux_y);
		
		if(lider_grupo_x != lider_grupo_y){
		
			if(aux_x->_alt > aux_y->_alt){	
				lider_grupo_y->_lider = lider_grupo_x;
			}
			else{
				lider_grupo_x->_lider = lider_grupo_y;	
			}
			
			lider_grupo_y->_alt = max(high(lider_grupo_x->_esq), high(lider_grupo_y->_dret) + 1) ;
			
			_size--;	//decrementar el contador de grupos, porque se han unido dos subgrupos
		}
	}
	else{	//si son iguales, mirar si forma parte del arbol
		node *aux_x = consulta(_arrel,x);
		if(aux_x == NULL) throw error(ElemInexistent);
	}
}

//Coste : O(log(n)) siendo n el numero de elementos de la partición 
template <typename T>
bool particio<T>::mateix_grup(const T &x, const T &y) const throw(error){
	
	node* aux_x=consulta(_arrel, x);
	node* aux_y=consulta(_arrel, y);
	
	if(x == y and aux_x != NULL){
		return true;
	}
	else{

    		node *lider_grupo_x = find(aux_x);
		node *lider_grupo_y = find(aux_y);
		
		if(lider_grupo_x->_val == lider_grupo_y->_val) return true;		//si tienen el mismo representante del grupo, significa que estan en el mismo grupo
    		else return false;
	}
	
}

//Coste : O(1) constante
template <typename T>
nat particio<T>::size() const throw(){
	return _size;
}

//Coste : O(1) constante
template <typename T>
nat particio<T>::num_elements() const throw(){
	return _elem;
}

//Coste : O(1) constante
template <typename T>
nat particio<T>::num_maxim() const throw(){
	return _max;
}

//Coste : O(1) constante
template <typename T>
typename particio<T>::node *particio<T>::copia_tot(node *src){
//Pre: src es el nodo a partir del cual se hará la busqueda en el arbol
//Post: Retorna n que tendrá el contenido de src.
	node* n;
	if(src == NULL) n = NULL;
	else{
		n = new node;

		n->_val = src->_val;
		
		n->_esq = copia_tot(src->_esq);
		n->_dret = copia_tot(src->_dret);
		
		n->_lider = src->_lider;
		n->_alt = src->_alt;
	}
	return n;
}

//Coste : O(log(n)) siendo n numero de elementos del arbol
template <typename T>
typename particio<T>::node *particio<T>::afegir_aux(node *act, const T &x){
//Pre: n es el nodo a partir del cual se hará la busqueda en el arbol
//Post: x ya esta insertada en el AVL y se retorna la raiz del arbol ya equilibrado.

	node *n = NULL;

	if (act != NULL){
		if (act->_val < x){ /*x major, dreta*/
    			act->_dret = afegir_aux(act->_dret, x);
		}
		else if (x < act->_val){ /*x menor, esq*/
	    		act->_esq = afegir_aux(act->_esq, x);
		}
		else return act;
		act->_alt = max(high(act->_esq), high(act->_dret)) + 1;

		int equi = equilibra(act);

		/*esq-esq*/
		if (equi > 1 and x < act->_esq->_val){
	    		return right_rotation(act);
		}

		/*dret-dret*/
		if (equi < -1 and act->_dret->_val < x ){
	    		return left_rotation(act);
		}

		/* Casos de 2 passos
		   esq-dret*/
		if (equi > 1 and act->_esq->_val < x){
			act->_esq = left_rotation(act->_esq);
			return right_rotation(act);
		}

		/*dret-esq*/
		if (equi < -1 and x < act->_dret->_val){
			act->_dret = right_rotation(act->_dret);
			return left_rotation(act);
		}
	
		return act;
	}
	else{
		n = new node;
		n->_val = x;
		n->_esq = n->_dret = NULL;
		n->_alt = 1;
		n->_lider = n;
		_elem++;
		_size++;
	}
	return n;
}

//Coste : O(1) constante
template <typename T>
typename particio<T>::node *particio<T>::left_rotation(node *n){
//Pre: n es el nodo a partir del cual se hará la busqueda en el arbol
//Post: Retorna la raiz del arbol girado a la izquierda 
	node *a = n->_dret;
	node *c = a->_esq;

	a->_esq = n;
	n->_dret = c;

	n->_alt = max(high(n->_esq), high(n->_dret)) + 1;
	a->_alt = max(high(a->_esq), high(a->_dret)) + 1;

	return a;
}

//Coste : O(1) constante
template <typename T>
typename particio<T>::node *particio<T>::right_rotation(node *n){
//Pre: n es el nodo a partir del cual se hará la busqueda en el arbol
//Post: Retorna la raiz del arbol girado a la derecha 
	node *a = n->_esq;
	node *c = a->_dret;

	a->_dret = n;
	n->_esq = c;

	n->_alt = max(high(n->_esq), high(n->_dret)) + 1;
	a->_alt = max(high(a->_esq), high(a->_dret)) + 1;

	return a;
}

//Coste : O(1) constante
template <typename T>
nat particio<T>::max(nat a, nat b){
//Pre: a y b son valores naturales
//Post: Retorna el natural más grande.
	if (a < b) return b;
	else return a;
}

//Coste : O(1) constante
template <typename T>
int particio<T>::equilibra(node *n){
//Pre: n es el nodo a partir del cual se hará la busqueda en el arbol
//Post: Retorna la difrerencia de altura entre el subarbre izquierdo y el derecho de n.
	if (n != NULL) return high(n->_esq) - high(n->_dret);
	else return 0;
}

//Coste : O(1) constante
template <typename T>
nat particio<T>::high(node *n) const{
//Pre: n es el nodo a partir del cual se hará la busqueda en el arbol
//Post: Retorna la altura del nodo n.
	if (n != NULL) return n->_alt;
	else return 0;
}

//Coste : O(log(n)) siendo n numero de elementos del arbol
template <typename T>
typename particio<T>::node* particio<T>::consulta(node *n, const T &k) const{	
//Pre: n es el nodo a partir del cual se hará la busqueda en el arbol y k es una clau
//Post: Retorna un apuntador al nodo del AVL que contiene la clave k. En caso contrario, retorna NULL.
	if(n == NULL){
		return NULL;
	}
	else{
		if (n->_val == k) return n;
		else {
			if (k < n->_val and n->_esq != NULL){
				return consulta(n->_esq, k);
			}
			else if ( n->_val < k and n->_dret != NULL){
				return consulta(n->_dret, k);
			}
			else return NULL;
		}
	}
}

//Coste : O(log(n)) siendo n el numero de elementos de la partición 
template <typename T>
typename particio<T>::node *particio<T>::find(node *n)const{
//Pre: n es el nodo a partir del cual se hará la busqueda en el arbol
//Post: Retorna el representante del grupo al cual pertenece n

	//si n == n lider --> significa que hemos encontrado el representante del grupo
	
	if(n == NULL){	//si n no forman parte del arbol, retorna error
		throw error(ElemInexistent);
	}
	
	while(n != n->_lider){	//mientras el nodo no apunte a si mismo 
		n = n->_lider;	//buscar el representante del grupo
	}
	return n;
}

