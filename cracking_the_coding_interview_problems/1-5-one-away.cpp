/*
 * Cracking the coding interview edition 6
 * Problem 1.5
 * Three possible types of edit possible on a string
 * Insert a char, delete a char or replace a char
 * Write a function to check if two given string are one ( or zero ) edit(s) away
 */


bool oneEditReplace( const std::string & src, const std::string & dst )
{
    int mismatch = 0;
    for ( size_t i = 0; i < src.length(); ++i )
    {
        if ( src[i] != dst[i] )
        {
            ++mismatch;
        }
    }
    return (mismatch <= 1);
}

bool oneEditInsert( const std::string & src, const std::string & dst )
{
    

}



bool oneEditAway( const std::string & src, const std::string & dst )
{
    int srcLen = src.length();
    int dstLen = dst.length();
    if ( srcLen == dstLen )
    {
        return oneEditReplace(src, dst);
    }
    else if ( srcLen + 1 == dstLen )
    {
        return oneEditInsert(src, dst);
    }
    else if ( srcLen - 1 == dstLen )
    {
        return oneEditRemove(src, dst);
    }
    return false;
}
