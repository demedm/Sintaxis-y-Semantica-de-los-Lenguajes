.PHONY = run1 run2 clean 

RemoveComments1: RemoveComments1.c
	gcc -o RemoveComments1 RemoveComments1.c

RemoveComments2: RemoveComments2.c
	gcc -o RemoveComments2 RemoveComments2.c

run1 : RemoveComments1 Test.c NoComments.c
	./RemoveComments1 < Test.c > NoComments.c

run2 : RemoveComments2 Test.c NoComments.c
	./RemoveComments2 < Test.c > NoComments.c

clean :
	rm -f RemoveComments1 RemoveComments2 NoComments.c

dot: RemoveComments.gv
	dot -Tpng RemoveComments.gv -o RemoveComments.png