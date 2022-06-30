#include "Node.h"
using namespace std;

Node::Node()
{
    coef =0.00;
    exp =0.00;
    next = NULL;
}

Node::Node(double inCoefficient, int inExponent)
{
    coef = inCoefficient;
    exp = inExponent;
    next = NULL;
}

ostream& operator <<(ostream &out, Node* n){
    if(n != nullptr){

        if(abs(n->getCoef()) > 1) out <<abs(n->getCoef());
        if(abs(n->getCoef()) == 1 &&  abs(n->getExp()) == 0 ) out <<abs(n->getCoef());
        if(abs(n->getCoef()) >= 1
        &&  abs(n->getExp()) > 0 ) out << "x";
        if(n->getExp() == -1) out << "^" <<  n->getExp();
        if(abs(n->getExp()) > 1) out << "^" <<  n->getExp();
    }
    return out;
}
