#ifndef PARTICULA_H
#define PARTICULA_H

#include <QGraphicsItem>
#include <QPainter>

class Particula : public QGraphicsItem
{
public:
    Particula(double VelocidadIni, double PosIniY, double Angulo, double r, double m);
    void moverParticula(double dt, float vertlim);
    void colisionParticula(float horzlim, float vertlim);
    double VX=0, VY=0, px=0, py=0, ax=0, ay=0, v=0;
    ~Particula();

protected:
    double v0;  //Variable para la Velocidad inicial
    double py0;  //Variable para la posicion inicial en y de la particula
    double alfa;  //Variable para el angulo del tiro parabolico
    double rad; //Variable para el radio de la particula
    double masa; //Variable para la masa de la particula

    //Estos metodos: boundingRect y paint se deben implementar, ya que son metodos virtuales puros en la clase QGraphicsItem
    QRectF boundingRect() const; //Este metodo debe implementarse para encerrar la figura en un rectangulo

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //Se implementa para dar formato a la figura
};

#endif // PARTICULA_H
