#include <iostream>
#include<string>
#include<iomanip> 
using namespace std;

bool IsLeapYear(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

struct stDate
{
	short Day;
	short Month;
	short Year;
};

short NumberOfDaysInAMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[12] = { 31 ,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

short NumberOfDaysFromTheBeginningOfTheYear(short Year, short Month, short Day)
{

	short totalDays = 0;

	for (int i = 1; i <= Month - 1; i++)
	{
		totalDays += NumberOfDaysInAMonth(Year, i);
	}

	totalDays += Day;
	return totalDays;
}

stDate DateAddDays(short Days , stDate Date)
{

	short RemainingDays = Days + NumberOfDaysFromTheBeginningOfTheYear(Date.Year, Date.Month, Date.Day);
	short MonthDays = 0; // ايام الشهر

	Date.Month = 1;

	while (true)
	{

		MonthDays = NumberOfDaysInAMonth(Date.Year, Date.Month);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++; 
			}
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
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
	short Days = ReadDaysToAdd();

	Date = DateAddDays(Days, Date);
	
	cout << "\nDate after adding [" << Days << "] days is ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;


	system("pause>0");
	return 0;
}