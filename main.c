
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

/**
 * @returns int
*/
int main()
{
	menu();
	return 0;
}


/**
 * Processing user input and calling the corresponding functions.
 * @returns int
*/
int menu()
{
	bool quit = false;
	int choice = 0;

	//Declaring variables for AlgoValues
	uint8_t rule = 30;
	int statelen = 32;
	uint_c state = statelen / 2;
	uint_c generations = statelen / 2;
	bool wrap = false;
	uint_c *ptr = NULL;
	ptr = malloc(sizeof(uint_c) * generations);
	AlgoValues* data = NULL;

	//Allocating space for AlgoValues datatype and initialising variables
	data = (AlgoValues*)malloc(sizeof(AlgoValues));
	if (data != NULL)
	{
		data->statelen = 32;
		data->state = data->statelen / 2;
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

	while (quit == false)
	{
		menuDisplay();

		//take user input for menu choice
		if ((scanf("%d", &choice)) != 0)
		{
			switch (choice)
			{
			case 1:
				//calls function to run main algorithm
				algorithm(state, rule, statelen, generations, wrap, ptr);
				displayGenerations(ptr, generations, statelen);
				break;

			case 2:
				//calls function to set AlgoValues
				*data = editValues(*data);
				state = data->state;
				rule = data->rule;
				statelen = data->statelen;
				wrap = data->wrap;
				generations = data->generations;
				break;

			case 3:
				//calls function to save algorithm output to file
				saveToFile(ptr, generations, statelen, "testfile.txt");
				break;
				
			case 4:
				//loads algorithm output from text file
				loadFromFile(ptr, generations, "testfile.txt");
				displayGenerations(ptr, generations, statelen);
				break;
			case 5:
				//exits program
				quit = true;
				exit(0);
				break;
			}
		}

	}

	return 0;
}

/**
 * Displays menu options to user.
 * @returns int
*/
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