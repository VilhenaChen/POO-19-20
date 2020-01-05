#pragma once

#include <iostream>
#include <string>
#include "Autodromos.h"
#include "Par_Campeonato.h"

using namespace std;

class Campeonato
{
	int numero_corrida = 0;
	bool corrida_decorrer = false;
	vector<Autodromo*> autodromos_campeonato;
	vector<Par_Campeonato*> pares_campeonato;

public: 

	//add
	void addAutodromoCampeonato(Autodromo* autod);
	void addParCampeonato(Piloto* pil_point);

	//find
	int EncontraAutodromoComMenorMaxCarros();

	//gets
	string getAsString();
	int getNumero_corrida();
	bool getCorridaDecorrer();
	int getTotalvetor();
	int getTamAutodromos();
	char getIDCarro(int posicao);
	Carro* getCarro(char idcarro);
	int getMaxPontos();

	//set
	void setNumero_corrida(int num);
	void setCorridaDecorrer(bool cor);
	void setClassificacaoCorrida();
	void setClassificacaoCampeonato();

	//Prepare
	void preparaCorrida();

	//Launch
	void lancaCorrida();

	//Display

	//Driver Personallity
	//Crazy Driver
	void Lugar(Par_Campeonato* par);
	int getUltimo();

	//Charge
	void carregaAllBat();
	void carregaBat(char idcarro, float energia);

	//Stop
	void paraCarro(string nome);

	//Acident
	void acidente(char idcarro);

	//Finish
	void acabaCorrida();

	//show
	void mostraInformacaoCorrridaOrganizada();
	void mostraClassificacaoCampeonatoOrganizada();

	//verify
	bool verificaSeJaTodosAcabaram();
	bool verificaSeCampeonatoAcabou();

	//Points
	void atribuiPontos();

	//Destroy
	void destroi(char idcarro);



	void passatempo(int seg);

	virtual ~Campeonato()
	{
		for (int i = 0; i < autodromos_campeonato.size(); i++)
			delete autodromos_campeonato[i];
		for (int j = 0; j <pares_campeonato.size(); j++)
			delete pares_campeonato[j];
	}
};

ostream& operator << (ostream& out, Campeonato& a);

