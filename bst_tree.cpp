#include<iostream>

typedef struct node{
	int value;
	struct node* parent;
	struct node* lchild;
	struct node* rchild;
}*BSTNode;



//����Ԫ��
void insert(BSTNode head,int value){
    if(head->value == -1){
		head->value = value;
		head->parent = NULL;
		head->lchild = NULL;
		head->rchild = NULL;
	}
	else{
		if(value < head->value){
			if(!head->lchild){
				BSTNode tnode = new node();
				head->lchild = tnode;
				tnode->parent = head;
				tnode->value  = value;
				tnode->lchild = NULL;
				tnode->rchild = NULL;	
			}
			else{
				insert(head->lchild,value);
			}
		}
		else{
			if(!head->rchild){
				BSTNode tnode = new node();
				head->rchild = tnode;
				tnode->parent = head;
				tnode->value = value;
				tnode->lchild = NULL;
				tnode->rchild = NULL;		
			}
			else{
				insert(head->rchild,value);
			}
		}
	}
}


//����
void create_tree(int A[],int len,BSTNode head){
	int i;
	for(i=0;i<len;i++){
		insert(head,A[i]);
	}
}

//������
void inorder(BSTNode head){
	if(head->lchild != NULL)
		inorder(head->lchild);
	cout << head->value << endl;
	if(head->rchild != NULL)
		inorder(head->rchild);	
}

//������
BSTNode search(BSTNode head,int x){
	if(head->value != -1 && head->value == x){
		return head;
	}
	if(x < head->value && head->lchild != NULL){
		return search(head->lchild,x);
	}
	if(x >= head->value && head->rchild != NULL){
		return search(head->rchild,x);
	}
}

//�ǵݹ�����
BSTNode search2(BSTNode head,int x){
	while(head != NULL && head->value != x){
		if(x < head->value)
			head = head->lchild;
		else
			head = head->rchild;
	}
	return head;
	
}
//������СԪ��
BSTNode minimum(BSTNode head){
	while(head->lchild != NULL)
		head = head->lchild;
	return head;
}

//�������Ԫ��
BSTNode maxmum(BSTNode head){
	while(head->rchild != NULL)
		head = head->rchild;
	return head;
}

//������������µĺ��,currΪ��ǰ�ڵ� 
BSTNode successor(BSTNode curr){
	if(curr->rchild != NULL)
		return minimum(curr->rchild);
	BSTNode pnode = curr->parent;
	while(pnode != NULL && pnode->rchild == curr){
		curr = pnode;
		pnode = pnode->parent;
	}
	return pnode;
}
//��ѯ��������µ�ǰ����currΪ��ǰ�ڵ�
BSTNode predecessor(BSTNode curr){
	if(curr->lchild != NULL)
		return maxmum(curr->lchild);
	BSTNode pnode = curr->parent;
	while(pnode != NULL && pnode->lchild == curr){
		curr = pnode;
		pnode = pnode->parent;
	}
	return pnode;
}

//ɾ��ָ���Ľڵ�
BSTNode tree_delete(BSTNode root,BSTNode curr){
	BSTNode y,x;
	//���curr����ֻ��һ����Ů 
	if(curr->lchild == NULL || curr->rchild == NULL){
		y = curr;
	}
	//curr��������Ů 
	else{
		y = successor(curr);
	}
	//xָ����Ů����null,����y�ǲ���curr�ĺ�� 
	//���y��curr�ĺ�̵Ļ�����ôy�϶�û������Ů
	// 
	if(y->lchild != NULL){
		x = y->lchild;
	}
	else{
		x = y->rchild;
	}
	// 
	if(x != NULL){
		x->parent = y->parent;
	}
	//ɾ�����ڵ� 
	if(y->parent == NULL){
		root = x;
	}
	else if(y == y->parent->lchild){
		y->parent->lchild = x;
	}
	else{
		y->parent->rchild = x;		
	}
	if(y != curr){
		curr->value = y->value;
	}
	return y;
}


int main(){
	int A[] = {10,8,23,15,16,2,9,4,29};
	int len = 9;
	BSTNode head = new node();
	head->value = -1;
	head->lchild = NULL;
	head->rchild = NULL;
	create_tree(A,len,head);
//	inorder(head);
	BSTNode tnode = search(head,10);
	tree_delete(head,tnode);
	inorder(head);
	/*
	if(tnode != NULL){
		if(tnode->lchild != NULL)
			cout<<"��Ѱ1�������ڵ�:"<< tnode->lchild->value<<endl;
	}
	BSTNode succ = successor(tnode);
	cout<<"�ؼ���Ϊ9�Ľڵ�ĺ��Ϊ"<<succ->value<<endl; 
	tnode = search(head,15);
	if(tnode != NULL){
		BSTNode prec = predecessor(tnode);
    	cout<<"�ؼ���15��ǰ��:"<<prec->value<<endl;
    }
	BSTNode tnode2 = search2(head,23);
	if(tnode2 != NULL){
		if(tnode2->lchild != NULL)
			cout<<"��Ѱ2�������ڵ�:"<< tnode2->lchild->value<<endl;
	}
	BSTNode min_node = minimum(head);
	cout<<"��СԪ��Ϊ:"<<min_node->value<<endl;
	BSTNode max_node = maxmum(head);
	cout<<"���Ԫ��Ϊ:"<<max_node->value<<endl;
	*/
	system("pause");
	return 0;
}
