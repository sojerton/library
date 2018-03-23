#include <iostream>

using namespace std;



class HUMAN{
private:
	int health, armor,manaPool;
public:
	void set(int health,int armor,int manaPool){
		this->health=health;
		this->armor=armor;
		this->manaPool=manaPool;
	}
	void get(){
		cout<<health<<endl<<armor<<endl<<manaPool<<endl;
	}
};
class Elf:virtual public HUMAN {
private:
	int agility;
public:
	Elf(int agil): agility(agil){}
	void Agility(int agility){
		cout<<agility<<endl;
	}
};
class Orc:virtual public HUMAN {
private:
	int strength;
public:
	Orc(int str):strength(str){}
	void Strength(int strength){
		cout<<strength<<endl;
	}
};
class Human:virtual public HUMAN {
private:
	int intellect;
public:
	Human(int in):intellect(in){}
	Human(const Human &other){this->intellect=other.intellect;}
	void Intellect(int intellect){
		cout<<intellect<<endl;
	}
	friend Orc;
};
class SonOrcElf:public Orc,public Elf{
public:
    void show(){cout<<"YA RODILSYA!"<<endl;}
};

class Hybrid
{
public:
    int maxHealth;
    Hybrid():maxHealth(150){}
    Hybrid(int first): maxHealth(first){}
    friend Hybrid operator+ (Hybrid&l, Hybrid& r);
    ~Hybrid(){}
};

Hybrid operator+ (Hybrid&l, Hybrid& r)
    {
        return Hybrid(l.maxHealth+r.maxHealth);
    }


int main()
{


    return 0;
}
