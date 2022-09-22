/*
    Copyright 2022 Total Pave Inc

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include <tp/geom/Extent.h>

namespace TP { namespace geom {
    template <class T>
    Extent<T>::Extent(void) {
        T inf, neginf;
        if (std::numeric_limits<T>::has_infinity) {
            // infinity is only a valid concept on floating
            // numbers
            inf = std::numeric_limits<T>::infinity();
            neginf = -(std::numeric_limits<T>::infinity());
        }
        else {
            // We must be dealing with an int type
            inf = std::numeric_limits<T>::max();
            neginf = std::numeric_limits<T>::min();
        }

        set(
            inf,
            inf,
            neginf,
            neginf
        );
    }

    template <class T>
    Extent<T>::Extent(T minx, T miny, T maxx, T maxy) {
        set(minx, miny, maxx, maxy);
    }

    template <class T>
    Extent<T>::~Extent() {}

    template <class T>
    bool Extent<T>::isInBounds(const Extent<T>& b) const {
        const Extent<T>& a = *this;
        /*
            Instead of checking if their box is inside our box,
            which requires 16 across both x & y boolean checks...
            it's more efficent to check if their box is completely
            out of bounds of our box, which can be done with only
            4 boolean checks
        */
        return !(
            b.$minx > a.$maxx || b.$maxx < a.$minx ||
            b.$miny > a.$maxy || b.$maxy < a.$miny
        );
    }

    template <class T>
    void Extent<T>::set(T minx, T miny, T maxx, T maxy) {
        $minx = minx;
        $miny = miny;
        $maxx = maxx;
        $maxy = maxy;
    }

    template <class T>
    void  Extent<T>::get(T& minx, T& miny, T& maxx, T& maxy) const {
        minx = $minx;
        miny = $miny;
        maxx = $maxx;
        maxy = $maxy;
    }

    template <class T>
    void  Extent<T>::extend(T x, T y) {
        if (x < $minx) {
            $minx = x;
        }
        if (x > $maxx) {
            $maxx = x;
        }
        if (y < $miny) {
            $miny = y;
        }
        if (y > $maxy) {
            $maxy = y;
        }
    }

    template <class T>
    void  Extent<T>::extend(const Extent<T>& extent) {
        extend(extent.$minx, extent.$miny);
        extend(extent.$maxx, extent.$maxy);
    }
}}
