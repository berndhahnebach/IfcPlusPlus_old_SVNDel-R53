/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/
#include <sstream>
#include <limits>

#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/model/IfcPPAttributeObject.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IfcPPEntityEnums.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVertex.h"

// ENTITY IfcVertex 
IfcVertex::IfcVertex() {}
IfcVertex::IfcVertex( int id ) { m_id = id; }
IfcVertex::~IfcVertex() {}

// method setEntity takes over all attributes from another instance of the class
void IfcVertex::setEntity( shared_ptr<IfcPPEntity> other_entity )
{
	shared_ptr<IfcVertex> other = dynamic_pointer_cast<IfcVertex>(other_entity);
	if( !other) { return; }
}
void IfcVertex::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "=IFCVERTEX" << "(";
	stream << ");";
}
void IfcVertex::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcVertex::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
}
void IfcVertex::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcTopologicalRepresentationItem::getAttributes( vec_attributes );
}
void IfcVertex::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
}
void IfcVertex::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcTopologicalRepresentationItem::setInverseCounterparts( ptr_self_entity );
}
void IfcVertex::unlinkSelf()
{
	IfcTopologicalRepresentationItem::unlinkSelf();
}
