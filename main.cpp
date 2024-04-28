
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

int main()
{
	Array<int> ar(5, 12, 5, 8);

	for (int i = 0; i < ar.getSize(); i++)
		std::cout << ar[i] << ", ";

	return 0;
}