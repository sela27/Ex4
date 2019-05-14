#pragma once
#include "Guesser.hpp"
using namespace std;

class SmartGuesser : public bullpgia::Guesser {
public:

	string s = "";
	int Memory_bull = -1;
	int index = 0;
	bool last_drop = false;
	void learn(string reply) override

	{

		Memory_bull = this->lastbull;
		Guesser::learn(reply);                           //// go and tell me how much bulls and pgia

	}

	string guess() override;

};
