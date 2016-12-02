################################
# Name: Leo Gomez              #
# CruzID: legomez              #
# Class: CMPS-12M              #
# Date: Nov 12, 2014           #
# filename: Makefile           #
# Details:makefile for testing #
#  and using list.c            #
################################

list: list.c
	gcc -Wall -g -std=c99 list.c -o list

clean:
	rm -f *.o

spotless: clean
	rm -f list list.o a.out

test: list
	valgrind ./list

.PHONY: clean spotless test

