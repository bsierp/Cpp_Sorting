#ifndef BUCKET_HH
#define BUCKET_HH
/**
 * @file Bucket.hh
 * @brief Plik zawiera deklaracje funkjci używanych w procesie sortowania kubełkowego
 * 
 */
#include "Stack.hh"
/**
 * @brief Funkcja sortująca tablice przy użyciu sortowania kubełkowego
 * 
 * Funkcja napisana jest pod aktualne zadanie, tzn. Nie sortujemy tu pojedynczych kubełków,
 * ponieważ ranking jest liczbą całkowitą z zakresu od 1 do 10.
 * UWAGA!!!
 * Funkcja zwraca posortowaną tablicę z elementami oryginalnej tablicy
 * 
 * @param table - tablica do posortowania
 * @param n - rozmiar tablicy
 * @return Node* - wskaźnik do posortowanej tablicy
 */
Node * bucket_sort(Node *table,long int n);
#endif