#ifndef COORDENADA_H
#define COORDENADA_H


class Coordenada{
private:
    int x;
    int y;
public:
    Coordenada();
    Coordenada(int x, int y);
    ~Coordenada();

    int getX();
    int getY();
    void setX(int x);
    void setY(int y);

    void down();
    void up();
    void left();
    void right();
};

#endif // COORDENADA_H
