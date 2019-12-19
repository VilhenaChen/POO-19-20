#pragma once
#include <string>
#include "Piloto.h"

using namespace std;

class Carro
{
	string marca, modelo;
	char id_carro;
	int energia_max, energia_atual;
	bool ligado = false;
	int velocidade_max = 200, velocidade_atual = 0;
	bool acelerador_pressionado = false, travao_pressionado = false;
	bool sinal_emergencia = false;
	bool avariado = false;
	int tempo = 0;
	Piloto* piloto_par = nullptr;

public:
	Carro(char idc, int ea, int em, string brand, string model) : id_carro(idc), energia_atual(ea), energia_max(em), marca(brand), modelo(model){}

	//gets
	string getMarca();
	string getModelo();
	char getId_carro();
	int getEnergia_max();
	int getEnergia_atual();
	int getVelocidade_max();



	virtual ~Carro() {}
};

