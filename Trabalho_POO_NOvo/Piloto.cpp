#include "Piloto.h"

string Piloto::getNome()
{
	return nome;
}

string Piloto::getPersonalidade()
{
	return personalidade;
}

string Piloto::getPersonalidadeTemporaria()
{
	return pers_temp;
}

Carro* Piloto::getCarroPar()
{
	return carro_par;
}

int Piloto::getTempo()
{
	return tempo;
}

void Piloto::setCarroPar(Carro* car_par)
{
	carro_par = car_par;
}

void Piloto::setTempo(int segundos)
{
	tempo = tempo + segundos;
}

void Piloto::setPersonalidadeTemporaria(string person)
{
	pers_temp = person;
}
