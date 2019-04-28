#pragma once
#include<iostream>
#include<cstdint>
using namespace std;
#ifndef uint
#define uint unsigned int
#endif
namespace bullpgia 
{

	class Chooser 
	{
		virtual string choose(uint length);
	};

}