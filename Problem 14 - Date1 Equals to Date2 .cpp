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

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) ? true : false : false : false;
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

	if (IsDate1EqualDate2(Date1, Date2))
	{
		cout << "\nYes , Date1 is Less than Date2. ";
	}
	else
		cout << "\nNo , Date1 is NOT Less than Date2.";


	system("pause>0");
	return 0;
}