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
  vector<nat> resultat = g.quants_succ_succ();
  for(nat i=0; i<resultat.size(); i++) {
    cout << resultat[i] << " ";
  }
  cout << endl;
  return 0;
}
