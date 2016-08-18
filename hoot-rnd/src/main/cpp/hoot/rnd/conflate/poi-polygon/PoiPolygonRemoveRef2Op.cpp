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
 * @copyright Copyright (C) 2015, 2016 DigitalGlobe (http://www.digitalglobe.com/)
 */
#include "PoiPolygonRemoveRef2Op.h"

// hoot
#include <hoot/core/Factory.h>
#include <hoot/core/filters/BuildingCriterion.h>
#include <hoot/core/filters/PoiCriterion.h>
#include <hoot/core/visitors/RemoveRef2Visitor.h>

namespace hoot
{

HOOT_FACTORY_REGISTER(OsmMapOperation, PoiPolygonRemoveRef2Op)

PoiPolygonRemoveRef2Op::PoiPolygonRemoveRef2Op()
{
}

void PoiPolygonRemoveRef2Op::apply(shared_ptr<OsmMap>& map)
{
  RemoveRef2Visitor poiVisitor;
  poiVisitor.addCriterion(ElementCriterionPtr(new PoiCriterion()));
  map->visitRw(poiVisitor);

  RemoveRef2Visitor buildingVisitor;
  buildingVisitor.addCriterion(ElementCriterionPtr(new BuildingCriterion(map)));
  map->visitRw(buildingVisitor);
}

}