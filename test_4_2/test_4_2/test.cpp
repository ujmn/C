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
		++_count;
		_sum += _count;	
	}
	static int GetSum()
	{
		return _sum;
	}
	static int _sum;
	static int _count;
private:
	
};

int Add::_sum = 0;
int Add::_count = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		Add* add = new Add[n];
		int i = Add::GetSum();
		delete[] add;
		return i;
	}
private:
};


int main()
{
	Solution s;
	int i = s.Sum_Solution(1);
	i += s.Sum_Solution(1);
	return 0;
}