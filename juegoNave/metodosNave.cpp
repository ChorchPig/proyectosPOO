#include <stdio.h>
#include <windows.h>
#include "prototipos.h"

using namespace std;

Nave::Nave(int _x, int _y, int _vidas){
    coordX=_x;
    coordY=_y;
    vidas=_vidas;
}

Nave::~Nave(){ }

void Nave::pintar(){
    goToXY(this->coordX, this->coordY);
    printf("  %c", 94);
    goToXY(this->coordX, this->coordY+1);
    printf(" %c%c%c", 40, 207, 41);
    goToXY(this->coordX, this->coordY+2);
    printf("%c%c %c%c", 190, 238, 238, 190);
}

void Nave::borrar(){
    goToXY(this->coordX, this->coordY);
    printf("     ");
    goToXY(this->coordX, this->coordY+1);
    printf("     ");
    goToXY(this->coordX, this->coordY+2);
    printf("     ");
}

void Nave::actuar(char tecla){
	borrar();
	switch (tecla){
        case 'w' : {
            if(coordY>LIM_SUP+1)
                coordY--;
		    break;
		}
		case 'a' : {
            if(coordX>LIM_IZQ+1)
                coordX--;
            break;
		}
		case 's' : {
		    if(coordY<LIM_INF-3)
                coordY++;
            break;
		}
		case 'd' : {
            if(coordX<LIM_DER-5)
                coordX++;
            break;
		}
        case 'W' : {
            if(coordY>LIM_SUP+1)
                coordY--;
		    break;
		}
		case 'A' : {
            if(coordX>LIM_IZQ+1)
                coordX--;
            break;
		}
		case 'S' : {
		    if(coordY<LIM_INF-3)
                coordY++;
            break;
		}
		case 'D' : {
            if(coordX<LIM_DER-5)
                coordX++;
            break;
		}
		case ARRIBA : {
		    if(coordY>LIM_SUP+1)
                coordY--;
		    break;
		}
		case IZQUIERDA : {
            if(coordX>LIM_IZQ+1)
                coordX--;
            break;
		}
		case ABAJO : {
		    if(coordY<LIM_INF-3)
                coordY++;
            break;
		}
		case DERECHA : {
            if(coordX<LIM_DER-5)
                coordX++;
            break;
		}
		case ESPACIO : balas.push_back(balas.emplace_back(coordX+2, coordY-1)); break;
    }
	pintar();
}

void Nave::mostrarVidas(){
    goToXY(LIM_DER-10, LIM_SUP-1);
    printf("Vidas:        ");
    for(int i=0; i<vidas; i++){
        goToXY(LIM_DER-4+i, LIM_SUP-1);
        printf("%c", 43); //quiero usar el caracter alt+3, ¿cómo lo hago?
    }
}

void Nave::perderVida(){
    vidas--;
    borrar();
    Sleep(200);
    pintar();
    Sleep(200);
    borrar();
    Sleep(200);
    pintar();
    Sleep(200);
}

int Nave::getVidas()const{ return vidas; }

int Nave::getX()const{ return coordX; }

int Nave::getY()const{ return coordY; }

bool Nave::choqueNaveAst(list<Asteroid> &asteroides){
    bool result=false;
    auto it=begin(asteroides);
    while(!result&&it!=end(asteroides)){
            if((*it).getX()==coordX+2&&(*it).getY()==coordY){
                (*it).reiniciarPosicion();
                result=true;
            }
            if((*it).getX()>=coordX+1&&(*it).getX()<=coordX+3&&(*it).getY()==coordY+1){
                (*it).reiniciarPosicion();
                result=true;
            }
            if((*it).getX()>=coordX&&(*it).getX()<=coordX+4&&(*it).getY()==coordY+2){
                (*it).reiniciarPosicion();
                result=true;
            }
            it++;
    }
    return result;
}

void Nave::moverBalas(){
    for(auto it=balas.begin(); it!=balas.end(); it++){
        (*it).mover();
        if((*it).fuera()){
            goToXY((*it).getX(), (*it).getY());
            printf(" ");
            it=balas.erase(it);
        }
    }
}

bool Nave::choqueBalaAst(list<Asteroid>& asteroides){
    bool impacto = false;
    for (auto itBala = balas.begin(); itBala != balas.end(); ){
        for (auto& ast : asteroides){
            if (itBala->getX() == ast.getX() &&
                itBala->getY() == ast.getY())
            {
                goToXY(ast.getX(), ast.getY());
                printf(" ");
                ast.reiniciarPosicion();
                impacto = true;
                break;
            }
            if (itBala->getX() == ast.getX() &&
                itBala->getY() == ast.getY()+1)
            {
                goToXY(ast.getX(), ast.getY());
                printf(" ");
                goToXY(ast.getX(), ast.getY()+1);
                printf(" ");
                ast.reiniciarPosicion();
                impacto = true;
                break;
            }
        }
        if (impacto)
            itBala = balas.erase(itBala);
        else
            ++itBala;
    }
    return impacto;
}

