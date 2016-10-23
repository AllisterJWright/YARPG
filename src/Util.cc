#include<cstdlib>
#include<algorithm>
#include<unordered_map>

using namespace std;

template <class T>
void swap (T* a, T* b) { *a ^= *b; *b ^= *a; *a ^= *b; }


/**
 * Mutates array to sorted list via bubble sort
 * @param list: the list to be sorted
 * @param length: the length of the list as a int-based type
 */
template <class T>
void BubbleSort(T* list, int length)
{
	for (int i = 0; i < length; i++)
		for (int j = i + 1; j < length; j++)
			if (list[i] > list[j])
				swap(&(list[i]), &(list[j]));
}


short Roll (short diceCount, short diceSide, short constant = 0,
		short keepState = 1, short keepCount = 0,
		short expl = 0)
{
	short out = 0;
	short currRoll = 0;
	short* rolls = (short*) calloc(diceCount, sizeof(short*));
	for (int i = 0; i < diceCount; i++)
	{
		rolls[i] = currRoll = 1 + (rand()%diceSide);
		for (int j = 1; currRoll == diceSide && j <= expl; j++)
			rolls[i] += currRoll = 1 + (rand()%diceSide);
	}
	BubbleSort(rolls, diceCount);
	if (keepCount > 0)
	{
		if (keepState)
			for (int i = 0; i < keepCount; i++)
				out += rolls[diceCount - i - 1];
		else
			for (int i = 0; i < keepCount; i++)
				out += rolls[i];
	}
	else
		for (int i = 0; i < diceCount; i++)
			out += rolls[i];
	return out + constant;
}

short D20Roll(short adv = 1)
{
	switch (adv) {
		case 0: return Roll(2, 20, 0, 0, 1);
		case 1: return Roll(1, 20);
		case 2: return Roll(2, 20, 0, 1, 1);
		default: return 0;
	}
}

short GenAbility() { return Roll(4, 5, 3, 1, 3); }

template <class T>
T TableRoll(T* table, short len) { return table[rand()%len]; }
