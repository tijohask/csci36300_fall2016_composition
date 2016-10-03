
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
array(stack.max_size()), top_(0), cur_size_(stack.size()), max_size_(stack.max_size()), is_empty_(stack.is_empty())
{
	if(!is_empty_)
	{//if the stack is not empty, assign the topmost value
		top_ = stack.top();
	}
	for(int i = 0; i < cur_size_; i++)
	{//copy the stack over
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

// Ryan: Why is there a get method here?

//
// get
//
/**
 * Genuine question: is there a better way to do this?
 * I put this get method in here to be able to copy the 
 * Stack from one to another. Array is private, after all,
 * so there is no direct means of getting to it, but...
 * I dunno. I feel like I missed something.
 *
 * I'm honestly not sure if a get method should be in this 
 * class.
 */
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
	//assign everything to their default values
	Array<T> array (50);
	max_size_ = 50;
	top_ = 0;
	cur_size_ = 0;
	is_empty_ = true;
}
