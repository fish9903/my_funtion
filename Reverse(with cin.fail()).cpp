#include<iostream>
#include<limits>

using namespace std;

void reverse_it(const int& num);

int main()
{
	while(1)
	{
		int n;

		cout << "Enter a natural number." << endl;
		cin >> n;
		
		if (cin.fail()) // if n > INT32_MAX
		{
			cout << "Wrong input" << endl;
			cin.clear();
		}
		else if (n <= 0)
		{
			break;
		}
		else
			reverse_it(n);
		
	}

	return 0;
}

void reverse_it(const int& num)
{
	int tmp = num;
	int count = 1;

	while (tmp >= 10)	//finding the number of digit
	{
		count++;
		tmp /= 10;
	}

	tmp = num;
	if (count == 1 && num > 0)
		cout << num << endl;
	else if (num > 0)
	{
		for (int i = 0; i < count; i++)
		{
			cout << tmp % 10;
			tmp /= 10;
		}
		cout << endl;
	}
}
