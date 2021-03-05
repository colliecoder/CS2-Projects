//Kiersten Campbell
//CS2
//1-29-2020
//bigint.cpp

//Updated 9-27-2020 for readability and clearness

#include "bigint.hpp"

/*
-> bigint is a relatively simple programming class which relies on an array of integers 
-> I highly suggest starting with the read me documentation to gain a better understanding of bigint before launching into reading the code
-> I start out by walking the reader through the code step by step with comments for educational purposes and then allow the code to speak for itself in later section
-> enjoy!
*/






//default constructor - set to initialize bigint to zero
bigint::bigint() {
    int i;
    
    //this loop sets the array of ints of the bigint class to zero
    //CAPACITY is in the a global variable set in bigint.hpp which represents the max capacity of intArray
    for (i=0; i < CAPACITY; ++i) {
        intArray[i] = 0;
    }
}

//int constructor - converts integer input into a bigint
bigint::bigint(int userNum) {
    int placeValue;
    int i = 0;

    while (i!=CAPACITY) {
        intArray[i++] = userNum % 10;
        userNum = userNum / 10;
    }
}

/*char string constructor - takes input bigger than int in the form 
of a string and converts said string to bigint form */
bigint::bigint(const char input[]) : bigint {
    int i = 0;
    int size = 0;

    //gets length
    while(input[size] != '/0') {
        size++;
    }

    //transfer chars into bigint
    for (i = 0; i < size; ++i) {
        intArray[i] = input[size - i] - '0';
    }
}

//debug print - prints out bigint for debugging purposes
void bigint::debugPrint(std::ostream& output) {
    int i;

    //output
    for (i=CAPACITY-1; i >= 0; --i) {
        output << intArray[i] << " | ";
    }
}

/*read before proceeding 
for anyone unfamiliar with the concept of operator overloading refresh with this great YouTube video by the Cherno:
https://www.youtube.com/watch?v=mS9755gF66w&t=380s */

//operator overload <<
std::ostream& operator<< (std::ostream& output, const bigint& bigNum) {
    bool print = false;

    //prints bigint into a ostream
    for(int i = CAPACITY-1; i > 0; --i) {
        if(bigNum.intArray[i] != 0) {
            print = true;
        }
        if(print) {
            output << bigNum.intArray[i];
        }
    }
    
    output << bigNum.intArray[0];

    return output;
}

//overload ==
bool bigint::operator== (const bigint& rightBigNum) {
    int i;

    for (i=0; i<CAPACITY; ++i) {

        if(rightBigNum.intArray[i] != intArray[i]) {
            return false;
        }
    }

    return true;
}

/*
Overload input operator>> 
Works in the following manner: 
Read in any number of digits until a semi colon ";" is encountered. 
The number may span over multiple lines.
Assumes the input is valid. 
*/
 std::istream& operator>> (std::istream& input, bigint& userNum) {
    char a;
    char tempArray[CAPACITY+1];
    int counter = 0;

    /*
     For the length of the input stream puts the input into char 'a'
     Counts the length of the intArray
     ... also stores it in tempArray 
     */
    input >> a;
    while(a !=';' && !input.eof()) {
        tempArray[counter]  = a;
        ++counter;
        input >> a;
    }
     
    tempArray[counter] = '\0'; // Setting null allows the char ctor to work - see Cherno video: https://www.youtube.com/watch?v=FeHZHF0f2dw

    userNum = bigint(tempArray);

    return input;
 }


//overloaded ++ operator for adding two bigints together... this was a bitch to figure out
bigint bigint::operator+(const bigint& rightBigNum) const {
    int place = 0;
    int remainder = 0;
    int carry = 0;
    bigint answer;
    int i = 0;

    for (i = 0; i < CAPACITY; ++i) {
        //performs initial addition of a column
        place = rightBigNum.intArray[i] + intArray[i];
    
        
        //checks the column to see if anything will carry over into the next column
        remainder = (place % 10) + carry;
        if (remainder == 10) {
            remainder = 0;
            carry = 1;
        }
        else {
            carry = (place / 10);
        }
        
        answer.intArray[i] = remainder;
    }

    return answer;
}



/*Overload the subscript operator[]. 
It returns the i-th digit, where i is the 10^i position. 
So the first digit is the the one's place (10^0) and the second digit is 10^1 (ten's place).
*/

int bigint::operator[](int power) const {
    int subscript;

    subscript = intArray[power];

    return subscript;

}

bigint timesDigit(const bigint& multiplyMe, int digit) {
    bigint answer = multiplyMe;
    int carry = 0;
    int place;
    int i;
    int length;
    int counter;


    for(i=0; i<CAPACITY; i++) {
        place = (digit * multiplyMe.intArray[i]) + carry;
        carry = place / 10;
        place = place % 10;
        
        //set answer equal to place
        answer.intArray[i] = place;
    }
        if (answer == 0) {
            return 0;
        }
    
        return answer;
}

bigint times10(const bigint& multiplyNum, int zeros) {
    bigint answer;
    int i;

    /*

    if (zeros == zeros) {
        std::cout << "wait what?"
        return multiplyNum;
    }

    */

    for (i=zeros; i < CAPACITY; ++i) {
        answer.intArray[i] = multiplyNum.intArray[i - zeros];
    }

    if (answer == 0) {
        return 0;
    }


    return answer;
}

/*
Multiplication of bigint with multiple digits - 
this needs to use timesDigit and times10 or it gets way 
too complicated so make sure that timesDigit() and times10() have been tested before beginning 
the * operator overload. 

To develop this function I looked at how long multiplication worked and developed a step to step
algorithm for "doing long multiplication" with my bigint. This is probably a good way to think 
about it if you don't have pseudocode to work with. 
*/
bigint bigint::operator*(const bigint& rightBigNum) const{
    int i;
    bigint product = 0;
    bigint temp;

    for (i=0; i<CAPACITY; i++) {
         
        temp = timesDigit(*this, rightBigNum.intArray[i]);
        product = product + times10(temp, i);
    }

    return product;
}

/*
the human brain is wider, computers are taller
*/
