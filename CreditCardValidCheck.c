
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long long int credit_num;
    printf("Please enter the credit card number: \n");
    scanf("%lld",&credit_num);
    // 13 15 16
    // using a local memory string and checking it's length using len functions on the str
    char num[256];
    int odd = 0;
    int even = 0;
    int seven = 0;
    char eva[256];
    long long temp_num = credit_num;
    int initials = 0;

    sprintf(num, "%lli", credit_num);
    int bruh = strlen(num);
    int con = 0;

    // applying the formula
    // get the even numbers and multiply them by 2 and find the sum which we add to the odd number's
    // sum.
    while (con == 0)
    {
        for (int i = 1; i < bruh + 2; i++)
        {
            int digit = temp_num % 10;
            temp_num = temp_num / 10;
            if (i < bruh - 1)
            {
                initials = temp_num;
            }
            if (i % 2 != 0)
            {
                odd = odd + digit;
            }
            else if (i % 2 == 0)
            {

                even = (digit * 2);

                sprintf(eva, "%i", even);
                int lol = strlen(eva);

                for (int k = lol + 1; k > 0; k--)
                {
                    int even_digit = even % 10;
                    even = even / 10;
                    seven = seven + even_digit;
                }
            }
        }
        con = 1;
    }

    int checksum = seven + odd;
    int verify = checksum % 10;

    int vfcon = 0;
    if (verify == 0)
    {
        vfcon = 1;
    }

    if ((bruh == 15) && (initials == 34 || initials == 37) && (vfcon == 1))
    {
        printf("AMEX\n");
    }
    else if ((bruh == 16) && (initials > 50 && initials < 56) && (vfcon == 1))
    {
        printf("MASTERCARD\n");
    }
    else if ((bruh == 13 || bruh == 16) && (initials > 39 && initials < 50) && (vfcon == 1))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
