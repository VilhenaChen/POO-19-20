#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Autodromos.h"
#include "DGV.h"
class Interface
{

	DGV dgva;
	Autodromos autoa;
public:
	Interface() {}

	//menu inicial
	bool menu_inicial();

	//menu campeonato
	bool menu_campeonato();

	//tokens
	vector<string> getTokens(string stri);

	//launch
	void lancaMenuInicial();
	void lancaMenuCampeonato();


	virtual ~Interface() {}
};
