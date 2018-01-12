#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

void qs(char *items, int left, int right){
    int i,j;
    char x,y;
    i = left; j = right;
    x = items[(left + right)/2];
    do {
        while ((items[i]<x) && (i<right)) i++;
        while ((x<items[j]) && (j>left)) j--;
        if(i<=j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    }   while (i<=j);

    if(left<j) qs(items, left, j);
    if(i<right) qs(items, i, right);
};

int main()
{
    setlocale(LC_ALL, "Russian");
    char str[] = "asdasdqwret hjhgfsa fjlkzxklj";
    int len = strlen(str);
    cout<<"Массив в исходном виде: "<<str<<endl;
    qs(str, 0, len-1);
    cout<<"Отсортированный массив: "<<str<<endl;
    cin.get();
    return 0;
}
