#include "XMLElement.h"

XMLElement::XMLElement(std::string & name)
{
    //ctor
    _name = new std::string(name);
}

XMLElement::~XMLElement()
{
    //dtor
}

std::string XMLElement::toString()
{
    std::string ret = "";
    ret += "<" + *_name + " ";

    for(unsigned int i = 0; i < _attributes.size(); i++)
    {
        ret += *(_attributes.at(i)) + " ";
    }
    ret += ">\r\n";

    if(_value->size() > 0)
    {
        ret+= *_value + "\r\n";
    }

    for(unsigned int i = 0; i < _childs.size(); i++)
    {
        ret += (_childs.at(i))->toString();
    }

    ret += "</" + *_name + ">\r\n";
    return ret;
}

void XMLElement::addChild(XMLElement& e )
{
    _childs.push_back(new XMLElement(e));
}

void XMLElement::addAttribute(std::string& s )
{
    _attributes.push_back(new std::string(s));
}

void XMLElement::setValue(std::string& s )
{
    _value = new std::string(s);
}
