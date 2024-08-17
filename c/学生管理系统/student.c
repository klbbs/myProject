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
	    	default:printf("��⵽���������룬�������ڷ�Χ�ڵ�����\n");
	    		system("pause");
	    		system("cls");
	    		break;
			}
	}
    return 0;
}

void welcome(){
    printf("*********************************\n");
    printf("*\tѧ������ϵͳ\t\t*\n");
    printf("*********************************\n");
    printf("*\tѡ�����б�\t\t*\n");
    printf("*********************************\n");
    printf("*\t1.¼��ѧ����Ϣ\t\t*\n");
    printf("*\t2.��ӡѧ����Ϣ\t\t*\n");
    printf("*\t3.ͳ��ѧ����Ϣ\t\t*\n");
    printf("*\t4.����ѧ����Ϣ\t\t*\n");
    printf("*\t5.�޸�ѧ����Ϣ\t\t*\n");
    printf("*\t6.ɾ��ѧ����Ϣ\t\t*\n");
    printf("*\t7.���ɼ�����\t\t*\n");
    printf("*\t8.�˳�ϵͳ\t\t*\n");
    printf("*********************************\n");
}

void InputStudent(Node* head){
	
	Node* p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	printf("����ѧ��ѧ�ţ��������ɼ�\n");
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
		printf("ѧ��:%d������:%s���ɼ�:%d\n",info->student.StuNum,info->student.name,\
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
	printf("������%d\n",count);
	system("pause");
	system("cls");
}

void FindStudent(Node* head){
	printf("����ѧ��ѧ��:\n");
	int StuNum;
	scanf("%d",&StuNum);
	Node* p = head->next;
	while(p != NULL){
		if(p->student.StuNum == StuNum){
			printf("ѧ��ѧ�ţ�%d������:%s���ɼ�:%d\n",p->student.StuNum,\
			p->student.name,p->student.score);
			return;
		}
	}
	printf("δ�ҵ�ѧ��");
	system("pause");
	system("cls");
	return;
}

void SaveStudent(Node* head){
	FILE* file = fopen("./stu.info","w");
	if(file == NULL){
		printf("�����ļ�ʱ�򿪴��ļ�ʧ��\n");
	}
	Node* p = head->next;
	while(p != NULL){
		if(fwrite(&p->student,sizeof(Student),1,file) != 1){
			printf("д��ʧ��\n");
			return;
		}
		p = p->next;
	}
	fclose(file);
	
}

void LoadStudent(Node* head){
	FILE* file = fopen("./stu.info","r");
	if(!file){
		printf("û��ѧ���ļ���������ȡ\n");
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
	printf("��ȡ�ļ��ɹ�\n");
}

void ModifyStudent(Node* head){
	printf("������Ҫ�޸ĵ�ѧ��ѧ��\n");
	int StuNum;
	scanf("%d",&StuNum);
	Node* p = head->next;
	while(p != NULL){
		if(p->student.StuNum == StuNum){
			printf("��������ѧ�������ͳɼ�\n");
			scanf("%s%d",p->student.name,&p->student.score);
			printf("�޸����ݳɹ�\n");
			SaveStudent(head);
			system("pause");
			system("cls");
			return;	
		}
		p = p->next;
	}
	system("pause");
	system("cls");
	printf("δ�ҵ���ѧ�ŵ�ѧ��\n");
}

void deleteStudent(Node* head){
	printf("����ɾ��ѧ����ѧ��\n");
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
			printf("ɾ���ɹ�\n");
			system("pause");
			system("cls");
			return;
		}
		printf("δ�ҵ�Ŀ��ѧ��\n");
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


