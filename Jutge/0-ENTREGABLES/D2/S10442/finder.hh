#ifndef FINDER_HH
#define FINDER_HH

#include "geometry.hh"

//*diferencias
//* const T *; puntero a obj T
//* const T *t; (lo mismo solo que aqui guardas ese puntero en t)


template <class T>
// Finder<T> para acceder a cualquier clase
class Finder {
    private:

        // relacio obj(individual) amb les seves coordenades

        //ens serveix per tenir juntes les coordenades d'un sol obj

        //MIRAR SI NO FA FALTA IGUAL NO
        std::map<const T*, std::set<std::pair<int, int>>> items_coords_;
       
        // relacio coordenades amb conjunts d'objs que estan allà

        //ens serveix per tenir una graella de coordenades amb tots els objectes
        std::map<std::pair<int, int>, std::set<const T*>>    grid_;
    
    public:
        Finder();

        void add(const T *t)
        {
            //agafem tipus de obj items_coords[]
            //afegim el punter *t a les celles que pertoquen
            //aixo amb funcio
        }

        void update(const T *t)
        {
            //remove
            //add
        }
        
        void remove(const T *t)
        {
            //borrem desde les coords
        }

        std::set<const T *> query(pro2::Rect qrect) const
        {
            //
        }
};
#endif


//* pensar en t com a tipus de obj (coin) que te get_rect() per obtenir les seves coordenades


// * El rectangle màxim de l’espai bidimensional és (0, 0, 20000, 20000)

//* obj no pot tenir un rectangle amb amplada o alçada major que 2000.