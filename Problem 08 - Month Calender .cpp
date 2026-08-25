#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool IsLeapYear(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short DayOfWeekOrder(short Year, short Month, short Day)
{
	short a, y, m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	//ترتيب اليوم في الأسبوع
}

short NumberOfDaysInAMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	// Index: 0 1 2 3 4 5 6 7 8 9 10 11
	// Month:Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
	short NumberOfDays[12] = { 31 ,28,31,30,31,30,31,31,30,31,30,31 };

	// If the month is February, check if the year is leap year.
	// Otherwise, get the number of days from the array.
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
	//?             // True              // False
}

string MonthShortName(short MonthNumber)
{
	string arrDayNames[12] = { "Jan","Feb","Mar","April","May","June","Jul","Aug","Sep","Oct","Nov","Dec" };

	return arrDayNames[MonthNumber - 1];
}

void PrintMonthCalender(short Year, short Month)
{
	int NumberOfDays = NumberOfDaysInAMonth(Year, Month);
	int current = DayOfWeekOrder(Year, Month, 1);

	printf("\n---------------%s------------------\n\n",
		MonthShortName(Month).c_str());
	
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n");

	int i;             
	for (i = 0; i < current; i++) 
	{
		printf("     ");
	}

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}

	printf("\n ------------------------------------\n\n");
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

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	PrintMonthCalender(Year, Month);

	system("pause>0");
	return 0;
}