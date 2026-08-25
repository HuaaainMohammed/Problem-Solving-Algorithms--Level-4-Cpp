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
	return ((Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false);
}

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month ? (Date1.Day < Date2.Day ? true : false ) : false)) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
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
	cout << "\nEnter Date1 :";
	stDate Date1 = ReadFullDate();

	cout << "\nEnter Date2 :";
	stDate Date2 = ReadFullDate();

	 if(IsDate1AfterDate2(Date1 ,Date2))
		 cout << "\nYes, Date1 is After Date2.";
	 else
		 cout << "\nNo, Date1 is NOT After Date2.";

	system("pause>0");
	return 0;
}