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

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
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

bool IsValidateDate(stDate Date)
{
	
	if (Date.Day < 1 || Date.Day > 31)
		return false;

	
	if (Date.Month < 1 || Date.Month > 12)
		return false;

	if (Date.Month == 2)
	{
		if (IsLeapYear(Date.Year))
		{
			if (Date.Day > 29)
				return false;
		}
		else
		{
			if (Date.Day > 28)
				return false;
		}
	}
	  // 35/01/2026
	short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > DaysInMonth)
		return false;

	return true;
}

int main()
{

	stDate Date1 = ReadFullDate();

	if (IsValidateDate(Date1))
		cout << "\nYes, Date is a valide date.\n";
	else
		cout << "\nNo, Date is a NOT valide date\n";


	system("pause>0");
	return 0;
}