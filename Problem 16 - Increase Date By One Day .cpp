#include <iostream>
#include<string>
#include<iomanip> 
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

bool IsLeapYear(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInAMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[12] = { 31 ,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);

}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

short ReadDaysToAdd()
{
	short number;
	cout << "\How many days to add ?";
	cin >> number;
	return number;
}

short ReadDay()
{
	short number;
	cout << "\nPlease enter a Day ? ";
	cin >> number;
	return number;
}

short ReadMonth()
{
	short number;
	cout << "\nPlease enter a Month ? ";
	cin >> number;
	return number;
}

short ReadYear()
{
	short number;
	cout << "\nPlease enter a Year ? ";
	cin >> number;
	return number;
}

stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

int main()
{
	stDate Date = ReadFullDate();

	Date = IncreaseDateByOneDay(Date);

	cout << "\nAfter adding one day is " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;
}