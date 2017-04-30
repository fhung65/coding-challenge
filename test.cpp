#include <iostream>
#include <stddef.h>

#include "pixel.h"
//#include "canvas.h"

void test_1() {
	Pixel p = Pixel('0');
	Pixel* c = &p;
	Pixel* r = &p;

	p.mesh(3,4);

	while (r != NULL) {
		c = r;
		while (c != NULL) {
				std::cout << c->val;
			c = c->right;
		}
		std::cout << '\n';
		r = r->down;
	}
}

int main(int argc, char* argv[]) {
	test_1();

	std::cout << "hello world\n";
	return 0;
}
