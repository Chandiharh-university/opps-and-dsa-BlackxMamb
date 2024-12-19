#include <iostream>
class Counter {
private:
    int count;

public:
    Counter(int c = 0) : count(c) {}
    int getCount() const {
        return count;
    }

    void increment() {
        count++;
    }
};
void processCounter(Counter counter) {
    static int staticCallCount = 0; 
    staticCallCount++;

    counter.increment();
    
    std::cout << "Counter value (local copy): " << counter.getCount() << std::endl;
    std::cout << "Static call count: " << staticCallCount << std::endl;
}

int main() {
    Counter myCounter(5); 
    
    processCounter(myCounter);
    processCounter(myCounter);
    processCounter(myCounter);

    std::cout << "Original Counter value: " << myCounter.getCount() << std::endl;

    return 0;
}
using static keyword and pass by value and user defined