#include "GoPSReader.h"

void GoPSReader::set_filename(std::string FILENAME){
    // SET the SOURCE_FILE var into the filename
    GoPSReader::SOURCE_FILE = FILENAME;
}

int GoPSReader::get_file_size(){
    int num_lines = 0;
    std::string line;
    std::ifstream ifs(GoPSReader::SOURCE_FILE.c_str());
    while(std::getline(ifs, line)) ++num_lines;

    return num_lines;
}

std::string GoPSReader::get_content(){
    std::ifstream ifs(GoPSReader::SOURCE_FILE.c_str());
    std::string content((std::istreambuf_iterator<char>(ifs)),
                        (std::istreambuf_iterator<char>()   ));

    // Last line is whitespace, remove the last char
    if(!content.empty()) content.resize(content.size()-1);

    GoPSReader::NMEAData = content;
    return NMEAData;
};

int main(){
    std::string FILE_NAME = "etc/NMEAData.csv";
    GoPSReader NMEAData_h;
    NMEAData_h.set_filename(FILE_NAME);

    std::string data = NMEAData_h.get_content();
    int num_lines = NMEAData_h.get_file_size();

    std::cout << num_lines << std::endl;
    std::cout << "|" << data << "|" << std::endl;

    return 0;
};
