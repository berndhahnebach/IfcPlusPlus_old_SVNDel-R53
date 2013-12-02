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
#include "include/IfcComplexProperty.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcIdentifier.h"
#include "include/IfcObjectReferenceSelect.h"
#include "include/IfcPropertyDependencyRelationship.h"
#include "include/IfcPropertyReferenceValue.h"
#include "include/IfcPropertySet.h"
#include "include/IfcText.h"

// ENTITY IfcPropertyReferenceValue 
IfcPropertyReferenceValue::IfcPropertyReferenceValue() { m_entity_enum = IFCPROPERTYREFERENCEVALUE; }
IfcPropertyReferenceValue::IfcPropertyReferenceValue( int id ) { m_id = id; m_entity_enum = IFCPROPERTYREFERENCEVALUE; }
IfcPropertyReferenceValue::~IfcPropertyReferenceValue() {}

// method setEntity takes over all attributes from another instance of the class
void IfcPropertyReferenceValue::setEntity( shared_ptr<IfcPPEntity> other_entity )
{
	shared_ptr<IfcPropertyReferenceValue> other = dynamic_pointer_cast<IfcPropertyReferenceValue>(other_entity);
	if( !other) { return; }
	m_Name = other->m_Name;
	m_Description = other->m_Description;
	m_UsageName = other->m_UsageName;
	m_PropertyReference = other->m_PropertyReference;
}
void IfcPropertyReferenceValue::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "=IFCPROPERTYREFERENCEVALUE" << "(";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_UsageName ) { m_UsageName->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_PropertyReference ) { m_PropertyReference->getStepParameter( stream, true ); } else { stream << "$"; }
	stream << ");";
}
void IfcPropertyReferenceValue::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcPropertyReferenceValue::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPropertyReferenceValue, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcPPException( strserr.str().c_str() ); }
	#ifdef _DEBUG
	if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcPropertyReferenceValue, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
	#endif
	m_Name = IfcIdentifier::readStepData( args[0] );
	m_Description = IfcText::readStepData( args[1] );
	m_UsageName = IfcText::readStepData( args[2] );
	m_PropertyReference = IfcObjectReferenceSelect::readStepData( args[3], map );
}
void IfcPropertyReferenceValue::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcSimpleProperty::setInverseCounterparts( ptr_self_entity );
}
void IfcPropertyReferenceValue::unlinkSelf()
{
	IfcSimpleProperty::unlinkSelf();
}