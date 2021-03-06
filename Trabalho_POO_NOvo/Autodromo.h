#pragma once
#include <string>
#include "Garagem.h"
using namespace std;

class Autodromo
{
	string nome;
	int max_carros_pista, comprimento;
	Garagem gar;

public:
	Autodromo(int MaxCar, int comp, string name) :max_carros_pista(MaxCar), comprimento(comp), nome(name) {}

	//gets
	string getNome();
	int getMax();
	int getComp();

	//add
	void addParGaragem(Par_Campeonato* par);

	virtual ~Autodromo() {}
};
