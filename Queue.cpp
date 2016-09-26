
#include <stdexcept>


/*  
  Array <T> array;

  size_t cur_size_;
  
  size_t max_size_;
  
  bool is_empty_;
*/

//
// Queue default
//
template <typename T>
Queue <T>::Queue (void): 
array(50), cur_size_(0), max_size_(50), is_empty_(true) 
{
	
}

//
// Queue copy
//
template <typename T>
Queue <T>::Queue (const Queue & queue): 
array(NULL), cur_size_(queue.size()), max_size_(queue.max_size()), is_empty_(queue.is_empty())
{
	array = Array <T> (queue.max_size());
	cur_size_ = queue.size();
	max_size_ = queue.max_size();
	for(int i = 0; i < cur_size_; i++)
	{
		array[i] = queue.get(i);
	}
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{

} 

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	if(this != &rhs)
	{
		array = Array <T> (rhs.max_size());
		cur_size_ = rhs.size();
		max_size_ = rhs.max_size();
		for(int i = 0; i < cur_size_; i++)
		{
			array[i] = rhs.get(i);
		}
	}
}

//
// get
//
template <typename T>
T Queue <T>::get (size_t index) const
{
	return array[index];
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
	if(cur_size_ == max_size_)
	{
		array.resize(max_size_ * 2);
	}
	array.set(cur_size_, element);
	cur_size_ = cur_size_ + 1;
	if(is_empty_)
	{
		is_empty_ = false;
	}
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
	T hold = array[0];
	
	for(int i = 0; i < cur_size_ - 1; i++)
	{
		array[i] = array[i + 1];
	}
	
	cur_size_ -= 1;
	
	if(cur_size_ == 0)
	{
		is_empty_ = true;
	}
	
	return hold;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
	cur_size_ = 0;
	is_empty_ = true;
}
