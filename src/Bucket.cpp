/**
 * @file Bucket.cpp
 * @brief Plik zawiera definicje funkcji używanych podczas sortowania kubełkowego
 * 
 */
#include "Bucket.hh"
#include <iostream>
void bucket_sort(List *l,long int n){
    Node *table = l->to_array(n); 
    List tab[10];//Jako że rangi są od 1-10, tworzymy 10 kubełków
    //Node *t = new Node[n];//Zwracana tablica z posortowanymi wartościami
    for(long int i=0;i<n;i++){
        tab[table[i].get_rank()-1].insert(&table[i]);
    }
    //Sortowanie kubełkowe powinno sortować wartości w kubełkach. Jako, że mamy tylko 10 wartości nie potrzebujemy tego.
    //Łączymy kubełki
    for(int i=1;i<10;i++){
        tab[0].join(tab[i]);
    }
    *l = tab[0];
    //delete[] table;
    //     for(long int i=0;i<n;i++){
    //     std::cout<<t[i].get_rank()<<std::endl;
    // }
    // Node * temp;
    // long int index = 0;
    // for(int i=0;i<10;i++){
    //     temp =tab[i].get_first();
    //     while(temp!=nullptr){
    //         t[index++] = *temp;
    //         temp=temp->get_next();
    //     }
    // }
    // for(long int i=0;i<n;i++){
    //     t[i] = *temp;
    //     temp=temp->get_next();
    // }
    //delete[] table;
    //return t;
    // Node * temp=tab[0].get_first();
    // for(long int i=0;i<n;i++){
    //     std::cout<<table[i].get_rank()<<std::endl;
    // }
    //delete[] table;//Zwalniamy miejsce po starej tablicy
    //return t;
}