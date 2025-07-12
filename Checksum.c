#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binary_sum(char s1[], char s2[], char sum[], int len)
{
    int carry = 0, i;
    for (i = len - 1; i >= 0; i--)
    {
        int total = (s1[i] - '0') + (s2[i] - '0') + carry;
        sum[i] = (total % 2) + '0';
        carry = total / 2;
    }
    printf("Sum of String with carry: %d %s \n", carry, sum);
    while (carry)
    {
        for (i = len - 1; i >= 0 && carry; i--)
        {
            carry = (sum[i] == '1');
            sum[i] = carry ? '0' : '1';
        }
        printf("Sum of String with carry : %d %s \n", carry, sum);
    }
}

void complement_1s(char str[])
{
    for (int i = 0; str[i]; i++)
        str[i] = (str[i] == '0') ? '1' : '0';
    printf("1s Complement is: %s\n", str);
}

void receiver(char s1[], char s2[], char sum[], int len)
{
    char check_sum[20] = {0}, final_sum[30] = {0};
    printf("In Receiver Side \n");
    binary_sum(s1, s2, check_sum, len);
    printf("Sum of 1st two frame=%s\n", check_sum);
    binary_sum(check_sum, sum, final_sum, len);
    printf("Sum of all 3 frames=%s \n", final_sum);
    complement_1s(final_sum);
    printf("Result =%s \n", final_sum);
}

int main()
{
    char a[20], b[20], result[20] = {0};
    printf("Enter 1st string : ");
    scanf("%s", a);
    printf("Enter 2nd string : ");
    scanf("%s", b);

    int len = strlen(a);
    printf("\n In sender side\n %s %s\n", a, b);
    binary_sum(a, b, result, len);
    complement_1s(result);

    receiver(a, b, result, len);
    return 0;
}