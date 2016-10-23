#include "Skills.cc"
#include<ctime>
#include<iostream>

using namespace std;

int main()
{
	srand(time(0));
	short* rolls = (short*) calloc(100, sizeof(short));
	for (int i = 0; i < 100; i++)
	{
		rolls[i] = D20Roll();
	}
	BubbleSort(rolls, 100);
	for (int i = 0; i < 100; i++)
		cout << rolls[i] << "; ";
	return 0;
}
