#include <iostream>
#include<string>
#include<iomanip> 
using namespace std;

string NumberToText(int Number)
{
	if (Number == 0)
	{
		return "";
	}

	if (Number >= 1 && Number <= 19)
	{
		string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
			"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
			"Nineteen"};

		return arr[Number] + " ";
	}

	if (Number >= 20 && Number <= 99)
	{
		string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" }; 
		return arr[Number / 10] + " " + NumberToText(Number % 10);
	}

	if (Number >= 100 && Number >= 199)
	{
		return "One Hundred " + NumberToText(Number % 100);
	}

	if (Number >= 200 && Number <= 999)
	{
		return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
	}
	
	if (Number >= 1000 && Number <= 1999)
	{
		return "One Thousand " + NumberToText(Number % 1000);
	}
	
	if (Number >= 2000 && Number <= 999999)
	{
		return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
	}
	
	if (Number >= 1000000 && Number <= 1999999)
	{
		return "One Millios " + NumberToText(Number % 1000000);
	}

}

int ReadNumber()
{
	int number; 
	cout << "Enter a number ? ";
	cin >> number;
	return number;
}

int main()
{
	int number = ReadNumber();

	cout << NumberToText(number);

	system("pause>0");
	return 0;
}