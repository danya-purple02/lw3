#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct node 
{
	int priority;
	char information[40];
	struct node* next;
};

struct node* head = NULL, * last = NULL, * f = NULL;
struct node* make_struct();
void add_to_list();
struct node* find_struct(char* name);
void del_struct(char* name);
void review_struct();

int main() 
{
	
}

struct node* make_struct() 
{
	char inf_str[40] = {};
	int prior_str = 0;
	
	struct node* new_str = NULL;

	if ((new_str = (node*)malloc(sizeof(struct node))) == NULL)
	{
		cout << "malloc error. struct didn't apper" << endl;
		exit(1);
	}
	cout << "input information:" << endl;
	cin >> inf_str;

	cout << "input element priority:" << endl;
	cin >> prior_str;

	if (*inf_str == 0 || prior_str == 0) 
	{
		cout << "error. must type some values" << endl;
		return NULL;
	}
	new_str->next = NULL;
	return new_str;
}

void add_to_list() 
{
	struct node* p = NULL;
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

void review_struct(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		cout << "list is empty" << endl;
	}
	while (struc)
	{
		cout << "name" << struc->information << endl;;
		struc = struc->next;
	}
	return;
}

struct node* find_struct(char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		cout << "list is empty" << endl;
	}
	while (struc)
	{
		if (strcmp(name, struc->information) == 0)
		{
			return struc;
		}
		struc = struc->next;
	}
	cout << "element not found" << endl;
	return NULL;
}

void del_struct(char* name)
{
	struct node* struc = head;
	struct node* prev;
	int flag = 0;

	if (head == NULL)
	{
		cout << "list is empty" << endl;
		return;
	}

	if (strcmp(name, struc->information) == 0) 
	{
		flag = 1;
		head = struc->next;
		free(struc);
		struc = head;
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}

	while (struc) 
	{
		if (strcmp(name, struc->information) == 0) 
		{
			flag = 1;
			if (struc->next) 
			{
				prev->next = struc->next;
				free(struc);
				struc = prev->next;
			}
			else	
			{
				prev->next = NULL;
				free(struc);
				return;
			}
		}
		else
		{
			prev = struc;
			struc = struc->next;
		}
	}
	if (flag == 0)	
	{
		cout << "element not found" << endl;
		return;
	}
}
