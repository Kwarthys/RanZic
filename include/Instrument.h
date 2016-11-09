#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include "XMLElement.h"

class Instrument
{
    public:
        static short GLOBAL_ID;
        Instrument();
        virtual ~Instrument();

        std::string toString(){return _descriptor->toString();}
        XMLElement * getDescriptor(){return _descriptor;}

    protected:
        std::string _name, _abreviation, _id;
        short _midiC, _midiB, _midiP, _pan, _volume, _shortid;

        XMLElement * _descriptor;

    private:
};

#endif // INSTRUMENT_H
