#include "Range.h"

Range::Range(int start, int stop) :
    start(start),
    stop(stop)
{

}

Range::~Range()
{

}

int Range::getRangeStart() const
{
    return start;
}

int Range::getRangeStop() const
{
    return stop;
}

void Range::reverseRange()
{
    int stopCopy;
    stopCopy = stop;
    stop = start;
    start = stopCopy;
}

