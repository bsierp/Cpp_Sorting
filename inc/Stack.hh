/**
 * @file Stack.hh
 * @brief Plik zawiera definicję klasy List oraz deklaracje jej metod
 * 
 */
#include "Node.hh"
#include <stdexcept>
/**
 * @brief Model stosu przechowującego elementy typu Node
 * 
 */
class Stack {
    /**
     * @brief Element szczytowy stosu
     * 
     */
    Node * top;
    public:
    /**
     * @brief Konstruktor bezparametryczny
     * 
     * Tworzy pusty stos
     * 
     */
    Stack(){top = nullptr;};
    /**
     * @brief Metoda dodająca nowy element o zadanym tytule i rankingu
     * 
     * @param t - tytuł filmu
     * @param r - ranking filmu do dodania
     */
    void push(std::string t, int r);
    /**
     * @brief Metoda dodaje element do stosu
     * 
     * @param n - element do dodania
     */
    void push(Node * n);
    /**
     * @brief Metoda zwraca element o właściwym rankingu z wierzchu stosu
     * 
     * Jeżeli element ma nieprawidłowy ranking (tj. o wartości 0) metoda, usuwa
     * go ze stosu.
     * UWAGA!!!
     * Metoda nie czyści pamięci po właściwym elemencie, należy stosować
     * tylko jako przypisanie do elementu, inaczej może spowodować
     * wyciek pamięci.
     * @return Node* - element wierzchni stosu
     * @throws std::underflow_error - w wypadku wywołania na pustym stosie, bądź ze stosem z samymi niewłaściwymi rankingami
     */
    Node * pop();
    /**
     * @brief Metoda sprawdzająca, czy stos jest pusty
     * 
     * @return true - Jeżeli stos jest pusty
     * @return false - w przeciwnym wypadku
     */
    bool is_empty() { return top == nullptr; };
    /**
     * @brief Metoda zamienia stos na tablicę
     * 
     * @param n - liczba elementów w tablicy
     * @return Node* - tablica z elementami ze stosu
     * @throws std::underflow_error - w wypadku wywołania na pustym stosie
     */
    Node * to_array(long int n);
};