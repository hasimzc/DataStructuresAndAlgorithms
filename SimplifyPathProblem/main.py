'''
here is the link of the problem https://leetcode.com/problems/simplify-path/submissions/
'''

class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        path.replace('//','/')
        path = path.split('/')
        for p in path:
            if p == '.' or p=='':
                continue
            elif p == '..':
                if len(stack) >0 :
                    stack.pop(-1)
                else:
                    continue
            else:
                stack.append(p)
        string = '/'.join(stack)
        string = '/' + string
        return string
