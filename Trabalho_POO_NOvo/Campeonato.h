#pragma once

#include <iostream>
#include <string>
#include "Autodromos.h"
#include "Par_Campeonato.h"
using namespace std;
class Campeonato
{
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

	void passatempo(int seg);

	virtual ~Campeonato() {}
};

ostream& operator << (ostream& out, Campeonato& a);

