// https : // practice.geeksforgeeks.org/problems/reverse-a-string/0/#

string
reverseWord(string str)
{

    int s = 0;
    int e = str.length() - 1;

    while (s <= e)
    {
        swap(str[s], str[e]);
        s++;
        e--;
    }

    return str;
}