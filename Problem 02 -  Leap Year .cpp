#include <iostream>
#include<string>
#include<iomanip> 
using namespace std;

bool IsLeapYear(short year)
{
	if (year % 400 == 0)
	{
		return true;
	}

	else if (year % 100 == 0)
	{
		return false;
	}
	else if (year % 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

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

	if (IsLeapYear(Year))
	
		cout << "\nYes , Year [" << Year << "] is a lap year \n";
	
	else
		cout << "\No , Year [" << Year << "] is NOT a lap \n";

	system("pause>0");
	return 0;
}