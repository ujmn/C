#include "Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date::~Date()
{}

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Date Date::operator+(int days)
{
	_day += days;
	return *this;
}

Date Date::operator-(int days)
{
	_day -= days;
	return *this;
}

int Date::operator-(const Date& d)
{
	int ytmp = _year - d._year;
	int mtmp = _month - d._month;
	int dtmp = _day - d._day;
	return ytmp * 365 + mtmp * 30 + dtmp;
}

Date& Date::operator++()
{
	_day += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	_day += 1;
	return tmp;
}

Date& Date::operator--()
{
	_day -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	_day -= 1;
	return tmp;
}

bool Date::operator>(const Date& d)const
{
	if (_year > d._year)
		return true;
	else if (_month > d._month)
		return true;
	else if (_day > d._day)
		return true;
	return false;
}

bool Date::operator>=(const Date& d)const
{
	if (_year > d._year)
		return true;
	else if (_month > d._month)
		return true;
	else if (_day >= d._day)
		return true;
	return false;
}

bool Date::operator<(const Date& d)const
{
	if (_year < d._year)
		return true;
	else if (_month < d._month)
		return true;
	else if (_day < d._day)
		return true;
	return false;
}

bool Date::operator<=(const Date& d)const
{
	if (_year < d._year)
		return true;
	else if (_month < d._month)
		return true;
	else if (_day <= d._day)
		return true;
	return false;
}

bool Date::operator==(const Date& d)const
{
	if (_day == d._day && _month == d._month && _year == d._year)
		return true;
	return false;
}

bool Date::operator!=(const Date& d)const
{
	if (_day != d._day || _month != d._month || _year != d._year)
		return true;
	return false;
}