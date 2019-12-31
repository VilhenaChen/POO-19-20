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
					(*it)->setLugarPista(lugar);
					cont++;

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
		(*it)->setVelocidae(1);
		(*it)->setTerminouCorrida(false);
	}
}

void Campeonato::lancaCorrida()
{
	setCorridaDecorrer(true);
	cout << "Corrida no Autodromo: " << autodromos_campeonato[numero_corrida]->getNome() << " (" << autodromos_campeonato[numero_corrida]->getComp() << ")" << endl;
	cout << "Pares participantes: " << endl;
	for (auto it = pares_campeonato.begin(); it < pares_campeonato.end(); it++)
	{
		cout << "Nome: " <<(*it)->getPiloto()->getNome()<<" ID Carro: "<<(*it)->getCarro()->getId_carro()<< " Tempo: " << (*it)->getTempo()<<endl;
	}
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
		}
		else
		{
			cout << "[ERRO] O Carro nao esta a participar neste Campeoonato" << endl;
		}
	}

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
				cout << i << ". " << (*it)->getCarro()->getId_carro() << " " << (*it)->getCarro()->getMarca()  << " / " << (*it)->getPiloto()->getNome() << " ( " << (*it)->getPiloto()->getPersonalidade() << ") - " << (*it)->getCarro()->getEnergia_atual() << "mAh, " << (*it)->getCarro()->getEnergia_max() << "mAh - " << (*it)->getPosicao() << "m - " << (*it)->getVelocidade() << "m/s" << endl;
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

void Campeonato::passatempo(int seg)
{
	int tempo_atual;
	int tempo;
	int pos;
	int comp;
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
				pos =(((*it)->getVelocidade())*((*it)->getTempo()));
				(*it)->setPosicao(pos);
			}
		}
	}
}

ostream& operator << (ostream& out, Campeonato& a)
{
	out << a.getAsString();
	return out;
}
