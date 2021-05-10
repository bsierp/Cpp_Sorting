/**
 * @file List.cpp
 * @brief Plik zawiera definicje metod klasy List
 * 
 */
#include "List.hh"

void List::insert(Node * n){
    //W przypadku pierwszego elementu
    if(this->first==nullptr)
        this->first=n;
    else
        this->last->set_next(n);
    this->last=n;
}
// void List::insert(std::string t, int r){
//     Node * temp = new Node(t,r);
//     (*this).insert(temp);
// }
void List::join(List l){
    if(l.get_first()!=nullptr){
    (*this).insert(l.get_first());
    this->last=l.get_last();
    }
}

