#ifndef _Date
#define _Date
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int day, int month, int year);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	bool operator==(const Date& rightHandItem) const;
	friend ostream& operator<<(ostream& out, const Date& d)
	{
		out << d.day << "/" << d.month << "/" << d.year;
		return out;
	}
	friend istream& operator>>(istream& in, Date& d)
	{
		int day, month, year;
		in >> day >> month >> year;
		d = Date(day, month, year);
		return in;
	}
};
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
int Date::getDay() const
{
	return day;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}
void Date::setDay(int day)
{
	this->day = day;
}
void Date::setMonth(int month)
{
	this->month = month;
}
void Date::setYear(int year)
{
	this->year = year;
}
bool Date::operator==(const Date& rightHandItem) const
{
	return (day == rightHandItem.day && month == rightHandItem.month && year == rightHandItem.year);
}
#endif