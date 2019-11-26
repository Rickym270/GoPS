#ifndef GoPSREADER
#define GoPSREADER

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

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

};

#endif /* GoPSREADER */
