#pragma once
#include <iostream>
#include <vector>
struct Counter
{
	long long correctlyPlacedchar = 0;
	long long   missPlacedchar =0;
};
class GameManager
{
public:
	void StartGame();
	void EndGame();
	Counter guessesAndMisses(std::string& input) const; 

	bool checkDuplicate(std::string word);
	std::vector<std::string>CheckValidWords(std::vector<std::string>& wordList);
	void ManageInput(std::string& input);
	bool isDuplicateCharacter;
	bool isGameOver;
	std::string hiddenWord;
	std::string input;
	int lives;
	size_t  my_random(const size_t& min, const size_t& max);
	size_t  randNum;
};

