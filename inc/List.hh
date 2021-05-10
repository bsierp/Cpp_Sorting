#ifndef LIST_HH
#define LIST_HH
/**
 * @file Node.hh
 * @brief Plik zawiera definicję klasy List oraz deklaracje jej metod
 * 
 */
#include "Node.hh"
/**
 * @brief Model listy jednokierunkowej
 * 
 * Używana do sortowania kubełkowego oraz filtrowania
 */
class List{
    /**
     * @brief Wskaźnik na początek listy
     * 
     */
    Node* first;
    /**
     * @brief Wskaźnik na koniec listy
     * 
     */
    Node* last;
public:
    /**
     * @brief Konstruktor bezparametryczny
     * 
     * Inicjuje pustą listę
     */
    List(){last=nullptr; first=nullptr;};
    /**
     * @brief Metoda dodająca element na koniec listy
     * 
     * @param t - tytuł filmu
     * @param r - ranking filmu
     */
    //void insert(std::string t, int r);
    /**
     * @brief Metoda dodaje element na koniec listy
     * 
     * @param n - wskaźnik na nowy element
     */
    void insert(Node * n);
    /**
     * @brief Metoda łącząca dwie listy
     * 
     * @param l - lista do dołączenia
     */
    void join(List l);
    /**
     * @brief Zwraca pierwszy obiekt listy
     * 
     * @return Node* - wskaźnik do pierwszego obiektu
     */
    Node * get_first() const {return this->first;};
    /**
     * @brief Zwraca ostatni obiekt lsity
     * 
     * @return Node* - wskaźnik do ostatniego obiektu
     */
    Node * get_last() const {return this->last;};
    
};

#endif