//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void): Base_Array<T>(N)
{
	//use the length constructor
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr): Base_Array<T>(arr)
{
	//use the array copy constructor
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr)
{
	//NO
	//throw 	
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill): Base_Array<T>(N, fill)
{
	//use the fill constructor
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
	//All the real "Destruction" happens in the Array class...
	//*sigh*
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	this->cur_size_ = rhs.size();//copy over the current size
	for(int i = 0; i < this->cur_size_; i++)
	{
		this->data_[i] = rhs.get(i);
	}//copy the array over
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
	//NO
}

//
// resize
//
/* 
 * Overriding the base method to prevent problems. Now resize
 * will do nothing.
 */
/*
Fixed array now inherits from Base Array. Resize is not needed.
template <typename T, size_t N>
void Fixed_Array <T, N> :: resize(size_t new_size)
{
	//NO
}*/
