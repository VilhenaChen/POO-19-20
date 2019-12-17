#include <iostream>
#include <string>
#include <vector>
#include "DGV.h"

using namespace std;

vector<string> getTokens(string stri);

int main()
{
	string com, com_completo;
	DGV dgva;
	do
	{
		com.clear();
		cout << "COMANDOS" << endl;
		cout << endl;
		cout << "carregaP <nomeFicheiro>" << endl;
		cout << "carregaC <nomeFicheiro>" << endl;
		cout << "carregaA <nomeFicheiro>" << endl;
		cout << "cria <letraTipo> <dados do objeto>" << endl;
		cout << "lista" << endl;
		cout << "Insira um comando: ";
		getline(cin, com_completo);
		vector <string> vet_var_comando;
		vet_var_comando = getTokens(com_completo);
		unsigned int k = 0;
		com = vet_var_comando[k];
		k++;
		if (com == "cria" && k < vet_var_comando.size())
		{
			string tipo;
			tipo = vet_var_comando[k];
			k++;
			if (tipo == "c")
			{
				string marca, modelo, st_en_at, st_en_max;
				st_en_at = vet_var_comando[k];
				k++;
				st_en_max = vet_var_comando[k];
				k++;
				marca = vet_var_comando[k];
				if (k < vet_var_comando.size())
				{
					modelo = vet_var_comando[k];
					dgva.addCarro(stoi(st_en_at), stoi(st_en_max), marca, modelo);
				}
				else
				{
					dgva.addCarro(stoi(st_en_at), stoi(st_en_max), marca);
				}
			}
			else
			{
				if (tipo == "p")
				{
					string tipo_pil, nome_pil;
					nome_pil.clear();
					tipo_pil = vet_var_comando[k];
					k++;
					for (unsigned int i = k; i < vet_var_comando.size(); i++)
					{
						nome_pil = nome_pil + vet_var_comando[i];
					}
					dgva.addPiloto(nome_pil);
				}
			}
		}
		else
		{
			if (com == "lista")
			{
				cout << dgva << endl;
			}
		}
	} while (com != "end");
	return 0;
}

vector<string> getTokens(string stri)
{
	istringstream iss(stri);
	vector<string> resultado;
	for (string aux; iss >> aux;)
		resultado.push_back(aux);
	return resultado;
}
