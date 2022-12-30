# you and the graders will be able to compile and run as follows
# to compile task1, type the command: make task1
# to run task1, type the command: make run-task1
# ...and so on for task2 and task3
# Please implement only two tasks.

task1: spellchecker.o
	g++ -Wall -o spellchecker spellapp.cpp spellchecker.o
spellchecker.o: spellchecker.cpp spellchecker.h
	g++ -Wall -c spellchecker.cpp
task2: randomFile.o
	g++ -Wall -o randomFile randomFileApp.cpp randomFile.o
randomFile.o: randomFile.cpp randomFile.h
	g++ -Wall -c randomFile.cpp


# add another target for your other task

clean:
	rm *.o

cpplint-task1: spellapp
	cpplint spellchecker.h spellchecker.cpp spellapp.cpp

run-task1: spellchecker
	./spellchecker

cpplint-task2: randomFileApp
	cpplint randomFile.h randomFile.cpp randomFileApp.cpp

run-task2: randomFile
	./randomFile
