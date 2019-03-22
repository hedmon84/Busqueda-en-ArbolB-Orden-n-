#pragma once
#include "FechaData.h"
#include <list>
#include <vector>
#include <iostream>
#include <fstream>


class Node
{
	
public:
	Node** pagina;
	int grado;
	bool hoja;
	int Ubicacion_Key;

	FechaData *llaves;
	Node *search(FechaData n);
	Node(int key, bool hojas);
	void recorrer();
	bool ficherosC(FechaData, FechaData);
	void split(int i, Node* y);
	void insert(FechaData);


	
};

