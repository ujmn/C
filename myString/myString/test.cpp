#include "myString.h"
using namespace std;

int main()
{
	myString s1("hello world!");
	myString s2(s1);
	myString s3(nullptr);
	s1.test(s2);
	s3 = s2;

	cout << s1.size() << endl;
	cout << s1.length() << endl;
	s1.resize(20, '6');
	cout << s1;
	cout << s1.size() << endl;
	cout <<s1.capacity() << endl;

	return 0;
}