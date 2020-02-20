#pragma once

// Templated doubly-linked list
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
	tList();                              // initializes head to null
	tList(const tList& other);            // copy-constructor
	tList& operator=(const tList &rhs);   // copy-assignment
	~tList();                             // delete all nodes upon destruction

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front
	void push_back(const T& val);   // adds element to back (i.e. before back)
	void pop_back();                // removes element from back

	void Display();					// displays the linked list
	T& front();                     // returns the element at the head
	const T& front() const;         // returns the element at the head (const)
	T& back();                      // returns the element at the tail
	const T& back() const;          // returns the element at the tail (const)

	void remove(const T& val);      // removes all elements equal to the given value

	bool empty() const;             // Returns true if there are no elements
	void clear();                   // Destroys every single node in the linked list
	void resize(size_t newSize);    // Resizes the linked list to contain the given number of elements
									// New elements are default-initialized

	//I would have made it so that sort would send back the Data but making one for each seemed faster then trying to do that and since im in a rush im doing this.
	void sort(tList* sorting, tList* placeHolder);
	void sort2(tList* sorting, tList* placeHolder);
	void sortAscending();
	void sortDescending();

	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		iterator();                                 // initializes an empty iterator pointing to null
		iterator(Node * startNode);                 // initializes an iterator pointing to the given node

		bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
		bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
		T& operator*();                             // returns a reference to the element pointed to by the current node
		const T& operator*() const;                 // returns a reference to the element pointed to by the current node
		iterator& operator++();                     // pre-increment (returns a reference to this iterator after it is incremented)
		iterator operator++(int);                   // post-increment (returns an iterator as it was before it was incremented)
		iterator& operator--();                     // pre-decrement (returns a reference to this iterator after it is decremented)
		iterator operator--(int);                   // post-decrement (returns an iterator as it was before it was decremented)
	};

	iterator begin();                               // returns an iterator pointing to the first element
	const iterator begin() const;                   // returns a const iterator pointing to the first element
	iterator end();                                 // returns an iterator pointing to one past the last element
	const iterator end() const;                     // returns a const iterator pointing to one past the last element
};

template<typename T>
inline tList<T>::tList()
{
	head = nullptr;
}

template<typename T>
inline tList<T>::tList(const tList & other)
{
	if (other.head == nullptr) 
	{
		head = tail = nullptr;                       // if list is other is empty, empty this.
	}
	else
	{
		head = new Node(*other.head);      // set the head and copy data.
		Node* otherTemp = other.head->next;
		Node* temp = head;
		while (otherTemp != nullptr)
		{
			temp->next = new Node(*otherTemp); //copy the data into the next node.
			temp = temp->next;                                      // temp refers to last element of list.
			otherTemp = otherTemp->next;                            // step one forward.
		}
		tail = temp;
	}
}

template<typename T>
inline tList<T> & tList<T>::operator=(const tList & rhs)
{
	if (this == &rhs)
	{
		return *this; //checks if they are the same array.
	}
	if (rhs.head == nullptr)
	{
		head = tail = nullptr;                       // if list other is empty, empty this.
	}
	else 
	{
		push_front(rhs.head->data);
		Node* n = rhs.head->next;
		Node* temp = head;
		while (n != nullptr)
		{
			temp->next = n; //copy the data into the next node.
			temp = temp->next;                              // temp refers to last element of list.
			n = n->next;                            // step one forward.
		}
		tail = temp;
	}

	return *this;
}

template<typename T>
inline tList<T>::~tList()
{

}

template<typename T>
inline void tList<T>::push_front(const T & val)
{
	if (tail == nullptr && head != nullptr)
	{
		Node* n = new Node();
		n->data = val;
		n->next = head;
		n->next->prev = n;
		head = n;
		tail = n->next;

	}
	else
	{
		Node* n = new Node();
		n->data = val;
		n->next = head;
		if (head != nullptr) {
			n->next->prev = n;
		}
		head = n;
	}
}

template<typename T>
inline void tList<T>::pop_front()
{
	if(head != nullptr)
	{
		Node* n = new Node();
		n = head;
		head = n->next;
		head->prev = nullptr;
		delete n;
	}
}

