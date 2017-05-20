#ifndef LIST_H
#define LIST_H

#include <string>

template<typename T>
class List {
private:
	class Node {
	private:
		T value;
		Node * prev;
		Node * next;

	public:
		Node(T value, Node * prev, Node * next)
			: value(value), prev(prev), next(next)
		{
		}

		T& getValue()
		{
			return this->value;
		}

		void setValue(T value)
		{
			this->value = value;
		}

		Node * getNext() const
		{
			return this->next;
		}

		void setNext(Node * next)
		{
			this->next = next;
		}

		Node * getPrev() const
		{
			return this->prev;
		}

		void setPrev(Node * prev)
		{
			this->prev = prev;
		}
	};

	Node * head;
	Node * tail;
	size_t size;
public:
	class Iterator
	{
	private:
		Node* current;
	public:
		Iterator(Node* start)
			: current(start) {}

		Iterator& operator++()
		{
			this->current = this->current->getNext();
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator valueBeforeIncrement = *this;
			++(*this);
			return valueBeforeIncrement;
		}

		bool operator==(const Iterator& other) const
		{
			return this->current == other.current;
		}

		bool operator!=(const Iterator& other) const
		{
			return this->current != other.current;
		}

		T& operator*()
		{
			return this->current->getValue();
		}
	};

	List() : head(nullptr), tail(nullptr), size(0)
	{
	}

	List(const List& other)
		: List()
	{
		for (Node * currNode = other.head; currNode != nullptr; currNode = currNode->getNext())
		{
			this->add(currNode->getValue());
		}
	}

	List(std::initializer_list<T> initList)
		: List()
	{
		for (T item : initList)
		{
			this->add(item);
		}
	}

	T first() const
	{
		return this->head->getValue();
	}

	void add(T value)
	{
		Node * newNode = new Node(value, nullptr, nullptr);

		if (!this->isEmpty())
		{
			newNode->setPrev(this->tail);
			this->tail->setNext(newNode);
			this->tail = newNode;
		}
		else
		{
			this->head = newNode;
			this->tail = newNode;
			this->head->setPrev(nullptr);
			this->head->setNext(nullptr);
		}

		this->size++;
	}

	void addAll(const List& other)
	{
		for (Node * currNode = other.head; currNode != nullptr; currNode = currNode->getNext())
		{
			this->add(currNode->getValue());
		}
	}

	void removeFirst()
	{
		Node *ptrNext = this->head->getNext();
		delete this->head;

		this->head = ptrNext;
		if (ptrNext != nullptr)
		{
			this->head->setPrev(nullptr);
		}

		size--;
	}

	void removeAll()
	{
		Node *ptrHead = this->head;
		while (ptrHead != nullptr)
		{
			Node *next = ptrHead->getNext();
			delete ptrHead;
			ptrHead = next;
		}

		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}

	size_t getSize() const
	{
		return this->size;
	}

	bool isEmpty() const
	{
		return this->size == 0 ? true : false;
	}

	static List getReversed(List l)
	{
		List reversedList;

		for (Node * currNode = l.tail; currNode != nullptr; currNode = currNode->getPrev())
		{
			reversedList.add(currNode->getValue());
		}

		return reversedList;
	}

	std::string toString() const
	{
		std::ostringstream outputStream;

		for (Node * currNode = this->head; currNode != nullptr; currNode = currNode->getNext())
		{
			outputStream << currNode->getValue() << " ";
		}

		return outputStream.str();
	}

	List& operator<<(const T& value)
	{
		this->add(value);
		return *this;
	}

	List& operator<<(const List& other)
	{
		this->addAll(other);
		return *this;
	}

	List& operator=(const List& other)
	{
		if (this != &other)
		{
			Node *ptrhead = this->head;
			while (ptrhead != nullptr)
			{
				Node *next = ptrhead->getNext();
				delete ptrhead;
				ptrhead = next;
			}

			this->head = nullptr;
			this->tail = nullptr;
			this->size = 0;

			for (Node * currNode = other.head; currNode != nullptr; currNode = currNode->getNext())
			{
				this->add(currNode->getValue());
			}
		}

		return *this;
	}

	~List()
	{
		Node *ptrHead = this->head;
		while (ptrHead != nullptr)
		{
			Node *next = ptrHead->getNext();
			delete ptrHead;
			ptrHead = next;
		}
	}

	Iterator begin() const
	{
		return Iterator(this->head);
	}

	Iterator end() const
	{
		return Iterator(nullptr);
	}
};

#endif // LIST_H

