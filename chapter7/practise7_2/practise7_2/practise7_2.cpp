#include <iostream>
#include <string>
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
};
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
int main()
{
	using namespace std;
	Sales_data total;
	if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {
		Sales_data trans;
		while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
		{
			if (total.bookNo == trans.bookNo)
			{
				total.revenue = total.revenue * total.units_sold + trans.revenue * trans.units_sold;
				total.units_sold += trans.units_sold;
			}
			else
			{
				cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
				total = trans;
			}
		}
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
	}
	else
	{
		cout << "请输入书本的序号、数量、价格" << endl;
		return -1;
	}
	system("pause");
	return 0;
}