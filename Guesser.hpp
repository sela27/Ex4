#pragma once
#include<iostream>
#include <string>
#include "calculate.hpp"

using namespace std;

namespace bullpgia 
{
	class Guesser 
	{
		protected:
			int length;
			int lastbull;
			int lastpgia;
		public:
			virtual string guess() = 0;
			virtual void startNewGame(int l)
			{
				length = l;
			}
			virtual void learn(string reply)
			{
				string s1 = reply.substr(0, reply.find(","));
				string s2 = reply.substr(reply.find(",") + 1);
				lastbull = stoi(s1);
				lastpgia = stoi(s2);
			}
	};

}
