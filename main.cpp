
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
	MyArray<int> ar{1, 2, 3, 5, 8};
	MyArray<int> other;

	other = ar;

	other[1] = 15;
	other.append(2);

	std::cout << ar << other << std::endl;

	return 0;
}