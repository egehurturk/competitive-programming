#include <cstdio>
#include <stack> // for stacks
#include <queue>

using namespace std;

int main() {
    stack<char> s; // create a stack of chars
    queue<char> q; // create queue of chars
    deque<char> d; // create dequeue of chars

    printf("%d\n", s.empty()); // if s is empty, return 1
    
    // insert elements into stack
    s.push('a');
    s.push('b');
    s.push('c');
    // stacks are LIFO, thus
    // c <- top
    // b
    // a
    printf("%c\n", s.top()); // top value of queue
    s.pop(); // remove first element
    printf("%c\n", s.top());
    printf("%d\n", s.empty()); // stack is not-empty

    // queue
    printf("%d\n",  q.empty());
    while (!s.empty()) {
        q.push(s.top()); // enqueue b and then a
        s.pop();
    }
    q.push('z'); 
    printf("%c\n", q.front()); // print the front one
    printf("%c\n", q.back()); // print the back one

    while (!q.empty()) {
        printf("%c\n", q.front());
        q.pop();
    }

    d.push_back('a'); // pushes element to the back
    d.push_back('b');
    d.push_back('c');

    printf("%c - %c\n", d.front(), d.back());               // prints 'a - c'
    d.push_front('d');
    printf("%c - %c\n", d.front(), d.back());               // prints 'd - c'
    d.pop_back();
    printf("%c - %c\n", d.front(), d.back());               // prints 'd - b'
    d.pop_front();
    printf("%c - %c\n", d.front(), d.back());     
}