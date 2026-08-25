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

struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
};

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month ? (Date1.Day < Date2.Day ? true : false) : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return ((Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
		days[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month,
		Date.Year));
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

enum enDateCompare
{
	Before = -1, Equal = 0, After = 1
};

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforDate2(Date1, Date2))
		return enDateCompare::Before;
	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	/*if (IsDate1AfterDate2(Date1, Date2))
		return enDateCompare::After;*/

		// This is faster.
	return enDateCompare::After;
}

int PeriodLengthInDays(stPeriod Period1, bool IncludeEndDate = false)
{
	return GetDifferenceInDays(Period1.StartDate, Period1.EndDate, IncludeEndDate);
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
	//الحالة الاولة : الفترة الثانيه تنتهي قبل بداية الاولى
	// الحالة الثانيه : الفترة الثانيه تبدا بعد انتهاء الاولى 
	if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before
		|| CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool isDateInPeriod(stDate Date, stPeriod Period)
{
	// Example:
   // StartDate = 10/08/2026
   // EndDate   = 20/08/2026
   // Date      = 15/08/2026
   //
   // 15 is not before 10 = false
   // 15 is not after 20  = false
   //
   // false || false = false
   // !false = true
   //
   // Therefore, Date is within the period.
	return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before
		||
		CompareDates(Date, Period.EndDate) == enDateCompare::After);
}

int CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
	int Period1Length = PeriodLengthInDays(Period1, true);
	int Period2Length = PeriodLengthInDays(Period2, true);

	int OverlapDays = 0;

	if (!IsOverlapPeriods(Period1, Period2))
		return 0;

	if (Period1Length < Period2Length)
	{
		while (IsDate1BeforDate2(Period1.StartDate, Period1.EndDate))
		{

			if (isDateInPeriod(Period1.StartDate, Period2))
			{
				OverlapDays++;
			}
			Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
		}
	}
	else
	{
		while (IsDate1BeforDate2(Period2.StartDate, Period2.EndDate))
		{

			if (isDateInPeriod(Period2.StartDate, Period1))
			{
				OverlapDays++;
			}
			Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
		}
	}

	return OverlapDays;
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

stPeriod ReadPeriod()
{
	stPeriod Period;
	cout << "\nEnter Start Date:\n";
	Period.StartDate = ReadFullDate();
	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadFullDate();

	return Period;
}

int main()
{
	cout << "\nEnter Period1 :";
	stPeriod Period1 = ReadPeriod();

	cout << "\nEnter Period2 :";
	stPeriod Period2 = ReadPeriod();

	cout << "\nOverlap Days Count Is : " << CountOverlapDays(Period1, Period2);


	system("pause>0");
	return 0;
}