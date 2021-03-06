#include "Arbol.h"

Arbol::Arbol() {
    nulo = new Nodo;
    nulo->setColor(0);
    nulo->setIzquierdo(nullptr);
    nulo->setDerecho(nullptr);
    raiz = nulo;
}
/**
 * @brief Arbol insertar
 * 
 * @param dato 
 */
void Arbol::insertar(int dato) {
    Nodo* nuevo = new Nodo(dato);
    nuevo->setPadre(nullptr);
    nuevo->setIzquierdo(nulo);
    nuevo->setDerecho(nulo);
    nuevo->setColor(1);

    Nodo* y = nullptr;
    Nodo* x = raiz;

    while (x != nulo) {
        y = x;
        if (nuevo->getDato() < x->getDato()) {
            x = x->getIzquierdo();
        }
        else {
            x = x->getDerecho();
        }
    }

    nuevo->setPadre(y);
    if (y == nullptr) {
        raiz = nuevo;
    }
    else if (nuevo->getDato() < y->getDato()) {
        y->setIzquierdo(nuevo);
    }
    else {
        y->setDerecho(nuevo);
    }

    if (nuevo->getPadre() == nullptr) {
        nuevo->setColor(0);
        return;
    }

    if (nuevo->getPadre()->getPadre() == nullptr) {
        return;
    }

    arreglar(nuevo);
}
/**
 * @brief Arbol buscar
 * 
 * @param nodo 
 * @param valor 
 * @return true 
 * @return false 
 */
bool Arbol::buscar(Nodo* nodo, int valor) {
    bool verificador;
    if (nodo == nulo || valor == nodo->getDato()) {
        if (nodo != nulo)
        {
            verificador = false;
        }
        else {
            verificador = true;
        }

        return verificador;
    }

    if (valor < nodo->getDato()) {
        return buscar(nodo->getIzquierdo(), valor);
    }
    return buscar(nodo->getDerecho(), valor);
}
/**
 * @brief Arbol eliminar
 * 
 * @param dato 
 */
void Arbol::eliminar(int dato) {
    Nodo* z = nulo;
    Nodo* x, * y;
    Nodo* aux = raiz;

    while (aux != nulo) {
        if (aux->getDato() == dato) {
            z = aux;
        }

        if (aux->getDato() <= dato) {
            aux = aux->getDerecho();
        }
        else {
            aux = aux->getIzquierdo();
        }
    }

    if (z == nulo) {
        cout << "Dato no encontrado" << endl;
        return;
    }

    y = z;
    int color = y->getColor();
    if (z->getDerecho() == nulo) {
        x = z->getDerecho();
        intercambiar(z, z->getDerecho());
    }
    else if (z->getDerecho() == nulo) {
        x = z->getIzquierdo();
        intercambiar(z, z->getIzquierdo());
    }
    else {

        y = obtenerMinimo(z->getDerecho());
        color = y->getColor();
        x = y->getDerecho();
        if (y->getPadre() == z) {
            x->setPadre(y);
        }
        else {
            intercambiar(y, y->getDerecho());
            y->setDerecho(z->getDerecho());
            y->getDerecho()->setPadre(y);
        }

        intercambiar(z, y);
        y->setIzquierdo(z->getIzquierdo());
        y->getIzquierdo()->setPadre(y);
        y->setColor(z->getColor());
    }
    delete z;
    if (color == 0) {
        arreglarEliminar(x);
    }

}
/**
 * @brief Arbol rotar izquierda
 * 
 * @param nodo 
 */
void Arbol::rotarIzquierda(Nodo* nodo) {

    Nodo* y = nodo->getDerecho();
    nodo->setDerecho(y->getIzquierdo());
    if (y->getIzquierdo() != nulo) {
        y->getIzquierdo()->setPadre(nodo);
    }
    y->setPadre(nodo->getPadre());

    if (nodo->getPadre() == nullptr) {
        raiz = y;
    }
    else if (nodo == nodo->getPadre()->getIzquierdo()) {
        nodo->getPadre()->setIzquierdo(y);
    }
    else {
        nodo->getPadre()->setDerecho(y);
    }
    y->setIzquierdo(nodo);
    nodo->setPadre(y);
}
/**
 * @brief Arbol rotar derecha
 * 
 * @param nodo 
 */
void Arbol::rotarDerecha(Nodo* nodo) {

    Nodo* y = nodo->getIzquierdo();
    nodo->setIzquierdo(y->getDerecho());
    if (y->getDerecho() != nulo) {
        y->getDerecho()->setPadre(nodo);
    }
    y->setPadre(nodo->getPadre());

    if (nodo->getPadre() == nullptr) {
        raiz = y;
    }
    else if (nodo == nodo->getPadre()->getDerecho()) {
        nodo->getPadre()->setDerecho(y);
    }
    else {
        nodo->getPadre()->setIzquierdo(y);
    }
    y->setDerecho(nodo);
    nodo->setPadre(y);
}
/**
 * @brief Arbol arreglar
 * 
 * @param nodo 
 */
