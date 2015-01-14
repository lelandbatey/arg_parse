
OUTPUT_NAME = argparse
COMPILER = g++ -g -std=c++11 $(CFLAGS)


executable:
	$(COMPILER) main.cpp -o $(OUTPUT_NAME)

clean:
	rm -fv $(OUTPUT_NAME)

debug: COMPILER = g++ -DDEBUG -g -std=c++11 -Wall
debug: clean executable

