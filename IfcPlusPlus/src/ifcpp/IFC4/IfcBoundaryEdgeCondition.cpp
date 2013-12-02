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
#include "include/IfcBoundaryEdgeCondition.h"
#include "include/IfcLabel.h"
#include "include/IfcModulusOfRotationalSubgradeReactionSelect.h"
#include "include/IfcModulusOfTranslationalSubgradeReactionSelect.h"

// ENTITY IfcBoundaryEdgeCondition 
IfcBoundaryEdgeCondition::IfcBoundaryEdgeCondition() { m_entity_enum = IFCBOUNDARYEDGECONDITION; }
IfcBoundaryEdgeCondition::IfcBoundaryEdgeCondition( int id ) { m_id = id; m_entity_enum = IFCBOUNDARYEDGECONDITION; }
IfcBoundaryEdgeCondition::~IfcBoundaryEdgeCondition() {}

// method setEntity takes over all attributes from another instance of the class
void IfcBoundaryEdgeCondition::setEntity( shared_ptr<IfcPPEntity> other_entity )
{
	shared_ptr<IfcBoundaryEdgeCondition> other = dynamic_pointer_cast<IfcBoundaryEdgeCondition>(other_entity);
	if( !other) { return; }
	m_Name = other->m_Name;
	m_TranslationalStiffnessByLengthX = other->m_TranslationalStiffnessByLengthX;
	m_TranslationalStiffnessByLengthY = other->m_TranslationalStiffnessByLengthY;
	m_TranslationalStiffnessByLengthZ = other->m_TranslationalStiffnessByLengthZ;
	m_RotationalStiffnessByLengthX = other->m_RotationalStiffnessByLengthX;
	m_RotationalStiffnessByLengthY = other->m_RotationalStiffnessByLengthY;
	m_RotationalStiffnessByLengthZ = other->m_RotationalStiffnessByLengthZ;
}
void IfcBoundaryEdgeCondition::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "=IFCBOUNDARYEDGECONDITION" << "(";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_TranslationalStiffnessByLengthX ) { m_TranslationalStiffnessByLengthX->getStepParameter( stream, true ); } else { stream << "$"; }
	stream << ",";
	if( m_TranslationalStiffnessByLengthY ) { m_TranslationalStiffnessByLengthY->getStepParameter( stream, true ); } else { stream << "$"; }
	stream << ",";
	if( m_TranslationalStiffnessByLengthZ ) { m_TranslationalStiffnessByLengthZ->getStepParameter( stream, true ); } else { stream << "$"; }
	stream << ",";
	if( m_RotationalStiffnessByLengthX ) { m_RotationalStiffnessByLengthX->getStepParameter( stream, true ); } else { stream << "$"; }
	stream << ",";
	if( m_RotationalStiffnessByLengthY ) { m_RotationalStiffnessByLengthY->getStepParameter( stream, true ); } else { stream << "$"; }
	stream << ",";
	if( m_RotationalStiffnessByLengthZ ) { m_RotationalStiffnessByLengthZ->getStepParameter( stream, true ); } else { stream << "$"; }
	stream << ");";
}
void IfcBoundaryEdgeCondition::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcBoundaryEdgeCondition::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBoundaryEdgeCondition, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcPPException( strserr.str().c_str() ); }
	#ifdef _DEBUG
	if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcBoundaryEdgeCondition, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
	#endif
	m_Name = IfcLabel::readStepData( args[0] );
	m_TranslationalStiffnessByLengthX = IfcModulusOfTranslationalSubgradeReactionSelect::readStepData( args[1], map );
	m_TranslationalStiffnessByLengthY = IfcModulusOfTranslationalSubgradeReactionSelect::readStepData( args[2], map );
	m_TranslationalStiffnessByLengthZ = IfcModulusOfTranslationalSubgradeReactionSelect::readStepData( args[3], map );
	m_RotationalStiffnessByLengthX = IfcModulusOfRotationalSubgradeReactionSelect::readStepData( args[4], map );
	m_RotationalStiffnessByLengthY = IfcModulusOfRotationalSubgradeReactionSelect::readStepData( args[5], map );
	m_RotationalStiffnessByLengthZ = IfcModulusOfRotationalSubgradeReactionSelect::readStepData( args[6], map );
}
void IfcBoundaryEdgeCondition::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcBoundaryCondition::setInverseCounterparts( ptr_self_entity );
}
void IfcBoundaryEdgeCondition::unlinkSelf()
{
	IfcBoundaryCondition::unlinkSelf();
}