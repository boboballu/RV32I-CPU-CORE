# Makefile - linked from common folder
# syscalls.c, riscv.ld, start.S, start.ld are files for libc++ support
# makevars.mk takes in the additional user cc, c files 
# add the additional cc, c files of user program here
ASMs  += 
ccFs += multiply.cc main.cc
OBJ  += multiply.o main.o
