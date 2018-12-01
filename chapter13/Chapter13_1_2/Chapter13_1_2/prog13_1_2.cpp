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
	bookNo = rhs.bookNo;//����string::operator
	units_sold = rhs.units_sold;//ʹ������int
	revenue = rhs.revenue;//ʹ������double
	return *this;
}

class Foo {
public:
	Foo();//Ĭ�Ϲ��캯��
	Foo(const Foo&);//�������캯��
	Foo& operator=(const Foo&);//��ֵ�����
};

int main()
{
	Sales_data trans, accum;
	trans = accum;//ʹ��Sales_data�Ŀ�����ֵ�����
}