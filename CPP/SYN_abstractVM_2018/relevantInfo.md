comments
Begin with a semicolon (;) and end at the end
of a line. A comment may be indifferent at the
beginning of a line or after an instruction.

push v
Stacks  the  v  value  at  the  top.  The  v  value will naturally take one of the following forms:
int8(n), int16(n), int32(n), float(z), double(z) or
bigdecimal(z).For example,int16(n) creates an signed 16-bit integer with the value n.

pop
Unstacks the value at the top of the stack. If the stack is empty the program’s execution must
stop error.

clear
Clears the stack, making it empty.

dup
Duplicates the value on the top of the stack,
and stacks the copy of the value.

swap
Reverses the order of (swaps) the top two values
on the stack.

dump
Displays each value on the stack from the newest to the oldest,WITHOUT MODIFYING the stack.
Each value is separated from the next one with a line break.

assert v
Checks that the value at the top of the stack is equal to the one passed as parameter in this instruction.
If it’s not the case, the program execution must stop error.
The v value, of course, has the same form as those passed as parameter during the push instruction.

load v
Copies the value from the register v and stacks it at the top. if the register v does not contain a value, the program execution must stop error.

store v
Unstacks the first value and stores it to the register v.

print
Makes sure that the value at the top of the stack is an 8-bit integer (if this is not the case, see the assert instruction), then interprets it like an ASCII value and
displays the corresponding character on the standard output.

sqrt
Unstacks the first value in the stack, calculates its square root, and then stacks the result.

add
Unstacks the first two values in the stack, adds
them, and then stacks the result.
If the number of values in the stack is strictly
less than 2, the program execution must stop
error.

sub
Unstacks  the  first  two  values  in  the  stack, substracts them, and then stacks the result.
If the number of values in the stack is strictly
less than 2, the program execution must stop
error.

mul
Unstacks the first two values in the stack, multiplies them, and then stacks the result.
If the number of the values in the stack is strictly less than 2, the program execution must stop error.

div
Unstacks the first two values in the stack, divides them, and then stacks the result.
If the number of the values in the stack is strictly less than 2, the program execution must stop error.
Also, if the divisor is equal to 0, the program execution must also stop error.

mod
Unstacks the first two values in the stack, calculates their modulo, and then stacks the result.
If the number of the values in the stack is strictly less than 2, the program execution must stop error.
Also, if the divisor is equal to 0, the program execution must also stop error.

exit
Quits the program execution that is underway. If this instruction does not appear, despite the fact that all
of the instructions have been executed, the execution must stop error.