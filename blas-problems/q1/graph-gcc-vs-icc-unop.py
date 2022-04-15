import matplotlib.pyplot as plt
import numpy as np

# array of all vector lengths
vec_len = [20000000, 40000000, 60000000, 80000000, 100000000]

gcc_sscal = [46.826000  , 93.332000  , 138.300000 , 183.993000 , 226.088000 ] 
gcc_dscal = [49.500000  , 95.730000  , 142.435000 , 187.902000 , 235.211000 ]
gcc_sdot = [61.455000  , 121.595000 , 179.921000 , 237.832000 , 299.763000 ]
gcc_ddot = [77.696000  , 153.765000 , 231.348000 , 308.195000 , 385.151000 ]
gcc_saxpy = [78.032000  , 158.216000 , 230.364000 , 306.761000 , 383.734000 ]
gcc_daxpy = [103.776000 , 209.573000 , 310.813000 , 413.144000 , 517.293000 ]

icc_sscal = [5.683000  , 11.785000 , 20.011000 , 25.380000 , 30.644000 ]
icc_dscal = [11.999000 , 25.601000 , 37.013000 , 48.444000 , 59.337000 ]
icc_sdot = [18.366000 , 35.906000 , 52.773000 , 70.426000 , 86.987000 ]
icc_ddot = [36.138000  , 70.732000  , 102.953000 , 137.163000 , 172.691000 ]
icc_saxpy = [31.115000  , 59.858000  , 91.307000  , 120.422000 , 149.039000 ]
icc_daxpy = [60.476000  , 121.335000 , 178.677000 , 238.981000 , 298.794000]

#legend
legend = ['icc_sscal', 'icc_dscal', 'icc_sdot', 'icc_ddot', 'icc_saxpy', 'icc_daxpy', 'gcc_sscal', 'gcc_dscal', 'gcc_sdot', 'gcc_ddot', 'gcc_saxpy', 'gcc_daxpy']

#plot
plt.plot(vec_len, gcc_sscal, '-o', label='gcc_sscal')
plt.plot(vec_len, gcc_dscal, '-o', label='gcc_dscal')
plt.plot(vec_len, gcc_sdot, '-o', label='gcc_sdot')
plt.plot(vec_len, gcc_ddot, '-o', label='gcc_ddot')
plt.plot(vec_len, gcc_saxpy, '-o', label='gcc_saxpy')
plt.plot(vec_len, gcc_daxpy, '-o', label='gcc_daxpy')
plt.plot(vec_len, icc_sscal, '-o', label='icc_sscal')
plt.plot(vec_len, icc_dscal, '-o', label='icc_dscal')
plt.plot(vec_len, icc_sdot, '-o', label='icc_sdot')
plt.plot(vec_len, icc_ddot, '-o', label='icc_ddot')
plt.plot(vec_len, icc_saxpy, '-o', label='icc_saxpy')
plt.plot(vec_len, icc_daxpy, '-o', label='icc_daxpy')
plt.legend(legend, loc='upper left')
plt.show()