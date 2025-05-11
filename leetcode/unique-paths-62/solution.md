Can be nailed down to an easy combinatoric exercise in which you have to determine the formula for finding in how many different ways
can you place **m - 1 balls** (down moves) into **m + n - 2 boxes** (required down + right moves to goal).

The not so trivial part comes when you have to calculate the binomial of larger numbers.

Computing factorials is not an option because they grow very fast and if we use the factorial formula for the binomials we get
higher factorials in the equation than the binomial itself which does not work.

First i came up with the idea to initialize the factorials in the beggining through dp and thus evade computing over and over but
quickly realized the size of the numbers is the problem and not the computation, so then i decided to use the formula for
the binomials where you can compute one binomial by the sum of its "neighbours" sitting one row higher in pascal's triangle.

So this way you don't need calculating very large factorials which the computer can't handle, so i made the dp structure being
the pascal's triangle.

Some tests didnt qualify so I had to make a little optimization where you don't need the full triangle but only the elements with column
position lesser or equal than the column position of the element to be found.
