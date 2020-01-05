#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Autodromos.h"
#include "DGV.h"
#include "Campeonato.h"
#include "Consola.h"
class Interface
{

	DGV dgva;
	Autodromos autoa;
	Campeonato campea;
	vector<DGV> copias_dgv;

public:
	Interface() {}


	//menu inicial
	bool menu_inicial();

	//menu campeonato
	bool menu_campeonato();

	//menu corrida
	bool menu_corrida(); //Continua no proximo episodio

	//tokens
	vector<string> getTokens(string stri);

	//launch
	void lancaMenuInicial();
	void lancaMenuCampeonato();

	//choose
	void addAutodromoCampeonato(string name_aut);
	void addParesCampeonato();

	//copy
	void criaCopiaDGV(const DGV& copy);

	virtual ~Interface() {}
};
