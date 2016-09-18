#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <exception>

template <typename T>
class Queue
{
public:
	/// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the stack is empty.
   */
  class empty_exception : public std::exception
  {
  public:
    /// Default constructor.
    empty_exception (void)
      : std::exception () { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg)
      : std::exception (msg) { }
  };

  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Stack & s);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Stack & rhs);

  /**
   * Add a new element to the end of the list
   *
   *@param[in]		element		Element to add to the list
   */
  void enqueue (T element);
  
  /**
   * Remove the element from the beginning of the queue
   *
   *@exception		empty_exception		The queue is empty.
   */
  T dequeue (void);
  
  /// Remove all elements from the queue.
  void Queue <T>::clear (void)

  /**
   * Test if the queue is empty
   *
   * @retval         true          The queue is empty
   * @retval         false         The queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element in the queue.
   *
   * @return         Size of the queue.
   */
  size_t size (void) const;

  /// Remove all elements from the queue.
  void clear (void);

private:
  // add memer variable here
};

// include the inline files
#include "Queue.inl"

// include the source file
#include "Queue.cpp"

#endif    // !defined _QUEUE_H_
