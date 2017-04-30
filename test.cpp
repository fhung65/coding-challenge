#include <iostream>
#include <stddef.h>
#include <vector>

#include "pixel.h"
#include "canvas.h"


void test_2() {
	Canvas c = Canvas(4,5,'\0');
	c.draw();
	std::cout << '\n';
	c.add_row(4, '1');
	c.draw();
	std::cout << '\n';
	c.add_row(0, '2');
	c.draw();
	std::cout << '\n';
	c.add_row(1, '3');
	c.draw();
	std::cout << '\n';
	c.add_row(10, '4');
	c.draw();
	std::cout << '\n';

	c.add_col(4, 'a');
	c.draw();
	std::cout << '\n';

	c.add_col(6, 'b');
	c.draw();
	std::cout << '\n';

	c.add_col(0, 'c');
	c.draw();
	std::cout << '\n';

	c.add_row(0, '0');
	c.draw();
	std::cout << '\n';
}

int main(int argc, char* argv[]) {

	test_2();

	return 0;
}
