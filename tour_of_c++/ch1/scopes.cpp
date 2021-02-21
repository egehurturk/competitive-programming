#include <iostream>

using namespace std;

int a = 3; // global

struct Record {
	char *name;  // member scope 
};

int f(int x) { // f is global
	// x is local
	return x * x;
}

int main() {

}


// local -> enclosed by {}
// class 
// namespace 
// global -> not in any namespace & class & function & block
