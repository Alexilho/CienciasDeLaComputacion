#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <cstdlib>
#include <iostream>
#include "Lista.h"

using namespace std;

	struct Candidatos {
		int posicion;
		string nombre;
		string apellido;
		int identificacion;
		char sexo;
		string estadoCivil;
		string fnacimiento;
		string ciudadNac;
		string ciudadRes; //solo se pueden postular quienes residan en el pueblo
		string partido;
		string candidatura;
		string vicepresidente; //si candidatura es igual a presidente
	};
	
	struct Partidos{
		int posicion;
		string nombre;
		string representante;
		Lista <Candidatos> candi;
	};
	
	struct Ciudad {
		int posicion;
		string nombre;
		string departamento;
		int censo; //debe ser generado al azar
		Lista <Partidos> parti; //por ahora manejarlo asi y estudiar si es necesario algun cambio
	};
	
	struct Ganadores {
		int ganador;
	};


#endif
