#include<stdio.h>

#define	ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
	if( allocbuf + ALLOCSIZE - allocp -n >=0){
		allocp += n;
		return allocp -n;
	} else{/*c���Ա�֤��0��Զ������Ч�����ݵ�ַ������0��ζ�ſ�������ʾ�������쳣�¼�*/
		return 0;
	}
}
void afree(char* p)
{
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
main()
{

	char* p;
	int i;
	if((p = alloc(100))){
		for(i=0;i<100;i++,p++){
			*p = 'A';
		}	
	}
	afree(p - 100);
	return 0;
}
