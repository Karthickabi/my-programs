Collecting Candies
CodeVita
Krishna loves candies a lot, so whenever he gets them, he stores them so that he can eat them later whenever he wants to.
He has recently received N boxes of candies each containing Ci candies where Ci represents the total number of candies in the ith box. 
Krishna wants to store them in a single box. The only constraint is that he can choose any two boxes and store their joint contents in an empty box only.
Assume that there are infinite number of empty boxes available.
At a time he can pick up any two boxes for transferring and if both the boxes say contain X and Y number of candies respectively, then it takes him exactly X+Y seconds of time.
As he is to eager to collect all of them he has approached you to tell him the minimum time in which all the candies can be collected. 

Boundary Condition(s): 
1 <= T <= 100
1 <= N <= 10000 
1 <= Candies in each box <= 100009

Input Format: 
The first line contains T representing the number of test cases.
The next 2*T lines containing T test cases.
Each test case is comprised of two lines of input. 
The first line of input of a test case is the number of boxes N. 
The second line of input is N integers delimited by whitespace denoting number of candies in each box. 

Output Format: 
The first T lines contain the minimum time required (in seconds) for each of the test case.

Example Input/Output 1:
Input: 
1
4 
1 2 3 4 

Output:
19

Explanation: 4 boxes, each containing 1, 2, 3 and 4 candies respectively.
Adding 1 + 2 in a new box takes 3 seconds 
Adding 3 + 3 in a new box takes 6 seconds
Adding 4 + 6 in a new box takes 10 seconds 
Hence total time taken is 19 seconds. 
There could be other combinations also, but overall time does not go below 19 seconds. 

Example Input/Output 2: 
Input: 
1
5 
1 2 3 4 5

Output: 
33 

Explanation: 
5 boxes, each containing 1, 2, 3, 4 and 5 candies respectively.
Adding 1 + 2 in a new box takes 3 seconds
Adding 3 + 3 in a new box takes 6 seconds 
Adding 4 + 5 in a new box takes 9 seconds 
Adding 6 + 9 in a new box takes 15 seconds 
Hence total time taken is 33 seconds. 
There could be other combinations also,but overall time does not go below 33 seconds. 

Example Input/Output 3: 
Input: 
2 
3 
6 4 2 
4
10 50 20 34 

Output: 
18 
208

import java.util.*;
public class Hello {

    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int k=sc.nextInt();
        while(k-->0)
        {
            int n=sc.nextInt();
            PriorityQueue<Long> heap=new PriorityQueue<>();
            for(int i=0;i<n;i++)
            heap.add(sc.nextLong());
            long tot=0;
            for(int i=1;i<n;i++)
            {
                long fmin=heap.poll();
                long smin=heap.poll();
                tot+=fmin+smin;
                heap.add(fmin+smin);
            }
            System.out.println(tot);
        }
	}
}
