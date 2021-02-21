double sqrt(double);

class Vector {
public: 
	Vector(int s);				// only interface
	double& operator[](int i);	// only interface
	int size();					// omly interface
private:
	double* elem;
	int sz;
};

int main(void) {

}

double sqrt(double d) {
	// algorithm ...
	return 0.0;
}

// Definition of class functions:
Vector::Vector(int s)
	:elem{new double[s]}, sz{s}
{

}

double& Vector::operator[](int i) { // definition
	return elem[i];
}

int Vector::size() { // definition
	return sz;
}

