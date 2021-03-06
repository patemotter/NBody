#include "Physics.h"
#include <math.h>
#include <iostream>

//  Constants of physics calculations
const double G = 6.6726E-11;
const double EPS = 0.1;
const double DAMP = 1.1;

//  Distance between two bodies w/ dampening applied
double distance(double distances[]) {
  double dist = 0.0;
  for (int i = 0; i < 3; i++) {
    dist += distances[i]*distances[i];
  }
  return sqrt(dist + DAMP*DAMP);
}

//  Print out information for debugging purposes
void print(Body a) {
  std::cout << "Body: " << a.getNum() << std::endl;
  std::cout << "Forces " << a.getForceX() << " " << a.getForceY() << " " << a.getForceZ() << std::endl;
  std::cout << "Total force " << sqrt(a.getForceX()*a.getForceX() + 
    a.getForceY()*a.getForceY() + 
    a.getForceZ()*a.getForceZ()) << std::endl;
  std::cout << "New velocity: " << a.getVelX() << " " << a.getVelY() << " " << a.getVelZ() << std::endl;
  std::cout << "New position: " << a.getPosX() << " " << a.getPosY() << " " << a.getPosZ() << std::endl << std::endl;
}

//  Given two bodies, adjust a while treating b as a stationary body
void updateBody(Body &a, Body &b) {
  double r[3] = {b.getPosX() - a.getPosX(), b.getPosY() - a.getPosY(), b.getPosZ() - a.getPosZ()};
  double acc[3] = {0.0};
  double dist = distance(r);

  //  update force
  a.setForce( a.getForceX() + (G * r[0] * a.getMass() * b.getMass() /  pow(dist,3.0)),
  a.getForceY() + (G * r[1] * a.getMass() * b.getMass() / pow(dist,3.0)),
  a.getForceZ() + (G * r[2] * a.getMass() * b.getMass() / pow(dist,3.0)));

  //  update velocity
  for (int i = 0; i < 3; i++) {
    acc[i] = G * b.getMass() * r[i] / pow(dist,3.0);
  }
  a.setVel(a.getVelX() + acc[0], a.getVelY() + acc[1], a.getVelZ() + acc[2]);

  //  update position
  a.setPos(a.getPosX() + a.getVelX(), a.getPosY() + a.getVelY(), a.getPosZ() + a.getVelZ()); 

  //  Print new information
  //print(a, b.getMass(), dist);
}
