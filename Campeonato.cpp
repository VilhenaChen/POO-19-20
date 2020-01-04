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
		s << "Nome: " << (*it)->getPiloto()->getNome() << " ID Carro: " << (*it)->getCarro()->getId_carro() << " Tempo: " << (*it)->getTempo() << " Velocidade: " << (*it)->getVelocidade() << " Posicao pista: "<< (*it)->getPosicao()<< " Classificacao: "<< (*it)->getLugarPista()<<endl;
	}
	return s.str();
}

int Campeonato::getNumero_corrida()
{
	return numero_corrida;
}

bool Campeonato::getCorridaDecorrer()
{
	return corrida_decorrer;
}

int Campeonato::getTotalvetor()
{
	int total=0;
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		total++;
	}
	return total;
}

char Campeonato::getIDCarro(int posicao)
{
	char id;
	id = pares_campeonato[posicao]->getCarro()-> getId_carro();
	return id;
}

Carro* Campeonato::getCarro(char idcarro)
{
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++) 
	{
		if ((*it)->getCarro()->getId_carro() == idcarro) 
		{
			return (*it)->getCarro();
		}
	}
	return nullptr;
}

void Campeonato::setNumero_corrida(int num)
{
	numero_corrida = num;
}

void Campeonato::setCorridaDecorrer(bool cor)
{
	corrida_decorrer  = cor;
}

void Campeonato::setClassificacaoCorrida()
{
	int comp = autodromos_campeonato[numero_corrida]->getComp();
	int lugar = 1;
	int cont = 0;
	int lugant;
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		if ((*it)->getTerminouCorrida() == true) 
		{
			if (lugar <= (*it)->getLugarPista())
			{
				cont++;
			}
		}
	}
	for (int i = comp; i >= 0 ; i--) 
	{
		lugar = cont + 1;
		for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
		{
			if ((*it)->getTerminouCorrida() == false)
			{
				if (i == (*it)->getPosicao())
				{
					lugant = (*it)->getLugarPista();
					(*it)->setLugarPista(lugar);
					cont++;
					if ((*it)->getPiloto()->getPersonalidade() == "Crazy Driver")
					{
						if (lugant < lugar && (*it)->getAcelerador()==false)
						{
							(*it)->setAcelerador(true);
							(*it)->setSegacel(1);
						}
						else 
						{
							if ((*it)->getAcelerador() == true)
							{
								if ((*it)->getSegacel() == 0)
								{
									if (lugant < lugar)
									{
										(*it)->setSegacel(1);
									}
									else 
									{
										(*it)->setAcelerador(false);
									}
								}
								else 
								{
									if ((*it)->getSegacel() == 2) 
									{
										(*it)->setAcelerador(false);
										(*it)->setSegacel(0);
									}
									else 
									{
										(*it)->setSegacel(2);
									}
								}
							}
						}
					}
					if ((*it)->getPosicao() == comp)
					{
						(*it)->setTerminouCorrida(true);
					}
				}
			}
		}
	}

}

void Campeonato::setClassificacaoCampeonato()
{

}

void Campeonato::preparaCorrida()
{
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		(*it)->setPosicao(0);
		(*it)->setLugarPista(0);
		(*it)->setLugarCampeonato(0);
		(*it)->setTempo(0);
		(*it)->setVelocidade(1);
		(*it)->setTerminouCorrida(false);
		(*it)->setSegacel(0);
	}
}

void Campeonato::lancaCorrida()
{
	int count=0;
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		count++;
	}
	if (count < 2)
	{
		cout << "[ERRO] A Corrida nao pode comecar, nao exitem pelo menos 2 participantes!!!" << endl;
		//falta verificar isto
	}
	setCorridaDecorrer(true);
	cout << "Corrida no Autodromo: " << autodromos_campeonato[numero_corrida]->getNome() << " (" << autodromos_campeonato[numero_corrida]->getComp() << ")" << endl;
	cout << "Pares participantes: " << endl;
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		cout << "Nome: " <<(*it)->getPiloto()->getNome()<<" ID Carro: "<<(*it)->getCarro()->getId_carro()<< " Tempo: " << (*it)->getTempo()<<endl;
	}
}


