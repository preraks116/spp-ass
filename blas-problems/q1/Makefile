# indicate how the object files are to be created
CC         := icc 
# CC 		   := gcc
# CFLAGS     := -g -O3 -lm
# CFLAGS     := -g -lm
CFLAGS     := -g -axCORE-AVX2 -O3

OBJECT_FILES := q1.o helper.o 
q1: $(OBJECT_FILES)
	$(CC) $(CFLAGS) -o q1 $(OBJECT_FILES)
q1.o: q1.c
	$(CC) $(CFLAGS) -c q1.c
helper.o: ../utils/helper.c
	$(CC) $(CFLAGS) -c ../utils/helper.c
clean:
	rm *.o
	rm q1