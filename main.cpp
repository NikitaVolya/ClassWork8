
#include <iostream>

#include "Array.h"

double sum(double pOption)
{
	return pOption;
}

template <class...Types>
double sum(double first, Types...args)
{
	double result = first;
	result += sum(args...);
	return result;
}

int getNumber(double first)
{
	return 1;
}

template <class...Types>
int getNumber(double first, Types...args)
{	
	return 1 + getNumber(args...);
}

template <class...Types>
double avg(Types...args)
{
	double s = sum(args...);
	int number = getNumber(args...);
	return s / number;
}

int main()
{
	std::cout << avg(5, 5, 11);

	return 0;
}