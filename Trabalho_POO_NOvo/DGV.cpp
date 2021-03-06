#include "DGV.h"
#include <iostream>
#include <string>


DGV::DGV(const DGV& copy, string name)
{
	nome = name;
	for (auto it = copy.vetor_carros.begin(); it < copy.vetor_carros.end();it++) 
	{
		vetor_carros.push_back(new Carro((*it)->getId_carro(), (*it)->getEnergia_atual(), (*it)->getEnergia_max(), (*it)->getMarca(),(*it)->getModelo()));
	}
	for (auto it = copy.vetor_pilotos.begin(); it < copy.vetor_pilotos.end(); it++)
	{
		vetor_pilotos.push_back(new Piloto((*it)->getNome(),(*it)->getPersonalidade()));
	}
	for (auto itc = copy.vetor_carros.begin(); itc < copy.vetor_carros.end(); itc++)
	{
		for (auto it = vetor_carros.begin(); it < copy.vetor_carros.end(); it++)
		{
			(*it)->setAvariado((*it)->getAvariado());
			if ((*it)->getId_carro() == (*itc)->getId_carro()) 
			{
				for (auto itpc = vetor_pilotos.begin(); itpc < vetor_pilotos.end(); itpc++)
				{
					if ((*itpc)->getNome() == (*itc)->getPilotoPar()->getNome()) 
					{
						(*it)->setPilotoPar((*itpc));
						(*itpc)->setCarroPar((*it));
					}
				}
			}

		}
	}
}

void DGV::addCarro(float ener_atual, float ener_max, string brand, string model)
{
	char id = this->findNextID();
	vetor_carros.push_back(new Carro(id, ener_atual, ener_max, brand, model));
}

void DGV::addPiloto(string nome, string personalidade)
{
	string novo_nome = this->findNextNamePiloto(nome);
	vetor_pilotos.push_back(new Piloto(novo_nome, personalidade));
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

Piloto* DGV::getPilotoSegundoPosicaoNoVetor(int posi)
{
	return vetor_pilotos[posi];
}

Carro* DGV::getCarroSegundoPosicaoNoVetor(int posi)
{
	return vetor_carros[posi];
}

size_t DGV::getTamVetorPilotos()
{
	size_t tam=vetor_pilotos.size();
	return tam;
}

size_t DGV::getTamVetorCarros()
{
	size_t tam = vetor_pilotos.size();
	return tam;
}

string DGV::getNome()
{
	return nome;
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
			if (stof(en_at) > 0 && (stof(en_max) > stof(en_at)))
			{
				this->addCarro(stof(en_at), stof(en_max), marc, mod);
			}
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
	string nome, aux, genero;
	if (f.is_open()) {
		while (getline(f, linha))
		{
			nome.clear();
			istringstream iss(linha);
			iss >> genero;
			iss >> nome;
			while (iss >> aux)
			{
				nome = nome + espaco;
				nome = nome + aux;
			}
			if (genero == "crazy" || genero == "rapido" || genero == "surpresa")
			{
				this->addPiloto(nome, genero);
			}
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
							cout << "O piloto " << (*ita)->getPilotoPar()->getNome() << " foi inserido no carro: " << (*itb)->getCarroPar()->getId_carro() << endl;
							return;
						}
						else
						{
							cout << "O piloto escolhido j� se encontra no carro: " << (*itb)->getCarroPar()->getId_carro() << endl;
							return;
						}
					}
					else 
					{
						if ((*itb)->getCarroPar() != nullptr)
						{
							cout << "O piloto escolhido j� se encontra no carro: " << (*itb)->getCarroPar()->getId_carro() << " e o carro escolhido j� tem sentado o piloto: " << (*ita)->getPilotoPar()->getNome() << endl;
							return;
						}
						else
						{
							cout << "O carro escolhido j� tem sentado o piloto: " << (*ita)->getPilotoPar()->getNome() << endl;
							return;
						}
					}
				}
			}
			cout << "O Piloto " << name_pil << " n�o existe" << endl;
			return;
		}
	}
	cout << "O carro " << let_car << " n�o existe" << endl;
	
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
				return;
			}
		}
	}
	cout << "O carro " << let_car << " n�o existe" << endl;
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
	cout << "O carro " << let_car <<" n�o existe" << endl;
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
	cout << "O piloto " << name_pil << " n�o existe" << endl;
}

void DGV::verificaPilotosMortos()
{
	for (auto it = vetor_pilotos.begin(); it < vetor_pilotos.end(); it++) 
	{
		if ((*it)->getMorto() == true) 
		{
			apagaPiloto((*it)->getNome());
		}
	}
}

void DGV::verificaCarrosDestruidos()
{
	for (auto it = vetor_carros.begin(); it < vetor_carros.end(); it++)
	{
		if ((*it)->getDestruido() == true)
		{
			apagaCarro((*it)->getId_carro());
		}
	}
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
			s << " Est� no carro: " << (*it)->getCarroPar()->getId_carro() << endl;
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