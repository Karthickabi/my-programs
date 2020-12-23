/*There are a N students in a high school class. For simplicity, the students are named A, B, C, . . . (up to the Nth letter of the alphabet).
No two students have exactly the same height.The Principal of the school wants to organize a class photograph where the students are arranged in descending order of heights. 
The class teacher has been asked to list the students in descending order of heights to send to the photographer.The teacher does not know the heights of the various students.
However, there are a set of photographs, which between them have all the students in that class. 
From each of the photographs, the teacher obtained a list of students in descending height order and needs to combine them into one list of students in descending height order.
It is possible that the photographs do not fully determine the ordering in the list. 
In this case, as it is vacation time, the teacher needs to write to some of the students to send her their exact height, so that she can create the complete list.
The objective is to write a program that can list the students to whom she must write to determine their heights.
Constraints
N<=26, K<=10
Input Format
Line 1 contains two comma separated positive integers, N and K. N gives the number of students in the class (A,B,C, . . .), and K is the number of photographs
The next K lines each contain a comma separated list of the students in descending order from the corresponding photograph.
Output
Output should be one comma separated list (in alphabetical order) of students whose height must be known to create the ordered list. 
If it is not necessary to write to any student, the output should be N/A
Test Case

TestCase 1
8,3
D,C,E,F,G,H
C,A,E
D,C,B,E

Output
A,B

TestCase 2
8,3
D,C,E,F,G,H
C,A,B,E
D,B

Output
N/A

Explanation
Example 1
Input
8,3
D,C,E,F,G,H
C,A,B,E
D,B

Output
N/A

Explanation
N is 8 and K is 3, and so there are 8 students and 3 photographs. As the students are named the first N letters of the alphabet, the students are A, B, C, D, E, F, G, H.
The first photograph shows the ordering as D, C, E, F, G, H, that is D is taller than C who is taller than E and so on. 
The second photograph shows that C is taller than A, who is taller than B who is taller than E. The third photograph shows that D is taller than B.
From photograph 1, E, F, G and H are all shorter than C, and are in that order. From photograph 2, A and B are taller than E and in that order. 
Hence A, B, C and D are all taller than E, F, G and H. Hence the last four in the final ordered list must be E, F, G, H in that order.
From the first photograph, D is taller than C, and from the second photograph, C is taller than A who is taller than B. 
Hence the order of the first four is D, C, A, B. The third photograph confirms this order.
Hence the full list is D, C, A, B, E, F, G, H. The full order can be determined without writing to any student to get their height.
Hence the output is N/A.

Example 2
Input
8,3
D,C,E,F,G,H
C,A,E
D,C,B,E
Output
A,B
Explanation
N is 8 and K is 3. The students are A, B, C, D, E, F, G, H (the first N letters of the alphabet)
As before, from photographs 1, 2 and 3, we can determine that A, B, C and D are taller than E, F, G, H, and that E, F, G, H are the last four in the ordered list.
From the first photograph, D is taller than C, and from the second photograph, C is taller than A. From the third photograph, C is taller than B. 
The possible orders of the first four could be D, C, A, B or D, C, B, A. No information is present in any of the photographs which says which order is correct. 
Hence the teacher must write to both B and A to determine their heights so as to establish the correct order. 
The output must be sorted in alphabetic order, and hence the output is A,B.

*/#include <stdio.h>
void h(char a,char b,char t[][2],int i)
{if(b==0)
return;
if(t[a-'A'][i]==0)
t[a-'A'][i]=b;
else
{char f=t[a-'A'][i];
while(f!=b&&f!=0)
f=t[f-'A'][i];
if(f==0)
t[a-'A'][i]=b;}}
int main()
{int r,c,k,p=0;
scanf("%d,%d",&r,&c);
char a[r][2],t[r+1],f,te;
memset(a,0,r*3);
for(int i=0;i<c-1;i++)
{k=0;
while(scanf(" %c%c ",&t[k],&te)==2)
{if(k>0)
h(t[k-1],t[k],a,1);
if(k>1)
h(t[k-1],t[k-2],a,0);
if(te=='\r'||te=='\n')
break;
k++;}h(t[k],t[k-1],a,0);}
k=0;
while(scanf("%c,",&t[k])==1)
{if(k>0)
h(t[k-1],t[k],a,1);
if(k>1)
h(t[k-1],t[k-2],a,0);
k++;}
h(t[k-1],t[k-2],a,0);
for(int j=0;j<r;j++)
printf("%c,%c,%c\n",a[j][0],'A'+j,a[j][1]);
printf("\n");}
