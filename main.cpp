#include <iostream>
#include <fstream>

#include "XMLElement.h"
#include "PerlinNoise.h"
#include "Note.h"
#include "Guitar.h"
#include "Measure.h"
#include "MusicBuilder.h"

using namespace std;

int main()
{
    MusicBuilder * factory = new MusicBuilder();


    std::string idName = "identification", rigthsName = "rights", artistName = "Kwarthys";
    std::string titleName = "movement-title", title = "Try It";
    XMLElement* titre = new XMLElement(titleName);
    titre->setValue(title);
    XMLElement* id = new XMLElement(idName);
    XMLElement* owner = new XMLElement(rigthsName);
    owner->setValue(artistName);
    id->addChild(owner);

    XMLElement * partList = new XMLElement("part-list");

    XMLElement * song = new XMLElement("score-partwise");
    song->addAttribute("version=\"2.0\"");

    song->addChild(titre);
    song->addChild(id);
    song->addChild(partList);

    Guitar * guitar = new Guitar();
    Guitar * guitar2 = new Guitar();

    partList->addChild(guitar->getDescriptor());
    partList->addChild(guitar2->getDescriptor());

    XMLElement * part = new XMLElement("part");
    part->addAttribute("id=\"P0\"");

    song->addChild(part);

    Measure * measure1 = factory->getNewMeasure();

    measure1->getDescriptor()->getChildByName("attributes")->addChild(guitar->getStaffDescriptor());

    XMLElement * dir = new XMLElement("direction");
    dir->addAttribute("directive=\"yes\"");
    dir->addAttribute("placement=\"above\"");

    XMLElement * dirType = new XMLElement("direction-type");
    XMLElement * metronome = new XMLElement("metronome");
    metronome->addAttribute("default=\"40\"");
    metronome->addAttribute("parentheses=\"yes\"");
    XMLElement * beatUnit = new XMLElement("beat-unit");
    beatUnit->setValue("quarter");
    metronome->addChild(beatUnit);
    XMLElement * perMin = new XMLElement("per-minute");
    perMin->setValue("150");
    metronome->addChild(perMin);
    dirType->addChild(metronome);
    dir->addChild(dirType);
    XMLElement * sound = new XMLElement("sound");
    sound->setValue("150");
    dir->addChild(sound);

    measure1->getDescriptor()->addChild(dir);

    part->addChild(measure1->getDescriptor());

    for(int i = 0; i < 12; i++)
    {
        Measure * m = factory->getNewMeasure();
        bool measureDone = false;
        short tempCount = 0;
        while(!measureDone)
        {
            Note * n = factory->getRandomNote();
            if(tempCount + n->getDuration() <= 8)
            {
                m->getDescriptor()->addChild(n->getDescriptor());
                tempCount += n->getDuration();
            }

            if(tempCount == 8)measureDone = true;
        }
        part->addChild(m->getDescriptor());
    }
/*
    Note * note1 = new Note();
    note1->setDuration(2);
    note1->setString(6);
    note1->setFret(2);

    Note * note2 = new Note();
    note2->setDuration(1);
    note2->setString(6);
    note2->setFret(0);

    measure1->getDescriptor()->addChild(note1->getDescriptor());
    measure1->getDescriptor()->addChild(note1->getDescriptor());
    measure1->getDescriptor()->addChild(note2->getDescriptor());
    measure1->getDescriptor()->addChild(note2->getDescriptor());
    measure1->getDescriptor()->addChild(note2->getDescriptor());
    measure1->getDescriptor()->addChild(note2->getDescriptor());

    Measure * m2 = factory->getNewMeasure();
    m2->getDescriptor()->addChild(note1->getDescriptor());
    m2->getDescriptor()->addChild(note2->getDescriptor());
    m2->getDescriptor()->addChild(note2->getDescriptor());
    m2->getDescriptor()->addChild(note2->getDescriptor());
    m2->getDescriptor()->addChild(note2->getDescriptor());
    m2->getDescriptor()->addChild(note1->getDescriptor());

    part->addChild(m2->getDescriptor());
*/
    cout << song->toString() << endl << endl;

    ofstream xmlOutputFile;
    xmlOutputFile.open ("generated.xml");
    xmlOutputFile << song->toString();
    xmlOutputFile.close();

    /*
    PerlinNoise p = PerlinNoise();

    double min = 1;
    double max = 0;

    for(int x = 0; x < 100; x++)
    {
        double noise = p.noise(x*0.1,0,0)*2 - 0.5;
        if(min > noise) min = noise;
        if(max < noise) max = noise;
        cout << 0.1*x << ":" << noise << " | ";
    }

    cout << endl << "min " << min << "| max " << max << endl;
*/

    return 0;
}
