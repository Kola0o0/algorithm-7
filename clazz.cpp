#include<iostream>
using namespace std;
class Str{
   public:
   Str(const char* str);
   Str(const Str &another);
   ~Str();
   Str& operator = (const Str&rhs);
   char* m_data;
};

Str::Str(const char* str){
   //strlen��strΪnullʱ���׳��쳣
   if(str==NULL){
      m_data = new char[1];
      m_data[0] = '\0';
   }
   else{
      int len = strlen(str);
      m_data = new char[len+1];
      strcpy(m_data,str);
   }
}

Str::Str(const Str& another){
   int len = strlen(another.m_data);
   m_data = new char[len+1];
   strcpy(m_data,another.m_data);
}

Str& Str::operator = (const Str &rhs){
   if(this == &rhs)
      return *this;
   delete[] m_data;              //ɾ��ԭ�����ݣ��¿�һ���ڴ�
   m_data = new char[strlen(rhs.m_data)+1];
   strcpy(m_data,rhs.m_data);
   return *this; 
}
Str::~Str(){
   //�������� 
   delete[] m_data;
}

int main(){
   char* ch="I am a student!";
   Str *tstr = new Str(ch);
   Str *tstr2 = new Str(*tstr);
   tstr2->m_data = "I am a teacher!";
   tstr = tstr2;
   cout<<tstr->m_data<<endl; 
   tstr->~Str();
   system("pause");
   return 0;
}
