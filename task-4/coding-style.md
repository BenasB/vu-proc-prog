# Coding style

## Naming

| Entity              | Convention | Example    |
| ------------------- | ---------- | ---------- |
| Variables           | camelCase  | myVariable |
| Functions           | camelCase  | myFunction |
| Structures          | PascalCase | MyStruct   |
| `define`s           | MACRO_CASE | MY_DEFINE  |
| Tests               | MACRO_CASE | MY_TEST    |
| `.c` and `.h` files | kebab-case | my-file    |

## General rules

### Variables

Variable names should be specific, not too short. Write full worlds if there's no world wide used acronym (not the case for User Interface = UI, etc.).

```diff
+ mySpecificName, maxLimit, currentCount
- x, currcnt, ln
```

_Exception:_ indices such as `i, j, k`, etc.

### Brackets

Make sure to put brackets on new lines as such:

```C
int my_function (double variable)
{

}
```

### Comments

Comments should be provided **only when necessary**. Try to write code that doesn't need any additional explanation, use the [KISS principle](https://en.wikipedia.org/wiki/KISS_principle).

### Indentation

Use 4 spaces indentation.

### Pointers

Write the asterisk `*` for pointers with the name, not the type:

```C
int *x;
```

## Code structures

### Conditions

Conditions should be written like this:

```C
if (condition)
{
    // statement
}
else if (condition)
{
    // statement
}
else
{
    // statement
}
```

### `for` loop

`for` loops should be written like this:

```C
for (int i = 0; i < limit; i++)
{
    for (int j = 0; j < limit; j++)
    {
        for (int k = 0; k < limit; k++)
        {
            // statement
        }
    }
}
```

### `while` loop

`while` loops should be written like this:

```C
while (condition)
{
    // statement
}
```

### `do while` loop

`do while` loops should be written like this:

```C
do
{
    // statement
} while (condition);
```

### `switch`

`switch` should be written like this:

```C
switch(variable)
{
case case1:
    // statement
    break;

case case2:
    // statement
    break;

default:
    // statement
    break;
}
```

### `struct`

`struct` should be defined like this:

```C
struct MyStruct
{
    int variable;
} structVariable;
```
