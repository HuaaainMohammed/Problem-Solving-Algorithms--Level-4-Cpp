#include <iostream>
#include<string>
#include<iomanip> 
using namespace std;

short DayOfWeekOrder(short Year, short Month , short Day)
{
	short a, y, m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
		
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	//ترتيب أيام الأسبوع
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrder ];
}

short ReadYear()
{
	short number;
	cout << "\nPlease enter a Year ? ";
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

short ReadDay()
{
	short number;
	cout << "\nPlease enter a Day ? ";
	cin >> number;
	return number;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	cout << "\nDate            :" << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order       :" << DayOfWeekOrder(Year, Month, Day);
	cout << "\nDay Name        :" << DayShortName(DayOfWeekOrder(Year , Month , Day));

	system("pause>0");
	return 0;
}