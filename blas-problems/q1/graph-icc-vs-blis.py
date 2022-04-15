import matplotlib.pyplot as plt
import numpy as np

# array of all vector lengths
vec_len = [20000000, 40000000, 60000000, 80000000, 100000000]

icc_sscal = [5.869000, 12.054000, 20.224000, 26.866000, 32.710000]
icc_dscal = [12.336000, 27.428000, 36.869000, 49.693000, 61.508000]
icc_sdot = [18.123000, 36.330000, 52.101000, 69.725000, 86.079000]
icc_ddot = [36.464000, 70.216000, 102.929000, 137.384000, 171.000000]
icc_saxpy = [30.512000, 60.362000, 89.885000, 119.536000, 149.342000]
icc_daxpy = [60.612000, 120.673000, 179.584000, 239.356000, 298.043000]

blis_sscal = [5.714000  , 11.926000 , 20.825000 , 26.899000 , 32.963000 ]
blis_dscal = [12.136000 , 30.753000 , 39.367000 , 50.724000 , 64.747000 ]
blis_sdot = [9.010000  , 14.807000 , 21.812000 , 28.183000 , 35.517000 ]
blis_ddot = [14.820000 , 31.321000 , 41.456000 , 54.002000 , 67.153000 ]
blis_saxpy = [10.373000 , 18.133000 , 28.326000 , 36.504000 , 45.323000 ]
blis_daxpy = [21.235000 , 39.392000 , 55.455000 , 71.568000 , 88.239000 ]

# plot the graphs with vec_len as x-axis and time in ms as y-axis

#legend
legend = ['icc_sscal', 'icc_dscal', 'icc_sdot', 'icc_ddot', 'icc_saxpy', 'icc_daxpy', 'blis_sscal', 'blis_dscal', 'blis_sdot', 'blis_ddot', 'blis_saxpy', 'blis_daxpy']

#plot
plt.plot(vec_len, icc_sscal, 'r', label='icc_sscal')
plt.plot(vec_len, icc_dscal, 'g', label='icc_dscal')
plt.plot(vec_len, icc_sdot, 'b', label='icc_sdot')
plt.plot(vec_len, icc_ddot, 'y', label='icc_ddot')
plt.plot(vec_len, icc_saxpy, 'c', label='icc_saxpy')
plt.plot(vec_len, icc_daxpy, 'm', label='icc_daxpy')
plt.plot(vec_len, blis_sscal, 'r--', label='blis_sscal')
plt.plot(vec_len, blis_dscal, 'g--', label='blis_dscal')
plt.plot(vec_len, blis_sdot, 'b--', label='blis_sdot')
plt.plot(vec_len, blis_ddot, 'y--', label='blis_ddot')
plt.plot(vec_len, blis_saxpy, 'c--', label='blis_saxpy')
plt.plot(vec_len, blis_daxpy, 'm--', label='blis_daxpy')
plt.legend(legend, loc='upper left')
plt.show()