#include <iostream>
#include <string>
#include <vector>
#include "DGV.h"
#include "Autodromos.h"
#include "Interface.h"

using namespace std;

//vector<string> getTokens(string stri);
//novo

int main()
{
	Interface intera; ??

	/*int op = 0, en_at, en_max, resp, maxCar, comp;
	string mar, mod, nome;
	char letr_carro;
	string nom_piloto, str_letr_carro, nom_autodromo;
	DGV dgva;
	Autodromos autoa;
	do
	{
		cout << "MENU" << endl;
		cout << "1 - Inserir Piloto" << endl;
		cout << "2 - Inserir Carro" << endl;
		cout << "3 - Insira Autodromo" << endl;
		cout << "4 - Listar" << endl;
		cout << "5 - Ler Autodromos de ficheiro" << endl;
		cout << "6 - Ler Carros de ficheiro" << endl;
		cout << "7 - Ler Pilotos de ficheiro" << endl;
		cout << "8 - Fazer piloto entrar num carro" << endl;
		cout << "9 - Fazer piloto sair de um carro" << endl;
		cout << "10 - Elimina carro" << endl;
		cout << "11 - Elimina piloto" << endl;;
		cout << "12 - Elimina autodromo" << endl;
		cout << "Insira a opcao pretendida: " << endl;
		cin >> op;
		cin.ignore();
		switch (op)
		{
		case 1:
			cout << "Insira o nome do piloto" << endl;
			getline(cin, nome);
			dgva.addPiloto(nome);
			break;
		case 2:
			cout << "Insira a energia atual do carro: " << endl;
			cin >> en_at;
			cin.ignore();
			cout << "Insira a energia maxima do carro: " << endl;
			cin >> en_max;
			cin.ignore();
			cout << "Insira a marca do carro: " << endl;
			getline(cin, mar);
			cout << "Inserir Modelo? (1=Sim 2=Nao): " << endl;
			cin >> resp;
			cin.ignore();
			do
			{
				switch (resp)
				{
				case 1:
					cout << "Insira o modelo: " << endl;
					getline(cin, mod);
					dgva.addCarro(en_at, en_max, mar, mod);
					break;
				case 2:
					dgva.addCarro(en_at, en_max, mar);
					break;
				default:
					cout << "OPÇÂO INVÁLIDA" << endl;
				}
			} while (resp != 1 && resp != 2);
			break;
		case 3:
			cout << "Insira o Nome do Autodromo: " << endl;
			getline(cin, nome);
			cout << "Insira o Maximo dos carros: " << endl;
			cin >> maxCar;
			cin.ignore();
			cout << "Insira o Comprimento do Autodromo: " << endl;
			cin >> comp;
			cin.ignore();
			autoa.addAutodromo(maxCar, comp, nome);
			break;
		case 4:
			cout << dgva << endl;
			cout << autoa << endl;
			break;
		case 5:
			bool verifica_au;
			verifica_au = autoa.leFicheiroAutodromos("Autodromos.txt");
			if (verifica_au == false)
			{
				cout << "O Ficheiro nao pode ser aberto!" << endl;
			}
			break;
		case 6:
			bool verifica_car;
			verifica_car = dgva.leFicheiroCarros("Carros.txt");
			if (verifica_car == false)
			{
				cout << "O Ficheiro nao pode ser aberto!" << endl;
			}
			break;
		case 7:
			bool verifica_pil;
			verifica_pil = dgva.leFicheiroPilotos("Pilotos.txt");
			if (verifica_pil == false)
			{
				cout << "O Ficheiro nao pode ser aberto!" << endl;
			}
			break;
		case 8:
			cout << "Insira o id do carro: " << endl;
			getline(cin, str_letr_carro);
			cout << "Insira o nome do piloto: " << endl;
			getline(cin, nom_piloto);
			letr_carro = str_letr_carro[0];
			dgva.entraNoCarro(letr_carro, nom_piloto);
			break;
		case 9:
			cout << "Insira o id do carro" << endl;
			getline(cin, str_letr_carro);
			letr_carro = str_letr_carro[0];
			dgva.saiDoCarro(letr_carro);
			break;
		case 10:
			cout << "Insira o id do carro: " << endl;
			getline(cin, str_letr_carro);
			letr_carro = str_letr_carro[0];
			dgva.apagaCarro(letr_carro);
			break;
		case 11:
			cout << "Insira o nome do piloto: " << endl;
			getline(cin, nom_piloto);
			dgva.apagaPiloto(nom_piloto);
			break;
		case 12:

			cout << "Insira o nome do autodromo: " << endl;
			getline(cin, nom_autodromo);
			autoa.apagaAutodromo(nom_autodromo);
			break;
		default:
			cout << "OPCAO INVALIDA" << endl;
		}
	} while (op != 13);*/
	return 0;
}