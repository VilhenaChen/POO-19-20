#include "Campeonato.h"
#include "Consola.h"

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

int Campeonato::getTamAutodromos()
{
	int cont = 0;
	for (auto it = autodromos_campeonato.begin(); it < autodromos_campeonato.end(); it++) 
	{
		cont++;
	}
	return cont;
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

int Campeonato::getMaxPontos()
{
	int max = 0;
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++) 
	{
		if ((*it)->getPontos() > max) 
		{
			max = (*it)->getPontos();
		}
	}
	return max;
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
		if ((*it)->getTerminouCorrida() == true && (*it)->getCarro()->getAvariado() == false && (*it)->getSaiucorrida() == false)
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
					if ((*it)->getPiloto()->getPersonalidade() == "crazy" || (*it)->getPiloto()->getPersonalidadeTemporaria() == "crazy")
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
	int lugar;
	int cont = 0;
	int points = 0;
	points= getMaxPontos();
	for (int i = points; i > 0 ; i--)
	{
		lugar = cont + 1;
		for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
		{
			if (i == (*it)->getPontos())
			{
				(*it)->setLugarCampeonato(lugar);
				cont++;
			}
		}
	}
}

void Campeonato::preparaCorrida()
{
	int inicor;
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		(*it)->setPosicao(0);
		(*it)->setLugarPista(0);
		(*it)->setLugarCampeonato(0);
		(*it)->setTempo(0);
		(*it)->setVelocidade(1);
		(*it)->setTerminouCorrida(false);
		(*it)->setSaiucorrida(false);
		(*it)->setSegacel(0);
		if ((*it)->getPiloto()->getPersonalidade() == "crazy" || (*it)->getPiloto()->getPersonalidade() == "surpresa") 
		{
			inicor = (rand() % 5) + 1;
			(*it)->setInicorrida(inicor);
		}
	}
}

void Campeonato::lancaCorrida()
{
	int count=0;
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		if ((*it)->getCarro()->getAvariado() == false)
		{
			count++;
		}
	}
	if (count < 2)
	{
		cout << "[ERRO] A Corrida nao pode comecar, nao exitem pelo menos 2 participantes!!!" << endl;
		//falta verificar isto
	}
	setCorridaDecorrer(true);
	cout << "Corrida no Autodromo: " << autodromos_campeonato[numero_corrida]->getNome() << " (" << autodromos_campeonato[numero_corrida]->getComp() << ")" << endl;
	mostraInformacaoCorrridaOrganizada();
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
				cout << "O carro " << idcarro << " j� esta avariado " << endl;
			}
		}
	}
	cout << "O carro " << idcarro << " nao existe!!!" << endl;
}

void Campeonato::acabaCorrida()
{
	cout << "Classifica��o final da corrida: " << endl;
	mostraInformacaoCorrridaOrganizada();
	atribuiPontos();
	setCorridaDecorrer(false);
	numero_corrida++;
}

void Campeonato::mostraInformacaoCorrridaOrganizada()
{
	Consola::clrscr();
	Consola::setScreenSize(100, 100);
	int y = 4;
	char id;
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		if ((*it)->getSaiucorrida() == false)
		{
			int x = 70;
			id = (*it)->getCarro()->getId_carro();
			Consola::gotoxy(5, y);
			cout << (*it)->getCarro()->getId_carro() << " " << (*it)->getCarro()->getMarca() << " / " << (*it)->getPiloto()->getNome() << " ( " << (*it)->getPiloto()->getPersonalidade() << ") - " << (*it)->getCarro()->getEnergia_atual() << "mAh, " << (*it)->getCarro()->getEnergia_max() << "mAh - " << (*it)->getPosicao() << "m - " << (*it)->getVelocidade() << "m/s" << endl;
			x = x +(((*it)->getPosicao() * 20) / autodromos_campeonato[numero_corrida]->getComp());
			Consola::gotoxy(x, y);
			cout << id;
			y++;
			Consola::gotoxy(70, y);
			cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
			y = y + 3;
		}

	}
	Consola::gotoxy(0, y + 1);
}

