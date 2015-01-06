
OUTPUT_NAME = argparse
COMPILER = g++ -DDEBUG -g -std=c++11 -Wall

debug:
	$(COMPILER) main.cpp -o $(OUTPUT_NAME)

