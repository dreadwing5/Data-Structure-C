/* Problem Statement: Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
1) Only one disk can be moved at a time.
2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3) No disk may be placed on top of a smaller disk. */

#include <stdio.h>
int count = 1;
void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        printf("Step %d : Move disk from %d  to  %d \n", count, A, C);
        count++; //Display the steps to solve the problem
                 //1,2,3 represents the respective towers, u can only move 1 disc at a time
        TOH(n - 1, B, A, C);
        /*  Don't try to understand by seeing the code 
        Trust me you won't even konw what's even going on. 
        Draw a freaking tree and back track it . Don't try to overthink it! Btw we came to this 
        conclusion  through series of steps, check ur note for better understanding... */
    }
}

int main()
{

    TOH(3, 1, 2, 3); //Tower of Hinoi
    return 0;
}