#pragma once
#include <string>

using namespace std;

class Carro;
class Piloto
{
	string nome;
	string ordem;
	string personalidade = "Generico";
	Carro* carro_par = nullptr;

public:
	
	Piloto(string name, string person = "Generico" ) :nome(name), personalidade(person) {}

	//get
	string getNome();
	string getPersonalidade();
	Carro* getCarroPar();

	//sets
	void setCarroPar(Carro* car_par);

	virtual ~Piloto() 
	{
	}
};

