#pragma once
#include <string>

using namespace std;

class Carro;
class Piloto
{
	string nome;
	string ordem;
	string personalidade = "Generico";
	string pers_temp;
	int tempo = 0;
	Carro* carro_par = nullptr;

public:
	
	Piloto(string name, string person = "Generico" ) :nome(name), personalidade(person) {}

	//get
	string getNome();
	string getPersonalidade();
	string getPersonalidadeTemporaria();
	Carro* getCarroPar();
	int getTempo();

	//sets
	void setCarroPar(Carro* car_par);
	void setTempo(int segundos);
	void setPersonalidadeTemporaria(string person);

	virtual ~Piloto() 
	{
	}
};

