#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node *list;
typedef struct Node
{
	char name[20]; //학생이름 
	int st_no; // 학번
	float gpa; // 학점
	char  phone[20]; //전화번호
	char  address[30]; //출신도(시)
	list link; //다음 로드를 가리치기 위한거
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

	//연결리스트 만들기-새 노드를 정렬되게 넣는 방법   
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
			if (!prev){ //새 노드를 맨 앞에 넣어야 함.
				np->link = First;
				First = np;
			}
			else{ //새 노드를 중간에 즉 prev 다음에 넣어야 함
				np->link = prev->link;
				prev->link = np;
			}
		}
	}
	Print_linked_list(First);
	// 2 연결리스트의 부분 구간 출력
	printf("두 학생의 이름을 넣으시오>");
	scanf("%s %s", tnameA, tnameB);
	Print_between(First, tnameA, tnameB);

	// 3 학생 수 출력하기
	printf("지역 명을 넣으시오>");
	scanf("%s", location);
	num = Compute_num_students_of_location(First, location);
	printf("%d\n",num);



	printf("찾을 이름을 입력하시오>");
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

	// (4) 삭제작업
	if (curr != NULL)
		res = delete_node(&First, prev, curr);
	if (res == 0)
		printf("삭제실패.\n");
	else
		printf("%s 삭제성공.\n", stuname);

	//(5) 프린트
	Print_linked_list(First);
}


// 화일로부터 연결리스트 만드는 함수
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

//연결리스트의 부분 구간 출력 함수
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
// 학생 수 출력 함수
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

//리스트의 삭제 함수
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

//리스트의 출력
void Print_linked_list(list first)
{
	printf("The list contains: \n");
	for (; first; first = first->link)
		printf("%s %d %.1lf %s %s\n", first->name, first->st_no, first->gpa, first->phone, first->address);
}