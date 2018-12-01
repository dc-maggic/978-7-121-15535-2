#include <iostream>
#include <string>
class Sales_data {
public:
	Sales_data() = default;
	Sales_data(const Sales_data&);
	Sales_data& operator=(const Sales_data &);
private:
	std::string bookNo;
	int units_sold = 0;
	double revenue = 0.0;
};
Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
	bookNo = rhs.bookNo;//调用string::operator
	units_sold = rhs.units_sold;//使用内置int
	revenue = rhs.revenue;//使用内置double
	return *this;
}

class Foo {
public:
	Foo();//默认构造函数
	Foo(const Foo&);//拷贝构造函数
	Foo& operator=(const Foo&);//赋值运算符
};

int main()
{
	Sales_data trans, accum;
	trans = accum;//使用Sales_data的拷贝赋值运算符
}