#include <iostream>
#include <vector>

using namespace std; 
struct Vector {
	int sz;			// fields
	double *elem;	// fields
};


void vector_init(Vector&, int);


int main(void) {
	//
}


/**
 * We use (.) to access struct members from a name and reference
 * We use (->) to access struct members from a pointer
 */
void f(Vector v, Vector& rv, Vector* pv) {
	int i1 = v.sz; // access through name
	int i2 = rv.sz; // access through reference
	int i4 = pv->sz; // access through pointer
}

double read_and_sum(int s) {
	Vector v;
	vector_init(v, s);
	for (int i = 0; i != s; ++i) 
		cin >> v.elem[i];

	double sum = 0;
	for (int i = 0; i != s; ++i) 
		sum += v.elem[i];
	return sum;

}

void vector_init(Vector& v, int s) {
	v.elem = new double[s]; // allocate array of doubles
	v.sz = s;
	// new allocates memory from heap (same as malloc)
}