#include "linkedList.hpp"
//#include <bitset/stdc++.h>

int main(){
    LinkedList<int> lk;

    lk.pushFront(5);
    lk.pushBack(10);
    lk.pushFront(2);
    lk.pushFront(12);
    lk.pushFront(112);
    lk.pushFront(122);
    lk.pushFront(89);
    lk.pushFront(1);
    lk.print();
    lk.reverse();
    lk.print();
    cout << lk[2] << endl;
    lk.print();
    lk.sort();
    lk.print();
    return 0;
}