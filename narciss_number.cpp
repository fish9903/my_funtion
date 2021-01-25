//#define _CRT_SECURE_NO_WARININGS

//#include<stdio.h>

/*
* Narcissistic number is a number that is
* the sum of its own digits each raised to the power of the number of digits.
* ex) 153 = 1^3 + 5^3 + 3^3, 1634 = 1^4 + 6^4 + 3^4 + 4^4
*/

#include<iostream>

using namespace std;

int is_narciss(int& n); // return 1 if narcissistic number
int m_pow(int n, int epn = 1); // return n ^ epn

int main()
{
	int num;

	cout << "Enter the number greater than 0 : ";
	cin >> num;

	if (is_narciss(num))
		cout << num << " is narcissistic number." << endl;
	else
		cout << num << " is not narcissistic number" << endl;

	return 0;
}

int is_narciss(int &n)
{
	int tmp = n;
	int count = 1; // number of digit

	while (tmp >= 10) // Finding the number of digits
	{
		count++;
		tmp /= 10;
	}

	int sum = 0; // compare with n
	tmp = n;
	if (count == 1) // 1 ~ 9
		return 1;
	else
	{		
		for (int i = 0; i < count; i++)
		{
			sum += m_pow(tmp / m_pow(10, count - 1 - i), count);
			tmp %= m_pow(10, count - 1 - i);
		}
	}
	
	if (sum == n)
		return 1;
	else 
		return 0;
}

int m_pow(int n, int epn)
{
	int result = 1;

	for (int i = 0; i < epn; i++)
		result *= n;

	return result;
}