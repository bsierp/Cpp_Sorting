#ifndef BUCKET_HH
#define BUCKET_HH
/**
 * @file Bucket.hh
 * @brief Plik zawiera deklaracje funkjci używanych w procesie sortowania kubełkowego
 * 
 */
#define MAX_LIST_SIZE 51731
#include "List.hh"
/**
 * @brief Funkcja sortująca tablice przy użyciu sortowania kubełkowego
 * 
 * Funkcja napisana jest pod aktualne zadanie, tzn. Nie sortujemy tu pojedynczych kubełków,
 * ponieważ ranking jest liczbą całkowitą z zakresu od 1 do 10.
 * 
 * @param table - tablica do posortowania
 * @param n - rozmiar tablicy
 */
void bucket_sort(List *l,long int n);
#endif