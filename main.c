
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#endif

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "algorithm.h"
#include "output.h"

int main()
{
	/*int statelen = 32;
	int generations = calculateGenerations(statelen);
	uint_c* ptr = NULL;
	ptr = malloc(sizeof(uint_c) * generations);
	// algorithm(1U << 15, 30, statelen, generations, 0, ptr);
	// displayGenerations(ptr, generations, statelen);
	// saveToFile(ptr, generations, statelen, "testfile.txt");

	loadFromFile(ptr, generations, "testfile.txt");
	displayGenerations(ptr, generations, statelen);*/
	menu();
	return 0;
}

//int algorithm(uint32_t state, uint8_t rule, int statelen, int wrap)
//algorithm(1U << 15, 45, 32, 0)



int menu()
{
	bool quit = false;
	int choice = 0;

	uint8_t rule = 30;
	int statelen = 32;
	uint_c state = statelen / 2;
	uint_c generations = statelen / 2;
	bool wrap = false;
	uint_c *ptr = NULL;
	ptr = malloc(sizeof(uint_c) * generations);
	AlgoValues* data = NULL;

	data = (AlgoValues*)malloc(sizeof(AlgoValues));
	if (data != NULL)
	{
		data->statelen = 32;
		data->state = 500;
		data->generations = data->statelen / 2;
		data->rule = 30;
		data->wrap = false;
		data->output = NULL;
	}
	else
	{
		printf("memory allocation error\n");
		return 104;
	}
	//menuDisplay();

	while (quit == false)
	{
		menuDisplay();


		if ((scanf("%d", &choice)) != 0)
		{
			switch (choice)
			{
			case 1:
				algorithm(state, rule, statelen, generations, wrap, ptr);
				displayGenerations(ptr, generations, statelen);
				break;

			case 2:
				*data = editValues(*data);
				state = data->state;
				rule = data->rule;
				statelen = data->statelen;
				wrap = data->wrap;
				generations = data->generations;
				break;

			case 3:
				saveToFile(ptr, generations, statelen, "testfile.txt");
				break;
				
			case 4:
				loadFromFile(ptr, generations, "testfile.txt");
				displayGenerations(ptr, generations, statelen);
				break;
			case 5:

				quit = true;
				exit(0);
				break;
			}
		}

	}

	return 0;
}

int menuDisplay()
{
	printf("Please input your choice with the keyboard\n");
	printf("1.) Run Cellular Automata \n");
	printf("2.) Edit Cellular Automata settings\n");
	printf("3.) Save current Automata to file\n");
	printf("4.) Load Automata from file\n");
	printf("5.) Exit Program!\n");

	return 0;
}