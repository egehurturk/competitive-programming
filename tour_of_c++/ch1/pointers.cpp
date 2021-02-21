#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

void sort(const vector<double>& v); 

void null_ptr() {
	double *d = nullptr;
	// nullptr is a safe null pointer
	if (d == nullptr) 
		cout << "Null" << endl;

	
}

int count_x(char* p, char x) {
	if (p == nullptr) return 0;
	int count = 0;
	for (; p != nullptr; ++p)
			if (*p == x)
					++count;
	return count;
}

int count_x_new(char* p, char x) {
	int count = 0;
	while (p) {				// while(p) == while(p != nullptr)
		if (*p == x)
			++count;
		++p;
	}
	return count;
}

void copy_fct() {
	int v1[10] = {0,1,2,3,4,5,6,7,8,9};
	int v2[10];

	for (auto i = 0; i != 10; i++) {
		v2[i] = v1[i];
	}

	// OR

	for (auto x: v) 
		cout << x << endl;

	// OR

	for (auto x: {10,21,32,43,54,65} ) 
		cout << x << endl;

	int j[] = {0,1,2,3,4,5,6,7,8,9};
	for (auto& x: j)
		++x;

	// & means reference

}

int main() {
	char v[6]; // array of 6 characters
	char* p; // pointer to a character

	// [] -> array of , * -> pointer to
	// size of an array is constant
	
	char* j = &v[3]; // j points to the 4th element of v
	char x = *j; 

	// prefix * means contents of
	// prefix & means address of 
}


// in DECLERATION, & means reference to
// reference is similar to pointer, no need to use * to access


/*


T a[n]; -> array of n Ts

T* p;   -> pointer to T

T& r; 	-> reference to T

T f(A); -> function taking argument A returning Ts


*/



