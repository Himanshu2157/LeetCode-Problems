#include <string.h>
#include <stdlib.h>
#include <limits.h>

char* convert(char* s, int numRows) {

    if(numRows == 1) {
        return s;
    }

    char* str = (char*)malloc(strlen(s)+1);
    int index = 0;
    int gap_ptr = 2*(numRows-1);
    int n=strlen(s);
    int condition1, condition2;
    condition1 = condition2 = 1;

    

    for(int base = 0; base<numRows && base<n; base++){

        str[index] = s[base]; index++;

        while(index<n){

            if(base!=numRows-1 && gap_ptr-base<n){
                str[index] = s[gap_ptr-base]; index++;
                condition1 = 0;
            }

            if(index>=n) break;

            if(base!=0 && gap_ptr+base<n){
                str[index] = s[gap_ptr+base]; index++;
                condition2 = 0;
            }

            if (gap_ptr > INT_MAX - (2*(numRows-1)) || (condition1 && condition2)) break;

            condition1 = condition2 =1;
            gap_ptr += (2*(numRows-1));
        }
        gap_ptr=2*(numRows-1);
    }

    str[index] = '\0';

    return str;
}