#ifndef ARG_PARSE_H
#define ARG_PARSE_H

#include <string>
#include <vector>
#include <map>

namespace argparse {

    class argument_parser
    {
    public:
        argument_parser(int argc, char* argv);
        // ~argument_parser();
        
        void print_args();
        bool is_empty();
        std::vector<std::string> get_raw_args();
        bool option_exists(std::string key);
        std::string get_option(std::string key);

    private:
        std::vector<std::string> _raw_args;
        std::map<std::string, std::string> _options;

    };

}



#endif
