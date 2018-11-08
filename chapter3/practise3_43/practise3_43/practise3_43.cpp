#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::begin;
using std::end;
int main() {
	int ia[3][4] = {
		{0,1,2,3},
	{4,5,6,7},
	{8,9,10,11}
	};
	//���ͱ���
	using int_array = int[4];
	//����������̣�
	for (int (&row)[4] : ia) {
		for (int &col : row)
			cout << col << " ";
		cout << endl;
	}
	cout << endl;
	//�±������
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			cout << ia[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//ָ��
	for (int (*p)[4] = begin(ia); p != end(ia); ++p) {
		for (int (*q) = begin(*p); q != end(*p); ++q)
			cout << *q << " ";
		cout << endl;
	}
	system("pause");
}