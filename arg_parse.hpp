#ifndef ARG_PARSE_H
#define ARG_PARSE_H

#include <string>
#include <vector>
#include <map>

namespace argparse {

	class ArgumentParser
	{
	public:
		ArgumentParser(int argc, const char* argv[]);
		// ~ArgumentParser();
		
		void print_args();
		bool empty();
		std::vector<std::string> get_all_args();
		std::vector<std::string> get_bare_args();
		bool option_exists(std::string key);
		bool bare_arg_exists(std::string key);
		std::string get_option(std::string key);
		std::string get_current_executable_name();

	private:
		std::vector<std::string> _all_args;
		std::vector<std::string> _bare_args;
		std::map<std::string, std::string> _options;
		std::string _executable_name;

	};
}


#endif
