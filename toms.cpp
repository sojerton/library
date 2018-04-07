#include <iostream>
#include <vector>//векторы
#include <algorithm>//подключаем сортировку для векторов
//вектор с данными - чередующийся массив данных с именем и страницами произведений
//
//
using namespace std;

int Size, val;   //количество книг, количество страниц в томах
bool ending=true; //проверка на конец массива
int K=0, prop=0;

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

class Tom
{
public:
    int j;
    void Set(int *&Arr, string *&ArrM, const int N){ //выделяем память под массив тома
        Arr=new int[N];
        ArrM=new string[N];
    }
    void Fill(int *Arr, string *ArrM, const int N, vector<NOVEL>&s){ //заполняем массив ранее отсортированным вектором с романами
        int res=0;
        K=K+prop; //чтобы цикл начинался с места остановки
        for(j=K; j<N; j++){
            res = res + s[j].numPages; //проверка на заполненность тома
            if(res < val){
                Arr[j]=s[j].numPages; //запоняем массив из вектора романов
                ArrM[j]=s[j].name;
                if(j==N-1) ending=false; //если конец вектора, то выходим
            }else{prop=j-K; break;}
        }
    }
    void Show(int *Arr, string *ArrM, const int num){ //выводим на экран
        cout<<"TOM "<<num<<endl;
        for(int i=K; i<j; i++){
            cout<<ArrM[i]<<" ---- "<<Arr[i]<<" страниц"<<endl;
        }
    }
};

class Sort //функция сортировки векторов
{
public:
    bool operator() (const NOVEL& l, const NOVEL& r) //перегрузка оператора > для векторов
    {return  l.numPages > r.numPages;}
}sortObject;

void first(vector<NOVEL>&s, NOVEL&novels){ //функция записи и сортировки романов для дальнейшей записи в тома
    cout<<"Введите количество книг: ";
    while (!(cin >> Size) || (cin.peek() != '\n')) // защита от ввода неправильных данных
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Ошибка! Попробуйте снова." << endl;
    }
    string name;
    int numPages;
    register int i;
    for (i=0; i<Size; i++){
        s.push_back(novels);
        cout<<"название книги "<<i+1<<" ";
        cin.get();
        getline(cin, name);
        cout<<"Количество страниц для "<< name <<endl;
        while (!(cin >> numPages) || (cin.peek() != '\n')) // защита от ввода неправильных данных
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Ошибка! Попробуйте снова." << endl;
        }
        s.at(i).Set(name, numPages);
    }
    sort(s.begin(), s.end(), sortObject);
    for(int i = 0; i < s.size(); i++)
    cout << s[i].name<<" "<<s[i].numPages<<endl;
    cout<<"Нажмите ENTER"<<endl;
}

void Menu(void){
    system("cls");
    cout << "Меню"<<endl;
    cout << "1. Указать несколько романов."<<endl;
    cout << "2. Составить сборники сочинений."<<endl;
    cout << "3. для выхода."<<endl;
}

int main()
{
    setlocale(LC_ALL,"rus");
    Menu();
    vector <NOVEL> s;//создаем массив романов
    NOVEL novels;
    int key;
    int num=1;
    cin >>key;//значение для меню
    bool A=true;
    while (A==true){    //запускаем бесконечный цикл
        if (key<4 && key>0) {
            switch (key){
            case 1:
                first(s, novels);
                cin.get();
                cin.get();
                Menu();
                cin>>key;
                break;
            case 2:{
                int *Ptr = NULL; //инициализируем ссылку на имя
                string *PtrM = NULL; // и страницы
                cout<<"Введите размер томов: ";
                while (!(cin >> val) || (cin.peek() != '\n')) // защита от ввода неправильных данных
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Ошибка! Попробуйте снова." << endl;
                }
                for(int i=0; i<Size; i++){
                    if(ending){ //пока не дойдет до конца вектора
                        Tom *a = new Tom[Size]; // создаем динамический массив томов
                        a[i].Set(Ptr, PtrM, Size);
                        a[i].Fill(Ptr, PtrM, Size, s);
                        a[i].Show(Ptr, PtrM, num);
                        num++; //для счетчика томов
                    }else{break;}
                }
                cout<<"Нажмите ENTER"<<endl;
                cin.get();
                cin.get();
                Menu();
                cin>>key;
                break;}
            case 3:   exit(0);
            }
        }
    else {cout<<"Неверное значение"<<endl;
    A=false;}
    }
    cin.get();
    return 0;
}
