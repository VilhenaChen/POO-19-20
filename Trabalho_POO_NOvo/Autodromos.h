#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Autodromo.h"

using namespace std;

class Autodromos
{
	vector<Autodromo*> vetor_autodromos;

public:
	Autodromos() {}

	virtual ~Autodromos() {}
};

