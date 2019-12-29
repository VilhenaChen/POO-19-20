#pragma once
#include <string>
#include "Piloto.h"

using namespace std;

class Carro
{
	string marca, modelo;
	char id_carro;
	int energia_max, energia_atual;
	int velocidade_max = 200;
	bool avariado = false;
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
	Piloto* getPilotoPar();
	int getTempo();

	//sets
	void setPilotoPar(Piloto* pil_par);
	//void setTempo(int segundos);

	virtual ~Carro()
	{
	}
};

