#include<iostream>
#include<time.h>
#include<windows.h>
using namespace std;
#define m 13		//Ԫ�ظ���
#define n 20		//hash table��С 

struct node{
	int x;
	struct node* next;
};

//ʹ�ó�������key 
int hash(int x){
	int remain = x % m;
	return remain;
}

//���뵽hash table�� 
void hash_insert(struct node table[],int x){
	int key = hash(x);
	struct node* head;
	if(table[key].x != -1){
		struct node* tnode = new node();
		tnode->x = x;
		head = table[key].next;
		table[key].next = tnode;
		tnode->next = head;
	}
	else{
		table[key].x = x;
	}
}

//��hash table��������,����table[h(k)]���йؼ��ֵ�Ԫ�� 
int hash_search(struct node table[],int k){
	struct node* head;
	head = &table[k];
	while(head!=NULL){
		if(head->x == k){
			return head->x;
		}
		head = head->next;
	}
	return -1;
}

//��hash table��ɾ��Ԫ��
void hash_delete(struct node table[],int x){
	int h = hash(x);
	struct node	*prev,*cur;
	prev = (struct node	*)&table[h];
	cur  =  prev;
	//headΪĿ��Ԫ�� 
	if(cur->x == x){
		
		cur = cur->next;
		if(cur != NULL){
			prev->x = cur->x;
			prev->next = cur->next;
		}
		else{
			prev->x = -1;
		}
	}
	else{
		cur = cur->next;
		while(cur != NULL){
			if(cur->x ==x){
				prev->next = cur->next;
				break;
			}
			prev =cur;
			cur = cur->next;
		}
	}
}

int main(){
	struct node hash_table[m];
	struct node* head;
	int i,rand_num;
	//��ʼ��hash����
	for(i=0;i<m;i++){
		hash_table[i].x = -1;
		hash_table[i].next = NULL;
	}
	
	for(i=0;i<n;i++){
/*
		Sleep(1000);
		srand(time(0));
		rand_num = rand();
*/
		hash_insert(hash_table,i);	
	}
	
	//��ʾ���е�Ԫ�� 
	for(i=0;i<m;i++){
		head = &hash_table[i];
		if(head!=NULL){
			do{
				cout<<head->x<<" ";
				head = head->next;
			}while(head != NULL);
			cout<<endl;
		}
	}
	//���ҹؼ���Ϊ6��Ԫ��
	if(hash_search(hash_table,0)!=-1){
		hash_delete(hash_table,0);
	}
	cout<<endl;
	//��ʾ���е�Ԫ�� 
	
	for(i=0;i<m;i++){
		head = &hash_table[i];
		if(head!=NULL){
			do{
				cout<<head->x<<" ";
				head = head->next;
			}while(head != NULL);
			cout<<endl;
		}
	}
	
	system("pause");
	return 0;
}
