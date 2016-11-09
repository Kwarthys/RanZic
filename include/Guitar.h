#ifndef GUITAR_H
#define GUITAR_H

#include "Instrument.h"

class Guitar : public Instrument
{
    public:
        Guitar();
        virtual ~Guitar();

        XMLElement * getStaffDescriptor(){return _staffDescriptor;}

    protected:
        XMLElement * _staffDescriptor;

    private:
};

#endif // GUITAR_H
