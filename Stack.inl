//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return cur_size_;
}

//
// max_size
//
template <typename T>
inline
size_t Stack <T>::max_size (void) const
{
	return max_size_;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	return top_;
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	return is_empty_;
}
