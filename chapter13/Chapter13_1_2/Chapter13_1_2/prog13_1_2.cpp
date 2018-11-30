#include <iostream>
#include <string>
#include <vector>
class Sales_data {
public:
	Sales_data() = default;
	Sales_data(const Sales_data&);
	Sales_data& operator=(const Sales_data &);
	~Sales_data();
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
	~Foo();//析构函数
};

int main()
{
	Sales_data trans, accum;
	trans = accum;//使用Sales_data的拷贝赋值运算符
	Sales_data *p = new Sales_data;//p是一个内置指针
	auto p2 = make_shared<Sales_data>();//p2是一个shared_ptr
	Sales_data item(*p);//拷贝构造函数将*p拷贝到item中
	vector<Sales_data> vec;//局部对象；
	vec.push_back(*p2);//拷贝p2指向的对象
	delete p;//对p指向的对象执行析构函数；
}