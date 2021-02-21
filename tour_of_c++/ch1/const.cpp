#include <iostream>
#include <vector>
using namespace std;

double sum(const vector<double>&); // sum will not modify argument

vector<double> v {1.2, 3.4, 4.5};



double square_(double x) {
	return x * x;
}

int main() {
	// two types of immutability: const, constexpr
	const int dmv = 17; 		// named constant
	int var = 17;				// var is not a constant

	constexpr double max1 = 1.4 * square_(dmv);	// OK if square(17) is a constant expression
	constexpr double max2 = 1.4 * square_(var); 	// ERROR: var is not a constant expression
	const double max3 = 1.4 * square_(var); 		// OK, may be evaluated at runtime
	return 0;
}


double sum(const vector<double>& v) {
	double sum = 0;
	for (auto it = v.begin(); it != v.end(); it++) {
		sum += *it;
	}
	return sum;
}

