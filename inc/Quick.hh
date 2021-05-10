#ifndef QUICK_HH
#define QUICK_HH
/**
 * @file Quick.hh
 * @brief Plik zawiera deklaracje funkjci używanych w procesie sortowania szybkiego
 * 
 */
#include "Node.hh"
#include <algorithm>
/**
 * @brief Funkcja sortująca tablice przy użyciu scalania
 * 
 * Funkcja bazuje na rekurencji. Wybiera środkowy element jako piwot,
 * a potem zamienia miejscami elementy w stosunku do piwota. Następnie
 * jest ona wywoływana dla mniejszych podzbiorów, aż do próby sortowania
 * zbiorów jednoelementowych
 * @param table - tablica główna, która zostanie posortowana
 * @param l - indeks pierwszego elementu w tablicy głównej
 * @param r - indeks ostatniego elemetnu w tablicy głównej
 */
void quick_sort(Node *table,int l, int r);
#endif