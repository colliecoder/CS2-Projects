### String

A fun project to create a string class in C++ from scratch, employing dynamic arrays and deepening my understanding of operator overloading and memory management 🧠.

#### Project Overview

The String project tasks involved developing a highly functional String class capable of performing a variety of operations akin to those provided by the standard C++ string library.

#### Key Features

- **Custom String Handling:** Implements a class for string manipulation without using the C++ standard `string` or other libraries, focusing on manual memory and resource management.
- **Dynamic Arrays:** Utilizes dynamically allocated arrays to efficiently manage character sequences, showcasing skills in dynamic memory allocation.
- **Operator Overloading:** Extensively uses operator overloading to enable natural syntax for string operations such as concatenation, comparison, and assignment.

#### Implementation Highlights

- **Constructors:** Offers multiple constructors for diverse initialization scenarios, including default, character, and character array constructors.
- **Operator Overloading:** Implements a suite of overloaded operators to facilitate string concatenation (`+`), comparison (`==`, `<`), and assignment (`=`) among others, enhancing the usability and flexibility of the String class.
- **String Manipulation:** Provides essential string functionalities like substring extraction (`substr`), character and substring search (`findch`, `findstr`), and stream insertion and extraction operators (`<<`, `>>`), broadening the class's applicability.

#### Usage

```cpp
#include "string.hpp" // Include the custom String class header

// Create String instances
String s1; // Default constructor
String s2 = 'a'; // Char constructor
String s3 = "hello"; // Char array constructor

// Perform operations
String s4 = s2 + s3; // Concatenation
bool isEqual = (s2 == s3); // Comparison
```
#### Contribution

Since this was originally a school project I would prefer if people did not contribute to this project at the moment. I use github to store, maintain and showcase my code for string but it is a purely educational project - not a collaborative one. As such I have not included a license and maintain the copyrights of my personal code. Please feel free to download and explore this project at your own leisure as long as it is not being used for plagiarism or modified!

#### Future Directions

While this project served as an invaluable learning experience, refining and extending the String class is an ongoing pursuit. Future enhancements may include optimizing memory usage and expanding the set of string operations - but most likely if I do anything else with C++ it will be a new project related to my passion of AI development!
