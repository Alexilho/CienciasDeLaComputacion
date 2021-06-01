#include <cstdlib>
#include <iostream>

using namespace std;
void BuscarReceta();


int main(int argc, char** argv) {
			
	
        cout<<"Menu principal: "<<endl;
        cout<<"1: Insertar receta"<<endl<<"2: Eliminar receta"<<endl<<"3: Modificar receta"<<endl<<"4: Buscar receta"<<endl<<"5: Salir"<<endl; 
        int a; cin>>a;
        switch(a){
            case 1: //Insertar(); 
			break;	
            case 2: //Eliminar(); 
			break;
			case 3: //Modificar();
            case 4: BuscarReceta();
			break;
            case 5: system("pause");
        }		
	}
	
	 void BuscarReceta(){
			cout<<"----------------------------------------------"<<endl;
			cout<<"Menu de seleccion: "<<endl;
			cout<<"1: Buscar por nombre"<<endl<<"2: Buscar por ingrediente"<<endl<<"3: Salir"<<endl;
			int b; cin>>b;
			switch(b){
				case 1: //BuscarNombre();
				break;
				case 2: //BuscarIngrediente();
				break;
				case 3: system("pause");
			}	
		}


		                 	              
