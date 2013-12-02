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
#include "include/IfcDateTime.h"
#include "include/IfcDuration.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPerson.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToControl.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByObject.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcText.h"
#include "include/IfcWorkPlan.h"
#include "include/IfcWorkPlanTypeEnum.h"

// ENTITY IfcWorkPlan 
IfcWorkPlan::IfcWorkPlan() { m_entity_enum = IFCWORKPLAN; }
IfcWorkPlan::IfcWorkPlan( int id ) { m_id = id; m_entity_enum = IFCWORKPLAN; }
IfcWorkPlan::~IfcWorkPlan() {}

// method setEntity takes over all attributes from another instance of the class
void IfcWorkPlan::setEntity( shared_ptr<IfcPPEntity> other_entity )
{
	shared_ptr<IfcWorkPlan> other = dynamic_pointer_cast<IfcWorkPlan>(other_entity);
	if( !other) { return; }
	m_GlobalId = other->m_GlobalId;
	m_OwnerHistory = other->m_OwnerHistory;
	m_Name = other->m_Name;
	m_Description = other->m_Description;
	m_ObjectType = other->m_ObjectType;
	m_Identification = other->m_Identification;
	m_CreationDate = other->m_CreationDate;
	m_Creators = other->m_Creators;
	m_Purpose = other->m_Purpose;
	m_Duration = other->m_Duration;
	m_TotalFloat = other->m_TotalFloat;
	m_StartTime = other->m_StartTime;
	m_FinishTime = other->m_FinishTime;
	m_PredefinedType = other->m_PredefinedType;
}
void IfcWorkPlan::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "=IFCWORKPLAN" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ObjectType ) { m_ObjectType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Identification ) { m_Identification->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_CreationDate ) { m_CreationDate->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_Creators );
	stream << ",";
	if( m_Purpose ) { m_Purpose->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Duration ) { m_Duration->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_TotalFloat ) { m_TotalFloat->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_StartTime ) { m_StartTime->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_FinishTime ) { m_FinishTime->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcWorkPlan::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcWorkPlan::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args<14 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcWorkPlan, expecting 14, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcPPException( strserr.str().c_str() ); }
	#ifdef _DEBUG
	if( num_args>14 ){ std::cout << "Wrong parameter count for entity IfcWorkPlan, expecting 14, having " << num_args << ". Object id: " << getId() << std::endl; }
	#endif
	m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::readStepData( args[2] );
	m_Description = IfcText::readStepData( args[3] );
	m_ObjectType = IfcLabel::readStepData( args[4] );
	m_Identification = IfcIdentifier::readStepData( args[5] );
	m_CreationDate = IfcDateTime::readStepData( args[6] );
	readEntityReferenceList( args[7], m_Creators, map );
	m_Purpose = IfcLabel::readStepData( args[8] );
	m_Duration = IfcDuration::readStepData( args[9] );
	m_TotalFloat = IfcDuration::readStepData( args[10] );
	m_StartTime = IfcDateTime::readStepData( args[11] );
	m_FinishTime = IfcDateTime::readStepData( args[12] );
	m_PredefinedType = IfcWorkPlanTypeEnum::readStepData( args[13] );
}
void IfcWorkPlan::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcWorkControl::setInverseCounterparts( ptr_self_entity );
}
void IfcWorkPlan::unlinkSelf()
{
	IfcWorkControl::unlinkSelf();
}