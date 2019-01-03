#ifndef CASE_H
#define CASE_H

#include <string>

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
