#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>  
#include <time.h>   

#include "consultas.h"

//sobrecarga de metodos
void Consulta();
void Simulacion();
void Resultados();
void ProcesoElectoral();
void ConsultarPartido();
void GestionDatos();
void ConsultarCiudad();
void SimulacionAlcaldia(); 
void SimulacionPresidencial();
void ResultadosAlc();
void ResultadosPres();
void mostrarPresidencia();
void consultarCenso();
void estadisticas();
void estadisticas1();
void estadisticas2();
void menu();
using namespace std;

	Lista<Candidatos> candidatos;
	Lista<Partidos> partidos;
	Lista<Ciudad> ciudades;
	Lista<Partidos> consultasPar;
	Lista<Candidatos> consultasCan;
	Lista<Ciudad> consultasCiu;
	Lista<int> ganadoresalcaldia;
	Lista<int> ganadorpresidencia;
	Lista<int> segundopresidencia;
	Lista<int> resultadospresidencia;
	
	consultas consulta;

	int a,j,numeroCandidato,opcionResultados;
	string nombreCiudad,nombreCity, censoTotal;
	
	
	//crear mas metodos para evitar switch case dentro de switch case e intentar crear las variables al comienzo del codigo
	int main(int argc, char** argv) {
		//cargamos los datos
		//Cargar();	
		do {
			menu();
			cin>>a;
			system("CLS");
			switch(a){
				case 1: {
					Consulta(); //LLEVARA AL MENU CONSULTA
				break;
				}
				case 2: {
					Simulacion(); //LLEVARA AL MENU DE LA SIMULACION
					break;
				}
				case 3: {
					Resultados();
					break;
				}
				case 4: {
					estadisticas();
					system("pause");
					system("cls");
					break;
				}
			}	
		}while(0<a&&a<5);
	}
		
		
	void Consulta(){//mas metodos, variables al comienzo
		do {
			cout<<endl<<"Menu de Consulta"<<endl;
			cout<<endl<<"Por favor seleccione una opcion"<<endl;
			cout<<"-------------------------------"<<endl;
			cout<<endl<<"1- Consultar por partido /////"<<endl<<"2- Mostrar lista candidatos presidencia //////"<<endl;
			cout<<"3- Consultar segun ciudad"<<endl<<"4- Tarjeton Presidencial"<<endl;
			cout<<"5- Consultar censo electoral //////"<<endl<<"6- Consultar edad candidatos ////"<<endl<<"";
						
			cout<<"-------------------------------"<<endl<<"seleccione: ";
			cin>>a;
			system("CLS");
			switch(a){
				
				case 1: {
					ConsultarPartido();
					break;
				}
				case 2:{
					mostrarPresidencia();	
					//MOSTRAR LISTA DE CANDIDATOS A PRESIDENCIA Y VICEPRESIDENCIA NOMBRECANDIDATO, EDAD, CIUDAD NAC, ESTADO CIVIL
					break;
				}
				case 3:{
					ConsultarCiudad();	
					break;
				}
				case 4:{				
					//TARJETON PRESIDENCIAL , CON NOMBRE DE CANDIDATOS Y PARTIDO TANTO PRESIDENCIA COMO VICEPRE
					break;
				}
				case 5:{
					consultarCenso();	
					//MOSTRAR POR CADA CIUDAD EL CENSO ELECTORAL
					break;
				}
				case 6:{
					candidatos = consulta.candidatos;
					for (int i=0; i<candidatos.getTam();i++){
						//ya tendriamos la fecha en int 
				        string fecha (candidatos.devolverDato(i).fnacimiento,6,9);
				        //ya se tiene la edad
				        int edad = 2018-(atoi(fecha.c_str()));
				        
				        cout<<i+1<<" Nombre: "<<candidatos.devolverDato(i).nombre;
				        cout<<" --- Edad: "<<edad<<endl;	
					}     
					system("pause");   	
					system("CLS");
					break;
				}
				
			}
		}while(0<a&&a<7);
	}
		
	void Simulacion(){ 
		cout<<endl<<"Menu de simulacion"<<endl;
		cout<<endl<<"Por favor seleccione una opcion"<<endl;
		cout<<"-------------------------------"<<endl;
		cout<<endl<<"1- Gestionar datos "<<endl<<"2- Proceso Electoral //////"<<endl;
		cout<<"-------------------------------"<<endl<<"seleccione: ";
		cin>>a;
		system("CLS");
		switch(a){
			case 1:{
				GestionDatos(); //AQUI LLEVARA AL MENU DONDE CREAREMOS, ELIMINAREMOS O MODIFICAREMOS CANDIDATOS
				break;
			}
			case 2:{
				ProcesoElectoral(); //AQUI SE REALIZARA EL PROCESO ELECTORAL
				break;
			}
		}		
	}
		
	void Resultados(){
		cout<<endl<<"Por favor seleccione una opcion"<<endl;
		cout<<"-------------------------------"<<endl;
		cout<<endl<<"1- Resultados Alcaldia"<<endl<<"2- Resultados presidencia"<<endl;
		cin>>opcionResultados;
		system("CLS");
			switch (opcionResultados) {
			case 1:{
				ResultadosAlc();
				break;
				}
			case 2: {
				ResultadosPres();
				//DESPLEGAMOS RESULTADOS A LA PRESIDENCIA
				break;
				}
		}
	}

		
	void GestionDatos(){
		
		Candidatos candidatoAct;
		cout<<endl<<"Por favor seleccione una opcion"<<endl;
		cout<<"-------------------------------"<<endl;
		cout<<endl<<"1- Ingresar candidato ////mirar"<<endl<<"2- Modificar candidato"<<endl<<"3- Eliminar candidato"<<endl;
		cin>>opcionResultados;
		system("CLS");
		switch (opcionResultados) {
			case 1:{
				/*
				cout<<"Ingrese nombre: "<<endl;
				cin.ignore(1);
				getline(cin, candidatoAct.nombre);
	
				cout<<"Ingrese apellido: "<<endl;
				getline(cin, candidatoAct.apellido);
				
				cout<<"Ingrese identificacion: "<<endl;
				cin >> candidatoAct.identificacion;
				cin.ignore(1);
				
				cout<<"Ingrese sexo: "<<endl;
				cin>> candidatoAct.sexo;
				cin.ignore(1);
				
				cout<<"Ingrese estado civil: "<<endl;
				getline(cin, candidatoAct.estadoCivil);
				
				cout<<"Ingrese fecha de nacimiento: "<<endl;
				getline(cin, candidatoAct.fnacimiento);
				
				cout<<"Ingrese ciudad de nacimiento: "<<endl;
				getline(cin, candidatoAct.ciudadNac);
				
				cout<<"Ingrese ciudad de residencia: "<<endl;
				getline(cin, candidatoAct.ciudadRes);
				
				cout<<"Ingrese partido: "<<endl;
				getline(cin, candidatoAct.partido);
				
				cout<<"Ingrese candidatura: "<<endl;
				getline(cin, candidatoAct.candidatura);
				
				if (candidatoAct.candidatura == "Presidencia"){
					cout<<"Ingrese vicepresidente: "<<endl;
					getline(cin, candidatoAct.vicepresidente);
				}
				else {
					candidatoAct.vicepresidente="";
				}
				
				convertidorTxt.anadir_Candidato(candidatoAct);
				
				Cargar();
				*/					
				break;
				}
				
			case 2: {
				//DESPLEGAMOS RESULTADOS A LA PRESIDENCIA
				break;
				}
		}
		//ACTUALIZAR EL TXT DESPUES DE INSERTAR ELIMINAR O MODIFICAR 
	}
		
	void ProcesoElectoral(){
			
			cout<<endl<<"Menu de simulacion"<<endl;
			cout<<endl<<"Por favor seleccione una opcion"<<endl;
			cout<<"-------------------------------"<<endl;
			cout<<endl<<"1- Votar para alcaldia "<<endl<<"2- Votar para presidencia"<<endl;
			cout<<"-------------------------------"<<endl<<"seleccione: ";
			cin>>a;
			system("CLS");
			switch(a){
				case 1:{
					SimulacionAlcaldia();
					break;
				}
				case 2:{
					SimulacionPresidencial();
					break;
				}
			}
		}
		
		
	void SimulacionAlcaldia(){
		
		ciudades = *consulta.ciu_ProcesoElectoral(); 
		int candidatos = 5; //numero de partidos, contando el voto en blanco
		srand (time(NULL));
		long *voto= new long[candidatos+3];   	 
		for(int i=0;i < ciudades.getTam();i++){
			cout<<i+1<<" Ciudad: "<<ciudades.devolverDato(i).nombre<<endl;
			cout<<"Censo: "<<ciudades.devolverDato(i).censo<<endl;
			long *censoCandidato= new long[candidatos+3];
			int porcentaje; 
			int total=0;
			int mayor1=0;
			candidatos=candidatos +3;
			cout<<endl;
			
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
			
				if(j<5){
					cout<<"Porcentaje de voto por el partido "<< (j+1)<<": "<<voto[j]<<"%"<<endl;
					censoCandidato[j] = (ciudades.devolverDato(i).censo/100)*voto[j]; 
					cout<<censoCandidato[j]<<" personas votaron por este candidato"<<endl;
					cout<<endl;
				} 
					if(j==5){
					cout<<"Porcentaje de voto nulo: "<<voto[j]<<"%"<<endl;
					censoCandidato[j] = (ciudades.devolverDato(i).censo/100)*voto[j]; 
					cout<<censoCandidato[j]<<" anuladas"<<endl;
					cout<<endl;
				}
				if(j==6){
					cout<<"Porcentaje de voto en blanco: "<<voto[j]<<"%"<<endl;
					censoCandidato[j] = (ciudades.devolverDato(i).censo/100)*voto[j]; 
					cout<<censoCandidato[j]<<" votaron"<<endl;
					cout<<endl;
					
				}
				if(j==7){
					cout<<"abstinencia de voto: "<<voto[j]<<"%"<<endl;
					censoCandidato[j] = (ciudades.devolverDato(i).censo/100)*voto[j]; 
					cout<<censoCandidato[j]<<" no votaron"<<endl;
					cout<<endl;
				}	
				if (voto[j]>mayor1 && j<5){
    			mayor1=voto[j];	
			 }   

    			
			}
				ganadoresalcaldia.anadir_final(mayor1);
				cout<<"El ganador es: "<<"con un porcentaje de: "<<mayor1<<"%"<<endl;
				cout<<"------------------------------------------------"<<endl;
				cout<<endl;
				candidatos=5;

	}
		system("pause");
		system("CLS");
}
	

	
	void SimulacionPresidencial(){
		int censoTotal, x,s;
		int mayor=0;
		int segundomayor=0;
		int candidato = 10;
		int contador=0;
		int *voto= new int[candidato+3];
		int *resultado= voto;
		candidatos = *consulta.candidatos_a_Presidencia();
		ciudades = *consulta.ciu_ProcesoElectoral(); 
		for(int i = 0; i < ciudades.getTam(); i++){
	        ciudades.devolverDato(i).nombre;
	        ciudades.devolverDato(i).censo;
	        censoTotal=censoTotal+ciudades.devolverDato(i).censo;
	    } 
			cout<<"El censo total es: "<<censoTotal<<endl;

			long *censoCandidato= new long[candidato+3];
			int porcentaje; 
			int total=0;
			int segundo=0;
			candidato=candidato+3;
			srand (time(NULL));   
			cout<<endl;
			for(int j=0;j<candidato;j++){ //realiza el conteo de cada votante candidatos agrupa por partido.	
				do {
					porcentaje=rand()%((101-total));
				}while(porcentaje>(100/candidato)+5);
				total=total+porcentaje;
				if(j + 1 == candidato){
					voto[j]=100-total+porcentaje;
				}
				else{
					voto[j]=porcentaje;   
				}	
				if(j<10){
					cout<<"Porcentaje de voto por el candidato "<<candidatos.devolverDato(j).nombre<<" "<<candidatos.devolverDato(j).apellido<<" con "<<voto[j]<<"%"<<endl;
					censoCandidato[j] = (censoTotal/100)*voto[j]; 
					cout<<censoCandidato[j]<<" personas votaron por este candidato"<<endl;


				} 
				if(j==10){
					cout<<"Porcentaje de voto nulo: "<<voto[j]<<"%"<<endl;
					censoCandidato[j] = (censoTotal/100)*voto[j]; 
					cout<<censoCandidato[j]<<" anuladas"<<endl;


				}
				if(j==11){
					cout<<"Porcentaje de voto en blanco: "<<voto[j]<<"%"<<endl;
					censoCandidato[j] = (censoTotal/100)*voto[j]; 
					cout<<censoCandidato[j]<<" votaron"<<endl;


				}
				if(j==12){
					cout<<"abstinencia de voto: "<<voto[j]<<"%"<<endl;
					censoCandidato[j] = (censoTotal/100)*voto[j]; 
					cout<<censoCandidato[j]<<" no votaron "<<endl;

				}
				resultado[j]=voto[j];
				resultadospresidencia.anadir_final(voto[j]);
				if (voto[j]>mayor && j<10){
    			mayor=voto[j];
    			}
			cout<<endl;
			}

			for(int i=0;i<candidato;i++){
				if(resultado[i]==mayor){
					cout<<"El ganador es: "<<candidatos.devolverDato(i).nombre<<" "<<candidatos.devolverDato(i).apellido<<" con un porcentaje de: "<<mayor<<"%"<<endl;
					ganadorpresidencia.anadir_final(mayor);
					contador++;
				}
			}
			if(contador>1){
				segundomayor=mayor;
				segundopresidencia.anadir_inicio(segundomayor);
			}
			else{
				x=mayor;
				int *segundo = voto;
				int n=0;
				bool m=false;
				do{
					if(segundo[n]==x){
						segundo[n]=0;
						m=true;
					}
					n++;
				}
			while(n<candidato && !m);
				for(int j=0;j<candidato-3;j++){
					if(segundo[j]>=segundomayor){
						segundomayor=segundo[j];
						s=j;	
					}
				}
			cout<<"El segundo es: "<<candidatos.devolverDato(s).nombre<<" "<<candidatos.devolverDato(s).apellido;
			cout<<" con un porcentaje de: "<<segundomayor<<"%"<<endl;
			segundopresidencia.anadir_inicio(segundomayor);
		}	
		
		cout<<"------------------------------------------------"<<endl;
		system("pause"); 
		system("CLS");
	}	
	
	void ResultadosAlc(){
		for(int i=0; i<ciudades.getTam();i++){
			cout<<"Ciudad: "<<ciudades.devolverDato(i).nombre<<endl;
			cout<<"Censo: "<<ciudades.devolverDato(i).censo<<endl;
			cout<<"Resultado Ganador: "<<ganadoresalcaldia.devolverDato(i)<<"%"<<endl;
			cout<<"------------------------------------------------"<<endl<<endl;
		}
		for(int i=0;i<ciudades.getTam();i++){
			ganadoresalcaldia.eliminar_posicion(i);
			ganadoresalcaldia.modificar(ganadoresalcaldia.devolverDato(i),i);
		}
		system("pause");
		system("CLS");
	}
	void ResultadosPres(){	
		int censoTotal;	
		for(int i=0;i<ciudades.getTam();i++){
		ciudades.devolverDato(i).nombre;
		ciudades.devolverDato(i).censo;
	    censoTotal=censoTotal+ciudades.devolverDato(i).censo;
	}
		int i=1;
		cout<<"Censo total: "<<censoTotal<<endl;
		cout<<endl<<"Resultado Ganador: "<<ganadorpresidencia.devolverDato(i)<<"%"<<endl;
		if(ganadorpresidencia.devolverDato(i)<50){
			cout<<endl<<"Segundo Ganador: "<<segundopresidencia.devolverDato(i)<<"%"<<endl;
			cout<<endl<<"HAY SEGUNDA VUELTA ENTRE ESTOS CANDIDATOS"<<endl;
		}
		cout<<"------------------------------------------------"<<endl<<endl;
		ganadorpresidencia.eliminar_final();
		ganadorpresidencia.modificar(ganadorpresidencia.devolverDato(i),i);
		segundopresidencia.eliminar_final();	
		segundopresidencia.modificar(segundopresidencia.devolverDato(i),i);
		system("pause");
		system("CLS");
	}	
	void ConsultarPartido(){
		string partidoConsultar, deptoConsultar,fnac,fecha;
		int edad;
		cout<<endl<<"Por favor seleccione una opcion"<<endl;
		cout<<"-------------------------------"<<endl;
		cout<<endl<<"1- Consultar por partido y departamento ////"<<endl<<"2- Consultar solo por partido ///"<<endl<<"3- Consultar partidos legalmente reconocidos /////"<<endl;
		cout<<"-------------------------------"<<endl<<"seleccione: ";
		cin>>a;
		switch(a){
			case 1:{
				cout<<"Por favor digite el nombre del partido"<<endl;
				cin.ignore(1);
				getline(cin, partidoConsultar);
				cout<<"Por favor digite el nombre del departamento"<<endl;
				getline(cin,deptoConsultar);
				
				candidatos = *consulta.candi_Alcal_por_Parti_Depto(partidoConsultar, deptoConsultar);				
				for(int i = 0; i < candidatos.getTam(); i++){
					cout<<candidatos.devolverDato(i).posicion<<endl<<" Nombre: "<<candidatos.devolverDato(i).nombre<<" "<<candidatos.devolverDato(i).apellido<<endl;
					string fecha ((candidatos.devolverDato(i).fnacimiento),6,9);
					//ya se tiene la edad
					int edad = 2018-(atoi(fecha.c_str()));
					cout<<" Edad: "<<edad<<endl;
					cout<<" Sexo: "<<candidatos.devolverDato(i).sexo<<endl;
					
				}		
				//MOSTRAR LA LISTA DE LOS CANDIDATOS A CADA CIUDAD CON CIUDAD,NOMBRE CANDIDATO, SEXO, EDAD
				system("pause");
				system("CLS");				
					
				break;
			
			}
			case 2:{
				cout<<"Por favor digite el nombre del partido"<<endl;
				cin.ignore(1);
				getline(cin,partidoConsultar);
				system("CLS");
				cout<<partidoConsultar<<endl;
				
				candidatos = *consulta.cons_Alcaldia_Partido(partidoConsultar);				
				for(int i = 0; i < candidatos.getTam(); i++){
					cout<<i+1<<endl<<" Nombre: "<<candidatos.devolverDato(i).nombre<<" "<<candidatos.devolverDato(i).apellido<<endl;
					cout<<" Ciudad: "<<candidatos.devolverDato(i).ciudadRes<<endl;
					cout<<" Sexo: "<<candidatos.devolverDato(i).sexo<<endl;
					string fecha ((candidatos.devolverDato(i).fnacimiento),6,9);
					//ya se tiene la edad
					int edad = 2018-(atoi(fecha.c_str()));
					cout<<" Edad: "<<edad<<endl;
				}		
				//MOSTRAR LA LISTA DE LOS CANDIDATOS A CADA CIUDAD CON CIUDAD,NOMBRE CANDIDATO, SEXO, EDAD
				system("pause");
				system("CLS");
				break;
			}
			case 3: {
				partidos = *consulta.parti_Reconocidos();
				for (int i=0; i<partidos.getTam(); i++){
					cout<<i+1<<endl<<" Nombre: "<<partidos.devolverDato(i).nombre<<endl;
					cout<<" Representate: "<<partidos.devolverDato(i).representante<<endl;
				}
				break;
			}
		}
	}
	
	void mostrarPresidencia(){
		
		candidatos = *consulta.candidatos_a_Presidencia();
		for(int k=0;k<candidatos.getTam();k++){
			//(Nombre del candidato, edad, ciudad, de nacimiento, estado civil).
			cout<<k+1<<endl<<" Nombre: "<<candidatos.devolverDato(k).nombre<<" "<<candidatos.devolverDato(k).apellido<<endl;
			string fecha ((candidatos.devolverDato(k).fnacimiento),6,9);
			//ya se tiene la edad
			int edad = 2018-(atoi(fecha.c_str()));
			cout<<" Edad: "<<edad<<endl;		
			cout<<" Ciudad de Nacimiento: "<<candidatos.devolverDato(k).ciudadNac<<endl;
			cout<<" Estado Civil: "<<candidatos.devolverDato(k).estadoCivil<<endl;
			cout<<" Vicepresidente: "<<candidatos.devolverDato(k).vicepresidente<<endl;
			cout<<endl;
		}
		system("pause");
		system("CLS");
	}	
		
	void ConsultarCiudad(){
		string ciudadConsultar;
					
		cout<<endl<<"Por favor seleccione una opcion"<<endl;
		cout<<"-------------------------------"<<endl;
					
		cout<<endl<<"1- Mostrar por partido"<<endl<<"2- Mostrar tarjeton a alcaldia"<<endl;
		cout<<"3- Ciudades para las cuales se realizara el proceso electoral /////"<<endl;
		cout<<"4- Candidatos a la Alcaldia de una ciudad /////"<<endl;
		cout<<"-------------------------------"<<endl<<"seleccione: ";
		cin>>a;
		system("CLS");
		switch(a){
			case 1:{	
				cout<<endl<<"Por favor digite ciudad"<<endl;
				cin>> ciudadConsultar;
				cout<<"-------------------------------"<<endl;				
				//NOMBRE DEL CANDIDATO A LA ALCADIA DE DICHA CIUDAD
				break;
			}
			case 2: {
				cout<<endl<<"Por favor digite ciudad"<<endl;
				cin>> ciudadConsultar;
				cout<<"-------------------------------"<<endl;		
				//MOSTRAR EL TARJETON DE CANDIDATOS A LA ALCALDIA
				break;
			}
			case 3: {
				ciudades = *consulta.ciu_ProcesoElectoral();
				for (int i=0; i<ciudades.getTam(); i++){
					cout<<i+1<<"Ciudad: "<<ciudades.devolverDato(i).nombre<<endl;
				}
				break;
			}
			case 4: {
				cout<<endl<<"Por favor digite ciudad"<<endl;
				cin.ignore(1);
				getline(cin, ciudadConsultar);
				
				candidatos = *consulta.candidatos_Alcaldia_una_Ciudad(ciudadConsultar);
				for (int i=0;i<candidatos.getTam(); i++){
					cout<<i+1<<" Nombre: "<<candidatos.devolverDato(i).nombre<<" "<<candidatos.devolverDato(i).apellido<<endl;
				}
				break;
			}
		}
	}
		
	void consultarCenso(){
		int censoTotal;
		ciudades = *consulta.ciu_ProcesoElectoral(); 
		for(int i = 0; i < ciudades.getTam(); i++){
	        cout<<i+1<<" Ciudad: "<<ciudades.devolverDato(i).nombre<<endl;
	        cout<<"Censo: "<<ciudades.devolverDato(i).censo<<endl;
	        censoTotal=censoTotal+ciudades.devolverDato(i).censo;
	        cout<<endl;
	    }
	    cout<<"Censo total: "<<censoTotal<<endl;
	    system("pause");
	    system("CLS");
	}
	
	void estadisticas(){
		cout<<endl<<"Por favor seleccione una opcion"<<endl;
		cout<<"-------------------------------"<<endl;
					
		cout<<endl<<"1- Estadisticas alcaldia "<<endl<<"2- Estadisticas presidencia"<<endl;
		cout<<"-------------------------------"<<endl<<"seleccione: ";
		cin>>a;
		system("CLS");
		switch(a){
			case 1:{	
				estadisticas1();	
				break; 
			}
			case 2: {		
				estadisticas2();
				break;
			}
		}
	}
	
	
	void estadisticas1() {
		
		cout<<endl<<"Por favor seleccione una opcion"<<endl;
		cout<<"-------------------------------"<<endl;
					
		cout<<endl<<"1- Reporte general por Dpto "<<endl<<"2- Reporte detallado por Dpto"<<endl;
		cout<<"3- Totales nacionales"<<endl;
		cout<<"-------------------------------"<<endl<<"seleccione: ";
		cin>>a;
		system("CLS");
		switch(a){
			case 1:{		
				//NOMBRE DEL CANDIDATO A LA ALCADIA DE DICHA CIUDAD
				break;
			}
			case 2: {		
				int contador=0;
				
				for(int k =0;k<partidos.getTam();k++){
					for(int i =0;i<partidos.devolverDato(k).candi.getTam();i++){
						if (partidos.devolverDato(k).candi.devolverDato(i).candidatura=="Presidencia") {
							contador++;
							cout<<"presidente"<<i<<partidos.devolverDato(k).candi.devolverDato(i).nombre<<partidos.devolverDato(k).candi.devolverDato(i).apellido<<endl;
							cout<<"tama;o "<<partidos.devolverDato(k).candi.getTam()<<endl;
						}
					}
					cout<<partidos.devolverDato(k).nombre<<": "<<contador<<endl;
					contador=0;	
				}
				break;
			}
			case 3: {
				
				break;
			}
		}
	}
	
	void estadisticas2() {
		cout<<endl<<"Por favor seleccione una opcion"<<endl;
		cout<<"-------------------------------"<<endl;
					
		cout<<endl<<"1- Reporte general por Dpto "<<endl<<"2- Reporte general para totalidad del pais"<<endl;
		cout<<"3- Reporte detallado por Dpto"<<endl<<"4- Reporte detallado para la totalidad del pais"<<endl;
		cout<<"5- Segunda vuelta?"<<endl;
		cout<<"-------------------------------"<<endl<<"seleccione: ";
		cin>>a;
		system("CLS");
		switch(a){
			case 1:{		
				//NOMBRE DEL CANDIDATO A LA ALCADIA DE DICHA CIUDAD
				break;
			}
			case 2: {		
				int contador=0;
				
				for(int k =0;k<partidos.getTam();k++){
					for(int i =0;i<partidos.devolverDato(k).candi.getTam();i++){
						if (partidos.devolverDato(k).candi.devolverDato(i).candidatura=="Presidencia") {
							contador++;
							cout<<"presidente"<<i<<partidos.devolverDato(k).candi.devolverDato(i).nombre<<partidos.devolverDato(k).candi.devolverDato(i).apellido<<endl;
							cout<<"tama;o "<<partidos.devolverDato(k).candi.getTam()<<endl;
						}
					}
					cout<<partidos.devolverDato(k).nombre<<": "<<contador<<endl;
					contador=0;	
				}
				break;
			}
			case 3: {
				
				break;
			}
			case 4: {
				
				break;
			}
			case 5: {
				ResultadosPres();
				break;
			}
		}
	}
	
	void menu(){
		cout<<"Menu principal de las elecciones del pais del sagrado corazon"<<endl;
		cout<<endl<<"Por favor seleccione una opcion"<<endl;
		cout<<"-------------------------------"<<endl;
		cout<<"1- Consulta"<<endl<<"2- Simulacion de eleccion"<<endl<<"3- Resultados"<<endl<<"4- Estadisticas"<<endl;
		cout<<endl<<"Digite cualquier otro numero para salir"<<endl;
		cout<<"-------------------------------"<<endl<<"Seleccione: ";	
	}

	
		
	
