#pragma once
#include <iostream>
#define SIZE_INCREMENT 10
using namespace std;

template <class T>
class MyVector
{
	T* vec;
	size_t length;
	size_t capacity;

public:
	MyVector();
	MyVector(int _capacity);
	MyVector(MyVector& mv);
	~MyVector();
	void push_back(T item);
	void pop_back();
	T& operator[](size_t pos);
	size_t size();
};

template <class T>
MyVector<T>::MyVector()
{
	vec = new T[SIZE_INCREMENT];
	capacity = SIZE_INCREMENT;
	length = 0;
}

template <class T>
MyVector<T>::MyVector(int _capacity)
{
	vec = new T[_capacity];
	capacity = _capacity;
	length = 0;
}

template <class T>
MyVector<T>::MyVector(MyVector& mv)
{
	vec = new T[mv.capacity];
	capacity = mv.capacity;
	length = mv.length;

	for (int i = 0; i < mv.length; i++)
	{
		vec[i] = mv.vec[i];
	}
}

template <class T>
MyVector<T>::~MyVector()
{
	delete[] vec;
}

template <class T>
void MyVector<T>::push_back(T item)
{
	if (length < capacity)
	{
		vec[length++] = item;
	}
	else
	{
		//create a new bigger array
		T* new_vec = new T[capacity + SIZE_INCREMENT];

		//copy items to the new array
		for (int i = 0; i < capacity; i++)
			new_vec[i] = vec[i];

		//swap array pointers
		T* temp = vec;
		vec = new_vec;

		//delete old array
		delete[]temp;

		//now, add the new item
		vec[length++] = item;
	}

}

template <class T>
void MyVector<T>::pop_back()
{
	if(length > 0)
		length--;
}

template <class T>
T& MyVector<T>::operator[](size_t pos)
{
	return vec[pos];
}

template <class T>
size_t MyVector<T>::size()
{
	return length;
}
