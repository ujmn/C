#include <iostream>
using namespace std;

#if 0
class Date {
public:
	Date(int year, int month, int day):_year(year),_month(month),_day(day)
	{
		cout << "Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019,04,02);
	return 0;
}

#endif

class Add {
public:
	Add()
	{
		_sum += _count;
		++_count;
	}
	static int GetSum()
	{
		return _sum;
	}
private:
	static int _sum;
	static int _count;
};

int Add::_sum = 0;
int Add::_count = 1;

class Solution {
public:
	int Sum_Solution(int n) {
		Add add[5];
		int i = Add::GetSum();
		return i;
	}
private:
};


int main()
{
	Solution s;
	s.Sum_Solution(5);
	return 0;
}