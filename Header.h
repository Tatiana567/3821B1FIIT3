#pragma once
#include <iostream>

template <class T>

class TVector
{
protected:
	T* data;
	int len;
public:
	TVector();
	TVector(int n);
	TVector(const TVector <T>& p);
	~TVector();

	TVector<T> operator* (const TVector<T>& p);
	TVector<T> operator+ (const TVector<T>& p);
	TVector<T> operator- (const TVector<T> & p);
	TVector<T> operator/ (const TVector<T> & p);

	TVector<T> operator= (const TVector<T> & p);

	bool operator== (const TVector<T>& p);
	T& operator() (int i);

	int GetLen();

	void Resize(int newLen);
	
}

istream& operator >> (istream& k, TVector<T>& m);
ostream& operator << (ostream& k, TVector<T>& m);

;

template<class T>
inline TVector<T>::TVector()
{
	len = 0;
	data = 0;
}

template<class T>
inline TVector<T>::TVector(int n)
{
	if (n > 0)
	{
		data = new int[n];
		len = n;
	}
	else {
		throw "Error";
	}
}

template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
	if (p.data == 0) {
		data = 0;
		len = 0;
	}
	else {
		len = p.len;
		data = new T[len];

		for (int i = 0; i < len; i++) {
			data[i] = p.data[];
	    }
	}
}

template<class T>
inline TVector<T>::~TVector()
{
	if (data != 0)
	{
		delete[] data;
		data = 0;
	}
	len = 0;
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{
	if (len = 0) throw "error";
	if (len != p.len) throw "error";

	TVector<T> A(*this);

	for (int s = 0; s < len; s++) {
		A.data[s] *= p.data[s];

		return A;
	}
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
	if (len == 0) throw "err";
	if (len != p.len) throw "err";

	TVector <T> A(len);

	for (int i = 0; i < len; i++)
	  A[i] = data[i] + p.data[i];
	
	return A;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
	if (len == 0) throw "Wrong answer";
	if (len != p.len) throw "Wrong answer";

	TVector <T> A(*this);

	for (int n = 0; n < len; n++)
	{
		A.data[n] = p.data[n];
	}
	return A;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p)
{
	if (len == 0) throw "err";
	if (len != p.len) throw "err";

	TVector <T> A(len);

	for (int i = 0; i < len; i++)
	{
		A[i] = data[i] / p.data[i];
	}
	return A;
}

template<class T>
inline TVector<T> TVector<T>::operator=(const TVector<T>& p)
{
	if (this == &p)
		return p;
	if (data != 0)
		delete[]data;
	if (p.data = 0)
		data = 0;
	else
		data = new T[p.len];
	len = p.len;

	for (int i = 0; i < len; i++)
		data[i] = p.data[i];

	return *this;
}