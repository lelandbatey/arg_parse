#include <iostream>

#include "arg_parse.cpp"

int main(int argc, char *argv[]){
    auto arguments = argparse::ArgumentParser(argc, argv); 
    arguments.print_args();
    return 0;
}

