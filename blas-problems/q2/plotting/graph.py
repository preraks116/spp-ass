import matplotlib.pyplot as plt
import numpy as np

rows = [2000, 4000, 6000, 8000, 10000]
## add 2000 to each element in rows 
cols = [x + 2000 for x in rows]

# get matrix size in a list
matrix_size = [x*(x+2000) for x in range(2000, 10001, 2000)]

icc_sgemv = [1.045000, 3.712000, 8.011000, 13.690000, 21.215000 ]
icc_dgemv = [2.003000, 6.952000, 15.216000, 26.755000, 41.746000]

gcc_sgemv = [24.295000, 74.686000, 149.277000, 249.542000, 369.120000]
gcc_dgemv = [25.143000, 75.594000, 155.780000, 257.111000, 381.355000]

op_icc_sgemv = [1.104000, 3.272000, 7.040000, 12.097000, 18.616000]
op_icc_dgemv = [1.823000, 6.651000, 14.259000, 24.133000, 36.436000]

op_gcc_dgemv = [8.225000,25.281000, 51.744000 ,86.864000 ,130.238000 ]
op_gcc_sgemv = [8.149000 ,24.035000 , 48.436000,82.096000 ,124.460000]

blis_sgemv = [1.384000,4.267000 ,7.819000 ,12.805000,19.069000]
blis_dgemv = [2.449000 ,7.365000  ,14.861000  ,27.344000 ,37.570000 ]

omp_icc_sgemv = [1.872000 , 3.450000  ,6.038000  , 10.227000 , 14.853000 ]
omp_icc_dgemv = [2.402000 ,5.746000  ,11.031000 ,19.049000 ,27.858000 ]
omp_gcc_sgemv = [1.208000 , 3.467000  , 6.805000  , 11.866000 , 17.092000 ]
omp_gcc_dgemv = [1.530000 ,4.771000  ,10.778000 ,17.777000 ,27.520000 ]




# put the numbers above in an array


# for i in range(5):
#     gflops = (3*rows[i]*cols[i] + rows[i])/omp_gcc_dgemv[i]
#     # round it off to 4 decimal points and print it
#     print("GFLOPS: ", round(gflops/1000000, 4))
#     # print(gflops/1000000)

# plot with data on x and icc_sgemv on y
# plt.plot(matrix_size, blis_sgemv, label = "blis_sgemv")
# plt.plot(matrix_size, blis_dgemv, label = "blis_dgemv")
# plt.plot(matrix_size, op_gcc_sgemv, label = "gcc_sgemv")
# plt.plot(matrix_size, op_gcc_dgemv, label = "gcc_dgemv")
# plt.legend()
# plt.xlabel("Matrix Size")
# plt.ylabel("Time (ms)")
# plt.show()

# plt.plot(matrix_size, icc_sgemv, "r-", label = "ICC")
# # plt.plot(matrix_size, gcc_sgemv, "b-", label = "GCC")
# plt.plot(matrix_size, op_icc_sgemv, "g-", label = "Vectorized ICC")
# # plt.plot(matrix_size, op_gcc_sgemv, "y-", label = "Vectorized GCC")
# plt.plot(matrix_size, blis_sgemv, "y-", label = "BLIS ")
# plt.plot(matrix_size, omp_icc_sgemv, "c-",  label = "Parallelized ICC")
# plt.plot(matrix_size, omp_gcc_sgemv, "m-", label = "Parallelized GCC")

# plt.plot(matrix_size, icc_dgemv, "r--", label = "ICC")
# # plt.plot(matrix_size, gcc_dgemv, "b--", label = "icc_dgemv")
# plt.plot(matrix_size, op_icc_dgemv, "g--", label = "Vectorized ICC")
# plt.plot(matrix_size, op_gcc_dgemv, "y--", label = "Vectorized GCC")
# plt.plot(matrix_size, blis_dgemv, "k--", label = "BLIS")
# plt.plot(matrix_size, omp_icc_dgemv, "c--",  label = "Parallelized ICC")
# plt.plot(matrix_size, omp_gcc_dgemv, "m--", label = "Parallelized GCC")
# plt.legend()

# plot omp_icc_sgemv, omp_icc_dgemv, omp_gcc_sgemv, omp_gcc_dgemv
plt.plot(matrix_size, omp_icc_sgemv, "r-", label = "Parallelized ICC SGEMV")
plt.plot(matrix_size, omp_icc_dgemv, "r--", label = "Parallelized ICC DGEMV")
plt.plot(matrix_size, omp_gcc_sgemv, "b-", label = "Parallelized GCC SGEMV")
plt.plot(matrix_size, omp_gcc_dgemv, "b--", label = "Parallelized GCC DGEMV")
plt.legend()

plt.show()
# print(381.355/27.52)
