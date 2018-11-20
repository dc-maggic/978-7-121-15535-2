
#include <iostream>
#include <string>
using namespace std;
struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
int main()
{
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
		{
			if (total.bookNo == trans.bookNo)
			{
				total.revenue = total.revenue * total.units_sold + trans.revenue * trans.units_sold;
				total.units_sold += trans.units_sold;
			}
			else
			{
				cout << total.bookNo <<" "<< total.units_sold << " " <<total.revenue << endl;
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