#include <iostream>
#include<string>
#include <ctime>
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

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

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

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;

	while (IsDate1BeforDate2(Date1, Date2))
	{

		Days++;
		Date1 = IncreaseDateByOneDay(Date1);

	}

	return IncludeEndDay ? ++Days : Days;
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

stDate GetSystemDate()
{

	stDate Date;

	time_t t = time(0);

	tm now;
	localtime_s(&now, &t);

	Date.Day = now.tm_mday;
	Date.Month = now.tm_mon + 1;
	Date.Year = now.tm_year + 1900;

	return Date;
}

int main()
{
	cout << "\nPlease Enter Your Date of Birthday ";
	
	stDate Date1 = ReadFullDate();
	stDate Date2 = GetSystemDate();


	cout << "\nYour Age is :" << GetDifferenceInDays(Date1, Date2, true) <<" Day(s).";

	system("pause>0");
	return 0;
}