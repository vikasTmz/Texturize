CC = g++
CFLAGS = -Wall
PROG = exe

MATLABROOT = "/usr/local/MATLAB/MATLAB_Production_Server/R2015a"

SRCS = TextureTransfer.cpp
LIBS = -I/usr/local/MATLAB/MATLAB_Production_Server/R2015a/extern/include/ -L${MATLABROOT}/extern/lib/glnxa64/ -I"/usr/local/MATLAB/MATLAB_Production_Server/R2015a/simulink/include" -I"/usr/local/MATLAB/MATLAB_Production_Server/R2015a/extern/include/cpp" -fPIC -ansi -pthread -O -DNDEBUG -shared -O   -L"/usr/local/MATLAB/MATLAB_Production_Server/R2015a/runtime/glnxa64" -lm -lmwmclmcrrt


all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG)