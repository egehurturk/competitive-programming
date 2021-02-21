#include <iostream>
#include <vector>

using namespace std; 

enum class Color{red, blue, green};

enum class Traffic_Light{green, yellow, red};

int main(void) {
	Color col = Color::red;
	Traffic_Light light = Traffic_Light::red;
}

// Color::red is different from Traffic_Light::red
// enum class -> means  enum is strongly typed and scoped

