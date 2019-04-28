#pragma once
#include "Guesser.hpp"
using namespace std;

class SmartGuesser: public bullpgia::Guesser {
	string guess() override;
};