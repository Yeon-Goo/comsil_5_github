#ifndef __ARRAY__
#define __ARRAY__

#include <iostream>
#include <cstdlib>
using namespace std;


template <typename T>
class Array{
	protected:
		T *data;
		T len;
	public:
			Array(int size);
			~Array();

			T length() const;

			T& operator[](T i);
			T operator[](T i)const;

			void print();
};

template <typename T>
Array<T>::Array(int size)
{
    if(size<0)
    {
    }
    else
    {
        data = new T[size];
        len = size;
    }
}

template <typename T>
Array<T>::~Array()
{
    delete [] data;
}

template <typename T>
T Array<T>::length() const
{
    return len;
}

template <typename T>
T& Array<T>::operator[](T i)
{
    static T tmp;

    if(i >= 0 && i < len)
    {
        return data[i];
    }
    else
    {
        cout<<"Array bound error!"<<endl;
        return tmp;
    }
}

template <typename T>
T Array<T>::operator[](T i) const
{
    if(i >= 0 && i < len)
    {
        return data[i];
    }
    else
    {
        cout<<"Array bound error!"<<endl;
        return 0;
    }
}

template <typename T>
void Array<T>::print()
{
    int i;
    cout<<"[";
    for(i = 0; i < len; i++)
        cout<<data[i]<<" ";
    cout<<"]";
    cout<<endl;
}
#endif
