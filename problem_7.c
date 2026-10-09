#include <math.h>
#include <limits.h>

int reverse(int x){
    if(x>=INT_MIN && x<=INT_MAX){

        int count_digits = 0;
        int copy_x = x;

        while(copy_x/10!=0){
            count_digits++;
            copy_x/=10;
        }
        
        int power = count_digits;
        int temp, reverse = 0;

        while(power>=0){

            if((x%10)*pow(10,power)<INT_MIN || (x%10)*pow(10,power)>INT_MAX){
                return 0;
            }

            temp = (x%10)*pow(10,power);

            if ((temp > 0 && reverse > INT_MAX - temp) || (temp < 0 && reverse < INT_MIN - temp)) {
                return 0;
            }
            
            reverse+=temp;
            power--;
            x/=10;
        }
        
        return reverse;

    }
    else{
        return 0;
    }
}
