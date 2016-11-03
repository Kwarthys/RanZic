#include <iostream>

#include "XMLElement.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    std::string name = "premier", name2 = "deux";
    XMLElement e = XMLElement(name);
    XMLElement e2 = XMLElement(name2);

    std::string value = "Je suis le premier", value2 = "value2";
    e.setValue(value);e2.setValue(value2);
    std::string  attr = "Premier=\"1\"", at2 = "id=\"id2\"";
    e.addAttribute(attr); e2.addAttribute(at2);

    e.addChild(e2);

    cout << e.toString();

    return 0;
}
