#include <iostream>
#include "practise15_21.h"
using namespace std;
int main()
{
	cout << "请输入长方形的长和宽： ";
	double x, y;
	cin >> x >> y;
	Rectangle rec(x, y);
	cout << " 周长： " << rec.perimeter() << " 面积： " << rec.area() << endl;
	cout << "请输入圆形的半径： ";
	cin >> x ;
	Circle cir(x);
	cout << " 周长： " << cir.perimeter() << " 面积： " << cir.area() << endl;
	cout << "请输入长方体的长宽高： ";
	double z;
	cin >> x >> y >> z;
	Cuboid cu(x, y, z);
	cout << " 面积： " << cu.area() << " 体积： " << cu.volume()<< endl;
	system("pause");
	return 0;
}