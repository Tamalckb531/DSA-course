# Important notes for CPP basics

## variables and datatype:

Number range in a variable : (-2^byte - 1) to (2^byte - 1)
Here, byte is basically the occupied place of the variable. <br/>

let n = byte <br/>
for integer, signed form : 2^(n-1) to 2^(n-1) - 1 <br/>
for integer, unsigned form : 0 to 2^n - 1 <br/>

## user input:

1. cin.ignore(): It clears the input buffer, useful after using cin to prevent unexpected behavior when mixing different input methods.

2. cin.fail(): It checks if the previous input operation failed, typically used to handle invalid input.

3. getline(cin, 10): Reads input from cin into a string, stopping either after reaching a newline or after reading 10 characters, whichever comes first.
