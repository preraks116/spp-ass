# indicate how the object files are to be created
# CC         := icc 
CC 		   := gcc

# CFLAGS     := -g -axCORE-AVX2 -O3 -qopenmp
# CFLAGS     := -g -axCORE-AVX2 -O3
# CFLAGS     := -g -axCORE-AVX2

# CFLAGS     := -g -O3 -lm -fopenmp
# CFLAGS     := -g -O3 -lm
CFLAGS     := -g -lm

OBJECT_FILES := q2.o helper.o 
q2: $(OBJECT_FILES)
	$(CC) $(CFLAGS) -o q2 $(OBJECT_FILES)
q2.o: q2.c
	$(CC) $(CFLAGS) -c q2.c
helper.o: ../../utils/helper.c
	$(CC) $(CFLAGS) -c ../../utils/helper.c
clean:
	rm *.o
	rm q2

# OBJECT_FILES := q2-omp.o helper.o 
# q2-omp: $(OBJECT_FILES)
# 	$(CC) $(CFLAGS) -o q2-omp $(OBJECT_FILES)
# q2-omp.o: q2-omp.c
# 	$(CC) $(CFLAGS) -c q2-omp.c
# helper.o: ../../utils/helper.c
# 	$(CC) $(CFLAGS) -c ../../utils/helper.c
# clean:
# 	rm *.o
# 	rm q2-omp