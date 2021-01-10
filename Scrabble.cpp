/**
*
* Solution to course project # 8
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Pavlin Dimitrov
* @idnumber 62614
* @compiler VS
*
* <file with helper functions>
*
*/

using namespace std;
#include <iostream>
#include <string>
#include<fstream>
#include<vector>
int commandNumberValidator(int number)
{
	while (true)
	{
		if (number < 1 || number>4)
		{
			cout << "You entered an invalid number. Please enter a number between 1 and 4:";
			cin >> number;
		}
		else
		{
			break;
		}
	}
	return number;
}
string validatedWord(string inputWord)
{
	bool isValid = true;
	int sizeWord = 10;
	if (inputWord.size()!=sizeWord)
	{
		isValid = false;
	}
	for (int i = 0; i < inputWord.size(); i++)
	{
		char currentLetter = inputWord[i];
		if (currentLetter<97||currentLetter>122)
		{
			isValid = false;
			break;
		}
	}
	if (!isValid)
	{
		cout << "Enter a valid word that contains 10 small letters:";
		string newWord;
		cin >> newWord;
		validatedWord(newWord);
	}
	else
	{
		return inputWord;
	}
}
int validatedSettingsNumber(int number)
{
	while (true)
	{
		if (number < 1 || number>20)
		{
			cout << "You entered an invalid number. Please enter a number between 1 and 20:";
			cin >> number;
		}
		else
		{
			break;
		}
	}
	return number;
}
bool wordValidator(string inputWord, char currentWord[])
{
	int maxSizeWord = 10;
	bool containsChar;
	if (inputWord.size() > 10)
	{
		return false;
	}
	for (int i = 0; i < inputWord.size(); i++)
	{
		containsChar = false;
		for (int j = 0; j < maxSizeWord; j++)
		{
			if (inputWord[i] == currentWord[j])
			{
				containsChar = true;
				break;
			}
		}
		if (!containsChar)
		{
			return false;
		}
	}
	return true;

}
void falseWordOutput(char currentWord[])
{
	cout << "Invalid word! Try again with: ";
	int maxSizeWord = 10;
	for (int i = 0; i < maxSizeWord; i++)
	{
		if (i == 9)
		{
			cout << currentWord[i];
		}
		else
		{
			cout << currentWord[i] << " ";
		}
	}
	cout << endl;
	cout << "Enter word:";
}
vector <string> dictionaryCorrectWords(int currentRound)
{
	vector <string> correctWords;
	if (currentRound == 1)
	{
		correctWords.push_back("cat");
	}
	else if (currentRound == 2)
	{
		correctWords.push_back("pet");
	}
	else if (currentRound == 3)
	{
		correctWords.push_back("time");
		correctWords.push_back("dog");
	}
	else if (currentRound==4)
	{
		correctWords.push_back("dad");
	}
	else if (currentRound==5)
	{
		correctWords.push_back("king");
	}
	else if (currentRound==6)
	{
		correctWords.push_back("life");
	}
	else if (currentRound==7)
	{
		correctWords.push_back("true");
		correctWords.push_back("lie");
	}
	else if (currentRound==8)
	{
		correctWords.push_back("heart");
	}
	else if (currentRound==9)
	{
		correctWords.push_back("smile");
	}
	else if (currentRound==10)
	{
		correctWords.push_back("water");
	}
	else if (currentRound==11)
	{
		correctWords.push_back("wallet");
	}
	else if (currentRound==12)
	{
		correctWords.push_back("dress");
	}
	else if (currentRound==13)
	{
		correctWords.push_back("laptop");
	}
	else if (currentRound==14)
	{
		correctWords.push_back("rat");
		correctWords.push_back("hat");
	}
	else if (currentRound==15)
	{
		correctWords.push_back("paper");
	}
	else if(currentRound==16)
	{
		correctWords.push_back("wiskey");
	}
	else if (currentRound==17)
	{
		correctWords.push_back("vodka");
	}
	else if (currentRound==18)
	{
		correctWords.push_back("football");
		correctWords.push_back("foot");
		correctWords.push_back("ball");
	}
	else if (currentRound==19)
	{
		correctWords.push_back("alchohol");
	}
	else if (currentRound==20)
	{
		correctWords.push_back("love");
	}
	return correctWords;
}
void commands()
{
	cout << "If you want to start a new Scrabble Game press 1" << endl;
	cout << "If you want to go to Settings press 2" << endl;
	cout << "If you want to include a new word press 3" << endl;
	cout << "If you want to Exit the game press 4" << endl;
	cout << "Enter a number for command:";
}
void gameStarter(int numberRounds)
{
	cout << "Congratulations! You managed to start a new game!" << endl;
	cout << "Good luck!" << endl;
	fstream inputFile;
	inputFile.open("dictionary.txt");
	char currentChar = ' ';
	int counterRounds = 1;
	int counterCharacters = 0;
	int totalScore = 0;
	const int maxSizeWord = 10;
	char currentWord[maxSizeWord];

	if (inputFile.is_open())
	{
		cout << "Round " << counterRounds << ". Available letters: ";
		while (!inputFile.eof())
		{
			
			inputFile >> skipws >> currentChar;
			if (currentChar != '\n')
			{
				currentWord[counterCharacters] = currentChar;
				cout << currentChar << " ";
				counterCharacters++;
			}
			if (counterCharacters == 10)
			{
				cout << endl;
				cout << "Enter word:";
				string inputWord;
				cin >> inputWord;
				bool isValidWord = wordValidator(inputWord, currentWord);
				if (!isValidWord)
				{
					while (true)
					{
						falseWordOutput(currentWord);
						cin >> inputWord;
						isValidWord = wordValidator(inputWord, currentWord);
						if (isValidWord)
						{
							break;
						}
					}
				}
				vector <string> correctWords = dictionaryCorrectWords(counterRounds);
				for (int i = 0; i < correctWords.size(); i++)
				{
					int score = 0;
					if (correctWords[i] == inputWord)
					{
						for (int j = 0; j < inputWord.size(); j++)
						{
							score = j;
						}
						score++;
						totalScore += score;
					}
				}
				if (counterRounds == numberRounds)
				{
					cout << "Your total score is:" << totalScore;
					inputFile.close();
					break;
					commands();
				}
				counterRounds++;
				cout << "Round " << counterRounds << ". Available letters: ";
				counterCharacters = 0;
			}			
		}
	}
	else
	{
		cout << "There is an issue with oppening the dictionary!";
	}
}
void mainCommands(int numberRounds)
{
	commands();
	int inputNumber;
	cin >> inputNumber;
	int validatedInputNumber = commandNumberValidator(inputNumber);
	if (validatedInputNumber == 1)
	{
		gameStarter(numberRounds);
		cout << endl;
		mainCommands(10);
	}
	else if (validatedInputNumber == 2)
	{
		cout << "You can change the number of rounds!" << endl;
		cout << "Enter your disered number of rounds from 1 to 20:";
		int inputNumber;
		cin >> inputNumber;
		int validatedNumber = validatedSettingsNumber(inputNumber);
		cout << "Congratulations! You changed the number of rounds to " << validatedNumber << "!";
		cout << endl;
		mainCommands(validatedNumber);
	}
	else if (validatedInputNumber==3)
	{
		cout << "You can now add a new word to the dictionary!"<<endl;
		cout << "Enter a word that has 10 letters: ";
		string inputWord;
		cin >> inputWord;
		string validatedInputWord = validatedWord(inputWord);
		string validatedWordWithSpaces;
		for (int i = 0; i < validatedInputWord.size(); i++)
		{
			validatedWordWithSpaces += validatedInputWord.substr(i, 1)+" ";
		}
		fstream inputFile;
		inputFile.open("dictionary.txt",fstream::out|fstream::app);
		inputFile << validatedWordWithSpaces;
		inputFile.close();
		cout << "Congratulation! You managed to add the word:" << validatedWordWithSpaces << "to the dictionary!";
		cout << endl;
		mainCommands(10);
	}
	else if (validatedInputNumber==4)
	{
		cout << "You exit the game! Have a nice day!";
		return;
	}
}
int main()
{
	cout << "Welcome to Scrabble!" << endl;
	int defauldNumberRounds = 10;
	mainCommands(defauldNumberRounds);
}

