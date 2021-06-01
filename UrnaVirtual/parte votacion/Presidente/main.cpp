  #include <iostream>
#include <stdlib.h>  
#include <time.h>   
using namespace std;


void consultarCenso(){
		int censoTotal;
		for(int i = 0; i < ciudades.getTam(); i++){
	        cout<<"Ciudad: "<<ciudades.devolverDato(i).nombre<<endl;
	        cout<<"Censo: "<<ciudades.devolverDato(i).censo<<endl;
	        censoTotal=censoTotal+ciudades.devolverDato(i).censo;
	        cout<<endl;
	    }
	    cout<<"Censo total: "<<censoTotal<<endl;
	    system("pause");
}

cout<<"el censo es: "<<censototal<<endl;


int main(int argc, char** argv) {
	int censo;
	cout<<"ingrese el numero de censo: ";
	cin >> censo; //cantidad de personas 
	cout<<endl<<"El numero de censo total es: "
	int candidatos; //numero de partidos, contando el voto en blanco
	cin >> candidatos; 
	
	int *voto= new int[candidatos+3];
	
	
	
	/*for(int i=0;i<censo;i++){ //Random del numero total de votantes, de 1 a 100 respectivamente.
		voto[i]=rand()%100 + 1; 
		int j=0;
		bool m=false;
		do{
			if(voto[i]>(j*100/candidatos) && voto[i]<=(j+1)*100/candidatos){ //Compara que el numero de votantes no sea superior.
				voto[i]=j+1;
				m=true;
			}
			j++;
		}
		while(j<candidatos && !m); //avanza el numero de partidos.
		//cout<<"Persona "<< (i+1) <<" voto por :" <<voto[i]<<endl; 
	}*/
	int porcentaje;
	int total=0;
	candidatos=candidatos +3;
	srand (time(NULL)); 
	 
	for(int j=0;j<candidatos;j++){ //realiza el conteo de cada votante candidatos agrupa por partido.
		
		do {
			porcentaje=rand()%((101-total));
			
			
		}while(porcentaje>(100/candidatos)+5);
		
		total=total+porcentaje;
		
		if(j + 1 == candidatos){
			voto[j]=100-total+porcentaje;
		}
		else{
			voto[j]=porcentaje;   
		}
		
		
		//cout<<(j+1)<<": "<<<<endl;
		cout<<"Porcentaje de voto por el partido "<< (j+1)<<": "<<voto[j]<<"%"<<endl; //realiza el conteo por medio de porcentaje.po
	}
}
