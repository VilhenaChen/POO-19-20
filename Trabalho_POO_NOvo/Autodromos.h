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
	//add
	void addAutodromo(int max, int comp, string nome);

	//read from file
	bool leFicheiroAutodromos(string nome_ficheiro);

	//getTokens

	//erase
	void apagaAutodromo(string name_aut);
	
	//find
	Autodromo* encontraAutodromo(string name_aut);

	string getAsString();

	virtual ~Autodromos() 
	{
		for (int i = 0; i < vetor_autodromos.size(); i++)
			delete vetor_autodromos[i];
	}
};

ostream& operator << (ostream& out, Autodromos& a);

