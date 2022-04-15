# KYC 
## Prerak Srivastava
## 2020111013

### 1. 

Command used in manjaro `cat /proc/cpuinfo`

Link: https://ark.intel.com/content/www/us/en/ark/products/191075/intel-core-i59300h-processor-8m-cache-up-to-4-10-ghz.html

- Model: Intel(R) Core(TM) i5-9300H CPU 
- Generation: 9
- Frequency Range: 2.40GHz - 4.10GHz
- Number of Cores: 4
- Hyper Threading Availability: Yes
- SIMD ISA: Intel® AVX2
- Cache Size: 8192 KB
- Maximum Main Memory Bandwidth: 41.8 GB/s

### 2.

To theoretically calculate peak FLOPS per core, the formula is as follows:

#### Per Core
```
FLOPS = cycles_per_second * flops_per_cycle
cycles_per_second = 4.10 GHz = 4.10 * 10^9 
flops_per_cycle = 32 (For coffee lake microarchitecture)
FLOPS = 131.2 * 10^9 
FLOPS = FLOPS / 10^9
FLOPS = 131.2 Gflops
```
#### Per Processor
```
no_of_cores = 4
FLOPS_per_processor = 131.2 * 4 = 524.8 Gflops
```

Using whetstone benchmark program

Command 
```
./whetstone 1000000
```
Output
```
Loops: 1000000, Iterations: 1, Duration: 15 sec.
C Converted Double Precision Whetstones: 6666.7 MIPS
```

**Tentatively remove second one hehe uwu**

Command
```
./whetstone 10000000
```
Output
```
Loops: 10000000, Iterations: 1, Duration: 103 sec.
C Converted Double Precision Whetstones: 9708.7 MIPS
```

Running another benchmark gives the following results
```
cd Flops/version3
bash compile_linux_gcc.sh
./2013-Haswell
```
The output is stored in `flops_benchmark_output.txt`

#### Writing Benchmark to calculate FLOPS

To measure FLOPS we first need code that performs floating point operations, and measure its execution time 

```c
void func1(){
    // perform floating point instructions
    double x = 1.5;
    double y = 2.5;
    // total number of floating point instructions performed = 200000000
    for (int i = 0; i < 100000000; i++) {
        x = x + y;
        y = x * y;
    }
}
```
Command
```
cd benchmark
gcc benchmark.c -O1
./a.out 
```
Output
```
----------------------------------------
func1
time: 0.509031 s
----------------------------------------
FLOPS: 3.929034 GFLOPS
```

As we can see, this benchmark is heavily unoptimized for the following reasons
- there is kind of parralelism being used
- This can be made efficient by using parallelization using OpenMP or vectorization.

### 3.
<!-- 
Reference for maximum memory bandwidth: https://codearcana.com/posts/2013/05/18/achieving-maximum-memory-bandwidth.html -->

- Main memory size: 15.5 GB
- Memory type: DDR4

#### Stream Benchmark

Benchmarking using STREAM submodule

**Compler**: icc

Command used
```
cd stream-benchmark/STREAM
make stream.icc
./stream.omp.AVX2.80M.20x.icc
```
Output
```
-------------------------------------------------------------
STREAM version $Revision: 5.10 $
-------------------------------------------------------------
This system uses 8 bytes per array element.
-------------------------------------------------------------
Array size = 80000000 (elements), Offset = 0 (elements)
Memory per array = 610.4 MiB (= 0.6 GiB).
Total memory required = 1831.1 MiB (= 1.8 GiB).
Each kernel will be executed 20 times.
 The *best* time for each kernel (excluding the first iteration)
 will be used to compute the reported bandwidth.
-------------------------------------------------------------
Number of Threads requested = 8
Number of Threads counted = 8
-------------------------------------------------------------
Your clock granularity/precision appears to be 1 microseconds.
Each test below will take on the order of 56318 microseconds.
   (= 56318 clock ticks)
Increase the size of the arrays if this shows that
you are not getting at least 20 clock ticks per test.
-------------------------------------------------------------
WARNING -- The above is only a rough guideline.
For best results, please be sure you know the
precision of your system timer.
-------------------------------------------------------------
Function    Best Rate MB/s  Avg time     Min time     Max time
Copy:           28061.6     0.045808     0.045614     0.046849
Scale:          28122.0     0.045844     0.045516     0.049271
Add:            31367.5     0.061685     0.061210     0.062947
Triad:          31334.8     0.061489     0.061274     0.062979
-------------------------------------------------------------
Solution Validates: avg error less than 1.000000e-13 on all three arrays
-------------------------------------------------------------
```
**Compiler**: gcc 

