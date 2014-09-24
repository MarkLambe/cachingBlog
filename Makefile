COMPILER = g++


all: main.o ce_matrix.o cf_matrix.o ce_matrix.o cv_matrix.o
	$(COMPILER) main.o cv_matrix.o ce_matrix.o cf_matrix.o -o cache_demo


main.o: main.cpp
	$(COMPILER) -c main.cpp

cf_matrix.o: cf_matrix.cpp
	$(COMPILER) -c cf_matrix.cpp

ce_matrix.o: ce_matrix.cpp
	$(COMPILER) -c ce_matrix.cpp

cv_matrix.o: cv_matrix.cpp
	$(COMPILER) -c cv_matrix.cpp

clean:
	rm *.o cache_demo