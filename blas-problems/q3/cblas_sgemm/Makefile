# indicate how the object files are to be created
CC         := icc 
# CC 		   := gcc

# CFLAGS     := -g -axCORE-AVX2 -O3 -qopenmp
CFLAGS     := -g -axCORE-AVX2 -O3
# CFLAGS     := -g -axCORE-AVX2

# CFLAGS     := -g -O3 -lm -fopenmp
# CFLAGS     := -g -O3 -lm
# CFLAGS     := -g -lm

OBJECT_FILES := q3.o helper.o 
q3: $(OBJECT_FILES)
	$(CC) $(CFLAGS) -o q3 $(OBJECT_FILES)
q3.o: q3.c
	$(CC) $(CFLAGS) -c q3.c
helper.o: ../../utils/helper.c
	$(CC) $(CFLAGS) -c ../../utils/helper.c
clean:
	rm *.o
	rm q3

# OBJECT_FILES := q3-omp.o helper.o 
# q3-omp: $(OBJECT_FILES)
# 	$(CC) $(CFLAGS) -o q3-omp $(OBJECT_FILES)
# q3-omp.o: q3-omp.c
# 	$(CC) $(CFLAGS) -c q3-omp.c
# helper.o: ../../utils/helper.c
# 	$(CC) $(CFLAGS) -c ../../utils/helper.c
# clean:
# 	rm *.o
# 	rm q3-omp