#include <iostream>
#include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 class graf {
   // Graf dirigit i no etiquetat.
   // Les arestes es guarden en llistes d’adjacència (vector amb els successors).
   public:
     // Constructora per defecte. Crea un graf buit.
     graf();
 
     // Destructora
     ~graf();
 
     // Llegeix les dades del graf del canal d’entrada
     void llegeix();
 
     vector<nat> quants_succ_succ() const;
     // Pre: Cert
     // Post: Retorna quants successors diferents tenen els successors de cada vèrtex
     // del graf
 
   private:
     nat n; // Nombre de vèrtexs
     nat m; // Nombre d’arestes
     vector<vector<nat> > a; // Vectors amb els successors de cada vèrtex
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode públic quants_succ_succ i privats addicionals
vector<nat> graf::quants_succ_succ() const{
// Pre: Cert
// Post: Retorna quants successors diferents tenen els successors de cada vèrtex
// del graf

	vector<nat> v;
	vector<nat> succ_succ;
	if(a.size() !=0){
		
		for(int i = 0; i < a.size(); ++i){	//recorrer el vector del sucesores de cada vertice
			if(a[i].size() == 0)v.push_back(0);
			else{
				int cont = 0;
				for(int j = 0; j < a[i].size(); ++j){
					
					
					for(int z = 0; z < a[a[i][j]].size(); z++){
						succ_succ.push_back(a[a[i][j]][z]);
					}
					
				}
				for(int x = 0; x < succ_succ.size(); x++){
					for(int z = x+1; z < succ_succ.size(); z++){
						if(succ_succ[x] == succ_succ[z]) --cont;
					}
					++cont;
				}
				v.push_back(cont);
				succ_succ.clear();
			}
		}
		
	}
	else v.push_back(0);
	
	return v;
}

