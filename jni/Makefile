
INC = -I/usr/include
INC_JNI = -I/usr/lib/jvm/jdk1.7.0_09/include -I/usr/lib/jvm/jdk1.7.0_09/include/linux

CFLAGS = -Wall -fPIC
CFLAGS_SO = -shared
CFLAGS_JNI = $(CFLAGS) $(INC_JNI)

ALL = libLoadJNI.so libHookSample.so
all: $(ALL)

libHookSample.so: hookSample.o
	g++ $(CFLAGS_SO) -o libHookSample.so hookSample.o -ldl
hookSample.o: hookSample.cpp
	g++ $(CFLAGS_JNI) -c hookSample.cpp -o hookSample.o

libLoadJNI.so: loadJNI.o
	g++ $(CFLAGS_SO) -o libLoadJNI.so loadJNI.o
loadJNI.o: loadJNI.cpp
	g++ $(CFLAGS_JNI) -c loadJNI.cpp -o loadJNI.o

clean:
	rm -f *.o
	rm -f *.so

