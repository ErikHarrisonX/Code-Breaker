#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 10;

	const string words[NUM_WORDS][NUM_FIELDS] = {
		{"operator", "A symbol that tells compiler to perform specific mathematical or logical manipulations."},
		{"static_cast", "A type casting operator implicit conversion between types (int to float, pointer to void), and explicit conversion functions."},
		{"register", "A request to the compiler that the specified variable has to stored."},
		{"namespace","Declarative region that provides a scope to identifiers inside."},
		{"volatile","Intended to prevent compiler from applying any optimizations on objects that change that can’t be determined by compiler."},
		{"typedef","Allows to create new names for types such as int, or, more commonly in C++.\n Can be used to provide clarity to code and easier for changes underlying data types."},
		{"dynamic_cast","Converts from a pointer/reference to a base type to a pointer/references to a derived type."},
		{"explicit","Specifies that a constructor or conversion function cannot be used for implicit conversions and copy-initalization.\n May be used with a constant expression."},
		{"typename","Keyword to create templates.\n Specifying name in template definition or declaration is a type."},
		{"reinterpret_cast","A type of operator used to convert one pointer of another pointer of any type, even if the class is related to each other or not."}
		
	};

	char playAgain = 'y';

	srand(time(0));

	do
	{
		int choice = (rand() % NUM_WORDS);
		//gets the word
		string theWord = words[choice][WORD];
		//gets the hint for the word
		string theHint = words[choice][HINT];
		//jumbles the word v
		string jumble = theWord;
		int length = jumble.size();
		for (int i = 0; i < length; i++)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}
		//displays the jumbled word for player
		string guess;
		cout << "WORD: " << jumble << endl;
		cout << "\nEnter your guess: ";
		cin >> guess;
		while ((guess != theWord) && (guess != "quit")) 
		{
			if (guess == "hint")
			{
				cout << "HINT: " << theHint;
			}
			else
			{
				cout << "\nIncorrect.";
			}

			cout << "WORD: " << jumble << endl;
			cout << "\nEnter your guess: ";
			cin >> guess;
		}
		//Game over screen
		if (guess != "quit")
			cout << "\nCongrats! You guessed the word!" << endl;
		cout << "\n********Thanks for playing^_^*****\n";
		cout << "\nWould you like to play again (y/n)?: ";
		cin >> playAgain;
			
	} while (playAgain != 'n');

	return 0;
}