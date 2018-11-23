#include <iostream>
#include <string>
class ConstRef {
public:
	ConstRef(int il);
private:
	int i;
	const int ci;
	int &ri;
};
ConstRef::ConstRef(int il) :i(il), ci(il), ri(i) {}
class Sales_data {
	friend std::istream &read(std::istream&, Sales_data&);
public:
	//��ί�й��캯��ʹ�ö�Ӧ��ʵ�γ�ʼ����Ա
	Sales_data(std::string s, unsigned cnt, double price) :bookNo(s), units_sold(cnt), revenue(price*cnt) {}
	//	Sales_data(std::istream &is = std::cin) { read(is, *this); }
	//���๹�캯��ȫ��ί�и���һ�����캯����
	Sales_data() :Sales_data("", 0, 0) { std::cout << "finish Sales_data()" << std::endl; }
	Sales_data(std::string s) :Sales_data(s, 0, 0) { std::cout << "finish Sales_data(std::string s)" << std::endl; }
	Sales_data(std::istream &is ) {
		read(is, *this);
		std::cout << "finish Sales_data(std::&istream &is)" << std::endl;
	}
private:
	std::string bookNo;
	double revenue;
	unsigned units_sold;

};
std::istream &read(std::istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
int main()
{
	Sales_data example1;
	Sales_data example2("123456");
	Sales_data example3(std::cin);
	system("pause");
	return 0;
}