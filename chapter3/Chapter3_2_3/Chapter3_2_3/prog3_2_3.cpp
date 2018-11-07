#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	string str("some string");
	for (auto c : str)
		cout << c << endl;
	string s("Hello world!!!");
	decltype(s.size()) punct_cnt = 0;
	for (auto d : s)
		if (ispunct(d))
			++punct_cnt;
	cout << punct_cnt << " punctuation characters in " << s << endl;
	for (auto &cc : s)
		cc = toupper(cc);
	cout << s << endl;
	const string hexdigits = "0123456789ABCDEF";
	cout << "Enter a series of numbers between 0 and 15" << " separeted by spaces. Hit TNTER when finished: " << endl;
	string result;
	string::size_type n;
	while (cin >> n)
		if (n < hexdigits.size())
			result += hexdigits[n];
	cout << "Your hex number is: " << result << endl;
	system("pause");
}