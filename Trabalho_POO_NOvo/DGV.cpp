#include "DGV.h"

void DGV::addCarro(int ener_atual, int ener_max, string brand, string model)
{
	char id = this->findNextID();
	vetor_carros.push_back(new Carro(id, ener_atual, ener_max, brand, model));
}

char DGV::findNextID()
{
	bool letra_encon;
	for (int i = 97; i < 122; i++)
	{
		letra_encon = false;
		for (auto it = vetor_carros.begin(); it < vetor_carros.end(); it++)
		{
			if (char(i) == (*it)->getid_carro())
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

char DGV::findNextnamePiloto(string name)
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
