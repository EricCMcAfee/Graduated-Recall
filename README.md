# GraduatedRecall
Final Project - Data Structures - CU Boulder - Summer 2024

Project Motivation and Background Information - Language learning and how to remember it all

I've been learning German for over two years now and can hold a conversation, though my vocabulary is still growing. While understanding spoken German, syntax, and grammar can be challenging, vocabulary often proves to be one of the biggest hurdles in achieving true language mastery due to its vastness. Although there’s no universal definition of "fluency" and debate exists over the exact number of words needed to achieve it, most estimates suggest that around 10,000 words are necessary for "near-native" proficiency. The challenge becomes apparent when considering that vocabulary-focused apps like Duolingo might only introduce 5 to 10 new words each day, which means maintaining that pace for approximately 2.5 to 3 years to reach this goal. This estimation assumes perfect retention and doesn’t account for other aspects of language learning.

Spaced repetition is a learning technique based on the principle that we need several exposures to new information before it becomes entrenched in long-term memory (see the graph below - credit Wikipedia). Graduated Recall is a specific application of this approach, developed through the Pimsleur Language Learning Method. I began my German studies with Pimsleur and strongly support its effectiveness. The name "Graduated Recall" aptly captures the idea that, as we become more familiar with the material, the intervals between review sessions should gradually lengthen.

<img src = "https://github.com/EricCMcAfee/Graduated-Recall/blob/main/Documentation/Forgetting%20Curve.png" width = "600">

Project Overview - A simple application that simplifies vocabulary while saving trees!

    To support my vocabulary studies and reduce the need for countless index cards, I developed a program that quizzes you on a list of German (or any foreign language) vocabulary words. To use it, simply import a CSV file by saving it as "NEWWORDS.xlsx" in the "VocabLists" folder of the project. I’ve handled file path differences across systems, so you don’t need to worry about that—just make sure your CSV file is saved with two columns (English and German) and the specified file name. Note: Be sure there is no whitespace at the top of your CSV file!

    The basic outline of program execution is as follows:

    -  Currently, all user input and program output are handled through the terminal, though I plan to add more modern and visually appealing UI elements in the future.
    - The user is prompted to specify the number of new words they want to add to their study rotation.
    - An algorithm then creates a study list from these new words, along with words from several other lists based on the user’s familiarity with previously studied vocabulary.
    - The main quiz loop displays the words from this study list and their translations one at a time, asking the user to rate their confidence in each answer.
    - Each word is then moved to the end of its selected confidence level category, ensuring it is reviewed again only after less recently encountered words (utilizing a FIFO approach).
    - When the user restarts the application, their previous responses influence the creation of the new study list, allowing for continuous progression through their entire vocabulary.

Data Structure Review - An argument for the doubly linked list

    This project uses five doubly linked lists in C++, which I’ve named "VocabList" for clarity. The class includes two pointer variables for the head and tail of the list, along with a set of member functions for performing both fundamental list operations and application-specific tasks. Additionally, the class defines a node structure that contains an English word (string), its German translation (string), and pointers to both the next and previous nodes in the list.

    List Details:

    - The first three lists categorize words by levels of familiarity: weak, medium, and strong. As users are tested on each word, they are prompted to sort the word into one of these categories. Each of these lists overwrites its respective csv file after program exeuction, allowing users to track their progress and continue from where they left off across different sessions of the application.
    - The fourth list is populated from a "NEWWORDS" CSV file. This list serves as the initial source for loading vocabulary into the application and allows users to add a configurable number of new words to their study bank each time. This list is updated and saved back to the CSV to prevent duplicates, offering significant value as users can input a large set of new words at once and continue working through them until all words are sorted into the "strong" bucket.
    - The fifth list does not have a backing CSV file. It serves as a pool that combines words from all familiarity buckets. This is the list used during the quiz execution, where words are reviewed, and each word is sorted back into the user-selected bucket during the process.

    I chose the doubly linked list for several reasons:

    - First, the concept was covered in our textbook, and I found the doubly linked list to be more intuitive and flexible than the singly linked list. The trade-off of having one additional pointer per node seems worthwhile given the expected volume of data in this project.
    - Second, considering the project’s design, I anticipated that users might want to revisit or adjust their confidence levels for previously reviewed words. Although these features are planned for future updates, the "previous" node pointer will be crucial for implementing such functionality effectively.
    - Lastly, linked lists revolve around pointers, and I wanted to gain more experience with them, particularly the challenges of removing nodes without disrupting an active loop or creating circular references. While a vector could have been a viable alternative, working with linked lists provides valuable practice with pointer management.

    For specific function descriptions, please review the .h files.

    Architecture Diagram

<img src = "https://github.com/EricCMcAfee/Graduated-Recall/blob/main/Documentation/Graduated%20Recall%20Data%20Architecture.png" width = "600">

Executing Instructions

    - I compiled my program on a windows machine using the g++ compiler available through  the C/C++ extension in Visual Studio Code. 
    - To test, run on VSC with the same extension enabled.
    - Either use the prepackaged list of a few vocab words or build your own csv, dropping it in the "VocabLists" folder and saving as NEWWORDS.csv
    - Simply follow the prompts in the terminal! You can review the updated csv files to see where your progress is sorted.

Links

    - https://en.wikipedia.org/wiki/Spaced_repetition
    - https://www.pimsleur.com/

Future State Items
- WIP

