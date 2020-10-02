OBJS = main.o incrementTask.o decrementTask.o fifo.o

all: app

app:$(OBJS)
	g++ -o app $(OBJS) -l pthread

%.o : src/%.cpp
	g++ -o $@ -c $< -I include