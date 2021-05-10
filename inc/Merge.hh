#ifndef MERGE_HH
#define MERGE_HH
/**
 * @file Merge.hh
 * @brief Plik zawiera deklaracje funkjci używanych w procesie sortowania przez scalanie
 * 
 */
#include "Node.hh"
/**
 * @brief Funkcja scalająca posortowane tablice
 * 
 * @param table - tablica główna, do której zostaną scalone dwie tablice
 * @param l - indeks w tablicy głównej, od którego zaczyna się pierwsza podtablica
 * @param m - indeks w tablicy głównej, na którym ma się kończyć pierwsza podtablica
 * @param r - indeks w tablicy głównej, na którym ma się kończyc druga podtablica
 */
void merge(Node *table[], int l, int m, int r);
/**
 * @brief Funkcja sortująca tablice przy użyciu scalania
 * 
 * Funkcja bazuje na rekurencji. Dzieli tablice na dwie podtablice,
 * na których jest wywoływana ta funkcja, dopóki nie będą to tablice jednoelementowe.
 * Na koniec następuje scalanie tablicy.
 * @param table - tablica główna, która zostanie podzielona na dwie podtablice
 * @param l - indeks w tablicy głównej, od którego zaczyna się pierwsza podtablica
 * @param r - indeks w tablicy głównej, na którym ma się kończyc druga podtablica
 */
void merge_sort(Node *table, int l, int r);
#endif