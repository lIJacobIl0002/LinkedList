#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include<iostream>

class LinkedList { // integer based LinkedList
	private:
		struct Node {
			int item;
			Node* next; // next node
			Node* prev; // previous node

			Node(int item, Node* next=nullptr, Node* prev=nullptr) : item(item), next(next), prev(prev) {}

		};
		Node* head; // start of the linked list
		Node* tail; // end of the linked list
		size_t size; // size of the linked list

	public:
		LinkedList() : head(nullptr), tail(nullptr), size(0) {}
		~LinkedList() {
			clear();
		}
		
		// add element to the right
		// 
		void push(int value) { // O(1)

			if(this->head == nullptr) {
				Node* new_node = new Node(value);

				this->head = new_node;
				this->tail = new_node;
			} else {
				this->tail->next = new Node(value, nullptr, this->tail); 
				this->tail = this->tail->next;
			}

			if(this->head->next == nullptr && this->tail != this->head)
				this->head->next = this->tail;

			size++;
		}

		// LinkedList size
		// @returns size of linked list
		size_t get_size() { 
			return this->size;
		}

		// searchs for specified element in the linked list 
		// @return true if found else false
		bool search(int value) { // search for value
			// O(1) best case. O(n) worse case
			Node* headTemp = this->head;
			Node* tailTemp = this->tail;

			while(headTemp->next != tailTemp && headTemp->prev != tailTemp) {
				if(headTemp->item == value || tailTemp->item == value)
					return true;

				headTemp = headTemp->next;
				tailTemp = tailTemp->prev;
			}

			return false;
		}

		// clear and free all nodes
		void clear() { // O(n)
			if(head == nullptr) return;

			Node* temp;

			while(this->head) {
				temp = this->head->next;
				delete head;
				head = temp;	
			}
		
			head = nullptr;
			tail = nullptr;
			size = 0;
		}
		
		// add element to the left of the list
		void pushleft(int value) { // O(1)
			if(head == nullptr)
				throw std::runtime_error("Empty linked list");

			if(this->head == nullptr) {
				Node* new_node = new Node(value);

				this->head = new_node;
				this->tail = new_node;

			} else {
				this->head->prev = new Node(value, this->head);
				this->head = this->head->prev;
			}

			size++;
		}

		// remove element on the left
		// @returns popped element 
		int popleft() { // O(1)
			if(head == nullptr)
				throw std::runtime_error("Empty linked list");

			Node* current = this->head;
			int value = current->item;

			this->head = this->head->next;
			
			delete current;
			size--;

			return value;
		}

		int pop() { // O(1)
			if(head == nullptr)
				throw std::runtime_error("Empty Linked list");

			Node* current = this->tail;
			int value = current->item;

			this->tail = this->tail->prev;
			this->tail->next = nullptr;

			delete current;
			size--;

			return value;
		}

		// display elements in the format of `0 -> 1 -> 2 -> nullptr;`
		void display() { // O(n)
			if(head == nullptr)
				throw std::runtime_error("Empty Linked list");

			Node* current = this->head;

			while(current) {
				std::cout << current->item << " -> ";
				current = current->next;
			}

			std::cout << "nullptr;\n";
		}

		// no idea why I added this LOL
		void displayleft() { // O(n)
			if(tail == nullptr)
				throw std::runtime_error("Empty Linked list");

			Node* current = this->tail;

			while(current) {
				std::cout << current->item << " -> ";
				current = current->prev;
			}

			std::cout << "nullptr;\n";
		}

};

#endif
/*int main() {
	LinkedList x = LinkedList();
	
	x.push(2);
	x.pushleft(1);
	x.push(3);
	x.pushleft(0);
	x.pushleft(-1);

	x.display();
	std::cout << x.search(0);
	//std::cout << x.get_size();
}*/
