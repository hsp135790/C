#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node *list;
typedef struct Node
{
	char name[20]; //�л��̸� 
	int st_no; // �й�
	float gpa; // ����
	char  phone[20]; //��ȭ��ȣ
	char  address[30]; //��ŵ�(��)
	list link; //���� �ε带 ����ġ�� ���Ѱ�
};

list search_ins_position(list First, char name[20]);

list Print_between(list First, char tnameA[20], char tnameB[20]);

int Compute_num_students_of_location(list First, char location[20]);

int delete_node(list *First, list trail, list x);

void Print_linked_list(list first);


int main()
{
	list First, np, prev, curr;
	int res = 0, num1, num;
	double gpa;
	char name[20], name1[20], name2[20], tnameA[20], tnameB[20], location[20];
	char stuname[20];
	FILE* student;
	student = fopen("student.txt", "r");

	//���Ḯ��Ʈ �����-�� ��带 ���ĵǰ� �ִ� ���   
	First = NULL;
	while (1){
		res = fscanf(student, "%s %d %lf %s %s", name, &num1, &gpa, name1, name2);
		if (res < 5)
			break;
		np = (list)malloc(sizeof(Node));
		strcpy(np->name, name);
		strcpy(np->phone, name1);
		strcpy(np->address, name2);
		np->st_no = num1;
		np->gpa = gpa;

		if (!First){
			First = np;
			np->link = NULL;
		}
		else{
			prev = search_ins_position(First, name);
			if (!prev){ //�� ��带 �� �տ� �־�� ��.
				np->link = First;
				First = np;
			}
			else{ //�� ��带 �߰��� �� prev ������ �־�� ��
				np->link = prev->link;
				prev->link = np;
			}
		}
	}
	Print_linked_list(First);
	// 2 ���Ḯ��Ʈ�� �κ� ���� ���
	printf("�� �л��� �̸��� �����ÿ�>");
	scanf("%s %s", tnameA, tnameB);
	Print_between(First, tnameA, tnameB);

	// 3 �л� �� ����ϱ�
	printf("���� ���� �����ÿ�>");
	scanf("%s", location);
	num = Compute_num_students_of_location(First, location);
	printf("%d\n",num);



	printf("ã�� �̸��� �Է��Ͻÿ�>");
	scanf("%s", stuname);
	prev = NULL;
	curr = First;
	while (curr != NULL)
	{
		if (strcmp(curr->name, stuname) == 0)
			break;
		else{
			prev = curr;
			curr = curr->link;
		}
	}

	// (4) �����۾�
	if (curr != NULL)
		res = delete_node(&First, prev, curr);
	if (res == 0)
		printf("��������.\n");
	else
		printf("%s ��������.\n", stuname);

	//(5) ����Ʈ
	Print_linked_list(First);
}


// ȭ�Ϸκ��� ���Ḯ��Ʈ ����� �Լ�
list search_ins_position(list First, char name[20])
{
	list curr = First, prev = NULL;
	while (curr != NULL)
	{
		if (strcmp(curr->name, name) > 0)
			return prev;
		else
		{
			prev = curr;
			curr = curr->link;
		}
	}
	return prev;
}

//���Ḯ��Ʈ�� �κ� ���� ��� �Լ�
list Print_between(list First, char tnameA[20], char tnameB[20])
{
	list curr = First;
	curr = First;
	while (1)
	{
		if (strcmp(curr->name, tnameA) >= 0)
		{
			printf("%s %d %.1lf %s %s\n", curr->name, curr->st_no, curr->gpa, curr->phone, curr->address);
			curr = curr->link;
			if (strcmp(curr->name, tnameB) >= 0)
				break;
		}
		else
			curr = curr->link;
	}
	if (strcmp(curr->name, tnameB) == 0)
		printf("%s %d %.1lf %s %s\n", curr->name, curr->st_no, curr->gpa, curr->phone, curr->address);
	return NULL;
}
// �л� �� ��� �Լ�
int Compute_num_students_of_location(list First, char location[20])
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

//����Ʈ�� ���� �Լ�
int delete_node(list *First, list trail, list x)
{
	if (First == NULL)
		return 0;
	if (trail){
		trail->link = x->link;
	}
	else
		*First = (*First)->link;
	free(x);
	return 1;
}

//����Ʈ�� ���
void Print_linked_list(list first)
{
	printf("The list contains: \n");
	for (; first; first = first->link)
		printf("%s %d %.1lf %s %s\n", first->name, first->st_no, first->gpa, first->phone, first->address);
}