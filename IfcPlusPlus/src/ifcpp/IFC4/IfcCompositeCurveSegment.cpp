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
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IfcPPEntityEnums.h"
#include "include/IfcCompositeCurve.h"
#include "include/IfcCompositeCurveSegment.h"
#include "include/IfcCurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcTransitionCode.h"

// ENTITY IfcCompositeCurveSegment 
IfcCompositeCurveSegment::IfcCompositeCurveSegment() {}
IfcCompositeCurveSegment::IfcCompositeCurveSegment( int id ) { m_id = id; }
IfcCompositeCurveSegment::~IfcCompositeCurveSegment() {}

// method setEntity takes over all attributes from another instance of the class
void IfcCompositeCurveSegment::setEntity( shared_ptr<IfcPPEntity> other_entity )
{
	shared_ptr<IfcCompositeCurveSegment> other = dynamic_pointer_cast<IfcCompositeCurveSegment>(other_entity);
	if( !other) { return; }
	m_Transition = other->m_Transition;
	m_SameSense = other->m_SameSense;
	m_ParentCurve = other->m_ParentCurve;
}
void IfcCompositeCurveSegment::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "=IFCCOMPOSITECURVESEGMENT" << "(";
	if( m_Transition ) { m_Transition->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_SameSense == false ) { stream << ".F."; }
	else if( m_SameSense == true ) { stream << ".T."; }
	stream << ",";
	if( m_ParentCurve ) { stream << "#" << m_ParentCurve->getId(); } else { stream << "$"; }
	stream << ");";
}
void IfcCompositeCurveSegment::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcCompositeCurveSegment::readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCompositeCurveSegment, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcPPException( strserr.str().c_str() ); }
	#ifdef _DEBUG
	if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcCompositeCurveSegment, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
	#endif
	m_Transition = IfcTransitionCode::createObjectFromStepData( args[0] );
	if( _stricmp( args[1].c_str(), ".F." ) == 0 ) { m_SameSense = false; }
	else if( _stricmp( args[1].c_str(), ".T." ) == 0 ) { m_SameSense = true; }
	readEntityReference( args[2], m_ParentCurve, map );
}
void IfcCompositeCurveSegment::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
}
void IfcCompositeCurveSegment::unlinkSelf()
{
	IfcGeometricRepresentationItem::unlinkSelf();
}
