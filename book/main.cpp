#include <iostream>

int main(){

	int x = 0;
	int y = 43;
	auto qqq = [x, &y]{

		std::cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;
		++y;
	};
	x = y = 77;
	qqq();
	qqq();
	return 0;

}
