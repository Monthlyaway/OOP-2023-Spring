#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
class LoopQueue {
public:
    typedef typename vector<T>::size_type size_type;
    LoopQueue(int capacity) : data(capacity) {
        first = last = 0;
    }
    bool isEmpty() const { return first == last; }
    bool isFull() const { return (last + 1) % data.size() == first; }
    size_type getLength() const {
        if (last >= first) {
            return last - first;
        }
        return data.size() - first + last;
    }
    bool dequeue(T& e) {
        if (isEmpty())
            return false;

        e = data[first];
        first = (first + 1) % data.size();
        return true;
    }
    bool enqueue(const T& e) {
        if (isFull()) 
            return false;

        data[last] = e;
        last = (last + 1) % data.size();
        return true;
    }
    void print() {
        size_type i;
        cout << "Print Queue£º";
        for (i = first; i != last; i = (i + 1) % data.size()) {
            cout << data[i] << ' ';
        }
        cout << endl;
    }
private:
    vector<T> data;
    size_type first, last;
};

int main() { 
    int a;
    LoopQueue<int> qu(3);
    for (int i = 1; i < 6; i++) {
        qu.enqueue(i);
        qu.print();
    }
    qu.dequeue(a);
    qu.print();

    cout << qu.getLength() << endl;
    qu.enqueue(a);
    qu.print();

    cout << qu.getLength() << endl;
    return 0;
}