template<typename T>
inline void tList<T>::push_back(const T & val)
{
	if (head == nullptr && tail != nullptr)
	{
		Node* n = new Node();
		n->data = val;
		n->prev = tail;
		n->prev->next = n;
		tail = n;
		head = n->prev;

	}
	else
	{
		Node* n = new Node();
		n->data = val;
		n->prev = tail;
		if (tail != nullptr) {
			n->prev->next = n;
		}
		tail = n;
	}
}

template<typename T>
inline void tList<T>::pop_back()
{
	if (tail != nullptr)
	{
		Node* n = new Node();
		n = tail;
		tail = n->prev;
		n->prev->prev->next = tail;
		tail->next = nullptr;
		delete n;
	}
}

template<typename T>
inline void tList<T>::Display()
{
	std::cout << "\nNow displaying Tlist: ";
	Node *disp = head;
	if (head == nullptr)
	{
		std::cout << "empty\n";
		return;
	}
	while (disp != nullptr)
	{
		std::cout << " " << disp->data;
		if (disp->next == nullptr)
		{
			break;
		}
		disp = disp->next;
	}
	std::cout << "\n";
}

template<typename T>
inline T & tList<T>::front()
{
		return head->data;
}

template<typename T>
inline const T & tList<T>::front() const
{
	const Node* n = head;
	return n;
}

template<typename T>
inline T & tList<T>::back()
{
	return tail->data;
}
template<typename T>
inline const T & tList<T>::back() const
{
	const Node* n = tail;
	return n;
}

template<typename T>
inline void tList<T>::remove(const T & val)
{
	Node* n = head;
	//checks if head is null.
	if (head == nullptr)
	{
		std::cout << "\nHead is Null" << std::endl;
		return;
	}
	//checks if head is the value that needs to be deleted.
	if (head->data == val)
	{
		//deltes it and makes sure it goes through the linked list to see if any more need to be deleted
		head = n->next;
		//frees up the memory
		free(n);
		std::cout << "\nDeleted Node." << std::endl;
		remove(val);
		return;
	}
	Node* n2 = n->next;
	while (n2->next != nullptr)
	{
		n = n->next;
		n2 = n2->next;
		if(n2->data == val)
		{

			n->next = n2->next;
			if (n2->next != nullptr)
			{
				n2->next->prev = n;
			}
			n2->next = n->prev;
			free(n2);
			std::cout << "\nDeleted Node." << std::endl;
			remove(val);
			return;
		}
	}
	if (tail == nullptr)
	{
		std::cout << "\nTail is Null" << std::endl;
		return;
	}
	//checks if tail is the value that needs to be deleted.
	if (tail->data == val)
	{
		n = tail;
		//deltes it and makes sure it goes through the linked list to see if any more need to be deleted
		tail = n->prev;
		//frees up the memory
		free(n);
		std::cout << "\nDeleted Node." << std::endl;
		return;
	}
	std::cout << "\nall Nodes with value deleted." << std::endl;
	return;
}

template<typename T>
inline bool tList<T>::empty() const
{
	if(head == nullptr)
	{
		return true;
	}
	return false;
}

template<typename T>
inline void tList<T>::clear()
{
	Node* n = head;
	Node* temp = new Node();
	while(n != nullptr)
	{
		temp = n->next;
		delete[] n;
		n = temp;
	}
	head = nullptr;
	tail = nullptr;
}

template<typename T>
inline void tList<T>::resize(size_t newSize)
{
	Node* n = head;
	int s = 0;
	while (n != tail)
	{
		n = n->next;
		s++;
	}
	if (newSize >= s) {
		for (int i = 0; i < newSize; i++)
		{
			push_back(0);
		}
	}
	else
	{
		for (int i = 0; i < (s-newSize); i++)
		{
			pop_back();
		}
	}
}

template<typename T>
typename inline tList<T>::iterator tList<T>::begin()
{
	iterator n = new iterator();
	n::cur = head;
	return n;
}

template<typename T>
typename inline  const tList<T>::iterator tList<T>::begin() const
{
	const iterator n = new iterator();
	n::cur = head;
	return n;
}

template<typename T>
typename inline tList<T>::iterator tList<T>::end()
{
	iterator n = new iterator();
	n::cur = tail;
	return n;
}

template<typename T>
typename inline  const tList<T>::iterator tList<T>::end() const
{
	const iterator n = new iterator();
	n::cur = tail;
	return n;
}

