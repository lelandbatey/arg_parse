#include <iostream>
#include <assert.h>
#include "../arg_parse.cpp"


int main(int argc, char *argv[]){
	const char* argstr0[] = {"invocation", "--arg0=val0"};
	auto ap0 = argparse::ArgumentParser(2, argstr0);

	const char* argstr1[] = {"invocation", "--arg0", "val0"};
	auto ap1 = argparse::ArgumentParser(3, argstr1);

	const char* argstr2[] = {"invocation", "--arg0", "--arg1=val1"};
	auto ap2 = argparse::ArgumentParser(3, argstr2);

	const char* argstr3[] = {"invocation", "--arg0", "--arg1", "val1"};
	auto ap3 = argparse::ArgumentParser(4, argstr3);


	// Testing ap0
	assert(ap0.empty() == false);
	assert(ap0.get_bare_args().empty() == true);
	assert(ap0.option_exists("arg0"));
	assert(ap0.get_option("arg0") == "val0");
	assert(ap0.get_current_executable_name() == "invocation");

	assert(ap1.empty() == false);
	assert(ap1.get_bare_args().empty() == true);
	assert(ap1.option_exists("arg0"));
	assert(ap1.get_option("arg0") == "val0");
	assert(ap1.get_current_executable_name() == "invocation");

	assert(ap2.empty() == false);
	assert(ap2.get_bare_args().empty() == false);
	assert(ap2.option_exists("arg1"));
	assert(ap2.get_option("arg1") == "val1");
	assert(ap2.bare_arg_exists("arg0"));
	assert(ap2.get_current_executable_name() == "invocation");

	ap3.print_args();
	assert(ap3.empty() == false);
	assert(ap3.get_bare_args().empty() == false);
	assert(ap3.option_exists("arg1"));
	assert(ap3.get_option("arg1") == "val1");
	assert(ap3.bare_arg_exists("arg0"));
	assert(ap3.get_current_executable_name() == "invocation");

	return 0;
}
