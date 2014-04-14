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
#include "include/IfcAxis2Placement3D.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProfileDef.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSweptSurface.h"

// ENTITY IfcSweptSurface 
IfcSweptSurface::IfcSweptSurface() {}
IfcSweptSurface::IfcSweptSurface( int id ) { m_id = id; }
IfcSweptSurface::~IfcSweptSurface() {}

// method setEntity takes over all attributes from another instance of the class
void IfcSweptSurface::setEntity( shared_ptr<IfcPPEntity> other_entity )
{
	shared_ptr<IfcSweptSurface> other = dynamic_pointer_cast<IfcSweptSurface>(other_entity);
	if( !other) { return; }
	m_SweptCurve = other->m_SweptCurve;
	m_Position = other->m_Position;
}
void IfcSweptSurface::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "=IFCSWEPTSURFACE" << "(";
	if( m_SweptCurve ) { stream << "#" << m_SweptCurve->getId(); } else { stream << "$"; }
	stream << ",";
	if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
	stream << ");";
}
void IfcSweptSurface::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcSweptSurface::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSweptSurface, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcPPException( strserr.str().c_str() ); }
	#ifdef _DEBUG
	if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcSweptSurface, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
	#endif
	readEntityReference( args[0], m_SweptCurve, map );
	readEntityReference( args[1], m_Position, map );
}
void IfcSweptSurface::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcSurface::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "SweptCurve", m_SweptCurve ) );
	vec_attributes.push_back( std::make_pair( "Position", m_Position ) );
}
void IfcSweptSurface::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
}
void IfcSweptSurface::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcSurface::setInverseCounterparts( ptr_self_entity );
}
void IfcSweptSurface::unlinkSelf()
{
	IfcSurface::unlinkSelf();
}
