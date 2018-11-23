#include <iostream>
#include <string>
typedef double Money;
std::string bal;
class Acount {
public:
	Money balance() { return bal; }
private:
	Money bal=2.0;
};
int height;
class Screen {
public:
	typedef std::string::size_type pos;
	Screen() = default;
	void dummy_fcn( pos heigth) {
		cursor = width * height;
		std::cout << cursor << std::endl;
	}
	void dummy_fcn2(pos height) {
		cursor = width * this->height;
		std::cout << cursor << std::endl;

	}
	void dummy_fcn3(pos height) {
		cursor = width * Screen::height;
		std::cout << cursor << std::endl;
	}
	void dummy_fcn4(pos ht) {
		cursor = width * height;
		std::cout << cursor << std::endl;
	}
	void dummy_fcn5(pos height) {
		cursor = width * ::height;
		std::cout << cursor << std::endl;
	}
private:
	pos cursor = 3;
	pos height = 1, width = 1;
};
int main()
{
	Acount balance();
	Screen x;
	x.dummy_fcn(9);
	x.dummy_fcn(2);
	x.dummy_fcn3(3);
	x.dummy_fcn4(4);
	x.dummy_fcn5(5);
	system("pause");
	return 0;
}