void Campeonato::Lugar(Par_Campeonato* par)
{
	int lugar;
	int last;
	last = getUltimo();
	lugar =par->getLugarPista();
	if (lugar == 1)
	{
		par->setAcelerador(false);
		par->setTravao(false);
	}
	else
	{
		if (lugar == last)
		{
			par->setAcelerador(false);
			par->setAcelerador(true);
		}
		else
		{
			par->setAcelerador(true);
			par->setTravao(false);
		}
	}
}

int Campeonato::getUltimo()
{
	int lugar = 0, ultimo = 0;
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		lugar = (*it)->getLugarPista();
		if (ultimo < lugar)
		{
			ultimo = lugar;
		}
	}
	return ultimo;
}
/*
void Campeonato::Perdeulugares()
{

}

void Campeonato::SemBat(int pos)
{
	pares_campeonato[pos]->setSinal(true);
}

void Campeonato::probAcidente()
{

}
*/
void Campeonato::carregaAllBat()
{
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		if ((*it)->getLigado() == false)
		{
			float enMax;
			enMax = (*it)->getCarro()->getEnergia_max();
			(*it)->getCarro()->setEnergia_atual(enMax);
		}
		else
		{
			cout << "[ERRO] O Carro " << (*it)->getCarro()->getId_carro() << " nao esta parado!!" << endl;
		}
	}

}

void Campeonato::carregaBat(char idcarro, float energia)
{
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		if ((*it)->getCarro()->getId_carro() == idcarro)
		{
			if ((*it)->getLigado() == false)
			{
				(*it)->getCarro()->setEnergia_atual(energia);
			}
			else
			{
				cout << "[ERRO] O carro nao esta Parado!!!" << endl;
			}
			return;
		}
	}
	cout << "[ERRO] O Carro nao esta a participar neste Campeoonato" << endl;
}

void Campeonato::paraCarro(string nome)
{
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		if ((*it)->getPiloto()->getNome() == nome)
		{
			(*it)->setAcelerador(false);
			(*it)->setTravao(true);
			(*it)->setSaiucorrida(true);
		}
	}
	cout << "O Piloto " << nome << " nao esta a participar!!!" << endl;
}

void Campeonato::acidente(char idcarro)
{
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		if ((*it)->getCarro()->getId_carro() == idcarro)
		{
			if ((*it)->getCarro()->getAvariado() == false)
			{
				(*it)->getCarro()->setAvariado(true);
				return;
			}
			else 
			{
				cout << "O carro " << idcarro << " já esta avariado " << endl;
			}
		}
	}
	cout << "O carro " << idcarro << " nao existe!!!" << endl;
}

void Campeonato::acabaCorrida()
{
	cout << "Classificação final da corrida: " << endl;
	mostraInformacaoCorrridaOrganizada();
	atribuiPontos();
	setCorridaDecorrer(false);
	numero_corrida++;

}

void Campeonato::mostraInformacaoCorrridaOrganizada()
{
cout << "Informacao sobre a corrida no autodromo " << autodromos_campeonato[numero_corrida]->getNome() << " (" << autodromos_campeonato[numero_corrida]->getComp() << " m) :" << endl;
for (int i = 1; i < pares_campeonato.size(); i++)
{
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		if (i == (*it)->getLugarPista())
		{
			cout << i << ". " << (*it)->getCarro()->getId_carro() << " " << (*it)->getCarro()->getMarca() << " / " << (*it)->getPiloto()->getNome() << " ( " << (*it)->getPiloto()->getPersonalidade() << ") - " << (*it)->getCarro()->getEnergia_atual() << "mAh, " << (*it)->getCarro()->getEnergia_max() << "mAh - " << (*it)->getPosicao() << "m - " << (*it)->getVelocidade() << "m/s" << endl;
		}
	}

}
}

bool Campeonato::verificaSeJaTodosAcabaram()
{
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		if ((*it)->getTerminouCorrida() == false)
		{
			return false;
		}
	}
	return true;
}

