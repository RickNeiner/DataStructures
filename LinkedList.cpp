// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

ILinkedList::ILinkedList() : m_count(0)
{

}

/** Returns true if list is empty, otherwise false */
bool ILinkedList::isEmpty() const
{

	if(m_count == 0) {
		return true;
	}
	else {
		return false;
	}
}

Node::Node() : m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{

}
Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node * Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	delete m_next;
	// you can recursively handle this which would require some code
	// Otherwise you need to delete each node individualy in the owner of the Nodes (i.e. the LinkedList)
}

PointerBasedLinkedList::PointerBasedLinkedList() : ILinkedList(), m_head(nullptr)
{

}

/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{
	Node* newNode = new Node;
	newNode->setItem(val);
	newNode->setNext(NULL);
	if (m_head == NULL){
		m_head = newNode;
		m_count++;
		return true;
	}
	else {
		Node* knewNode = m_head;
		while(knewNode->getNext() != NULL){
			knewNode = knewNode->getNext();
		}
		knewNode->setNext(newNode);
		m_count++;
		return true;
	}
	//TODO
}
/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{
	//TODO
	Node* curNode = nullptr;
	Node* preNode = nullptr;
	if(m_head != nullptr)
	{
		curNode = m_head->getNext();
		preNode = m_head;
	}
	bool out = false;
	int count = 0;
	if(isEmpty())
	{
		return out;
	}
	else
	{
		while(m_head != nullptr && out == false)
		{
			if(curNode->getItem() == val){
				out = true;
				for(int i = 0; i < count; i++)
				{
					preNode = preNode->getNext();
				}
				preNode->setNext(curNode->getNext());
				curNode->setNext(nullptr);
				delete curNode;
				curNode = nullptr;
				m_count--;
				return out;
			}
			else
			{
				curNode = curNode->getNext();
				count++;
			}

		}
	}
	return out;
}

/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
    //TODO
	/*Node* curNode = new Node;
	Node* preNode = new Node;
	curNode = m_head->getNext();
	while(curNode->getNext() != NULL)
	{
		preNode = curNode;
		curNode = curNode->getNext();
		preNode->setNext(NULL);
		delete preNode;
	}*/
	m_count = 0;
	delete m_head;
	m_head = nullptr;
	
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	//TODO - maybe not depending on how you implement Node::~Node
	clear();
}

std::string PointerBasedLinkedList::toString() const
{
	//TODO
	string str = "";
	Node* newNode = m_head;
	while (newNode != nullptr)
	{
		if (newNode == m_head)
		{
			str += std::to_string(newNode->getItem());
		}
		else
		{
			str += " " + std::to_string(newNode->getItem());
		}
		newNode = newNode->getNext();
	} 
	
	return str;
}

ArrayBasedLinkedList::ArrayBasedLinkedList() : ILinkedList()
{
    m_count = 0;
}


bool ArrayBasedLinkedList::add(int val)
{
	//TODO
	if(val != 0){
		for(int i=0; i<= 10; i++){
			m_values[i] = val;
			m_count++;
			return true;
		}
	}
	else{
		return false;
	}
	return false;
}

bool ArrayBasedLinkedList::remove(int val)
{
	//TODO
	if(val != 0){
		for(int i=0; i <= 10; i++){
			if(m_values[i] == val){
				val = 0;
				m_values[10] = val;
				m_count--;
				return true;
			}
		}
	}
	else{
		return false;
	}
	return false;
}

void ArrayBasedLinkedList::clear()
{
	//TODO
	for(int i=0; i <= 10; i++){
		m_values[i] = 0;
	}
	m_count = 0;
}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{

}

std::string ArrayBasedLinkedList::toString() const
{
	//TODO
	string str = "";
	for(int i=0; i <= 10; i++){
		str = "m_values[i] ";
	}
	return str;
}
