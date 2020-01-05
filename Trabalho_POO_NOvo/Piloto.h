#pragma once
#include <string>

using namespace std;

class Carro;
class Piloto
{
	string nome;
	string personalidade;
	string pers_temp;
	Carro* carro_par = nullptr;

public:
	
	Piloto(string name, string person ) :nome(name), personalidade(person) {}

	//get
	string getNome();
	string getPersonalidade();
	string getPersonalidadeTemporaria();
	Carro* getCarroPar();

	//sets
	void setCarroPar(Carro* car_par);
	void setPersonalidadeTemporaria(string person);

	virtual ~Piloto() 
	{
	}
};

