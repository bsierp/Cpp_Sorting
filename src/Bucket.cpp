/**
 * @file Bucket.cpp
 * @brief Plik zawiera definicje funkcji używanych podczas sortowania kubełkowego
 * 
 */
#include "Bucket.hh"
Node * bucket_sort(Node *table,long int n){
    Stack tab[10];//Jako że rangi są od 1-10, tworzymy 10 kubełków
    Node *t = new Node[n];//Zwracana tablica z posortowanymi wartościami
    for(long int i=0;i<n;i++){//Wrzucamy element do odpowiedniego kubełka, bazując na rankingu
        tab[table[i].get_rank()-1].push(&table[i]);
    }
    //Sortowanie kubełkowe powinno sortować wartości w kubełkach. Jako, że mamy tylko 10 wartości nie potrzebujemy tego.
    //Łączymy kubełki
    long int index=0;
    for(int i=0;i<10;i++){
        while (!tab[i].is_empty())
        {
            t[index++] = *tab[i].pop();
        }
        
    }
    delete[] table;
    return t;
}