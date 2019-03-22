#pragma once

#include "Node.h"
#include <time.h>
class ArbolB
{
	time_t start, end;
	double time_taken;
	Node *raiz;
	int min_node;
public:

	ArbolB(int tam);
	
	void llenar(int x);
	void recorrer();
	Node* buscar(FechaData x);
	bool buscar(FechaData y, int codigo);
	void insert(int pos, FechaData y);
	bool Sequencial_Search(FechaData y, int codigo);
	void PrintMes(FechaData x);
};

