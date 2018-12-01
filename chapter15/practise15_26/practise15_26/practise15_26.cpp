#include<iostream>
#include<string>
class Quote {
public:
	Quote() = default;
	std::string isbn() const { return bookNo; }
	virtual ~Quote() { std::cout << "Quote's destructor." << std::endl; };
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual void debug() const;
	Quote(const std::string &book, double p) :bookNo(book), price(p) { std::cout << "Quote's constructor." << std::endl; }
	//拷贝函数
	Quote(const Quote&eg) :bookNo(eg.bookNo), price(eg.price) { std::cout << "Quote's copy constructor." << std::endl; }
	//拷贝构造函数
	Quote& operator=(const Quote &eg) {
		std::cout << "Quote's synthesized copy_assignment operator" << std::endl;
		bookNo = eg.bookNo,
			price = eg.price;
		return *this;
	}
	//拷贝赋值运算符
protected:
	std::string bookNo;
	double price = 0;
};
void Quote::debug() const {
	std::cout << "bookNo=" << isbn() << " price= " << price << std::endl;
}

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double price, std::size_t qty, double disc) :
		Quote(book, price), qty(qty), discount(disc)
	{
		std::cout << "Disc_quote's constructor." << std::endl;
	}
	Disc_quote(const Disc_quote& eg) :Quote(eg), qty(eg.qty), discount(eg.discount) {
		std::cout << "Disc_quote's synthesized copy constructor." << std::endl;
	}
	Disc_quote& operator=(const Disc_quote &eg) {
		std::cout << "Disc_quote's synthesized copy_assignment operator" << std::endl;
		Quote::operator=(eg);
		discount = eg.discount;
		qty = eg.qty;
		return *this;
	}
	double net_price(std::size_t) const = 0;
	~Disc_quote() { std::cout << "Disc_quote's destructor." << std::endl; }
protected:
	std::size_t qty = 0; //折扣使用的购买量
	double discount = 0;  //折扣的小数值
};

class Bulk_quote :public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string book, double p, std::size_t qty, double dis) :
		Disc_quote(book, p, qty, dis)
	{
		std::cout << "Bulk_quote's constructor." << std::endl;
	}
	Bulk_quote(const Bulk_quote &eg) :Disc_quote(eg)
	{
		std::cout << "Bulk_quote's copy constructor." << std::endl;
	}
	Bulk_quote& operator=(const Bulk_quote &eg) {
		std::cout << "Bulk_quote's synthesized copy_assignment operator" << std::endl;
		Disc_quote::operator=(eg);
		return *this;
	}
	double net_price(std::size_t n) const override {
		if (n > qty)
			return n * price*(1 - discount);
		else
			return n * price;
	}
	~Bulk_quote() { std::cout << "Bulk_quote's destructor." << std::endl; }
protected:
	double discount = 0.0;
	std::size_t qty = 0;
};
int main()
{
	Bulk_quote ex1("123-456-78", 8.0, 10, 0.2);
	Bulk_quote ex2("123-456-78", 19.0, 10, 0.2);
	Bulk_quote ex3 = ex2;
	ex2 = ex1;
	std::cout << std::endl;
	ex3 = ex1;
	system("pause");
	return 0;
}