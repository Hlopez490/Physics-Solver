#include "LinkedList.h"
#include "Node.h"

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

void addToList(string line, LinkedList &list);
double findValue(string line);
void calcPrint(LinkedList list,double value);
void likeTerms(LinkedList &list);

int main(){
    float value;
    string fileName,line,expression;

    cout<<"Enter File Name:: ";
    cin >>  fileName;

    fstream file(fileName, fstream::in | fstream::out | fstream::binary);
    if(file){
        while(file.good()){
            getline(file, line);
            LinkedList list;
            value = findValue(line);
            line.erase(0,line.find('=')+2);
            addToList(line, list);
            likeTerms(list);
            calcPrint(list, value);
        }
        file.close();
    }

}

void addToList(string line, LinkedList &list){
    while(line != ""){
        double coefVal = 1;
        int expVal = 0;
        if(line[0] == '-' || (line[0] == ' ' &&  line[1] == '-' ) ){
            line.erase(0,line.find('-')+1);
            coefVal *= -1;
        }
        cout<< line <<endl;
        if(line[0] == '+') line.erase(0,line.find('+')+2);
        if(line.find('x') != 0){
            if(line.find('x') < line.find('+') && line.find('x') < line.find('-')) {
                coefVal *= stod(line.substr(0, line.find('x')));
                //cout << "COEF: " << coefVal <<endl;
                line.erase(0,line.find('x')+1);
            }else{
                coefVal *= stod(line.substr(0, line.find(' ')));
                //cout << "COEF: " << coefVal <<endl;
                line.erase(0,line.find(' ')+1);
            }
        }else if(line.find('x') > line.length()){
            string temp = line.substr(0, line.find(' '));
            coefVal *= stod(temp);
            //cout << "COEF: " << coefVal <<endl;
            line.erase(0,1);
        }else if(line.find('x') == 0){
            expVal = 1;
            line.erase(0,line.find('x')+1);
        }
        if(line[0] == '^'){
            string temp = line.substr(line.find('^')+1);
            line.erase(0,line.find(' ')+1);
            expVal = stoi(temp);
            //cout << "EXP: " << expVal <<endl;
        }
        if(line.find(' ') > line.length()){
            line.erase(0,line.length());
        }
        Node* newNode = new Node(coefVal, expVal);
        list += newNode;
    }

}

double findValue(string line){

    line.erase(0,line.find("(")+1);
    string val = line.substr(0, line.find(")"));
    double value = stod(val);
    return value;
}

void likeTerms(LinkedList &list){
    bool added;
    double total;
    list.sortList();
    for(int i=0; i < list.getLength();i++){
        total = list[i]->getCoef();
        Node* newPtr = list[i+1];
        while(newPtr != nullptr){
            if(list[i]->getExp() == list[i]->getNext()->getExp()){
                total += list[i]->getNext()->getCoef();
                added = true;
                list.deleteNode(list[i],list[i]->getNext());
            }
            newPtr = newPtr->getNext();
        }
        if(added) list[i]->setCoef(total);
    }
}

void calcPrint(LinkedList list, double value){

    float answer, total;
    for(int i=0; i<list.getLength();i++){
        answer = pow(value,(double)list[i]->getExp());
        answer *= list[i]->getCoef();
        total += answer;
        //cout<<"CALCULATED :" << total <<endl;
    }
    cout << setprecision(3) << fixed << list;
    cout << " = " << setprecision(3) << fixed << total << endl;

}
