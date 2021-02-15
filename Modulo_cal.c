#define _CRT_SECURE_NO_WARNINGS

/*
*	### Modulo ###
*
* (a * b) % m = (a % m) * (b % m)
* (a + b) % m = (a % m) + (b % m)
* 
* ex) 968 % 7 = 900 % 7 + 60 % 7 + 8 % 7
*             = ((2 + 7) * 100) % 7 + 60 % 7 + 8 % 7
*             = (2 * 100) % 7 + ...
*             = ((9 % 7) * 100) % 7 + ...
*
*             remainer = 9 % 7 = 2
*             remainer = (2 * 10 + 6) % 7 = 5
*             remainer = (5 * 10 + 8) % 7 = 2 (Answer) 
*/

#include<stdio.h>
#include<stdlib.h>

int modulo(int a[], const int m, const int size);

int main()
{
	int mod, arr[1000];
	char ch;

	printf("Enter a big positive integer.\n");

	int i = 0;
	for (int ch = getchar(); ch != '\n'; ch = getchar())
	{
		arr[i] = atoi(&ch);
		i++;
	}

	printf("Enter a modulo number.\n");
	scanf("%d", &mod);
	printf("The result of modulo is %d.\n", modulo(arr, mod, i));

	/*for (int j = 0; j < i; j++)
		printf("%d ", arr[j]);*/

	return 0;
}

int modulo(int a[], const int m, const int size)
{
	int remainer = 0;

	for (int i = 0; i < size; i++)
	{
		if(i == 0)
			remainer = a[i] % m;
		else
		{
			remainer = (remainer * 10 + a[i]) % 7;
		}
	}

	return remainer;
}
