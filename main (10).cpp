#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> elements; // Container for stack elements

public:
    // Push an element onto the stack
    void push(int value) {
        elements.push_back(value);
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        elements.pop_back();
    }

    // Peek at the top element of the stack
    int top() const {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return -1; // Return a sentinel value
        }
        return elements.back();
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Get the size of the stack
    int size() const {
        return elements.size();
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << "\n";

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << "\n";

    stack.pop();
    stack.pop();
    stack.pop(); // Attempting to pop from an empty stack

    return 0;
}
