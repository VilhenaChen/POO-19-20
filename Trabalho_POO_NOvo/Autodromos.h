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
		for (auto it = vetor_autodromos.begin(); it < vetor_autodromos.end(); it++)
		{
			delete* it;
			vetor_autodromos.erase(it);
		}
	}
};

ostream& operator << (ostream& out, Autodromos& a);

