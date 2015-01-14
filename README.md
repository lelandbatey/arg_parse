Arg_Parse
=========


A small library for handling command line arguments. Written in C++.


How's it work?
--------------

This is a relatively simple and naive way of handling command line arguments. This library will not handle every possible way a command line argument *could* be specified. There are many conventions for passing in arguments, but this library only handles a small subset:

- There are two different types of arguments:
	1. "Key-value arguments"
		- These arguments can take two forms:
			1. `--key0 value0`
			2. `--key0=value0`
	2. "Bare arguments"
		- Bare arguments are just strings, and are without keys. An example invocation might be:
			- `./the_program bare_argument0 bare_argument1`
