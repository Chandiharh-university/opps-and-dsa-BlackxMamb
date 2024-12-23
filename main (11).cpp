#include <iostream>
#include <queue>

class Queue {
private:
    std::queue<int> elements; // Container for queue elements

public:
    // Enqueue an element into the queue
    void enqueue(int value) {
        elements.push(value);
        std::cout << "Enqueued: " << value << "\n";
    }

    // Dequeue an element from the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        std::cout << "Dequeued: " << elements.front() << "\n";
        elements.pop();
    }

    // Peek at the front element of the queue
    int front() const {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return -1; // Return a sentinel value
        }
        return elements.front();
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Get the size of the queue
    int size() const {
        return elements.size();
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front element: " << queue.front() << "\n";

    queue.dequeue();
    std::cout << "Front element after dequeue: " << queue.front() << "\n";

    queue.dequeue();
    queue.dequeue();
    queue.dequeue(); // Attempting to dequeue from an empty queue

    return 0;
}
