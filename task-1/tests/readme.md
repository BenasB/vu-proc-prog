# Unit testing

## How to run it

Just execute `tests/run_tests.sh <path/to/file.c>` where `<path/to/file.c>` is a path relative to the project root directory. After it, you will receive the testing result summary, e.g.

```
1. SMALL: PASSED
2. LARGE: FAILED
Expected:
20 14
Recieved:
20 15
3. MEDIUM IDK: PASSED

Total tests: 3
Passed: 2
Failed: 1
```

## Prerequisites

* Mandatory `cases.txt` file that describes your test cases
* Optional `ignore.txt` file that describes strings to be ignored from the received output of the program.

The example below contains 3 test cases where every one of them have an input (it can span 1 or more lines) and an expected output (it can also span 1 or more lines)

### `cases.txt` format:

```
Test name GOES here, IT CAN BE ANYTHING
1 2 3 input starts on the next line

5 8 expected output starts after a new line after the input

TEST CASE2
input
can span multiple
lines until a new line

same goes with
expected output

NEGATIVE_NUMBERS
-1 -2
-4 -5

2 4
8 10
```

### `ignore.txt` format

```
These
Words
Will
Be
Removed
THIS EXACT LINE WILL BE REMOVED
```