#pragma once
#include "node.hpp"


template <typename T>
class LinkedList{
    private:
    Node<T>* head;
    int size;
    public:
    LinkedList():head(nullptr), size(0){}

    void pushFront(T data){
        this->head = new Node<T>(data, head);
        size++;
    }
    
    void popFront(){
        if(!head)
            return;
        else{
            Node<T>* current = head;
            this->head = current->next;
            delete current;
            size--;
        }
    }

    void popBack(){
        if(head== nullptr){
            return;
        }else if(!head->next){
            delete head;
            this->head = nullptr;
            size--;
        }else{
            Node<T>* current = head;
            while(current->next->next){
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
            size--;
        }
    }

    void pushBack(T data){
        Node<T>* newNode = new Node<T>(data);
        if(!head)
            this->head = newNode;
        else{
            Node<T>* lastN = head;
            while(lastN->next){
                lastN = lastN->next;
            }
            lastN->next = newNode;
        }
        size++;
    }

    T front(){
        if(!size)
            return 0;
        else
            return this->head->data;
    }

    T back(){
        if(!size)
            return 0;
        else{
            Node<T>* auxNode = this->head;
            while(!!auxNode->next){
                auxNode = auxNode->next;
            }
            return auxNode->data;
        }
    }

    T operator[](int position){
        if(position > this->size){
            return 0;
        }
        Node<T>* auxN = head;
        while(position--){
            auxN = auxN->next;
        }
        return auxN->data;
    }

    bool empty(){
        return !head;
    }

    int getSize(){
        return size;
    }

    void clear(){
        Node<T>* deleteNode = this->head;
        while(deleteNode){
            Node<T>* auxN = deleteNode;
            deleteNode = deleteNode->next;
            delete auxN;
        }
    }

    void reverse(){
        if(!head)
            return;
        else{
            Node<T>* current = head;
            Node<T>* prev = nullptr;
            while(current){
                Node<T>* saveN = current->next;
                current->next = prev;
                prev = current;
                current = saveN;
            }
            this->head = prev;
        }
    }



    void print(){
        if(!head)
            return;
        Node<T>* aux = head;
        while(!!aux){
            cout << aux->data << ' ';
            aux = aux->next;
        }
        cout << endl;
    }
};