Command used
```
cd stream-benchmark/STREAM
make stream_c.exe
./stream_c.exe
```

Output
```
-------------------------------------------------------------
STREAM version $Revision: 5.10 $
-------------------------------------------------------------
This system uses 8 bytes per array element.
-------------------------------------------------------------
Array size = 10000000 (elements), Offset = 0 (elements)
Memory per array = 76.3 MiB (= 0.1 GiB).
Total memory required = 228.9 MiB (= 0.2 GiB).
Each kernel will be executed 10 times.
 The *best* time for each kernel (excluding the first iteration)
 will be used to compute the reported bandwidth.
-------------------------------------------------------------
Number of Threads requested = 8
Number of Threads counted = 8
-------------------------------------------------------------
Your clock granularity/precision appears to be 1 microseconds.
Each test below will take on the order of 7344 microseconds.
   (= 7344 clock ticks)
Increase the size of the arrays if this shows that
you are not getting at least 20 clock ticks per test.
-------------------------------------------------------------
WARNING -- The above is only a rough guideline.
For best results, please be sure you know the
precision of your system timer.
-------------------------------------------------------------
Function    Best Rate MB/s  Avg time     Min time     Max time
Copy:           25576.0     0.006524     0.006256     0.008151
Scale:          18857.2     0.008594     0.008485     0.008924
Add:            21613.6     0.011240     0.011104     0.011505
Triad:          21177.1     0.011542     0.011333     0.012044
-------------------------------------------------------------
Solution Validates: avg error less than 1.000000e-13 on all three arrays
-------------------------------------------------------------
```
Therefore, main memory bandwidth using the stream benchmark is coming around 25-28 GB/s
### 4. 

Secondary Storage Device: HDD

- Size: 1 TB
- Average Read Rate: 222.4 MB/s
- Average Write Rate: 69.8 MB/s
- Average Access Time: 4.04 ms

# Know your Cluster

- ADA Peak FLOPs: 70.66 TFLOPS
- Abacus Peak FLOPs: 14 TFLOPS

## BLAS Problems

### BLAS Level 1

#### BLAS
Command
```shell
cd blas-problems/q1
make
./q1 1
./q1 2
./q1 3
./q1 4
./q1 
```
First method for writing LEVEL 1 functions is written in blas-problems/q1/q1.c

Output (The time given here is in ms)

#### Approach 1: Without Optimizations

**Compiler**: icc

**Flags**: `-g -axCORE-AVX2`

| Vector Length |   sSCAL   |   dSCAL   |   sDOT    |    dDOT    |   sAXPY    |   dAXPY    |
| :-----------: | :-------: | :-------: | :-------: | :--------: | :--------: | :--------: |
|   20000000    | 5.683000  | 11.999000 | 18.366000 | 36.138000  | 31.115000  | 60.476000  |
|   40000000    | 11.785000 | 25.601000 | 35.906000 | 70.732000  | 59.858000  | 121.335000 |
|   60000000    | 20.011000 | 37.013000 | 52.773000 | 102.953000 | 91.307000  | 178.677000 |
|   80000000    | 25.380000 | 48.444000 | 70.426000 | 137.163000 | 120.422000 | 238.981000 |
|   100000000   | 30.644000 | 59.337000 | 86.987000 | 172.691000 | 149.039000 | 298.794000 |

**Compiler**: gcc

**Flags**: `-g -lm`

