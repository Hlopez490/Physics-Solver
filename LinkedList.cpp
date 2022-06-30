#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(){
    head = NULL;
    length = 0;
}

LinkedList::~LinkedList(){
    recDestruct(head);
}

LinkedList::LinkedList(Node* newhead, int newLength){
    head = newhead;
    length = newLength;
}

LinkedList::LinkedList(LinkedList &ogList){
    Node* traverse = ogList.getHead();
    int size = ogList.getLength();
    length = size;
    Node* prev = nullptr;
    head = nullptr;
    while(size){
        Node* newNode = new Node;
        if(!head){
            newNode->setExp(traverse->getExp());
            newNode->setCoef(traverse->getCoef());
            newNode->setNext(NULL);
            head = newNode;
            prev = newNode;
        }else{
            prev->setNext(newNode);
            newNode->setExp(traverse->getExp());
            newNode->setCoef(traverse->getCoef());
            newNode->setNext(NULL);
            prev = newNode;
        }
        traverse = traverse->getNext();
        size--;
    }
}

void LinkedList::recDestruct(Node* start){

    if (start == NULL) return;

    recDestruct(start->getNext());

    length--;
    free(start);

}

void LinkedList::setHead(Node* newHead){
    length =0;
    head = newHead;
    Node* traverse = head;
    while(traverse != nullptr){
        length++;
        traverse = traverse->getNext();
    }
}

void LinkedList::deleteNode(Node* changeNode, Node* delNode){

    changeNode->setNext(delNode->getNext());
    length--;

}

void LinkedList::operator += (Node* newNode){

    if(!head){
        head = newNode;
        length++;
    }else{
        Node *traverse = head;
        while(traverse->getNext() != nullptr){
            traverse = traverse->getNext();
        }
        traverse->setNext(newNode);
        length++;
    }
}

Node* LinkedList::operator[](int index){
    if(index <= length){
        if(head == nullptr){
            return head;
        }
        Node* traverse = head;
        while(index>0){
            traverse = traverse->getNext();
            --index;
        }
        return traverse;
    }
    return nullptr;
}


void LinkedList::sortList(){
    if (head != nullptr) {
        Node* cur = nullptr;
        Node* start= nullptr;
        Node* temp = nullptr;
        Node* prev = nullptr;
        while (head != nullptr) {
            prev = nullptr;
            cur = head;
            temp = head;
        while (cur != nullptr) {
            if (cur->getNext() != nullptr && cur->getNext()->getExp() < temp->getExp()) {
            temp = cur->getNext();
            prev = cur;
            }
        cur = cur->getNext();
        }
        if (temp == head) head = head->getNext();
        if (prev != nullptr) prev->setNext(temp->getNext());
        temp->setNext(start);
        start = temp;
        }
        head = start;
    }

}


ostream &operator <<(ostream &out, LinkedList &list){

    for(int n =0; n < list.length ; n++){
        if(n==0 && list[n]->getCoef() < 0) out << "-" << list[n];
        if(list[n]->getCoef()<0 && n > 0) out << " - " << list[n];
        if(n==0 && list[n]->getCoef() > 0) out << list[n];
        else if( list[n]->getCoef() > 0) out<< " + "<< list[n];
    }
    return out;
}
