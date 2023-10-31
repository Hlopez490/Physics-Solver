#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
    private:
        int length;
        Node *head;

    public:

        LinkedList();
        ~LinkedList();
        LinkedList(Node*, int);
        LinkedList(LinkedList &);

        Node* getHead(){return head;};
        int getLength(){return length;};

        void setHead(Node*);
        void deleteNode(Node*, Node*);
        void recDestruct(Node*);

        void operator += (Node *);
        Node* operator[](int);

        void sortList();

        friend std::ostream &operator <<(std::ostream &, LinkedList &);
};



#endif // LINKEDLIST_H
