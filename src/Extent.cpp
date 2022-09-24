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
    bool Extent<T>::isInBounds(const T x, const T y) const {
        return (
            x >= $minx && x <= $maxx &&
            y >= $miny && y <= $maxy
        );
    }

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
            b.$minx >= a.$maxx || b.$maxx <= a.$minx ||
            b.$miny >= a.$maxy || b.$maxy <= a.$miny
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
    void Extent<T>::get(T& minx, T& miny, T& maxx, T& maxy) const {
        minx = $minx;
        miny = $miny;
        maxx = $maxx;
        maxy = $maxy;
    }

    template <class T>
    void Extent<T>::getRange(T& x, T& y) const {
        x = $maxx - $minx;
        y = $maxy - $miny;
    }

    template <class T>
    void Extent<T>::extend(T x, T y) {
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
    void Extent<T>::translate(T x, T y) {
        $minx += x;
        $maxx += x;
        $miny += y;
        $maxy += y;
    }

    template <class T>
    void Extent<T>::extend(const Extent<T>& extent) {
        extend(extent.$minx, extent.$miny);
        extend(extent.$maxx, extent.$maxy);
    }

    // @static
    template <class T>
    Extent<T> Extent<T>::quad(const Extent<T>& extent) {
        T rx, ry;
        extent.getRange(rx, ry);

        rx /= 2.0;
        ry /= 2.0;

        return Extent<T>(extent.$minx, extent.$miny, extent.$minx + rx, extent.$miny + ry);
    }

    template class Extent<float>;
    template class Extent<double>;
    template class Extent<int8_t>;
    template class Extent<uint8_t>;
    template class Extent<int16_t>;
    template class Extent<uint16_t>;
    template class Extent<int32_t>;
    template class Extent<uint32_t>;
    template class Extent<int64_t>;
    template class Extent<uint64_t>;
}}
