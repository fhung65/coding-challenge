#include <iostream>
#include <stddef.h>
#include <vector>

#include "canvas.h"

void test_2() {
	Canvas c = Canvas(4,6, 'o');
	c.draw();
	std::cout << '\n';

	c.add_col(0, '1');
	c.draw();
	std::cout << '\n';

	c.add_col(0, '2');
	c.draw();
	std::cout << '\n';

	c.add_col(0, '3');
	c.draw();
	std::cout << '\n';

	c.add_col(10, '4');
	c.draw();
	std::cout << '\n';

	c.add_col(4, '5');
	c.draw();
	std::cout << '\n';

	c.add_row(0, 'a');
	c.draw();
	std::cout << '\n';

	c.add_row(0, 'b');
	c.draw();
	std::cout << '\n';

	c.add_col(4, '6');
	c.draw();
	std::cout << '\n';

	c.add_row(10, 'c');
	c.draw();
	std::cout << '\n';

	c.add_row(3, 'd');
	c.draw();
	std::cout << '\n';

	c.set(5,6, '@');
	c.draw();
	std::cout << '\n';
}

int main(int argc, char* argv[]) {

	test_2();

	return 0;
}
