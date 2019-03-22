#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct trans_data {
	int code;
	char name[25];
	char invoice_code[12];
	char date[12];
	short int day;
	short int month;
	short int year;
	char payment_type[12];
	double total;
	char business_type[20];
	char business_name[60];
};

class FechaData
{
public:

	short int month;
	short int year;
	vector<int> ld;


};

