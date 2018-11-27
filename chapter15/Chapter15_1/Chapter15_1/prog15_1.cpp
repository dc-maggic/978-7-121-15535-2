#include <iostream>
class Quote {
public:
	std::string isbn() const;
	virtual double net_price(std::size_t b) const;
};
class Bulk_quote : public Quote {
public:
	double net_price(std::size_t) const override;
};
double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << n << " total due:: " << ret << std::endl;
	return ret;
}