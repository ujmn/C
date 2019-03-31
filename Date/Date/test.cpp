#include "Date.h"

int main()
{
	Date d1(2019, 3, 29);
	Date d2(d1);
	Date d3 = d1++;
	Date d4 = ++d1;
	bool flag = d4 > d3;
	return 0;
}