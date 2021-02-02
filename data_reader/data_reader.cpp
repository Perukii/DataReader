
namespace Data_reader{

    using data_container = std::vector<std::vector<int>>;

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
                    data[data.size()-1].push_back(std::atoi(segment.c_str()));
                    segment = "";
                }

            }

        }
    }

}

