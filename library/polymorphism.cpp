#include <iostream>
#include <windows.h>

using namespace std;

class person
{
private:
    char name[20];
public:
    void Get(){cout <<name<<" ";}
    void Set(){cout<<"Name: "; cin.get();cin.getline(name,19);}
    virtual void GetData()=0;
    virtual bool outst()=0;
};

class teacher: public person
{
private:
    int kol;
public:
    void GetData(){person::Set(); cout<<"Kol: "; cin>>kol;}
    bool outst()    {if (kol>50) {cout<<" kol="<<kol; return true;} else return false;}
};

class student: public person
{
private:
    float ball;
public:
    void GetData(){person::Set(); cout<<"Sr.Ball: "; cin>>ball;}
    bool outst()    {if (ball>4) {cout<<" Ball="<<ball;return true;} else return false;}
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
        person *ptr[10];
        int n=0;
        char ch;
        do
        {
            cout<<"Student or Teach (s/t)"<<endl;
            cin>>ch;
            if(ch=='s')
                ptr[n]=new student;
            else
                ptr[n]=new teacher;
            ptr[n]->GetData();
            n=n+1;
            cout<<"Input person?(y/n)"; cin>>ch;
        }
        while(ch=='y');
        for(int i=0; i<n; i++)
        {
            cout<<endl; ptr[i]->Get();
            if (ptr[i]->outst()==true) cout<<" This is outstanding person"<<endl;
        }
    cout<<endl;
    system("pause");
    return 0;
}
