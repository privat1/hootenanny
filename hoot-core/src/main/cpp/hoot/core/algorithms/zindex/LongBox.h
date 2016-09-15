/*
 * This file is part of Hootenanny.
 *
 * Hootenanny is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * --------------------------------------------------------------------
 *
 * The following copyright notices are generated automatically. If you
 * have a new notice to add, please use the format:
 * " * @copyright Copyright ..."
 * This will properly maintain the copyright information. DigitalGlobe
 * copyrights will be updated automatically.
 *
 * @copyright Copyright (C) 2015 DigitalGlobe (http://www.digitalglobe.com/)
 */
#ifndef LONGBOX_H
#define LONGBOX_H

//Std Includes
#include <vector>

//Qt includes
#include <QString>

namespace hoot
{

using namespace std;

/**
 * Used to represent a bounding box in Z-Value space.
 */
class LongBox
{
public:

  static string className() { return "hoot::LongBox"; }

  LongBox(vector<long int> min, vector<long int> max);

  virtual ~LongBox();

  long calculateVolume();

  /**
    * Returns true if at least one edge overlaps with one of the other boxes
    * edges.
    */
  bool edgeOverlaps(LongBox b);

  LongBox expand(int size);

  int getDimensions() { return getMin().size(); }

  vector<long int> getMax() { return _max; }

  vector<long int> getMin() { return _min; }

  void setMax(vector<long int> max) { _max = max; }

  void setMin(vector<long int> min) { _min = min; }

  bool in(vector<long int> p);

  bool intersects(LongBox b);

  /**
   * @brief toString
   * @return QString
   */
  QString toString();

  long getWidth(int d);

private:
  vector<long int> _min;
  vector<long int> _max;
};

}

#endif // MINAGGREGATOR_H
