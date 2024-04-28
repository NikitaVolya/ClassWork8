#pragma once

#include <iostream>

template <class T>
class MyArray
{
private:
	T* elements;
	size_t size;
public:
	MyArray() : elements(nullptr), size(0) {}
	MyArray(const std::initializer_list<T>& list);
	MyArray(const MyArray<T>& other);
	MyArray(MyArray<T>&& other);
	~MyArray();

	const MyArray<T>& operator=(const MyArray<T>& other);
	const MyArray<T>& operator=(MyArray<T>&& other);

	MyArray<T> copy() const { return *this; };
	size_t getSize() const { return size; }

	T& operator[](int pIndex) { return elements[pIndex]; }
	const T& operator[](int pIndex) const { return elements[pIndex]; }

	const MyArray<T>& append(const T& element);

	friend std::ostream& operator<<(std::ostream& out, const MyArray<T>& object)
	{
		std::cout << "[ ";
		for (int i = 0; i < object.getSize(); i++)
			std::cout << object[i] << (i < object.getSize() - 1 ? ", " : " ]");
		return out;
	}
};

template<class T>
inline MyArray<T>::MyArray(const std::initializer_list<T>& list) : elements { new T[list.size()] }, size { list.size() }
{
	int i = 0;
	for (const int& item : list)
		elements[i++] = item;
}

template<class T>
inline MyArray<T>::MyArray(const MyArray<T>& other) : elements{ new T[other.size] }, size{ other.size }
{
	for (int i = 0; i < other.size; i++)
		elements[i] = other[i];
}

template<class T>
inline MyArray<T>::MyArray(MyArray<T>&& other)
{
	elements = other.elements;
	size = other.size;

	other.elements = nullptr;
	other.size = 0;
}

template<class T>
MyArray<T>::~MyArray()
{
	if (elements)
		delete[] elements;
}

template<class T>
const MyArray<T>& MyArray<T>::append(const T& element)
{
	T* newElements = new T[size + 1];
	for (int i = 0; i < size; i++)
		newElements[i] = elements[i];
	newElements[size++] = element;
	elements = newElements;
	return *this;
}

template<class T>
inline const MyArray<T>& MyArray<T>::operator=(const MyArray<T>& other)
{
	if (this == &other)
		return *this;

	if (size != other.size)
	{
		size = other.size;
		delete[] elements;
		elements = new T[size];
	}

	for (int i = 0; i < size; i++)
		elements[i] = other.elements[i];

	return *this;
}

template<class T>
inline const MyArray<T>& MyArray<T>::operator=(MyArray<T>&& other)
{
	elements = other.elements;
	size = other.size;

	other.elements = nullptr;
	other.size = 0;
}