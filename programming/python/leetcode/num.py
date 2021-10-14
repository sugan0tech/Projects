#User function Template for python3

class Solution:
    def findTwoElement( self,arr, n):
        big = max(arr)
        missing = 0
        repeat_num = 0
        for i in range(1, big + 1):
            if i not in arr:
                missing = i

        i_index = 0
        j_index = 0
        for i in arr:
            for j in arr:
                if (i == j)and(i_index != j_index):
                    repeat_num = i
                j_index += 1
            i_index += 1
        st = [repeat_num, missing]
        return st

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 

    tc=int(input())
    while tc > 0:
        n=int(input())
        arr=list(map(int, input().strip().split()))
        ob = Solution()
        ans=ob.findTwoElement(arr, n)
        print(str(ans[0])+" "+str(ans[1]))
        tc=tc-1
# } Driver Code Ends