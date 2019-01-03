#ifndef CASE_H
#define CASE_H

#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Case
{
  public:
    Case();
    Case(int posX, int posY, char status);
    virtual ~Case();
    const Case& operator=(const Case& other);
    char getStatus() const;
    int getPosX() const;
    int getPosY() const;
    void setPos(int posX, int posY);
    void setStatus(char status);

  protected:
    int _posX;
    int _posY;
//    Case& _top;
//    Case& _bottom;
//    Case& _left;
//    Case& _right;
    char _status;

  private:
};

#endif // CASE_H
