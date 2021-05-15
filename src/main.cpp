/**
 * @file main.cpp
 * @brief Plik z kodem drivera
 * 
 */
#include "Bucket.hh"
#include "Quick.hh"
#include "Merge.hh"
#include "rapidcsv.hh"
#include <iostream>
#include <chrono>
#include <cstring>
#include "Exception.hh"
#define VALID_ELEMENTS 962903 //Liczba elementów z rankingiem
#define TOTAL_ELEMENTS 1010292 //Wszystkie elementy
int main(int argc, char *argv[]){
    if(argc==3){
        if(strcmp(argv[2],"q")||strcmp(argv[2],"m")||strcmp(argv[2],"b")){
        try{
            long int n = std::stol(argv[1]);
            bool is_odd = n%2; //Używane do liczenia mediany
            rapidcsv::Document doc("projekt2_dane.csv", rapidcsv::LabelParams(0, 0));
            List l;
            for(long int i=0;i<n;i++){
                if(doc.GetCell<std::string>("rating",std::to_string(i)).empty()){
                    l.insert(doc.GetCell<std::string>("movie",std::to_string(i)),0);//W przypadku pustego pola rankingu, wstawiamy 0
                    n++;
                    if(n>TOTAL_ELEMENTS)//Dla maksymalnej ilości elementów
                        n=TOTAL_ELEMENTS;
                }
                else
                {
                l.insert(doc.GetCell<std::string>("movie",std::to_string(i)),std::stoi(doc.GetCell<std::string>("rating",std::to_string(i))));
                }
            }
            auto start = std::chrono::steady_clock::now();
            l.filter();
            auto end = std::chrono::steady_clock::now();
            std::cout<<"Czas filtrowania:"<<std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<< " us" << std::endl;
            n = std::stol(argv[1]);
            if(n>VALID_ELEMENTS)
                n=VALID_ELEMENTS;
        if(strcmp(argv[2],"q")==0){
            Node * tab = l.to_array(n);
            start = std::chrono::steady_clock::now();
            quick_sort(tab,0,n-1);
            end = std::chrono::steady_clock::now();
            std::cout<<"Czas sortowania:"<<std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<< " us" << std::endl;
            for(int i=1;i<n;i++){
                if(tab[i].get_rank()<tab[i-1].get_rank())
                    throw unsrt_error();
            }
        }
        else if(strcmp(argv[2],"m")==0){
            Node * tab = l.to_array(n);
            start = std::chrono::steady_clock::now();
            merge_sort(tab,0,n-1);
            end = std::chrono::steady_clock::now();
            std::cout<<"Czas sortowania:"<<std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<< " us" << std::endl;
            for(int i=1;i<n;i++){
                if(tab[i].get_rank()<tab[i-1].get_rank())
                    throw unsrt_error();
            }
        }
        else if(strcmp(argv[2],"b")==0){
        //Node *btab = new Node[n];
        start = std::chrono::steady_clock::now();
        bucket_sort(&l,n);
        end = std::chrono::steady_clock::now();
        Node * tab = l.to_array(n);
        std::cout<<"Czas sortowania:"<<std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<< " us" << std::endl;
        //std::cout<<n;
        for(long int i=1;i<n;i++){
            
            std::cout<<tab[i].get_rank()<<std::endl;
            // if(tab[i].get_rank()<tab[i-1].get_rank())
            //     throw unsrt_error();
        }
        }
        else{
             std::cout<<"Błędny argument sortowania"<<std::endl;
            return 0;
        }
            return 0;
    
        }
        catch(const std::invalid_argument & e){
            std::cerr<<e.what();
            std::cerr<<"Błąd! Niepoprawna długość ciągu"<<std::endl;
            return 0;
        }
        catch(const unsrt_error & e){
            std::cerr<<e.what();
            return 0;
        }
    }
    else{
        std::cerr<<"Niepoprawne argumenty wywołania"<<std::endl;
        return 0;
    }
}
}