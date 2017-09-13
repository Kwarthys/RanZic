#include "Note.h"
#include <iostream>

Note::Note()
{
    //ctor
    std::string note = "note", pitchName = "pitch";
    _descriptor = new XMLElement(note);
    XMLElement * pitch = new XMLElement(pitchName);
    XMLElement * step = new XMLElement("step", "E");
    XMLElement * octave = new XMLElement("octave", "2");

    pitch->addChild(step);
    pitch->addChild(octave);

    XMLElement * notations = new XMLElement("notations");
    XMLElement * technical = new XMLElement("technical");

    notations->addChild(technical);

    _descriptor->addChild(pitch);
    _descriptor->addChild(notations);
}

void Note::setFret(short f)
{
    if(_fret == f)return;
    else
    {
        if(_descriptor->getChildByName("fret") != nullptr)
        {
            _descriptor->getChildByName("fret")->setValue(std::to_string(f));
        }
        else
        {
            _fret = f;
            XMLElement * fret = new XMLElement("fret", std::to_string(f));
            _descriptor->getChildByName("technical")->addChild(fret);
        }
    }
}

void Note::setString(short s)
{
    if(_string == s)return;
    else
    {
        if(_descriptor->getChildByName("string") != nullptr)
        {
            _descriptor->getChildByName("string")->setValue(std::to_string(s));
        }
        else
        {
            _string = s;
            XMLElement * str = new XMLElement("string", std::to_string(s));
            _descriptor->getChildByName("technical")->addChild(str);
        }
    }
}

void Note::setDuration(short s)
{
    _duration = s;
    std::string durationName = "duration", durationValue = std::to_string(s);
    XMLElement * duration = new XMLElement(durationName);
    duration->setValue(durationValue);
    _descriptor->addChild(duration);
}

Note::~Note()
{
    //dtor
    delete(_descriptor);
}
