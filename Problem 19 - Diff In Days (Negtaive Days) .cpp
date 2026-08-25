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

void SwapDates(stDate& Date1, stDate& Date2)
{
	stDate TempDate;

	TempDate.Year = Date1.Year;
	TempDate.Month = Date1.Month;
	TempDate.Day = Date1.Day;

	Date1.Year = Date2.Year;
	Date1.Month = Date2.Month;
	Date1.Day = Date2.Day;

	Date2.Year = TempDate.Year;
	Date2.Month = TempDate.Month;
	Date2.Day = TempDate.Day;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	short SwapFlagValue = 1;

	if (!IsDate1BeforDate2(Date1,Date2))
	{
		SwapDates(Date1, Date2);
		SwapFlagValue = -1;
	}

	while (IsDate1BeforDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
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
	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();

	cout << "\nDiffrence is : " << GetDifferenceInDays(Date1, Date2);

	cout << "\nDiffrence (Including End Day ) is :" << GetDifferenceInDays(Date1, Date2, true);

	system("pause>0");
	return 0;
}