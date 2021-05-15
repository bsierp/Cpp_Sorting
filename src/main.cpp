/**
 * @file main.cpp
 * @brief Plik z kodem głównego sortowania oraz drivera
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
#define VALID_ELEMENTS 962903 //Liczba elementów z właściwym rankingiem
#define TOTAL_ELEMENTS 1010292 //Wszystkie elementy
/**
 * @brief Funkcja main, zawiera sortowanie główne oraz driver programu
 * 
 * argv[1] - liczba elementów do posortowania
 * argv[2] - rodzaj sortowania
 * W przypadku ilości argumentów wywołania innej niż 2 uruchamia się driver
 * @param argc - liczba argumentów wywołania
 * @param argv - tablica z argumentami wywołania
 * @return int - zwraca 0 przy poprawnym działaniu i -1 dla błędu
 */
int main(int argc, char *argv[]){
    if(argc==3){
        try{
            long int n = std::stol(argv[1]);
            double average=0;//Wartość średniej
            rapidcsv::Document doc("projekt2_dane.csv", rapidcsv::LabelParams(0, 0));
            Stack s;//Stos do którego będą wczytywane wartości z pliku
            for(long int i=0;i<n;i++){
                if(doc.GetCell<std::string>("rating",std::to_string(i)).empty()){
                    s.push(doc.GetCell<std::string>("movie",std::to_string(i)),0);//W przypadku pustego pola rankingu, wstawiamy 0
                    n++;
                    if(n>TOTAL_ELEMENTS)//Dla maksymalnej ilości elementów
                        n=TOTAL_ELEMENTS;
                }
                else
                {
                s.push(doc.GetCell<std::string>("movie",std::to_string(i)),std::stoi(doc.GetCell<std::string>("rating",std::to_string(i))));
                }
            }
            n = std::stol(argv[1]);
            if(n>VALID_ELEMENTS)
                n=VALID_ELEMENTS;
            auto start = std::chrono::steady_clock::now();
            Node * tab = s.to_array(n);//Zamiana stosu na tablicę
            auto end = std::chrono::steady_clock::now();
            std::cout<<"Czas filtrowania:"<<std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<< " µs" << std::endl;
            //Sprawdzenie argumentu wywołania i uruchomienie odpowiedniego sortowania:
        if(strcmp(argv[2],"q")==0){
            start = std::chrono::steady_clock::now();
            quick_sort(tab,0,n-1);
            end = std::chrono::steady_clock::now();
            std::cout<<"Czas sortowania szybkiego:"<<std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<< " µs" << std::endl;
        }
        else if(strcmp(argv[2],"m")==0){
            start = std::chrono::steady_clock::now();
            merge_sort(tab,0,n-1);
            end = std::chrono::steady_clock::now();
            std::cout<<"Czas sortowania przez scalanie:"<<std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<< " µs" << std::endl;
        }
        else if(strcmp(argv[2],"b")==0){
        start = std::chrono::steady_clock::now();
        tab = bucket_sort(tab,n);
        end = std::chrono::steady_clock::now();
        std::cout<<"Czas sortowania kubełkowego:"<<std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<< " µs" << std::endl;
        }
        else{
             std::cout<<"Błędny argument sortowania"<<std::endl;
            return -1;
        }
            if(n%2)
                std::cout<<"Mediana:"<<tab[n/2].get_rank()<<std::endl;
            else
                std::cout<<"Mediana:"<<(tab[n/2].get_rank()+tab[(n/2)-1].get_rank())/2<<std::endl;
            for(long int i=1;i<n;i++){
            average += tab[i-1].get_rank();
            //Sprawdzenie, czy elementy są posortowane, jednoczesne liczenie średniej
            if(tab[i].get_rank()<tab[i-1].get_rank())
                throw unsrt_error();
        }
            average+=tab[n-1].get_rank();
                std::cout<<"Średnia:"<<average/n<<std::endl;
            return 0;
        //Obsługa wyjątków
        }
        catch(const std::invalid_argument & e){
            std::cerr<<e.what()<<std::endl;
            std::cerr<<"Błąd! Niepoprawna długość ciągu"<<std::endl;
            return -1;
        }
        catch(const unsrt_error & e){
            std::cerr<<e.what()<<std::endl;
            return -1;
        }
        catch(const std::underflow_error & e){
            std::cerr<<e.what()<<std::endl;
            return -1;
        }
    }
    //Driver uruchamiany jest wywołaniem programu wpisując liczbę argumentów wywołania różną od 2
    else{
        std::cout<<"Uruchamianie drivera"<<std::endl;
        std::cout<<"================================================"<<std::endl;
        int n = 15;
        rapidcsv::Document doc("projekt2_dane.csv", rapidcsv::LabelParams(0, 0));
        Stack s[3];//Stos do którego będą wczytywane wartości z pliku
        for(int j=0;j<3;j++){
            for(long int i=0;i<n;i++){
                    s[j].push(doc.GetCell<std::string>("movie",std::to_string(n*j+i)),std::stoi(doc.GetCell<std::string>("rating",std::to_string(n*j+i))));
            }
        }
        Node *tab[3];
        for(int i=0;i<3;i++){
            tab[i]=s[i].to_array(n);
        }
        std::cout<<"Elementy przed sortowaniem przez scalanie:"<<std::endl;
        for(int i=0;i<n;i++){
            std::cout<<tab[0][i].get_title()<<":"<<tab[0][i].get_rank()<<std::endl;
        }
        std::cout<<"================================================"<<std::endl;
        merge_sort(tab[0],0,n-1);
        std::cout<<"Elementy po sortowaniu przez scalanie:"<<std::endl;
        for(int i=0;i<n;i++){
            std::cout<<tab[0][i].get_title()<<":"<<tab[0][i].get_rank()<<std::endl;
        }
        std::cout<<"================================================"<<std::endl;
        std::cout<<"Elementy przed sortowaniem szybkim:"<<std::endl;
        for(int i=0;i<n;i++){
            std::cout<<tab[1][i].get_title()<<":"<<tab[1][i].get_rank()<<std::endl;
        }
        std::cout<<"================================================"<<std::endl;
        quick_sort(tab[1],0,n-1);
        std::cout<<"Elementy po sortowaniu szybkim:"<<std::endl;
        for(int i=0;i<n;i++){
            std::cout<<tab[1][i].get_title()<<":"<<tab[1][i].get_rank()<<std::endl;
        }
        std::cout<<"================================================"<<std::endl;
        std::cout<<"Elementy przed sortowaniem kubełkowym:"<<std::endl;
        for(int i=0;i<n;i++){
            std::cout<<tab[2][i].get_title()<<":"<<tab[2][i].get_rank()<<std::endl;
        }
        std::cout<<"================================================"<<std::endl;
        tab[2]=bucket_sort(tab[2],n);
        std::cout<<"Elementy po sortowaniu kubełkowym:"<<std::endl;
        for(int i=0;i<n;i++){
            std::cout<<tab[2][i].get_title()<<":"<<tab[2][i].get_rank()<<std::endl;
        }
        return 0;
    }
}