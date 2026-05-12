.PHONY = run clean 

scanner: scannerLexico.c scanner.c scanner.h
	gcc -o scanner scannerLexico.c scanner.c

# run1 : scanner test_heavy.c output.txt
# 	./scanner < test_heavy.c > output.txt
run1 : scanner test.c output.txt
	./scanner <test.c> output.txt

parser: scanner.c declaraciones.c scanner.h declaraciones.h parser.c
	gcc -o parser parser.c scanner.c declaraciones.c

# run2 : parser test_heavy.c output.txt
# 	./parser < test_heavy.c > outputParser.txt
run2 : parser test.c output.txt
	./parser <test.c> outputParser.txt

clean :
	rm -f scanner parser output.txt outputParser.txt