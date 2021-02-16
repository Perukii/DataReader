
#include <vector>
#include <string>
#include <fstream>

namespace Data_reader{

    using data_container = std::vector<std::vector<std::string>>;
    
    void read_data(data_container& data, const char* file, bool is_string){

        std::ifstream input(file);

        data.clear();

        for(std::string line;getline(input,line);){

            if(line[0] == '#')continue;

            data.push_back({});
            std::string segment("");

            for(int i=0;i<line.length();i++){

                if(line[i] != ','){
                    segment.push_back(line[i]);
                }

                if(line[i] == ',' or i == line.length()-1){

                    data[data.size()-1].push_back(segment);

                    segment = "";
                }
            }
        }
    }

    template<class T>
    void write_data(std::vector<std::vector<T>>& data, const char * file){

        std::ofstream ofs(file);
 
        for(int i=0;i<data.size();i++){
            for(int j=0;j<data[i].size();j++){
                ofs<<data[i][j];
                if(j!=data[i].size()-1)ofs<<",";
            }
            ofs<<std::endl;
        }

        ofs.close();

    }

    int string_to_int(std::string tar){
        return std::atoi(tar.c_str());
    }

    double string_to_double(std::string tar){
        return std::stod(tar.c_str());
    }

}

