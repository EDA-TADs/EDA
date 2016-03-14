# Abstract Data Types

#### March 2, 2016

We need to code a generic version of the Polynomial ADT, with generic coefficients and natural exponents.
The representation of a certain polynomial of degree g,

    SUM i=0 -> g: (c_i * x^i) is a static array P[0..N], N >= g, so that 
    FORALL i : 0 <= i <= g : P[i] = c_i .

 * *Code* the generic version of the _Polynomial_ ADT.
 * *Include* all the default implementations: constructors, destructor, operators = and ==, and the friend function <<.
 * *Overload* operator+ so that it adds two polynomials.
 * *Add* an operation to the ADT that evaluates a polynomial for a specific value of x.
 * *Code* the main function of a program which tests all the implemented operations of the _Polynomial_ ADT work correctly.
 
 
 
