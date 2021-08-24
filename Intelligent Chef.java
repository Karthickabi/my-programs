Intelligent Chef
There are N persons in a hotel.
Each person has their own preferences for food. The hotel chef wants to prepare the food items as minimum as possible.
The program must accept the food preferences of each person as the input.
The program must print the minimum number of food items that must be prepared to serve everyone in the hotel. 
Note: Each person eats only one food item but has many options.

Boundary Condition(s): 
1 <= N <= 10^4 
1 <= Length of the name of each food item <= 50 

Input Format: 
The first line contains N.
The next N lines, each containing the string value(s) representing the preferences of food items of a person.

Output Format:
The first line contains the minimum number of food items that must be prepared to serve everyone in the hotel. 

Example Input/Output 1: 
Input: 
5 
Dosa Poori
Idli Poori
Idli Poori 
Idli Dosa
Poori 

Output: 
2
Explanation: 
Here N = 5 representing the 5 persons in the hotel. 
At least 2 food items (Idli & Poori) must be prepared to serve everyone in the hotel. 

Example Input/Output 2:
Input: 
10 
Chapati Idli Pongal Poori Dosa
Poori Dosa Chapati
Idli Dosa Poori 
Pongal
Dosa Pongal Poori Chapati 
Idli Pongal Poori 
Idli Pongal Chapati Dosa 
Dosa Chapati
Chapati Idli Pongal Poori Dosa 
Chapati 

Output: 
3

import java.util.*;
class food implements Comparable<food>
{
    String name;
    List<Integer>cus;
    @Override
    public int compareTo(food other)
    {
        return this.cus.size()-other.cus.size();
    }
}
public class Hello 
{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();sc.nextLine();
        Map<String,food> foodm=new HashMap<>();
        List<Integer> rem=new ArrayList<>();
        for(int i=1;i<=n;i++)
        {
            rem.add(i);
            String pre[]=sc.nextLine().split("\\s+");
            for(String j:pre)
            {
                if(!foodm.containsKey(j))
                {
                    food f=new food();
                    f.name=j;
                    f.cus=new ArrayList<>();
                    foodm.put(j,f);
                }
                foodm.get(j).cus.add(i);
            }
        }
        int co=0;
        while(!rem.isEmpty())
        {
            List<food> it=new ArrayList<>(foodm.values());
            Collections.sort(it,Collections.reverseOrder());
            food most=it.get(0);
            co++;
            foodm.remove(most.name);
            rem.removeAll(most.cus);
            for(String i:foodm.keySet())
            {
                foodm.get(i).cus.removeAll(most.cus);
                
            }
        }
        System.out.print(co);
	}
}
