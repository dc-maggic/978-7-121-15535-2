#include <iostream>
class NoDefault {
public:
	NoDefault(int) {}

};
class C {
public:
	NoDefault member;
	C() :member(0) {}
};