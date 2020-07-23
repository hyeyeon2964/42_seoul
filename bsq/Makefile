bsq : main.o print_res.o read_f.o scan_square.o tools.o
	gcc -o BSQ main.o print_res.o read_f.o scan_square.o tools.o
main.o : main.c
	gcc -c -o main.o main.c
print_res.o : print_res.c
	gcc -c -o print_res.o print_res.c
read_f.o : read_f.c
	gcc -c -o read_f.o read_f.c
scan_square.o : scan_square.c
	gcc -c -o scan_square.o scan_square.c
tools.o : tools.c
	gcc -c -o tools.o tools.c
clean :
	rm *.o
