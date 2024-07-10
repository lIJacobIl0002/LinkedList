#include "src/LinkedList.hpp"

int main() {
	LinkedList<int> list;

	list.push(1); // 1 -> nullptr;
	list.push(2); // 1 -> 2 -> nullptr;
	list.pushleft(0); // 0 -> 1 -> 2 -> nullptr;

	if(list.search(1))
			std::cout << "found 1 in x\n";

	list.display(); // 0 -> 1 -> 2 -> nullptr;

	int value = list.pop(); // 2

	int value2 = list.popleft(); // 0

	std::cout << value << ' ' << value2 << '\n';

	list.clear(); // will be called when list is destructed

    return 0;
}
