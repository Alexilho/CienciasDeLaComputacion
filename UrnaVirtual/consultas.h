#include <stddef.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#include "convertidorTxt.h"

void Cargar();

class consultas{
	public: 
	Lista<Candidatos> candidatos;
	Lista<Partidos> partidos;
	Lista<Ciudad> ciudades;
	Lista<Candidatos> consultasCan;
	Lista<Ciudad> consultasCiu;
	Lista<Partidos> consultasPar;
	
	convertidor convertidorTxt;
	
	consultas(){
		Cargar();	
	}
	
	//CONSULTAR ALCALDIA SOLO POR PARTIDO

	Lista<Candidatos>* cons_Alcaldia_Partido(string partidoConsultar){
		
		Lista<Candidatos> consultasCan1;
		consultasCan=consultasCan1;
		for(int i = 0; i < partidos.getTam(); i++){
			if (partidos.devolverDato(i).nombre == partidoConsultar)
				for(int k=0;k<partidos.devolverDato(i).candi.getTam();k++){
					if (partidos.devolverDato(i).candi.devolverDato(k).candidatura == "Alcaldia") {
						consultasCan.anadir_final(partidos.devolverDato(i).candi.devolverDato(k));	
					}					
				}
		}
		return &consultasCan;
	}
	
	Lista<Candidatos> *cons_Presidencia(string partidoConsultar){
		
		Lista<Candidatos> consultasCan1;
		consultasCan=consultasCan1;
		for(int i = 0; i < partidos.getTam(); i++){
			if (partidos.devolverDato(i).nombre == partidoConsultar)
				for(int k=0;k<partidos.devolverDato(i).candi.getTam();k++){
					if (partidos.devolverDato(i).candi.devolverDato(k).candidatura == "Alcaldia") {
						consultasCan.anadir_final(partidos.devolverDato(i).candi.devolverDato(k));	
					}					
				}
		}
		return &consultasCan;
	}
	
	//CIUDADES PARA LAS CUALES SE REALIZARA EL PROCESO ELECTORAL
	
	Lista<Ciudad> *ciu_ProcesoElectoral (){
		
		Lista<Ciudad> consultasCiu1;
		consultasCiu=consultasCiu1;
		
		for (int i=0; i<ciudades.getTam(); i++){
			consultasCiu.anadir_final(ciudades.devolverDato(i));
		}
		return &consultasCiu;		
	}
	
	//PARTIDOS LEGALMENTE RECONOCIDOS
	
	Lista<Partidos> *parti_Reconocidos (){
		
		Lista<Partidos> consultasPar1;
		consultasPar= consultasPar1;
		
		for (int i=0; i<partidos.getTam(); i++) {
			consultasPar.anadir_final(partidos.devolverDato(i));
		}
		return &consultasPar;
	}
	//TODOS LOS CANDIDATOS A LA ALCADIA DE UNA CITY
	Lista<Candidatos> *candidatos_Alcaldia_una_Ciudad (string ciudadConsultar){
		
		Lista<Candidatos> consultasCan1;
		consultasCan=consultasCan1;
		for(int i = 0; i < candidatos.getTam(); i++){
			if (candidatos.devolverDato(i).ciudadRes == ciudadConsultar)
				if (candidatos.devolverDato(i).candidatura == "Alcaldia") 
					consultasCan.anadir_final(candidatos.devolverDato(i));	
		}	
		return &consultasCan;
	}
	
	//CANDIDATOS A PRESIDENCIA Y VICEPRESIDENCIA
	Lista<Candidatos> *candidatos_a_Presidencia (){
		
		Lista<Candidatos> consultasCan1;
		consultasCan=consultasCan1;
		for(int i = 0; i < candidatos.getTam(); i++){
			if (candidatos.devolverDato(i).candidatura == "Presidencia") 
					consultasCan.anadir_final(candidatos.devolverDato(i));	
		}	
		return &consultasCan;
	}
	
	//DADO UN PARTIDO Y DEPTO MUESTRE CANDIDATOS A ALCALDIA
	Lista<Candidatos> *candi_Alcal_por_Parti_Depto(string partidoConsultar, string deptoConsultar){
		
		Lista<Candidatos> consultasCan1;
		consultasCan=consultasCan1;
		bool repetido = true;
		for(int i = 0; i < ciudades.getTam(); i++){
			if(ciudades.devolverDato(i).departamento == deptoConsultar) {
				for (int k=0; k<ciudades.devolverDato(i).parti.getTam() ; k++) {
					if (ciudades.devolverDato(i).parti.devolverDato(k).nombre == partidoConsultar) {
						for (int j=0; j<ciudades.devolverDato(i).parti.devolverDato(k).candi.getTam() ; j++) {
							if (ciudades.devolverDato(i).parti.devolverDato(k).candi.devolverDato(j).candidatura == "Alcaldia" && 
							ciudades.devolverDato(i).parti.devolverDato(k).candi.devolverDato(j).ciudadRes==ciudades.devolverDato(i).nombre) {
								for(int t=0;t<consultasCan.getTam();t++){
									if(consultasCan.devolverDato(t).posicion!=ciudades.devolverDato(i).parti.devolverDato(k).candi.devolverDato(j).posicion){
										repetido=true;
									}else{
										repetido=false;
										break;
									}
								}
								if(repetido){
									consultasCan.anadir_final(ciudades.devolverDato(i).parti.devolverDato(k).candi.devolverDato(j));
								}
								repetido=false;
							}
						}	
					}
				}
			}
		}	
		return &consultasCan;
	}
	
	
	
	void Cargar(){
		convertidorTxt.leerTxt();
		candidatos = *convertidorTxt.devolver_lista_candidatos();
		partidos = *convertidorTxt.devolver_lista_partidos();
		ciudades = *convertidorTxt.devolver_lista_ciudades();
	}
};
