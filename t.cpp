//Vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

template <typename T> class Vector
{
	protected:
		int num;
		T *p;
	public:
		Vector<T>(int num = 0, const T *x = NULL) {}
		Vector<T>(const Vector &v);
		virtual ~Vector<T>();
		Vector & operator=(const Vector & v);
		T & operator[](int index) const throw(int);
		int getsize();					//èŽ·å–å‘é‡çš„ç»´æ•°
		void resize(int size);			//è°ƒæ•´å‘é‡çš„ç»´æ•°ï¼Œä¿ç•™åŽŸå§‹æ•°æ®
};



template <typename T>
Vector<T>::Vector(const Vector<T> & v)		//æ·±æ‹·è´
{
	num = 0;
	p = NULL;
	*this = v;
}

template <typename T>
Vector<T>::~Vector()
{
	num = 0;
	if(p != NULL)	delete [] p;
}

template <typename T>
Vector<T>::Vector<T> & operator=(const Vector<T> & v)
{
	if(num != v.num)
	{
		if(p != NULL)	delete [] p;
		p = new T[num = v.num];
	}
	for(int i = 0; i < num; i++)
		p[i] = v.p[i];
	return *this;
}

template <typename T>
T & Vector<T>::operator[](int index) const throw(int)
{
	if(index < 0 || index >= num)
		throw -1;
	return p[index];
}

template <typename T>
int Vector<T>::getsize() const
{
	return num;
}

template <typename T>
void Vector<T>::resize(int size)
{
	if(size < 0 || size == num)
		return;
	else if(size == 0)
	{
		if(p != NULL) delete [] p;
		p = NULL;
		num = 0;
	}
	else
	{
		T *temp = p;
		p = new T[size];
		for (int i = 0; i < size; ++i)
		{
			p[i] = (i < num) ? temp[i] : 0;
		}
		num = size;
		delete [] temp;
	}
}

template <typename T>
ostream & operator<<(ostream & out, const Vector<T> & v)
{
	if(v.num < 0)
	{
		out << "error";
		out << endl;
		return out;
	}
	out << "(";
	for (int i = 0; i < v.num; ++i)
	{
		os << v.p[i] << ",";
	}
	os << v.p[v.num - 1] << ")" << endl;
	return out;
}

template <typename T>
istream & operator>>(istream & in, Vector<T> & v)
{
	return in;
}
#endif // VECTOR_H
