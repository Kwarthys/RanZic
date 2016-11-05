#include <iostream>

#include "XMLElement.h"
#include "PerlinNoise.h"
#include "Note.h"

using namespace std;

int main()
{
    std::string name = "premier", name2 = "deux", name3 = "waow";
    XMLElement e = XMLElement(name);
    XMLElement e2 = XMLElement(name2);
    XMLElement e3 = XMLElement(name3);

    cout << "creating Note" << endl << endl;

    Note note = Note();cout << note.getDescriptor()->toString() << endl<< endl;
    note.setduration(2);cout << note.getDescriptor()->toString() << endl<< endl;
    note.setOctave(2);cout << note.getDescriptor()->toString() << endl<< endl;
    note.setFret(2);cout << note.getDescriptor()->toString() << endl<< endl;
    note.setString(6);cout << note.getDescriptor()->toString() << endl<< endl;
    note.setStep('F');cout << note.getDescriptor()->toString() << endl<< endl;

    cout << "End of Note creation" << endl << endl;

    std::string value = "Je suis le premier", value2 = "value2";
    e.setValue(value);e2.setValue(value2);
    std::string  attr = "Premier=\"1\"", at2 = "id=\"id2\"";
    e.addAttribute(attr); e2.addAttribute(at2);

    e.addChild(&e2);

    e2.addChild(&e3);

    e.addChild(note.getDescriptor());


    cout << e.toString() << endl;

    XMLElement * recup = e.getChildByName(name3);
    //cout << recup->toString() << endl;

/*
    PerlinNoise gen = PerlinNoise();
    for(double i = 0; i < 200 ; i++)
    {
        cout << gen.noise(i/10,i/100,0) << " ";
    }
*/
    return 0;
}
