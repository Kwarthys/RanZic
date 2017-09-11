#include "Measure.h"

Measure::Measure(int number)
{
    _descriptor = new XMLElement("measure");
    _descriptor->addAttribute("number=\"" + std::to_string(number) + "\"");

    XMLElement * attr = new XMLElement("attributes");

    XMLElement * div = new XMLElement("divisions");
    div->setValue("2");
    attr->addChild(div);

    XMLElement * time = new XMLElement("time");
    XMLElement * beats = new XMLElement("beats");
    beats->setValue("4");
    XMLElement * beatType = new XMLElement("beat-type");
    beatType->setValue("4");

    time->addChild(beats);
    time->addChild(beatType);

    attr->addChild(time);

    _descriptor->addChild(attr);
}

    /*
  <measure number="0">
   <attributes>
    <divisions>2</divisions>
    <key>
     <fifths>0</fifths>
     <mode>major</mode>
    </key>
    <time>
     <beats>4</beats>
     <beat-type>4</beat-type>
    </time>
    <clef>
     <sign>TAB</sign>
     <line>5</line>
    </clef>
    <staff-details>
    */

Measure::~Measure()
{
    //dtor
    delete(_descriptor);
}
