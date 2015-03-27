#ifndef swap_hpp
#define swap_hpp
#include<random>
#include<iostream>
#include<string>
using namespace std;
class Swap
{
public:
	double Notional;
	double T;
	string Currency;
	bool longorshort;
	float fixrate;
	double t = 0;

public:
	Swap(double Notional_, double T_, string Currency_, bool LongorShort_, float rate_) : Notional(Notional_), T(T_), Currency(Currency_), longorshort(LongorShort_), fixrate(rate_) {};
};

Swap swapGenerator()
{
	double Notional;
	double T;
	string Currency;
	bool LongorShort;
	float rate;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 1);
	double percent;
	percent = dis(gen);
	if (percent<0.5) Currency = "USD";
	else Currency = "EUR";

	if (percent<0.55) LongorShort = false;
	else LongorShort = true;
	T = 2.0 + int(percent*48.0);

	Notional = 800000.0 + 400000.0*percent;

	rate = 0.02 + percent*0.06;

	return Swap(Notional, T, Currency, LongorShort, rate);


}

#endif
