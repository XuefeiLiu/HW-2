#ifndef datageneration_hpp
#define datageneration_hpp

#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include"counterparty.h"
using namespace std;

void dataGenerate(int couterpartyNumber,int deal) 
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 1);
	for (int i = 1; i <= couterpartyNumber; i++)
	{
		ostringstream outfilename;
		outfilename << "bigdata_";
		outfilename << i;
		outfilename << ".txt";
		std::ofstream outfile(outfilename.str());
		int selector;
		string rating;

		std::uniform_int_distribution<> dis2(0, 30);
		selector = dis2(gen); // Returns a uniformly distributed random integer from 0 to 30.

		switch (selector)
		{
			// "A" rated counterparties. "Bucket A"
		case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
			rating = 'A'; // "rating" is of type char (1 byte)
			break;
			// "B" rated counterparties. "Bucket B"
		case 16: case 17: case 18: case 19: case 20: case 21: case 22: case 23:
			rating = 'B';
			break;
			// "C" rated counterparties. "Bucket C"
		case 24: case 25: case 26: case 27:
			rating = 'C';
			break;
			// "D" rated counterparties. "Bucket D"
		case 28: case 29:
			rating = 'D';
			break;
			// "E" rated counterparties. "Bucket E"
		case 30:
			rating = 'E';
			break;
		default:
			rating = 'X'; // Error.
			break;
		}

		outfile << rating << endl<<endl;
		outfile.close();
	}
	std::uniform_int_distribution<> dis3(1, couterpartyNumber);
		for (int j = 0; j<deal; j++)
		{
			int number = dis3(gen);
			std::string s = std::to_string(number);
			string file = "bigdata_" + s+".txt";
			ofstream myfile(file,std::ofstream::out | std::ofstream::app);
			if (myfile.is_open())
			{
				Swap tempSwapDeal = swapGenerator();
				myfile << "SwapDeal," << tempSwapDeal.Notional << "," << tempSwapDeal.T << "," << tempSwapDeal.Currency << "," << tempSwapDeal.longorshort << "," << tempSwapDeal.fixrate << endl;

				fx tempFXDeal = fxGenerator();
				myfile << "FXDeal," << tempFXDeal.notional << "," << tempFXDeal.longorshort << endl;

				myfile.close();
			}
			else cout << "Unable to open file";
		}
		
	}


#endif
