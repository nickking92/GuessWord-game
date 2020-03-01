#pragma once
#include "GameManager.h"
#include "WordList.h"
#include <random>
#include <time.h>
size_t GameManager::my_random(const size_t& min, const size_t& max)
{
	return rand() % (max - min + 1) + min;
}
	void GameManager::StartGame()
	{
		srand(time(NULL));
		isGameOver = false;
		std::cout << "Word Wizard \n";
		std::cout << "Guess the correct word \n";
		randNum = my_random(0,CheckValidWords(dictionaryWords).size());
		std::string element = CheckValidWords(dictionaryWords)[randNum];
		hiddenWord = element;
		std::cout << "Hidden word is " << hiddenWord << "\n";
		lives = hiddenWord.length();
		//std::cout <<"Lives: "<< lives << std::endl;
		
	}
	void GameManager::EndGame()
	{
		isGameOver = true;
		
	}
	bool GameManager::checkDuplicate(std::string word)
	{
		for (long long  index = 0;index <word.length();index++)
		{
		for(long long  compare=index+1;compare < word.length();compare++)
		{
			if (word[index] ==word[compare]) {
			
				return true;
			}
		}
			return false;
		}
	}

	void GameManager::ManageInput(std::string& input)
	{
		while (std::cin >> input) {

			if (input == hiddenWord)
			{
				std::cout << "Well done! Thats correct word " << std::endl;
				std::cout << "-----------------------------" << std::endl;
				StartGame();

			}
			else if (input.length() != hiddenWord.length())
			{
				std::cout << "Word contains more or less than " << input.length() << " characters!" << std::endl;
				std::cout << "Guess again" << std::endl;

			}else
			{
				if(input.length()> 8)
				{
					std::cout << "Greska" << std::endl;
				}
			}

			if (!isDuplicateCharacter) {
				checkDuplicate(input);
				std::cout << "Word cant contain duplicate characters " << std::endl;
			}

			lives--;
			std::cout << "Lives left: " << lives << std::endl;
			const Counter& counter = guessesAndMisses(input);
			std::cout << "You have " << counter.correctlyPlacedchar << " correctly placed characters " << "and "\
				<< counter.missPlacedchar << " misplaced characters" << std::endl;
			if (lives <= 0)
			{
				lives = 0;
				std::cout << "You run out of lives" << std::endl;
				std::cout << "Game Over" << std::endl;
				EndGame();
				return;
			}
		}
	
	}
	

	std::vector<std::string>GameManager::CheckValidWords(std::vector<std::string>& wordList)
	{
		std::vector<std::string> ValidWord;

		for(std::string word :wordList)
		{
			if (word.size() >= 5 && word.size() <= 8 && checkDuplicate(word))
			ValidWord.push_back(word);
		}
		return ValidWord;
	}

	Counter GameManager::guessesAndMisses(std::string& input) const
	{
		Counter count;
	
		for (size_t guessIndex = 0; guessIndex < input.size(); guessIndex++)
		{

				if (input[guessIndex] == hiddenWord[guessIndex])
				{
					count.correctlyPlacedchar++;
					continue;
				}

				for (size_t hiddenIndex = 0; hiddenIndex < hiddenWord.size(); hiddenIndex++)
				{
					if (input[guessIndex] == hiddenWord[hiddenIndex])
					{
						count.missPlacedchar++;
						break;
					}

				}			
			return count;
		}
	}