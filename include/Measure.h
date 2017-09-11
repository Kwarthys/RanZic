#ifndef MEASURE_H
#define MEASURE_H

#include "XMLElement.h"

class Measure
{
    public:
        Measure(int number);
        virtual ~Measure();

        XMLElement * getDescriptor(){return _descriptor;}

    protected:
        XMLElement * _descriptor;

    private:
};

#endif // MEASURE_H
