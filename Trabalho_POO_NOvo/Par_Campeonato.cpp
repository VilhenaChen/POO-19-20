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

int Par_Campeonato::getPontos()
{
	return pontos;
}

bool Par_Campeonato::getSaiucorrida()
{
	return saiucorrida;
}

bool Par_Campeonato::getTerminouCorrida()
{
	return terminou_corrida;
}

int Par_Campeonato::getSegacel()
{
	return segacel;
}

int Par_Campeonato::getSegsemacel()
{
	return segsemacel;
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

void Par_Campeonato::setVelocidade(int velo)
{
	velocidade_atual = velo;
}

void Par_Campeonato::setSinal(bool sig)
{
	sinal_emergencia = sig;
}

void Par_Campeonato::setPontos(int pon)
{
	pontos = pon;
}

void Par_Campeonato::setSaiucorrida(bool saiu)
{
	saiucorrida = saiu;
}

void Par_Campeonato::setTerminouCorrida(bool term)
{
	terminou_corrida = term;
}

void Par_Campeonato::setSegacel(int seg)
{
	segacel = seg;
}

void Par_Campeonato::setSegsemacel(int seg)
{
	segsemacel = seg;
}

void Par_Campeonato::aumentaVelocidade()
{
	int vel;
	vel = getVelocidade();
	if (getAcelerador() == true)
	{
		setVelocidade(vel + 1);
	}
}

void Par_Campeonato::diminuiVelocidade()
{
	int vel;
	vel = getVelocidade();
	if (getTravao() == true)
	{
		setVelocidade(vel - 1);
	}
}
