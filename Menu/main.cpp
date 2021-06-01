#include <cstdlib>
#include <iostream>

using namespace std;
void ImprimirLista();
void OrdenarCarrera();
void OrdenarHobbie();

int main(int argc, char** argv) {
			
	
        cout<<"Menu principal: "<<endl;
        cout<<"1: Insertar"<<endl<<"2: Eliminar"<<endl<<"3: ImprimirLista"<<endl<<"4: Salir"<<endl; 
        int a; cin>>a;
        switch(a){
            case 1: //Insertar(); 
			break;	
            case 2: //Eliminar(); 
			break;
            case 3: ImprimirLista();
			break;
            case 4: system("pause");
        }		
	}
	
	 void ImprimirLista(){
			cout<<"----------------------------------------------"<<endl;
			cout<<"Menu de seleccion: "<<endl;
			cout<<"1: Ordenar por nombre"<<endl<<"2: Ordenar por Carrera"<<endl<<"3: Ordenar por Hobbie"<<endl<<"4: Ordenar por Edad"<<endl;
			int b; cin>>b;
			switch(b){
				case 1: //rdenarNombre();
				break;
				case 2: OrdenarCarrera(); 
				break;
				case 3: OrdenarHobbie(); 
				break;
				case 4: //OrdenarEdad(); 
				break;
			}
		}
		
		void OrdenarCarrera(){
			cout<<"----------------------------------------------"<<endl;
			cout<<"1: Ordenar por Carrera Electronica"<<endl<<"2: Ordenar por Carrera Sistemas"<<endl<<"3: Ordenar por Carrera Industrial"<<endl<<"4: Ordenar por Carrera Catastral"<<endl;
			int c; cin>>c;
			switch(c){
				case 1: //OrdenarElectronica(); 
				break;
				case 2: //OrdenarSistemas(); 
				break;
				case 3: //OrdenarIndustrial(); 
				break;
				case 4: //OrdenarCatastral(); 
				break;
			}
		}
		
		void OrdenarHobbie(){
						cout<<"----------------------------------"<<endl;
			cout<<"1: Ordenar por Danza"<<endl<<"2: Ordenar por Natación"<<endl<<"3: Ordenar por Basket"<<endl<<"4: Ordenar por Beisbol"<<endl;
			int c; cin>>c;
			switch(c){
				case 1: //OrdenarDanza(); 
				break;
				case 2: //OrdenarNatacion(); 
				break;
				case 3: //OrdenarBasket(); 
				break;
				case 4: //OrdenarBeisbol();
				break;
			}
		}
		                 	                                
