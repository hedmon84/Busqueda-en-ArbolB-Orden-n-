#include "Node.h"

Node::Node(int key, bool hojas):grado(key),hoja(hojas),Ubicacion_Key(0) {

	
	llaves = new FechaData[2 * grado - 1];
	pagina = new Node *[2 * grado];


}

Node * Node::search(FechaData n)
{
	int i = 0;

	while (i < Ubicacion_Key&& ficherosC(llaves[i], n))
		i++;

	if ((llaves[i].year == n.year) && (llaves[i].month == n.month))
		return this;

	if (hoja == true)
		return NULL;

	return pagina[i]->search(n);
}

void Node::recorrer()
{
	
	for (int i = 0; i < Ubicacion_Key; i++) {
		if (hoja == false)
			pagina[i]->recorrer();

		cout << "Fecha: ";
		cout << llaves[i].month << "/";
		cout << llaves[i].year << endl;

	}

	int i = 0;
	if (hoja == false)
		pagina[ i]->recorrer();
	


}

bool Node::ficherosC(FechaData dato1, FechaData dato2)
{
	if (dato1.year < dato2.year)
		return true;
	if (dato1.year == dato2.year && dato1.month < dato2.month)
		return true;

	return false;
}

void Node::split(int i, Node * y)
{

	Node *n = new Node(y->grado, y->hoja);
	n->Ubicacion_Key = grado - 1;

	for (int j = 0; j < grado - 1; j++)
	{
		n->llaves[j] = y->llaves[j + grado];
	}

	if (y->hoja == false) {
		for (int j = 0; j < grado; j++)
		{
			n->pagina[j] = y->pagina[j + grado];
		}
	}

	y->Ubicacion_Key = grado - 1;

	for (int j = Ubicacion_Key; j >= i + 1; j--)
	{
		pagina[j + 1] = pagina[j];
	}

	pagina[i + 1] = n;

	for (int j = Ubicacion_Key - 1; j >= i; j--)
	{
		llaves[j + 1] = llaves[j];
	}

	llaves[i] = y->llaves[grado - 1];
	Ubicacion_Key = Ubicacion_Key + 1;
}

void Node::insert(FechaData x)
{


	int i = Ubicacion_Key - 1;
	if (hoja) {
		while (i >= 0 && this->ficherosC(x, llaves[i])) {
			llaves[i + 1] = llaves[i];
			i--;
		}
		llaves[i + 1] = x;
		Ubicacion_Key = Ubicacion_Key + 1;
	}
	else {

		while (i >= 0 && this->ficherosC(x, llaves[i]))
			i--;

		if (pagina[i + 1]->Ubicacion_Key == (2 * grado - 1)) {
			split(i + 1, pagina[i + 1]);

			if (this->ficherosC(llaves[i + 1], x))
				i++;
		}
		pagina[i + 1]->insert(x);
	}
}
