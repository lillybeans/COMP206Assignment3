/** Author: Lilly Tong (260459522)
 *  COMP206 Assignment 3 Question 1: Experimental Average
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printEachLine(char* line);

int main(int argc, char** argv) //char** means string array! note that argv[0] is program name! skip it! file should be argv[1]
{
	char filename[200];

	if (argc != 2) //2 arguments expected: program name, file name. If not 2 arguments, show error.
	{
		printf("Error: Please input a single file that you would like to process.");
	}

	else
	{
		strcpy(filename, argv[1]); //store filename passed by user on command line into variable "filename"

		FILE *file_ptr; //initialize a pointer to point to the file
		char line[300]; //for processing each line in the file

		file_ptr=fopen(filename,"rt"); //make the address of file_ptr equal to the file

		if (file_ptr == NULL) //null file
		{
			printf("Error: File is null");
			return 1;
		}

		while(fgets(line,299,file_ptr)!=NULL) //while next line is not null, read it
		{
			printEachLine(line); //print the average of each line by calling averageOfEachLine
		}

		fclose(file_ptr); //close while when done
	}

}

void printEachLine(char* line)
{
	//Step 1: Split the string separated by commas into tokens
	char* token; //string array to store the tokens
	double sum=0; //initialize sum of all numbers on this line to be 0, then we will find the sum as we go through the loop
	double avg; //double since could be decimal
	int count=0;

	//Step 2: retrieve title, which is the first token
	token=strtok(line,","); //separate the string by commas, and point "token" to the first token from the string.
	printf("%s ",token); //print the title first

	token=strtok(NULL,","); //now token points to the first number in line

	//Step 3: process the rest tokens, which are all data (numbers)
	while(token != NULL) //while we still have tokens to process
	{
		int number=atoi(token); //convert token to int
		sum=sum+number;
		count++;
		token=strtok(NULL,","); //read next token
	}

	avg=sum/count;

	printf("%.2f\n",avg);

}
