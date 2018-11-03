#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stdlib.h>

template <typename T, typename C=10 >
struct allocator {
	typedef T *pointer;
	pointer operator() (pointer *oldata, unsigned int size){
		return realloc(oldata, size+(sizeof(T) * C));
	}
};

template<typename T, typename A=allocator<T>>
struct RVector {

	unsigned int capacity;
	unsigned int size;
	unsigned int realloc_cap;
	size_t nmemb;

	T      *data;
	A      allocator;

	RVector(unsigned int capacity, unsigned int realloc_cap);
	virtual ~RVector();
};

template<typename T>
RVector<T>::RVector(unsigned int capacity, unsigned int realloc_cap)
{
	this->capacity    = capacity;
	this->realloc_cap = realloc_cap;
	this->size        = 0;
	this->nmemb       = sizeof(T);
	this->data        = (T *)calloc(capacity, sizeof(T));

}

template<typename T>
RVector<T>::~RVector()
{
	free(data);
	this->capacity    = 0;
	this->realloc_cap = 0;
	this->size        = 0;
	this->data        = nullptr;
}

template<typename T>
void rvector_realloc(RVector<T> *vector, unsigned int size)
{
	if (vector->size+1 == vector->capacity) {
		T *data = (T *)realloc(vector->data,
			(vector->size+size)*vector->nmemb);
		vector->data = data;
	}
	vector->capacity += size;
}

template <typename T>
void rvector_pushback(RVector<T> *vector, T value)
{
	rvector_realloc(vector, vector->realloc_cap);
	vector->data[vector->size] = value;
	vector->size += 1;
}

template<typename T>
T *rvector_at(const RVector<T> *vector, unsigned int index)
{
	return &vector->data[index];
}

#endif /* VECTOR_H_INCLUDED */

