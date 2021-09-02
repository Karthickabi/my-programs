There are N dogs in a pet store. The pet store wants to keep the N dogs in cages.
There can be two dogs in each cage. A dog can be eitheir passive or aggressive.
If the dog is passive, it can be clubed with another passive dog.
If the dog is aggressive, it has to be alone in a cage.
The program must print the number ways W to put the N dogs in the cages as the output.

Note: The number of cages in the pet store is sufficient to keep N dogs according to the given condition.

Example Input/Output 1:
Input:
2
Output:
2

Example Input/Output 2:
Input:
3
Output:
4

Example Input/Output 3:
Input: 
10
Output: 
9496

n=int(input())
a=[1,2]
for i in range(2,n):
  a.append(a[i-1]+a[i-2]*i)
print(a[n-1])
