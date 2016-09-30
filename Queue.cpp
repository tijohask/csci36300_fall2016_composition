
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
array(queue.max_size()), cur_size_(queue.size()), max_size_(queue.max_size()), is_empty_(queue.is_empty())
{
	for(int i = 0; i < cur_size_; i++)
	{//iterate through the array, copying the queue
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
	if(this != &rhs)//check pointers
	{
		array = Array <T> (rhs.max_size());//declare a new array to match the rhs
		cur_size_ = rhs.size();//assign the sizes
		max_size_ = rhs.max_size();
		for(int i = 0; i < cur_size_; i++)
		{//iterate through, copying the queue
			array[i] = rhs.get(i);
		}
	}
}

//
// get
//
/**
 * Genuine question: is there a better way to do this?
 * I put this get method in here to be able to copy the 
 * Queue from one to another. Array is private, after all,
 * so there is no direct means of getting to it, but...
 * I dunno. I feel like I missed something.
 */
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
	cur_size_ = 0;
	is_empty_ = true;
}
