#include <iostream>
#include<string>
#include<iomanip> 
using namespace std;

bool IsLeapYear(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

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