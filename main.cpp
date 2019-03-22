
#include <iostream>
#include"ArbolB.h"

int main() {

	time_t start, end;
	double time_taken;
	int opc = 0;
	int dat = 0;
	ArbolB trans(128);
	cout << "Ingrese cantidad de Registros que desea mandar al arbol B = ";
	cin >> dat;
	trans.llenar(dat);
	cout << "***llenado total del Arbol B***\n\n";
	
	
	FechaData t;
	t.month = 5;
	t.year = 2004;

	do {
	
		cout << "-----Arbol B -----" << endl;
		cout << "--Este arbol es de orden   " << 128 << "--" << endl;
		cout << "Ingrese Opcion :  \n" << "1 Recorrer el Arbol b \n" << "2 Buscar \n" << "3 Sequencial Search \n" << "4 imprimir mes \n";
		cin >> opc;
		switch (opc)
		{
		case 1:
			trans.recorrer();
			break;
		case 2:
			cout << "Ingrese Mes\n: ";
			cin >> dat;
			t.month = dat;
			cout << "Ingrese year\n";
			cin >> dat;
			t.year = dat;
			cout << "Ingrese codigo\n";
			cin >> dat;
			time(&start);
			if (trans.buscar(t,dat))
				cout << "Encontrado\n";
			else cout << "No se encuentra\n";
			time(&end);
			cout << "Verdadero" << endl;
			time(&end);
			time_taken = double(end - start);
			cout << "Time taken by program is : " << fixed
				<< time_taken;
			cout << " sec " << endl;
			break;
		case 3:
			cout << "Ingrese Mes\n: ";
			cin >> dat;
			t.month = dat;
			cout << "Ingrese year\n";
			cin >> dat;
			t.year = dat;
			cout << "Ingrese codigo\n";
			cin >> dat;
			if (trans.Sequencial_Search(t, dat))
				cout << "Encontrado\n";
			else cout << "No se encuentra\n";
			break;
		case 4:
			cout << "Ingrese Mes\n: ";
			cin >> dat;
			t.month = dat;
			cout << "Ingrese year\n";
			cin >> dat;
			t.year = dat;
			trans.PrintMes(t);
			break;

		case -1:

			break;

	
		}



	} while (opc != -1);
	

	
	system("pause");

	


	






}