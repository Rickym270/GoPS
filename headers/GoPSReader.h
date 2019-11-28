#ifndef GoPSREADER
#define GoPSREADER

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

class GoPSReader{
    public:
        // Default Constructor & Destructor
        GoPSReader(){};
        ~GoPSReader(){};

        // Set filename
        void set_filename(std::string FILENAME);

        // Get CSV Content
        std::string get_content();

        // Get number of lines in a file
        int get_file_size();
    private:
        std::string SOURCE_FILE;
        std::string NMEAData;

        std::vector<std::map<std::string, std::string> > location_vecmap;

};

#endif /* GoPSREADER */
