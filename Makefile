
############################################
#  Author: 	Amber Rogowicz
#  File	:	Makefile  for building pyramid 
#  Date:	July 2018

CC = g++
# Note: the following are OSX platform flags
CFLAGS  = -v -Wall -std=c++17 -ggdb 

# adjust flags as necessary for your platform
# CC = clang++
#CFLAGS  = -v -g -Wall -std=c++11 

#LDFLAGS =  -lpthread

all: look_and_say.o  look_and_say

look_and_say: look_and_say.o  
	$(CC) $(CFLAGS) $(LDFLAGS) look_and_say.o -o look_and_say

look_and_say.o: look_and_say.cc 
	$(CC) $(CFLAGS) -c look_and_say.cc -o look_and_say.o



clean:
	rm -rf *.o  look_and_say
