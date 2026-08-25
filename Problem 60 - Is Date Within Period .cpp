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

enum enDateCompare
{
	Before = -1, Equal = 0, After = 1
};

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return ((Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false);
}

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month ? (Date1.Day < Date2.Day ? true : false) : false)) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

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

bool isDateInPeriod(stDate Date , stPeriod Period)
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
	stPeriod Period = ReadPeriod();

	cout << "\nEnter Date to check:\n";
	stDate Date = ReadFullDate();

	if (isDateInPeriod(Date, Period))
		cout << "\nYes, Date is within period\n";
	else
		cout << "\nNo, Date is NOT within period\n";


	system("pause>0");
	return 0;
}