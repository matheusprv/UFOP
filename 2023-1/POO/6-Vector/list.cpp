#include <list>
#include <iostream>
using namespace std;


int main(){

    list<int> li;

    for(int i=0; i<4; i++){
        li.push_back(i);
        cout << i << " " << endl;
    }

    return 0;
}