#ifndef FX_HPP
#define FX_HPP
#include<random>
class fx
{
public:
	double notional;
	bool longorshort;
	double t = 0;
public:
	fx(double notional_, bool longorShort_) : notional(notional_), longorshort(longorShort_){};

};

fx fxGenerator()
{
	bool longorshort;
	double Notional;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(800000.0, 1200000.0 );
	Notional = dis(gen);
	std::uniform_real_distribution<> dis2(0,1);
	double percent;
	percent = dis2(gen);
	if (percent<0.4)
		longorshort = false;
	else
		longorshort = true;



	return fx(Notional, longorshort);

}



#endif
