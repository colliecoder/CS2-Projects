#include "string.hpp"
#include <iostream>

//default constructor
String::String() {
    str[0] = '\0';

}

//char constructor
String::String(char userChar) {
    str[0] = userChar;
    str[1] = '\0';
}

//char array constructor
String::String(const char array[]) {
    int i = 0;

    while (i != STRING_SIZE) {
        if (array[i] != '\0') {
            str[i] = array[i];
            ++i;
        }
        else {
            str[i] = '\0';
            break;
        }
    }
}

//these two [] operators return the location of the string's index... 
//not sure what the difference is between & vs const....
char& String::operator[] (int index) {
    return str[index];

}

char String::operator[] (int index) const {
    return str[index];

}

int String::capacity() const {
    int capacity;

    capacity = STRING_SIZE -1;

    return capacity;
}

int String::length() const {
    int length = 0;
    int i;

    for (i=0; str[i]!='\0'; ++i) {
        ++length;
    }

    return length;
}

String String::operator+ (const String& rightSide) const {
    String newString;
    int rightLength;
    int leftLength;
    int i;
    int k = 0;

   

    leftLength = length();

    //put leftSide into new string
    for(i=0; i < leftLength; ++i) {
        newString.str[i] = str[i];
    }

    //find length of rightSide
    rightLength = rightSide.length();

    //put rightSide into new string character by character
    for (i=leftLength; i < (rightLength + leftLength); ++i) {
        newString.str[i] = rightSide.str[k];
        ++k;
    }

    newString.str[i] = '\0';

    return newString;
}

bool String::operator== (const String& rightSide) const {
    bool equal;
    int leftLength;
    int rightLength = rightSide.length();
    int i;
    int j;
    int length=0;

    //find leftLength
    for (j=0; str[j] != '\0'; ++j) {
        length++;
    }

    leftLength = length;

    if (leftLength != rightLength) {
        equal = false;
        return equal;
    }

    //iterate through array comparing left side with right side
    for (i=0; i < rightLength; ++i) {
        if (str[i] != rightSide.str[i]) {
            equal = false;
            return equal;
        }
         }

         equal = true;
         return equal;
    }



bool String::operator< (const String& rightSide) const {
    int i = 0;

    // check if they are equal aka not less Than
while (rightSide.str[i] == str[i]) {
    if (str[i] == '\0' && rightSide.str[i] == '\0') {
        return false;
    }
    ++i;
}

//compares left and right side of char[] string returning bool true/false based on ASCII values
return str[i] < rightSide.str[i];
}

std::istream& operator>>(std::istream& input, String& inputString) {
   input >> inputString.str;

   return input;
}

std::ostream& operator<<(std::ostream& output, const String& outputString) {
    int i = 0;

    //prints bigint into a ostream
        while(outputString.str[i] != '\0') {
            output << outputString.str[i];
            ++i;
        }
    
    output << '\0';

    return output;
}


//==============================================================================

//array + string
String operator+ (const char leftSide[],  const String& rightSide) {
    String result;

    result = leftSide + rightSide;
    
    return result;
}

//char + string
String operator+ (char leftSide, const String& rightSide) {
    String result;

    result = leftSide + rightSide;

    return result;

}

// char[] + string
bool operator== (const char leftSide[], const String& rightSide) {
    bool answer;

    if(leftSide == rightSide) {
        answer = true;
    }
    else {
        answer = false;
    }

    return answer;
}

//char == string
bool operator== (char leftSide, const String& rightSide) {
     bool answer;

    if(leftSide == rightSide) {
        answer = true;
    }
    else {
        answer = false;
    }

    return answer;

}

//char[] < string
bool operator< (const char leftSide[],  const String&rightSide) {
     bool answer;

    if(leftSide < rightSide) {
        answer = true;
    }
    else {
        answer = false;
    }

    return answer;

}

//char < string
bool operator< (char leftSide, const String& rightSide) {
     bool answer;

    if(leftSide < rightSide) {
        answer = true;
    }
    else {
        answer = false;
    }

    return answer;

}

bool operator<= (const String& leftSide, const String& rightSide) {
     bool answer;

    if((leftSide < rightSide) || (leftSide == rightSide)) {
        answer = true;
    }
    else {
        answer = false;
    }

    return answer;
    


}

bool operator!= (const String& leftSide, const String& rightSide) {
     bool answer;

    if(leftSide == rightSide) {
        answer = false;
    }
    else {
        answer = true;
    }

    return answer;

}

bool operator>= (const String& leftSide, const String& rightSide) {
     bool answer;
     bool comparison;

     comparison = leftSide < rightSide;

    if((!comparison)) {
        answer = true;
    }
    else {
        answer = false;
    }

    return answer;
}

bool operator> (const String& leftSide, const String& rightSide) {
    bool answer;
    bool comparison;

    comparison = ((leftSide < rightSide) || (leftSide == rightSide));

    if(!comparison) {
        answer = true;
    }
    else {
        answer = false;
    }

    return answer;
}

//========================================================================
// additional methods/functions:



//returns the sub string from start to end position (inclusive)
String String::substr(int position, int length) const {
    String result;
    int i;
    int j = 0;
    
    for (i = position; i<(position + length); ++i) {
        result.str[j] = str[i];
        j++;
    }
    ++j;

    result.str[j] = '\0';

    return result;
}

//returns location of ch at or after pos, returns -1 if not found
int String::findch(int position, char character) {
    int location = -1;
    int i;
    int j;
 
    for(i=position; i<length(); ++i) {
        if(str[i] == character) {
            location = i;
            return location;
        }
    }

    return location;
}

//returns the location of str at or after pos, returns -1 if not found.
int String::findstr(const String& findMe) const {
    int location = -1;
    char character = findMe[0];
    int length = 0;
    int subLength = findMe.length();
    int i;
    int j;
    int k;

    for (k=0; str[k]!='\0'; ++k) {
        ++length;
    }
 
    for(i=0; i<length; ++i) {
        if((str[i] == character)) {
            location = i;
            //verify its the right string by looping through j loop
            for (j=0; j<subLength; ++j) {
                //if its not the right string location = -1
                if(str[i+j] != findMe.str[j]){
                    location = -1;
                    break;
                }
                //if it is right return start location
                else if(j == subLength) {
                    break;

                }
            }
        }
    }

    return location;
}




