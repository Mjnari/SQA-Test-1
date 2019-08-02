/*
PP 1.6: In the language of your choice, write a method that modifies a string using the following rules:

1. Each word in the input string is replaced with the following: the first letter of the word, the count of
distinct letters between the first and last letter, and the last letter of the word. For example,
“Automotive parts" would be replaced by "A6e p3s".

2. A "word" is defined as a sequence of alphabetic characters, delimited by any non-alphabetic
characters.

3. Any non-alphabetic character in the input string should appear in the output string in its original
relative location.
We are looking for accuracy, efficiency and solution completeness. Please include this problem
description in the comment at the top of your solution. The problem is designed to take approximately
1-2 hours.
*/

//Mjnari Richards
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int modWord(char word[256])
{
	int n = 0;
	int k, new, count;
	char letter[26];
	
	printf("Your modified word is: ");

	while (word[n] != '\n')
	{
		//char is alphabetic
		if (isalpha(word[n]))
		{
			count = 0;
			memset(letter, 0, sizeof(letter));
			//handles a "word"
			while (isalpha(word[n]))
			{
				new = 1;
				k = 0;
				//first char
				if (n == 0 || !isalpha(word[n-1]))
					printf("%c", word[n]);
				//middle char/s
				else if (isalpha(word[n + 1])){
					//is char new?
					while (k < count)
					{
						if (letter[k] == tolower(word[n]))
						{
							//char not new
							new = 0;
							k = count;
						}
							k++;
					}
					//char is new
					if (new == 1)
					{
						letter[count] = tolower(word[n]);
						count++;
					}
				}
				n++;
			}
			//last char
                        printf("%d%c", count, word[n - 1]);
		}
		//char not alphabetic
		printf("%c", word[n]);
		if (word[n + 1] != '\0') //prevents overflow if last char in line is alphabetic
			n++;
	}
	printf("\n\n");
	return 0;	
}

int main() 
{
	char *word;
	size_t bufsize = 32;
	size_t characters;
	
	word = (char *)malloc(bufsize * sizeof(char));
	if (word == NULL)
	{
		perror("Unable to allocate buffer \"word\"");
		exit(1);
	}

	do
	{
		//prompt user for input
		printf("Enter the word/s you want modified.\nIf you are done using this program press enter with no other input.\n");
		if (characters = getline(&word, &bufsize, stdin))
		{
			//printf("You entered: %s", word);
			printf("You entered: %s", word);
			modWord(word);
		} else
		{
			perror("Read error\n");
			exit(1);
		}
	} while (word[0] != '\n');
	
	printf("Have a nice day\n");
	return 0;
}
