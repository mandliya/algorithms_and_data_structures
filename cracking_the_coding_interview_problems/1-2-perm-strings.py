"""
Cracking the coding interview edition 6
Given two strings, determine if one is permutation of other.
"""

from collections import Counter


def check_permutation(str1, str2):
    """Checks if the two strings are permutations of each other
    Args:
        str1 : first string
        str2 : second string
    Returns:
        True if strings are permutations of each other
    """
    # if strings are different in size, they can't be permutation of each other.
    if len(str1) != len(str2):
        return False
    
    # count the occurance of each char of str1, and match it with str2
    counter = Counter()
    for c in str1:
        counter[c] += 1
    for c in str2:
        if counter[c] == 0:
            return False
        counter[c] -= 1
    return True


if __name__ == "__main__":
    str1 = 'listen'
    str2 = 'silent'
    print(F"'{str1}' is permutation of '{str2}' : ", check_permutation(str1, str2))

    str1 = 'hello'
    str2 = 'world'
    print(F"'{str1}' is permutation of '{str2}' : ", check_permutation(str1, str2))