void Arbol::arreglar(Nodo* nodo) {

    Nodo* aux;
    while (nodo->getPadre()->getColor() == 1) {
        if (nodo->getPadre() == nodo->getPadre()->getPadre()->getDerecho()) {
            aux = nodo->getPadre()->getPadre()->getIzquierdo();
            if (aux->getColor() == 1) {
                aux->setColor(0);
                nodo->getPadre()->setColor(0);
                nodo->getPadre()->getPadre()->setColor(1);
                nodo = nodo->getPadre()->getPadre();
            }
            else {
                if (nodo == nodo->getPadre()->getIzquierdo()) {
                    nodo = nodo->getPadre();
                    rotarDerecha(nodo);
                }
                nodo->getPadre()->setColor(0);
                nodo->getPadre()->getPadre()->setColor(1);
                rotarIzquierda(nodo->getPadre()->getPadre());
            }
        }
        else {
            aux = nodo->getPadre()->getPadre()->getDerecho();

            if (aux->getColor() == 1) {
                aux->setColor(0);
                nodo->getPadre()->setColor(0);
                nodo->getPadre()->getPadre()->setColor(1);
                nodo = nodo->getPadre()->getPadre();
            }
            else {
                if (nodo == nodo->getPadre()->getDerecho()) {
                    nodo = nodo->getPadre();
                    rotarIzquierda(nodo);
                }
                nodo->getPadre()->setColor(0);
                nodo->getPadre()->getPadre()->setColor(1);
                rotarDerecha(nodo->getPadre()->getPadre());
            }
        }
        if (nodo == raiz) {
            break;
        }
    }
    raiz->setColor(0);


}
/**
 * @brief Arbol areglar eliminar
 * 
 * @param nodo 
 */
void Arbol::arreglarEliminar(Nodo* nodo) {
    Nodo* s;

    while (nodo != raiz && nodo->getColor() == 0) {
        if (nodo == nodo->getPadre()->getIzquierdo()) {
            s = nodo->getPadre()->getDerecho();
            if (s->getColor() == 1) {
                s->setColor(0);
                nodo->getPadre()->setColor(1);
                rotarIzquierda(nodo->getPadre());
                s = nodo->getPadre()->getDerecho();
            }

            if (s->getIzquierdo()->getColor() == 0 && s->getDerecho()->getColor() == 0) {
                s->setColor(1);
                nodo = nodo->getPadre();
            }
            else {
                if (s->getDerecho()->getColor() == 0) {
                    s->getIzquierdo()->setColor(0);
                    s->setColor(1);
                    rotarDerecha(s);
                    s = nodo->getPadre()->getDerecho();
                }

                s->setColor(nodo->getPadre()->getColor());
                nodo->getPadre()->setColor(0);
                s->getDerecho()->setColor(0);
                rotarIzquierda(nodo->getPadre());
                nodo = raiz;
            }
        }
        else {
            s = nodo->getPadre()->getIzquierdo();
            if (s->getColor() == 1) {
                s->setColor(0);
                nodo->getPadre()->setColor(1);
                rotarDerecha(nodo->getPadre());
                s = nodo->getPadre()->getIzquierdo();
            }

            if (s->getDerecho()->getColor() == 0 && s->getDerecho()->getColor() == 0) {
                s->setColor(1);
                nodo = nodo->getPadre();
            }
            else {
                if (s->getIzquierdo()->getColor() == 0) {
                    s->getDerecho()->setColor(0);
                    s->setColor(1);
                    rotarIzquierda(s);
                    s = nodo->getPadre()->getIzquierdo();
                }

                s->setColor(nodo->getPadre()->getColor());
                nodo->getPadre()->setColor(0);
                s->getIzquierdo()->setColor(0);
                rotarDerecha(nodo->getPadre());
                nodo = raiz;
            }
        }
    }
    nodo->setColor(0);
}



// void Arbol::preOrden(Nodo *nodo){
//     if (nodo != nullptr)
//     {
//         cout << nodo->dato << " ";
//         preOrden(nodo->izquierdo);
//         preOrden(nodo->derecho);
//     }

// }

// void Arbol::inOrden(Nodo *nodo){
//     if (nodo != nullptr)
//     {
//         inOrden(nodo->izquierdo);
//         cout << nodo->dato << " ";
//         inOrden(nodo->derecho);
//     }

// }

// void Arbol::postOrden(Nodo *nodo){
//     if (nodo != nullptr)
//     {
//         postOrden(nodo->izquierdo);
//         postOrden(nodo->derecho);
//         cout << nodo->dato << " ";
//     }


// }

/**
 * @brief Mostrar arbol
 * 
 * @param raiz 
 * @param index 
 * @param last 
 */
