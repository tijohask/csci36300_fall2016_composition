
#include <stdexcept>

  /*
  Array <T> array;
  
  T top_;

  size_t cur_size_;
  
  size_t max_size_;
  
  bool is_empty_;
  */

//
// Stack
//
template <typename T>
Stack <T>::Stack (void):
array(50), top_(0), cur_size_(0), max_size_(50), is_empty_(true) 
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack):
array(), top_(0), cur_size_(stack.size()), max_size_(stack.max_size()), is_empty_(stack.is_empty())
{
	if(!is_empty_)
	{
		top_ = stack.top();
	}
	array = Array <T> (stack.max_size());
//	cur_size_ = stack.size();
//	max_size_ = stack.max_size();
	for(int i = 0; i < cur_size_; i++)
	{
		array[i] = stack.get(i);
	}
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{

}

//
// get
//
template <typename T>
T Stack <T>::get (size_t index) const
{
	return array[index];
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	if(cur_size_ == max_size_)
	{
		array.resize(max_size_ * 2);
	}
	array.set(cur_size_, element);
	cur_size_ = cur_size_ + 1;
	top_ = element;
	if(is_empty_)
	{
		is_empty_ = false;
	}
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	//T hold = top_;
	cur_size_ = cur_size_ - 1;//decrement current size
	if(cur_size_ == 0)
	{//check if removing the element emptied the array
		is_empty_ = true;
		top_ = 0;
	}
	else
	{//assign a new topmost element
		top_ = array[cur_size_ - 1];
	}
	//return hold;
	//Shouldn't pop return the item that was popped off?
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	//copy over the is_empty_ boolean
	is_empty_ = rhs.is_empty();
	
	if(!is_empty_)
	{//if the array isn't empty, copy over the top value
		top_ = rhs.top();
	}
	
	//assign a new array
	array = Array <T> (rhs.max_size());
	
	cur_size_ = rhs.size();//set the sizes to their new values
	max_size_ = rhs.max_size();
	
	for(int i = 0; i < cur_size_; i++)
	{//copy over the stack elements
		array[i] = rhs.get(i);
	}
	
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	//basically a new constructor
	//assign everything to their default values
	Array<T> array (50);
	max_size_ = 50;
	top_ = 0;
	cur_size_ = 0;
	is_empty_ = true;
}
