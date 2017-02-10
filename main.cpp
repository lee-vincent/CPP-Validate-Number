//
//  main.cpp
//  week9
//
//  Created by Vincent Lee on 5/31/15.
//  Copyright (c) 2015 10k Bulbs. All rights reserved.
//

#include <iostream>
#include <string>


bool stringIsInt(std::string num) {

    //make sure there are characters to process
    if(num.length() <= 0) return false;
    
    
    //find the last non-whitespace character position
    int lastNonWSChar = num.length() - 1;
    while(num[lastNonWSChar] == ' ' && lastNonWSChar >= 0) lastNonWSChar--;


    //skip leading whitespace
    int index = 0;
    while(num[index] == ' ') index++;
    
   
    //is everything whitespace?
    if(index == num.length()) {
        return false;
    }
    
    
    //process the first non-whitespace character
    char c1 = num[index];
    bool usedSign = false;
    
    if(c1 == '-' || c1 == '+') {
        usedSign = true;
    } else if (!(c1 > '0' && c1 < '9')) {
        return false;
    }

    
    //if sign used, skip whitespace to first number
    if(usedSign) {
        index++;
        while(num[index] == ' ') index++;
        
        //was the rest whitespace?
        if(index == num.length()) {
            return false;
        }
    
    }


    //process remaining characters
    while(index <= lastNonWSChar) {
        char ch = num[index];
        if(!(ch > '0' && ch < '9')) return false;
        index++;
    }

return true;
}



bool stringIsFloat(std::string num) {
    
    //make sure there are characters to process
    if(num.length() <= 0) return false;
    
    
    //find the last non-whitespace character position
    int lastNonWSChar = num.length() - 1;
    while(num[lastNonWSChar] == ' ' && lastNonWSChar >= 0) lastNonWSChar--;
    
    //false if terminated by decimal point
    if(num[lastNonWSChar] == '.') return false;
    
    
    //skip leading whitespace
    int index = 0;
    while(num[index] == ' ') index++;
    
    
    //is everything whitespace?
    if(index == num.length()) {
        return false;
    }
    
    
    //process the first non-whitespace character
    char c1 = num[index];
    bool usedSign = false;
    bool usedDecimalPoint = false;
    
    
    if(c1 == '-' || c1 == '+') {
        usedSign = true;
    } else if (c1 == '.') {
        usedDecimalPoint = true;
        std::cout << "usedDecimalPoint " << usedDecimalPoint << std::endl;
    } else if (!(c1 > '0' && c1 < '9')) {
        return false;
    }
    
    index++;
    
    //if sign used, skip whitespace to first number
    if(usedSign) {
        while(num[index] == ' ') index++;
        
        //was the rest whitespace?
        if(index == num.length()) {
            return false;
        }
        
    }
    
    
    
    
    
    //process remaining characters
    while(index <= lastNonWSChar) {
        char ch = num[index];
        
        if (ch == '.') {
            if(!usedDecimalPoint) {
                usedDecimalPoint = true;
            } else {
                return false;
            }
        } else if(!(ch > '0' && ch < '9')) {
        
            return false;
        }
        
        index++;
    }
    
    return true;
}


//
//int main(int argc, const char * argv[]) {
//
//    
//    std::cout << stringIsFloat("  -1. ") << std::endl;
//    return 0;
//}