void Campeonato::mostraClassificacaoCampeonatoOrganizada()
{
	cout << "Vencedores Campeonato"<< endl;
	for (int i = 1; i <= 2; i++)
	{
		if (i == 1)
		{
			cout << "Campeao/Campeoes:" << endl;
		}
		else
		{
			cout << "Vice-Campeao/Vice-Campeoes:" << endl;
		}
		for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
		{
			if (i == (*it)->getLugarCampeonato())
			{
				cout << (*it)->getCarro()->getId_carro() << " " << (*it)->getCarro()->getMarca() << " / " << (*it)->getPiloto()->getNome() << " ( " << (*it)->getPiloto()->getPersonalidade() << ") - " << (*it)->getPontos() << " pontos " << endl;
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

bool Campeonato::verificaSeCampeonatoAcabou()
{
	if (numero_corrida == getTamAutodromos()) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Campeonato::verificaCarrosDestruidos()
{
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		if ((*it)->getCarro()->getDestruido() == true)
		{
			pares_campeonato.erase((it));
		}
	}
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
			pares_campeonato.erase(it);
			return;
		}
	}
	cout << "O carro " << idcarro << " n�o esta neste campeonato " << endl;
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
			if((*it)->getPiloto()->getPersonalidade() == "surpresa")
			{
				if (rand() % 100 < 50)
				{
					(*it)->getPiloto()->setPersonalidadeTemporaria("crazy");
				}
				else
				{
					(*it)->getPiloto()->setPersonalidadeTemporaria("rapido");
				}
			}
			tempo_atual = (*it)->getTempo();
			pos = (*it)->getPosicao();
			if (pos < comp)
			{
				tempo = tempo_atual + 1;
				(*it)->setTempo(tempo);
				if (((*it)->getPiloto()->getPersonalidade() != "crazy" && (*it)->getPiloto()->getPersonalidadeTemporaria() != "crazy") || (((*it)->getPiloto()->getPersonalidade()=="crazy" || (*it)->getPiloto()->getPersonalidadeTemporaria() == "crazy") && (*it)->getInicorrida()<=tempo)|| (*it)->getPiloto()->getPersonalidadeTemporaria() == "rapido")
				{
					pos = (((*it)->getVelocidade()) * ((*it)->getTempo()));
					(*it)->setPosicao(pos);
					enat = (*it)->getCarro()->getEnergia_atual();

					if ((*it)->getPiloto()->getPersonalidade() == "rapido" || (*it)->getPiloto()->getPersonalidadeTemporaria() == "rapido")
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
							if (rand() % 100 < 10)
							{
								(*it)->setSinal(true);
							}
						}
						else
						{
							(*it)->setAcelerador(true);
						}
					}
					if (enat > 0.0)
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
			if ((*it)->getPiloto()->getPersonalidade() == "crazy" || (*it)->getPiloto()->getPersonalidadeTemporaria() == "crazy")
			{
				lugarp = (*it)->getLugarPista();
				int lugar;
				int last;
				last = getUltimo();
				lugar =(*it)->getLugarPista();
				if (lugar == 1)
				{
					(*it)->setAcelerador(false);
					(*it)->setTravao(false);
				}
				else
				{
					if (lugar == last)
					{
						(*it)->setAcelerador(false);
						(*it)->setAcelerador(true);
					}
					else
					{
						(*it)->setAcelerador(true);
						(*it)->setTravao(false);
					}
				}
				if (rand() % 100 < 5)
				{
					acidente((*it)->getCarro()->getId_carro());
					(*it)->getPiloto()->setmorto(true);
					(*it)->getCarro()->setDestruido(true);
				}
			}
		}
		mostraInformacaoCorrridaOrganizada();
		for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
		{
			if ((*it)->getAcelerador() == true)
				(*it)->aumentaVelocidade();
			if ((*it)->getTravao() == true)
				(*it)->diminuiVelocidade();
			if ((*it)->getSinal() == true)
				(*it)->setTravao(true);
			if ((*it)->getCarro()->getAvariado() == true)
			{
				(*it)->getCarro()->setEnergia_atual(0);
				Consola::gotoxy(0,0);
				cout << "O carro " << (*it)->getCarro()->getId_carro() << " avariou!";
			}
		}
	}
}

ostream& operator << (ostream& out, Campeonato& a)
{
	out << a.getAsString();
	return out;
}
