#include<stdio.h>

#define RED 	0
#define BLACK 	1

//����ڵ�ṹ��node��ָ��ýṹ���ָ�� 
struct node
{
	struct node* parent;
	struct node* left;
	struct node* right;
	int color;
	int key;
}NIL_NODE = {NULL,NULL,NULL,BLACK,-1};

typedef struct node *nodeptr;
nodeptr NIL= &NIL_NODE;
nodeptr ROOT; 

void creat_tree(nodeptr z);
void left_rotate(nodeptr x);
void right_rotate(nodeptr x);
void insert(nodeptr z);
void insert_fixup(nodeptr z);

main()
{
	int i,num;
	//�ṹ�ڵ�����
	struct node nodes[9] = {
					{NULL ,NIL,NIL,BLACK,11},
					{NULL,NIL,NIL,RED,2},
					{NULL,NIL,NIL,BLACK,14},
					{NULL,NIL,NIL,BLACK,1},
					{NULL,NIL,NIL,BLACK,7},
					{NULL,NIL,NIL,RED,13},
					{NULL,NIL,NIL,RED,15},
					{NULL,NIL,NIL,RED,5},
					{NULL,NIL,NIL,RED,8}
					};
	nodeptr tnode = malloc(sizeof(struct node));
	//���������
	ROOT = NIL;
	i=0;
	num = 9;
	while(i<num){
		creat_tree(&nodes[i++]);
	}
	tnode->key = 12;
	insert(tnode);
	return 0;
}

void creat_tree(nodeptr z)
{
	nodeptr x,y;
	int i;
	x = ROOT;
	y = NIL;
	while(x != NIL){
		y = x;
		if(z->key <= x->key){
			x = x->left;
		}else{
			x = x->right;
		}
	}
	z->parent = y;
	if( y == NIL){
		ROOT = z;
		ROOT->parent = NIL;
	}else if(y->key > z->key){
		y->left = z;
	}else{
		y->right = z;
	}
	z->left = NIL;
	z->right = NIL;
}

void insert(nodeptr z)
{
	nodeptr x,y;
	int i;
	x = ROOT;
	y = NIL;
	while(x != NIL){
		y = x;
		if(z->key <= x->key){
			x = x->left;
		}else{
			x = x->right;
		}
	}
	z->parent = y;
	if( y == NIL){
		ROOT = z;
	}else if(y->key > z->key){
		y->left = z;
	}else{
		y->right = z;
	}
	z->left = NIL;
	z->right = NIL;
	z->color = RED;
	insert_fixup(z);
}

void insert_fixup(nodeptr z)
{
	nodeptr p,pp,y,left,right;
	//ѭ������ʽ 
	while( (p = (nodeptr)(z->parent)) != NIL && (pp = (nodeptr)(p->parent)) != NIL && (p->color == RED)){
		//z����Ϊz�游������
		if(p == pp->left){
			y = pp->right;
			//��һ����� 
			if(y->color == RED){
				p->color = BLACK;
				pp->color = RED;
				y->color = BLACK;
				z = pp;					//z�������� 
			}
			else{
				//�ڶ������ 
				if(z == p->right){
					z = p;					//z����һ�� 
					left_rotate(z);	//z����һ�� 
				}
				//��������� 
				p->color = BLACK;
				pp->color = RED;
				right_rotate(pp);
			}
		}
		//z����Ϊz�游������ 
		else{
			y = pp->left;
			if(y->color == RED){
				p->color = BLACK;
				y->color = BLACK;
				pp->color =	RED;
				z = pp;
			}else{ 
				if(z == p->left){
					z = p;					//����һ�� 
					right_rotate(z);		//����һ�� 
				}
				p->color = BLACK;
				pp->color = RED;
				left_rotate(pp);
			}
		}
	}
	ROOT->color = BLACK;
}

void left_rotate(nodeptr x)
{
	nodeptr y,p;
	y = x->right;
	x->right = y->left;
	p = x->parent;
	y->parent = p;
	if(p == NIL)
		ROOT = y;
	else if(x == p->left)
		p->left = y;
	else
		p->right = y;
	y->left = x;
	x->parent = y;
}

void right_rotate(nodeptr x)
{
	nodeptr y,p;
	y = x->left;
	x->left = y->right;
	p = x->parent;
	y->parent = p;
	if(p == NIL)
		ROOT = y;
	else if(x == p->left)
		p->left = y;
	else
		p->right = y;
	y->right = x;
	x->parent = y;
}
