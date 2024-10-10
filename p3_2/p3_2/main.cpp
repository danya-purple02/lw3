#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct queue
{
	char information[40];
	struct queue* next;
};

struct queue* head = NULL, * last = NULL, * f = NULL, * tmp = NULL;
struct queue* make_struct();
void add_to_list();
void retrieve_struct();

int main()
{
	int choise = 0;
	cout << "data structure \"queue\"" << endl << endl;
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

struct queue* make_struct()
{
	struct queue* new_str = NULL;

	if ((new_str = (queue*)malloc(sizeof(struct queue))) == NULL)
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
	struct queue* p = NULL;
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
	struct queue* new_head = NULL;
	int flag = 0;

	if (head == NULL)
	{
		cout << "list is empty" << endl;
		return;
	}
	else
	{
		cout << head->information << endl << endl;
		new_head = head->next;
		free(head);
		head = new_head;
	}
}