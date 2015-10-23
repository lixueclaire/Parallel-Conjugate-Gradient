parallel conjugate gradient solver
===================================
This is a conjugate gradient solver for large sparse matrix. ie, to get x in Ax = b.
Read data from "matrix", save result in "ans".

### generate N*N matrix
		python Random_matrix.py N

### serial algorithm
		g++ CPU_Conjugate.cpp -o cpu_conjugate
		./cpu_conjugate N -t -d

### parallel algorithm
		mpic++ MPI_Conjugate.cpp -o mpi_conjugate
		mpiexec -n 2 ./mpi_conjugate N -t -d

### validate if the result is right
		g++ Validation.cpp -o validation
		./validation
