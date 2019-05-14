#include<iostream>
#include "calculate.hpp"
#include<string>
using namespace std;
using namespace bullpgia;



namespace bullpgia {

	string calculateBullAndPgia(string choose, string guess) {



		int i;
		int j;
		int pgia = 0;
		int bull = 0;
		int num = choose.length();
		int* arr_ZeroF_oneT = new int[num];   ////heap of 0/1


		for (i = 0; i < num; i++) {           ////start all zero
			arr_ZeroF_oneT[i] = 0;
		}


		for (i = 0; i < choose.length(); i++) {
			char c = choose.at(i);
			char g = guess.at(i);
			if (c == g) {                     ////if we have bull bull++ -and be 1
				bull++;
				arr_ZeroF_oneT[i] = 1;
				continue;

			}

			for (j = 0; j < guess.length(); j++) {
				g = guess.at(j);
				if (c == g && arr_ZeroF_oneT[j] == 0) {          ////if we not have bull or pgia so pgia++ and be 1
					pgia++;
					arr_ZeroF_oneT[j] = 1;
					break;

				}


			}

		}

		delete[] arr_ZeroF_oneT;
		string cal = to_string(bull) + "," + to_string(pgia);              ////delete heap
		return cal;

	}

}
