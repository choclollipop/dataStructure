testSeqTable:sequenceTable.o testSeqTable.o
	gcc sequenceTable.o testSeqTable.o -o testSeqTable

sequenceTable.o:sequenceTable.c
	gcc -c sequenceTable.c -o sequenceTable.o

testSeqTable.o:testSeqTable.c
	gcc -c testSeqTable.c -o testSeqTable.o

clean:
	@rm -rf *.o testSeqTable