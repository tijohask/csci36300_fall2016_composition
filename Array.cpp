
#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void): data_(NULL), cur_size_(0), max_size_(0)
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length): data_(NULL), cur_size_(length), max_size_(length)
{
	if(length > 0)
	{
		data_ = new T[length];
	}
}

//
// Array (size_t, value)
//
template <typename T>
Array <T>::Array (size_t length, T fill): data_(NULL), cur_size_(length), max_size_(length)
{
	if(length > 0)
	{
		data_ = new T[length];
		this->fill(fill);
	}
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array): data_(NULL), cur_size_(array.size), max_size_(array.max_size())
{
	if(array.max_size() > 0)
	{
		data_ = new T[array.max_size()];
		for(size_t i = 0; i < cur_size_; i++)
		{//and copy the data in from the other array
			data_[i] = array[i];
		}
	}
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	if(data_ != NULL)
	{
		delete [] data_;
	}
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	if(this != &rhs)
	{
		delete [] data_;
		data_ = new T[rhs.max_size()];
		cur_size_ = rhs.size();
		max_size_ = rhs.max_size();
		for(size_t i = 0; i < cur_size_; i++)
		{
			data_[i] = rhs[i];
		}
	}
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
	if(index >= max_size_)
	{
		throw std::out_of_range ("Index out of range");
	}
	return data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
	if(index >= max_size_)
	{
		throw std::out_of_range ("Index out of range");
	}
	return data_[index];

}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{
	if(index >= max_size_)
	{
		throw std::out_of_range ("Index out of range");
	}
	return data_[index];

}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
	if(index >= max_size_)
	{
		throw std::out_of_range ("Index out of range");
	}
	data_[index] = value;
	if(cur_size_ < index)
	{
		cur_size_ = index;
	}
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if(max_size_ < new_size)
	{//the array will need to be expanded

		T * hold = data_;//store the old data
		data_ = new T[new_size];//make a new array
		max_size_ = new_size;//reassign the maximum size to the new value
		this->fill(' ');
		//fill the array with blanks. the compiler doesn't like
		//assigning uninitialized values
		for(size_t i = 0; i < cur_size_; i++)
		{//iterate through and copy the old array
			data_[i] = hold[i];
		}
		delete [] hold;
		//apparently this needs to be deleted.
		//thought the compiler would do this when it went out of scope.
	}

	else if(max_size_ > new_size)
	{//the array will need to be truncated
		
		if(cur_size_ > new_size)
		{//if the array is truncated past the previous last element
			cur_size_ = new_size;
		}
		T * hold = data_;//store the old data
		data_ = new T[new_size];//make a new array
		max_size_ = new_size;//reassign the maximum size to the new value
		this->fill(' ');
		//fill the array with blanks. the compiler doesn't like
		//assigning uninitialized values
		for(size_t i = 0; i < cur_size_; i++)
		{//iterate through and copy the old array
			data_[i] = hold[i];
		}
		delete [] hold;
		//apparently this needs to be deleted.
		//thought the compiler would do this when it went out of scope.
	}

	else
	{//nothing needs to be done
		return;
	}
}

//
// find (element)
//
template  <typename T>
int Array <T>::find (T value) const
{
	return this->find(value, 0);
}

//
// find (element, size_t) 
//
template <typename T>
int Array <T>::find (T val, size_t start) const
{
	if(start >= max_size_)
	{
		throw std::out_of_range ("Index is out of range");
	}
	for(int i = start; i < max_size_; i++)
	{
		if(data_[i] == val)
		{
			return static_cast<int>(i);
		}
	}
	return -1;
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	//(this != &rhs) compares the addresses. 
	//If the object is being assigned to itself, its caught and nothing happens
	
	//(*this != rhs) compares the actual objects.
	//It'll save time if many identical arrays are being compared to 
	//each other, but it'll waste time if the majority of arrays are not
	//similar
	
	if(this == &rhs)
	{
		return true;
	}
	if(cur_size_ == rhs.size() && max_size_ == rhs.max_size())
	{
		for(size_t i = 0; i < max_size_; i++)
		{
			if(data_[i] != rhs[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{
	for(size_t i = 0; i < max_size_; i++)
	{
		data_[i] = value;
	}
}
