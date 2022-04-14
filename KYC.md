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

### 3.
<!-- 
Reference for maximum memory bandwidth: https://codearcana.com/posts/2013/05/18/achieving-maximum-memory-bandwidth.html -->

- Main memory size: 15.5 GB
- Memory type: DDR4

#### Stream Benchmark

Benchmarking using STREAM submodule

Benchmarking using icc

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
Benchmarking using gcc 

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
Therefore, main memory bandwidth is around 25-28 GB/s
### 4. 

Secondary Storage Device: HDD

- Size: 1 TB
- Average Read Rate: 222.4 MB/s
- Average Write Rate: 69.8 MB/s
- Average Access Time: 4.04 ms

# Know your Cluster

- ADA Peak FLOPs: 70.66 TFLOPS
- Abacus Peak FLOPs: 14 TFLOPS