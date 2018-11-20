#include <iostream>
#include <string>
#include "Sales_data.h"
std::istream &read(std::istream& is, Sales_data& s)
{
	is >> s.bookNo >> s.units_sold >> s.revenue;
	return is;
}
std::ostream &print(std::ostream& os, const Sales_data& s)
{
	os << s.bookNo << " " << s.units_sold << " " << s.revenue ;
	return os;
}
int main()
{
	using namespace std;
	Sales_data total;
	if (read(cin,total)) {
		Sales_data trans;
		while (read(cin,trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout,total)<< endl;
				total = trans;
			}
		}
		print(cout,total)<< endl;
	}
	else {
		cerr << "No data?!" << endl;
	}
	system("pause");
	return 0;
}