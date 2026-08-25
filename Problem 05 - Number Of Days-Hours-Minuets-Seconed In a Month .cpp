#include <iostream>
#include<string>
#include<iomanip> 
using namespace std;

bool IsLeapYear(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

}

short NumberOfDaysInMonth(short Year , short Month)
{
	if (Month < 1 || Month >12)
	{
		return 0;
	}

	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28; 
	}

	short arr31Days[7] = { 1,3,5,7,8,10,12 };
	for (short i = 0; i < 7; i++)
	{
		if (arr31Days[i] == Month)
			return 31;
	}

	return 30;
}

short NumberOfHoursInMonth(short Year, short Month)
{
	return NumberOfDaysInMonth(Year , Month) * 24;
}

int NumberOfMinutesInMonth(short Year, short Month)
{
	
	return NumberOfHoursInMonth(Year, Month) * 60;
}

int NumberOfSeconedInMonth(short Year, short Month)
{
	return NumberOfMinutesInMonth(Year, Month) * 60;
}

short ReadYear()
{
	short number;
	cout << "\nPlease enter a Year to check ? ";
	cin >> number;
	return number;
}

short ReadMonth()
{
	short number;
	cout << "\nPlease enter a Month to check ? ";
	cin >> number;
	return number;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber of Days in [" << Month << "] is " << NumberOfDaysInMonth(Year , Month);
	cout << "\nNumber of Hours in [" << Month << "] is " << NumberOfHoursInMonth(Year, Month);
	cout << "\nNumber of Minutes in [" << Month << "] is " << NumberOfMinutesInMonth(Year, Month);
	cout << "\nNumber of Seconed in [" << Month << "] is " << NumberOfSeconedInMonth(Year , Month);

	system("pause>0");
	return 0;
}