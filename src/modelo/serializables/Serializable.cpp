//
// Created by sebas on 6/10/19.
//

#include <iostream>
#include "Serializable.h"

void
Serializable::serializarEntero (ostream & in, int entero)
{
  in << entero << endl;
}

int
Serializable::deserializarEntero (istream & stream)
{
  return stoi (deserializarString (stream));
}

void
Serializable::serializarString (ostream & in, const string & string)
{
  in << string << endl;
}

string
Serializable::deserializarString (istream & stream)
{
  string line;
  getline (stream, line);
  return line;
}

void
Serializable::serializarBoolean (ostream & in, bool boolean)
{
  in << boolean << endl;
}

bool
Serializable::deserializarBoolean (istream & stream)
{
  string line;
  getline (stream, line);
  return stoi (line);
}
