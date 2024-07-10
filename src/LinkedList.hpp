#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

template <typename T>
class LinkedList {
public:
	struct Node {
		T item;

		Node* next;
		Node* prev;

		Node(T item) : item(item),
				next(nullptr), prev(nullptr)
		{}
	};

	class EmptyLinkedList : public std::exception {
	private:
		const char* msg;

	public:
		EmptyLinkedList(const char* msg) : msg(msg) {}

		const char* what() const noexcept override {
			return msg;
		}

	};

	LinkedList();
	~LinkedList();

	//push a value into the linked list
	void push(T val);

	//push a value on the left side of the linked list
	void pushleft(T val);

	//search for a value in the linked list
	bool search(T val);

	//remove and return the first item (on the right side)
	T pop();

	//remove and return the first item (on the left side)
	T popleft();

	//display the linked list (in this order: 1 -> 2 -> nullptr);
	void display();

	//reverse the linked list
	void reverse();

	//empty the linked list (will be cleared regardless once destructed)
	void clear();

	//get linked list size
	size_t get_size();

	// get linked list head
	Node* get_head();

	// get linked list tail
	Node* get_tail();

private:
	Node* head;
	Node* tail;
	size_t size;
};

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
LinkedList<T>::~LinkedList() {
	clear();
}

template<typename T>
void LinkedList<T>::push(T val) { // O(1)
	Node* node = new Node(val);

	if(!head) {
		head = node;
		tail = node;

	} else {
		tail->next = node;
		node->prev = tail;
		tail = tail->next;
	
	}

	size++;
}

template<typename T>
void LinkedList<T>::pushleft(T val) { // O(1)
	Node* node = new Node(val);

	if(!head) {
		head = node;
		tail = node;

	} else {
		node->next = head;
		head->prev = node;
		head = node;

	}

	size++;
}

template<typename T>
bool LinkedList<T>::search(T val) { // O(n)
	Node* cur = head;
	while(cur) {
		if(cur->item == val)
			return true;

		cur = cur->next;
	}
	return false;
}

template<typename T>
T LinkedList<T>::pop() { // O(1)
	if(size == 0)
		throw EmptyLinkedList("self explanatory lol");

	T item = tail->item;
	Node* cur = tail;

	tail = tail->prev;
	tail->next = nullptr;

	delete cur;
	size--;

	return item;
}

template<typename T>
T LinkedList<T>::popleft() { // O(1)
	if(size == 0)
		throw EmptyLinkedList("self explanatory lol");

	T item = head->item;
	Node* cur = head;

	head = head->next;
	head->prev = nullptr;

	delete cur;
	size--;

	return item;
}

template<typename T>
void LinkedList<T>::display() { // O(n)
	Node* current = head;
	while(current) {
		std::cout << current->item << " -> ";
		current = current->next;
	}

	std::cout << "nullptr\n";
}

template<typename T>
void LinkedList<T>::reverse() { // O(n/2) or O(n)
	Node* left = head;
	Node* right = tail;
	T temp;
	
	int start = 0;

	while(start < (size/2)) {
		temp = left->item;

		left->item = right->item;
		right->item = temp;
		
		start++;
		left = left->next;
		right = right->prev;
	}

}

template<typename T>
void LinkedList<T>::clear() { // O(n)
	if(size == 0) return;

	Node* next;
	while(head) {
		next = head->next;
		delete head;

		head = next;
	}

	head = nullptr;
	tail = nullptr;
	size = 0;
};

template<typename T>
size_t LinkedList<T>::get_size() {
	return size;
}

template<typename T>
LinkedList<T>::Node* LinkedList<T>::get_head() {
	return head;
}

template<typename T>
LinkedList<T>::Node* LinkedList<T>::get_tail() {
	return tail;
}

#endif
