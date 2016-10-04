// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

// Ryan: Please include the honor pledge in each file.

// Fix: Included honor pledge

#include <stdexcept>

/*  
  Array <T> array;

  size_t cur_size_;
  
  size_t max_size_;
  
  bool is_empty_;
*/

// Ryan: It is better to set default values than hard code them
// into your code.

// Fix: Added default values

#define _MAX_SIZE_ 50
#define _CUR_SIZE_ 0
#define _IS_EMPTY_ true

//
// Queue default
//
template <typename T>
Queue <T>::Queue (void): 
array(_MAX_SIZE_), cur_size_(_CUR_SIZE_), max_size_(_MAX_SIZE_), is_empty_(_IS_EMPTY_) 
{
	
}

//
// Queue copy
//
template <typename T>
Queue <T>::Queue (const Queue & queue): 
array(queue.max_size()), cur_size_(queue.size()), max_size_(queue.max_size()), is_empty_(queue.is_empty())
{
	for(int i = 0; i < cur_size_; i++)
	{//iterate through the array, copying the queue
		array[i] = queue.array.get(i);
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
	if(this != &rhs)//check pointers
	{
		array = Array <T> (rhs.max_size());//declare a new array to match the rhs
		cur_size_ = rhs.size();//assign the sizes
		max_size_ = rhs.max_size();
		for(int i = 0; i < cur_size_; i++)
		{//iterate through, copying the queue
			array[i] = rhs.array.get(i);
		}
	}
}

// Ryan: Why do you need the get method?
// I didn't realize that a public method could be called
// from a private variable. 
// Fix: Unnecessary code has been removed.

//
// get
//

/*   :P   */

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
	if(cur_size_ == max_size_)
	{//resize the array as needed
		array.resize(max_size_ * 2);
	}
	array.set(cur_size_, element);//put the element at the end of the queue
	cur_size_ = cur_size_ + 1;
	if(is_empty_)
	{//make sure is_empty_ is false
		is_empty_ = false;
	}
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
	T hold = array[0];//store the value to be returned
	
	for(int i = 0; i < cur_size_ - 1; i++)
	{//move everything forward one unit
		array[i] = array[i + 1];
	}
	
	cur_size_ -= 1;//decrement cur_size_
	
	if(cur_size_ == 0)
	{//if this emptied the array, mark it as such
		is_empty_ = true;
	}
	
	return hold;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{//reset inside elements to default
 //there shouldn't be a way to get to the old data,
 //so there isn't really a need to delete said data
	Array<T> array (_MAX_SIZE_);
	max_size_ = _MAX_SIZE_;
	cur_size_ = _CUR_SIZE_;
	is_empty_ = _IS_EMPTY_;
}

#undef _MAX_SIZE_
#undef _CUR_SIZE_
#undef _IS_EMPTY_
