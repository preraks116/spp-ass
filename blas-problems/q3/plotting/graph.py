import matplotlib.pyplot as plt
import numpy as np

m = [200, 600, 1000, 1400, 2000]
k = [x + 200 for x in m]
n = [x + 200 for x in k]

matrix_size = [x*(x+400) for x in range(200, 2001, 400)]

blis_sgemm = [4.046000,11.519000  ,31.337000  , 75.169000  , 183.760000 ]
blis_dgemm = [9.011000 ,20.775000  ,60.834000  ,147.386000 ,396.114000 ]

icc_sgemm = [38.059000  ,238.617000  ,992.434000  ,9095.817000  ,41747.513000 ]
icc_dgemm = [53.497000  ,  357.391000  , 1762.003000  ,11328.725000 ,47936.548000 ]

gcc_sgemm = [118.037000   , 1287.008000  , 5529.920000  , 17294.369000 , 46805.713000 ]
gcc_dgemm = [120.131000   ,1632.157000  ,6403.790000  ,19182.455000 ,55708.977000 ]

op_icc_sgemm = [37.538000,240.426000,1021.825000  ,9269.478000  ,41260.255000 ]
op_icc_dgemm = [52.732000,365.831000   ,1705.998000  ,11353.136000 ,49184.683000              ]

op_gcc_sgemm = [71.580000    , 482.551000   , 1916.106000  , 9020.441000  , 39199.686000 ]
op_gcc_dgemm = [75.929000    ,554.174000   ,2373.110000  ,11333.940000 ,  45908.279000 ]

omp_icc_sgemm = [35.559000    ,     216.657000   ,    1595.501000  ,   3926.005000  ,   10702.296000 ]
omp_icc_dgemm =[54.183000 ,333.097000,1641.880000,4151.858000,11559.818000]

omp_gcc_sgemm = [57.468000    , 277.563000   , 1795.891000  , 4282.664000  , 11677.727000 ]
omp_gcc_dgemm = [62.228000    ,401.194000   ,1864.001000  ,4551.218000  ,12886.488000]

# for i in range(len(m)):
#     gflops = (m[i]*n[i]*(3*k[i] + 1))/blis_sgemm[i]
#     # round it off to 4 decimal points and print it
#     print("GFLOPS: ", round(gflops/1000000, 4))
#     # print(gflops/1000000)

# plot icc_xgemm and gcc_xgemm
# plt.plot(matrix_size, omp_icc_sgemm, 'r', label='Parallelized ICC sGEMM')
# plt.plot(matrix_size, omp_icc_dgemm, 'b', label='Parallelized ICC dGEMM')
# plt.plot(matrix_size, omp_gcc_sgemm, 'r--', label='Parallelized GCC sGEMM')
# plt.plot(matrix_size, omp_gcc_dgemm, 'b--', label='Parallelized GCC dGEMM')
# plt.plot(matrix_size, blis_sgemm, 'r:', label='BLIS sGEMM')
# plt.plot(matrix_size, blis_dgemm, 'b:', label='BLIS dGEMM')

# plot all sgemm
plt.plot(matrix_size, omp_icc_dgemm, 'r', label='Parallelized ICC dGEMM')
plt.plot(matrix_size, omp_gcc_dgemm, 'b', label='Parallelized GCC dGEMM')
plt.plot(matrix_size, op_icc_dgemm, 'r--', label='Vectorized GCC dGEMM')
plt.plot(matrix_size, op_gcc_dgemm, 'b--', label='Vectorized GCC dGEMM')
plt.plot(matrix_size, blis_dgemm, 'y', label='BLIS dGEMM')
plt.plot(matrix_size, gcc_dgemm, 'b-.', label='GCC dGEMM')
plt.plot(matrix_size, icc_dgemm, 'r-.', label='ICC dGEMM')
plt.xlabel('Matrix Size')
plt.ylabel('Time (ms)')
plt.title('Execution Time vs Matrix Size')
plt.legend()
plt.show()