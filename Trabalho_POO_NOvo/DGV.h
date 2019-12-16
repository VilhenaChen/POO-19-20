#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Carro.h"
#include "Piloto.h"

using namespace std;

class DGV
{
	vector <Carro*> vetor_carros;
	vector <Piloto*> vetor_pilotos;

public:
	DGV():{}

	//add
	void addCarro(int ener_atual, int ener_max, string brand, string model = "Moldelo Base");
	void addPiloto(string nome, string personalidade = "Generico");
	//erase

	//find
	char findNextID();
	char findNextnamePiloto(string name);
	//check

	virtual ~DGV() {}
};