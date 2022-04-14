
# output: runner_probing.o ProbingHashTable.o Hash.o
# 	g++ runner_probing.o ProbingHashTable.o Hash.o -o probing

# runner_probing.o: runner_probing.cpp
# 	g++ -c runner_probing.cpp

# ProbingHashTable.o: ProbingHashTable.cpp ProbingHashTable.h Hash.cpp
# 	g++ -c ProbingHashTable.cpp

# Hash.o: Hash.cpp Hash.h
# 	g++ -c Hash.cpp

# clean:
# 	rm *.o probing

all: probing

probing: runner_probing.cpp ProbingHashTable.cpp Hash.cpp
	g++ -std=c++17 runner_probing.cpp ProbingHashTable.cpp Hash.cpp -o probing

clean:
	rm probing
