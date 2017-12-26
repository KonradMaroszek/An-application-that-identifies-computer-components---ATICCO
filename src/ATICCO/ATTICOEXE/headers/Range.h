#ifndef RANGE_H
#define RANGE_H

class Range
{
public:
    Range (int start, int stop);
    ~Range();

public:
    int getRangeStart() const;
    void setRangeStart(int value);

    int getRangeStop() const;
    void setRangeStop(int value);

private:
    int start;
    int stop;
};

#endif // RANGE_H
