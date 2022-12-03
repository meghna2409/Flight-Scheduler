/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author CS 225: Data Structures
 */

#include "HSLAPixel.h"
#include <cmath>
#include <iostream>

namespace cs225 {
  HSLAPixel::HSLAPixel() {
    h = 0;
    s = 0;
    l = 1.0;
    a = 1.0;
  }

  HSLAPixel::HSLAPixel(double hue, double saturation, double luminance) {
    h = hue;
    s = saturation;
    l = luminance;
    a = 1.0;
  }

  HSLAPixel::HSLAPixel(double hue, double saturation, double luminance, double alpha) {
    h = hue;
    s = saturation;
    l = luminance;
    a = alpha;
  }

  bool HSLAPixel::operator== (HSLAPixel const & other) const {
    if (fabs(a - other.a) > 0.0000001) { return false; }
    if ( a == 0 ) { return true; }

    if (fabs(l - other.l) > 0.0000001) { return false; }
    if (l == 0 || l == 1) { return true; }

    if (fabs(s - other.s) > 0.01) { return false; }
    if (s == 0) { return true; }

    if (fabs(h - other.h) < 0.0000001 || fabs(h - other.h) > (360.0 - 0.0000001) ) { return true; }
    else { return false; }
}

  bool HSLAPixel::operator!= (HSLAPixel const & other) const {
    return !(*this == other);
  }

  bool HSLAPixel::operator<  (HSLAPixel const & other) const {
      if (h < other.h)
          return true;
      else if (h > other.h)
          return false;
      // == hue

      if (s < other.s)
          return true;
      else if (s > other.s)
          return false;
      // == saturation

      if (l < other.l)
          return true;
      else if (l > other.l)
          return false;
      // == lumininance

      if (a < other.a)
          return true;
      else if (a > other.a)
          return false;
      // == alpha

      // same pixel
      return false;
  }

  std::ostream & operator<<(std::ostream & out, HSLAPixel const & pixel) {
    out << "(" << pixel.h << ", " << pixel.s << ", " << pixel.l << (pixel.a != 1 ? ", " + std::to_string(pixel.a) : "") << ")";

    return out;
  }


}
