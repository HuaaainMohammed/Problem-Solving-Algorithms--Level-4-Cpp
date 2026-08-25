#include <iostream>
#include<string>
#include<iomanip> 
using namespace std;

bool IsLeapYear(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

}

short NumberOfDaysInYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 365;

}

short NumberOfHoursInYear(short Year)
{
	return NumberOfDaysInYear(Year) * 24;
}

short NumberOfMinutesInYear(short Year)
{
	return NumberOfHoursInYear(Year) * 60;
}

short NumberOfSeconedInYear(short Year)
{
	return NumberOfMinutesInYear(Year) * 60;
}

short ReadYear()
{
	short number;
	cout << "Enter a year ? ";
	cin >> number;
	return number;
}

int main()
{
	short Year = ReadYear();

	cout << "\nNumber of Days in [" << Year << "] is " << NumberOfDaysInYear(Year);
	cout << "\nNumber of Hours in [" << Year << "] is " << NumberOfHoursInYear(Year);
	cout << "\nNumber of Minutes in [" << Year << "] is " << NumberOfMinutesInYear(Year);
	cout << "\nNumber of Seconed in [" << Year << "] is " << NumberOfSeconedInYear(Year);

	system("pause>0");
	return 0;
}