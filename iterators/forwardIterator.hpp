#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../node.hpp"
#include <stdexcept>

template<typename T>
class ForwardIterator{
    protected:
        Node<T>* current;
    public:
        ForwardIterator(){}
        ForwardIterator(Node<T>* node) : current(node){}

        ForwardIterator<T> operator=(ForwardIterator<T> node){
            this->current = node.current;
            return *this;
        }

        bool operator !=(ForwardIterator<T> node){
            return current != node.current;
        }

        ForwardIterator<T> operator++(){
            current = current->next;
            return *this;
        }

        T operator*(){
            return current->data;
        }

};
#endif