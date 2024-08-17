#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct _student
{
    int StuNum;
    char name[20];
    int score;
}Student;

typedef struct _node
{   
    struct _node* next;
    Student student;
}Node;

void welcome();
void InputStudent(Node* head);
void PrintStudent(Node* head);
void CountStudent(Node* head);
void FindStudent(Node* head);
void SaveStudent(Node* head);
void LoadStudent(Node* head);
void ModifyStudent(Node* head);
void deleteStudent(Node* head);
void sortStudent(Node* head);
