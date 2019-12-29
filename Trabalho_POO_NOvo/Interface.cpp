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
	en_max.empty();
	en_at.empty();
	string marca;
	marca.empty();
	string modelo;
	modelo.empty();
	string name_pil;
	name_pil.empty();
	string genero_pil;
	genero_pil.empty();
	string name_aut, maximoC, comprim;
	name_aut.empty();
	maximoC.empty();
	comprim.empty();
	string letr_car;
	letr_car.empty();
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
						k++;
						en_max = vet_var_comando[k];
						k++;
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
							dgva.addCarro(stoi(en_at), stoi(en_max), marca, modelo);
						}
						else
						{
							dgva.addCarro(stoi(en_at), stoi(en_max), marca);
						}
					}
					else
					{
						if (tipo == "p")
						{
							genero_pil = vet_var_comando[k];
							k++;
							name_pil = vet_var_comando[k];
							k++;
							for (unsigned int i = k; i < vet_var_comando.size(); i++, k++)
							{
								name_pil = name_pil + espaco;
								name_pil = name_pil + vet_var_comando[i];
							}
							dgva.addPiloto(name_pil);
						}
						else
						{
							if (tipo == "a")
							{

								maximoC = vet_var_comando[k];
								k++;
								comprim = vet_var_comando[k];
								k++;
								name_aut = vet_var_comando[k];
								k++;
								for (unsigned int i = k; i < vet_var_comando.size(); i++, k++)
								{
									name_aut = name_aut + espaco;
									name_aut = name_aut + vet_var_comando[i];
								}
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
	return true;
}

bool Interface::menu_campeonato()
{
	vector <string> vet_var_comando;
	string com_completo;
	string com;
	com.clear();
	cout << "CAMPEONATO" << endl;
	cout << "COMANDOS" << endl;
	cout << endl;
	cout << "listacarros" << endl;
	cout << "carregabat <letraCarro> <Q>" << endl;
	cout << "carregatudo" << endl;
	cout << "corrida" << endl;
	cout << "acidente <letraCarro>" << endl;
	cout << "stop <letraCarro>" << endl;
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
	segundos.empty();
	if (com == "listacarros")
	{
		cout << campea << endl;
	}
	else
	{
		if (com == "carregabat")
		{

		}
		else
		{
			if (com == "carregatudo")
			{

			}
			else
			{
				if (com == "corrida")
				{

				}
				else
				{
					if (com == "acidente")
					{

					}
					else
					{
						if (com == "stop")
						{

						}
						else
						{
							if (com == "destroi")
							{

							}
							else
							{
								if (com == "passatempo")
								{
									segundos = vet_var_comando[k];
									k++;
									campea.passatempo(stoi(segundos));
								}
								else
								{
									if (com == "log")
									{

									}
									else
									{
										cout << "Comando Invalido!!!" << endl;
										return false;
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
	for (npares = 1; (npares <= max) && (pos<dgva.getTamVetorPilotos()); npares++) 
	{
		pilot = dgva.getPilotoSegundoPosicaoNoVetor(pos);
		if (pilot->getCarroPar() != nullptr) 
		{
			campea.addParCampeonato(pilot);
		}
		pos++;
	}
}



