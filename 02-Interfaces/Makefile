.PHONY = run clean test

run : TablasDeConversion
	./TablasDeConversion

clean :
	rm -f ConversionTest.o Conversion.o ConversionTest TablasDeConversion TablasDeConversion.o

test : ConversionTest
	./ConversionTest

TablasDeConversion: TablasDeConversion.o Conversion.o
	gcc TablasDeConversion.o Conversion.o -o TablasDeConversion

TablasDeConversion.o : TablasDeConversion.c Conversion.h
	gcc TablasDeConversion.c -c -o TablasDeConversion.o	

ConversionTest : ConversionTest.o Conversion.o
	gcc ConversionTest.o Conversion.o -o ConversionTest

ConversionTest.o : ConversionTest.c Conversion.h
	gcc ConversionTest.c -c -o ConversionTest.o

Conversion.o : Conversion.c Conversion.h
	gcc Conversion.c -c -o Conversion.o