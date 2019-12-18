#include "Autodromos.h"
#include <iostream>
#include <string>

void Autodromos::addAutodromo(string nome, int max, int comp)
{
	vetor_autodromos.push_back(new Autodromo(nome, max, comp));
}

string Autodromos::getAsString()
{
	ostringstream s;
	s << "Autodromos" << endl;
	for (auto it = vetor_autodromos.begin(); it < vetor_autodromos.end(); it++)
	{
		s << "Nome: " << (*it)->getNome() << " Max Carros: " << (*it)->getMax() << " Comprimento: " << (*it)->getComp() << endl;
	}
	return s.str();
}

ostream& operator << (ostream& out, Autodromos& a)
{
	out << a.getAsString();
	return out;
}
