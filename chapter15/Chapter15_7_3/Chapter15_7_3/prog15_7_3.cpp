#include <iostream>
class B {
};
class D : public B {
public:
	D(const D& d) :B(d) {}
	D(D&& d) :B(std::move(d)) {}
};