#ifndef LIST_HH
#define LIST_HH
/**
 * @file Node.hh
 * @brief Plik zawiera definicję klasy List oraz deklaracje jej metod
 * 
 */
#include "Node.hh"
class List{
    Node* first;
    Node* last;
public:
    List(){last=nullptr; first=nullptr;};
    void insert(std::string t, int r);
};

#endif