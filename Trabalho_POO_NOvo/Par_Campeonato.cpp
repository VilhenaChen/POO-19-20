#include "Par_Campeonato.h"

Piloto* Par_Campeonato::getPiloto()
{
	return piloto_par;
}

Carro* Par_Campeonato::getCarro()
{
	return carro_par;
}

int Par_Campeonato::getPosicao()
{
	return posicao_pista;
}

int Par_Campeonato::getLugarPista()
{
	return lugar_corrida;
}

int Par_Campeonato::getLugarCampeonato()
{
	return lugar_campeonato;
}

int Par_Campeonato::getTempo()
{
	return tempo;
}

bool Par_Campeonato::getLigado()
{
	return ligado;
}

bool Par_Campeonato::getAcelerador()
{
	return acelerador_pressionado;
}

bool Par_Campeonato::getTravao()
{
	return travao_pressionado;
}

int Par_Campeonato::getVelocidade()
{
	return velocidade_atual;
}

bool Par_Campeonato::getSinal()
{
	return sinal_emergencia;
}

void Par_Campeonato::setPosicao(int pos)
{
	posicao_pista = pos;
}

void Par_Campeonato::setLugarPista(int lugar)
{
	lugar_corrida = lugar;
}

void Par_Campeonato::setLugarCampeonato(int lugar)
{
	lugar_campeonato = lugar;
}

void Par_Campeonato::setTempo(int seg)
{
	tempo = seg;
}

void Par_Campeonato::setLigado(bool liga)
{
	ligado = liga;
}

void Par_Campeonato::setAcelerador(bool acelera)
{
	acelerador_pressionado = acelera;
}

void Par_Campeonato::setTravao(bool trava)
{
	travao_pressionado = trava;
}

void Par_Campeonato::setVelocidae(int velo)
{
	velocidade_atual = velo;
}

void Par_Campeonato::setSinal(bool sig)
{
	sinal_emergencia = sig;
}