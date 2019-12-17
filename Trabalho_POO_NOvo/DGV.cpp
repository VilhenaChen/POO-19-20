#include "DGV.h"
#include <iostream>
#include <string>

void DGV::addCarro(int ener_atual, int ener_max, string brand, string model)
{
	char id = this->findNextID();
	vetor_carros.push_back(new Carro(id, ener_atual, ener_max, brand, model));
}

void DGV::addPiloto(string nome, string personalidade)
{
	string novo_nome = this->findNextNamePiloto(nome);
	vetor_pilotos.push_back(new Piloto(novo_nome));
}

char DGV::findNextID()
{
	bool letra_encon;
	for (int i = 97; i < 122; i++)
	{
		letra_encon = false;
		for (auto it = vetor_carros.begin(); it < vetor_carros.end(); it++)
		{
			if (char(i) == (*it)->getId_carro())
			{
				letra_encon = true;
				break;
			}
		}
		if (letra_encon == false)
		{
			return char(i);
		}
	}
	return '?';
}

string DGV::findNextNamePiloto(string name)
{
	bool nome_encon = false;
	string test_name = name;
	int i = 0;
	do
	{
		test_name = name + to_string(i);
		nome_encon = false;
		for (auto it = vetor_pilotos.begin(); it < vetor_pilotos.end(); it++)
		{
			if (test_name == (*it)->getNome())
			{
				nome_encon = true;
				i++;
				break;
			}
		}
	} while (nome_encon == true);
	return test_name;
}

string DGV::getAsString()
{
	ostringstream s;
	cout << "Carros" << endl;
	for (auto it = vetor_carros.begin(); it < vetor_carros.end(); it++)
	{
		s << "ID: " << (*it)->getId_carro() << " Marca: " << (*it)->getMarca() << " Modelo: " << (*it)->getModelo() << " Energia Maxima: " << (*it)->getEnergia_max() << " Velociade Maxima: " << (*it)->getVelocidade_max() << endl;
	}
	cout << "Pilotos" << endl;
	for (auto it = vetor_pilotos.begin(); it < vetor_pilotos.end(); it++)
	{
		s << "Nome: " << (*it)->getNome() << " Personalidade: " << (*it)->getPersonalidade() << endl;
	}
	return s.str();
}

ostream& operator << (ostream& out, DGV& a)
{
	out << a.getAsString();
	return out;
}