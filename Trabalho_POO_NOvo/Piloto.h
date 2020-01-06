#pragma once
#include <string>

using namespace std;

class Carro;
class Piloto
{
	string nome;
	string personalidade;
	string pers_temp;
	bool morto = false;
	Carro* carro_par = nullptr;

public:
	
	Piloto(string name, string person ) :nome(name), personalidade(person) {}

	//get
	string getNome();
	string getPersonalidade();
	string getPersonalidadeTemporaria();
	bool getMorto();
	Carro* getCarroPar();

	//sets
	void setCarroPar(Carro* car_par);
	void setPersonalidadeTemporaria(string person);
	void setmorto(bool estado);

	virtual ~Piloto() 
	{
	}
};

