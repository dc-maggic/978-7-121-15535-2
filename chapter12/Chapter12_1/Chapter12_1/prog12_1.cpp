#include <iostream>
#include <memory>
#include<string>
#include<vector>
using namespace std;

int main()
{
	shared_ptr<string> p1;//shared_ptr，可以指向 string
	shared_ptr<int>p2;//shared_ptr，可以指向 int
	if (p1&&p1->empty())//如果p1不为空，检查它是否指向一个空 string；
		*p1 = "hi";//如果p1指向一个空string，解引用p1，将一个新值赋予 string；
	shared_ptr<int>p3 = make_shared<int>(42);//指向一个值为42的 int 的 shared_ptr；
	shared_ptr<string>p4 = make_shared<string>(10, '9');//指向一个值为"9999999999"的 string；
	shared_ptr<int>p5 = make_shared<int>();//指向一个值初始化的 int，即，值为0；
	//使用 auto 定义一个对象来保存 make_shared 的结果
	auto p6 = make_shared<vector<string>>();//指向一个动态分配的空的 vector<string>；
	//拷贝和赋值；
	auto p = make_shared<int>(42);//p 指向的对象只有 p 一个引用者；
	auto q(p);//p 和 q 指向相同对象，此对象有两个引用者；
	auto r = make_shared<int>(42);
	r = q;//给 r 赋值，令它指向另一个地址；
	      //递增 q 指向的对象的引用计数；
	      //递减 r 原来指向的对象的引用计数；
	      //r 原来指向的对象已经没有引用者，会自动释放；
	return 0;
}