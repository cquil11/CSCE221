all: probing chaining HashCoin

probing: runner_probing.cpp ProbingHashTable.cpp Hash.cpp
	g++ -std=c++17 runner_probing.cpp ProbingHashTable.cpp Hash.cpp -o probing

chaining: runner_chaining.cpp ChainingHashTable.cpp Hash.cpp
	g++ -std=c++17 runner_chaining.cpp ChainingHashTable.cpp Hash.cpp -o chaining

HashCoin: HashCoin.cpp Hash.cpp Block.h
	g++ -std=c++17 HashCoin.cpp Hash.cpp Block.h -o HashCoin

clean:
	rm probing chaining HashCoin
