// TODO : 

"li x6, 8\n\t"    
"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"li x28, 16\n\t"    
"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"loop2:\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"

"vsetvli x5, x6, e16, ta, ma\n\t" 
"addi %[others_cnt], %[others_cnt], 1\n\t"

"vle16.v v0, 0(%[h])\n\t"     
"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"sub x28, x28, x5\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
 
"slli x5, x5, 1\n\t" 
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"add %[h], %[h], x5\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"vle16.v v1, 0(%[x])\n\t"    
"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"add %[x], %[x], x5\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"vadd.vv v2, v0, v1\n\t"      
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"vse16.v v2, 0(%[y])\n\t"     
"addi %[sw_cnt], %[sw_cnt], 1\n\t"

"add %[y], %[y], x5\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"bnez x28, loop2\n\t"

