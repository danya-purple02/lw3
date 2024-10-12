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

struct node* head = NULL, * last = NULL, * f = NULL, * tmp = NULL;
struct node* make_struct();
void add_to_list();
struct node* find_struct();
void del_struct(int prior);
void review_struct();

int main()
{
	int choise = 0;
	while (1)
	{
		cout << "choose action" << endl;
		cout << "review struct - 1 |  add element - 2  | delete element - 3" << endl;
		cout << "find element - 4  | exit programm - 5 |" << endl;
		cin >> choise;
		cout << endl;
		switch (choise)
		{
		case 1:
		{
			review_struct();
			cout << "---------------------" << endl << endl;
			continue;
		}
		case 2:
		{
			add_to_list();
			cout << "---------------------" << endl << endl;
			continue;
		}
		case 3:
		{
			int prior = 0;
			cout << "enter element priority: ";
			cin >> prior;
			cout << endl;
			del_struct(prior);
			cout << "done!" << endl;
			cout << "---------------------" << endl << endl;
			continue;
		}
		case 4:
		{
			struct node* p = find_struct();
			cout << "priority: " << p->priority << endl << "name: " << p->information << endl;
			cout << "---------------------" << endl << endl;
			continue;
		}
		case 5:
		{
			return 0;
		}
		}
	}
}

struct node* make_struct()
{
	struct node* new_str = NULL;

	if ((new_str = (node*)malloc(sizeof(struct node))) == NULL)
	{
		cout << "malloc error. struct didn't apper" << endl;
		exit(1);
	}
	cout << "enter information:" << endl;
	cin >> new_str->information;

	cout << "enter element priority:" << endl;
	cin >> new_str->priority;

	if (new_str->information == 0 || new_str->priority == 0)
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
	else
	{
		struct node* curr = head;
		struct node* prev = NULL;
		while (curr != NULL && curr->priority < p->priority)
		{
			prev = curr;
			curr = curr->next;
		}
		if (prev == NULL)
		{
			p->next = head;
			head = p;
		}
		else
		{
			prev->next = p;
			p->next = curr;
		}
		if (p->next == NULL)
		{
			last = p;
		}
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
		cout << "priority: " << struc->priority << endl;
		cout << "name: " << struc->information << endl << endl;
		struc = struc->next;
	}
	return;
}

struct node* find_struct()
{
	int choise_2 = 0;
	cout << "find by name - 1 | find by priority - 2" << endl;
	cin >> choise_2;

	switch (choise_2)
	{
	case 1:
	{
		char name[20] = { 0 };
		cout << "enter search value: ";
		cin >> name;
		cout << endl;
		struct node* struc = head;
		if (head == NULL)
		{
			cout << "list is empty" << endl;
			return NULL;
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
	case 2:
	{
		int prior = 0;
		cout << "enter search value: ";
		cin >> prior;
		cout << endl;
		struct node* struc = head;
		if (head == NULL)
		{
			cout << "list is empty" << endl;
			return NULL;
		}
		while (struc)
		{
			if (prior == struc->priority)
			{
				return struc;
			}
			struc = struc->next;
		}
		cout << "element not found" << endl;
		return NULL;
	}
	}

}

void del_struct(int prior)
{
	struct node* struc = head;
	struct node* prev = head;
	struct node* tmp = NULL;
	int flag = 0;

	if (head == NULL)
	{
		cout << "list is empty" << endl;
		return;
	}

	if (prior == struc->priority)
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
		if (prior == struc->priority && struc != head)
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
		else if (prior == struc->priority && struc == head)
		{
			flag = 1;
			if (struc->next)
			{
				head = struc->next;
				free(struc);
				struc = head;
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