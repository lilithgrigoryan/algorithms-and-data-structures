tests:
	make doubly_linked_list
	gcc build/doubly_linked_list/list.o \
		build/doubly_linked_list/node.o \
		tests/doubly_linked_list/list_tests.c -o build/tests.o

doubly_linked_list:
	gcc -c lib/doubly_linked_list/list.c -o build/doubly_linked_list/list.o
	gcc -c lib/doubly_linked_list/node.c -o build/doubly_linked_list/node.o

clear:
	rm -rf build/*.o
	rm -rf build/**/*.o