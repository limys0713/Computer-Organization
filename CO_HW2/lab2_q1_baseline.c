// TODO : 

"li x5, 16\n\t"    
"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"loop:\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"	

"lh x6, 0(%[h])\n\t"
"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"lh x7, 0(%[x])\n\t"
"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"add x28, x7, x6\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"sh x28, 0(%[y])\n\t"
"addi %[sw_cnt], %[sw_cnt], 1\n\t"

"addi %[h], %[h], 2\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"addi %[x], %[x], 2\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"addi %[y], %[y], 2\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"addi x5, x5, -1\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"bnez x5, loop\n\t"


