

import java.util.*;
public class hanoi_iterative
{

    class Stack
    {
        int capacity;
        int top;
        int array[];
    }


    Stack createStack(int capacity)
    {
        Stack stack=new Stack();
        stack.capacity = capacity;
        stack.top = -1;
        stack.array = new int[capacity];
        return stack;
    }


    boolean isFull(Stack stack)
    {
        return (stack.top == stack.capacity - 1);
    }


    boolean isEmpty(Stack stack)
    {
        return (stack.top == -1);
    }


    void push(Stack stack,int item)
    {
        if(isFull(stack))
            return;
        stack.array[++stack.top] = item;
    }


    int pop(Stack stack)
    {
        if(isEmpty(stack))
            return Integer.MIN_VALUE;
        return stack.array[stack.top--];
    }


    void moveDisksBetweenTwoPoles(Stack src, Stack dest,
                                            char s, char d)
    {
        int pole1TopDisk = pop(src);
        int pole2TopDisk = pop(dest);


        if (pole1TopDisk == Integer.MIN_VALUE)
        {
            push(src, pole2TopDisk);
            moveDisk(d, s, pole2TopDisk);
        }

        else if (pole2TopDisk == Integer.MIN_VALUE)
        {
            push(dest, pole1TopDisk);
            moveDisk(s, d, pole1TopDisk);
        }

        else if (pole1TopDisk > pole2TopDisk)
        {
            push(src, pole1TopDisk);
            push(src, pole2TopDisk);
            moveDisk(d, s, pole2TopDisk);
        }

        else
        {
            push(dest, pole2TopDisk);
            push(dest, pole1TopDisk);
            moveDisk(s, d, pole1TopDisk);
        }
    }


    void moveDisk(char from, char to, int disk)
    {
        System.out.println("Move the disk "+disk +
                        "from "+from+" to "+to);
    }


    void tohIterative(int num_of_disks, Stack
                 src, Stack aux, Stack dest)
    {
        int i, total_num_of_moves;
        char s = '1', d = '2', a = '3';


        if (num_of_disks % 2 != 0)
        {
            char temp = d;
            d = a;
            a  = temp;
        }
        total_num_of_moves = (int) (Math.pow(2, num_of_disks) - 1);


        for (i = num_of_disks; i >= 1; i--)
            push(src, i);

        for (i = 1; i <= total_num_of_moves; i++)
        {
            if (i % 3 == 1)
              moveDisksBetweenTwoPoles(src, dest, s, d);

            else if (i % 3 == 2)
              moveDisksBetweenTwoPoles(src, aux, s, a);

            else if (i % 3 == 0)
              moveDisksBetweenTwoPoles(aux, dest, a, d);
        }
    }


    public static void main(String[] args)
    {
    	Scanner scan = new Scanner(System.in);
    	System.out.println("Enter number of disks");

        int num = scan.nextInt();


        int num_of_disks = num;
        double startTime = System.nanoTime();
        hanoi_iterative hanoi = new hanoi_iterative();
        Stack src, dest, aux;


        src = hanoi.createStack(num_of_disks);
        dest = hanoi.createStack(num_of_disks);
        aux = hanoi.createStack(num_of_disks);

        hanoi.tohIterative(num_of_disks, src, aux, dest);
        double endTime = System.nanoTime();
        double costTime = (endTime - startTime);
        System.out.println(costTime/1000000 + "ms");
    }
}
