#pragma once
#include "DGV.h"
class Par_Campeonato
{
	int posicao_pista=0, lugar_corrida=0, lugar_campeonato=0, tempo=0;
	bool ligado = false;
	bool acelerador_pressionado = false, travao_pressionado = false;
	int velocidade_atual = 0;
	bool sinal_emergencia = false;
	Carro* carro_par;
	Piloto* piloto_par;

public:
	Par_Campeonato(Carro* car, Piloto* pilot) : carro_par(car), piloto_par(pilot) {}
	//get
	Piloto* getPiloto();
	Carro* getCarro();
	int getPosicao();
	int getLugarPista();
	int getLugarCampeonato();
	int getTempo();
	bool getLigado();
	bool getAcelerador();
	bool getTravao();
	int getVelocidade();
	bool getSinal();

	//set
	void setPosicao(int pos);
	void setLugarPista(int lugar);
	void setLugarCampeonato(int lugar);
	void setTempo(int seg);
	void setLigado (bool liga);
	void setAcelerador(bool acelera);
	void setTravao(bool trava);
	void setVelocidae(int velo);
	void setSinal(bool sig);


	virtual ~Par_Campeonato()
	{
	}

};
