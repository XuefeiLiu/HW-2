#ifndef STATE_H
#define STATE_H
#include"datatype.h"
#include<string>
#include<random>
#include<iostream>
#include <boost/tuple/tuple.hpp>
using namespace std;
class State :public parameter
{
public:
	double hazard;
	int timesteps;//if we compute monthly the timesteps will be 12 
	double t;//total time horizon
public:
	State();
	boost::tuple <vector<double>, vector<double>> state();


};
State::State()
{
	hazard = 0;
	t = 5;
	timesteps = 12;
}

boost::tuple <vector<double>, vector<double>> State::state()
{
	int N = int(t * timesteps);
	vector<double> r(N);
	vector<double> fxrate(N);
	for (int i = 0; i < N; i++)
	{
		r[i] = floatrate(i*1.0 / timesteps);
		fxrate[i] = fx(i*1.0 / timesteps);
	}
	return boost::make_tuple(fxrate, r);
}


#endif