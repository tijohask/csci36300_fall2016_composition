//
// size
//
template <typename T>
inline
size_t Queue <T>::size (void) const
{
	return cur_size_;
}

template <typename T>
inline
size_t Queue <T>::max_size (void) const
{
	return max_size_;
}

//
//
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
	return is_empty_;
}
