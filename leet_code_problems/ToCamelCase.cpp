#include <stddef.h>
#include <string.h>
#include <iostream>

using namespace std;

char *get(char *s, char *a, int start, int end, int End)
{
    int i;
    cout << end << endl;

    for (i = start; i <= end; i++)
    a[i] = s[i];
    a[end+1] = ' ';
    a[end+2] = s[end];
     for(int j=end+1 ; j<End;j++)
          a[j+1] = s[j];
     
    return a;
}
char *solution(char *camelCase)
{

    char *b;
    int i = strlen(camelCase) + 1;

    b = (char *)malloc(i * sizeof(char));
    int index = 0;
    i--;
    for (int o = 0; o < i; o++)
    {
        if (camelCase[o] <= 90)
        {
            get(camelCase, b, index, o - 1, i);
            index = o;
        }
    }

    cout << endl<< "index = " << index << endl;

    return b;
}
int main()
{

    char a[12];
    gets(a);
    cout << solution(a);

    return 0;
}