## When Running the Binary:

Action: `./cuboid` 

Result: `bash: ./cuboid: cannot execute binary file: Exec format error`

Conclusion: The binary is likely compiled to run in Linux

Solution: Run the binary in a Linux container (via Podman `brew install podman`)

## When Debugging Code

**Initial Check for provided Args**

Bug: Argc was checking for 3 args using argc != 3

Solution: Argc includes the binary name as an arg, so it must be 4

---

**Storing Dimensional Arguments**

Bug: Numerical arguments passed in via argv are recognized as characters, not integers

Solution: Convert the strings to integers using `strtol()`

---
**Indexing Errors**

1. Bug: The calculated total number of lines was incorrect

    Solution: Add +1 to the calculation in order to represent the first line and, in a way, the 0 index

2. Bug: The k index, representing the index of a character array being built, was reset every loop

    Solution: Set k = 0 outside the loop, as this way the image can be built fully

---

**Construction Errors**

1. Bug: Too many spaces are adding during the construction of the first edge

    Solution: Since the space generation section handles the spaces in front of the first edge, remove the spaces additions from this sections

2. Bug: Underscore construction did not follow the pattern of characters necessary

    Solution: Since iteration is over the length of X, add the characters as groups based on the line number. E.g. groups of 3 chars like ' ', '_', '\'

3. Bug: Construction of the side characters uses the incorrect pattern and line end detection

    Solution: Use `m` as an index for the number of /\ and \/ patterns being added to the last side, and remove the extraneous check from the end detection
