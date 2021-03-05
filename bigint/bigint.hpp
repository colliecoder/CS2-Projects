//Kiersten Campbell
//CS2
//1-29-2020
//bigint.hpp

#ifndef CS2_BIGINT_HPP
#define CS2_BIGINT_HPP
#include <iostream>


const int CAPACITY = 400;

  class bigint {
      public:

        //default constructor
        bigint();

        //int constructor
        bigint(int);

        //char string constructor
        bigint(const char[]);

        void debugPrint(std::ostream&);

        /*overload operator << - in this case overloading refers to rewriting the << to 
        include a case of bigint */

        friend std::ostream& operator << (std::ostream&, const bigint&);

        /*overload operator == - this operator is able to compare bigint to another bigint
        the boolean value returns true if equal and false if unequal */
        
        bool operator==(const bigint&);

        /*overload of operator >> aka input operator */

        friend std::istream& operator>> (std::istream&, bigint&);

        /*
        addition operator + - this operator is able to add one bigint 
        with another bigint using the numbers places. Returns the answer in a bigint
        */
       bigint operator+(const bigint&) const;

       /*subscript operator - returns the power of the subscript location i.e. i in 10^i*/

       int operator[] (int) const;

       /* multiplication operator- this gives us the ability to multiply two bigints and returns a bigint
       as the answer */

       bigint operator*(const bigint&) const;

       /* times10 is a friendly function that multiplies a bigint by 10^i 
       In a nutshell it basically adds zeros so (bigint 234, int 2) input
       would result in 23400 being returned as a bigint  */

       friend bigint times10(const bigint&, int);

       /* timesDigit multiplies a bigint by and int (0-9). Please do not enter invalid input */
       friend bigint timesDigit(const bigint&, int);

       /*the factorial operator is a bonus that does some factorial stuff */

       bigint operator!() const;

      private:
        //array of integers
        int intArray[CAPACITY];
  };

  #endif

