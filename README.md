## Grammar Corrector and Dictionary
This is a Grammar Corrector and Dictionary that me and my friends developed for our Data Structures project. The program makes use of basic **Natural Language Processing** I learned on my own within a limited timeframe.
The program corrects errors in helping verb placement within a sentence and works for all tenses of the English Language. The program has a limited scope of only Active Tense Sentences but works well within its scope.

### How it Works:
#### The Grammar Corrector Side:
The Grammar side breaks the input sentence into seperate words. Each word is searched inside a set list of verbs, helpings verbs, pronouns and prepositions. The words if found are then saved into strings and their tenses are scanned to utilize the correct position and/or the correct form of the helping verb to use. An if else ladder is used for each form of the sentence be it Indefinite, Continuous, Perfect or Perfect Continuous and this is done by checking the form of verb used.
The program in most cases changes the helping verb to go with the verb and the verb itself is only changed for Past Indefinite tenses where no other solution exists. 
The verbs and helping verbs are saved in a Hash Table of Linked Lists.

### The Dictionary Side:
The Dictionary Side was developed by my partners Saud Okzen Abbasi and Umer Ahmed. The Dictionary Side uses a set of text files for each letter each that have a huge amount of words with their meanings saved. The words are scanned and saved into an M-array tree for quick searching and the search time complexity proves to be O(1) if the word exists!
A similar approach was made the Synonyms/Antonyms.

### Technologies Used:
1. Windows Forms for GUI. The whole project is GUI based and the Windows forms were designed by myself.
2. Visual Studio 2019 for development.
3. We used HashTables, Trees and Vectors for Data Storage and processing.

### How to execute
1. The Project files as well as the code files have been uploaded. 
2. Open the .sln or the .vcxproj files in Visual Studio
3. Run the project using Ctrl + F5.
