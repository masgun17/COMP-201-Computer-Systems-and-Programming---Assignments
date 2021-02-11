/* 
 * CS:APP Data Lab 
 * 
 * < Mertcan Asgun 63948 >
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
  // If number is zero, negation of it gives 1. Otherwise it gives 0.
  return !x ;
}
/* 
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
    // In only one condition, implication returns 0, which is (1,0)
    return (!x)|y;
}
/* 
 * twoDigitNumberInBaseFour - return integer equivalent of (xy)_4 two digit number in base 4
 *   Example: twoDigitNumberInBaseFour(2, 3) = 11
 *   Legal ops: >> << +
 *   Max ops: 4
 *   Rating: 2
 */
unsigned twoDigitNumberInBaseFour(unsigned x, unsigned y) {
    // We have to find 4*x+y. So we will shift x to the left 2 times and add y.
  return (x << 2) + y;
}
/*
 * multThreeEighths - multiplies by 3/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*3/8),
 *   including overflow behavior.
 *   Examples: multThreeEighths(77) = 28
 *             multThreeEighths(-22) = -8
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multThreeEighths(int x) {
    // Details can be found after each line
    int value= 0 ;
    int signCheckXOR = 0;
    int signCheck = 0;
    signCheckXOR = (x>>31);  // 11...11 if negative, 00...00 if positive
    signCheck = (signCheckXOR & 1) ;  // 1 if negative, 0 if positive   
    x = ( x ^ signCheckXOR ) + signCheck ;  // Kind of absolute value - Simply 2's complement for negatives
    value = x + (x<<1) ;  // Multiply by 3
    value = value >> 3 ;  // Divide by 8
    return ( value ^ signCheckXOR) + signCheck ;  // If number was negative, this works as 2's complement.


//  But I think the following code is more accurate. However it requires 14 operation, that is why I do 
//  not submit this one, but still wanted to put it here.
//  In this one, to prevent overflow we will first use division instead of multiplication. But because of this
//  we will lose access to the last three bits of x. Therefore we are saving them as remainder before.

/*    int value= 0 ;
    int remainder= 0 ;
    int signCheckXOR = 0;
    int signCheck = 0;
    signCheckXOR = (x>>31);  // 11...11 if negative, 00...00 if positive
    signCheck = (signCheckXOR & 1) ;  // 1 if negative, 0 if positive    
    x = ( x ^ signCheckXOR ) + signCheck ;  // Kind of absolute value - Simply 2's complement
    remainder = (x & 7);  // Save last 3 digits (7 = 0b0111)
    value = x >> 3;
    value = value + (value << 1);
    remainder = (remainder + (remainder << 1)) >> 3; // Apply *3/8 algorithm on remainder also
    return ((( value + remainder ) ^ signCheckXOR ) + signCheck ) ;  // Sum them and convert it according to its sign.
*/


}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
    // We will follow a similar approach with previous question.
    // If number is 0 we get 1, we get 0 for all other numbers. For all integers x other than 0,
    // x and -x have different signs (i.e, 3 vs -3). However if x=0, also -x=0. We will use this fact.
    int shiftX = x >> 31 ;  // Depend on sign of x, either 11..111 or 00...00
    int signX = shiftX & 1 ;  // Depend on sign of x, either 1 or 0
    int complementX = (~ x)+1;  // Equals to -x
    int shiftCX = complementX >> 31 ;  // Depend on sign of -x, either 11..111 or 00...00
    int signCX = shiftCX & 1 ;  // Depend on sign of -x, either 1 or 0
    int signOR = (signX | signCX) ;  // If x is other than 0, (signX | signCX) will return 1 and ~ turn it into -2
    return (~signOR) + 2;  // If x is 0, (signX | signCX) will return 0 and ~ turn it into -1. To get 0 and 1 as desired, we add 2.


}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
    // We need 0111111...1111. We can get it by negating 1000...0000, which can be derived by left shifts.
    int x = 1 << 31;
    return ~x;
}
/* 
 * isOppositeSigns - if x and y has different signs then return 1, else return 0 
 *   Example: isOppositeSigns(4,-5) = 1.
 *            isOppositeSigns(3,2) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isOppositeSigns(int x, int y) {
    // Again, we can label x and y as positive or negative. Then we will XOR those labels, if they are different
    // it will return 1, otherwise return 0, as we wanted.
    x = ( x >> 31) & 1 ; // either 1 or 0
    y = ( y >> 31) & 1 ;
  return x ^ y;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    // If x is either 11...111 or 00..000, then we could simply return ( (x&y) | (~x&z) ). Because if x is 11....111, then
    // ~x is 00....00, and expression become (y|0), which is y. If x is 00...000, then ~x is 11....11 and expression become
    // (0|z), which is z. And this behaviour is exactly what we want.

    int sign = (!x);    // If x is 0, returns 1; otherwise returns 0. We have to switch them back later
    int step1 = (sign << 31);   // Shifting left by 31 bits, so that 0x1 can become 0x80000000
    int step2 = step1 >> 31;    // Shifting right by 31 bits, so that 0x80000000 becomes 0xffffffff (i.e. all 1s, 111....111)
    int flag = ~step2;  // We are switching back, so that 0 gives 00.....0000 and nonzero numbers give 11......1111.
    return ( (flag & y) | (~flag & z) ) ;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
    // First digit decides sign. So we have to convert it to 0, while not touching others.
    unsigned int abs = uf & 0x7fffffff; // Convert most significant bit to 0.
    if (abs > 0x7f800000){  // If abs is larger than infinity (!), then
        return uf;          // return the argument
}   else {
        return abs;         // else return abs
}    
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
    int sign = (uf >> 31) & 1; // 0 means positive, 1 means negative
    unsigned int abs = uf & 0x7fffffff; // For ease of computation, we will work on positive numbers
    if (abs >= 0x7f800000){  // If abs is larger than infinity (!) or NaN, then
        return 0x80000000u;          // return 0x80000000u
    }else { 
        int exp = abs >> 23 ;   // Extract exponent by shifting
        int frac = (abs << 9) >> 9 ;    // Extract fraction; left shift to remove exponent part and then right shift back
        int expReal = exp - 127 ;   // Remove bias term
        if (expReal < 0){   // If expReal is negative, then float number is lower than 1, which gets truncated to 0
            return 0;
        }if (expReal > 32){     // If expReal is larger than 32 bits, then we cannot shift the frac part enough times, in other words
            return 0x80000000u;  // we cannot represent the number, so out of range.
        }else if (expReal >= 23){   // frac part represents the numbers after the fraction (dot). Whenever expReal is larger
            frac = frac << (expReal - 23);  // than 23 we can get rid of the dot, and shift the frac to left.
        }else{      
            frac = frac >> (23 - expReal);  
        } abs = frac + 1;     // Normalization factor 
    if (sign){      // If number was initially negative, we change the sign
        abs = -abs;
    }
    return abs; 
    }   
}
