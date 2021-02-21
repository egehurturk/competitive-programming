#include <iostream>
#include <vector>

using namespace std; // make names from std visible withoud std::

double square(double); // or double square(double d);
void print_square(double);


void some_function() {
	double d = 2.2; // floating point number
	int i = 7; // integer
	cout << d << i << endl;
	d = d+i; // assign sum to d;
	cout << d << endl;
	i = d*i; // assign product to i;
	cout << i << endl;
	cout << d << i << endl;
}

void initialization_test() {
	// it works?
	double d1 = 2.3; // initialize d1 to 2.3
	double d2 {2.3}; // intialize d2 to 2.3
	vector<int> v {1,2,3,4,5,6};
	cout << d1 << endl;
	cout << d2 << endl;
}

void auto_() {
	// auto: variable type can be deduced from initializer
	auto b = true;
	auto ch = 'x';
	auto y = 25;
	auto z = sqrt(y);
	cout << b << endl;
	cout << ch << endl;
	cout << y << endl;
	cout << z << endl;
}

int main() {
	// print_square(1.234);
	#if __cplusplus == 201402L
    	std::cout << "C++14" << std::endl;
	#elif __cplusplus==201103L
    	std::cout << "C++11" << std::endl;
	#endif
	// initialization_test();
	// cout << "the size of a char is " << sizeof(char) << endl;
	// cout << "the size of an int is " << sizeof(int) << endl;
	// cout << "the size of a double is " << sizeof(double) << endl;
	auto_();

}

double square(double x) {
	return x * x;
}

void print_square(double x) {
	cout << "the square of " << x << " is " << square(x) << endl;
}