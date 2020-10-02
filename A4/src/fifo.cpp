#include <fifo.h>

Fifo::Fifo()
{
    count = 0;
}

int Fifo::get()
{
    int item = buffer[0];
    shift_forward();
    return item;
}

void Fifo::put(int item)
{
    if (is_full()) shift_forward();
    buffer[count] = item;
    count++;
}

bool Fifo::is_empty()
{
    return count == 0;
}

bool Fifo::is_full()
{
    return count == FIFO_SIZE;
}

void Fifo::reset()
{
    count = 0;
}

// Helper function

void Fifo::shift_forward()
{
    count--;
    for (int i=0; i<count; i++)
    {
        buffer[i] = buffer[i+1];
    }
}