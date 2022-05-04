#include <vector>
#include <iostream>
#include <queue>
#include <list>
using namespace std;
typedef unsigned int nat;
typedef std::pair<nat,nat> posicio;
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

	//vector<nat> quants_succ_succ() const;
	// Pre: Cert
	// Post: Retorna quants successors diferents tenen els successors de cada vèrtex
	// del graf
	list<nat> cami_mes_curt(nat ini, nat fi) const;

	private:
		nat n; // Nombre de vèrtexs
		nat m; // Nombre d’arestes
		vector<vector<nat> > a; // Vectors amb els successors de cada vèrtex

		// Aquí va l’especificació dels mètodes privats addicionals
		//static nat quants_succ_succ(vector<nat> &aux);
		static list<nat> cami_mes_curt(const vector<vector<nat>> &aux, nat ini, nat fi);
		
};
list<nat> graf::cami_mes_curt(nat ini, nat fi) const{
	//cout << n << endl;
	return cami_mes_curt(a, ini, fi);
}
list<nat> graf::cami_mes_curt(const vector<vector<nat> > &aux, nat ini, nat fi){
// Pre: a conté les arestes del graf en llistes d'adjacència,
// els vèrtexs que hi apareixen < a.size().
// ini<a.size(), fi<a.size()
// Post: Retorna el camí més curt per anar d’ini fins a fi.
// Si no existeixi camí retorna -1.
	vector<bool> vis(aux.size(), false);
	list<nat> l;
	nat d = -1;
	queue<nat> cv;	//guarda els següents vèrtexs a visitar
	queue<nat> cd; //la distància per anar de ini a cadascun dels vèrtexs de cv

	cv.push(ini);	//poner push del inici porque es el primer vertex que se visita
	l.push_back(ini);
	cd.push(0);
	vis[ini] = true;
	if (cv == fi) l.push_back(ini);
	else{
		while (not cv.empty() and d == -1) {	//mientras no este vacia y d sea que no se ha encontrado camino
			nat v = cv.front(); cv.pop();
			nat dv = cd.front(); cd.pop();
			
			if (v == fi) {
				l.push_back(dv);
				d = dv;
			
			}
			else {
				// Recorregut pels successors de v
				for(int i = 0; i < aux[v].size(); i++) {
					nat suc = aux[v][i];
					
					if (not vis[suc]) {	//mientra sno haya sido visitado anteriormente
						
						cv.push(suc);	//guardar el sucesor en la cola de sucesores
						cd.push(dv+1);	//guardar la distancia en la cola de distancias
						
						vis[suc] = true;	//marcar el vertex como visitado
					}
				}
			}
		}
		l.push_back(fi);
	}
	return l;
}

#include <iostream>
using namespace std;

graf::graf() : n(0), m(0) {}

graf::~graf() {}

void graf::llegeix() {
  // Llegim el nombre de vèrtexs i arestes
	cin >> n >> m;

	// Creem les llistes d'adjacència (vectors amb els successors dels n vèrtexs)
	a = vector<vector<nat> >(n);

	// Llegim les m arestes
	nat u, v;
	for(nat i = 0; i < m; i++) {
		cin >> u >> v; // Aresta que connecta vèrtex u amb vèrtex v
		a[u].push_back(v);
	}
}

int main() {
	graf g;
	g.llegeix();
	nat ini, fi;
	cin>>ini>>fi;
	list<nat>::iterator it;
	list<nat> mylist = g.cami_mes_curt(ini, fi);
	/*for(nat i=0; i<resultat.size(); i++) {
		cout << resultat[i] << " ";
	}*/
	cout << "camino : ";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
    		cout << ' ' << *it;
    	cout << endl;
	list<posicio> cd; 
	
	posicio p;
	nat x = 0;
	p.first = p.second = 0;
	cd.push_back(p); cd.push_back(p);
	cout << cd.size()<<endl;;
	list<posicio>::iterator iter;
	//cout <<"    "<< cd[0].first << endl;
	for (iter = cd.begin(); iter != cd.end(); ++iter)
    		cout <<"  "<< (*iter).first <<"  " << (*iter).second;

	return 0;
}

