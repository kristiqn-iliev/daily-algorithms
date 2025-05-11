This self implemented vector data structure is designed to make the implementation of algorithms easier, because they mostly use vectors of numbers. This custom data structures contains methods that allow:

0.0.1:

- seemless assignments with hardcoded lists;
- instantiating direct copies of objects of the same class;
- printing the data of the vector to the console;
- instantiating an object with a given hardcoded list;

  0.0.2:

- subvector method that takes 1 or 2 parameters start and/or end
  and returns a new vector of the same type start is the first
  element of the new vector and end is the first excluded from it.
- pop_back method that modifies current vector removing its last el
- pop_start same but with the first element
- total function that returns the sum of the elements of the vector

# must be refactored so that non-number types are taken into consideration

- max and min functions that return the minimum and maximum elements in the vector

# currently working only for int, and error handling for calling them with

# other types is not implemented