| Vector Length |   sSCAL    |   dSCAL    |    sDOT    |    dDOT    |   sAXPY    |   dAXPY    |
| :-----------: | :--------: | :--------: | :--------: | :--------: | :--------: | :--------: |
|   20000000    | 46.826000  | 49.500000  | 61.455000  | 77.696000  | 78.032000  | 103.776000 |
|   40000000    | 93.332000  | 95.730000  | 121.595000 | 153.765000 | 158.216000 | 209.573000 |
|   60000000    | 138.300000 | 142.435000 | 179.921000 | 231.348000 | 230.364000 | 310.813000 |
|   80000000    | 183.993000 | 187.902000 | 237.832000 | 308.195000 | 306.761000 | 413.144000 |
|   100000000   | 226.088000 | 235.211000 | 299.763000 | 385.151000 | 383.734000 | 517.293000 |

#### GCC VS ICC

![Screenshot_20220415_200301](/home/prerak/Pictures/Screenshot_20220415_200301.png)

#### Approach 2: With Optimizations (flags)

**Compiler**: icc

**Flags**: `-g -O3 -axCORE-AVX2`

| Vector Length |   sSCAL   |   dSCAL   |   sDOT    |    dDOT    |   sAXPY    |   dAXPY    |
| :-----------: | :-------: | :-------: | :-------: | :--------: | :--------: | :--------: |
|   20000000    | 5.869000  | 12.336000 | 18.123000 | 36.464000  | 30.512000  | 60.612000  |
|   40000000    | 12.054000 | 27.428000 | 36.330000 | 70.216000  | 60.362000  | 120.673000 |
|   60000000    | 20.224000 | 36.869000 | 52.101000 | 102.929000 | 89.885000  | 179.584000 |
|   80000000    | 26.866000 | 49.693000 | 69.725000 | 137.384000 | 119.536000 | 239.356000 |
|   100000000   | 32.710000 | 61.508000 | 86.079000 | 171.000000 | 149.342000 | 298.043000 |

**Compiler**: gcc

**Flags**: `-g -O3 -lm`

| Vector Length | sSCAL     | dSCAL     | sDOT       | dDOT       | sAXPY      | dAXPY      |
| ------------- | --------- | --------- | ---------- | ---------- | ---------- | ---------- |
| 20000000      | 6.377000  | 13.561000 | 34.853000  | 50.526000  | 32.928000  | 64.173000  |
| 40000000      | 12.148000 | 26.763000 | 69.398000  | 100.064000 | 61.586000  | 124.626000 |
| 60000000      | 19.758000 | 38.489000 | 103.804000 | 150.921000 | 93.030000  | 185.809000 |
| 80000000      | 30.590000 | 50.709000 | 138.987000 | 200.757000 | 125.574000 | 249.614000 |
| 100000000     | 33.822000 | 65.588000 | 174.219000 | 250.510000 | 154.668000 | 311.347000 |

#### GCC VS ICC![Screenshot_20220415_192657](/home/prerak/Pictures/Screenshot_20220415_192657.png)

#### BLIS

BLIS has been install at the location `~/blis` on my system, for which I have updated the makefiles accordingly to link all the required files. 

Command
```shell
cd blas-problems/blis/q1
make
./q1.x
```
Output (The time given here is in ms)

| Vector Length | sSCAL     | dSCAL     | sDOT      | dDOT      | sAXPY     | dAXPY     |
| ------------- | --------- | --------- | --------- | --------- | --------- | --------- |
| 20000000      | 5.714000  | 12.136000 | 9.010000  | 14.820000 | 10.373000 | 21.235000 |
| 40000000      | 11.926000 | 30.753000 | 14.807000 | 31.321000 | 18.133000 | 39.392000 |
| 60000000      | 20.825000 | 39.367000 | 21.812000 | 41.456000 | 28.326000 | 55.455000 |
| 80000000      | 26.899000 | 50.724000 | 28.183000 | 54.002000 | 36.504000 | 71.568000 |
| 100000000     | 32.963000 | 64.747000 | 35.517000 | 67.153000 | 45.323000 | 88.239000 |

#### GCC VS BLIS

![Screenshot_20220415_192404](/home/prerak/Pictures/Screenshot_20220415_192404.png)

#### ICC VS BLIS

![Screenshot_20220415_193143](/home/prerak/Pictures/Screenshot_20220415_193143.png)

