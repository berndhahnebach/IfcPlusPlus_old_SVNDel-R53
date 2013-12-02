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
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPException.h"
#include "include/IfcMeasureValue.h"
#include "include/IfcSizeSelect.h"
#include "include/IfcPositiveRatioMeasure.h"

// TYPE IfcPositiveRatioMeasure 
IfcPositiveRatioMeasure::IfcPositiveRatioMeasure() {}
IfcPositiveRatioMeasure::~IfcPositiveRatioMeasure() {}
void IfcPositiveRatioMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCPOSITIVERATIOMEASURE("; }
	//supertype as attribute: double m_value
	stream << m_value;
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IfcPositiveRatioMeasure> IfcPositiveRatioMeasure::readStepData( std::string& arg )
{
	// read TYPE
	if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcPositiveRatioMeasure>(); }
	shared_ptr<IfcPositiveRatioMeasure> type_object( new IfcPositiveRatioMeasure() );
	// read TYPE
	//supertype as attribute: double m_value
	type_object->m_value = atof( arg.c_str() );
	return type_object;
}