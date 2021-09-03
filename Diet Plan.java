Diet Plan
CodeVita
Dwayne Johnson is planning to follow a diet suggested by his Nutritionist. The Nutritionist prescribed him the total protein, carbohydrates and fats, he should take daily. 
Dwayne Johnson searches on an online food store and makes a list of protein, carbohydrates and fats contained in a single unit of various food items.
His target is to have the maximum protein, carbohydrates and fats in his diet without exceeding the prescribed limit.
He also wants to have as much diverse food items as much as possible. That is, he does not want to have many units of one food item and 0 of others. 
Multiple combinations of 'units of food items' are possible to achieve the target.
Mathematically speaking, diversity is more if the difference between the number of units of food item chosen the most and the number of units of another
food item chosen the least, is as small as possible. To solve this problem, he uses maximum possible number of units of all the items so that total amount 
of protein, carbohydrates and fats is not more than prescribed limit.

For example - if total nutrition required is 100P, 130C and 130F (where P is Protein, C is Carbohydrates and F is Fats) and 2 different food items, viz.
Item A and Item B, have following amount of nutrition: Item A - 10P, 20C, 30F Item B - 20P, 30C, 20F then, he can have (maximum possible) 
2 units of all the items as having 3 units will exceed the prescribed amount of Carbohydrates and fats. Next, he chooses food items to fulfill the remaining nutrients. 
He chooses one more units of maximum number of food items.
He continues this process till he cannot add a unit of any food item to his diet without exceeding the prescribed limit.
In this example, he can choose one more unit of item B or one more unit of item A.
In case he has two sets of food items then the priority is given to fulfill the requirements of Protein, Carbohydrates, and Fats in that order.
So he chooses item B. You will be provided the maximum nutrients required and the nutrients available in various food items.
You need to find the amount of nutrients for which there is a shortfall as compared to the prescription, after making his selection using the process described above.
In the example he still needs 20P, 0C, 10F to achieve his target.

Note:
- Amount of P, C, F in two food items will not be same. 
- P, C, F values in input can be in any order.
- Output should be in order - P, C, F. 

Boundary Condition(s): 
1 <= Number of Food Items <= 10
Maximum amount of Nutrients is less than 1500 i.e. x + y + z <= 1500 

Input Format:
The first line contains the maximum limit of nutrients in the following format. 
xP yC zF, where x, y and z are integers.
The second line contains nutrient composition of different food items separated by pipe (|).

Output Format: 
The first line contains the shortfall for each nutrient type, fulfilled separated by a space.
E.g. If the output is 10P, 20C, 30F, then print "10 20 30" (without quotes). 

Example Input/Output 1:
Input: 
100P 130C 130F 
10P 20C 30F|20P 30C 20F 

Output: 
20 0 10

Explanation:
Having 2 units of item A and 3 units of item B provides - 2 * [10P 20C 30F] + 3 * [20P 30C 20F] = 100P, 130C, 120F.
This is the best combination that can reduce the shortfall [20P, 0C, 10F] without exceeding his prescription. 
In contrast, if 3 units of A and 2 units of B are chosen then 3 * [10P 20C 30F] + 2 * [20P 30C 20F] = 70P, 120C, 130F produces a shortfall of [30P, 10C, 0F]. 
However, since protein shortfall in this case is more than the previous combination, this is not the right combination to follow.

Example Input/Output 2:
Input: 
130P 120C 110F 
4P 9C 2F|4P 3C 2F|7P 1C 3F 

Output: 
2 4 50 

Explanation: 
Having 9 units of item A, 9 units of item B and 8 units of Item C provides - 9 * [4P 9C 2F] + 9 * [4P 3C 2F] + 8 * [7P 1C 3F] = 108P, 116C, 60F. 
This is the best combination that can reduce the shortfall [2P, 4C, 50F] without exceeding his prescription.

import java.util.*;
class combo implements Comparable<combo>
{
    int p,c,f;
    public void add(combo item)
    {
        this.p+=item.p;
        this.c+=item.c;
        this.f+=item.f;
    }
    @Override
    public int compareTo(combo other)
    {
        if(this.p==other.p)
        {
            if(this.c==other.c)
            {
                return this.f-other.f;
            }
            return this.c-other.c;
        }
        return this.p-other.p;
    }
}
public class Hello {

    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        combo max=parsecombo(sc.nextLine().trim());
        String itemdata[]=sc.nextLine().trim().split("\\|");
        combo groupsum=new combo();
        List<combo> items=new ArrayList<>(); 
        for(String i:itemdata)
        {
            combo item=parsecombo(i);
            items.add(item);
            groupsum.add(item);
        }
        combo curr=new combo();
        while(canAdd(max,curr,groupsum))
        {
            curr.add(groupsum);
        }
        int n=items.size();
        while(true)
        {
            List<combo> comboThat=new ArrayList<>();
            for(int i=1;i<(1<<n);i++)
            {
                combo currcom=new combo();
                for(int j=0;j<n;j++)
                {
                    if((i&(1<<j))>0)
                    {
                        currcom.add(items.get(j));
                    }
                }
                if(canAdd(max,curr,currcom))
                {
                    comboThat.add(currcom);
                }
            }
            if(comboThat.isEmpty())
            break;
            Collections.sort(comboThat,Collections.reverseOrder());
            curr.add(comboThat.get(0));
        }
        System.out.print((max.p-curr.p)+" "+(max.c-curr.c)+" "+(max.f-curr.f));
	}
	private static combo parsecombo(String i)
	{
	    combo c=new combo();
	    for(String k:i.split(" "))
	    {
	        parse(c,k);
	    }
	    return c;
	}
	private static void parse(combo c,String i)
	{
	    char item=Character.toUpperCase(i.charAt(i.length()-1));
	    int q=Integer.parseInt(i.substring(0,i.length()-1));
	    switch(item)
	    {
	        case 'P':c.p=q;break;
	        case 'F':c.f=q;break;
	        case 'C':c.c=q;break;
	    }
	}
	private static boolean canAdd(combo max,combo curr,combo item)
	{
	    return curr.p+item.p<=max.p&&curr.f+item.f<=max.f&&
	    curr.c+item.c<=max.c;
	}
}
