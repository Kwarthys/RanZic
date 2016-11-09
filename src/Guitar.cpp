#include "Guitar.h"

#include <iostream>

Guitar::Guitar()
{
    _name = "Electric Guitar"; _abreviation = "E-Gt";
    XMLElement * nameXML = new XMLElement("part-name");
    nameXML->setValue(_name);
    XMLElement * abrevXML = new XMLElement("part-abbreviation");
    abrevXML->setValue(_abreviation);

    _descriptor->addChild(nameXML);
    _descriptor->addChild(abrevXML);

    _midiC = _shortid + 1; _midiB = 1; _midiP = 30 + _shortid; _volume = 80; _pan = 0;

    XMLElement * midiInstru = _descriptor->getChildByName("midi-instrument");
    midiInstru->addChild(new XMLElement("midi-channel", std::to_string(_midiC)));
    midiInstru->addChild(new XMLElement("midi-bank", std::to_string(_midiB)));
    midiInstru->addChild(new XMLElement("midi-program", std::to_string(_midiP)));
    midiInstru->addChild(new XMLElement("volume", std::to_string(_volume)));
    midiInstru->addChild(new XMLElement("pan", std::to_string(_pan)));

    _staffDescriptor = new XMLElement("staff-details");
    _staffDescriptor->addChild(new XMLElement("staff-lines","6"));

    std::string p[6][2] = {{"E","2"}, {"A", "2"} , {"D", "3"} , {"G", "3"} , {"B", "3"}, {"E","4"}};

    std::cout << "Starting deathloop" << std::endl << std::endl;

    for(int i = 1; i <= 6 ; i++)
    {
        std::cout << "In deathloop" << std::endl;
        XMLElement * line = new XMLElement("staff-tuning");
        line->addAttribute(std::string("line=\"" + std::to_string(i) + "\""));
        line->addChild(new XMLElement("tuning-step", p[i-1][0]));
        line->addChild(new XMLElement("tuning-octave", p[i-1][1]));
        _staffDescriptor->addChild(line);
    }
}

Guitar::~Guitar()
{
    //dtor
    delete(_staffDescriptor);
}
