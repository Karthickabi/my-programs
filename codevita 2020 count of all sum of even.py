import math
a,b=map(int,input().split())
k=int(input())
o=(b-a+1)//2
e=(b-a+1)//2
if a&1 and b&1:
    o+=1
elif a&1==0 and b&1==0:
    e+=1
sum,o1,e1=0,k-1,1
sum+=(e**k)
if k&1==0:
    sum+=(o**k)
    o1=k-2
    e1=2
while o1>1 and e1<k:
    sum+=(o**o1)*(e**e1)*(math.comb(k,max(o1,e1)))
    o1-=2
    e1+=2
print(sum)
