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
				//g = guess.at(j);
				c = choose.at(j);
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
