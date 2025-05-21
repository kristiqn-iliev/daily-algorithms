Solve using fixed sliding window technique.

Solution is accepted but it is very slow in terms of time, so next task will be to check for the best solution out there.

sol steps:

- basically i take the first subvector with lentgth k and sum its elements
- subtract from the sum the left-most element and add the right-most
- compare the the new sum to the current maximum and make max if bigger
