#include <iostream>
#include <deque>
using namespace std;

void main(){
   
    deque <int> num;
    deque <int>::iterator vnum;
    int a;

    for (a=0; a<100; a++){
        num.push_front(a);
    }

    for (a=1; a<100; a++){
        num.push_back(a);
    }

    for(vnum=num.begin(); vnum=num.end(); vnum++){
        cout << *vnum << " ";
    }
    cout << endl;

    system("pause");
}