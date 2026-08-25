#include <iostream>
#include<string>
#include<iomanip> 
using namespace std;

bool IsLeapYear(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

}

short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month >12)
		return 0;
	                   // Index: 0 1 2 3 4 5 6 7 8 9 10 11
                      // Month:Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
	short NumberOfDays[12] = { 31 ,28,31,30,31,30,31,31,30,31,30,31 };
	// If the month is February, check if the year is leap year.
    // Otherwise, get the number of days from the array.
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
	               //?             // True              // False
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

	cout << "\nNumber of Days in Month [" << Month << "] is " << NumberOfDaysInMonth(Year, Month);
	
	system("pause>0");
	return 0;
}