#pragma once
#include <iostream>

using namespace std;
template <typename T>
struct Node{
    T data;
    Node<T>* next;
    Node(T data, Node<T>* n = nullptr):data(data), next(n){}

};