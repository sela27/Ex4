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
		for (i = 0; i < this->length; i++)                    

		{

			Temperory_str.append("0");       

		}

		this->s.append(Temperory_str);                  ////add string of zero of start
		return s;

	}

	if (((this->Memory_bull == this->lastbull)) || this->Memory_bull == -1 || this->last_drop) {
		s.at(this->index) = s.at(this->index) + 1;
		this->last_drop = false;                                                                       ////in this condition we fix the drop that was or
		return s;                                                                                      ////if the two varible equls or m..equal to -1.increase
	}                                                                                                  ////the number in one

	else if ((this->Memory_bull + 1 == this->lastbull)) {
		//this->Memory_bull++;                                                                         ////else if the last bull bigger in one
		this->index = this->index + 1;                                                                 ////increse the index in one and than increase the number in one
		s.at(this->index) = s.at(this->index) + 1;
		return s;

	}

	else

	{
		s.at(this->index) = s.at(this->index) - 1;                                                     ////else Memory_bull>lastbull than return the
		this->index = this->index + 1;                                                                 ////number  in -1 and go to the next index
		this->last_drop = true;                                                                        ////sign that was drop
		return s;

	}



}
