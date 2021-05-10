/**
 * @file Merge.cpp
 * @brief Plik zawiera definicje funkcji używanych podczas sortowania przez scalanie
 * 
 */
#include "Merge.hh"

void merge(Node *table, int l, int m, int r){
    int elem1=m-l+1;//Liczba elementów pierwszego ciągu
    int elem2=r-m;//Liczba elementów drugiego ciągu
    Node *tab1 = new Node[elem1];
    Node *tab2 = new Node[elem2];
    //Tworzymy dwa podciągi, wypełniamy je elementami z ciągu oryginalnego
    for (int i=0;i<elem1;++i){
        tab1[i] = table[l+i];
    }
    for (int i=0;i<elem2;++i){
        tab2[i] = table[m+1+i];
    }
    int i=0,j=0,k=l;
    //Dodawanie posortowanych elementów do tablicy głównej
    while (i<elem1&&j<elem2) {
        if (tab1[i].get_rank()<=tab2[j].get_rank())
            table[k++]=tab1[i++];
        else
            table[k++]=tab2[j++];
    }
    //Kopiowanie pozostałych elementów ciągu, gdyby jeden z ciągów miał więcej elementów od drugiego
        while (i<elem1) {
        table[k++]=tab1[i++];
    }
        while (j<elem2) {
        table[k++]=tab2[j++];
    }
}
void merge_sort(Node *table, int l, int r){
    if(l<r){//Warunek wykona sie tylko dla ciagów niejednoelementowych
        int m = (r+l)/2;//Tworzenie liczby po środku, do podzielenia tablicy
        merge_sort(table,l,m);
        merge_sort(table,m+1,r);
        merge(table,l,m,r);
    }
}