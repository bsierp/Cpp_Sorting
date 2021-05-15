/**
 * @file Stack.cpp
 * @brief Plik zawiera definicje metod klasy Stack
 * 
 */
#include "Stack.hh"
void Stack::push(std::string t, int r){
    Node * n = new Node(t,r);
    (*this).push(n);
}
void Stack::push(Node * n){
    n->set_next(this->top);
    this->top=n;
}
Node * Stack::pop(){
    if((*this).is_empty())
    throw std::underflow_error("Pusty stos");
    else{
        Node * temp;
        while(!(*this).is_empty()){
            temp = this->top;
            this->top = this->top->get_next();
            if(temp->get_rank()==0)
                delete temp;//Usuwamy element o rankingu 0
            else
                return temp;//Zwracamy właściwy element
        }
        //W przypadku braku właściwych wartości rankingu
        throw std::underflow_error("W danych nie ma właściwych wartości rankingu");
    }
}
Node * Stack::to_array(long int n){
    if((*this).is_empty())
    throw std::underflow_error("Stos jest pusty");
    else{
        Node * tab = new Node[n];
        for(long int i=0;i<n;i++)
        {
            tab[i] = *(*this).pop();//Wypełniamy tablicę elementami ze stosu
        }
        return tab;
    }
}