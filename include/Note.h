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

        void setStep(char c);
        void setOctave(short s);
        void setduration(short s);
        void setString(short s);
        void setFret(short s);

        XMLElement * getDescriptor(){return _descriptor;}

    protected:

    private:
        char _step;
        short _octave;
        short _duration;
        short _string, _fret;

        XMLElement * _descriptor;
};

#endif // NOTE_H
