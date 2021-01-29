#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
//#define NDEBUG
#include<cstdlib>
#include<cassert>

using namespace std;

int leap_year(int y); // A funtion that determines if it is a leap year. (leap year -> return 1 else return 0)
int to_last_year(int year); // A function that returns the number of days from January 1, AD 1 to the end of last year
int to_last_month(int year, int month); // A function that returns the number of days until the last month of the year
int date_of_month(int year, int month); // A function that returns the number of days in the month

int main()
{
	int year, month;
	int start_pos;
	int max_date;

	while (1)
	{
		cout << "Enter year and month." << endl;
		cin >> year >> month;

		start_pos = (to_last_year(year) + to_last_month(year, month)) % 7 + 1;

		switch (start_pos)
		{
		case 0 :
			cout << "sunday" << endl;
			break;
		case 1:
			cout << "monday" << endl;
			break;
		case 2:
			cout << "tuesday" << endl;
			break;
		case 3:
			cout << "wednesday" << endl;
			break;
		case 4:
			cout << "thursday" << endl;
			break;
		case 5:
			cout << "friday" << endl;
			break;
		case 6:
			cout << "saturday" << endl;
			break;
		}

		cout << "Sun\tMon\tTues\tWen\tThu\tFri\tSat" << endl;

		int date = 1;
		max_date = date_of_month(year, month);
		for (int col = 0; col < 6; col++)
		{
			for (int row = 0; row < 7; row++)
			{
				if (row < start_pos && col == 0)
					cout << "*\t";
				else
				{
					if (date > max_date)
						cout << "*\t";
					else 
						cout << date++ << "\t";
				}
			}
			cout << endl;
		}

		cout << endl;
	}

	
	return 0;
}

int leap_year(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || (y % 4 == 0 && y % 100 == 0 && y % 400 == 0))
		return 1;
	else
		return 0;
}

int to_last_year(int year)
{
	int total = 0;

	for (int i = 1; i <= (year - 1); i++)
	{
		if (leap_year(i))
			total += 366;
		else
			total += 365;
	}

	return total;
}

int to_last_month(int year, int month)
{
	int total = 0;

	for (int i = 1; i <= (month - 1); i++)
	{
		total += date_of_month(year, i);

		/*if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)
			total += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			total += 30;
		else
		{
			if (leap_year(i))
				total += 29;
			else
				total += 28;
		}*/
	}

	return total;
}

int date_of_month(int year, int month)
{
	int total = 0;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		total = 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		total = 30;
	else // February
	{
		if (leap_year(year))
			total = 29;
		else
			total = 28;
	}

	return total;
}