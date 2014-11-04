/** Author: Lilly Tong (260459522)
 *  COMP206 Assignment 3 Question 3: Linked list
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ENGLISH
//#define CHINESE
//#define JAPANESE

struct node //each node of linked list
{
	char content[300]; //string content at each node
	struct node* next; //stores link to next node
};

int main()
{
	char word[300]; //create an array of char to store the word the user is going to type each time

	#ifdef ENGLISH
		printf("Welcome to the infinite string storage program.");
		printf("\nPlease input a single word:");
	#endif
	#ifdef CHINESE
		printf("欢迎来到无限大字符串储存程序。");
		printf("\n请输入一个单词:");
	#endif
	#ifdef JAPANESE
		printf("容量無制限の文字列ストレージへようこそ。");
		printf("\n単語を一つ入力してください:");
	#endif

	fgets(word,299,stdin);
	sscanf(word,"%s",word); //only take the first word in case user enters more than one
	if (strcmp(word,"***END***")==0) //if user wants to exit
	{
		exit(0); //then let them exit, otherwise see below..
	}

	//1. Generate head of linked list (we must do this outside of the loop or else we will lose track of our linked list in memory!)
	struct node* head=(struct node*)malloc(sizeof(struct node));
	strcpy(head->content,word); //since content is string must set it this way!
	head->next = NULL;

	//2. Loop through the other nodes and add data
	#ifdef ENGLISH
		printf("\nPlease input a single word:");
	#endif
	#ifdef CHINESE
		printf("\n请输入下一个单词:");
	#endif
	#ifdef JAPANESE
		printf("\n単語をもう一つ入力してください:");
	#endif
		fgets(word,299,stdin);
		sscanf(word,"%s",word); //only take the first word in case user enters more than one

	while(strcmp(word,"***END***")!=0) //as long as user doesn't enter ***END***
	{
		struct node* runner; //going to run through the linked list until I reach the end, THEN i create a new node
		runner=head; //set runner to be head in the beginning since we start looping from here

		while (runner -> next!=NULL) //if my next node is not null, still
		{
			runner = runner -> next;//keep running till we reach the end of linked list
		}

		//reached the end of linked list, can now create a new node
		struct node* newNode=(struct node*)malloc(sizeof(struct node)); //create new node
		runner -> next=newNode; //set newNode to be the next of the last node that previously had its 'next'=null
		strcpy(newNode->content,word); //store content at new node
		newNode -> next=NULL; //set new node's next to be null

		#ifdef ENGLISH
			printf("\nPlease input a single word:");
		#endif
		#ifdef CHINESE
			printf("\n请输入下一个单词:");
		#endif
		#ifdef JAPANESE
			printf("\n単語をもう一つ入力してください:");
		#endif
		fgets(word,299,stdin);
		sscanf(word,"%s",word); //only take the first word in case user enters more than one

	}

	//3. User finishes entering data, we print out our linked list
	struct node* runner;
	runner=head;
	printf("\n");
	while (runner -> next!=NULL)
	{
		printf("%s\n",runner->content);
		runner = runner->next;
	}
	//print the last one where next=NULL
	printf("%s\n",runner->content);

	//4. FREE: Release memory on everything we malloc-ed
	runner=head;
	struct node* temp; //keep track of the next thing we must free
	while(runner!=NULL)
	{
		temp=runner->next; //store next node into temporary
		free(runner); //delete current node
		runner=temp; //set next node as current node
	}

	return 0;
}
