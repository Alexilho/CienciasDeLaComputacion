#include <stddef.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
//#include "Lista.h"
#include "estructuras.h"


class convertidor {
	//estructura de datos donde x es el dato a guardar y sig es la posicion a la que apunta despues
	Lista<Candidatos> candidatos;
	Lista<Partidos> partidos;
	Lista<Ciudad> ciudad;
	Ciudad ciudadActual;
	Partidos partidoActual;
	Candidatos candidatoActual;
	
	
	private:
	
	public:
		//constructor
		convertidor(){
			
		}
		
		void leerTxt(){
					
			Lista <Candidatos> candidatos2;
			Lista <Partidos> partidos2;
		
			candidatos = candidatos2;
			partidos = partidos2;
			
			int j, t;
			ifstream candida("archivos\\candidatos.txt");
			ifstream parti("archivos\\partidos.txt");
			ifstream ciu("archivos\\ciudad.txt");
	
			if(ciu.is_open()){
				//crea la lista de partidos apartir del txt
				do{
					ciudadActual.posicion=ciudad.getTam()+1;
        			getline(ciu,ciudadActual.nombre);
        			getline(ciu,ciudadActual.departamento);
        			ciu >> ciudadActual.censo;
        			ciu.ignore(1);
        			ciudad.anadir_final(ciudadActual);
        			//termina el bucle si el partido actual es igual al ultimo partido agregado
        		}while(ciudad.getTam()==1||ciudadActual.nombre.compare(ciudad.devolverDato(ciudad.getTam()-2).nombre));
        		//elimina el repetido
		        ciudad.eliminar_final();
			}
	
			if(parti.is_open()){
				//crea la lista de partidos apartir del txt
				do{
					partidoActual.posicion=partidos.getTam()+1;
        			getline(parti,partidoActual.nombre);
        			getline(parti,partidoActual.representante);
        			partidos.anadir_final(partidoActual);
        			//termina el bucle si el partido actual es igual al ultimo partido agregado
        		}while(partidos.getTam()==1||partidoActual.nombre.compare(partidos.devolverDato(partidos.getTam()-2).nombre));
        		//elimina el repetido
        		partidos.eliminar_final();
			}
	
			if(candida.is_open()){
				//crea la lista de candidatos apartir del txt
				do{
					j=0;
					candidatoActual.posicion=candidatos.getTam()+1;
        			getline(candida,candidatoActual.nombre);
        			getline(candida,candidatoActual.apellido);
        			//se cambia el getline para los tipos int y char
        			candida >> candidatoActual.identificacion;
        			candida >> candidatoActual.sexo;
        			//necesario para que funcione el getline despues de un cin
        			candida.ignore(1);
        			getline(candida,candidatoActual.estadoCivil);
        			getline(candida,candidatoActual.fnacimiento);
        			//ya tendriamos la fecha en int 
        			string fecha (candidatoActual.fnacimiento,6,9);
        			//ya se tiene la edad
        			int edad = 2018-(atoi(fecha.c_str()));
        			//cout<<edad;
        			//system("pause");
        			//ya lo hace...solo que debe guardarse en algun lado
        			getline(candida,candidatoActual.ciudadNac);
        			getline(candida,candidatoActual.ciudadRes);
        			getline(candida,candidatoActual.partido);
        			getline(candida,candidatoActual.candidatura);
        			getline(candida,candidatoActual.vicepresidente);
        			candidatos.anadir_final(candidatoActual);
        			//bucle que busca la posicion de la lista de partidos donde esta el partido del candidato
        			while(partidos.devolverDato(j).nombre!=candidatoActual.partido){
						j++;
					}
        			//se obtienen cada uno de los datos del partido
        			partidoActual.nombre=partidos.devolverDato(j).nombre;
        			partidoActual.representante=partidos.devolverDato(j).representante;
        			partidoActual.candi=partidos.devolverDato(j).candi;
        			partidoActual.posicion=partidos.devolverDato(j).posicion;
        			//se a;ade el candidato a la lista de candidatos del partido
        			partidoActual.candi.anadir_final(candidatoActual);
        			//se modifica el partido en la lista de partidos con el nuevo candidato
        			partidos.modificar(partidoActual,j);
        			//termina el bucle si el candidato actual es igual al ultimo candidato agregado
        		}while(candidatos.getTam()==1||candidatoActual.nombre.compare(candidatos.devolverDato(candidatos.getTam()-2).nombre));
        		//elimina el repetido
        		partidoActual.candi.eliminar_final();
        		partidos.modificar(partidoActual,j);
        		candidatos.eliminar_final();
			}
			//agrega los partidos a las ciudades
			//recorre la lista de partidos
    		for(int i = 0; i < partidos.getTam(); i++){
    			//recorre la lista de candidatos de ese partido
        		for(int k=0;k<partidos.devolverDato(i).candi.getTam();k++){
        			t=0;
        			//busca la posicion de la ciudad que coincida con la ciudad del candidato
					while(partidos.devolverDato(i).candi.devolverDato(k).ciudadRes!=ciudad.devolverDato(t).nombre){
						t++;
					}
					ciudadActual.nombre=ciudad.devolverDato(t).nombre;
					ciudadActual.censo=ciudad.devolverDato(t).censo;
					ciudadActual.departamento=ciudad.devolverDato(t).departamento;
					ciudadActual.posicion=ciudad.devolverDato(t).posicion;
					ciudadActual.parti=ciudad.devolverDato(t).parti;
					//si el arrglo de partidos de la ciudad es igual a 0 o 
					//si el ultimo partido es diferente del que se va a ingresar, se inserta el partido
					if(ciudadActual.parti.getTam()==0||ciudadActual.parti.devolverDato(ciudadActual.parti.getTam()).nombre!=partidos.devolverDato(i).nombre){
						ciudadActual.parti.anadir_final(partidos.devolverDato(i));
						ciudad.modificar(ciudadActual,t);
					}
				}
 			}
			parti.close();
			candida.close();
			ciu.close();
		}
		
		
		
