/**
 * @file main.cpp
 * @brief Plik z kodem drivera
 * 
 */
#include "Bucket.hh"
#include "Quick.hh"
#include "Merge.hh"
#include <iostream>
int main(){
    std::srand(time(0));
    Node *tab = new Node[10];
    //Node *btab = new Node[10];
    std::string tit[10]={"A","B","C","D","E","F","G","H","I","J"};
    int rank[10] = {1,2,2,5,5,9,2,8,9,4};
    std::random_shuffle(&rank[0],&rank[10]);
    std::cout<<"Kolejność"<<std::endl;
    for(int i=0;i<10;i++){
        std::cout<<tit[i]<<":"<<rank[i]<<std::endl;
        tab[i] = Node(tit[i],rank[i]);
    }
    quick_sort(tab,0,9);
    for(int i=0;i<10;i++){
        std::cout<<tab[i].get_title()<<":"<<tab[i].get_rank()<<std::endl;
    }
    // btab = bucket_sort(tab,10);
    // for(int i=0;i<10;i++){
    //     std::cout<<btab[i].get_title()<<":"<<btab[i].get_rank()<<std::endl;
    // }
    return 0;
}