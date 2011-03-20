#include<iostream>
using namespace std;

int match(char* , char*);
int matchhere(char* , char*);
int matchstar(int , char*, char*);

/* match:��text�в���regexp */
int match(char* regexp,char *text)
{
    if(regexp[0] =='^')
       return matchhere(regexp+1,text);
    do{/*��ʹ�ַ���Ϊ��ʱҲ������*/
       if(matchhere(regexp,text))
          return 1;
    }while(*text++ != '\0');
    return 0;		
		 	   	
}


/* matchhere:��text�Ŀ�ͷ����regexp */
int matchhere(char* regexp,char* text)
{
    if(regexp[0]=='\0')
       return 1;
    if(regexp[1] == '*')
       return matchstar(regexp[0],regexp + 2,text);
    if(regexp[0] =='$' && regexp[1] == '\0')
       return *text == '\0';
    if(*text != '\0' &&(regexp[0]=='.' || regexp[0] == *text))
       return matchhere(regexp + 1,text + 1);
    return 0;
}

/* matchstar:��text�Ŀ�ͷ����C* regexp */
int matchstar(int c,char* regexp,char * text){
    do{
		/*ͨ���ƥ���������ʵ��*/
		if(matchhere(regexp,text))
			return 1; 
	}while(*text != '\0' && (*text++ == c || c == '.'));
	return 0;
}

int main(){
	char* regexp = "xabc$";
	char* text 	 = "xabcyyyyyyxabc";
	cout<<match(regexp,text);
	system("pause");
	return 0;
}
