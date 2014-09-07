#include <iostream>

using namespace std;

void reverseString(char *str);

int main()
{
    char str[] = "abcde";

    reverseString(str);

    cout << str << endl;

    return 0;
}

void reverseString(char *str)
{
    if (!str || str == '\0') return;

    char *p, *q;

    p = str;
    q = str;

    while(*(q+1) != '\0') q++;

    for (; p < q; p++, q--)
    {
        char temp = *p;
        *p = *q;
        *q = temp;
    }
}
