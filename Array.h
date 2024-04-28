#pragma once

template <class T>
class Array
{
private:
	T* elements;
	size_t size;
public:
	Array() : elements(nullptr), size(0) {}
	template<class...Types>
	Array(Types... args) : Array() { append(args...); }

	size_t getSize() const { return size; }

	T& operator[](int pIndex) { return elements[pIndex]; }

	const Array<T>& append(const T& element);

	template <class... Types>
	const Array<T>& append(const T& first, Types... args)
	{
		append(first);
		append(args...);
		return *this;
	}

	~Array();
};

template<class T>
const Array<T>& Array<T>::append(const T& element)
{
	T* newElements = new T[size + 1];
	for (int i = 0; i < size; i++)
		newElements[i] = elements[i];
	newElements[size++] = element;
	elements = newElements;
	return *this;
}

template<class T>
Array<T>::~Array()
{
	if (elements)
		delete[] elements;
}
