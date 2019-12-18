#pragma once
#include <string>

using namespace std;

class Autodromo
{
	string nome;
	int max_carros_pista, comprimento;

public:
	Autodromo(string name, int MaxCar, int comp) :nome(name), max_carros_pista(MaxCar), comprimento(comp) {}

	//gets
	string getNome();
	int getMax();
	int getComp();

	virtual ~Autodromo() {}
};

