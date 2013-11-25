TARGET := rwlock
CC := g++
SRCS := main.cpp rwlock.cpp
HDRS := rwlock.h
OBJS := $(SRCS:.cpp=.o)
CXXFLAG := -std=c++11

.SUFFIXES: .cpp .o
.PHONY: clean run
$(TARGET) : $(OBJS)
	$(CC) -Wall -o $@ $(OBJS)
	echo $@

$(OBJS) : $(HDRS)

.cpp.o:
	$(CC) $(CXXFLAG) -Wall -c $<

run:
	make
	./$(TARGET)
clean:
	-rm *.o
	-rm $(TARGET)
