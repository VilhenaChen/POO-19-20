#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Autodromo.h"

using namespace std;

class Autodromos
{
	vector<Autodromo*> vetor_autodromos;

public:
	Autodromos() {}

	//add
	void addAutodromo(int max, int comp, string nome);

	//read from file
	bool leFicheiroAutodromos(string nome_ficheiro);

	//getTokens



	string getAsString();

	virtual ~Autodromos() {}
};

ostream& operator << (ostream& out, Autodromos& a);

