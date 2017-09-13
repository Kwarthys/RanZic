#ifndef NOTE_H
#define NOTE_H

#include "XMLElement.h"
#include <string>
/*
<note>
    <pitch>
         <step>F</step>
         <octave>2</octave>
    </pitch>
    <duration>2</duration>
    <notations>
         <technical>
            <string>6</string>
            <fret>1</fret>
         </technical>
    </notations>
</note>
*/
class Note
{
    public:
        Note();
        virtual ~Note();

        void setFret(short s);
        void setDuration(short s);
        void setString(short s);

        std::string toString(){return _descriptor->toString();}

        XMLElement * getDescriptor(){return _descriptor;}

        short getDuration(){return _duration;}
        short getString(){return _string;}
        short getFret(){return _fret;}

    protected:

    private:
        short _duration, _string, _fret;

        XMLElement * _descriptor;
};

#endif // NOTE_H
