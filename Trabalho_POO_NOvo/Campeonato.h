#pragma once

#include <iostream>
#include <string>
#include "Autodromos.h"
#include "Par_Campeonato.h"

using namespace std;

class Campeonato
{
	int numero_corrida = 0;
	vector<Autodromo*> autodromos_campeonato;
	vector<Par_Campeonato*> pares_campeonato;

public: 

	//add
	void addAutodromoCampeonato(Autodromo* autod);
	void addParCampeonato(Piloto* pil_point);

	//find
	int EncontraAutodromoComMenorMaxCarros();

	//gets
	string getAsString();
	int getNumero_corrida();

	//set
	void setNumero_corrida(int num);

	void passatempo(int seg);
	void classificacao();

	virtual ~Campeonato() {}
};

ostream& operator << (ostream& out, Campeonato& a);

