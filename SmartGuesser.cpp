#include<iostream>
#include "SmartGuesser.hpp"
#include<string>
using namespace std;

string SmartGuesser::guess() {

	if (this->NewGame) {
		int i;
		string Temperory_str;
		this->s = "";
		this->lastbull = -1;
		this->lastpgia = -1;
		this->Memory_bull = -1;
		this->index = 0;
		this->NewGame = false;
		for (i = 0; i < this->length; i++)                    /////what is length ???
		{
			Temperory_str.append("0");
		}
		this->s.append(Temperory_str);
		return s;
	}


	if (((this->Memory_bull == this->lastbull)) || this->Memory_bull == -1 || this->last_drop) {
		s.at(this->index) = s.at(this->index) + 1;
		this->last_drop = false;
		return s;
	}


	else if ((this->Memory_bull + 1 == this->lastbull)) {
		//this->Memory_bull++;
		this->index = this->index + 1;
		s.at(this->index) = s.at(this->index) + 1;

		return s;
	}

	else
	{
		s.at(this->index) = s.at(this->index) - 1;
		this->index = this->index + 1;
		this->last_drop = true;
		return s;
	}

}
