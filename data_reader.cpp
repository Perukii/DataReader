
#include <vector>
#include <string>
#include <fstream>

#ifdef DATA_READER_MODE_STRING
    #define T std::string
#else
    #define T int
#endif

namespace Data_reader{
    using data_container = std::vector<std::vector<T>>;

    void read_data(data_container& data, const char* file){

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
                    #ifdef DATA_READER_MODE_STRING
                        data[data.size()-1].push_back(segment);
                    #else
                        data[data.size()-1].push_back(std::atoi(segment.c_str()));
                    #endif
                    segment = "";
                }
            }
        }
    }

    int string_to_int(std::string tar){
        return std::atoi(tar.c_str());
    }

    double string_to_double(std::string tar){
        return double(std::atoi(tar.c_str()));
    }

}

