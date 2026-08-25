#include <iostream>
#include<string>
#include<iomanip> 
using namespace std;

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

short NumberOfDaysFromTheBeginningOfTheYear(short Year , short Month , short Day)
{

	short totalDays = 0;

	for (int i = 1; i <= Month - 1; i++)
	{
		totalDays += NumberOfDaysInAMonth(Year, i);
	}

	totalDays += Day;
	return totalDays;
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

int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();

	cout << "\nNumber of Days from the beginning of the Year : " 
		<< NumberOfDaysFromTheBeginningOfTheYear(Year, Month, Day);	

	system("pause>0");
	return 0;
}