#pragma once
#include "Guesser.hpp"
using namespace std;

class SmartGuesser : public bullpgia::Guesser {
public:
	string guess() override;
private:
	string s="0000";
	int Memory_Pgia;
	int index = 0;


};
