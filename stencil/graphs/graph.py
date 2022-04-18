import matplotlib.pyplot as plt
import numpy as np

stencil_size = [x for x in range(3, 84, 20)]

gcc_hd = [93.878000, 4378.076000, 15249.852000, 33102.726000, 55492.324000]
op_gcc_hd = [23.635000, 1110.388000, 3795.378000, 7936.417000, 13541.367000]
omp_gcc_hd = [4.608000, 122.757000, 499.319000, 956.817000, 1789.617000]

icc_hd = [26.411000, 862.628000, 2860.697000, 6420.337000, 12027.179000]
op_icc_hd = [23.276000, 791.390000, 2811.835000, 6143.960000, 11989.756000]
omp_icc_hd = [8.763000, 225.761000, 750.108000, 1665.595000, 2877.264000]

gcc_uhd = [350.949000, 13243.805000, 44057.716000, 94987.475000, 168034.916000]
op_gcc_uhd =[64.631000,2442.030000,10637.017000,21839.558000,42745.312000]
omp_gc_uhd =[18.118000,499.481000,2032.337000,4025.289000,7533.248000]

icc_uhd = [121.918000, 3242.232000, 11546.700000, 25142.785000, 49031.951000]
op_icc_uhd = [103.103000, 3473.746000, 11816.069000, 25954.868000, 48800.378000]
omp_icc_uhd = [31.414000,899.212000,3048.473000,6623.252000,11740.869000]

# plotting the graph
# plt.plot(stencil_size, gcc_hd, 'r', label='GCC-HD')
# plt.plot(stencil_size, op_gcc_hd, 'b', label='VEC-GCC-HD')
# plt.plot(stencil_size, omp_gcc_hd, 'g', label='OMP-GCC-HD')
plt.plot(stencil_size, icc_hd, 'y', label='ICC-HD')
plt.plot(stencil_size, op_icc_hd, 'c', label='VEC-ICC-HD')
plt.plot(stencil_size, omp_icc_hd, 'm', label='OMP-ICC-HD')
# plt.plot(stencil_size, gcc_uhd, 'r--', label='GCC-UHD')
# plt.plot(stencil_size, op_gcc_uhd, 'b--', label='VEC-GCC-UHD')
# plt.plot(stencil_size, omp_gc_uhd, 'g--', label='OMP-GCC-UHD')
plt.plot(stencil_size, icc_uhd, 'y--', label='ICC-UHD')
plt.plot(stencil_size, op_icc_uhd, 'c--', label='VEC-ICC-UHD')
plt.plot(stencil_size, omp_icc_uhd, 'm--', label='OMP-ICC-UHD')
plt.legend()
plt.show()