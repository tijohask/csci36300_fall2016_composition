// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept>

  /*
  Array <T> array;
  
  T top_;

  size_t cur_size_;
  
  size_t max_size_;
  
  bool is_empty_;
  */
 
// Ryan: It is better to define a default value than
// to hardcode values into your code.

// Fix: Added default values

#define _MAX_SIZE_ 50
#define _CUR_SIZE_ 0
#define _IS_EMPTY_ true

//
// Stack
//
template <typename T>
Stack <T>::Stack (void):
array(_MAX_SIZE_), top_(0), cur_size_(_CUR_SIZE_), max_size_(_MAX_SIZE_), is_empty_(_IS_EMPTY_) 
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack):
array(stack.max_size()), top_(0), cur_size_(stack.size()), max_size_(stack.max_size()), is_empty_(stack.is_empty())
{
	if(!is_empty_)
	{//if the stack is not empty, assign the topmost value
		top_ = stack.top();
	}
	for(int i = 0; i < cur_size_; i++)
	{//copy the stack over
		array[i] = stack.array.get(i);
	}
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{

}

// Ryan: Why is there a get method here?
// I didn't realize that a public method could be called
// from a private variable. 
// Fix: Unnecessary code has been removed.

//
// get
//

/*   :P   */

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	if(cur_size_ == max_size_)
	{//double the array size if a resize is in order
		array.resize(max_size_ * 2);
	}
	array.set(cur_size_, element);//set the element
	cur_size_ = cur_size_ + 1;
	top_ = element;//assign element to top_
	if(is_empty_)
	{//make sure the empty flag is down
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
	if(this != &rhs)
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
			array[i] = rhs.array.get(i);
		}
	}
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	//assign everything to their default values
	Array<T> array (_MAX_SIZE_);
	max_size_ = _MAX_SIZE_;
	top_ = 0;
	cur_size_ = _CUR_SIZE_;
	is_empty_ = _IS_EMPTY_;
}

#undef _MAX_SIZE_
#undef _CUR_SIZE_
#undef _IS_EMPTY_
