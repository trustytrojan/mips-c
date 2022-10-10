li $t0, 9
li $t1, 10    
add $t2, $t0, $t1
mult $t2, $t0  
mflo $t3    
li $v0, 9    
move $a0, $t3
syscall