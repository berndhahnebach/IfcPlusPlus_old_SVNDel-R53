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
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPObject.h"
#include "IfcBSplineSurface.h"
class IfcParameterValue;
class IfcKnotType;
//ENTITY
class IfcBSplineSurfaceWithKnots : public IfcBSplineSurface
{
public:
	IfcBSplineSurfaceWithKnots();
	IfcBSplineSurfaceWithKnots( int id );
	~IfcBSplineSurfaceWithKnots();

	// method setEntity takes over all attributes from another instance of the class
	virtual void setEntity( shared_ptr<IfcPPEntity> other );
	virtual void getStepLine( std::stringstream& stream ) const;
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map );
	virtual void setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self );
	virtual void unlinkSelf();
	virtual const char* classname() const { return "IfcBSplineSurfaceWithKnots"; }


	// IfcRepresentationItem -----------------------------------------------------------
	// inverse attributes:
	//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
	//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

	// IfcGeometricRepresentationItem -----------------------------------------------------------

	// IfcSurface -----------------------------------------------------------

	// IfcBoundedSurface -----------------------------------------------------------

	// IfcBSplineSurface -----------------------------------------------------------
	// attributes:
	//  int											m_UDegree;
	//  int											m_VDegree;
	//  std::vector<std::vector<shared_ptr<IfcCartesianPoint> > >	m_ControlPointsList;
	//  shared_ptr<IfcBSplineSurfaceForm>			m_SurfaceForm;
	//  bool											m_UClosed;
	//  bool											m_VClosed;
	//  bool											m_SelfIntersect;

	// IfcBSplineSurfaceWithKnots -----------------------------------------------------------
	// attributes:
	std::vector<int >							m_UMultiplicities;
	std::vector<int >							m_VMultiplicities;
	std::vector<shared_ptr<IfcParameterValue> >	m_UKnots;
	std::vector<shared_ptr<IfcParameterValue> >	m_VKnots;
	shared_ptr<IfcKnotType>						m_KnotSpec;
};
