#include <iostream>
#include "practise15_21.h"
using namespace std;
int main()
{
	cout << "�����볤���εĳ��Ϳ� ";
	double x, y;
	cin >> x >> y;
	Rectangle rec(x, y);
	cout << " �ܳ��� " << rec.perimeter() << " ����� " << rec.area() << endl;
	cout << "������Բ�εİ뾶�� ";
	cin >> x ;
	Circle cir(x);
	cout << " �ܳ��� " << cir.perimeter() << " ����� " << cir.area() << endl;
	cout << "�����볤����ĳ���ߣ� ";
	double z;
	cin >> x >> y >> z;
	Cuboid cu(x, y, z);
	cout << " ����� " << cu.area() << " ����� " << cu.volume()<< endl;
	system("pause");
	return 0;
}