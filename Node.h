#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node
{

    private:
        double coef;
        int exp;
        Node *next;

    public:
        Node();
        ~Node();
        Node(double inCoefficient, int inExponent);

        void setCoef(double inCoef){coef = inCoef;};
        void setExp(int inExp){exp = inExp;};
        void setNext(Node *newNext){ next = newNext;};

        Node* getNext(){return next;};
        double getCoef() const {return coef;} ;
        int getExp() const {return exp;} ;

        friend std::ostream& operator <<(std::ostream &, Node *);

};

#endif // NODE_H
