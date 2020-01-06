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
	string nome = "principal";
	vector <Carro*> vetor_carros;
	vector <Piloto*> vetor_pilotos;

public:
	DGV() {}
	DGV(const DGV& copy, string name);
	//add
	void addCarro(float ener_atual, float ener_max, string brand, string model="Modelo Base");
	void addPiloto(string nome, string personalidade);

	

	//find
	char findNextID();
	string findNextNamePiloto(string name);

	//get
	Piloto* getPilotoSegundoPosicaoNoVetor(int posi);
	Carro* getCarroSegundoPosicaoNoVetor(int posi);
	size_t getTamVetorPilotos();
	size_t getTamVetorCarros();
	string getNome();

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

	//verify
	void verificaPilotosMortos();
	void verificaCarrosDestruidos();

	string getAsString();

	virtual ~DGV() 
	{
		for (auto it = vetor_carros.begin(); it < vetor_carros.end(); it++)
		{
			delete* it;
			vetor_carros.erase(it);
		}
		for (auto it=vetor_pilotos.begin(); it < vetor_pilotos.end(); it++)
		{
			delete* it;
			vetor_pilotos.erase(it);
		}
	}
};

ostream& operator << (ostream& out, DGV& a);