
#ifndef counterparty_hpp
#define counterparty_hpp
#include <vector>
#include<random>
#include "swap.h"
#include "fx.h"

class counterParty
{
public:
	double hazardRate;
	char level;


public:
	counterParty(int level_) : level(level_)    {
		if (level == 'A')
			hazardRate = 0.02;
		else if (level == 'B')
			hazardRate = 0.04;
		else if (level == 'C')
			hazardRate = 0.06;
		else if (level == 'D')
			hazardRate = 0.08;
		else if (level == 'E')
			hazardRate = 0.1;
	}
};

#endif
