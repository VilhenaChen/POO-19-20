#include "Autodromos.h"
#include <iostream>
#include <string>

void Autodromos::addAutodromo(int max, int comp, string nome)
{
	vetor_autodromos.push_back(new Autodromo(max, comp,nome));
}

bool Autodromos::leFicheiroAutodromos(string nome_ficheiro)
{
	ifstream f(nome_ficheiro);
	string linha;
	string espaco = " ";
	string num_car, com;
	string nome,aux;
	if (f.is_open()) {
		while (getline(f, linha))
		{
			nome.clear();
			istringstream iss(linha);
			iss >> num_car;
			iss >> com;
			iss >> nome;
			while (iss >> aux) 
			{
				nome = nome + espaco;
				nome = nome + aux;
			}
			this->addAutodromo(stoi(num_car), stoi(com), nome);
		}
		f.close();
		return true;
	}
	return false;
}

void Autodromos::apagaAutodromo(string name_aut)
{
	for (auto it = vetor_autodromos.begin(); it < vetor_autodromos.end(); it++)
	{
		if (name_aut == (*it)->getNome())
		{
			delete* it;
			vetor_autodromos.erase(it);
			cout << "O carro " << name_aut << " foi apagado" << endl;
			return;
		}
	}
	cout << "O autodromo " << name_aut << " não existe" << endl;
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
