#pragma once
#include <string>
#include "Piloto.h"

using namespace std;

class Carro
{
	string marca, modelo;
	char id_carro;
	float energia_max, energia_atual;
	int velocidade_max = 200;
	bool avariado = false;
	Piloto* piloto_par = nullptr;

public:
	Carro(char idc, float ea, float em, string brand, string model) : id_carro(idc), energia_atual(ea), energia_max(em), marca(brand), modelo(model){}
	//Carro(const Carro& copycar);
	//gets
	string getMarca();
	string getModelo();
	char getId_carro();
	float getEnergia_max();
	float getEnergia_atual();
	int getVelocidade_max();
	bool getAvariado();
	Piloto* getPilotoPar();

	//sets
	void setPilotoPar(Piloto* pil_par);
	void setEnergia_atual(float energia);
	void setAvariado(bool ava);

	virtual ~Carro()
	{
	}
};

