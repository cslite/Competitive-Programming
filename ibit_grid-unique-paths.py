import bisect
class Solution:
	# @param A : list of integers
	# @param B : integer
	# @param C : integer
	# @return an integer
	
	def mysolve(self,A,B,C,zerosAllowed):
	    c = int(C)
	    x = 1
	    i=0
	    while i<len(C) and C[i] == '0':
	        x *= 10
	        i += 1
	    c *= x
	    if B==0:
	        return 1
        leastnum = 10**(B-1)
        if c < leastnum:
            return 0
        maxnum = (leastnum*10) - 1
        if c > maxnum:
            res = 1
            if zerosAllowed or A[0] != 0:
                res *= len(A)
            elif A[0] == 0:
                res *= len(A)-1
            for i in range(1,B):
                res *= len(A)
            return res
        else:
            idx = bisect.bisect_left(A,int(C[0]))
            # idx = bisect.bisect_left(A,(C//leastnum))
            num = idx
            res = 0
            if zerosAllowed or A[0] != 0:
                res += num*(self.mysolve(A,B-1,C,True))
            elif A[0] == 0:
                res += (num-1)*(self.mysolve(A,B-1,C,True))
            c2 = C[1:]
            # c2 = C - ((C//leastnum)*leastnum)
            if idx<len(A) and A[idx] == int(C[0]):
                if B-1 > 0:
                    res += self.mysolve(A,B-1,c2,True)
            return res
                

	
	def solve(self, A, B, C):
	    if len(A) == 0:
	        return 0
	    if B==1:
	        return self.mysolve(A,B,str(C),True)
	    else:
	        return self.mysolve(A,B,str(C),False)
        