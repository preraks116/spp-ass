# indicate how the object files are to be created
CC         := icc 
# CC 		   := gcc

# CFLAGS     := -g -axCORE-AVX2 -O3 -qopenmp
# CFLAGS     := -g -axCORE-AVX2 -O3
CFLAGS     := -g -axCORE-AVX2

# CFLAGS     := -g -O3 -lm -fopenmp	
# CFLAGS     := -g -O3 -lm
# CFLAGS     := -g -lm

# OBJECT_FILES := stencil.o helper.o 
# stencil: $(OBJECT_FILES)
# 	$(CC) $(CFLAGS) -o stencil $(OBJECT_FILES)
# stencil.o: stencil.c
# 	$(CC) $(CFLAGS) -c stencil.c
# helper.o: helper.c
# 	$(CC) $(CFLAGS) -c helper.c
# clean:
# 	rm *.o
# 	rm stencil

OBJECT_FILES := stencil-omp.o helper.o 
stencil-omp: $(OBJECT_FILES)
	$(CC) $(CFLAGS) -o stencil-omp $(OBJECT_FILES)
stencil-omp.o: stencil-omp.c
	$(CC) $(CFLAGS) -c stencil-omp.c
helper.o: helper.c
	$(CC) $(CFLAGS) -c helper.c
clean:
	rm *.o
	rm stencil-omp