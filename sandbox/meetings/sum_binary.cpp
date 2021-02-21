#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;



vector<int> carry_sum(vector<int> A, vector<int> B) {
	int n = max(A.size(), B.size());
	vector<int> C(n+1, 0);
	int carry = 0;
	for (int i = n; i > 0; i--) {
		C[i+1] = (A[i] + B[i] + carry) % 2;
		if (A[i] + B[i] + carry >= 2) 
			carry = 1;
		else
			carry = 0;
	}
	C[0] = carry;
	return C;
}

int main(void) {
	vector<int> A {1, 0, 1, 1}; // 11
	vector<int> B {0, 0, 1, 1}; // 3
	// 1 0 0 1 0 18
	vector<int> C = carry_sum(A, B);
	for (vector<int>::iterator i = C.begin(); i != C.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}