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
            Node<T>* head_ = head;
            this->head = head_->next;
            delete head_;
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
            Node<T>* head_ = head;
            while(head_->next->next){
                head_ = head_->next;
            }
            delete head_->next;
            head_->next = nullptr;
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
    
    void sort(){
   		this->head = sortLk(this->head);
    }

    Node<T>* sortLk(Node<T>* head_){
        if(!head_ || !head_->next){
            return head_;
        }
        Node<T>* left = head_;
        Node<T>* right = head_;
        while(right && right->next){
            right = right->next;
            if(right->next) left = left->next;
            if(right->next) right = right->next;
        }
        right = left->next;
        left->next = nullptr;
        return merge(sortLk(head_), sortLk(right));
    }

    Node<T>* merge(Node<T>* n1, Node<T>* n2){
        if(n1 && n2) this->head = n1->data > n2->data ? n2: n1;
        else this->head = n1 ? n1 : n2;
        Node<T>* current = this->head;
        if(this->head == n1) n1 = n1->next;
        else n2 = n2->next;

        while(n1 && n2){
            if(n1->data > n2->data){
                current->next = n2;
                n2 = n2->next;
            }else{
                current->next = n1;
                n1 = n1->next;
            }
            current = current->next;
        }

        while(n1){
            current->next = n1;
            n1 = n1->next;
            current = current->next;
        }

        while(n2){
            current->next = n2;
            n2 = n2->next;
            current = current->next;
            
        }
        return this->head;
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
            Node<T>* head_ = head;
            Node<T>* prev = nullptr;
            while(head_){
                Node<T>* saveN = head_->next;
                head_->next = prev;
                prev = head_;
                head_ = saveN;
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
