def findCount(a,si,ei):
    if ei-si==0:
        return 1
    rc=min(a[si:ei+1])
    for i in range(si,ei+1):
        a[i]-=rc
    sti,eti=-1,-1
    for i in range(si,ei+1):
        if a[i]>0 and sti==-1:
            sti=i
        if a[i]==0 and sti!=-1 and eti==-1:
            eti=i-1
            rc+=findCount(a,sti,eti)
            sti,eti=-1,-1
    if sti!=-1 and eti==-1:
        rc+=findCount(a,sti,ei)
    return min(rc,ei-si+1)
n=input()
a=map(int,raw_input().strip().split())
print (min(n,findCount(a,0,n-1)))
