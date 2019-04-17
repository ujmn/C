#include "myString.h"
using namespace std;

int main()
{
	myString s1("hello world!");
	myString s2(s1);
	myString s3(nullptr);
	s1.test(s2);
	s3 = s2;

	cout << s1 << endl;
	cout << "s1.size()	" << s1.size() << endl;
	cout << "s1.capacity()	" << s1.capacity() << endl;
	cout << "s1.length()	" << s1.length() << endl;
	cout << "s1.emputy()	" << s1.empty() << endl;
	s1.resize(20, '6');
	cout << s1 << endl;
	s1.resize(10);
	cout << s1 << endl;
	s1.reserve(521);
	cout << s1 << endl;
	s1.clear();
	cout << s1 << endl;

	return 0;
}