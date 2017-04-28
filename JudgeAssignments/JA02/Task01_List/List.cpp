#include <sstream>
#include "List.h"

List::Node::Node(T value, Node * prev, Node * next)
	: value(value), prev(prev), next(next)
{

}

T List::Node::getValue() const
{
	return this->value;
}

void List::Node::setValue(T value)
{
	this->value = value;
}

List::Node * List::Node::getNext() const
{
	return this->next;
}

void List::Node::setNext(Node * next)
{
	this->next = next;
}

List::Node * List::Node::getPrev() const
{
	return this->prev;
}

void List::Node::setPrev(Node * prev)
{
	this->prev = prev;
}

List::List()
	: head(nullptr), tail(nullptr), size(0)
{
}

List::List(const List & other)
	: List()
{
	for (Node * currNode = other.head; currNode != nullptr; currNode = currNode->getNext())
	{
		this->add(currNode->getValue());
	}
}

T List::first() const
{
	return this->head->getValue();
}

void List::add(T value)
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

void List::addAll(const List & other)
{
	for (Node * currNode = other.head; currNode != nullptr; currNode = currNode->getNext())
	{
		this->add(currNode->getValue());
	}
}

void List::removeFirst()
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

void List::removeAll()
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

size_t List::getSize() const
{
	return this->size;
}

bool List::isEmpty() const
{
	return this->size == 0 ? true : false;
}

List List::getReversed(List l)
{
	List reversedList;

	for (Node * currNode = l.tail; currNode != nullptr; currNode = currNode->getPrev())
	{
		reversedList.add(currNode->getValue());
	}

	return reversedList;
}

std::string List::toString() const
{
	std::ostringstream outputStream;

	for (Node * currNode = this->head; currNode != nullptr; currNode = currNode->getNext())
	{
		outputStream << currNode->getValue() << " ";
	}

	return outputStream.str();
}

List & List::operator<<(const T & value)
{
	this->add(value);
	return *this;
}

List & List::operator<<(const List & other)
{
	this->addAll(other);
	return *this;
}

List & List::operator=(const List & other)
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

List::~List()
{
	Node *ptrHead = this->head;
	while (ptrHead != nullptr)
	{
		Node *next = ptrHead->getNext();
		delete ptrHead;
		ptrHead = next;
	}
}
