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

**Tentatively need to confirm flops_per_cycle**
#### Per Core
```
FLOPS = cycles_per_second * flops_per_cycle
cycles_per_second = 4.10 GHz = 4.10 * 10^9 
flops_per_cycle = 8
FLOPS = 32.8 * 10^9 
FLOPS = FLOPS / 10^9
FLOPS = 32.8 Gflops
```
#### Per Processor
```
no_of_cores = 4
FLOPS_per_processor = 32.8 * 4 = 131.2 Gflops
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
### 3.

Reference for maximum memory bandwidth: https://codearcana.com/posts/2013/05/18/achieving-maximum-memory-bandwidth.html

- Main memory size: 15.5 GB
- Memory type: DDR4

#### Stream Benchmark
Benchmarking using stream.c

Command used
```
cd stream-benchmark
./stream
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
Each test below will take on the order of 5794 microseconds.
   (= 5794 clock ticks)
Increase the size of the arrays if this shows that
you are not getting at least 20 clock ticks per test.
-------------------------------------------------------------
WARNING -- The above is only a rough guideline.
For best results, please be sure you know the
precision of your system timer.
-------------------------------------------------------------
Function    Best Rate MB/s  Avg time     Min time     Max time
Copy:           20030.1     0.008103     0.007988     0.008353
Scale:          19858.8     0.008266     0.008057     0.009142
Add:            22632.7     0.010759     0.010604     0.011394
Triad:          22652.0     0.010860     0.010595     0.011390
-------------------------------------------------------------
Solution Validates: avg error less than 1.000000e-13 on all three arrays
-------------------------------------------------------------
```
Benchmarking using STREAM submodule

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
Each test below will take on the order of 6634 microseconds.
   (= 6634 clock ticks)
Increase the size of the arrays if this shows that
you are not getting at least 20 clock ticks per test.
-------------------------------------------------------------
WARNING -- The above is only a rough guideline.
For best results, please be sure you know the
precision of your system timer.
-------------------------------------------------------------
Function    Best Rate MB/s  Avg time     Min time     Max time
Copy:           25587.7     0.006397     0.006253     0.006945
Scale:          19040.7     0.008813     0.008403     0.009798
Add:            21852.0     0.011325     0.010983     0.012597
Triad:          21614.1     0.011254     0.011104     0.011505
-------------------------------------------------------------
Solution Validates: avg error less than 1.000000e-13 on all three arrays
-------------------------------------------------------------
```
Therefore, main memory bandwidth = 20.03 GB/s 
### 4. 

Secondary Storage Device: HDD

- Size: 1 TB
- Average Read Rate: 222.4 MB/s
- Average Write Rate: 69.8 MB/s
- Average Access Time: 4.04 ms

# Know your Cluster

- ADA Peak FLOPs: 70.66 TFLOPS
- Abacus Peak FLOPs: 14 TFLOPS