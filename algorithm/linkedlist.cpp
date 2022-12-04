#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node* list;
typedef struct Node {
	char name[20]; //�л� �̸�
	int st_no; // �й�
	float gpa; // ����
	char phone[20]; // ��ȭ��ȣ
	char address[30]; //�ּ�

	list link; // ���� ��� ������ ���� �ڱ� ����
};

list Print_between(list First, char tnameA[20], char tnameB[20]);
list search_ins_position(list First, char name[20]);
int Compute_num_students_of_location(list First, char location[20]);
int delete_node(list* First, list trail, list x);
void Print_linked_list(list First);

int main()
{
	list First, np, prev, curr;
	int res = 0, cnt, m_st_no;
	double gpa;
	char name[20], m_phone[20], m_address[20], tnameA[20], tnameB[20], location[20];
	char delname[20];
	FILE* student;

	student = fopen("student.txt", "r");

	First = NULL;
	while (1)
	{
		res = fscanf(student, "%s %d %lf %s %s", name, &m_st_no, &gpa, m_phone, m_address);
		if (res < 5)
			break;

		np = (list)malloc(sizeof(Node));

		strcpy(np->name, name);
		strcpy(np->phone, m_phone);
		strcpy(np->address, m_address);
		np->st_no = m_st_no;
		np->gpa = gpa;

		if (!First)
		{
			First = np;
			np->link = NULL;
		}
		else
		{
			prev = search_ins_position(First,name);
			if (!prev)
			{
				np->link = First;
				First = np;
			}
			else
			{
				np->link = prev->link;
				prev->link = np;
			}
		}
	}
	Print_linked_list(First);

	printf("�� �л��� �̸��� �����ÿ� : "); //�Է¹��� �κ� ���� ���
	scanf("%s %s", tnameA, tnameB);
	Print_between(First, tnameA, tnameB);

	// 3. �л� �� ����ϱ�
	printf("���� ���� �����ÿ� : ");
	scanf("%s", location);
	cnt = Compute_num_students_of_location(First, location);
	printf("%d \n", cnt);

	//����

	printf("������ �̸��� �����ÿ� : ");
	scanf("%s", delname);
	prev = NULL;
	curr = First;
	while (curr != NULL)
	{	//Ž��
		if (strcmp(curr->name, delname) == 0)
			break;

		else
		{
			prev = curr;
			curr = curr->link;
		}
	}
	
	if (curr != NULL)
	{
		res = delete_node(&First, prev, curr);
	}
	
	if (res == 0)
	{
		printf("���� ����\n");
	}
	else
		printf("���� ����\n");


	Print_linked_list(First);
}

list search_ins_position(list First, char name[20])// ���Ϸ� ���� ���Ḯ��Ʈ ����
{
	list curr = First; 
	list prev = NULL;
	while (curr != NULL)
	{
		if (strcmp(curr->name, name) > 0) 
			return prev; //���ڿ� ������ �� ���� ��忡 �ִ� �� �� Ŭ ��� �ƹ��͵� ����

		else
		{
			prev = curr; //���� ��庸�� Ŭ ��� ���� ���� ������ ������
			curr = curr->link; // ���� ��忡�� ���� ����
		}
	}
	return prev;

}

list Print_between(list First, char tnameA[20], char tnameB[20]) //����Ʈ�� ���� �κ� ���� ���
{
	list curr = First;
	curr = First;
	
	while (1)
	{
		if (strcmp(curr->name, tnameA) >= 0)
		{
			printf("%s %d %.1lf %s %s\n", curr->name, curr->st_no, curr->gpa, curr->phone, curr->address);
			curr = curr->link; //���� ��忡�� ���� ����
			if (strcmp(curr->name, tnameB) >= 0)
				break;
		}
		else
			curr = curr->link;
	}
	if (strcmp(curr->name, tnameB) == 0)
	{
		printf("%s %d %.1lf %s %s\n", curr->name, curr->st_no, curr->gpa, curr->phone, curr->address);
	}
	return 0;

}

int Compute_num_students_of_location(list First, char location[20]) //�л� �� ���
{
	list curr = First;
	int count = 0;

	while (curr)
	{
		if (strcmp(curr->address, location) == 0)
		{
			count++;
			curr = curr->link;
		}
		else
			curr = curr->link;
	}
	return count;
}

int delete_node(list* First, list trail, list x) //����Ʈ ����
{
	if (First == NULL)
		return 0;
	if (trail)
	{
		trail->link = x->link;
	}
	else
		*First = (*First)->link;
	free(x);

	return 1;
}

void Print_linked_list(list First) //����Ʈ ���
{
	printf("The list cotains : \n");
	for (;First;First = First->link)
		printf("%s %d %.1lf %s %s \n", First->name, First->st_no, First->gpa, First->phone, First->address);

}