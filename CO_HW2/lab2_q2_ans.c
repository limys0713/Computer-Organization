// TODO : 

"li x6, 0\n\t"
"li x7, 8\n\t"
"vsetvli x5, x7, e16\n\t"
"vle16.v v0, 0(%[p_x])\n\t"
"li x30, -1\n\t"

"one_loop:\n\t"
"lh x12, 0(%[p_x])\n\t"
"vadd.vx v1, v0, x12\n\t"
"vmseq.vx v2, v1, %[target]\n\t"
"vfirst.m x13, v2\n\t"
"bne x13, x30, found\n\t"
"addi %[p_x], %[p_x], 2\n\t"
"addi x6, x6, 1\n\t"
"bne x6, x7, one_loop\n\t"
"j end\n\t"
   
"found:\n\t"
"li %[flag], 1\n\t"
   
"end:\n\t"
