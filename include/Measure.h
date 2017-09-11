#ifndef MEASURE_H
#define MEASURE_H

#include "XMLElement.h"

class Measure
{
    public:
        Measure();
        virtual ~Measure();

        XMLElement * getDescriptor(){return _descriptor;}

    protected:
        XMLElement * _descriptor;

    private:
};

#endif // MEASURE_H
