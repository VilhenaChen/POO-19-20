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
		if (i != 0)
		{
			test_name = name + to_string(i);
		}
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

bool DGV::leFicheiroCarros(string nome_ficheiro)
{
	ifstream f(nome_ficheiro);
	string linha, marc;
	string espaco = " ";
	string en_at, en_max;
	string mod, aux;
	if (f.is_open()) {
		while (getline(f, linha))
		{
			mod.clear();
			istringstream iss(linha);
			iss >> en_at;
			iss >> en_max;
			iss >> marc;
			iss >> mod;
			while (iss >> aux)
			{
				mod = mod + espaco;
				mod = mod + aux;
			}
			this->addCarro(stoi(en_at), stoi(en_max), marc, mod);
		}
		f.close();
		return true;
	}
	return false;
}

bool DGV::leFicheiroPilotos(string nome_ficheiro)
{
	ifstream f(nome_ficheiro);
	string linha;
	string espaco = " ";
	string nome, aux, lixo;
	if (f.is_open()) {
		while (getline(f, linha))
		{
			nome.clear();
			istringstream iss(linha);
			iss >> lixo;
			iss >> nome;
			while (iss >> aux)
			{
				nome = nome + espaco;
				nome = nome + aux;
			}
			this->addPiloto(nome);
		}
		f.close();
		return true;
	}
	return false;
}


void DGV::entraNoCarro(char let_car, string name_pil)
{
	
	for (auto ita = vetor_carros.begin(); ita < vetor_carros.end(); ita++)
	{
		if ((*ita)->getId_carro() == let_car)
		{
			for (auto itb = vetor_pilotos.begin(); itb < vetor_pilotos.end(); itb++)
			{
				if ((*itb)->getNome() == name_pil)
				{
					if ((*ita)->getPilotoPar()== nullptr)
					{
						if ((*itb)->getCarroPar()== nullptr) 
						{
							(*ita)->setPilotoPar(*itb);
							(*itb)->setCarroPar(*ita);
							cout << "O piloto" << (*ita)->getPilotoPar()->getNome() << "foi inserido no carro: " << (*itb)->getCarroPar()->getId_carro() << endl;
						}
						else
						{
							cout << "O piloto escolhido já se encontra no carro: " << (*itb)->getCarroPar()->getId_carro() << endl;
						}
					}
					else 
					{
						if ((*itb)->getCarroPar() != nullptr)
						{
							cout << "O piloto escolhido já se encontra no carro: " << (*itb)->getCarroPar()->getId_carro() << " e o carro escolhido já tem sentado o piloto: " << (*ita)->getPilotoPar()->getNome() << endl;
						}
						else
						{
							cout << "O carro escolhido já tem sentado o piloto: " << (*ita)->getPilotoPar()->getNome() << endl;
						}
					}
				}
			}
		}
	}
	
}

void DGV::saiDoCarro(char let_car)
{
	string pil_nam;
	for (auto it = vetor_carros.begin(); it < vetor_carros.end(); it++) 
	{
		if ((*it)->getId_carro() == let_car)
		{
			if ((*it)->getPilotoPar()!=nullptr)
			{
				(*it)->getPilotoPar()->setCarroPar(nullptr);
				pil_nam = (*it)->getPilotoPar()->getNome();
				(*it)->setPilotoPar(nullptr);
				cout << "O piloto " << pil_nam << " saiu do carro " << let_car << endl;
				return;
			}
			else 
			{
				cout << "O carro " << let_car << " esta vazio" << endl;
			}
		}
	}
	cout << "O carro " << let_car << " não existe" << endl;
}

void DGV::apagaCarro(char let_car)
{
	for (auto it = vetor_carros.begin(); it < vetor_carros.end(); it++)
	{
		if (let_car == (*it)->getId_carro())
		{
			if ((*it)->getPilotoPar()!= nullptr)
			{
				(*it)->getPilotoPar()->setCarroPar(nullptr);
			}
			delete* it;
			vetor_carros.erase(it);
			cout << "O carro " << let_car << " foi apagado" << endl;
			return;
		}
	}
	cout << "O carro " << let_car <<" não existe" << endl;
}

void DGV::apagaPiloto(string name_pil)
{
	for (auto it = vetor_pilotos.begin(); it < vetor_pilotos.end(); it++)
	{
		if (name_pil == (*it)->getNome())
		{
			if ((*it)->getCarroPar() != nullptr)
			{
				(*it)->getCarroPar()->setPilotoPar(nullptr);
			}
			delete* it;
			vetor_pilotos.erase(it);
			cout << "O piloto " << name_pil << " foi apagado" << endl;
			return;
		}
	}
	cout << "O piloto " << name_pil << " não existe" << endl;
}

string DGV::getAsString()
{
	ostringstream s;
	s << "Carros" << endl;
	for (auto it = vetor_carros.begin(); it < vetor_carros.end(); it++)
	{
		s << "ID: " << (*it)->getId_carro() << " Marca: " << (*it)->getMarca() << " Modelo: " << (*it)->getModelo() << " Energia Maxima: " << (*it)->getEnergia_max() << " Velociade Maxima: " << (*it)->getVelocidade_max();
		if ((*it)->getPilotoPar() != nullptr)
			s << " Contem o piloto: " << (*it)->getPilotoPar()->getNome() << endl;
		else
			s << endl;
	}
	s << "Pilotos" << endl;
	for (auto it = vetor_pilotos.begin(); it < vetor_pilotos.end(); it++)
	{
		s << "Nome: " << (*it)->getNome() << " Personalidade: " << (*it)->getPersonalidade();
		if ((*it)->getCarroPar() != nullptr)
			s << " Está no carro: " << (*it)->getCarroPar()->getId_carro() << endl;
		else
			s << endl;
	}
	return s.str();
}

ostream& operator << (ostream& out, DGV& a)
{
	out << a.getAsString();
	return out;
}