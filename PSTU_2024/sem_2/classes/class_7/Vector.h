#pragma once

#include <iostream>

using namespace std;

template <class T>
class Vector
{
private:
	int size;
	T* data;
public:
	Vector(int s, T k);
	Vector(const Vector<T>& obj);
	~Vector();
	Vector& operator=(const Vector<T>& obj);
	T& operator[](int index);
	Vector operator*(const Vector<T>& obj);
	int operator()();
	friend ostream& operator<<(ostream& out, const Vector<T>& obj)
	{
		for (int i = 0; i < obj.size; ++i)
		{
			out << obj.data[i] << ' ';
		}

		return out;
	}
	friend istream& operator>>(istream& in, Vector<T>& obj)
	{
		for (int i = 0; i < obj.size; ++i)
		{
			in >> obj.data[i];
		}

		return in;
	}
};

template <class T>
Vector<T>::Vector(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; ++i)
	{
		data[i] = k;
	}
}

template <class T>
Vector<T>::Vector(const Vector<T>& obj)
{
	size = obj.size;
	data = new T[size];
	for (int i = 0; i < size; ++i)
	{
		data[i] = obj.data[i];
	}
}

template <class T>
Vector<T>::~Vector()
{
	delete[] data;
	data = nullptr;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	size = obj.size;
	delete[] data;
	data = new T[size];

	for (int i = 0; i < size; ++i)
	{
		data[i] = obj.data[i];
	}

	return *this;
}

template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < size)
	{
		return data[index];
	}
	else
	{
		cerr << "Index out of range !" << endl;
		exit(1);
	}
}

template <class T>
Vector<T> Vector<T>::operator*(const Vector<T>& obj)
{
	if (size != obj.size)
	{
		cerr << "Vectors have different sizes !" << endl;
		exit(1);
	}

	Vector<T> tmp(size, 0);

	for (int i = 0; i < size; ++i)
	{
		tmp.data[i] = data[i] * obj.data[i];
	}
	return tmp;
}

template <class T>
int Vector<T>::operator()()
{
	return size;
}