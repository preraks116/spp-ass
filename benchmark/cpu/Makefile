# indicate how the object files are to be created
# CC         := icc 
CC 		   := gcc

# CFLAGS     := -g -axCORE-AVX2 -O3 -qopenmp
# CFLAGS     := -g -axCORE-AVX2 -O3
# CFLAGS     := -g -axCORE-AVX2

CFLAGS     := -g -O3 -lm -mfma -fopenmp
# CFLAGS     := -g -O3 -lm
# CFLAGS     := -g -lm

OBJECT_FILES := benchmark.o helper.o 
benchmark: $(OBJECT_FILES)
	$(CC) $(CFLAGS) -o benchmark $(OBJECT_FILES)
benchmark.o: benchmark.c
	$(CC) $(CFLAGS) -c benchmark.c
helper.o: helper.c
	$(CC) $(CFLAGS) -c helper.c
clean:
	rm *.o
	rm benchmark
