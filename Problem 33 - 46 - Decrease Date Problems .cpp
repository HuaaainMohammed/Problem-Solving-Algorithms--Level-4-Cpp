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

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);

}

stDate DecreaseDateByOneDay(stDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Day = 31;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
		}
	}
	else
	{
		Date.Day--;
	}
	return Date;
}

stDate DecreaseDateByXDays(stDate Date, int Days)
{
	for (int i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByXWeek(stDate Date, int Week)
{
	for (int i = 1; i <= Week; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}

stDate DecreaseDateByXMonth(stDate Date, short Month)
{
	for (short i = 1; i <= Month; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
	Date.Year--;
	return Date;
}

stDate DecreaseDateByXYear(stDate Date, short Year)
{
	for (short i = 1; i <= Year; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

stDate DecreaseDateByXYearFaster(stDate Date, short Year)
{
	Date.Year -= Year;
	return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
	Date.Year -= 10;
	return Date;
}

stDate DecreaseDateByXDecade(stDate Date, short Decade)
{
	for (short i = 1; i <= Decade * 10; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

stDate DecreaseDateByXDecadeFaster(stDate Date, short Decade)
{
	Date.Year -= Decade * 10;
	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
	Date.Year -= 100;
	return Date;
}

stDate DecreaseDateByOneMillennim(stDate Date)
{
	Date.Year -= 1000;
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
	stDate Date1 = ReadFullDate();
	cout << "\nDate After : ";

	Date1 = DecreaseDateByOneDay(Date1);
	cout << "\n\n01-Subtracting one day is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDays(Date1, 10);
	cout << "\n02-Subtracting 10 days is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneWeek(Date1);
	cout << "\n03-Subtracting One week is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXWeek(Date1, 10);
	cout << "\n04-Subtracting 10 week is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneMonth(Date1);
	cout << "\n05-Subtracting one month is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXMonth(Date1, 5);
	cout << "\n06-Subtracting 5 month is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneYear(Date1);
	cout << "\n07-Subtracting one year is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYear(Date1, 10);
	cout << "\n08-Subtracting 10 years is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYearFaster(Date1, 10);
	cout << "\n09-Subtracting 10 years (faster) is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneDecade(Date1);
	cout << "\n10-Subtracting one Decade is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecade(Date1, 10);
	cout << "\n11-Subtracting 10 Decades is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecadeFaster(Date1, 10);
	cout << "\n12-Subtracting 10 Decade (faster) is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneCentury(Date1);
	cout << "\n13-Subtracting one century is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneMillennim(Date1);
	cout << "\n14-Subtracting one Millennim is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	system("pause>0");
	return 0;
}