template<typename T>
inline tList<T>::iterator::iterator()
{
	cur = nullptr;
}

template<typename T>
inline tList<T>::iterator::iterator(Node * startNode)
{
	cur = startNode;
}

template<typename T>
inline bool tList<T>::iterator::operator==(const iterator & rhs) const
{
	if(cur == rhs)
	{
		return true;
	}
	return false;
}

template<typename T>
inline bool tList<T>::iterator::operator!=(const iterator & rhs) const
{
	if (cur != rhs)
	{
		return true;
	}
	return false;
}

template<typename T>
inline T & tList<T>::iterator::operator*()
{
	// TODO: insert return statement here
}

template<typename T>
inline const T & tList<T>::iterator::operator*() const
{
	// TODO: insert return statement here
}


template<typename T>
typename inline tList<T>::iterator & tList<T>::iterator::operator++()
{
	cur = cur.next;
	return *cur;
}

template<typename T>
typename inline tList<T>::iterator tList<T>::iterator::operator++(int)
{
	cur = cur.next;
	return *cur.prev;
}

template<typename T>
typename inline tList<T>::iterator & tList<T>::iterator::operator--()
{
	cur = cur.prev;
	return *cur;
}

template<typename T>
typename inline tList<T>::iterator tList<T>::iterator::operator--(int)
{
	cur = cur.prev;
	return *cur.next;
}

template<typename T>
inline void tList<T>::sort(tList* sorting, tList* placeHolder)
{
	if(head == nullptr)
	{
		return;
	}
	Node* n = sorting->head;
	Node* m = sorting->head;
	if (head->next == tail)
	{
		if (head->data > tail->data)
		{
			placeHolder->push_front(head->data);
			placeHolder->push_front(tail->data);
			clear();
		}
		else
		{
			placeHolder->push_front(tail->data);
			placeHolder->push_front(head->data);
			clear();
		}
		return;
	}
	while (m != tail)
	{
		m = m->next;
		if(n->data < m->data)
		{
			n = m;
		}

	}



	if(n == tail)
	{
		placeHolder->push_front(n->data);
		pop_back();
	}
	else if(n == head)
	{
		placeHolder->push_front(n->data);
		pop_front();
	}
	else
	{
		placeHolder->push_front(n->data);
		m = n->next;
		n->next->prev = n->prev;
		n->next->prev->next = n->next;
	}


	if(sorting->empty())
	{
		delete n, m;
	}

}

template<typename T>
inline void tList<T>::sort2(tList* sorting, tList* placeHolder)
{
	if (head == nullptr)
	{
		return;
	}
	Node* n = sorting->head;
	Node* m = sorting->head;
	if (head->next == tail)
	{
		if (head->data > tail->data)
		{
			placeHolder->push_back(head->data);
			placeHolder->push_back(tail->data);
			clear();
		}
		else
		{
			placeHolder->push_back(tail->data);
			placeHolder->push_back(head->data);
			clear();
		}
		return;
	}
	while (m != tail)
	{
		m = m->next;
		if (n->data < m->data)
		{
			n = m;
		}

	}



	if (n == tail)
	{
		placeHolder->push_back(n->data);
		pop_back();
	}
	else if (n == head)
	{
		placeHolder->push_back(n->data);
		pop_front();
	}
	else
	{
		placeHolder->push_back(n->data);
		m = n->next;
		n->next->prev = n->prev;
		n->next->prev->next = n->next;
	}


	if (sorting->empty())
	{
		delete n, m;
	}

}

template<typename T>
inline void tList<T>::sortAscending()
{
	int i = 0;
	tList<int>* placeHolder = new tList();
	Node* n = head;
	while (n != tail)
	{
		n = n->next;
		i++;
	}
	while(i >= 0)
	{
		sort(this, placeHolder);
		i--;
	}
	*this = *placeHolder;
}

template<typename T>
inline void tList<T>::sortDescending()
{
	int i = 0;
	tList<int>* placeHolder = new tList();
	Node* n = head;
	while (n != tail)
	{
		n = n->next;
		i++;
	}
	while (i >= 0)
	{
		sort2(this, placeHolder);
		i--;
	}
	*this = *placeHolder;
}
