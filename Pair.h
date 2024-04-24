#pragma once

#include <iostream>

template <typename FirstType, typename SecondType>
class Pair
{
private:
	FirstType first;
	SecondType second;

public:
	void print(char end = '\n') const { std::cout << first << " " << second << end; };
	Pair(FirstType pFirst, SecondType pSecond) : first(pFirst), second(pSecond) {};
};