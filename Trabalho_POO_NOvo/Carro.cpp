#include "Carro.h"

/*Carro::Carro(const Carro& copycar)
{
	id_carro = copycar.id_carro;
	energia_atual = copycar.energia_atual;
	energia_max = copycar.energia_max;
	marca = copycar.marca;
	modelo = copycar.modelo;
	velocidade_max = copycar.velocidade_max;
	avariado = copycar.avariado;
}*/

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
