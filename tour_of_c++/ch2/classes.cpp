#include <iostream>
#include <vector>

using namespace std; 

class Vector {
public:
	Vector(int s) :elem{new double[s]}, sz{s} {} // construct a vector
	double& operator[](int i) {
		return elem[i]; 
	}
	int size() {return sz;}

private:
	double *elem; // pointer to elements
	int sz;
};

double read_and_sum(int s);

int main() {
	cout << read_and_sum(5) << endl;
}

double read_and_sum(int s) {
	Vector v(s); // Vector(int s)
	for (int i = 0; i != v.size(); i++) {
		cin >> v[i]; // operator[](int i)
	}

	double sum = 0;
	for (int i = 0; i != v.size(); i++) 
		sum += v[i];
	return sum;
}