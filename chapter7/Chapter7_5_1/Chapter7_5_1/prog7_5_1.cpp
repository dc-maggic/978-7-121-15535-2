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
	Sales_data(std::string s = "") :bookNo(s) {}
	Sales_data(std::string s, unsigned cnt, double rev) :bookNo(s), units_sold(cnt), revenue(rev*cnt) {}
	Sales_data(std::istream &is) { read(is, *this); }
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