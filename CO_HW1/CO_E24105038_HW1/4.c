// description: matrix muliply without for loop
#include<stdio.h>

int main(){ 

    int i=0;
    int h[9]={0}, x[3]={0}, y[3]={0}; 

    FILE *input = fopen("../input/4.txt","r");

    for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
    fclose(input);

    int *p_x = &x[0] ;
    int *p_h = &h[0] ;
    int *p_y = &y[0] ;

    asm volatile(
                "li %[i], 0\n\t"  //initialize
                "li t4, 0 \n\t"   
                "li t5, 3 \n\t"
                "li t6, 12\n\t"
                "blt %[i], t5, outer_loop\n\t"   //jump inside the loop
                "j end\n\t"   //jump to end
                "outer_loop:\n\t"    //outer loop
                "li t4, 0\n\t"  //initialize t4=0
                "inner_loop:\n\t"    //inner loop
                "lw t0, 0(%[p_h])\n\t" //load 
                "lw t1, 0(%[p_x])\n\t" //load 
                "mul t2, t1, t0\n\t"    //mul 
                "lw t3, 0(%[p_y])\n\t" //load 
                "add t3, t3, t2\n\t" //add
                "sw t3, 0(%[p_y])\n\t"     //store
                "addi %[p_h], %[p_h], 4\n\t"    
                "addi %[p_x], %[p_x], 4\n\t"    
                "addi t4, t4, 1\n\t"    //increment 
                "blt t4, t5, inner_loop\n\t"    //if t4<t5 branch to inner loop
                "addi %[i], %[i], 1\n\t"    //increment  
                "addi %[p_y], %[p_y], 4\n\t"   
                "sub %[p_x], %[p_x], t6\n\t"    //reset the x address to x[0]
                "blt %[i], t5, outer_loop\n\t"    //if i<t5, branch to outer loop   
                "end:\n\t" 
                : [i] "+r" (i), [p_y] "+r" (p_y),[p_h] "+r" (p_h), [p_x] "+r" (p_x)
                : 
                : "t0", "t1", "t2", "t3", "t4", "t5","t6"  
    );

    p_y = &y[0];
    for(i = 0; i<3; i++)
        printf("%d \n", *p_y++);

    return(0) ; 
 
}
