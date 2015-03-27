#ifndef datatype_H
#define datatype_H
#include<random>
class parameter
{
public:
	double vol ;
	double beta0;
	double beta1;
	double beta2;
	double lambda;
	double fx0;
	double floatrate(double t) {
		if (t == 0.0) return beta0;
		double tl = t / lambda;
		double r = beta0 + (beta1 + beta2) * ((1-exp(-tl)) / tl)
			+ beta2 * exp(-tl);
		return r;
	}
	double fx(double t);
};


double parameter::fx(double t)
{
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<double> dis(0, sqrt(vol*t));
	return fx0 + dis(gen);
}

#endif