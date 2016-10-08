// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

// Ryan: Include the honor pledge in each file.

// Fix: Included honor pledge

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
/*
	if(N > M)
	{
		this->cur_size_ = arr.size();//copy over the current size
		this->max_size_ = N;
		this->data_ = new T[N];
		for(int i = 0; i < M; i++)
		{
			this->data_[i] = arr.get(i);
		}//copy the array over
		
	}
	else
	{
		this->cur_size_ = N;
		this->max_size_ = N;
		this->data_ = new T[N];
		for(int i = 0; i < N; i++)
		{
			this->data_[i] = arr.get(i);
		}
	}
*/
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
	//All the real "Destruction" happens in the Base_Array class...
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
/*	
	if(N > M)
	{
		this->cur_size_ = rhs.size();//copy over the current size

		for(int i = 0; i < M; i++)
		{
			this->data_[i] = rhs.get(i);
		}//copy the array over
		
	}
	else// (N <= M)
	{
		if(rhs.size() < N)
		{
			this->cur_size_ = rhs.size();
		}
		else
		{
			this->cur_size_ = N;
		}
		
		for(int i = 0; i < this->size(); i++)
		{
			this->data_[i] = rhs.get(i);
		}
	}
*/
}
