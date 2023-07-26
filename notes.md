## When Running the Binary:
1.
Action: `./cuboid` 
Result: `bash: ./cuboid: cannot execute binary file: Exec format error`
Conclusion: The binary is likely compiled to run in Linux
Solution: Run the binary in a Linux container (via Podman `brew install podman`)

## WHen Debugging Code

1. Initial Check for provided Args
Result: Argc was checking for 3 args using argc != 3
Solution: Argc includes the binary name as an arg, so it must be 4