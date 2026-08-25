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

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;

	// 18/08/2026
	// 31/08/2026
	while (IsDate1BeforDate2(Date1, Date2))
	{

		Days++;
		Date1 = IncreaseDateByOneDay(Date1);

	}

	return IncludeEndDay ? ++Days : Days;
}

short DayOfWeekOrder(short Year, short Month, short Day)
{
	short a, y, m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrder];
}

bool IsEndOfWeek(stDate Date)
{
	return DayOfWeekOrder(Date) == 6;
}

bool IsWeekend(stDate Date)
{
	short DayIndex = DayOfWeekOrder(Date);
	return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
	return !IsWeekend(Date);
}

short DaysUntilTheEndOfWeek(stDate Date)
{
	// عدد الأيام المتبقية حتى نهاية الأسبوع

	return 6 - DayOfWeekOrder(Date);

}

short DaysUntilTheEndOfMonth(stDate Date1)
{
	// عدد الأيام المتبقية حتى نهاية الشهر

	stDate EndOfMonthDate;
	EndOfMonthDate.Day = NumberOfDaysInAMonth(Date1.Year, Date1.Month);
	EndOfMonthDate.Month = Date1.Month;
	EndOfMonthDate.Year = Date1.Year;

	return GetDifferenceInDays(Date1, EndOfMonthDate, true);

}

short DaysUntilTheEndOfYear(stDate Date1)
{
	stDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date1.Year;

	return GetDifferenceInDays(Date1, EndOfYearDate, true);
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

short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
	short DaysCount = 0;
	while (IsDate1BeforDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom))
		{
			DaysCount++;
		}

		DateFrom = IncreaseDateByOneDay(DateFrom);
	}
	return DaysCount;
}

int main()
{
	cout << "\nVacation Starts: ";
	stDate DateFrom = ReadFullDate();

	cout << "\nVacation Ends: ";
	stDate DateTo = ReadFullDate();

	cout << "\nVaction From: " << DayShortName(DayOfWeekOrder(DateFrom)) << " , "
		<< DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;

	cout << "Vaction To: " << DayShortName(DayOfWeekOrder(DateTo)) << " , "
		<< DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;

	cout << "\n\nActucal Vacation Days is: " << CalculateVacationDays(DateFrom, DateTo);

	system("pause>0");
	return 0;
}