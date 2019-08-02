This is an old program I was asked to submit for an entry level SQA interview. The program passed the interview at the time.

Mjnari Richards

Compile:
gcc -o vAuto vAuto.c

Run: This will allow you to manually enter values
./vAuto

Run against test suite:
./vAuto < test.txt



View my last run of test suite in output.txt



Notes:
1) Test suite attempts to handle all expected cases as well as known edge cases.

2) "Alphabetic character" was interpreted as letters in the U.S "standard" english alphabet.  Any letters, or symbols, from another alphabet are treated as "non-alphabetic" and handled appropriately. 
	Reasoning: While I know of some letters outside this alphabet (such as ñ or á) I do not know anywhere near all of them.

3) Upper and lower case letters were interpreted to be treated as the same letter in regards to "distinct letters," but are printed seperately.
	3a) "abBA" returns "a1A" since I did not consider "b" a distint letter from "B"

4) "The first letter of the word, the count of distinct letters between the first and last letter, and the last letter of the word" was interpreted to mean the following.
	4a) "a" returns "a0a" since "a" is both the first and last letter with no letters in between.
	4b) "aa" also returns "a0a" since "a" is again both the first and last letter with no letters in between.
	4c) "aaa" returns "a1a" since "a" is the first and last letter, but "a" is also the distinct letter in between.  This is because the wording is ambiguous as to whether the first and last letter are to be considered when deciding a "distinct letter," or if only the "letters between the first and last letter" 
		are to be considered. The provided example "Automotive parts" does not cover this case, so I interpretted it as the later.

Thank you for your time, and I look forward to hearing your thoughts on my program,
MJ