void Campeonato::atribuiPontos()
{
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		if ((*it)->getLugarPista() == 1)
		{
			int pontos = 0;
			pontos = ((*it)->getPontos()) + 10;
			(*it)->setPontos(pontos);
		}
		else
		{
			if ((*it)->getLugarPista() == 2)
			{
				int pontos = 0;
				pontos = ((*it)->getPontos()) + 10;
				(*it)->setPontos(pontos);
			}
			else
			{
				if ((*it)->getLugarPista() == 3)
				{
					int pontos = 0;
					pontos = ((*it)->getPontos()) + 2;
					(*it)->setPontos(pontos);
				}
			}
		}
	}
}

void Campeonato::destroi(char idcarro)
{
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		if (idcarro == (*it)->getCarro()->getId_carro())
		{
			delete* it;
			pares_campeonato.erase(it);
			return;
		}
	}
	cout << "O carro " << idcarro << " não esta neste campeonato " << endl;
}

void Campeonato::passatempo(int seg)
{
	int tempo_atual;
	int tempsemacel;
	int tempo;
	int pos;
	int comp;
	int vel;
	float enat;
	float enlost;
	int lugarp;
	comp = autodromos_campeonato[numero_corrida]->getComp();
	for (int i = 1; i <= seg; i++)
	{
		for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
		{
			tempo_atual = (*it)->getTempo();
			pos = (*it)->getPosicao();
			if (pos < comp)
			{
				tempo = tempo_atual + 1;
				(*it)->setTempo(tempo);
				if ((*it)->getPiloto()->getPersonalidade() != "Crazy Driver" || ((*it)->getPiloto()->getPersonalidade()=="Crazy Driver" && (*it)->getInicorrida()<=tempo_atual))
				{
					pos = (((*it)->getVelocidade()) * ((*it)->getTempo()));
					(*it)->setPosicao(pos);
					enat = (*it)->getCarro()->getEnergia_atual();

					if ((*it)->getPiloto()->getPersonalidade() == "Piloto Rapido")
					{
						if (enat < (((*it)->getCarro()->getEnergia_max()) / 2.0))
						{
							if ((*it)->getAcelerador() == false && (*it)->getSegsemacel() == 3)
							{
								(*it)->setAcelerador(true);
								(*it)->setSegsemacel(0);
							}
							else
							{
								if ((*it)->getAcelerador() == true)
								{
									(*it)->setAcelerador(false);
									tempsemacel = (*it)->getSegsemacel();
									tempsemacel++;
									(*it)->setSegsemacel(tempsemacel);
								}
								else
								{
									tempsemacel = (*it)->getSegsemacel();
									tempsemacel++;
									(*it)->setSegsemacel(tempsemacel);
								}
							}
							if (rand() % 100 == 10)
							{
								(*it)->setSinal(true);
							}
						}
						else
						{
							(*it)->setAcelerador(true);
						}
					}
					if (enat > 0)
					{
						enlost = enat - 0.1;
						(*it)->getCarro()->setEnergia_atual(enlost);
					}
					else
					{
						(*it)->setSinal(true);
						if ((*it)->getVelocidade() > 0)
						{
							vel = (*it)->getVelocidade();
							(*it)->setVelocidade(vel - 1);
						}
						else
						{
							autodromos_campeonato[numero_corrida]->addParGaragem((*it));
						}
					}
				}
			}
		}
		setClassificacaoCorrida();
		for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
		{
			if ((*it)->getPiloto()->getPersonalidade() == "Crazy Driver") // ve a posicao anterior  nao sei se esta bem
			{
				lugarp = (*it)->getLugarPista();
				Lugar((*it));
				if (rand() % 100 == 5)
				{
					(*it)->getCarro()->setAvariado(true);
				}
			}
		}
		for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
		{
			if ((*it)->getAcelerador() == true)
				(*it)->aumentaVelocidade();
			if ((*it)->getTravao() == true)
				(*it)->diminuiVelocidade();
			if ((*it)->getSinal() == true)
				(*it)->setTravao(true); //Isto depois tem d ter mais verificacoes se calhar mas para ja fica assim okapa
			if ((*it)->getCarro()->getAvariado() == true)
				(*it)->getCarro()->setEnergia_atual(0);
		}
	}
}

ostream& operator << (ostream& out, Campeonato& a)
{
	out << a.getAsString();
	return out;
}
