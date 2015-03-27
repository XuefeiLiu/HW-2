#include"datatype.h"
#include<iostream>
#include<fstream>
#include"path.h"
#include"State.h"
using namespace std;
int main()
{
	parameter p;
	p.beta0 = 0.01;
	p.beta1 = 0.01;
	p.beta2 = 0.01;
	p.lambda = 5;
	p.vol = 0.2;
	std::cout << p.floatrate(1)<<std::endl;
	std::cout << p.fx(1)<<endl;

	
}