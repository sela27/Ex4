#pragma once

#include<iostream>
using namespace std;
#include <string>
#include "calculate.hpp"
namespace bullpgia

{
	class Guesser
	{
	protected:

		int length;
		int lastbull;
		int lastpgia;
		bool NewGame;

	public:
		Guesser()
		{
			lastbull = -1;
			lastpgia = -1;
		}
		virtual ~Guesser()

		{

		}
		virtual string guess() = 0;
		void startNewGame(int l)

		{
			length = l;
			NewGame = true;

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
