import java.util.*;


public class hanoi
{
    public static int N;
   
    public static Stack<Integer>[] tower = new Stack[4];

    public static void main(String[] args)
    {
    	    
     Scanner scan = new Scanner(System.in);
    
        tower[1] = new Stack<Integer>();
        tower[2] = new Stack<Integer>();
        tower[3] = new Stack<Integer>();
        
     System.out.println("Enter number of disks");
    	    
        int num = scan.nextInt();
        
        
        N = num;
        double start = System.nanoTime();

        toh(num);
        double end = System.nanoTime();
        double costtime = end - start;
        System.out.println(costtime/1000000 + "ms");
    }
  
    public static void toh(int n)
    {
        for (int d = n ; d > 0; d--)
            tower[1].push(d);
        
        		move(n, 1, 2, 3);
      
    }
   
    public static void move(int n, int a, int b, int c)
    {
        if (n > 0)
        {
            move(n-1, a, c, b);
            int d = tower[a].pop();
            tower[c].push(d);
            display(a,n,c);
            move(n-1, b, a, c);
        }
    }
    
    public static void display(int a, int n,int c)
    {
       System.out.println("Move disk " + n + " from tower " + a + " to " +" tower "+ c + "\n" );
       
    }
}
