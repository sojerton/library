#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>

using namespace std;

static int Size;

class NOVEL
{
public:
    string name;
    int numPages;
    void Set(string a, int b){
        name=a;
        numPages=b;
    }
};

class TOM
{
public:
    struct Novel{
        string name;
        int numPages;
    }data[];
};

class Sort
{
public:
    bool operator() (const NOVEL& l, const NOVEL& r)
    {return  l.numPages > r.numPages;}

    bool operator() (const TOM& l, TOM& r)
	{return (l::Novel.numPages==r::Novel.numPages && l::Novel.name==r::Novel.name);}

}sortObject;

void Menu(void){
    system("cls");
    cout << "Меню"<<endl;
    cout << "1. Указать несколько романов."<<endl;
    cout << "2. Составить сборники сочинений."<<endl;
    cout << "3. для выхода."<<endl;
}

void first(vector<NOVEL>&s, NOVEL&novels){
    cout<<"Введите количество книг: "; cin>>Size;
    string name;
    int numPages;
    register int i;
    for (i=0; i<Size; i++){
        s.push_back(novels);
        cout<<"название книги "<<i+1<<" ";
        cin.get();
        getline(cin, name);
        cout<<"Количество страниц для "<< name <<endl;
        cin>>numPages;
        s.at(i).Set(name, numPages);
    }
    sort(s.begin(), s.end(), sortObject);
    for(int i = 0; i < s.size(); i++)
    cout << s[i].name<< ' '<<s[i].numPages<<endl;
    cout<<"Нажмите ENTER";
}

void second(NOVEL&novels, vector<NOVEL>&s){
    int tempN, value, res=0;
    string tempS;
    cout<<"Введите размер томов: "; cin>>value;
    vector <TOM> v;
    TOM tom;
    int k=0;
    for(int i=0; i<Size; i++){
        v.push_back(tom);
        int j=0;
        if (res < value){
        res += s[i].numPages;
        v.at(k).data[j].numPages=s[i].numPages;
        v.at(k).data[j].name=s[i].name;
        j++;
        i++;
        cout<<"xui";
        }
    }
    for(vector<TOM>::iterator it = v.begin(); it != v.end(); it++)
    cout <<value<<"  qweeeeeeeeeeeeeeeee"<<endl;
    cout<<"Нажмите ENTER";
}

int main()
{
    setlocale(LC_ALL,"rus");
    Menu();
    int key;
    vector <NOVEL> s;
    NOVEL novels;
    cin >>key;
    bool A=true;
    while (A==true){
        if (key<6 && key>0) {
            switch (key){
            case 1:
                first(s, novels);
                cin.get();
                cin.get();
                Menu();
                cin>>key;
                break;
            case 2:
                second(novels, s);
                cin.get();
                cin.get();
                Menu();
                cin>>key;
                break;
            case 3:   exit(0);
            }
        }
    else {cout<<"Неверное значение"<<endl;
    A=false;}
    }
    cin.get();
    return 0;
}
