#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    if (n == 0)
        _data = NULL;
    else
        _data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& src) : _data(NULL), _size(0)
{
    *this = src;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& src)
{
    if (this != &src)
    {
        if (_data != NULL)
            delete[] _data;

        _size = src._size;
        if (_size == 0)
            _data = NULL;
        else
        {
            _data = new T[_size]();
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = src._data[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    if (_data != NULL)
        delete[] _data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size || _data == NULL)
        throw OutOfBoundsException();
    return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size || _data == NULL)
    {
        throw OutOfBoundsException();
    }
    return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
    return "Error: Index is out of bounds!";
}

#endif