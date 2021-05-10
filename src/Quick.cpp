/**
 * @file Quick.cpp
 * @brief Plik zawiera definicje funkcji używanych podczas sortowania szybkiego
 * 
 */
#include "Quick.hh"
void quick_sort(Node *table,int l,int r){
    int pivot = table[(l+r)/2].get_rank();//piwotem będzie element środkowy
    int i=l,j=r;//Tworzymy dwa iteratory, jeden przeszukuje od początku, drugi od końca
    while (true)
    {
        //Przenosimy obiekty o mniejszym piwocie na lewo, a o większym na prawo
        while (table[i].get_rank()<pivot){
        i++;
        }
        while (table[j].get_rank()>pivot){
        j--;
        }
        if(i<=j)
        std::swap(table[i++],table[j--]);//Zamieniamy, gdy iteratory napotkają elementy po niewłaściwej stronie
        else
        break;//Kończymy pętle, jeśli iteratory się miną
    }
    //Sprawdzamy, czy tablice nie są jednoelementowe
    if(j>l)
    quick_sort(table,l,j);
    if(i<r)
    quick_sort(table,i,r);
}