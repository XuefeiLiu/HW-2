#ifndef path_H
#define path_H
#include"State.h"
#include"datatype.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class Path:public State
{
public:
	double swapprice;
	double fxprice;
public:
	void path(string filename, double T, int steps);//create one path to calculate the price
};

void Path::path(string filename,double T, int steps)
{
	State state1;
	state1.t = T;
	state1.timesteps = steps;
	//we get the state variables of interest rate and fx rate.
	vector<double> r = state1.state().get<1>();
	vector<double> fx = state1.state().get<0>();

	ifstream file(filename);
	file.seekg(0, file.end);
	long file_length = file.tellg();
	string level;
	
	ifstream inputfile;
	inputfile.open(filename);
	getline(inputfile, level);
	if (level == "A")
		state1.hazard = 0.02;
	else if (level == "B")
		state1.hazard = 0.04;
	else if (level == "C")
		state1.hazard = 0.06;
	else if (level == "D")
		state1.hazard = 0.08;
	else if (level == "E")
		state1.hazard = 0.1;

	string temp;
	getline(inputfile, temp);
	
	while (inputfile.tellg() <= file_length)
	{
		string swapdeal;

		getline(inputfile, swapdeal, ',');
		string swap_N;
		string tenor;
		string denominator;
		string swap_longorshort;
		string fixrate;

		getline(inputfile, swap_N, ',');
		getline(inputfile, tenor, ',');
		getline(inputfile, denominator, ',');
		getline(inputfile, swap_longorshort, ',');
		getline(inputfile, fixrate, '\n');


		string fx_N;
		string fx_longorshort;
		string fxdeal;
		getline(inputfile, fxdeal, ',');
		getline(inputfile, fx_N, ',');
		getline(inputfile, fx_longorshort, '\n');


	}




}



#endif