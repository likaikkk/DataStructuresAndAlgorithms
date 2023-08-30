#include<iostream>
using namespace std;

//Function: swap_m
//Swap the position of two characters(if not the same)
//Parameter:
//        a: pointer to the first character
//        b: pointer to the second character
void swap_m(char* a, char* b) {//swap a for b
    if (*a != *b) {
        char temp = *a;
        *a = *b;
        *b = temp;
    }
    else if (*a == *b) {
        cout << "Identical swap occurs" << endl;
    }
}

//Function:permutation
//Generate a full permutation of a character array
//parameter:
//        per: pointer to the character array representing the permutation
//        b: pointer to the current character position in the permutation
void permutation(char* per, char* begin) {
    if (per == NULL)return;//If the input is NULL,return immediately
    if (*begin == '\0')//If the current character is the null terminator,the permutation is complete
        cout << per << endl;//Print the generated permutation
    else {
        for (char* pCh = begin;*pCh != '\0';pCh++) {
            if (pCh != begin)
                swap_m(pCh, begin);//Swap the curent character with the character at the 'begin' position
            permutation(per, (begin + 1));//Recursively generate permutation for the remaining character
            if (pCh != begin)
                swap_m(pCh, begin);//Swap the characters back to the original position after recursion
        }
    }
}

int main() {
    char str[] = "abc";
    
    permutation(str, str);

    return 0;
}

