#Strings, Vectors, and The AutoIndexer!
Sprint 1 - CSE 2341 - Fall 2016

## Introduction
Two fundamental things that you'll work with as a programmer are strings and sequential containers.  In Sprint 1, you will implement a *String* class and a *Vector* class in C++, and you will use the classes as part of an automated book indexer. You will use the classes you build for additional projects later in the semester, so it works in your favor to build a robust implementation of each class.

There are many schools of though on the best way to write code and test it.  One of these methodologies is called Test Driven Development (TDD).  In TDD, the basic idea is you write the testing code for whatever things you're working on *first*, and then write the thing to pass the tests.  For example, if you're implementing a String class, you might initially decide that String objects need to be able to be copied and printed to the screen.  So, before writing any part of the string class implementation, you write some code to test copy functionality and printing functionality.  Clearly, if string class hasn't been written yet, these test will fail - *that's exactly what you want to happen*.  Initially, all your tests will fail.  But as you begin writing the code to implement string, the tests will begin to pass.     

Quite a few frameworks exists for TDD (and unit testing, for which TDD is a particular type).  For Data Structures, we will use the (CATCH Framework)[https://github.com/philsquared/Catch].  While CATCH supports multiple paradigms of testing, we will use it in the TDD mindset for 2341.   

In this sprint, you are provided with a file called ```tests.cpp``` which shows an example of how to use the CATCH framework for testing your classes. It would be a good idea to use, at the very least, the provided CATCH example file to test your own String class.  In lab this week, more about CATCH will be covered including how to incorporate it into your projects.

## The String and Vector classes

As mentioned previously, in this sprint, you'll implement both a string class and a vector class. You'll be required to use these classes for the remainder of the semester, and allowed to update them and make them more efficient as the semester progresses as well.  So, it is in your best interest to make them as robust as possible.  

### The String Class

The String class shall represent a sequence of characters of unbounded length (within the limits of the system).  Minimally, the string class should expose an interface of functionality that is consistent with typical string libraries.  An example minimal string interface can be found in string.h associated with this sprint packet.   

The manner in which you implement the underlying functionality is up to your discretion.  One options would be to store null-terminated c-strings and effectively create a wrapper for the c-string functions.  Another option would be to simply store an array of characters and data members holding size as well as capacity.  

### The Vector Class
The Vector class should implement a standard contiguously-allocated, sequential list of elements.  The class should be templated so it can hold any data type. A Vector class should, at the very least, include a method or methods for inserting elements, and an overloaded [] operator for element lookup by index. All vectors should initially contain space for 10 elements and should grow at a rate of 1.5 times each time the capacity is reached.  A graceful handling of out-of-bounds issues is expected.  

### General Implementation Concerns

#### Dynamic Memory Management
Any class which manages dynamic memory (both of these will) must manage that memory following best practices (applying Rule-of-3, etc).  Not following those best practices could lead to segmentation faults, memory leaks, and shallow copy-related problems.

#### Testing Your Classes
It is expected that you will follow the TDD mindset when developing the string and vector classes.  The TAs have been directed to give guidance under that paradigm.  Therefore, you'll need to create your test case source files along with your project files.  This will be covered in more detail in Lab this week. You are only doing yourself a disservice by not fully investing your time and energy in TDD.  Every bug you tease out now is one less you'll need to worry about later.


<!-- It is expected that, along with your String and Vector implementations, you include some unit tests, run with the CATCH interface. An example of how to use the CATCH interface is included with this sprint. Your test cases must undeniably convince to your grader/TA that your class works for all reasonable and feasible test cases. -->

#### Running Your Code
Using the CATCH testing interface, providing a TEST_CASE in tests.cpp is equivalent to providing a main function. Inside your Sprint1 folder, you can use ```g++ *.cpp -std=c++11``` to compile your code and then ```./a.out``` to execute it and run your test cases.

## The AutoIndexer

### Introduction
Professor Harrison just got assigned to be the editor of a riveting textbook titled _Advanced Data Structure Implementation and Analysis_. She is super excited about the possibility of delving into the material and checking it for technical correctness. In addition to reviewing the technical content of the book, she mush also create an index for the book.

Everyone has used the index at the back of a book before. An index organizes important words or phrases in alphabetical order along with a “pointer” (not in the C++ sense, but in the index sense) to where that phrase can be found in the book. In most books, this “pointer” consists of a list of page numbers where that particular word or phrase can be found in the text. But, who or what creates these indexes? Are they created by humans? Are they created by computers?

Professor Harrison knows that an automated indexer is the way to go (not only because of speed, but because it can be reused later when she finishes writing her own book), but she just doesn't have time to edit the book and create the auto-indexer software in the short time frame. She has asked for your help! In this project, you will implement a program that can help Professor Harrison index a text.

### Your Task
You will implement a piece of software which can read in a book file (raw ASCII text with page indicators) and a category file, process the book data using the category file, and output the complete index to separate file.

### Input File Formats
The **input text** file will contain the text from the book to be indexed organized by pages from the book. The end of the book will be signaled by [-1] at the end of the file. All punctuation will have been removed from the file, but capitalization will still be the way it was in the original book. Here is a (very very) simple input text file:

```
[1]
This is the text that appears on page one of the book Note that there is no
[2]
punctuation anywhere but that sentence-based capitalization is still present
[3]
You only need to worry about indexing individual words not phrases
[4]
Lorem ipsum dolor sit amet consectetur adipiscing elit Phasellus condimentum
[-1]
```

Important points about the input file:
* No word in the input file will exceed 30 characters in length.  
* Page numbers may not necessarily always be in order.  
* No page number will be repeated.
* Indexing needs to be case-insensitive.  In other words, cat and Cat should be considered the same word.

The **category file** will contain information on categories to handle when indexing.  You have seen this in indexes before where it might say something like:
    _For spaniel, see dog._
Each entry in the list will be organized in the following way:

```
category = word1 word2 word3 word4
```

This means that where **word1** would appear in your index, you would output “**For word1, see category**”. Additionally, the pages where **word1** appears should be associated with the list for **category** in your implementation. Here is a sample category file:

```
apple = iphone ipad macbook
automobile = car truck toyota ford
```

### Output File Format
The output file will be organized alphabetically.  To be more precise, the output should be ordered based upon the ASCII value of the first character of the indexed token. Each letter will appear in square brackets followed by index entries that start with that letter in ascending alphabetic order. An index entry will consist of the indexed word, a colon, then a list of page numbers where that word was found in ascending order OR a reference to that word's category. No output line should be longer than 50 characters. The line should wrap before 50 characters and subsequent lines for that index entry should be indented 4 spaces.  Here is an example output file:

```
[A]
apple: 4, 12, 66, 131
asymptotic: 44, 45, 46
[B]
binary: 25, 26, 29, 88
[C]
comeonthisisacrazylongword: 13, 14, 16, 33, 101,
    102, 103, 105
[I]
For ipad, see apple.
```

Professor Harrison is a purist and doesn't trust many of the container classes and algorithms from the STL. **Therefore, she has instructed you to not use any of them.** However, through much pressuring from her students and colleagues, she has come to accept and trust the streaming libraries that are part of the STL (iostream, fstream, etc.). Prof. Harrison trusts your skills though, *so she encourages you to use your implementations of String and Vector*.

### Assumptions
You may make the following simplifying assumptions as you develop your project:
* The input files (text and category) will be properly formatted according to the rules above
* Punctuation will already be removed from the text file
* No need to worry about indexing phrases (this is much harder to do)
* No line of text in either input file will contain more than 80 characters
* No word will be longer than 30 characters
* Hyphenated words may exist in the files, but are to be considered simply one word (**sentence-based** is an individual word that is separate from the word **sentence** and the word **based** and would have its own index entry unless it was part of a category).
* No terms that are in one category will be in another category (e.g. ipad won't appear in the apple category and also the tablet category)
* Categories are only one level deep (e.g. a category term will not also be in the list of specific terms for another category)
* Categorical terms may also appear in the text
* You don't have to worry about various forms of the same word (e.g. run, runs, and running would each be considered individual words)

### Execution
The executable for this project will be run from the command line with three arguments:
* the name of the input text file,
* the name of the category file, and
* the name of the output file to write the index to.
Example:
```
prompt$ ./indexer book.dat categ.txt index.output
```

<!-- ### Implementation Details
You don't have any idea how many individual words, index entries, etc. will be present in the input data file.  Since Prof. Harrison doesn't like the STL,  you'll need to implement some “data structure” that is capable of “growing” as needed. This should sound like a great place for your Vector class.

Using dynamic memory allocation smartly, you can simulate the idea of an array growing in capacity. Therefore, this would allow you to handle really small books as well as really large books without being insensitive to memory usage issues. There is no need (and you definitely should not) allocate arrays with 50,000 elements and cross your fingers in hopes that you'll not encounter 50,001 items that need to go into your array.

In particular, you'll implement functionality that will resize your arrays as needed for the various different dimensions of your data structure (such as words, pages, page list, etc.). Figure 1 shows an overview of a potential memory layout for this project:

![archi diag](https://raw.githubusercontent.com/MarkFontenot/16S-CSE2341-Projects/proj02/ProgAssign02/screenshot.png)

At a minimum, your implementation should contain a pointer to a char pointer (char\*\*) and a pointer to an int pointer (int\*\*) at a minimum. You may have other data members as you see fit. Your implementation will likely always have some “extra” space to store more words and their page lists; **however, you may never have a data structure that is less than half-full.** -->

### What to Submit

By Tuesday Sept 6 @ 6am, you should have pushed the following to Github and opened a pull request (following the protocol from Sprint 0):
*  String class TDD test source code
*  Completed string class that passes all of your tests
*  Vector class TDD test source code
*  Vector interface (.h) file

During labs the week of Sept 12:
*  Check-ins with your TAs will happen during lab time

By Monday Sept 19 @ 6am, you should have pushed the following to Github and opened a pull request (following the protocol from Sprint 0):
*  String and Vector TDD files
*  Completed string and vector classes
*  Completed auto-indexer project source
*  qmake .pro file from QtCreator

All code submitted should :
*  be well formatted and documented
*  follow all best practices covered in lecture and lab
*  follow good design principles for object oriented programming


## Submission
You must push your work to GitHub by the due date. Your git repository must contain all of your code, design documents, and test cases.

## Grading
Your project will be graded by one of the TAs for the course.  They've all taken the course, performed well, and understand the expectations of Professor Fontenot.  

|Outcome                  		 	| Points | Points Earned |
|:------------------------			|:----------:|---------------|
|Design of String Class      		| 20        |               |
|Design of Vector Class      		| 20        |               |
|Vector Class Tests    			    | 30        |               |
|String Class Tests     			| 30        |               |
|Design of AutoIndexer   			| 30        |               |
|Source Code Quality    			| 30        |               |
|AutoIndexer Functionality     		| 40        |               |

**Please note that if any memory leaks exist in either the String or the Vector class, you will lose up to 30 points per data structure**

**Please note that code which does not compile will result in a grade of zero on the entire project!**
