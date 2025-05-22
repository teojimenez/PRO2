#ifndef FINDER_HH
#define FINDER_HH

#include "geometry.hh"
#include <map>
#include <set>

// Finder<T> para accedir a qualsevol clase
template <class T>
class Finder
{
    private:
        /// @brief Escala a la que es disminueixen les coordenades per estalviar iteracions
        const int SCALE = 200;

        /// @brief Map key: punter, value: Set de coordenades del punter. (només es útil per fer el remove)
        std::map<const T *, std::set<std::pair<int, int>>> individual_items_coords_;

        /// @brief Map que guarda coordenades amb els punters als objectes que estan allà
        std::map<std::pair<int, int>, std::set<const T *>> coords_map_;

        /**
         * @brief Verifica que les coordenades a, intersectin amb les b
         * @param a Rect principal
         * @param b Rect a verificar si interesecta
         * @returns True en cas que intersecti, o de lo contrari, false
         */
        bool obj_inside(pro2::Rect a, pro2::Rect b) const
        {
            // Verifiquem que estigui fora i ho neguem.
            return !(a.right < b.left || 
                    a.left > b.right ||
                    a.bottom < b.top ||
                    a.top > b.bottom);
        }

    public:

        /// @brief Constructor
        Finder() {};

        /**
         * @brief Afegir les coordenades d'un objecte
         * @param t Punter al obj
         */
        void add(const T *t)
        {
            auto rect = t->get_rect();
            for (int x = rect.left / SCALE; x <= rect.right / SCALE; x++)
            {
                for (int y = rect.top / SCALE; y <= rect.bottom / SCALE; y++)
                {
                    individual_items_coords_[t].insert({x, y});
                    coords_map_[{x, y}].insert(t);
                }
            }
        }

        /**
         * @brief Actualitzar les coordenades d'un punter
         * @param t Punter al obj
         */
        void update(const T *t)
        {
            remove(t);
            add(t);
        }

        /**
         * @brief Esborrar les coordenades d'un punter
         * @param t Punter al obj
         */
        void remove(const T *t)
        {
            for (pair<int, int> coords : individual_items_coords_[t])
            {
                auto it = coords_map_[coords].find(t);
                coords_map_[coords].erase(it);
            }
            individual_items_coords_.erase(t);
        }

        /**
         * @brief Funció que busca punters (a obj) que estiguin dins del rectangle 'qrect'
         * @param qrect Rectangle a mirar amb quins punters intersecta
         * @returns Un Set amb els punters que intersecten amb 'qrect'
         */
        std::set<const T *> query(pro2::Rect qrect) const
        {
            set<const T *> result;

            for (int x = qrect.left / SCALE; x <= qrect.right / SCALE; x++)
            {
                for (int y = qrect.top / SCALE; y <= qrect.bottom / SCALE; y++)
                {
                    auto it = coords_map_.find({x, y});
                    if (it != coords_map_.end())
                    {
                        //iteració al value del map (un set)
                        for (const T *obj : it->second)
                        {
                            // mirem amb les dades amb escala real, si el obj esta dins o no
                            if (obj_inside(qrect, obj->get_rect()))
                                result.insert(obj);
                        }
                    }
                }
            }
            return result;
        }
};

#endif