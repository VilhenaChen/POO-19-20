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

float Carro::getEnergia_max()
{
	return energia_max;
}

float Carro::getEnergia_atual()
{
	return energia_atual;
}

int Carro::getVelocidade_max()
{
	return velocidade_max;
}

bool Carro::getAvariado()
{
	return avariado;
}

Piloto* Carro::getPilotoPar()
{
	return piloto_par;
}

void Carro::setPilotoPar(Piloto* pil_par)
{
	piloto_par = pil_par;
}

void Carro::setEnergia_atual(float energia)
{
	energia_atual = energia;
}

void Carro::setAvariado(bool ava)
{
	avariado = ava;
}
