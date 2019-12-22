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
	DGV() {}

	//add
	void addCarro(int ener_atual, int ener_max, string brand, string model="Modelo Base");
	void addPiloto(string nome, string personalidade = "Generico");

	//erase

	//find
	char findNextID();
	string findNextNamePiloto(string name);

	//check

	//read from file
	bool leFicheiroCarros(string nome_ficheiro);
	bool leFicheiroPilotos(string nome_ficheiro);

	//enter the car
	void entraNoCarro(char let_car, string name_pil);

	string getAsString();

	virtual ~DGV() {}
};

ostream& operator << (ostream& out, DGV& a);