#include<iostream>
#include<string>
class Foo {
public:
	Foo();//Ĭ�Ϲ��캯��
	Foo(const Foo&);//�������캯��
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
//ʹ��string�Ŀ������캯��������orig.units_sold������Orig.revenue
int main()
{
	using namespace std;
	string dot(10, '.');//ֱ�ӳ�ʼ��
	string s(dot);//ֱ�ӳ�ʼ��
	string s2 = dot;//ֱ�ӿ�����ʼ��
	string null_book = "9-999-99999-9";//������ʼ��
	string nines = string(100, '9');//������ʼ��
}