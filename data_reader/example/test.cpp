#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

#include "data_reader/data_reader.cpp"

int main(){
    const char * file = "*.txt";
    Data_reader::data_container data_cont;
    Data_reader::read_data(data_cont, file);

    for(auto it:data_cont){
        for(auto jt:it){
            std::cout<<jt<<",";
        }
        std::cout<<std::endl;
    }
}