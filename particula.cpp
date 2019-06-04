#include "Particula.h"
#include <math.h>

Particula::Particula(double VelocidadIni, double PosIniY, double Angulo, double r, double m) : QGraphicsItem()  //Un constructor por defecto, que invoca al constructor de la clase base
{
    v0 = VelocidadIni;
    py0 = PosIniY;
    alfa = Angulo;
    rad = r;
    masa = m;
}

Particula::~Particula()  //Un destructor por defecto
{

}

QRectF Particula::boundingRect() const  //Implementacion del metodo boundingRect
{
    return QRectF(-1*rad,-1*rad,2*rad,2*rad);   // Creando el area rectangular para delimitar la Particula (es una particula circular)
}

void Particula::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)    //Implementacion del metodo paint
{
        painter->setBrush(Qt::darkGray);     // Color de relleno de la Particula
        painter->drawEllipse(boundingRect());  // Dibujando la Particula con el metodo drawEllipse y aprovechando las propiedades del rectangulo delimitador
}

void Particula::moverParticula(double dt, float vertlim)
{
    alfa = alfa *(M_PI/180);
    VX = v0+(ax*dt);
    VY = v0+(ay*dt);
    v = sqrt(pow(VX,2)+pow(VY,2));
    ax = (-0.001*pow(v,2)*pow(rad,2)*cos(alfa))/masa;
    ay = ((-0.001*pow(v,2)*pow(rad,2)*sin(alfa))/masa)-10;
    px += VX*dt + ((ax*pow(dt,2))/2);
    py += py0 + VY*dt + ((ay*pow(dt,2))/2);

    setPos(px, vertlim-py);
}

void Particula::colisionParticula(float horzlim, float vertlim)
{
    //Si la colision es con una barrera en sentido de avance horizontal (adelante o atras)
    if((px < rad) || (px > horzlim - rad))
        ax = -1*ax;

    //Si la colision es con una barrera en sentido de avance vertical (arriba o abajo)
    if((py < rad) || (py > vertlim - rad))
        VY = -1*0.5*VY;
}
