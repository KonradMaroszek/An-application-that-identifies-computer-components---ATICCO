#ifndef RANGE_H
#define RANGE_H

class Range
{
public:
    Range (int start, int stop);
    ~Range();

public:
    int getRangeStart() const;
    int getRangeStop() const;

    void reverseRange();

private:
    int start;
    int stop;
};

#endif // RANGE_H