void Arbol::mostrarArbol(Nodo* raiz, string index, bool last) {
    if (raiz != nulo) {
        cout << index;
        if (last) {
            cout << "R----";
            index += "   ";
        }
        else {
            cout << "L----";
            index += "|  ";
        }

        string sColor = raiz->getColor() ? "RED" : "BLACK";
        cout << raiz->getDato() << "(" << sColor << ")" << endl;
        mostrarArbol(raiz->getIzquierdo(), index, false);
        mostrarArbol(raiz->getDerecho(), index, true);
    }
}

Nodo* Arbol::getRaiz() {
    return raiz;
}
/**
 * @brief Arbol intercambiar
 * 
 * @param nodo1 
 * @param nodo2 
 */
void Arbol::intercambiar(Nodo* nodo1, Nodo* nodo2) {

    if (nodo1->getPadre() == nullptr)
    {
        raiz = nodo2;
    }
    else if (nodo1 == nodo1->getPadre()->getIzquierdo())
    {
        nodo1->getPadre()->setIzquierdo(nodo2);
    }
    else
    {
        nodo1->getPadre()->setDerecho(nodo2);
    }

    nodo2->setPadre(nodo1->getPadre());


}
/**
 * @brief Obtencion minimo
 * 
 * @param nodo 
 * @return Nodo* 
 */
Nodo* Arbol::obtenerMinimo(Nodo* nodo) {

    while (nodo->getIzquierdo() != nulo)
    {
        nodo = nodo->getIzquierdo();
    }

    return nodo;

}
/**
 * @brief Generar grafico de arbol
 * 
 * @param nombre 
 */
void Arbol::generarGrafico(string nombre) {

    cout << "\n";
    archivo.open(nombre + ".dot", ios::out);
    archivo << "graph G {\n";
    graficarArbol(raiz);
    archivo << "}";
    archivo.close();
   
    system(("dot.exe -Tpng "  + nombre + ".dot"  + " " + "-o" + " " + nombre + ".png").c_str());
    //remove((ruta + nombre + ".png").c_str());
    //remove((ruta + nombre + ".dot").c_str());
    remove((ruta + "\\" + nombre + "\\" + nombre + ".png").c_str());
    rename((ruta + "\\" + nombre + ".png").c_str(), (ruta + "\\" + nombre + "\\" + nombre + ".png").c_str());
    remove((ruta + "\\" + nombre + ".dot").c_str());
    remove((ruta + "\\" + nombre + ".png").c_str());

}

/**
 * @brief Graficar arbol
 * 
 * @param nodo 
 */

void Arbol::graficarArbol(Nodo* nodo) {
    if (nodo == nulo)
    {
        return;
    }
    if (nodo->getColor())
    {
        archivo << "x" << nodo << "[label=\"" << nodo->getDato() << "\",style=filled,fillcolor=lightcoral];" << endl;
    }
    else {
        archivo << "x" << nodo << "[label=\"" << nodo->getDato() << "\",style=filled,fillcolor=gray];" << endl;
    }


    if (nodo->getIzquierdo() != nulo)
    {

        archivo << "x" << nodo << "--" << "x" << nodo->getIzquierdo() << "[arrowhead = normaltee];" << endl;
    }

    if (nodo->getDerecho() != nulo)
    {
        archivo << "x" << nodo << "--" << "x" << nodo->getDerecho() << "[arrowhead = normaltee];" << endl;
    }

    graficarArbol(nodo->getIzquierdo());
    graficarArbol(nodo->getDerecho());
}

/**
 * @brief Arbol en preOrden
 * 
 * @param nodo 
 */
void Arbol::preOrden(Nodo* nodo) {

    if (nodo != nullptr) {
        if (nodo->getDato() != 0)
        {
            cout << nodo->getDato() << " ";
        }


        preOrden(nodo->getIzquierdo());
        preOrden(nodo->getDerecho());
    }

}
/**
 * @brief Arbol en Inorden
 * 
 * @param nodo 
 */
void Arbol::inOrden(Nodo* nodo) {
    if (nodo != nullptr) {
        inOrden(nodo->getIzquierdo());
        if (nodo->getDato() != 0)
        {
            cout << nodo->getDato() << " ";
        }
        inOrden(nodo->getDerecho());
    }
}
/**
 * @brief Arbol en postOrden
 * 
 * @param nodo 
 */
void Arbol::postOrden(Nodo* nodo) {
    if (nodo != nullptr) {
        postOrden(nodo->getIzquierdo());
        postOrden(nodo->getDerecho());
        if (nodo->getDato() != 0)
        {
            cout << nodo->getDato() << " ";
        }
    }
}


/**
 * @brief Arbol borrar
 * 
 */
void Arbol::borrarArbol() {
    nulo = new Nodo;
    nulo->setColor(0);
    nulo->setIzquierdo(nullptr);
    nulo->setDerecho(nullptr);
    raiz = nulo;
}