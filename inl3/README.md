# Task - Functions

Create a program doing the following:

1. Take two ints as input
2. Ask for one of three possible instructions:
- `a`: Add numbers
- `m`: Multiply numbers
- `k`: Calc quadratic sum
3. The calculations are to be done on the range spanned by the two 
provided integers.


## Questions

### What are the benefits of using functions instead of all code being 
inside the int main() {}?

Yeah, definately. Makes the code easier to read, easier to debug, 
easier to refactor. Avoids code duplicity too.

### Why not always use reference parameters?

Using return values (and not reference parameters) makes the code more 
readable (in my opinion, at least). If I pass reference variables into 
a function, I am not sure if they will be changed or not, making the 
implementation of the rest of my code more difficult. Return values are 
more "obvious" and frankly "safer."

## Rules & Caveats

1. Functions are to be both declared and defined.
2. Prints only allowed in skrivInfo() and skrivResultat()
3. Prints for cin allowed in lasEttTal and lasOp
4. Cin only allowed in lasEttTal and lasOp
5. Size of return value from multiplication should be considered
6. Input validate the instruction type
7. Not permitted to use arrays or pointers.

## Test cases (Swedish)

1. Läs in talen 3 och 5 samt välj addition. Svaret skall bli 12, 
eftersom 
(3)+(4)+(5)=12.
2. Läs in talen 3 och 5 samt välj multiplicera. Svaret skall bli 60, 
eftersom (3)*(4)*(5)=60.
3. Läs in talen 3 och 5 samt välj kvadratsumma. Svaret skall bli 50, 
eftersom (3*3)+(4*4)+(5*5)=50.
4. Läs in talen -3 och 5 samt välj multiplicera. Svaret skall bli 0, 
eftersom (-3)*(-2)*(-1)*(0)*(1)*(2)*(3)*(4)*(5)=0.
5. Läs in talen 5 och 3 samt välj addition. Svaret skall bli 12, 
eftersom 
(3)+(4)+(5)=12.
6. Läs in talen -3 och -5 samt välj addition. Svaret skall bli -12, 
eftersom (-5)+(-4)+(-3)=-12
7. Läs in talen 1 och 100 samt välj kvadratsumma. Svaret skall bli 
338350.
8. Frivillig uppgift: Läs in talen 1 och 1000 samt välj multiplicera. 
Kommentera resultatet.
