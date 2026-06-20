#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "prototipos.h"

using namespace std;

Serpiente::Serpiente(){
    for(int i=0; i<4; i++){
        cuerpo.emplace_back((LIM_IZQ+LIM_DER)/2-i, (LIM_SUP+LIM_INF)/2);
        goToXY((LIM_IZQ+LIM_DER)/2-i, (LIM_SUP+LIM_INF)/2);
        cout<<"x";
    }
    directionX=1;
    directionY=0;
}

void Serpiente::cambiarDireccion(char tecla){
	switch (tecla){
        case 'w' : {
            if(!directionY){
                directionX=0;
                directionY=-1;
            }
            break;
		}
		case 'a' : {
            if(!directionX){
                directionX=-1;
                directionY=0;
            }
		    break;
		}
		case 's' : {
            if(!directionY){
                directionX=0;
                directionY=1;
            }
            break;
		}
		case 'd' : {
            if(!directionX){
                directionX=1;
                directionY=0;
            }
		    break;
		}
        case 'W' : {
            if(!directionY){
                directionX=0;
                directionY=-1;
            }
            break;
		}
		case 'A' : {
            if(!directionX){
                directionX=-1;
                directionY=0;
            }
            break;
		}
		case 'S' : {
            if(!directionY){
                directionX=0;
                directionY=1;
            }
            break;
		}
		case 'D' : {
            if(!directionX){
                directionX=1;
                directionY=0;
            }
            break;
		}
        case ARRIBA : {
            if(!directionY){
                directionX=0;
                directionY=-1;
            }
            break;
		}
		case IZQUIERDA : {
            if(!directionX){
                directionX=-1;
                directionY=0;
            }
		    break;
		}
		case ABAJO : {
            if(!directionY){
                directionX=0;
                directionY=1;
            }
            break;
		}
		case DERECHA : {
            if(!directionX){
                directionX=1;
                directionY=0;
            }break;
		}
	}
}

void Serpiente::mover(bool crecer) {
    Segmento nuevaCabeza = {
        cuerpo[0].x + directionX,
        cuerpo[0].y + directionY
    };
    cuerpo.insert(cuerpo.begin(), nuevaCabeza);
    goToXY(nuevaCabeza.x, nuevaCabeza.y);
    cout<<"x";
    if (!crecer){
        Segmento cola=cuerpo.back();
        goToXY(cola.x, cola.y);
        cout<<" ";
        cuerpo.pop_back();
    }
}

bool Serpiente::choque() const {
    Segmento siguiente{
        cuerpo[0].x + directionX,
        cuerpo[0].y + directionY
    };

    // Choque con paredes
    if (siguiente.x <= LIM_IZQ || siguiente.x >= LIM_DER ||
        siguiente.y <= LIM_SUP || siguiente.y >= LIM_INF) {
        return true;
    }

    // Choque con el propio cuerpo
    for (const auto& seg : cuerpo) {
        if (seg.x == siguiente.x && seg.y == siguiente.y) {
            return true;
        }
    }

    return false;
}

bool Serpiente::vaAComer(const Manzana& manzana) const {
    int nextX = cuerpo[0].x + directionX;
    int nextY = cuerpo[0].y + directionY;

    return (nextX == manzana.getCoordX() &&
            nextY == manzana.getCoordY());
}

const vector<Segmento>& Serpiente::getCuerpo() const {
    return cuerpo;
}
