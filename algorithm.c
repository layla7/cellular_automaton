#include <stdio.h>

void displayValue(__uint32_t state, int statelen)
{
	for (int i = statelen; i > 0; i--)
	{
		__u_int s = state >> i;
		if (s % 2)
		{
			printf("0");
		}
		else
		{
			printf(".");
		}
	}
	printf("\n");
}

int main()
{
	__uint32_t state = 1u << 15;
	__uint8_t rule = 30;
	int statelen = 32;

	int generations = 16;

	for (int generation = 0; generation < generations; generation++)
	{
		displayValue(state, statelen);
		__uint32_t statecpy = state;
		__u_int lastBit;
		__u_int nextBit;
		__u_int currBit;
		__uint32_t nextState = 0;

		for (int i = 0; i < statelen; i++)
		{
			lastBit = (statecpy % 2);
			currBit = (statecpy >> 1) % 2;
			nextBit = (statecpy >> 2) % 2;

			__u_int bits = (lastBit << 2) + (currBit << 1) + nextBit;
			// printf("bit: %d\n", bits);

			__u_int next = (rule >> bits) % 2;
			// printf("%d\n", next);
			nextState += (next << i);

			statecpy = statecpy >> 1;
		}
		state = nextState << 1;
	}
	return 0;
}
