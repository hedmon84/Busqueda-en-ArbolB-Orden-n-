#include "ArbolB.h"



ArbolB::ArbolB(int tam)
{

	min_node = tam;
	raiz = NULL;
}


void ArbolB::llenar(int x) {

	ifstream FileData("data.dat", std::ifstream::in | std::ifstream::binary);
	if (!FileData) {
		cout << " Error al intentar abrir archivo data.dat";
	}

	trans_data t;

	FileData.seekg(0, std::ifstream::beg);
	FileData.read(reinterpret_cast<char*>(&t), sizeof(trans_data));

	FechaData trans;
	trans.month = t.month;
	trans.year = t.year;

	cout << "Fecha:";
	cout << trans.month << "/";
	cout << trans.year << "   ";
	cout << t.code << "" << std::endl;

	this->insert(0, trans);
	time(&start);
	for (int i = 0; i < x - 1; i++)
	{
		FileData.read(reinterpret_cast<char*>(&t), sizeof(trans_data));


		trans.month = t.month;
		trans.year = t.year;

		cout << "Fecha:";
		cout << trans.month << "/ ";
		cout << trans.year << " Codigo ->  ";
		cout << t.code << "" << std::endl;
		this->insert(i + 1, trans);
	}
	time(&end);
	time_taken = double(end - start);
	cout << "Time taken by program is : " << fixed
		<< time_taken;
	cout << " sec " << endl;
	FileData.close();

}

void ArbolB::recorrer() {
	ifstream FileData("data.dat", std::ifstream::in | std::ifstream::binary);
	if (!FileData) {
		cout << " Error al intentar abrir archivo data.dat";
	}
	time(&start);
	if (raiz != NULL)
		raiz->recorrer();
	time(&end);
	time_taken = double(end - start);
	cout << "Time taken by program is : " << fixed
		<< time_taken;
	cout << " sec " << endl;
	FileData.close();

}

Node * ArbolB::buscar(FechaData x)
{

	if (raiz == NULL) {
		return NULL;
	}else
	return raiz->search(x);
}

bool ArbolB::buscar(FechaData y, int code)
{
	FechaData x;
	x.month = y.month;
	x.year = y.year;

	Node* t = buscar(x);
	if (t == NULL)
		return false;
	int i = 0;
	for (i = 0; i < t->Ubicacion_Key; i++)
	{
		if ((t->llaves[i].year == x.year) &&
			(t->llaves[i].month == x.month)) {

			std::ifstream file("data.dat", std::ifstream::in | std::ifstream::binary);
			trans_data trans;

			for (unsigned int z = 0; z < t->llaves[i].ld.size(); z++)
			{
				file.seekg(sizeof(trans_data)*t->llaves[i].ld.at(z));
				file.read(reinterpret_cast<char*>(&trans), sizeof(trans_data));

				if (trans.code == code) {
					file.close();
					return true;
				}
			}

			file.close();

		}

	}

	return false;
}

void ArbolB::insert(int pos, FechaData y)
{
	y.ld.push_back(pos);

	Node* v = this->buscar(y);
	if (v != NULL) {
		int z = 0;
		for (z = 0; z < v->Ubicacion_Key; z++)
		{
			if ((v->llaves[z].year == y.year) &&
				(v->llaves[z].month == y.month))
				break;
		}
		v->llaves[z].ld.push_back(pos);
		return;

	}

	if (raiz == NULL) {
		raiz = new Node(min_node, true);
		raiz->llaves[0] = y;
		raiz->Ubicacion_Key = 1;
	}
	else {
		if (raiz->Ubicacion_Key == (2 * min_node - 1)) {
			Node* s = new Node(min_node, false);
			s->pagina[0] = raiz;
			s->split(0, raiz);

			int i = 0;
			if (raiz->ficherosC(s->llaves[0], y))
				i++;

			s->pagina[i]->insert(y);

			raiz = s;
		}
		else
			raiz->insert(y);
	}
}

bool ArbolB::Sequencial_Search(FechaData y, int code)
{
	ifstream FileData("data.dat", std::ifstream::in | std::ifstream::binary);
	if (!FileData) {
		cout << " Error al intentar abrir archivo data.dat";
	}

	trans_data t;

	FileData.seekg(0, std::ifstream::beg);
	FileData.read(reinterpret_cast<char*>(&t), sizeof(trans_data));

	FechaData trans;
	trans.month = t.month;
	trans.year = t.year;

	while (!FileData.eof()) {
		if (y.month == t.month && y.year == t.year && code == t.code) {
			FileData.close();
			return true;
		}

		FileData.read(reinterpret_cast<char*>(&t), sizeof(trans_data));

	}

	FileData.close();
	return false;

	
}

void ArbolB::PrintMes(FechaData x)
{
	Node * pos = this->buscar(x);
	if (pos == NULL)
		return;

	int i = 0;
	for (i = 0; i < pos->Ubicacion_Key; i++) {

		if ((pos->llaves[i].year == x.year) &&(pos->llaves[i].month == x.month)) {
			ifstream FileData("data.dat", std::ifstream::in | std::ifstream::binary);
			
			trans_data data;
			cout << endl;
			cout << "Fecha a Imprimir: " << x.month << "/" << x.year << endl;

			for (unsigned int z = 0; z < pos->llaves[i].ld.size(); z++)
			{
				FileData.seekg(sizeof(trans_data)*pos->llaves[i].ld.at(z));
				FileData.read(reinterpret_cast<char*>(&data), sizeof(trans_data));
				cout << endl;

				cout << "*Dia: " << data.day << endl;
				cout << "*Mes: " << data.month << endl;
				cout << "*year: " << data.year << endl;
				cout << "*Codigo: " << data.code << endl;


			}


		}


	}
}


