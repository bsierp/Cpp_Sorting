/**
 * @file Bucket.cpp
 * @brief Plik zawiera definicje funkcji używanych podczas sortowania kubełkowego
 * 
 */
#include "Bucket.hh"
#include <iostream>
Node * bucket_sort(Node *table, int n){
    List tab[10];//Jako że rangi są od 1-10, tworzymy 10 kubełków
    Node *t = new Node[n];//Zwracana tablica z posortowanymi wartościami
    for(int i=0;i<n;i++){
        tab[table[i].get_rank()-1].insert(&table[i]);
    }
    //Sortowanie kubełkowe powinno sortować wartości w kubełkach. Jako, że mamy tylko 10 wartości nie potrzebujemy tego.
    //Łączymy kubełki
    for(int i=1;i<10;i++){
        tab[0].join(tab[i]);
    }
    std::cout<<std::endl;
    Node * temp=tab[0].get_first();
    for(int i=0;i<n;i++){
        t[i]=*temp;
        temp = temp->get_next();
    }
    delete[] table;//Zwalniamy miejsce po starej tablicy
    return t;
    std::cout<<std::endl;
}