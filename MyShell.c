/** Author: Lilly Tong (260459522)
 *  COMP206 Assignment 3 Question 2: The System Command
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char input1[100]; //token: check for keyword "QUIT" or "SET"
	char input2[100]; //token: check for keyword "PROMPT"
	char input3[100]; //token: check for what the users wants to set as prompt, GIVEN that input1=SET and input2=PROMPT
	char command[200];
	char prompt[200];

	strcpy(prompt,"Super Shell!!"); //this is the same as saying our "prompt = "Super Shell!!""

	while(strcasecmp(command,"QUIT")!=0) //while user is not entering "QUIT" using insensitive case comparison
	{
		//Step 1: Print prompt
		printf("%s ",prompt); //display our prompt. DO NOT GET CONFUSED. This is not the command line's prompt, but your OWN prompt created in C!
		fgets(command,199,stdin); //read command given by the user

		//Step 2: Check if user entered a keyword "QUIT" or "SET PROMPT X"
		sscanf(command,"%s %s %s",input1,input2,input3); //we are only interested in seeing the first three inputs for keyword checking

		if (strcasecmp(input1,"QUIT")==0) //if user wants to quit
		{
			break;//exit loop
		}

		else if((strcasecmp(input1,"SET")==0) && (strcasecmp(input2,"PROMPT")==0)) //if user wants to change prompt
		{
			strcpy(prompt,input3); //the third input must be the user's customized prompt, so set it to prompt
		}

		else //otherwise
		{
			system(command); //send command to be executed by command line
		}
	}

	return 0;
}
