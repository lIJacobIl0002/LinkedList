#include<iostream>

class LinkedList { // integer based LinkedList
	private:
		struct Node {
			int item;
			Node* next; // next node
			Node* prev; // previous node

			Node(int item, Node* next=nullptr, Node* prev=nullptr) : item(item), next(next), prev(prev) {}

		};
		Node* head;
		Node* tail;
		size_t size;

	public:
		LinkedList() : head(nullptr), tail(nullptr), size(0) {}
		~LinkedList() { // free all the Nodes
			clear();
		}

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

		size_t get_size() {
			return this->size;
		}

		// O(1) best case. O(n) worse case
		bool search(int value) { // search for value
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
		
		void clear() { // O(n)
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

		void pushleft(int value) { // O(1)

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

int main() {
	LinkedList x = LinkedList();
	
	x.push(2);
	x.pushleft(1);
	x.push(3);
	x.pushleft(0);
	x.pushleft(-1);

	x.display();
	std::cout << x.search(0);
	//std::cout << x.get_size();
}
