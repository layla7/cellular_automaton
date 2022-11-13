/*#ifdef _MSC_VER
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

int menu()
{
	bool quit = false;
	int choice = 0;

	uint8_t rule = 30;
	int statelen = 32;
	int generations = statelen / 2;
	uint_c state = statelen / 2;
	uint_c* ptr = NULL;
	ptr = malloc(sizeof(uint_c) * generations);
	bool wrap = false;
	AlgoValues* data = NULL;

	data = (AlgoValues*)malloc(sizeof(AlgoValues));
	if (data != NULL)
	{
		data->statelen = 32;
		data->state = data->statelen / 2;
		data->generations = data->statelen / 2;
		data->rule = 30;
		data->output = NULL;
		data->wrap = false;
	}
	else
	{
		printf("memory allocation error\n");
		return 104;
	}

	while (quit == false)
	{
		menuDisplay();

		if ((scanf("%d", &choice)) == NULL)
		{
			switch (choice)
			{
			case 1:
				algorithm(state, rule, statelen, generations, wrap, *ptr);
				break;

			case 2:
				*data = editValues(*data);
				state = data->state;
				rule = data->rule;
				statelen = data->statelen;
				wrap = data->wrap;
				ptr = data->output;
				break;

			case 3:
				saveToFile(ptr, generations, statelen, "testfile.txt");
				break;
			case 4:
				loadFromFile(ptr, generations, "testfile.txt");
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
}*/