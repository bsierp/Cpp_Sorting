/**
 * @file List.cpp
 * @brief Plik zawiera definicje metod klasy List
 * 
 */
#include "List.hh"
#include <iostream>
void List::insert(Node * n){
    //W przypadku pierwszego elementu
    if(this->first==nullptr)
        this->first=n;
    else
        this->last->set_next(n);
    this->last=n;
}
void List::insert(std::string t, int r){
    if(this->first==nullptr){
        this->first=new Node(t,r);
        this->last=this->first;
    }
    else{
        this->last->set_next(new Node(t,r));
        this->last=this->last->get_next();
    }
}
void List::join(List l){
    if(l.get_first()!=nullptr){
    (*this).insert(l.get_first());
    this->last=l.get_last();
    }
}
Node * List::pop(){
    if(this->first==nullptr)
    throw std::underflow_error("Kolejka jest pusta");
    else
    {
        Node *temp;
        temp = this->first;
        this->first = temp->get_next();
        return temp;
    }
}
void List::filter(){
    if(this->first!=nullptr){
        Node * temp1 = this->first;
        Node * temp2,*temp3;
        while(temp1!=nullptr){
            //std::cout<<temp1->get_title()<<":"<<temp1->get_rank()<<std::endl;
            if(this->first->get_rank()==0){
            this->first = this->first->get_next();
            delete temp1;
            temp1 = this->first;
            }
            if(temp1==this->last){
                if(this->last->get_rank()==0){
                    this->last = temp3;
                    delete temp1;
                    return;
                }
                else
                    return;
            }
            else if(temp1->get_next()->get_rank()==0){
                temp2=temp1->get_next();
                temp1->set_next(temp2->get_next());
                delete temp2;
                temp3=temp1;
                temp1=temp1->get_next();
            }
            else{
                temp3=temp1;
                temp1=temp1->get_next();
            }
        }
    }
}
