import matplotlib.pyplot as plt
import numpy as np

# array of all vector lengths
vec_len = [20000000, 40000000, 60000000, 80000000, 100000000]

gcc_sscal = [6.377000  , 12.148000 , 19.758000 , 30.590000 , 33.822000  ]
gcc_dscal = [13.561000 , 26.763000 , 38.489000 , 50.709000 , 65.588000 ]
gcc_sdot =  [34.853000  , 69.398000  , 103.804000 , 138.987000 , 174.219000  ]
gcc_ddot =  [50.526000  , 100.064000 , 150.921000 , 200.757000 , 250.510000 ]
gcc_saxpy = [32.928000  , 61.586000  , 93.030000  , 125.574000 , 154.668000 ]
gcc_daxpy = [64.173000  , 124.626000 , 185.809000 , 249.614000 , 311.347000]

blis_sscal = [5.714000  , 11.926000 , 20.825000 , 26.899000 , 32.963000 ]
blis_dscal = [12.136000 , 30.753000 , 39.367000 , 50.724000 , 64.747000 ]
blis_sdot = [9.010000  , 14.807000 , 21.812000 , 28.183000 , 35.517000 ]
blis_ddot = [14.820000 , 31.321000 , 41.456000 , 54.002000 , 67.153000 ]
blis_saxpy = [10.373000 , 18.133000 , 28.326000 , 36.504000 , 45.323000 ]
blis_daxpy = [21.235000 , 39.392000 , 55.455000 , 71.568000 , 88.239000 ]


# plot the graphs with vec_len as x-axis and time in ms as y-axis

#legend
legend = ['GCC sscal', 'GCC dscal', 'GCC sdot', 'GCC ddot', 'GCC saxpy', 'GCC daxpy', 'BLIS sscal', 'BLIS dscal', 'BLIS sdot', 'BLIS ddot', 'BLIS saxpy', 'BLIS daxpy']

# plot
plt.plot(vec_len, gcc_sscal, 'r-', label='GCC sscal')
plt.plot(vec_len, gcc_dscal, 'g-', label='GCC dscal')
plt.plot(vec_len, gcc_sdot, 'b-', label='GCC sdot')
plt.plot(vec_len, gcc_ddot, 'y-', label='GCC ddot')
plt.plot(vec_len, gcc_saxpy, 'c-', label='GCC saxpy')
plt.plot(vec_len, gcc_daxpy, 'm-', label='GCC daxpy')
plt.plot(vec_len, blis_sscal, 'r--', label='BLIS sscal')
plt.plot(vec_len, blis_dscal, 'g--', label='BLIS dscal')
plt.plot(vec_len, blis_sdot, 'b--', label='BLIS sdot')
plt.plot(vec_len, blis_ddot, 'y--', label='BLIS ddot')
plt.plot(vec_len, blis_saxpy, 'c--', label='BLIS saxpy')
plt.plot(vec_len, blis_daxpy, 'm--', label='BLIS daxpy')
plt.legend(legend, loc='upper left')
plt.show()