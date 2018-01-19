#include <iostream>

using namespace std;

class car{
protected:
    int height;
    float speed;
public:
    car(){}

    car (int height, float speed){
        this->height = height;
        this->speed= speed;

        print();
    }

    void setValues (int height, float speed){
        this->height = height;
        this->speed= speed;
    }
    void print () {
        cout<<this->height<<" - "<<this->speed<<endl;
    }

    ~car (){
        cout<<"all is ok!"<<endl;
    }
};

class motorcycle : public car {
public:
    void print(){
        cout<<height<<" - "<<speed<<endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    car shkoda (1100, 240.5);

    motorcycle bmw;
    bmw.setValues(25, 125.1);
    bmw.print();

    cin.get();
    return 0;
}
