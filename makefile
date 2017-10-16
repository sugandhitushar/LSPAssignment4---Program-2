threadDemo: program.c program.h
	gcc -o threadDemo program.c -lpthread

.PHONY: clean run
clean:
	rm threadDemo
run:
	./threadDemo
usage:
	@echo make
	@echo make run
