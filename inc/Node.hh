#ifndef NODE_HH
#define NODE_HH
/**
 * @file Node.hh
 * @brief Plik zawiera definicję klasy Node oraz deklaracje jej metod
 * 
 */
#include <string>
/**
 * @brief Model węzła przechowywującego dane o tytule i rankingu
 * 
 */
class Node{   
    /**
    * @brief Zmienna przechowywująca tytuł filmu
    * 
    */
    std::string title;
    /**
     * @brief Zmienna przechowywująca ranking filmu
     * 
     */
    int rank;
    /**
     * @brief Wskaźnik na następny element(używane przy listach)
     * 
     */
    Node *next;
public:
    /**
     * @brief Konstruktor bezparametryczny
     * 
     * Tworzy obiekt z rankingiem 0 i pustym tytułem
     */
    Node(){title=""; rank=0; next=nullptr;};
    /**
     * @brief Konstruktor dwuparametryczny
     * 
     * Tworzy obiekt o zadanym tytule i rankingu
     * 
     * @param t - tytuł filmu
     * @param r - ranking filmu
     */
    Node(std::string t, int r){title=t; rank=r;};
    /**
     * @brief Zwraca ranking filmu
     * 
     * @return const int& - wartość rankingu filmu
     */
    const int & get_rank() const{return this->rank;};
    /**
     * @brief Zwraca tytuł filmu
     * 
     * @return const std::string& - tytul filmu
     */
    const std::string & get_title() const{return this->title;};
    /**
     * @brief Ustawia wskaźnik na następny obiekt
     * 
     * @param n - następny obiekt
     */
    void set_next(Node * n) {this->next=n;};
    /**
     * @brief Zwraca wskaźnik na następny obiekt
     * 
     * @return Node* - wskaźnik na następny obiekt
     */
    Node * get_next() const {return this->next;};
};





#endif