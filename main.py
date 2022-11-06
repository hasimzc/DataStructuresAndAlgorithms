'''

                Problem definition
Given two strings s1 and s2, check if they're anagrams.

Two strings are anagrams if they're made of the same characters with the same frequencies.

'''
string1 = input()
string2 = input()
def anagrams(str1,str2):
    if len(str1) != len(str2):
        return False
    dictionary1 = {}
    dictionary2 = {}
    for s1 in str1:
        if s1 in dictionary1.keys():
            dictionary1[s1] += 1
        else:
            dictionary1[s1] = 1
    for s2 in str2:
        if s2 in dictionary2.keys():
            dictionary2[s2] += 1
        else:
            dictionary2[s2] = 1
    for key in dictionary1.keys():
            return False
    return True
print(anagrams(string1,string2))