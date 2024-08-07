# GraduatedRecall
Final Project - Data Structures - CU Boulder - Summer 2024

Project Motivation and Background Information - Language learning and how to remember it all

For my project, I have designed an English/German vocabulary quiz application. I have been learning German for 2+ years and can speak conversationally today, though my vocabulary is limited. While aural recognition, syntax, and grammar are generally the more challenging conceptual hurdles, vocabulary remains one of the greatest challenges in true language learning mastery due to its sheer size. While "fluency" is not a concrete definition and many argue over the number of words needed to qualify it, most estimates agree that 10,000 words is a solid benchmark for "near-native" speech. The problem here becomes fairly obvious… Vocabulary focused apps like Duolingo might introduce 5 - 10 words daily, meaning you will have to keep that streak up for roughly 2.5 - 3 years! This of course assumes 100% retention and does not consider the other elements of language learning mentioned previously.

Spaced repetition is a learning system that posits our need for multiple exposures to new material before committing that material to long term memory (see the graph below). Graduated Recall is a specific implementation of this learning system that comes from the Pimsleur Language Learning Method. I personally stated my German learning journey with Pimsleur and I am a constant advocate of its efficacy. The name also more clearly outlines the concept, which is that these multiple exposures should be spaced further and further apart as we become more familiar with the material.


Project Overview - A simple application that simplifies vocabulary while saving trees!

To aid in my vocabulary studies and save many, many index cards, I have built a program to quiz a given list of German vocabulary words that can be imported by saving as "NEWWORDS.xlsx" in the "VocabLists" folder of the project. No need to worry about system differences in file path as I have controlled for that by writing the file path at run time. As long as the user saves a two column csv (English to German) to the aforementioned file name in the project, it should run!

The basic outline of program execution is as follows:

    - An algorithm generates a list of words to study from several other lists corresponding to the users familiarity with the word.
    - The main quiz loop then runs and displays the words in this study list and their translations, one at a time, prompting the user to sort each by how confident they are in the answer. 
    - Each word is appended back to its newly selected confidence level which places it at the end (or bottom) of the list so it will be encountered only after less recently seen words.
    - Each time the user restarts the application, their previous sorting will affect the generation of their new study list.

At a high level, the goal is to cycle through several words over multiple uses, displaying weaker words more often than strong words as prescribed by the graduated recall methodology.

Data Structure Review - An argument for the doubly linked list

This project leverages 5 doubly linked list in C++ which I named "VocabList" for clarity. The class contains two pointer variables to the head and tail of the list, a host of member functions to perform both essential list operations as well as application specific functions, and the definition for the node struct, which contains and English word (string), its German translation (string), and  pointers to both the next and previous node in the list.

List Details:

    - The first 3 are buckets for different levels of familiarity with a word (weak, medium, and strong). As a user is tested on a word, they are also asked to sort that word into one of these buckets. Each of these lists also has a respective csv to allow the user to continue working through a set of words and save their progress overall multiple different executions of the application.
    - The 4th list is generated from a "NEWWORDS" csv. This is how vocabulary is loaded into the application on first use, and how a user configurable number of new words can be added to the study bank each time. The list is manipulated and overwritten to the csv as with the other buckets so that duplicates are never introduced. This is where the real value in the application shines as a user can simply add a large list of new words one time and continue using the application until all of the words have been sorted into the "strong" bucket.
    - The 5th list does not have a backing csv and is used to pool a combination of words from each familiarity bucket. This list is what the user will be tested on as it is traversed, with each word (list node) being sorted back to the user selected bucket during execution.

I chose the doubly linked list for several reasons:

    - Firstly, it was covered in our textbook material and I found it more intuitive and flexible than the singly linked list. I feel this is well worth the cost of 1 pointer variable on each node (at least in the scope of the amount of data I expect here).
    - Secondly, in thinking about the design of the project, I imagined the user may want to cycle back through the list if they skipped ahead too fast or wanted to edit their confidence level and a previous word. While these are future state items for my project, the "previous" node pointer will be extremely useful for this functionality.
    - Lastly, linked lists are all about pointers. I wanted more practice with them and the challenges of removing them from one list without breaking a currently executing loop or creating circular reference. I believe a vector would have been a sensible alternative.

For specific function descriptions, please review the .h files.

Executing Instructions

    - I compiled my program on a windows machine using the g++ compiler available through  the C/C++ extension in Visual Studio Code. 
    - To test, run on VSC with the same extension enabled.
    - Either use the prepackaged list of a few vocab words or build your own csv, dropping it in the "VocabLists" folder and saving as NEWWORDS.csv

Architecture Diagram

    - TBC

Links

    - https://en.wikipedia.org/wiki/Spaced_repetition
    - https://www.pimsleur.com/

