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
#include <cstring>
//1010292
//54930
int main(int argc, char *argv[]){
    if(argc==1){
        std::cout<<"Wywołano program bez parametrów"<<std::endl;
        return 0;
    }
    else{
        //Sprawdzamy najpierw, żeby nie czekać na czytanie z pliku, gdy podamy błędny argument
        if(strcmp(argv[2],"q")&&strcmp(argv[2],"m")&&strcmp(argv[2],"b")){
            std::cout<<"Błędny argument sortowania"<<std::endl;
            return 0;
        }
        try{
            long int n = std::stol(argv[1]);
            rapidcsv::Document doc("projekt2_dane.csv", rapidcsv::LabelParams(0, 0));
            List l;
            for(long int i=0;i<n;i++){
                if(doc.GetCell<std::string>("rating",std::to_string(i)).empty()){
                    l.insert(doc.GetCell<std::string>("movie",std::to_string(i)),0);//W przypadku pustego pola rankingu, wstawiamy 0
                    n++;
                }
                else
                {
                l.insert(doc.GetCell<std::string>("movie",std::to_string(i)),std::stoi(doc.GetCell<std::string>("rating",std::to_string(i))));
                }
            }
            l.filter();
            n = std::stol(argv[1]);
            Node *tab = new Node[n];
            
            for(long int i=0;i<n;i++){
                tab[i] = *l.pop();
            }
        if(strcmp(argv[2],"q")){
            quick_sort(tab,0,n-1);
        }
        else if(strcmp(argv[2],"m")){
            merge_sort(tab,0,n-1);
        }
        else{
        Node *btab = new Node[n];
        btab = bucket_sort(tab,n);
        for(long int i=0;i<n;i++){
        std::cout<<btab[i].get_title()<<":"<<btab[i].get_rank()<<std::endl;
        }
        }
        for(long int i=0;i<n;i++){
            std::cout<<tab[i].get_title()<<":"<<tab[i].get_rank()<<std::endl;
        }
    return 0;
    
        }
    catch(const std::invalid_argument & e){
        std::cerr<<e.what();
        std::cerr<<"Błąd! Niepoprawna długość ciągu"<<std::endl;
        return 0;
        }
    }
}