// description: matrix muliply with two-level for loop
#include<stdio.h>

int main(){ 

    int f,i=0;
    int h[9]={0}, x[3]={0}, y[3]={0}; 

    FILE *input = fopen("../input/3.txt","r");
    for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
    fclose(input);

    int *p_x = &x[0] ;
    int *p_h = &h[0] ;
    int *p_y = &y[0] ;
 
    for (i = 0 ; i < 3; i++){
        p_x = &x[0] ; 

            for (f = 0 ; f < 3; f++)
                asm volatile(			                	
                    "li t5, 2\n\t"	//set intermediate
                    "lw t0, 0(%[p_h])\n\t" //load value
                    "lw t1, 0(%[p_x])\n\t" //load value 
                    "mul t2, t0, t1\n\t"    //mul 
                    "lw t3, 0(%[p_y])\n\t" //load value 
                    "add t4, t2, t3\n\t" //add
                    "sw t4, 0(%[p_y])\n\t"	//store
                    "addi %[p_h], %[p_h], 4\n\t"
                    "addi %[p_x], %[p_x], 4\n\t"
                    "bne %[f], t5, end\n\t"	//if not eq, go to exit
                    "beq %[f], t5, else\n\t"	//if equal go to else
                    "else:\n\t"
                    "addi %[p_y], %[p_y], 4\n\t"
                    "end:\n\t"
                    : [p_h] "+r" (p_h), [p_x]"+r" (p_x), [p_y] "+r" (p_y)
                    :  [f] "r" (f)
                    : "t0", "t1", "t2", "t3", "t4", "t5"
                );
        }

    p_y = &y[0];
    for(i = 0; i<3; i++)
        printf("%d \n", *p_y++);

    return(0) ;  
}
