#include "src/LinkedList.hpp"

int main() {
    LinkedList x;

    x.push(1); // 1 -> nullptr;
    x.push(2); // 1 -> 2 -> nullptr;
	x.pushleft(0); // 0 -> 1 -> 2 -> nullptr;

    if(x.search(1))
        std::cout << "found 1 in x\n";

    x.display(); // 0 -> 1 -> nullptr;

    int value = x.pop(); // 2

    int value2 = x.popleft(); // 0

    x.clear();

    return 0;
}
