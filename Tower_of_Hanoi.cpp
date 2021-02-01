#include<iostream>

using namespace std;

void move(int n, char start, char goal, char assistant) // start, goal ,assistant
{
	if (n == 1)
		printf("move a disk from %c to %c\n", start, goal);
	else
	{
		move(n - 1, start, assistant, goal);
		printf("move a disk from %c to %c\n", start, goal);
		move(n - 1, assistant, goal, start);
	}
}

int main()
{
	int n = 3;

	cout << "Enter the number of disks" << endl;
	cin >> n;
	move(n, 'X', 'Y', 'Z');

	return 0;
}