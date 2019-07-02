"""
 Cracking the coding interview, edition 6
 Problem 1.1
 Write an algorithm to determine whether a string has unique characters or not
 Can we do it without using additional data structures?
"""

def is_unique(string):
    """ Checks if string has unique characters.
    Args:
        string: the string which needs to be checked for unique characters.
        This string only contains a-z lowercase (26 chars).
        'check' is 32-bit integer, 1 bit per alphabet.
    Returns:
        True if string has unique characters False otherwise

    """
    check = 0
    for char in string:
        c = ord(char) - ord('a')
        if check & (1 << c) :
            return False
        check |= (1 << c)
    return True

def is_unique2(string):
    """ Checks if string has unique characters
    Args:
        string: ASCII string which needs to be checked for unique characters
    Returns:
        True if string has unique characters False otherwise.
    """
    check = [0 for _ in range(8)]
    for char in string:
        v = ord(char)
        # find int bucket which will represent this char
        idx = int(v / 32)
        # find the bit in this int bucket which will represent this char
        shift = v % 32

        if check[idx] & (1 << shift):
            return False
        check[idx] |= (1 << shift)

    return True


if __name__ == "__main__":
    str1 = "hello"
    print(F"'{str1}' has unique characters? :", is_unique(str1))
    str2 = "norepat"
    print(F"'{str2}' has unique characters? :", is_unique2(str2))