#include "Campeonato.h"

void Campeonato::addAutodromoCampeonato(Autodromo* autod)
{
	autodromos_campeonato.push_back(autod);
}

void Campeonato::addParCampeonato(Piloto* pil_point)
{
	pares_campeonato.push_back(new Par_Campeonato(pil_point->getCarroPar(),pil_point));
}

int Campeonato::EncontraAutodromoComMenorMaxCarros()
{
	int i = 0;
	for (auto it = autodromos_campeonato.begin(); it < autodromos_campeonato.end(); it++) 
	{
		if (i == 0 || i > (*it)->getMax()) 
		{
			i = (*it)->getMax();
		}
	}
	return i;
}

string Campeonato::getAsString()
{
	ostringstream s;
	s << "Autrodromos Escolhidos" << endl;
	for (auto it = autodromos_campeonato.begin(); it < autodromos_campeonato.end(); it++)
	{
		s <<"Nome: " << (*it)->getNome() <<" Comprimento: " <<(*it)->getComp() << " Maximo de Participantes: "<<(*it)->getMax() << endl;
	}
	s << "Pares" <<endl;
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		s << "Nome: " <<(*it)->getPiloto()->getNome()<<" ID Carro: "<<(*it)->getCarro()->getId_carro()<< " Tempo: " << (*it)->getTempo()<<endl;
	}
	return s.str();
}

void Campeonato::passatempo(int seg)
{
	int tempo_atual;
	int tempo;
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		tempo_atual = (*it)->getTempo();
		tempo = tempo_atual + seg;
		(*it)->setTempo(tempo);
	}

}

ostream& operator << (ostream& out, Campeonato& a)
{
	out << a.getAsString();
	return out;
}
