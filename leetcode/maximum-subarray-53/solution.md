Implemented a subarray recursion logic which takes the array and checks the subbaray with the left element excluded and then the subarray with the right element excluded and it breaks with long arrays because it makes too many redundant checks.

I implemented this knowing that I make too many steps and also the that question is taken from the dp section. I had thought of some solutions in this direction and thought of some but they seemed not too optimal so i made the easiest least optimal solution in order to at least pass some test.

With infinite time and memory I have a working solution, but the task is not solved yet.

-- Refined solution:

- Take the first element and begin an array in range : next to last
- Initialize a sum that is effectively the first element on start
- Check if sum > 0 and if yes add the next element, else start over
  with sum = 0 (ditching the array, starting a new one)
- Each iteration check if sum surpasses previous max and record it.
