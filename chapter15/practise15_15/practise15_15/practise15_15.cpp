#include <iostream>
#include <string>
class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double p):bookNo(book),price(p){}
	virtual double net_price(std::size_t n) const { return n*price; }
	//在基类中的虚函数 net_price 必须被定义防止后面的派生类无法使用
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Disc_quote :public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double p, std::size_t qty, double disc) :Quote(book, p), quantity(qty), discount(disc) {}
	double net_price(std::size_t n) const=0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};
class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :Disc_quote(book, p, qty, disc) {}
	double net_price(std::size_t n) const override;
private:

};
double Bulk_quote::net_price(std::size_t n) const
{
	if (n > quantity)
		return n * (1 - discount)*price;
	else
		return n*price;
}
int main()
{
	Bulk_quote test;
	system("pause");
	return 0;
}