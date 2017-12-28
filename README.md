# CMPE250_2017Fall_Project4

## About My Submission

I finished the project around 

28.12.2017 23.20

except for one tiny bug, that I spent almost an hour to find it.

The results was working correctly, yet derivatives were not.

Then, I saw that the following part at 00.03

```
long double Variable::getComputedValue() {
  if (computedValue . isEmpty()) {
    computedValue . setValue(Functions::functions[myType](left, right));
  }
  return computedValue . getValue();
}

long double Variable::getDerivativeValue() {
  if (derivativeValue . isEmpty()) {
    derivativeValue . setValue(Functions::functions[myType](left, right));
  }
  return derivativeValue . getValue();
}
```

and realized the reason that all the outputs were the original results, too

instead of
```
derivativeValue . setValue(Functions::derivatives[myType](left, right));
```
I have written
```
derivativeValue . setValue(Functions::functions[myType](left, right));
```

I quickly fixed it and recommitted it by 00.08. (I also auto-reformatted code, 
so that commit seems to include more changes but it's just spaces)

Then, I've added some more comments in the next 15 minutes.

In my computer and vm, the program works correctly on all test cases, except

Test Case 3 derivatives part, which says

Written values are different. values = 246290442436.101715 and 246192925599.857758

Don't know why but maybe using doubles instead of long doubles would fix it. 
(Maybe not, I'm tired and stressed out, so I'll just stop working on it)

## My Solution

I used function pointers and a tree structure that's similar to the given template. 
There are variables which are either inputs, constants, 
unary functions of another variables, or binary functions of another variables.

Also, it was important to use dynamic programming 
(adding a simple flag to check if a value was previously computed)
so that the program wouldn't run extremely slow.

I solved the cycle check problem, by making a dfs and keeping a visited flag on 
visited nodes until they're finished (all of their children is traversed and finished),
and I set a finished flag then. If a node has a child that is visited but not finished.
That means, this child is also the parent of parent of ... the current node, so the graph is cyclic.

I used long double to get high precision on my values.

I also experimented using function pointers. So, instead of creating sin, cos, etc. classes I used function pointers,
such as functions[SIN] gave me a function that calculates the sine of a given Variable. 
Similarly, derivations[SIN] gave me the derivation of that function.  

## How to compile

In a terminal, call commands:
```
>cmake CMakeLists.txt

>make

OR

>cmake CMakeLists.txt && make

```
Make sure the executable is produced.

Then you can test the project with the command:
```
>./project4 functionDefinitionFile inputValuesFile outputValuesFile derivativeValuesFile
```
