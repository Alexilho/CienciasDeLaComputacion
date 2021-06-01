
#include "estructura.h"
#include <iostream>
using namespace std;


template<class T>

class Pila{

public:
	tipoElemento<T> *pila;
	int p;
	Pila(int max=100){
		pila = new tipoElemento[max];
		p=0;
	}
	~Pila(){
		delete pila;
	}
				
	inline void meter(tipoElemento [v]){
		pila[p++]=v;
	}
	inline void sacar(){
		return pila[p--];
	}
	inline int vacia(){
		return !p;
	}
};
