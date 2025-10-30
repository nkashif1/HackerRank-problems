#include <cmath>
#include <cstdio>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;
public:
    void enqueue(int x)
    {
        s1.push(x);
    }
    void dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
            }
        }
        if (!s2.empty()) s2.pop();
    }

    int front() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
};



int main() {
     int q;
    cin >> q; // number of queries
    QueueUsingStacks queue;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            queue.enqueue(x);
        } else if (type == 2) {
            queue.dequeue();
        } else if (type == 3) {
            cout << queue.front() << endl;
        }
    }
    return 0;
}
