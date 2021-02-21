#include <iostream>
#include <vector>

using namespace std; 

enum Type {str, num};

union Value {
	char *s;
	int i;
};


struct Entry {
	char *name;
	Type t;
	Value v; // use if v.s if t == str; use v.i if t == num
};
// members s and i can never be used at the same time




void f(Entry *p) {
	if (p->t == str) {
		cout << p->v.s << endl;
	}
}

