#include "Carro.h"

string Carro::getMarca()
{
	return marca;
}

string Carro::getModelo()
{
	return modelo;
}

char Carro::getId_carro()
{
	return id_carro;
}

int Carro::getEnergia_max()
{
	return energia_max;
}

int Carro::getEnergia_atual()
{
	return energia_atual;
}

int Carro::getVelocidade_max()
{
	return velocidade_max;
}

Piloto* Carro::getPilotoPar()
{
	return piloto_par;
}

void Carro::setPilotoPar(Piloto* pil_par)
{
	piloto_par = pil_par;
}
