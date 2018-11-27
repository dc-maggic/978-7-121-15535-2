#include <iostream>
#include <string>
class Quote {
public:
	virtual ~Quote() = default;
	std::string isbn() const { return bookNo; }
	Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price) {}
	virtual double net_price(std::size_t n) const { return n * price; }
protected:
	double price = 0.0;
private:
	std::string bookNo;
};
class bulk_quote : public Quote{
public:
	double net_price(std::size_t n) const { return n * price; }
};
double print_total(std::ostream &os, const Quote item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
} 