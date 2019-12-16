#pragma once
#include <string>

class Autodromo
{
	string nome;
	int max_carros_pista, comprimento;

public:
	Autodromo(string name, int MaxCar int comp) :nome(name), max_carros_pista(Maxcar), comprimento(comp) {}
	virtual ~Autodromo{}
};

