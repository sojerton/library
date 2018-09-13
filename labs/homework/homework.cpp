#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>


using namespace std;

void show_vector( vector<int>&a)
{
        for (vector<int>::iterator it = a.begin() ; it!=a.end() ; ++it)
                cout<<*it<<" ";
}

int main()
{
    int N, psort=0, increase=1, maximum, minimum;
    string buff, str;
    vector<int> numbers, vIncrease;
    ifstream fin;
    fin.open("input.txt");
    getline(fin, buff);
    istringstream is(buff);
    while (is){
        is >> N;
    }
    getline(fin, str);
    istringstream iss(str);
    while (iss){
        int num;
        iss >> num;
        numbers.push_back(num);
    }
    numbers.pop_back();
    fin.close();

    for(int i=0; i<numbers.size(); i++){
        vIncrease.push_back(numbers[i]);
    }
    sort(numbers.begin(), numbers.end());
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i]>0){
            psort+= numbers[i];
        }
        if(i==0){
            minimum=numbers[i];
        }
        if(i==numbers.size()-1){
            maximum=numbers[i];
        }
    }
    int condition=0;
    for(int i=0; i<vIncrease.size(); i++){
        if(vIncrease[i]==minimum){
            condition++;
        }
        if(vIncrease[i]==maximum){
            condition++;
        }
        if(vIncrease[i]!=minimum && vIncrease[i]!=maximum && condition==1){
            increase*= vIncrease[i];
        }
    }

    cout << psort <<endl;
    cout << increase <<endl;
    show_vector(numbers);
    ofstream fout;
    fout.open("output.txt");
    fout << psort << " " << increase;
    fout.close();
    return 0;
}
