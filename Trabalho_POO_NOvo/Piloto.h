#pragma once
#include <string>

using namespace std;

class Carro;
class Piloto
{
	string nome;
	string ordem;
	string personalidade = "Generico";
	int tempo = 0;
	Carro* carro_par = nullptr;

public:
	
	Piloto(string name, string person = "Generico" ) :nome(name), personalidade(person) {}

	//get
	string getNome();
	string getPersonalidade();
	Carro* getCarroPar();
	int getTempo();

	//sets
	void setCarroPar(Carro* car_par);
	void setTempo(int segundos);

	virtual ~Piloto() 
	{
	}
};

