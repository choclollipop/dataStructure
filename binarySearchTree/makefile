TARFET=main
OBJ=binarySearchTree.o doubleLinkList.o doubleLinkListQueue.o main.o

$(TARFET):$(OBJ)
	gcc $^ -o $@

binarySearchTree.o:binarySearchTree.c
	gcc -c $^ -o $@

doubleLinkList.o:doubleLinkList.c
	gcc -c $^ -o $@

doubleLinkListQueue.o:doubleLinkListQueue.c
	gcc -c $^ -o $@

main.o:main.c
	gcc -c $^ -o $@

clean:
	@rm -rf *.o $(TARFET)