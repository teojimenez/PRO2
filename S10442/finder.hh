#ifndef FINDER_HH
#define FINDER_HH

#include "geometry.hh"
#include <map>
#include <set>

//*diferencias
//* const T *; puntero a obj T
//* const T *t; (lo mismo solo que aqui guardas ese puntero en t)


// Finder<T> para acceder a cualquier clase
template <class T>
class Finder {
    private:

        // relacio obj(individual) amb les seves coordenades

        //ens serveix per tenir juntes les coordenades d'un sol obj

        //MIRAR SI NO FA FALTA IGUAL NO
        std::map<const T*, std::set<std::pair<int, int>>> individual_items_coords_;

        // relacio coordenades amb conjunts d'objs que estan allà

        //ens serveix per tenir una graella de coordenades amb tots els objectes
        std::map<std::pair<int, int>, std::set<const T*>>    coords_map_;


        bool obj_inside(pro2::Rect a, pro2::Rect b) const 
        {
            //CUANDO NO ESTA FUERA
            return !(a.right  < b.left   ||
                    a.left   > b.right  ||  
                    a.bottom < b.top    ||  
                    a.top    > b.bottom);    
        }

    public:
        Finder(){};

        void add(const T *t)
        {
            auto rect = t->get_rect();
            for (int x = rect.left; x <= rect.right; x++)
            {
                for (int y = rect.top; y <= rect.bottom; y++)
                {
                    individual_items_coords_[t].insert({x, y});
                    coords_map_[{x, y}].insert(t);
                }
            }
            //agafem tipus de obj items_coords[]
            //afegim el punter *t a les celles que pertoquen
            //aixo amb funcio
        }

        void update(const T *t)
        {
            // erase
            remove(t);
            add(t);
            //add
        }
        
        void remove(const T *t)
        {
            for (pair<int, int> coords : individual_items_coords_[t])
            {
                //borrar en coords map
                //sabem que sempre existirà
                auto it = coords_map_[coords].find(t);

                coords_map_[coords].erase(it);
            }
            //borrar tot individual map para ese puntero
            individual_items_coords_.erase(t);
        }
        
        std::set<const T *> query(pro2::Rect qrect) const
        {
            set <const T *> result;

            for (int x = qrect.left; x <= qrect.right; x++)
            {
                for (int y = qrect.top; y <= qrect.bottom; y++)
                {
                    auto it = coords_map_.find({x, y});
                    if (it != coords_map_.end())//existeix
                    {
                        for (const T *t : it->second )
                        {
                            // auto it_obj = result.find(t);
                            if (obj_inside(qrect, t->get_rect()) )
                            {
                                result.insert(t);
                            }
                        }
                        
                    }
                }
            }
            return result;
        }
};
#endif


//* pensar en t com a tipus de obj (coin) que te get_rect() per obtenir les seves coordenades


// * El rectangle màxim de l’espai bidimensional és (0, 0, 20000, 20000)

//* obj no pot tenir un rectangle amb amplada o alçada major que 2000.