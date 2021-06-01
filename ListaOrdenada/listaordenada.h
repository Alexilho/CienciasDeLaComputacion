#ifndef LISTA_H     
#define LISTA_H  
#include <cstdlib>
#include <iostream>

using namespace std;


class lista_ordenada{
	
	Nodo *cab;
	int tam;
	
	
	public: lista_ordenada() {
		
		cab = NULL;
		tam = 0;
	}	
	
	void mostrar (int pos);
	void eliminar(int pos);
	void eliminar_final();
	bool lista_vacia();
	
	void insertar_final(Nodo infoNueva);
	void insertar_pos(Nodo infoNueva, int pos);
	void insertar_inicio(Nodo infoNueva);
	//modificar (nodo->info)
		
	}
};
	Struct Nodo {
		int clave;
		string info;
		Nodo *sig;
	}
	
	void mostrar (int pos){
		
	}	
	
	void insertar_pos(Nodo infoNueva, int pos){
		if(pos > tam) 
			insertar_final(infoNueva);
  		else{
	  		if (pos==1) insertar_inicio(infoNueva);
       	else{
		   	Nodo <T> *nuevo, *aux;
			nuevo = new Nodo <T>;
			nuevo->info = infoNueva;
			aux = cab;
			int p = 1;
			while(p<pos-1 && aux != NULL){
				aux = aux->sig;
			 	p++;
			}
			nuevo->sig=aux->sig;
			aux->sig=nuevo;
		}
    }
}

	void insertar_final(Nodo infoNueva){
		Nodo <T> *nuevo;
	  	nuevo = new Nodo <T>;
	  	nuevo->info = infoNueva;
	  	nuevo->sig = NULL;
	 	if(tam == 0) 
		 	cab = nuevo;
	  	else{
		  	Nodo <T> *aux;
	     	aux = cab;
	     	while(aux->sig != NULL) 	
			 	aux = aux->sig;
	     	
			aux->sig = nuevo;
    	}
  		tam++;
	}


	void insertar_inicio(Nodo infoNueva){
		Nodo <T> *nuevo;
	  	nuevo = new Nodo <T>;
	  	nuevo->info = infoNueva;
	  	nuevo->sig = cab;
	  	cab = nuevo;
	  	tam++;
	}	
	
	bool eliminar(int pos){
		if(tam >= pos){
			Nodo <T> *temp;
	       	temp = cab;
	    	if(pos == 1){
		   		cab = temp->sig;
          		delete temp;
        	}
	       	else{
			    for(int i=1;i<pos;i++)
			    	temp = temp->sig;          
	          	Nodo <T> *aux;
	          	aux = temp->sig;
	          	temp->sig = aux->sig;
				delete aux;
	        }
	    tam--;
        return true;          
    	}
 		else 
			return false;
	}
	
	
	void eliminar_final(){
			Nodo<T> *temp, *aux;
			temp = cab;
			if(temp != NULL){
				aux=temp -> sig;
				if(aux->sig == NULL){
					temp -> sig = NULL;
					delete aux;
					tam--;
				}
				else{
				while ((aux->sig) != NULL) {
				aux = aux -> sig;
				temp = temp -> sig;				
			}
			temp -> sig = NULL;
			delete aux;
			tam--;
			}
		}	   	 
	}


	bool lista_vacia(){
    	if(tam == 0) 
			return true;
    	else 
			return false;
	}

	

#endif

