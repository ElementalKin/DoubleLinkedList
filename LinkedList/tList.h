#pragma once
template<typename T>
class tList
{
 struct Node
  {
      T data;                     // data for the element stored
      Node * prev;                // pointer to node following this node
      Node * next;                // pointer to node following this node
  };

  Node * head;                    // pointer to head of linked list
  Node * tail;                    // pointer to tail of linked list

public:
  tList();                                    // initializes head to null
  tList(const tList& other);            // copy-constructor
  tList& operator=(const tList &rhs);   // copy-assignment
  ~tList();                                   // delete all nodes upon destruction

  void push_front(const T& val);  // adds element to front (i.e. head)
  void pop_front();               // removes element from front
  void push_back(const T& val);   // adds element to back (i.e. before back)
  void pop_back();                // removes element from back

  T& front();                     // returns the element at the head
  const T& front() const;         // returns the element at the head (const)
  T& back();                      // returns the element at the tail
  const T& back() const;          // returns the element at the tail (const)

  void remove(const T& val);      // removes all elements equal to the given value

  bool empty() const;             // Returns true if there are no elements
  void clear();                   // Destroys every single node in the linked list
  void resize(size_t newSize);    // Resizes the linked list to contain the given number of elements
                                  // New elements are default-initialized

  class iterator
  {
      Node * cur;                                 // current node being operated upon

  public:
      iterator();                                 // initializes an empty iterator pointing to null
      iterator(Node * startNode);                 // initializes an iterator pointing to the given node

      bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
      bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
      T& operator*() const;                       // returns a reference to the element pointed to by the current node
      iterator& operator++();                     // pre-increment (returns a reference to this iterator after it is incremented)
      iterator operator++(int);                   // post-increment (returns an iterator as it was before it was incremented)
      iterator& operator--();                     // pre-increment (returns a reference to this iterator after it is decremented)
      iterator operator--(int);                   // post-increment (returns an iterator as it was before it was decremented)
  };

  iterator begin();
  const iterator begin() const;
  iterator end();
  const iterator end() const;
};

template<typename T>
inline tList<T>::tList()
{
}

template<typename T>
inline tList<T>::tList(const tList & other)
{
}

template<typename T>
inline tList & tList<T>::operator=(const tList & rhs)
{
	// TODO: insert return statement here
}

template<typename T>
inline tList<T>::~tList()
{
}

template<typename T>
inline void tList<T>::push_front(const T & val)
{
}

template<typename T>
inline void tList<T>::pop_front()
{
}

template<typename T>
inline void tList<T>::push_back(const T & val)
{
}

template<typename T>
inline void tList<T>::pop_back()
{
}

template<typename T>
inline T & tList<T>::front()
{
	// TODO: insert return statement here
}

template<typename T>
inline const T & tList<T>::front() const
{
	// TODO: insert return statement here
}

template<typename T>
inline T & tList<T>::back()
{
	// TODO: insert return statement here
}

template<typename T>
inline const T & tList<T>::back() const
{
	// TODO: insert return statement here
}

template<typename T>
inline void tList<T>::remove(const T & val)
{
}

template<typename T>
inline bool tList<T>::empty() const
{
	return false;
}

template<typename T>
inline void tList<T>::clear()
{
}

template<typename T>
inline void tList<T>::resize(size_t newSize)
{
}

template<typename T>
inline iterator tList<T>::begin()
{
	return iterator();
}

template<typename T>
inline const iterator tList<T>::begin() const
{
	return iterator();
}

template<typename T>
inline iterator tList<T>::end()
{
	return iterator();
}

template<typename T>
inline const iterator tList<T>::end() const
{
	return iterator();
}

template<typename T>
inline tList<T>::iterator::iterator()
{
}

template<typename T>
inline tList<T>::iterator::iterator(Node * startNode)
{
}

template<typename T>
inline bool tList<T>::iterator::operator==(const iterator & rhs) const
{
	return false;
}

template<typename T>
inline bool tList<T>::iterator::operator!=(const iterator & rhs) const
{
	return false;
}

template<typename T>
inline T & tList<T>::iterator::operator*() const
{
	// TODO: insert return statement here
}

template<typename T>
inline iterator & tList<T>::iterator::operator++()
{
	// TODO: insert return statement here
}

template<typename T>
inline iterator tList<T>::iterator::operator++(int)
{
	return iterator();
}

template<typename T>
inline iterator & tList<T>::iterator::operator--()
{
	// TODO: insert return statement here
}

template<typename T>
inline iterator tList<T>::iterator::operator--(int)
{
	return iterator();
}