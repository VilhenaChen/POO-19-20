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
	//add
	void addCarro(int ener_atual, int ener_max, string brand, string model="Modelo Base");
	void addPiloto(string nome, string personalidade = "Generico");

	//erase

	//find
	char findNextID();
	string findNextNamePiloto(string name);

	//get
	Piloto* getPilotoSegundoPosicaoNoVetor(int posi);
	size_t getTamVetorPilotos();

	//read from file
	bool leFicheiroCarros(string nome_ficheiro);
	bool leFicheiroPilotos(string nome_ficheiro);

	//enter the car
	void entraNoCarro(char let_car, string name_pil);

	//get out of the car
	void saiDoCarro(char let_car);
	//erase
	void apagaCarro(char let_car);
	void apagaPiloto(string name_pil);

	string getAsString();

	virtual ~DGV() 
	{
		for (int i = 0; i < vetor_carros.size(); i++)
			delete vetor_carros[i];
		for (int j = 0; j < vetor_pilotos.size(); j++)
			delete vetor_pilotos[j];
	}
};

ostream& operator << (ostream& out, DGV& a);