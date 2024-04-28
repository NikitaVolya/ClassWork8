#pragma once

#include <iostream>

template <typename FirstType, typename SecondType>
class Pair
{
private:
	FirstType first;
	SecondType second;

public:
	Pair(FirstType& pFirst, SecondType& pSecond) : first(pFirst), second(pSecond) {};

	FirstType getFirst() const { return first; }
	SecondType getSecond() const { return second; }

	friend std::ostream& operator<<(std::ostream& out, Pair other)
	{
		out << other.getFirst() << ": " << other.getSecond();
		return out;
	}
};