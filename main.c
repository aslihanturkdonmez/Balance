
#include<stdio.h>
#include<stdlib.h>
#define bool int

// Yigin yapisi
typedef struct stackNode
{
char data;
struct stackNode *link;
}STACK;

// Yığından eleman çıkarma
int pop(STACK** first)
{
char dataOutPtr;
STACK *top;

//Stack boş ise
if (*first == NULL)
{
	printf("Stack is empty");
	getchar();
	exit(0);
}
else
{
	top = *first;
	dataOutPtr = top->data;
	*first = top->link;
	free(top);
	return dataOutPtr;
}
}

//Yigina eleman ekleme
void push(STACK** first, int new_data)
{

STACK* new_node =(STACK*) malloc(sizeof(STACK));

if (new_node == NULL)
{
	getchar();
	exit(0);
}

new_node->data = new_data;
new_node->link = (*first);
(*first) = new_node;
}

//paranezler eşleşiyorsa 1 döndürür
bool match(char character1, char character2)
{
if (character1 == '(' && character2 == ')')
	return 1;
else if (character1 == '{' && character2 == '}')
	return 1;
else if (character1 == '[' && character2 == ']')
	return 1;
else
	return 0;
}

// ifade dengeli mi kontrolü yapar dengeliyse 1 döndürür
bool balanced(const char p[], size_t n)
{

STACK *stack = NULL;

//eş parantezleri kontrol etmek için ifadeyi gezme döngüsü
for (int i = 0 ; i<n ;i++ )
{
	// başlangıç paranteziyse yığına ekle
	if (p[i] == '{' || p[i] == '(' || p[i] == '[')
		push(&stack, p[i]);

	//bitiş paranteziyse yığından çıkarır ve eşli mi kontrol eder
	if (p[i] == '}' || p[i] == ')' || p[i] == ']')
	{

		//eşi yok ise false döndürür
		if (stack == NULL)
		return 0;

		//eşi var ama uyumlu mu kontrolü
		else if ( !match(pop(&stack), p[i]) )
		return 0;
	}
}

//Tek kalan ifadeyi kontrol etme
if (stack == NULL)
	return 1;
else
	return 0;
}


int main()
{
char p[100] ;

printf("Ifade : ");
gets(p);

if (balanced(p,100))
	printf("Balanced \n");
else
	printf("Not Balanced \n");
return 0;
}


