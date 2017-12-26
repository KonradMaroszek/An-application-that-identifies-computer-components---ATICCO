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

void Range::setRangeStart(int value)
{
    start = value;
}

int Range::getRangeStop() const
{
    return stop;
}

void Range::setRangeStop(int value)
{
    stop = value;
}

