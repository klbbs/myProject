#include "student.h"

int main(){

    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    LoadStudent(head);
	while(1){
		welcome();
    
    	char c = _getch();
    	switch(c){
	    	case '1':InputStudent(head);
	    		break;
	    	case '2':PrintStudent(head);
	    		break;
	    	case '3':CountStudent(head);
	    		break;
	    	case '4':FindStudent(head);
	    		break;
	    	case '5':ModifyStudent(head);
	    		break;
	    	case '6':deleteStudent(head);
	    		break;
	    	case '7':sortStudent(head);
	    		break;
	    	case '8':
	    		exit(0);
	    		break;
	    	default:printf("检测到非正常输入，请输入在范围内的数字\n");
	    		system("pause");
	    		system("cls");
	    		break;
			}
	}
    return 0;
}

void welcome(){
    printf("*********************************\n");
    printf("*\t学生管理系统\t\t*\n");
    printf("*********************************\n");
    printf("*\t选择功能列表\t\t*\n");
    printf("*********************************\n");
    printf("*\t1.录入学生信息\t\t*\n");
    printf("*\t2.打印学生信息\t\t*\n");
    printf("*\t3.统计学生信息\t\t*\n");
    printf("*\t4.查找学生信息\t\t*\n");
    printf("*\t5.修改学生信息\t\t*\n");
    printf("*\t6.删除学生信息\t\t*\n");
    printf("*\t7.按成绩排序\t\t*\n");
    printf("*\t8.退出系统\t\t*\n");
    printf("*********************************\n");
}

void InputStudent(Node* head){
	
	Node* p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	printf("输入学生学号，姓名，成绩\n");
	scanf("%d%s%d",&p->student.StuNum,p->student.name,&p->student.score);
	
	Node* rear = head;
	while(rear->next != NULL){
		rear = rear->next;
	}
	rear->next = p;
	SaveStudent(head);
	system("pause");
	system("cls");
}

void PrintStudent(Node* head){
	Node* info = head->next;
	while(info != NULL){
		printf("学号:%d，姓名:%s，成绩:%d\n",info->student.StuNum,info->student.name,\
		info->student.score);
		info = info->next;
	}
	system("pause");
	system("cls");
}

void CountStudent(Node* head){
	Node* p = head;
	int count;
	while(p->next != NULL){
		count++;
		p = p->next;
	}
	printf("人数：%d\n",count);
	system("pause");
	system("cls");
}

void FindStudent(Node* head){
	printf("输入学生学号:\n");
	int StuNum;
	scanf("%d",&StuNum);
	Node* p = head->next;
	while(p != NULL){
		if(p->student.StuNum == StuNum){
			printf("学生学号：%d，姓名:%s，成绩:%d\n",p->student.StuNum,\
			p->student.name,p->student.score);
			return;
		}
	}
	printf("未找到学生");
	system("pause");
	system("cls");
	return;
}

void SaveStudent(Node* head){
	FILE* file = fopen("./stu.info","w");
	if(file == NULL){
		printf("保存文件时打开此文件失败\n");
	}
	Node* p = head->next;
	while(p != NULL){
		if(fwrite(&p->student,sizeof(Student),1,file) != 1){
			printf("写入失败\n");
			return;
		}
		p = p->next;
	}
	fclose(file);
	
}

void LoadStudent(Node* head){
	FILE* file = fopen("./stu.info","r");
	if(!file){
		printf("没有学生文件，跳过读取\n");
		return;
	}
	Node* fresh = (Node*)malloc(sizeof(Node));
	fresh->next = NULL;
	Node* move = head;
	while(fread(&fresh->student,sizeof(Student),1,file) == 1){
		move->next = fresh;
		move = fresh;
		fresh = (Node*)malloc(sizeof(Node));
		fresh->next = NULL;
	}
	free(fresh);
	fclose(file);
	printf("读取文件成功\n");
}

void ModifyStudent(Node* head){
	printf("输入需要修改的学生学号\n");
	int StuNum;
	scanf("%d",&StuNum);
	Node* p = head->next;
	while(p != NULL){
		if(p->student.StuNum == StuNum){
			printf("重新输入学生姓名和成绩\n");
			scanf("%s%d",p->student.name,&p->student.score);
			printf("修改数据成功\n");
			SaveStudent(head);
			system("pause");
			system("cls");
			return;	
		}
		p = p->next;
	}
	system("pause");
	system("cls");
	printf("未找到此学号的学生\n");
}

void deleteStudent(Node* head){
	printf("输入删除学生的学号\n");
	int StuNum = 0;
	scanf("%d",&StuNum);
	
	Node* move = head;
	while(move->next != NULL){
		if(move->next->student.StuNum == StuNum){
			Node* tmp = move->next;
			move->next = move->next->next;
			free(tmp);
			tmp = NULL;
			SaveStudent(head);
			printf("删除成功\n");
			system("pause");
			system("cls");
			return;
		}
		printf("未找到目标学生\n");
		system("pause");
		system("cls");
	}
}

void sortStudent(Node* head){
	Node* turn;
	Node* move;
	Node* save = NULL;
	for(turn = head->next;turn->next != NULL;turn = turn->next){
		for(move = head->next;move->next != save;move = move->next){
			if(move->student.score > move->next->student.score){
				Student temp = move->student;
				move->student = move->next->student;
				move->next->student = temp;
			}
		}
		save = move;
	}
	PrintStudent(head);
}


