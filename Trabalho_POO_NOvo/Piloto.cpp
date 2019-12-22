#include "Piloto.h"

string Piloto::getNome()
{
	return nome;
}

string Piloto::getPersonalidade()
{
	return personalidade;
}

Carro* Piloto::getCarroPar()
{
	return carro_par;
}

void Piloto::setCarroPar(Carro* car_par)
{
	carro_par = car_par;
}
