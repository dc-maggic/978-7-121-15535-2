#include <iostream>
#include <memory>
#include<string>
#include<vector>
using namespace std;

int main()
{
	shared_ptr<string> p1;//shared_ptr������ָ�� string
	shared_ptr<int>p2;//shared_ptr������ָ�� int
	if (p1&&p1->empty())//���p1��Ϊ�գ�������Ƿ�ָ��һ���� string��
		*p1 = "hi";//���p1ָ��һ����string��������p1����һ����ֵ���� string��
	shared_ptr<int>p3 = make_shared<int>(42);//ָ��һ��ֵΪ42�� int �� shared_ptr��
	shared_ptr<string>p4 = make_shared<string>(10, '9');//ָ��һ��ֵΪ"9999999999"�� string��
	shared_ptr<int>p5 = make_shared<int>();//ָ��һ��ֵ��ʼ���� int������ֵΪ0��
	//ʹ�� auto ����һ������������ make_shared �Ľ��
	auto p6 = make_shared<vector<string>>();//ָ��һ����̬����Ŀյ� vector<string>��
	//�����͸�ֵ��
	auto p = make_shared<int>(42);//p ָ��Ķ���ֻ�� p һ�������ߣ�
	auto q(p);//p �� q ָ����ͬ���󣬴˶��������������ߣ�
	auto r = make_shared<int>(42);
	r = q;//�� r ��ֵ������ָ����һ����ַ��
	      //���� q ָ��Ķ�������ü�����
	      //�ݼ� r ԭ��ָ��Ķ�������ü�����
	      //r ԭ��ָ��Ķ����Ѿ�û�������ߣ����Զ��ͷţ�
	return 0;
}