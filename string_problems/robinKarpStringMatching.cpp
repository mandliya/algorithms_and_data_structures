/*
 * Given a string pattern(P) and large Text string (T), Write a function search( P , T) which provide all the occurrences of P in T.
 * example : T => "AABAACAADAABAAABAA".
 *           P => "AABA"
 * Output : 0, 9, 13 ( all indices of T where pattern string P is starts to match.
 *
 * Approach:
 *         Lets say size of T  ==> N
 *         Size of P ==> M.
 *         Lets have a hash function --> hash.
 *         Step 1 :We will calculate hash of Pattern P, lets say it is p
 *         Step 2 : Then we will calculate hash of text portion from T[0-->M-1]. lets say  t(0) 
 *         Step 3: if ( p == t(0) ) if they match, add it to list of occurrences.
 *         Step 4: Go back to step 2, and calculate t(1) i.e hash of T[1-->M] using t(0) in O(1).
 *
 *         The question remains, how do we calculate t(1) from t(0) in O(1), we do it using Horner's rule
 *         H[m] = X[m]+ 10 (X[m-1] + 10(X[m-2]+……10(X[2] + 10 X[1]….))) —-> The 10 is the number of characters
 *         
 *         By Induction, we can calculate
 *         t(s+1) = 10 ( t(s) - 10^(m-1) * T[s] ) + T[s+m+1]
 *
 *         so for example 
 *         T = "123456", and m = 3
 *         T(0) = 123
 *         T(1) = 10 * ( 123 - 100 * 1) + 4 = 234
 *
 *         So in our case number of character can be 256 
 *         There t(s+1) = 256 ( t(s) - 256 ^ (m-1) * T[s] ) + T[s+m+1]
 *
 *         alphabet = 256;
 *         In our program we will precalculate 256 ^ m-1;
 *         h = pow(256, m-1)
 *
 */


#include<iostream>
#include<vector>


//alphabet is total characters in alphabet.
const int alphabet = 256;
//a large prime number
const int q = 101;


std::vector<int> search(const std::string pattern, const  std::string text)
{
    int M = pattern.size();
    int N = text.size();
    long h = 1;                          //hash val
    int p = 0;                          //hash value of pattern;
    int t = 0;                          //hash value of current text substring of size m;
    std::vector<int> indices;       // store all the indices of text where pattern matched.
    
    //hash value - pow( alphabet, m-1) % q;
    for ( int i = 0; i < M - 1; ++i ) {
        h = (alphabet * h) % q;
    }

    //initial hash values of pattern  and text substring
    for ( int i = 0; i < M ; ++i ) {
        p = ( alphabet * p + pattern[i] ) % q;
        t = ( alphabet * t + text[i] ) % q;
    }

    //Slide the pattern over text
    for ( int i = 0; i <= N - M; ++i ) {
            
        int j = 0;
        //if hash matches, check the chars one by one.
        if ( p == t ) {
            for (j = 0; j < M ; ++j ) {
                if ( pattern[j] != text[i+j] ) {
                    break;
                }
            }
            //pattern and text portion match
            if ( j == M ) {
                indices.push_back(i);
            }
        } else {
            //calculate the next t
            
            t = ( alphabet * ( t - text[i] * h) + text[i+M] ) % q;
            // in case current t is negative
            if ( t < 0 ) {
                t = ( t + q);
            }
        }

    }
    return indices;

}

void printIndices(std::vector<int> indices,
                  const std::string pattern,
                  const std::string text)
{
    if ( indices.size() == 0 ) {
        std::cout << "\"" <<  pattern << "\" does not occur in \"" << text << "\"" << std::endl;
    } else {
        std::cout << "\"" <<  pattern << "\" occurs in \"" << text << "\" at following position(s):";
        for ( auto i : indices ) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::string txt1("AABAACAADAABAAABAA");
    std::string pat1("AABA");
    std::string txt2("Hello World Hello World , All is great in World");
    std::string pat2("World");
    std::string txt3("GEEKS FOR GEEKS");
    std::string pat3("GEEKS");

    std::vector<int> indices1 = search(pat1, txt1);
    printIndices(indices1, pat1, txt1);
    std::vector<int> indices2 = search(pat2, txt2);
    printIndices(indices2, pat2, txt2);
    std::vector<int> indices3 = search(pat3, txt3);
    printIndices(indices3, pat3, txt3);
    return 0;
}
