# AAPV-BSA
Algorithm Analysis &amp; Program Validation | Binary Search Algorithm

To compile the code, you should execute these following commands:
```bash
# Navigate to the directory of the program
$ cd AAPV-BSA/

# Create a directory named 'build'
$ mkdir build

# Compile using CMAKE
$ cmake ..

# Build the binary file
$ build
```

After a successful build, you could execute the binary file, by typing the following command:
```bash
# The number of iterations is mandatory
$ ./AAPV-BSA [iterations]
```

You can redirect the output the results of the execution to a seperate file for future reference (maybe):
```bash
$ ./AAPV-BSA [iterations] > 'output_filename'
```

---

Table of correspondence between the number of iterations chosen and the memory that will be allocated by the program.
Types/Iterations|1|2|3|4|5|6|7|8|9|10
---|---|---|---|---|---|---|---|---|---|---
Integer|2 MB|4 MB|8 MB|16 MB|32 MB|64 MB|128 MB|256 MB|1 GB|2 GB
Double Flotttans|4 MB|8 MB|16 MB|32 MB|64 MB|128 MB|256 MB|1 GB|2 GB|4 GB
**Total**|6 MB|12 MB|24 MB|48 MB|96 MB|192 MB|374 MB|1.25 GB |3 GB|6 GB

---

Examples:
```bash
$ ./AAPV-BSA 2
Integers: 2097152 Bytes (2 MBytes)
Doubles: 4194304 Bytes (4 MBytes)
Total: 16777216 Bytes (6 MBytes)
iterative median (int): 0.00115933
recursive median (int): 0.000920333
iterative median (double): 0.000219333
recursive median (double): 0.000194667
---
Integers: 4194304 Bytes (4 MBytes)
Doubles: 8388608 Bytes (8 MBytes)
Total: 33554432 Bytes (12 MBytes)
iterative median (int): 0.00129633
recursive median (int): 0.001129
iterative median (double): 0.000286667
recursive median (double): 0.00023
---
```
```bash
$ ./AAPV-BSA 4 > 'benchmark_48MB.txt'
```
