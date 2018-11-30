#include<iostream>
#include<string>
class Foo {
public:
	Foo();//默认构造函数
	Foo(const Foo&);//拷贝构造函数
};
class Sales_data {
public:
	Sales_data(const Sales_data&);
private:
	std::string bookNo;
	int units_sold = 0;
	double revenue = 0.0;
};
Sales_data::Sales_data(const Sales_data &orig) :
	bookNo(orig.bookNo), units_sold(orig.units_sold), revenue(orig.revenue) {}
//使用string的拷贝构造函数，拷贝orig.units_sold，拷贝Orig.revenue
int main()
{
	using namespace std;
	string dot(10, '.');//直接初始化
	string s(dot);//直接初始化
	string s2 = dot;//直接拷贝初始化
	string null_book = "9-999-99999-9";//拷贝初始化
	string nines = string(100, '9');//拷贝初始化
}