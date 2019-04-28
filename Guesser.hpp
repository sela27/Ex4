#pragma once
#include<iostream>

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
			Guesser()
			{
			}
			virtual ~Guesser()
			{
			}
			virtual string guess() = 0;
			 void startNewGame(int l)
			{
				length = l;
			}
			void learn(string reply)
			{
			}
	};

}
