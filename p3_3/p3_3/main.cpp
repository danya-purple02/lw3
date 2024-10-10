#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct stack
{
	char information[40];
	struct stack* next;
};

struct stack* head = NULL, * last = NULL, * f = NULL, * tmp = NULL;
struct stack* make_struct();
void add_to_list();
void retrieve_struct();

int main()
{
	int choise = 0;
	cout << "data structure \"stack\"" << endl << endl;
	while (1)
	{
		cout << "choose action" << endl;
		cout << "| 1 - push (adds a structure element)" << endl;
		cout << "| 2 - pop  (retrieves a structure element)" << endl;
		cout << "| 3 - exit (exit the program)" << endl;
		cin >> choise;
		cout << endl;
		switch (choise)
		{
		case 1:
		{
			add_to_list();
			cout << "---------------------" << endl << endl;
			continue;
		}
		case 2:
		{
			retrieve_struct();
			cout << "---------------------" << endl << endl;
			continue;
		}
		case 3:
		{
			return 0;
		}
		}
	}
}

struct stack* make_struct()
{
	struct stack* new_str = NULL;

	if ((new_str = (stack*)malloc(sizeof(struct stack))) == NULL)
	{
		cout << "malloc error. struct didn't apper" << endl;
		exit(1);
	}
	cout << "enter information:" << endl;
	cin >> new_str->information;

	if (new_str->information == 0)
	{
		cout << "error. must type some values" << endl;
		return NULL;
	}
	new_str->next = NULL;
	return new_str;
}

void add_to_list()
{
	struct stack* p = NULL;
	p = make_struct();
	if (head == NULL && p != NULL)
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL)
	{
		last->next = p;
		last = p;
	}
}

void retrieve_struct()
{
	int flag = 0;
	struct stack* last = head;
	struct stack* penultimate = NULL;

	if (head == NULL)
	{
		cout << "list is empty" << endl;
		return;
	}
	else if (head->next != NULL) 
	{
		while (last->next != NULL) 
		{
			penultimate = last;
			last = last->next;
		}
		cout << last->information << endl << endl;
		free(last);
		penultimate->next = NULL;
	}
	else 
	{
		cout << last->information << endl << endl;
		free(last);
		head = NULL;
		cout << "this is the end of stack" << endl;
	}
}