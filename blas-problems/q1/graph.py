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

gcc_sscal = [6.377000  , 12.148000 , 19.758000 , 30.590000 , 33.822000  ]
gcc_dscal = [13.561000 , 26.763000 , 38.489000 , 50.709000 , 65.588000 ]
gcc_sdot =  [34.853000  , 69.398000  , 103.804000 , 138.987000 , 174.219000  ]
gcc_ddot =  [50.526000  , 100.064000 , 150.921000 , 200.757000 , 250.510000 ]
gcc_saxpy = [32.928000  , 61.586000  , 93.030000  , 125.574000 , 154.668000 ]
gcc_daxpy = [64.173000  , 124.626000 , 185.809000 , 249.614000 , 311.347000]

# plot the graphs with vec_len as x-axis and time in ms as y-axis

#legend
legend = ['icc_sscal', 'icc_dscal', 'icc_sdot', 'icc_ddot', 'icc_saxpy', 'icc_daxpy', 'gcc_sscal', 'gcc_dscal', 'gcc_sdot', 'gcc_ddot', 'gcc_saxpy', 'gcc_daxpy']

plt.plot(vec_len, icc_sscal, label='icc_sscal')
plt.plot(vec_len, gcc_sscal, label='gcc_sscal')
plt.plot(vec_len, icc_dscal, label='icc_dscal')
plt.plot(vec_len, gcc_dscal, label='gcc_dscal')
plt.plot(vec_len, icc_sdot, label='icc_sdot')
plt.plot(vec_len, gcc_sdot, label='gcc_sdot')
plt.plot(vec_len, icc_ddot, label='icc_ddot')
plt.plot(vec_len, gcc_ddot, label='gcc_ddot')
plt.plot(vec_len, icc_saxpy, label='icc_saxpy')
plt.plot(vec_len, gcc_saxpy, label='gcc_saxpy')
plt.plot(vec_len, icc_daxpy, label='icc_daxpy')
plt.plot(vec_len, gcc_daxpy, label='gcc_daxpy')
plt.legend()
plt.show()