		void anadir_Candidato(Candidatos candidato){
			
			candidatos.anadir_final(candidato);
			guardar_Candidato(candidato);
		}
		
		void guardar_Candidato(Candidatos candidato){
			string listaNueva;			
			listaNueva="archivos\\candidatos.txt";

			ofstream fs(listaNueva.c_str(), std::ios::app);
			fs << endl ;
			fs << candidato.nombre << endl;
			fs << candidato.apellido << endl;
			fs << candidato.identificacion << endl;
			fs << candidato.sexo << endl;
			fs << candidato.estadoCivil << endl;
			fs << candidato.fnacimiento << endl;
			fs << candidato.ciudadNac << endl;
			fs << candidato.ciudadRes << endl;
			fs << candidato.partido << endl;
			fs << candidato.candidatura << endl;
			fs << candidato.vicepresidente;

			fs.close();
			
			
			
		//	leerTxt();
		}
		void anadir_Partido(Partidos partido){
			
		}
		void anadir_Ciudad(Ciudad ciudad){
			
		}
		
		void modificar_Candidato(Candidatos canViejo, Candidatos canModificado){
			//usar busqueda binaria
			
			
			
			//recordar eliminar del partido que estaba el candidato y la ciudad
			//despues de modificar usar quick sort para ordenar las listas de ciudades y partidos
		}
		void modificar_Partido(Partidos parViejo, Partidos parModificado){
			
		}
		void modificar_Ciudad(Ciudad ciudad, Ciudad ciuModificada){
			
		}	
		
		Lista<Candidatos>* devolver_lista_candidatos(){
			return &candidatos;
		}
		Lista<Partidos>* devolver_lista_partidos(){
			return &partidos;
		}
		Lista<Ciudad>* devolver_lista_ciudades(){
			return &ciudad;
		}
		Candidatos busquedaBinaria(Lista<Candidatos> candidatos, int tamano, int clave){
			int Iarriba = tamano-1;
    		int Iabajo = 0;
    		int Icentro;
    		while (Iabajo <= Iarriba){
    			Icentro = (Iarriba + Iabajo)/2;
        		if (candidatos.devolverDato(Icentro).posicion == clave){
		    		return candidatos.devolverDato(Icentro);
	    		}else{
	        		if (clave < candidatos.devolverDato(Icentro).posicion){
	        			Iarriba=Icentro-1;
	        		}else{
	        			Iabajo=Icentro+1;
		   			}
				}
    		}
		return candidatos.devolverDato(0);
		}
		void quicksort(Lista<Candidatos> a, int izq, int der){
			int i, j;
			Candidatos aux; 
			int v;
  			if (der> izq){
				v=a.devolverDato(der).posicion; 
			i=izq-1; 
				j=der;
    			for(;;){
					while (a.devolverDato(++i).posicion<v);
            		while (a.devolverDato(--j).posicion>v);
        			if(i>=j) break;
        				aux=a.devolverDato(i);
        				a.modificar(a.devolverDato(j),i);
        				a.modificar(aux,j);
            			//intercambio(a,i,j);
            		}
				aux=a.devolverDato(i);
				a.modificar(a.devolverDato(der),i);
				a.modificar(aux,der);
    			quicksort(a, izq, i-1);
    			quicksort(a, i+1,der);
    		}
		}
};
