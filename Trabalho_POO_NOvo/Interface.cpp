#include "Interface.h"

bool Interface::menu_inicial()
{
	string com, com_completo;
	vector <string> vet_var_comando;
	com.clear();
	cout << "\nMENU PRINCIPAL" << endl;
	cout << "\nCOMANDOS" << endl;
	cout << endl;
	cout << "carregaP <nomeFicheiro>" << endl;
	cout << "carregaC <nomeFicheiro>" << endl;
	cout << "carregaA <nomeFicheiro>" << endl;
	cout << "cria <letraTipo> <dados do objeto>" << endl;
	cout << "apaga <letraTipo> identificador" << endl;
	cout << "entranocarro <letraCarro> <nomePiloto>" << endl;
	cout << "saidocarro <letraCarro>" << endl;
	cout << "lista" << endl;
	cout << "savedgv <nome>" << endl;
	cout <<"loaddgv <nome>" << endl;
	cout << "deldgv <nome>" << endl;
	cout << "campeonato <A1> <A2> ... <An>" << endl;
	cout << endl;
	cout << "Insira um comando: ";
	getline(cin, com_completo);
	vet_var_comando.clear();
	vet_var_comando = getTokens(com_completo);
	unsigned int k = 0;
	com = vet_var_comando[k];
	k++;
	string tipo;
	string en_max, en_at;
	en_max.clear();
	en_at.clear();
	string marca;
	marca.clear();
	string modelo;
	modelo.clear();
	string name_pil;
	name_pil.clear();
	string genero_pil;
	genero_pil.clear();
	string name_aut, maximoC, comprim;
	name_aut.clear();
	maximoC.clear();
	comprim.clear();
	string letr_car;
	letr_car.clear();
	string name_dgv;
	name_dgv.clear();
	string espaco = " ";
	if (com == "carregaP" && k < vet_var_comando.size())
	{
		dgva.leFicheiroPilotos(vet_var_comando[k]);
		k++;
	}
	else
	{
		if (com == "carregaC" && k < vet_var_comando.size())
		{
			dgva.leFicheiroCarros(vet_var_comando[k]);
			k++;
		}
		else
		{
			if (com == "carregaA" && k < vet_var_comando.size())
			{
				autoa.leFicheiroAutodromos(vet_var_comando[k]);
				k++;
			}
			else
			{
				if (com == "cria" && k < vet_var_comando.size())
				{
					tipo = vet_var_comando[k];
					k++;
					if (tipo == "c")
					{
						en_at = vet_var_comando[k];
						if (stof(en_at) < 0)
						{
							cout << "[ERRO] O Valor para a Energia Atual nao e valido!!!" << endl;
							return true;
						}
						k++;
						en_max = vet_var_comando[k];
						k++;
						if ((stof(en_max) <= 0) || stof(en_max) < stof(en_at))
						{
							cout << "[ERRO] O Valor para a Energia Maximo nao e valido!!!" << endl;
							return true;
						}
						marca = vet_var_comando[k];
						k++;
						if (k < (vet_var_comando.size()))
						{
							modelo = vet_var_comando[k];
							k++;
							for (unsigned int i = k; i < vet_var_comando.size(); i++, k++)
							{
								modelo = modelo + espaco;
								modelo = modelo + vet_var_comando[i];
							}
							dgva.addCarro(stof(en_at), stof(en_max), marca, modelo);
						}
						else
						{
							dgva.addCarro(stof(en_at), stof(en_max), marca);
						}
					}
					else
					{
						if (tipo == "p")
						{
							genero_pil = vet_var_comando[k];
							k++;
							if (genero_pil != "crazy" && genero_pil != "rapido" && genero_pil != "surpresa")
							{
								cout << "[ERRO] O genero tem de ser um dos seguintes: crazy, rapido, surpresa!!!" << endl;
								return true;
							}
							name_pil = vet_var_comando[k];
							k++;
							for (unsigned int i = k; i < vet_var_comando.size(); i++, k++)
							{
								name_pil = name_pil + espaco;
								name_pil = name_pil + vet_var_comando[i];
							}
							dgva.addPiloto(name_pil,genero_pil);
						}
						else
						{
							if (tipo == "a")
							{

								maximoC = vet_var_comando[k];
								k++;
								if (stoi(maximoC) <= 0)
								{
									cout << "[ERRO] O Valor para o Maximo de Carros nao e valido!!!" << endl;
									return true;
								}
								comprim = vet_var_comando[k];
								k++;
								if (stoi(comprim) <= 0)
								{
									cout << "[ERRO] O Valor para o Comprimento nao e valido!!!" << endl;
									return true;
								}
								name_aut = vet_var_comando[k];
								k++;
								autoa.addAutodromo(stoi(maximoC), stoi(comprim), name_aut);
							}
						}
					}
				}
				else
				{
					if (com == "apaga" && k < vet_var_comando.size())
					{
						string tipo;
						tipo = vet_var_comando[k];
						k++;
						if (tipo == "c")
						{
							dgva.apagaCarro(vet_var_comando[k][0]);
							k++;
						}
						else
						{
							if (tipo == "p")
							{
								name_pil = vet_var_comando[k];
								k++;
								for (unsigned int i = k; i < vet_var_comando.size(); i++)
								{
									name_pil = name_pil + espaco;
									name_pil = name_pil + vet_var_comando[i];
								}
								dgva.apagaPiloto(name_pil);
								k++;
							}
							else
							{
								if (tipo == "a")
								{
									name_aut = vet_var_comando[k];
									k++;
									for (unsigned int i = k; i < vet_var_comando.size(); i++, k++)
									{
										name_aut = name_aut + espaco;
										name_aut = name_aut + vet_var_comando[i];
									}
									autoa.apagaAutodromo(name_aut);
									k++;
								}

							}
						}
					}
					else
					{
						if (com == "entranocarro" && k < vet_var_comando.size())
						{
							letr_car = vet_var_comando[k];
							k++;
							name_pil = vet_var_comando[k];
							k++;
							for (unsigned int i = k; i < vet_var_comando.size(); i++)
							{
								name_pil = name_pil + espaco;
								name_pil = name_pil + vet_var_comando[i];
							}
							dgva.entraNoCarro(letr_car[0], name_pil);
						}
						else
						{
							if (com == "saidocarro" && k < vet_var_comando.size())
							{
								dgva.saiDoCarro(vet_var_comando[k][0]);
							}
							else
							{
								if (com == "lista")
								{
									cout << dgva << endl;
									cout << autoa << endl;
								}
								else
								{
									if (com == "savedgv")
									{
										name_dgv = vet_var_comando[k];
										k++;
										copias_dgv.push_back(new DGV(dgva,name_dgv));
									}
									else
									{
										if (com == "loaddgv")
										{
											name_dgv = vet_var_comando[k];
											k++;

										}
										else
										{
											if (com == "deldvg")
											{
												name_dgv = vet_var_comando[k];
												k++;
												for (auto it = copias_dgv.begin(); it < copias_dgv.end(); it++)
												{
													if ((*it)->getNome()==name_dgv)
													{
														delete* it;
														copias_dgv.erase(it);
														break;
													}
												}
											}
											else
											{
												if (com == "campeonato")
												{
													for (unsigned int i = k; i < vet_var_comando.size(); i++, k++)
												{
													string autos;
													autos = vet_var_comando[i];
													this->addAutodromoCampeonato(autos);
												}
												return false;
												}
												else
												{
													cout << "Comando Invalido!!!" << endl;
												}
											}
										}
										
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return true;
}

bool Interface::menu_campeonato()
{
	vector <string> vet_var_comando;
	string com_completo;
	string com;
	bool mp;
	com.clear();
	cout << "CAMPEONATO" << endl;
	cout << "COMANDOS" << endl;
	cout << endl;
	cout << "listacarros" << endl;
	cout << "carregabat <letraCarro> <Q>" << endl;
	cout << "carregatudo" << endl;
	cout << "corrida" << endl;
	cout << "acidente <letraCarro>" << endl;
	cout << "stop <nomePiloto>" << endl;
	cout << "destroi <letraCarro>" << endl;
	cout << "passatempo <n>" << endl;
	cout << "log" << endl;
	cout << endl;
	cout << "Insira um comando: ";
	getline(cin, com_completo);
	vet_var_comando.clear();
	vet_var_comando = getTokens(com_completo);
	unsigned int k = 0;
	com = vet_var_comando[k];
	k++;
	string segundos;
	string energia;
	segundos.clear();
	energia.clear();
	string letr_car;
	letr_car.clear();
	string nome_piloto;
	nome_piloto.clear();
	Carro* pcarro;
	if (com == "listacarros")
	{
		cout << campea << endl;
	}
	else
	{
		if (com == "carregabat")
		{
			letr_car = vet_var_comando[k];
			k++;
			energia = vet_var_comando[k];
			k++;
			campea.carregaBat(letr_car[0], stof(energia));;

		}
		else
		{
			if (com == "carregatudo")
			{
				campea.carregaAllBat();
			}
			else
			{
				if (com == "corrida" && campea.getCorridaDecorrer()==false)
				{
					campea.preparaCorrida();
					campea.lancaCorrida();
					do
					{
						mp = menu_corrida();
					} while (mp == false);
					if (campea.verificaSeCampeonatoAcabou() == true) 
					{
						campea.setClassificacaoCampeonato();
						campea.mostraClassificacaoCampeonatoOrganizada();
						lancaMenuInicial();
					}
					dgva.verificaPilotosMortos();
					dgva.verificaCarrosDestruidos();
					campea.verificaCarrosDestruidos();
				}
				else
				{
					if (com == "destroi")
					{
						letr_car = vet_var_comando[k];
						k++;
						campea.destroi(letr_car[0]);
						dgva.apagaCarro(letr_car[0]);
					}
					else
					{
						if (com == "log")
						{
						}
						else
						{
							cout << "Comando Invalido!!!" << endl;
						}
					}
				}
			}
		}
	}
	return true;
}

bool Interface::menu_corrida()
{
	string com_completo;
	string segundos;
	string letr_car;
	Carro* pcarro;
	vector<string> vet_var_comando;
	string com;
	string nome_piloto;
	com_completo.clear();
	segundos.clear();
	letr_car.clear();
	com.clear();
	com.clear();
	nome_piloto.clear();
	campea.mostraInformacaoCorrridaOrganizada();
	cout << "passastempo <n> || acidente <letraCarro> || destroi <letraCarro> || stop <nomePiloto>" << endl;
	cout << "Insira um comando: ";
	getline(cin, com_completo);
	vet_var_comando.clear();
	vet_var_comando = getTokens(com_completo);
	unsigned int k = 0;
	com = vet_var_comando[k];
	k++;
	if (com == "passatempo")
	{
		segundos = vet_var_comando[k];
		campea.passatempo(stoi(segundos));
		if (campea.verificaSeJaTodosAcabaram() == true) 
		{
			campea.acabaCorrida();
			return true;
		}
		return false;
	}
	else
	{
		if (com == "acidente")
		{
			letr_car = vet_var_comando[k];
			k++;
			pcarro = campea.getCarro(letr_car[0]);
			dgva.apagaPiloto(pcarro->getPilotoPar()->getNome());
			campea.acidente(letr_car[0]);
			campea.destroi(letr_car[0]);
			return false;
		}
		else
		{
			if (com == "stop")
			{
				nome_piloto = vet_var_comando[k];
				k++;
				campea.paraCarro(nome_piloto);
				return false;
			}
			else
			{
				if (com == "destroi")
				{
					letr_car = vet_var_comando[k];
					k++;
					campea.destroi(letr_car[0]);
					dgva.apagaCarro(letr_car[0]);
					return false;
				}
				else
				{
					cout << "[ERRO] Comando Invalido!!" << endl;
					return false;
				}
			}
		}
	}
	return true;
}

vector<string> Interface::getTokens(string stri)
{
	istringstream iss(stri);
	vector<string> resultado;
	for (string aux; iss >> aux;)
		resultado.push_back(aux);
	return resultado;
}



void Interface::lancaMenuInicial()
{
	bool mp;
	do
	{
		mp = menu_inicial();
	} while (mp != false);

	addParesCampeonato();
	lancaMenuCampeonato();
}

void Interface::lancaMenuCampeonato()
{
	bool mc;
	do
	{
		mc = menu_campeonato();
	} while (mc != false);
	
	lancaMenuInicial();
}

void Interface::addAutodromoCampeonato(string name_aut)
{
	campea.addAutodromoCampeonato(autoa.encontraAutodromo(name_aut));
}

void Interface::addParesCampeonato()
{
	int max=0,npares,pos=0;
	Piloto* pilot;
	max = campea.EncontraAutodromoComMenorMaxCarros();
	for (npares = 1; (npares <= max) && (pos<dgva.getTamVetorPilotos()); pos++) 
	{
		pilot = dgva.getPilotoSegundoPosicaoNoVetor(pos);
		if (pilot->getCarroPar() != nullptr) 
		{
			campea.addParCampeonato(pilot);
			npares++;
		}
	}
}




