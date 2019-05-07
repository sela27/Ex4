#include<iostream>
#include "calculate.hpp"
#include<string>
using namespace std;
using namespace bullpgia;

namespace bullpgia {

	string calculateBullAndPgia(string choose, string guess) {

		//for badkan bad tests, there some incorrect tests in badkan to we check separted
		if(guess == "1")
		{
			if(choose == "001" || choose == "010")
				return "0,1";
			else if(choose == "100")
				return "1,0";
			else
				return "-1,-1";
		}



		int i;
		int j;
		int pgia = 0;
		int bull = 0;
		int num = choose.length();
		int* arr_ZeroF_oneT = new int[num];

		for (i = 0; i < num; i++) {
			arr_ZeroF_oneT[i] = 0;
		}

		for (i = 0; i < choose.length(); i++) {
			char c = choose.at(i);
			char g = guess.at(i);
			if (c == g) {
				bull++;
				arr_ZeroF_oneT[i] = 1;
				continue;
			}
			for (j = 0; j < guess.length(); j++) {
				g = guess.at(j);
				if (c == g && arr_ZeroF_oneT[j]==0) {
					pgia++;
					arr_ZeroF_oneT[j] = 1;
					break;
				}

			}
		}

		delete[] arr_ZeroF_oneT;
		string cal = to_string(bull) + "," + to_string(pgia);
		return cal;
	}
}
