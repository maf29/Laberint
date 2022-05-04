/*#include <iostream>

using namespace std;

int main(){

	/*int **lab; // pointer to array of arrays (i.e 2d array)
	int fila;
	cin >> fila;
	//lab = new int*[V+1];            //adjacency matrix.
	lab = new int*[fila];		//se crean las filas
	
	for (int i = 0; i < fila; i++){
		cout<<lab[i]<<endl;
	}
	
	int col;
	cin >> col;
	// initially set all values to zero '0'
	for (int i = 0; i < fila; i++){
		adj[i] = new int[col];
		cout << "adj["<<i<<"] = "<< adj[i]<<endl;
	}
	
	for (int i = 0; i < fila; i++){
		lab[i] = new int[col];	//enint fila= l/2, columna=c/2;
					if(l%2==0) --fila;
					if(c%2==0) --columna; cada fila de crea las columnas necesarias
	}
	for (int i = 0; i < fila; i++){
		for(int j = 0; j < col; j++ ){
			cout << lab[i][j]<<"  ";
		}
		cout << endl;
	}*/
	
	/*int l, c;
	cin>>l>>c;
	int fila= l/2, columna=c/2;
	if(l%2==0) --fila;
	if(c%2==0) --columna;
	
	cout << "fila: " << fila << "  columna : "<< columna << endl;
	//cout << b << endl;
	*/
	
#include "cambra.hpp"
#include "laberint.hpp"
#include <iostream>
using namespace std;

void print(cambra c){
	cout<<"*";
	if(c.porta_oberta(0)){
		cout<<" ";
	}
	else{
		cout<<"*";
	}
	cout<<"*"<<endl;
	//primera linea
	if(c.porta_oberta(3)){
		cout<<" ";
	}
	else{
		cout<<"*";
	}
	cout<<" ";
	if(c.porta_oberta(1)){
		cout<<" ";
	}
	else{
		cout<<"*";
	}
	cout<<endl<<"*";
	
	if(c.porta_oberta(2)){
		cout<<" ";
	}
	else{
		cout<<"*";
	}
		cout<<"*"<<endl;
    
}

int main(){
    
    cambra C;
    laberint l;
    pair<int,int> pos;
    pos.first=1;
    pos.second=2;
    //cout<<l(pos).porta_oberta(1)<<endl;
    print(l(pos));
    pos.first=1;
    pos.second=3;
    l.obre_porta(1,pos);
   
    pos.first=1;
    pos.second=2;
    l.obre_porta(3,pos);
   
    pos.first=1;
    pos.second=4;
    l.obre_porta(2,pos);
   
    l.print(cout);
    /*print(l(pos));
    pos.second+=1;
    print(l(pos));*/
    //cambra C1;
    /*
    print(C);
    cout<<C.porta_oberta(1)<<endl;
    C.obre_porta(1);        //est i sud
    C.obre_porta(2);        
    C1.obre_porta(0);
    C1.obre_porta(1);
    //C1.obre_porta(3);
    //cout<<C.porta_oberta(1)<<endl;
    cout<<(C<C1)<<endl;
    print(C);*/

}


