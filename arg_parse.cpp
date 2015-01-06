#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "arg_parse.hpp"

#ifndef DEBUG
#define DEBUG 0
#endif


argparse::ArgumentParser::ArgumentParser(int argc, const char* argv[]){
	
	auto is_option = [](std::string& s){
		if (s.find("--") == 0 && s.length() > 2){
			return true;
		}
		return false;
	};

	auto is_argument_pair = [](std::string& s){
		if (s.find("=") != std::string::npos){
			return true;
		}
		return false;
	};

	for (int i = 0; i < argc; ++i){
		_all_args.push_back(argv[i]);
	}

	for (unsigned int i = 0; i < _all_args.size(); ++i){
		auto arg = _all_args[i];

		// We don't want the name of the executable to be parsed with the rest
		// of the arguments, but it could be useful, so we stash it in a
		// variable for potential use.
		if (i == 0){
			_executable_name = arg;
			continue;
		}

		if (is_option(arg)){
			// Removes the double-dashes
			arg = arg.substr(2);
			
			if (DEBUG){
				std::cout << "Current arugment: " << arg << std::endl;
				std::cout << "_all_args.size() = " << _all_args.size() << std::endl;
				std::cout << "i                = " << i << std::endl;
				std::cout << "i+1              = " << i+1 << std::endl;
				std::cout << "i+1 < _all_args.size() = " << bool(i+1 < _all_args.size()) << std::endl;
				if (i+1 < _all_args.size()){
					std::cout << "!is_option(_all_args[i+1]) = " << !is_option(_all_args[i+1]) << std::endl;
				}
			}

			if (is_argument_pair(arg)){
				if (DEBUG){
					std::cout << '"' << arg << "\" is single argument pair" << std::endl;
				}
				auto pos = arg.find('=');
				auto val = arg.substr(pos+1);
				auto key = arg.substr(0, pos);
				_options[key] = val;
			
			// Treats "--key0 val0" as "--key0=val0"
			} else if (i+1 < _all_args.size() && !is_option(_all_args[i+1])){
				if (DEBUG){
					std::cout << '"' << arg << "\" is sequential pair" << std::endl;
				}
				_options[arg] = _all_args[i+1];
				i++;
			
			// If an option is the last one in the list, or if it is followed
			// by another option, it is treated as a bare-argument
			} else {
				_bare_args.push_back(arg);
			}
			if (DEBUG){
				std::cout << std::endl;
			}
		} else {
			_bare_args.push_back(arg);
		}
	}
}

void argparse::ArgumentParser::print_args(){
	std::cout << "All arguments:" << std::endl << "\t";
	for (unsigned int i = 0; i < _all_args.size(); ++i){
		std::cout << _all_args[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Key-value arguments:" << std::endl;
	for (auto it = _options.cbegin(); it != _options.cend(); ++it){
		std::cout << "\t" << it->first << " = " << it->second << std::endl;
	}

	std::cout << "Bare arguments:" << std::endl;
	for (unsigned int i = 0; i < _bare_args.size(); ++i){
		std::cout << "\t" << _bare_args[i] << std::endl;
	}

	std::cout << "Executable name:\n\t" << _executable_name << std::endl;

}

bool argparse::ArgumentParser::empty(){
	if (_bare_args.empty() && _options.empty()){
		return true;
	}
	return false;
}

std::vector<std::string> argparse::ArgumentParser::get_all_args(){
	return _all_args;
}

std::vector<std::string> argparse::ArgumentParser::get_bare_args(){
	return _bare_args;
}

bool argparse::ArgumentParser::option_exists(std::string key){
	if (_options.count(key) > 0){
		return true;
	}
	return false;
}

bool argparse::ArgumentParser::bare_arg_exists(std::string key){
	for (unsigned int i = 0; i < _bare_args.size(); ++i){
		if (_bare_args[i] == key){
			return true;
		}
	}
	return false;
}

std::string argparse::ArgumentParser::get_option(std::string key){
	if (_options.count(key) > 0){
		return _options[key];
	} else {
		return std::string("");
	}
}


std::string argparse::ArgumentParser::get_current_executable_name(){
	return _executable_name;
}




