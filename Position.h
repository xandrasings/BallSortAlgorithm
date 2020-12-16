#ifndef __POSITION_H__
#define __POSITION_H__

class Position {
    protected:
        int var_content;
    public:
        Position (int);
        void print ();
};

class Rectangle {
    int width, height;
  public:
    Rectangle (int,int);
    int area () {return (width*height);}
};
#endif