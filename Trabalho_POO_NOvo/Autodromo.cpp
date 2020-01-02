#include "Autodromo.h"

string Autodromo::getNome()
{
	return nome;
}

int Autodromo::getMax()
{
	return max_carros_pista;
}

int Autodromo::getComp()
{
	return comprimento;
}

void Autodromo::addParGaragem(Par_Campeonato* par)
{
	gar.addPar(par);
}
