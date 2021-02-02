#include "linkedList.hpp"
//#include <bitset/stdc++.h>

int main(){
    LinkedList<int> lk;

    lk.pushFront(5);
    lk.pushBack(10);
    lk.pushFront(2);
    lk.pushFront(12);
    lk.print();
    lk.reverse();
    lk.print();
    cout << lk[2] << endl;
    return 0;
}