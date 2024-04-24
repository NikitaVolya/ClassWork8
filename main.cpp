
#include <iostream>
#include "Pair.h"

int main()
{
	Pair<char, int> test('a', 15);
	Pair<int, int> test2(2, 15);

	test.print();
	test2.print();

	return 0;
}