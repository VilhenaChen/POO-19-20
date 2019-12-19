#pragma once
#include <string>

using namespace std;

class Autodromo
{
	string nome;
	int max_carros_pista, comprimento;

public:
	Autodromo(int MaxCar, int comp, string name) :max_carros_pista(MaxCar), comprimento(comp), nome(name) {}

	//gets
	string getNome();
	int getMax();
	int getComp();

	virtual ~Autodromo() {}
};

