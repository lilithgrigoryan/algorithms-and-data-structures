all:
	make doubly_linked_list
	make hashtable
	gcc -g build/doubly_linked_list/list.o \
		build/doubly_linked_list/node.o \
		build/hashtable/hashtable.o \
		tests/tests.c -o build/tests.o

doubly_linked_list:
	gcc -g -c lib/doubly_linked_list/list.c -o build/doubly_linked_list/list.o
	gcc -g -c lib/doubly_linked_list/node.c -o build/doubly_linked_list/node.o

hashtable:
	gcc -g -c lib/hashtable/hashtable.c -o build/hashtable/hashtable.o

clear:
	rm -rf build/*.o
	rm -rf build/**/*.o