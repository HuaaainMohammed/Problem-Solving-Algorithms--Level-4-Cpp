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

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

stDate IncreaseDateByXDays(stDate Date , int Days)
{
	for (int i = 1; i <= Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

stDate IncreaseDateByXWeek(stDate Date , int Week)
{
	for (int i = 1; i <= Week; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;

}

stDate IncreaseDateByXMonth(stDate Date, short Month)
{
	for (short i = 1; i <= Month; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
	Date.Year++;
	return Date;
}

stDate IncreaseDateByXYear(stDate Date, short Year)
{
	for (short i = 1; i <= Year; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

stDate IncreaseDateByXYearFaster(stDate Date, short Year)
{
	Date.Year += Year;
	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
	Date.Year += 10;
	return Date;
}

stDate IncreaseDateByXDecade(stDate Date, short Decade)
{
	for (short i = 1; i <= Decade * 10; i++)
	{
		Date = IncreaseDateByOneDecade(Date);
	}
	return Date;
}

stDate IncreaseDateByXDecadeFaster(stDate Date, short Decade)
{
	Date.Year += Decade * 10;
	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	Date.Year += 100;
	return Date;
}

stDate IncreaseDateByOneMillennim(stDate Date)
{
	Date.Year += 1000;
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

	Date1 = IncreaseDateByOneDay(Date1);
	cout << "\n\n01-Adding one day is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	
	Date1 = IncreaseDateByXDays(Date1 , 10 );
	cout << "\n02-Adding 10 days is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneWeek(Date1);
	cout << "\n03-Adding One week is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	
	Date1 = IncreaseDateByXWeek(Date1, 10);
	cout << "\n04-Adding 10 week is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneMonth(Date1);
	cout << "\n05-Adding one month is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXMonth(Date1, 5);
	cout << "\n06-Adding 5 month is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneYear(Date1);
	cout << "\n07-Adding one year is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYear(Date1 , 10);
	cout << "\n08-Adding 10 years is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYearFaster(Date1, 10);
	cout << "\n09-Adding 10 years (faster) is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneDecade(Date1);
	cout << "\n10-Adding one Decade is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecade(Date1 , 10);
	cout << "\n11-Adding 10 Decades is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecade(Date1, 10);
	cout << "\n12-Adding 10 Decade (faster) is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneCentury(Date1);
	cout << "\n13-Adding one century is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneCentury(Date1);
	cout << "\n14-Adding one Millennim is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	system("pause>0");
	return 0;
}