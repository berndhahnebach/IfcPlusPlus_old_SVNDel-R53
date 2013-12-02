/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com  - Copyright (C) 2011 Fabian Gerold
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

//! @author Fabian Gerold
//! @date 2011-07-18

#define _USE_MATH_DEFINES 
#include <math.h>
#include <iterator>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Depth>
#include <osg/Material>
#include <osg/LineStipple>
#include <osg/MatrixTransform>
#include <osg/PolygonMode>
#include <osgText/Text>
#include <osgGA/TrackballManipulator>
#include <osgGA/StandardManipulator>

#include <carve/carve.hpp>
#include <carve/geom3d.hpp>
#include <carve/poly.hpp>
#include <carve/polyhedron_base.hpp>
#include <carve/faceloop.hpp>
#include <carve/input.hpp>
#include <carve/csg.hpp>
#include <carve/csg_triangulator.hpp>

#include "ifcpp/IFC4/include/IfcProductRepresentation.h"
#include "ifcpp/IFC4/include/IfcRepresentation.h"
#include "ifcpp/IFC4/include/IfcRepresentationItem.h"
#include "ifcpp/IFC4/include/IfcMappedItem.h"
#include "ifcpp/IFC4/include/IfcRepresentationMap.h"
#include "ifcpp/IFC4/include/IfcCartesianTransformationOperator.h"
#include "ifcpp/IFC4/include/IfcAxis1Placement.h"
#include "ifcpp/IFC4/include/IfcAxis2Placement.h"
#include "ifcpp/IFC4/include/IfcAxis2Placement2D.h"
#include "ifcpp/IFC4/include/IfcAxis2Placement3D.h"
#include "ifcpp/IFC4/include/IfcPlacement.h"
#include "ifcpp/IFC4/include/IfcExtrudedAreaSolid.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcPolyline.h"
#include "ifcpp/IFC4/include/IfcBoundingBox.h"
#include "ifcpp/IFC4/include/IfcProfileDef.h"
#include "ifcpp/IFC4/include/IfcFacetedBrep.h"
#include "ifcpp/IFC4/include/IfcEdge.h"
#include "ifcpp/IFC4/include/IfcClosedShell.h"
#include "ifcpp/IFC4/include/IfcFaceBasedSurfaceModel.h"
#include "ifcpp/IFC4/include/IfcConnectedFaceSet.h"
#include "ifcpp/IFC4/include/IfcShellBasedSurfaceModel.h"
#include "ifcpp/IFC4/include/IfcOpenShell.h"
#include "ifcpp/IFC4/include/IfcSectionedSpine.h"
#include "ifcpp/IFC4/include/IfcRevolvedAreaSolid.h"
#include "ifcpp/IFC4/include/IfcLengthMeasure.h"
#include "ifcpp/IFC4/include/IfcPositiveLengthMeasure.h"
#include "ifcpp/IFC4/include/IfcPlaneAngleMeasure.h"
#include "ifcpp/IFC4/include/IfcCartesianPoint.h"
#include "ifcpp/IFC4/include/IfcVector.h"
#include "ifcpp/IFC4/include/IfcDirection.h"
#include "ifcpp/IFC4/include/IfcStyledItem.h"
#include "ifcpp/IFC4/include/IfcProperty.h"
#include "ifcpp/IFC4/include/IfcPropertySet.h"
#include "ifcpp/IFC4/include/IfcComplexProperty.h"
#include "ifcpp/IFC4/include/IfcSimpleProperty.h"
#include "ifcpp/IFC4/include/IfcPropertySingleValue.h"
#include "ifcpp/IFC4/include/IfcIdentifier.h"
#include "ifcpp/IFC4/include/IfcInteger.h"
#include "ifcpp/IFC4/include/IfcFace.h"
#include "ifcpp/IFC4/include/IfcFaceSurface.h"
#include "ifcpp/IFC4/include/IfcFaceBound.h"
#include "ifcpp/IFC4/include/IfcEdgeLoop.h"
#include "ifcpp/IFC4/include/IfcOrientedEdge.h"
#include "ifcpp/IFC4/include/IfcVertexPoint.h"
#include "ifcpp/IFC4/include/IfcVertexLoop.h"
#include "ifcpp/IFC4/include/IfcGeometricSet.h"
#include "ifcpp/IFC4/include/IfcGeometricCurveSet.h"
#include "ifcpp/IFC4/include/IfcGeometricSetSelect.h"
#include "ifcpp/IFC4/include/IfcFeatureElementSubtraction.h"
#include "ifcpp/IFC4/include/IfcRelVoidsElement.h"
#include "ifcpp/IFC4/include/IfcRationalBSplineSurfaceWithKnots.h"
#include "ifcpp/IFC4/include/IfcSweptSurface.h"
#include "ifcpp/IFC4/include/IfcCylindricalSurface.h"
#include "ifcpp/IFC4/include/IfcSurfaceOfLinearExtrusion.h"
#include "ifcpp/IFC4/include/IfcSurfaceOfRevolution.h"
#include "ifcpp/IFC4/include/IfcCurveBoundedPlane.h"
#include "ifcpp/IFC4/include/IfcCurveBoundedSurface.h"
#include "ifcpp/IFC4/include/IfcRectangularTrimmedSurface.h"
#include "ifcpp/IFC4/include/IfcPlane.h"
#include "ifcpp/IFC4/include/IfcFaceOuterBound.h"
#include "ifcpp/IFC4/include/IfcBooleanClippingResult.h"
#include "ifcpp/IFC4/include/IfcBooleanOperator.h"
#include "ifcpp/IFC4/include/IfcBooleanOperand.h"
#include "ifcpp/IFC4/include/IfcHalfSpaceSolid.h"
#include "ifcpp/IFC4/include/IfcBoxedHalfSpace.h"
#include "ifcpp/IFC4/include/IfcPolygonalBoundedHalfSpace.h"
#include "ifcpp/IFC4/include/IfcCsgPrimitive3D.h"
#include "ifcpp/IFC4/include/IfcCsgSolid.h"
#include "ifcpp/IFC4/include/IfcSweptDiskSolid.h"
#include "ifcpp/IFC4/include/IfcAdvancedBrep.h"
#include "ifcpp/IFC4/include/IfcAdvancedBrepWithVoids.h"
#include "ifcpp/IFC4/include/IfcFixedReferenceSweptAreaSolid.h"
#include "ifcpp/IFC4/include/IfcSurfaceCurveSweptAreaSolid.h"
#include "ifcpp/IFC4/include/IfcBlock.h"
#include "ifcpp/IFC4/include/IfcRectangularPyramid.h"
#include "ifcpp/IFC4/include/IfcRightCircularCone.h"
#include "ifcpp/IFC4/include/IfcRightCircularCylinder.h"
#include "ifcpp/IFC4/include/IfcSphere.h"
#include "ifcpp/IFC4/include/IfcPresentationLayerWithStyle.h"
#include "ifcpp/IFC4/include/IfcPolyLoop.h"

#include "ifcpp/model/IfcPPModel.h"
#include "ifcpp/model/UnitConverter.h"
#include "ifcpp/model/IfcPPException.h"

#include "Utility.h"
#include "ConverterOSG.h"
#include "PlacementConverter.h"
#include "ProfileConverter.h"
#include "StylesConverter.h"
#include "UnhandledRepresentationException.h"
#include "RecursiveCallException.h"
#include "CurveConverter.h"
#include "RepresentationConverter.h"

RepresentationConverter::RepresentationConverter( shared_ptr<UnitConverter> unit_converter ) 
	: m_unit_converter(unit_converter)
{
	m_handle_styled_items = true;
	m_handle_layer_assignments = true;
	m_num_vertices_per_circle = 20;
	m_styles_converter = shared_ptr<StylesConverter>( new StylesConverter() );
	m_curve_converter = shared_ptr<CurveConverter>( new CurveConverter( m_unit_converter, m_num_vertices_per_circle ) );

#ifdef IFCPP_OPENMP
	omp_init_lock(&m_writelock_profile_cache);
	omp_init_lock(&m_writelock_detailed_report);
	omp_init_lock(&m_writelock_styles_converter);
#endif

#ifdef _DEBUG
	m_debug_viewer = NULL;
#endif
}

RepresentationConverter::~RepresentationConverter()
{
#ifdef IFCPP_OPENMP
	omp_destroy_lock(&m_writelock_profile_cache);
	omp_destroy_lock(&m_writelock_detailed_report);
	omp_destroy_lock(&m_writelock_styles_converter);
#endif
}

void RepresentationConverter::setNumVerticesPerCircle( int num_vertices )
{
	if( num_vertices < 6 ) { num_vertices = 6; }
	m_num_vertices_per_circle = num_vertices;
	m_curve_converter->m_num_vertices_per_circle = m_num_vertices_per_circle;
}

void RepresentationConverter::convertStyledItem( const shared_ptr<IfcRepresentationItem>& representation_item, shared_ptr<ItemData>& item_data )
{
	std::vector<weak_ptr<IfcStyledItem> >&	StyledByItem_inverse_vec = representation_item->m_StyledByItem_inverse;
	for( unsigned int i=0; i<StyledByItem_inverse_vec.size(); ++i )
	{
		weak_ptr<IfcStyledItem> styled_item_weak = StyledByItem_inverse_vec[i];
		shared_ptr<IfcStyledItem> styled_item = shared_ptr<IfcStyledItem>(styled_item_weak);

	#ifdef IFCPP_OPENMP
		omp_set_lock(&m_writelock_styles_converter);
		osg::StateSet* stateset = m_styles_converter->convertIfcStyledItem( styled_item );
		omp_unset_lock(&m_writelock_styles_converter);
	#else
		osg::StateSet* stateset = m_styles_converter->convertIfcStyledItem( styled_item );
	#endif
		if( stateset != NULL )
		{
			item_data->statesets.push_back(stateset);
		}
	}
}

void RepresentationConverter::convertIfcRepresentation(  const shared_ptr<IfcRepresentation>& representation, const carve::math::Matrix& pos, shared_ptr<RepresentationData>& input_data, std::set<int>& visited )
{
	std::stringstream err;
	double length_factor = m_unit_converter->getLengthInMeterFactor();
	const std::vector<shared_ptr<IfcRepresentationItem> >&	vec_representation_items = representation->m_Items;
	std::vector<shared_ptr<ItemData> >& vec_item_data = input_data->vec_item_data;

	std::vector<shared_ptr<IfcRepresentationItem> > unhandled_representation_items;
	std::vector<shared_ptr<IfcRepresentationItem> >::const_iterator it_representation_items;
	for( it_representation_items=vec_representation_items.begin(); it_representation_items!=vec_representation_items.end(); ++it_representation_items )
	{
		shared_ptr<IfcRepresentationItem> representation_item = (*it_representation_items);
		shared_ptr<ItemData> item_data( new ItemData() );
		vec_item_data.push_back( item_data );

		if( m_handle_styled_items )
		{
			convertStyledItem( representation_item, item_data );
		}

		//ENTITY IfcRepresentationItem  ABSTRACT SUPERTYPE OF(ONEOF(IfcGeometricRepresentationItem, IfcMappedItem, IfcStyledItem, IfcTopologicalRepresentationItem));
		shared_ptr<IfcGeometricRepresentationItem> geom_item = dynamic_pointer_cast<IfcGeometricRepresentationItem>(representation_item);
		if( geom_item )
		{
			try
			{
				convertIfcGeometricRepresentationItem( geom_item, pos, item_data );
			}
			catch( UnhandledRepresentationException& e)
			{
				if( e.m_item )
				{
					unhandled_representation_items.push_back( e.m_item );
				}
				else if( e.m_select )
				{
					err << "Unhandled Representation: " << e.m_select->classname() << std::endl;

				}
			}
			catch( IfcPPException& e )
			{
				err << e.what() << std::endl;
			}
			catch( std::exception& e )
			{
				err << e.what() << std::endl;
			}
			catch( ... )
			{
				err << "convertIfcRepresentation: failed at item #" << representation_item->getId() << std::endl;
			}
			continue;
		}
		
		shared_ptr<IfcMappedItem> mapped_item = dynamic_pointer_cast<IfcMappedItem>(representation_item);
		if( mapped_item )
		{
			shared_ptr<IfcRepresentationMap> map_source = mapped_item->m_MappingSource;
			if( !map_source )
			{
				unhandled_representation_items.push_back( representation_item );
				continue;
			}
			shared_ptr<IfcRepresentation> mapped_representation = map_source->m_MappedRepresentation;
			if( !mapped_representation )
			{
				unhandled_representation_items.push_back( representation_item );
				continue;
			}
		
			carve::math::Matrix map_matrix_target( carve::math::Matrix::IDENT() );
			if( mapped_item->m_MappingTarget )
			{
				shared_ptr<IfcCartesianTransformationOperator> transform_operator = mapped_item->m_MappingTarget;
				PlacementConverter::convertTransformationOperator(	transform_operator, map_matrix_target, length_factor );
			}

			carve::math::Matrix map_matrix_origin( carve::math::Matrix::IDENT() );
			if( map_source->m_MappingOrigin )
			{
				shared_ptr<IfcAxis2Placement> mapping_origin = map_source->m_MappingOrigin;
				shared_ptr<IfcPlacement> mapping_origin_placement = dynamic_pointer_cast<IfcPlacement>( mapping_origin );
				if( mapping_origin_placement )
				{
					PlacementConverter::convertIfcPlacement( mapping_origin_placement, map_matrix_origin, length_factor );
				}
				else
				{
					std::stringstream strs;
					strs << "#" << mapping_origin_placement->getId() << " = IfcPlacement: !dynamic_pointer_cast<IfcPlacement>( mapping_origin ) )";
					detailedReport( strs );
					continue;
					//throw IfcPPException( "! dynamic_pointer_cast<IfcPlacement>( mapping_origin ) )" );
				}
			}

			carve::math::Matrix mapped_pos( (map_matrix_origin*pos)*map_matrix_target );
			convertIfcRepresentation( mapped_representation, mapped_pos, input_data, visited );
			continue;
		}
		
		shared_ptr<IfcStyledItem> styled_item = dynamic_pointer_cast<IfcStyledItem>(representation_item);
		if( styled_item )
		{
			continue;
		}

		shared_ptr<IfcTopologicalRepresentationItem> topo_item = dynamic_pointer_cast<IfcTopologicalRepresentationItem>(representation_item);
		if( topo_item )
		{
			//IfcTopologicalRepresentationItem 		ABSTRACT SUPERTYPE OF(ONEOF(IfcConnectedFaceSet, IfcEdge, IfcFace, IfcFaceBound, IfcLoop, IfcPath, IfcVertex))

			shared_ptr<IfcConnectedFaceSet> topo_connected_face_set = dynamic_pointer_cast<IfcConnectedFaceSet>(topo_item);
			if( topo_connected_face_set )
			{
				continue;
			}

			shared_ptr<IfcEdge> topo_edge = dynamic_pointer_cast<IfcEdge>(topo_item);
			if( topo_edge )
			{
				shared_ptr<carve::input::PolylineSetData> polyline_data( new carve::input::PolylineSetData() );
				polyline_data->beginPolyline();
				shared_ptr<IfcVertex>& vertex_start = topo_edge->m_EdgeStart;

				shared_ptr<IfcVertexPoint> vertex_start_point = dynamic_pointer_cast<IfcVertexPoint>(vertex_start);
				if( vertex_start_point )
				{
					if( vertex_start_point->m_VertexGeometry )
					{
						shared_ptr<IfcPoint> edge_start_point_geometry = vertex_start_point->m_VertexGeometry;
						shared_ptr<IfcCartesianPoint> ifc_point = dynamic_pointer_cast<IfcCartesianPoint>(edge_start_point_geometry);
						if( ifc_point )
						{
							if( ifc_point->m_Coordinates.size() > 2 )
							{
								carve::geom::vector<3> point = carve::geom::VECTOR( ifc_point->m_Coordinates[0]->m_value*length_factor, ifc_point->m_Coordinates[1]->m_value*length_factor, ifc_point->m_Coordinates[2]->m_value*length_factor );
								polyline_data->addVertex( point );
								polyline_data->addPolylineIndex(0);
							}
						}
					}
				}

				shared_ptr<IfcVertex>& vertex_end = topo_edge->m_EdgeEnd;

				shared_ptr<IfcVertexPoint> vertex_end_point = dynamic_pointer_cast<IfcVertexPoint>(vertex_end);
				if( vertex_end_point )
				{
					if( vertex_end_point->m_VertexGeometry )
					{
						shared_ptr<IfcPoint> edge_point_geometry = vertex_end_point->m_VertexGeometry;
						shared_ptr<IfcCartesianPoint> ifc_point = dynamic_pointer_cast<IfcCartesianPoint>(edge_point_geometry);
						if( ifc_point )
						{
							if( ifc_point->m_Coordinates.size() > 2 )
							{
								carve::geom::vector<3> point = carve::geom::VECTOR( ifc_point->m_Coordinates[0]->m_value*length_factor, ifc_point->m_Coordinates[1]->m_value*length_factor, ifc_point->m_Coordinates[2]->m_value*length_factor );
								polyline_data->addVertex( point );
								polyline_data->addPolylineIndex(1);
							}
						}
					}
				}
				item_data->polyline_data.push_back( polyline_data );
				continue;
			}

		}

		unhandled_representation_items.push_back( representation_item );
			


		//std::string representation_type;
		//std::string	representation_identifier;
		//if( representation->m_RepresentationType )
		//{
		//	representation_type =  representation->m_RepresentationType->m_value;
		//}
		//if( representation->m_RepresentationIdentifier )
		//{
		//	representation_identifier =  representation->m_RepresentationIdentifier->m_value;
		//}

		//if( representation_identifier.compare( "Axis" ) == 0 )
		//{
		//	if( representation_type.compare( "Curve2D" ) == 0 || representation_type.compare( "GeometricCurveSet" ) == 0 )
		//	{
		//		//osg::StateSet* stateset_axis = item_group->getOrCreateStateSet();
		//		//stateset_axis->setMode( GL_LIGHTING,osg::StateAttribute::OFF );

		//		//osg::LineStipple* linestipple = new osg::LineStipple;
		//		//linestipple->setFactor( 2 );
		//		//linestipple->setPattern( 0xAAAA );
		//		//stateset_axis->setAttributeAndModes( linestipple, osg::StateAttribute::OVERRIDE|osg::StateAttribute::ON );
		//	}
		//}
	}

	if( m_handle_layer_assignments )
	{
		std::vector<weak_ptr<IfcPresentationLayerAssignment> >& LayerAssignments_inverse = representation->m_LayerAssignments_inverse;
		std::vector<weak_ptr<IfcPresentationLayerAssignment> >::iterator it_LayerAssignments_inverse;
		for( it_LayerAssignments_inverse = LayerAssignments_inverse.begin(); it_LayerAssignments_inverse != LayerAssignments_inverse.end(); ++it_LayerAssignments_inverse)
		{
			shared_ptr<IfcPresentationLayerAssignment> layer_assignment( (*it_LayerAssignments_inverse) );

			shared_ptr<IfcPresentationLayerWithStyle> layer_assignment_with_style = dynamic_pointer_cast<IfcPresentationLayerWithStyle>( layer_assignment );
			if( layer_assignment_with_style )
			{
				std::vector<shared_ptr<IfcPresentationStyle> >& vec_presentation_styles = layer_assignment_with_style->m_LayerStyles;
				for( int i=0; i<vec_presentation_styles.size(); ++i )
				{
					shared_ptr<IfcPresentationStyle>&  presentation_style = vec_presentation_styles[i];

#ifdef IFCPP_OPENMP
					omp_set_lock(&m_writelock_styles_converter);
					osg::StateSet* stateset = m_styles_converter->convertIfcPresentationStyle( presentation_style );
					omp_unset_lock(&m_writelock_styles_converter);
#else
					osg::StateSet* stateset = m_styles_converter->convertIfcPresentationStyle( presentation_style );
#endif
					if( stateset != NULL )
					{
						input_data->statesets.push_back(stateset);
					}
				}
			}
		}
	}

	if( unhandled_representation_items.size() > 0 )
	{
		for( unsigned int i=0; i<unhandled_representation_items.size(); ++i )
		{
			shared_ptr<IfcRepresentationItem> representation_item = unhandled_representation_items[i];
			
			std::string representation_type;
			std::string	representation_identifier;
			if( representation->m_RepresentationType )
			{
				representation_type =  representation->m_RepresentationType->m_value;
			}
			if( representation->m_RepresentationIdentifier )
			{
				representation_identifier =  representation->m_RepresentationIdentifier->m_value;
			}

			std::stringstream strs;
			strs << "unhandled representation: " << strs.str().c_str() << representation_type << " " << representation_identifier << std::endl;
			detailedReport( strs );
		}
	}
	if( err.tellp() > 0 )
	{
		detailedReport( err );
		//throw IfcPPException( err.str().c_str() );
	}
}

void RepresentationConverter::convertIfcGeometricRepresentationItem( const shared_ptr<IfcGeometricRepresentationItem>& geom_item, const carve::math::Matrix& pos, shared_ptr<ItemData> item_data )
{
	//ENTITY IfcGeometricRepresentationItem
	//ABSTRACT SUPERTYPE OF(ONEOF(
	//	IfcAnnotationFillArea, IfcBooleanResult, IfcBoundingBox, IfcCartesianTransformationOperator, IfcCompositeCurveSegment, IfcCsgPrimitive3D,
	//	IfcCurve, IfcDefinedSymbol, IfcDirection, IfcFaceBasedSurfaceModel, IfcFillAreaStyleHatching, IfcFillAreaStyleTiles, IfcFillAreaStyleTileSymbolWithStyle,
	//	IfcGeometricSet, IfcHalfSpaceSolid, IfcLightSource, IfcOneDirectionRepeatFactor, IfcPlacement, IfcPlanarExtent, IfcPoint, IfcSectionedSpine,
	//	IfcShellBasedSurfaceModel, IfcSolidModel, IfcSurface, IfcTextLiteral, IfcTextureCoordinate, IfcTextureVertex, IfcVector))

	shared_ptr<IfcBoundingBox> bbox = dynamic_pointer_cast<IfcBoundingBox>(geom_item);
	if( bbox )
	{
		shared_ptr<IfcCartesianPoint> corner = bbox->m_Corner;
		shared_ptr<IfcPositiveLengthMeasure> x_dim = bbox->m_XDim;
		shared_ptr<IfcPositiveLengthMeasure> y_dim = bbox->m_YDim;
		shared_ptr<IfcPositiveLengthMeasure> z_dim = bbox->m_ZDim;
		return;
	}

	shared_ptr<IfcFaceBasedSurfaceModel> surface_model = dynamic_pointer_cast<IfcFaceBasedSurfaceModel>(geom_item);
	if( surface_model )
	{
		std::vector<shared_ptr<IfcConnectedFaceSet> >& vec_face_sets = surface_model->m_FbsmFaces;
		std::vector<shared_ptr<IfcConnectedFaceSet> >::iterator it_face_sets;

		
		for( it_face_sets=vec_face_sets.begin(); it_face_sets!=vec_face_sets.end(); ++it_face_sets )
		{
			shared_ptr<IfcConnectedFaceSet> face_set = (*it_face_sets);
			std::vector<shared_ptr<IfcFace> >& vec_ifc_faces = face_set->m_CfsFaces;

			shared_ptr<ItemData> input_data_face_set( new ItemData );
			convertIfcFaceList( vec_ifc_faces, pos, input_data_face_set );
			std::copy( input_data_face_set->open_or_closed_shell_data.begin(), input_data_face_set->open_or_closed_shell_data.end(), std::back_inserter(item_data->open_shell_data) );
		}
		
		return;
	}

	shared_ptr<IfcBooleanResult> boolean_result = dynamic_pointer_cast<IfcBooleanResult>(geom_item);
	if( boolean_result )
	{
		convertIfcBooleanResult( boolean_result, pos, item_data );
		return;
	}

	shared_ptr<IfcSolidModel> solid_model = dynamic_pointer_cast<IfcSolidModel>(geom_item);
	if( solid_model )
	{
		convertIfcSolidModel( solid_model, pos, item_data );
		return;
	}

	shared_ptr<IfcCurve> curve = dynamic_pointer_cast<IfcCurve>(geom_item);
	if( curve )
	{
		std::vector<carve::geom::vector<3> > loops;
		std::vector<carve::geom::vector<3> > segment_start_points;
		m_curve_converter->convertIfcCurve( curve, loops, segment_start_points );

		shared_ptr<carve::input::PolylineSetData> polyline_data( new carve::input::PolylineSetData() );
		polyline_data->beginPolyline();
		for( int i=0; i<loops.size(); ++i )
		{
			carve::geom::vector<3> point = loops.at(i);
			polyline_data->addVertex( pos*point );
			polyline_data->addPolylineIndex(i);
		}
		item_data->polyline_data.push_back( polyline_data );
		
		return;
	}

	shared_ptr<IfcShellBasedSurfaceModel> shell_based_surface_model = dynamic_pointer_cast<IfcShellBasedSurfaceModel>(geom_item);
	if( shell_based_surface_model )
	{
		std::vector<shared_ptr<IfcShell> >& vec_shells = shell_based_surface_model->m_SbsmBoundary;
		std::vector<shared_ptr<IfcShell> >::iterator it_shells;

		for( it_shells=vec_shells.begin(); it_shells!=vec_shells.end(); ++it_shells )
		{
			shared_ptr<IfcShell> shell_select = (*it_shells);
			if( dynamic_pointer_cast<IfcClosedShell>( shell_select ) )
			{
				shared_ptr<IfcClosedShell> closed_shell = dynamic_pointer_cast<IfcClosedShell>( shell_select );
				std::vector<shared_ptr<IfcFace> >& vec_ifc_faces = closed_shell->m_CfsFaces;

				shared_ptr<ItemData> input_data_closed_shell( new ItemData() );
				convertIfcFaceList( vec_ifc_faces, pos, input_data_closed_shell );
				std::copy( input_data_closed_shell->open_or_closed_shell_data.begin(), input_data_closed_shell->open_or_closed_shell_data.end(), std::back_inserter(item_data->closed_shell_data) );
			}
			else if( dynamic_pointer_cast<IfcOpenShell>( shell_select ) )
			{
				shared_ptr<IfcOpenShell> open_shell = dynamic_pointer_cast<IfcOpenShell>( shell_select );
				std::vector<shared_ptr<IfcFace> >& vec_ifc_faces = open_shell->m_CfsFaces;

				shared_ptr<ItemData> input_data_open_shell( new ItemData() );
				convertIfcFaceList( vec_ifc_faces, pos, input_data_open_shell );

				std::copy( input_data_open_shell->open_or_closed_shell_data.begin(), input_data_open_shell->open_or_closed_shell_data.end(), std::back_inserter(item_data->open_shell_data) );
			}
		}
		return;
	}

	shared_ptr<IfcSurface> surface = dynamic_pointer_cast<IfcSurface>(geom_item);
	if( surface )
	{
		shared_ptr<carve::input::PolylineSetData> polyline( new carve::input::PolylineSetData() );
		convertIfcSurface( surface, pos, polyline );
		if( polyline->getVertexCount() > 1 )
		{
			item_data->polyline_data.push_back( polyline );
		}
		return;
	}
	
	shared_ptr<IfcPolyline> poly_line = dynamic_pointer_cast<IfcPolyline>(geom_item);
	if( poly_line )
	{
		std::vector<carve::geom::vector<3> > poly_vertices;
		m_curve_converter->convertIfcPolyline( poly_line, poly_vertices );

		const unsigned int num_points = poly_vertices.size();
		shared_ptr<carve::input::PolylineSetData> polyline_data( new carve::input::PolylineSetData() );
		
		polyline_data->beginPolyline();

		// apply position
		for( unsigned int i=0; i<num_points; ++i )
		{
			carve::geom::vector<3>& vertex = poly_vertices.at(i);
			vertex = pos*vertex;

			polyline_data->addVertex(vertex);
			polyline_data->addPolylineIndex(i);
		}
		item_data->polyline_data.push_back(polyline_data);

		return;
	}

	shared_ptr<IfcGeometricSet> geometric_set = dynamic_pointer_cast<IfcGeometricSet>(geom_item);
	if( geometric_set )
	{
		// ENTITY IfcGeometricSet SUPERTYPE OF(IfcGeometricCurveSet)
		std::vector<shared_ptr<IfcGeometricSetSelect> >& geom_set_elements = geometric_set->m_Elements;
		std::vector<shared_ptr<IfcGeometricSetSelect> >::iterator it_set_elements;
		for( it_set_elements=geom_set_elements.begin(); it_set_elements != geom_set_elements.end(); ++it_set_elements )
		{
			// TYPE IfcGeometricSetSelect = SELECT (IfcPoint, IfcCurve, IfcSurface);
			shared_ptr<IfcGeometricSetSelect>& geom_select = (*it_set_elements);

			shared_ptr<IfcPoint> select_point = dynamic_pointer_cast<IfcPoint>(geom_select);
			if( select_point )
			{

				continue;
			}

			shared_ptr<IfcCurve> select_curve = dynamic_pointer_cast<IfcCurve>(geom_select);
			if( select_curve )
			{
				//convertIfcCurve( select_curve )
				continue;
			}

			shared_ptr<IfcSurface> select_surface = dynamic_pointer_cast<IfcSurface>(geom_select);
			if( select_surface )
			{
				shared_ptr<carve::input::PolylineSetData> polyline( new carve::input::PolylineSetData() );
				convertIfcSurface( select_surface, pos, polyline );
				if( polyline->getVertexCount() > 1 )
				{
					item_data->polyline_data.push_back( polyline );
				}

				//convertIfcSurface( select_surface, pos, input_data );
				continue;
			}
		}

		shared_ptr<IfcGeometricCurveSet> geometric_curve_set = dynamic_pointer_cast<IfcGeometricCurveSet>(geometric_set);
		if( geometric_curve_set )
		{
			
			return;
		}
		return;
	}

	shared_ptr<IfcSectionedSpine> sectioned_spine = dynamic_pointer_cast<IfcSectionedSpine>(geom_item);
	if( sectioned_spine )
	{
		convertIfcSectionedSpine( sectioned_spine, pos, item_data );
		return;
	}
	
	throw UnhandledRepresentationException( geom_item );
}

// ENTITY IfcSolidModel ABSTRACT SUPERTYPE OF(ONEOF(IfcCsgSolid, IfcManifoldSolidBrep, IfcSweptAreaSolid, IfcSweptDiskSolid))
void RepresentationConverter::convertIfcSolidModel( const shared_ptr<IfcSolidModel>& solid_model, const carve::math::Matrix& pos, shared_ptr<ItemData> item_data )
{
	// TODO: class SolidModelConverter

	shared_ptr<IfcSweptAreaSolid> swept_area_solid = dynamic_pointer_cast<IfcSweptAreaSolid>(solid_model);
	if( swept_area_solid )
	{
		//ENTITY IfcSweptAreaSolid
		//	ABSTRACT SUPERTYPE OF(ONEOF(IfcExtrudedAreaSolid, IfcFixedReferenceSweptAreaSolid, IfcRevolvedAreaSolid, IfcSurfaceCurveSweptAreaSolid))
		//	SUBTYPE OF IfcSolidModel;
		//	SweptArea	 :	IfcProfileDef;
		//	Position	 :	OPTIONAL IfcAxis2Placement3D;
		//	WHERE
		//	SweptAreaType	 :	SweptArea.ProfileType = IfcProfileTypeEnum.Area;
		//END_ENTITY;

		shared_ptr<IfcProfileDef>& swept_area = swept_area_solid->m_SweptArea;
		shared_ptr<IfcAxis2Placement3D>& solid_position	= swept_area_solid->m_Position;					//optional


		shared_ptr<IfcExtrudedAreaSolid> extruded_area = dynamic_pointer_cast<IfcExtrudedAreaSolid>(swept_area_solid);
		if( extruded_area )
		{
			convertIfcExtrudedAreaSolid( extruded_area, pos, item_data );
			return;
		}
		
		shared_ptr<IfcFixedReferenceSweptAreaSolid> fixed_reference_swept_area_solid = dynamic_pointer_cast<IfcFixedReferenceSweptAreaSolid>(swept_area_solid);
		if( fixed_reference_swept_area_solid )
		{
			//Directrix	 : OPTIONAL IfcCurve;
			//StartParam	 : OPTIONAL IfcParameterValue;
			//EndParam	 : OPTIONAL IfcParameterValue;
			//FixedReference	 : IfcDirection;
			

#ifdef _DEBUG
			std::cout << "IfcFixedReferenceSweptAreaSolid not implemented" << std::endl;
#endif
			return;
		}

		shared_ptr<IfcRevolvedAreaSolid> revolved_area_solid = dynamic_pointer_cast<IfcRevolvedAreaSolid>(swept_area_solid);
		if( revolved_area_solid )
		{
			convertIfcRevolvedAreaSolid( revolved_area_solid, pos, item_data );
			return;
		}
		
		shared_ptr<IfcSurfaceCurveSweptAreaSolid> surface_curve_swept_area_solid = dynamic_pointer_cast<IfcSurfaceCurveSweptAreaSolid>(swept_area_solid);
		if( surface_curve_swept_area_solid )
		{
#ifdef _DEBUG
			std::cout << "IfcSurfaceCurveSweptAreaSolid not implemented" << std::endl;
#endif
			return;
		}
		
		throw UnhandledRepresentationException( solid_model );
	}

	shared_ptr<IfcManifoldSolidBrep> manifold_solid_brep = dynamic_pointer_cast<IfcManifoldSolidBrep>(solid_model);	
	if( manifold_solid_brep )
	{
		// IFC4:
		//ENTITY IfcManifoldSolidBrep 
		//	ABSTRACT SUPERTYPE OF(ONEOF(IfcAdvancedBrep, IfcFacetedBrep))
		//	SUBTYPE OF IfcSolidModel;
		//		Outer	 :	IfcClosedShell;
		//END_ENTITY;

		shared_ptr<IfcClosedShell>& outer_shell = manifold_solid_brep->m_Outer;

		if( outer_shell )
		{
			// first convert outer shell
			std::vector<shared_ptr<IfcFace> >& vec_faces_outer_shell = outer_shell->m_CfsFaces;
			shared_ptr<ItemData> input_data_outer_shell( new ItemData() );
			convertIfcFaceList( vec_faces_outer_shell, pos, input_data_outer_shell );
			std::copy( input_data_outer_shell->open_or_closed_shell_data.begin(), input_data_outer_shell->open_or_closed_shell_data.end(), std::back_inserter(item_data->closed_shell_data) );


			//shared_ptr<IfcConnectedFaceSet> face_set = (*it_face_sets);
			//std::vector<shared_ptr<IfcFace> >& vec_ifc_faces = face_set->m_CfsFaces;

			//shared_ptr<ItemData> input_data_face_set( new ItemData );
			//convertIfcFaceList( vec_ifc_faces, pos, input_data_face_set );
			//std::copy( input_data_face_set->open_or_closed_shell_data.begin(), input_data_face_set->open_or_closed_shell_data.end(), std::back_inserter(item_data->open_shell_data) );
		

			shared_ptr<IfcFacetedBrep> faceted_brep = dynamic_pointer_cast<IfcFacetedBrep>(manifold_solid_brep);
			if( faceted_brep )
			{
				shared_ptr<IfcClosedShell> shell = faceted_brep->m_Outer;
				if( !shell )
				{
					return;
				}
				std::vector<shared_ptr<IfcFace> >& vec_ifc_faces = shell->m_CfsFaces;

				shared_ptr<ItemData> input_data_closed_shell( new ItemData() );
				convertIfcFaceList( vec_ifc_faces, pos, input_data_closed_shell );
				std::copy( input_data_closed_shell->open_or_closed_shell_data.begin(), input_data_closed_shell->open_or_closed_shell_data.end(), std::back_inserter(item_data->closed_shell_data) );

				return;
			}

			shared_ptr<IfcAdvancedBrep> advanced_brep = dynamic_pointer_cast<IfcAdvancedBrep>(manifold_solid_brep);
			if( advanced_brep )
			{
				// ENTITY IfcAdvancedBrep	SUPERTYPE OF(IfcAdvancedBrepWithVoids)
				if( dynamic_pointer_cast<IfcAdvancedBrepWithVoids>(advanced_brep) )
				{
					shared_ptr<IfcAdvancedBrepWithVoids> advanced_brep_with_voids = dynamic_pointer_cast<IfcAdvancedBrepWithVoids>(solid_model);
					std::vector<shared_ptr<IfcClosedShell> >& vec_voids = advanced_brep_with_voids->m_Voids;

					// TODO: subtract voids from outer shell
					std::cout << "IfcAdvancedBrep not implemented" << std::endl;
				}
				return;
			}
		}

			
		throw UnhandledRepresentationException( solid_model );
	}

	shared_ptr<IfcCsgSolid> csg_solid = dynamic_pointer_cast<IfcCsgSolid>(solid_model);
	if( csg_solid )
	{
		shared_ptr<IfcCsgSelect> csg_select = csg_solid->m_TreeRootExpression;

		if( dynamic_pointer_cast<IfcBooleanResult>(csg_select) )
		{
			shared_ptr<IfcBooleanResult> csg_select_boolean_result = dynamic_pointer_cast<IfcBooleanResult>(csg_select);
			convertIfcBooleanResult( csg_select_boolean_result, pos, item_data );
		}
		else if( dynamic_pointer_cast<IfcCsgPrimitive3D>(csg_select) )
		{
			shared_ptr<IfcCsgPrimitive3D> csg_select_primitive_3d = dynamic_pointer_cast<IfcCsgPrimitive3D>(csg_select);
			convertIfcCsgPrimitive3D( csg_select_primitive_3d, pos, item_data );
		}
		return;
	}

	//shared_ptr<IfcReferencedSectionedSpine> spine = dynamic_pointer_cast<IfcReferencedSectionedSpine>(solid_model);
	//if( spine )
	//{
	//	convertIfcReferencedSectionedSpine( spine, pos, item_data );
	//	return;
	//}
	
	shared_ptr<IfcSweptDiskSolid> swept_disp_solid = dynamic_pointer_cast<IfcSweptDiskSolid>(solid_model);
	if( swept_disp_solid )
	{
		//ENTITY IfcSweptDiskSolid;
		//	ENTITY IfcRepresentationItem;
		//	INVERSE
		//		LayerAssignments	 : 	SET OF IfcPresentationLayerAssignment FOR AssignedItems;
		//		StyledByItem	 : 	SET [0:1] OF IfcStyledItem FOR Item;
		//	ENTITY IfcGeometricRepresentationItem;
		//	ENTITY IfcSolidModel;
		//		DERIVE
		//		Dim	 : 	IfcDimensionCount :=  3;
		//	ENTITY IfcSweptDiskSolid;
		//		Directrix	 : 	IfcCurve;
		//		Radius	 : 	IfcPositiveLengthMeasure;
		//		InnerRadius	 : 	OPTIONAL IfcPositiveLengthMeasure;
		//		StartParam	 : 	OPTIONAL IfcParameterValue;
		//		EndParam	 : 	OPTIONAL IfcParameterValue;
		//END_ENTITY;	

		shared_ptr<IfcCurve>& directrix_curve = swept_disp_solid->m_Directrix;
		shared_ptr<IfcPositiveLengthMeasure>& radius_measure = swept_disp_solid->m_Radius;
		double length_in_meter = m_unit_converter->getLengthInMeterFactor();
		double radius = 0.0;
		if( radius_measure )
		{
			radius = radius_measure->m_value*length_in_meter;
		}

		// TODO: handle inner radius, start param, end param

		std::vector<carve::geom::vector<3> > segment_start_points;
		std::vector<carve::geom::vector<3> > basis_curve_points;
		m_curve_converter->convertIfcCurve( directrix_curve, basis_curve_points, segment_start_points );

		shared_ptr<carve::input::PolyhedronData> pipe_data( new carve::input::PolyhedronData() );
		item_data->closed_shell_data.push_back(pipe_data);

		double angle = 0;
		double delta_angle = 2.0*M_PI/double(m_num_vertices_per_circle);	// TODO: adapt to model size and complexity
		std::vector<carve::geom::vector<3> > circle_points;
		for( int i = 0; i < m_num_vertices_per_circle; ++i )
		{
			// cross section (circle) is defined in YZ plane
			circle_points.push_back( carve::geom::VECTOR(0.0, sin(angle)*radius, cos(angle)*radius) );
			angle += delta_angle;
		}
		
		int num_base_points = basis_curve_points.size();
		carve::math::Matrix matrix_sweep;
		
		carve::geom::vector<3> local_z;

		if( num_base_points < 2 )
		{
			std::cout << "IfcSweptDiskSolid: num curve points < 2";
			return;
		}

		bool bend_found = false;
		if( num_base_points > 3 )
		{
			// compute local z vector by dot product of the first bend of the reference line
			carve::geom::vector<3> vertex_back2 = basis_curve_points.at(0);
			carve::geom::vector<3> vertex_back1 = basis_curve_points.at(1);
			for( int i=2; i<num_base_points; ++i )
			{
				carve::geom::vector<3> vertex_current = basis_curve_points.at(i);
				carve::geom::vector<3> section1 = vertex_back1 - vertex_back2;
				carve::geom::vector<3> section2 = vertex_current - vertex_back1;
				section1.normalize();
				section2.normalize();

				double dot_product = dot( section1, section2 );
				double dot_product_abs = abs(dot_product);

				// if dot == 1 or -1, then points are colinear
				if( dot_product_abs < (1.0-GEOM_TOLERANCE) || dot_product_abs > (1.0+GEOM_TOLERANCE) )
				{
					// bend found, compute cross product
					carve::geom::vector<3> lateral_vec = cross( section1, section2 );
					local_z = cross( lateral_vec, section1 );
					local_z.normalize();
					bend_found = true;
					break;
				}
			}
		}
		
		if( !bend_found )
		{
			// sweeping curve is linear. assume any local z vector
			local_z = carve::geom::VECTOR( 0, 0, 1 );
			double dot_normal_local_z = dot( (basis_curve_points.at(1) - basis_curve_points.at(0)), local_z );
			if( abs(dot_normal_local_z) < GEOM_TOLERANCE )
			{
				local_z = carve::geom::VECTOR( 0, 1, 0 );
				local_z.normalize();
			}
		}

		for( int ii=0; ii<num_base_points; ++ii )
		{
			carve::geom::vector<3> vertex_current = basis_curve_points.at(ii);
			carve::geom::vector<3> vertex_next;
			carve::geom::vector<3> vertex_before;
			if( ii == 0 )
			{
				// first point
				vertex_next	= basis_curve_points.at(ii+1);
				carve::geom::vector<3> delta_element = vertex_next - vertex_current;
				vertex_before = vertex_current - (delta_element);
			}
			else if( ii == num_base_points-1 )
			{
				// last point
				vertex_before	= basis_curve_points.at(ii-1);
				carve::geom::vector<3> delta_element = vertex_current - vertex_before;
				vertex_next = vertex_before + (delta_element);
			}
			else
			{
				// inner point
				vertex_next		= basis_curve_points.at(ii+1);
				vertex_before	= basis_curve_points.at(ii-1);
			}

			carve::geom::vector<3> bisecting_normal;
			bisectingPlane( bisecting_normal, vertex_before, vertex_current, vertex_next );

			carve::geom::vector<3> section1 = vertex_current - vertex_before;
			carve::geom::vector<3> section2 = vertex_next - vertex_current;
			section1.normalize();
			section2.normalize();
			double dot_product = dot( section1, section2 );
			double dot_product_abs = abs(dot_product);

			if( dot_product_abs < (1.0-GEOM_TOLERANCE) || dot_product_abs > (1.0+GEOM_TOLERANCE) )
			{
				// bend found, compute next local z vector
				carve::geom::vector<3> lateral_vec = cross( section1, section2 );
				local_z = cross( lateral_vec, section1 );
				local_z.normalize();
			}
			if( ii == num_base_points -1 )
			{
				bisecting_normal *= -1.0;
			}
			
			convertPlane2Matrix( bisecting_normal, vertex_current, local_z, matrix_sweep );
			matrix_sweep = pos*matrix_sweep;
						
			for( int jj = 0; jj < m_num_vertices_per_circle; ++jj )
			{
				carve::geom::vector<3> vertex = circle_points.at( jj );
				vertex = matrix_sweep*vertex;
				pipe_data->addVertex( vertex );
			}
		}

		// front cap
		std::vector<int> front_face_loop;
		for( int jj = 0; jj < m_num_vertices_per_circle; ++jj )
		{
			front_face_loop.push_back( jj );
		}
		pipe_data->addFace( front_face_loop.rbegin(), front_face_loop.rend() );

		// end cap
		std::vector<int> end_face_loop;
		const int end_face_begin = (num_base_points-1)*m_num_vertices_per_circle;
		for( int j = 0; j < m_num_vertices_per_circle; ++j )
		{
			end_face_loop.push_back( end_face_begin + j );
		}
		pipe_data->addFace( end_face_loop.begin(), end_face_loop.end() );
				

		int num_vertices = pipe_data->getVertexCount();
		for( int i=0; i<num_base_points- 1; ++i )
		{
			int i_offset = i*m_num_vertices_per_circle;
			int i_offset_next = (i+1)*m_num_vertices_per_circle;
			for( int jj = 0; jj < m_num_vertices_per_circle-1; ++jj )
			{
				pipe_data->addFace( i_offset + jj, i_offset + jj+1, i_offset_next + jj + 1, i_offset_next + jj );  
			}
			pipe_data->addFace( i_offset + m_num_vertices_per_circle-2, i_offset, i_offset_next, i_offset_next + m_num_vertices_per_circle-2 );  
		}

		return;
	}

	throw UnhandledRepresentationException( solid_model );
}

double failed_geom_offset = 10;
void RepresentationConverter::convertIfcBooleanResult( const shared_ptr<IfcBooleanResult>& bool_result, const carve::math::Matrix& pos, shared_ptr<ItemData> item_data )
{
	const int bool_result_id = bool_result->getId();
	
	std::stringstream err;
	shared_ptr<IfcBooleanClippingResult> boolean_clipping_result = dynamic_pointer_cast<IfcBooleanClippingResult>(bool_result);
	if( boolean_clipping_result )
	{
		shared_ptr<IfcBooleanOperator> boolean_operator = boolean_clipping_result->m_Operator;
		shared_ptr<IfcBooleanOperand> first_operand = boolean_clipping_result->m_FirstOperand;
		shared_ptr<IfcBooleanOperand> second_operand = boolean_clipping_result->m_SecondOperand;

		if( !boolean_operator || !first_operand || !second_operand )
		{
			return;
		}
		
		carve::csg::CSG::OP csg_operation = carve::csg::CSG::A_MINUS_B;
		if( boolean_operator->m_enum == IfcBooleanOperator::ENUM_UNION )
		{
			csg_operation = carve::csg::CSG::UNION;
		}
		else if( boolean_operator->m_enum == IfcBooleanOperator::ENUM_INTERSECTION )
		{
			csg_operation = carve::csg::CSG::INTERSECTION;
		}
		else if( boolean_operator->m_enum == IfcBooleanOperator::ENUM_DIFFERENCE )
		{
			csg_operation = carve::csg::CSG::A_MINUS_B;
		}

		shared_ptr<ItemData> input_data_first_operand( new ItemData() );
		convertIfcBooleanOperand( first_operand, pos, input_data_first_operand );

		std::vector<shared_ptr<carve::mesh::MeshSet<3> > > polyhedrons_first_operand( input_data_first_operand->polyhedrons );
		for( unsigned int i=0; i<input_data_first_operand->closed_shell_data.size(); ++i )
		{
			shared_ptr<carve::input::PolyhedronData>& polyhedron_data = input_data_first_operand->closed_shell_data[i];
			if( polyhedron_data->getVertexCount() < 3 )
			{
				continue;
			}

			carve::input::Options carve_options;
			shared_ptr<carve::mesh::MeshSet<3> > polyhedron( polyhedron_data->createMesh(carve_options) );
			polyhedrons_first_operand.push_back( polyhedron );

#ifdef _DEBUG
#ifndef IFCPP_OPENMP

			bool show_operands = false;
			if( show_operands )
			{
				if( m_debug_viewer )
				{
					osg::ref_ptr<osg::Geode> geode = new osg::Geode();
					ConverterOSG carve_converter;
					carve_converter.drawMeshSet( polyhedron, geode );
					osg::Group* group = (osg::Group*)m_debug_viewer->getSceneData();
					group->addChild(geode);

					//osg::ref_ptr<osg::PolygonMode> polygon_mode = dynamic_cast<osg::PolygonMode*>( geode->getOrCreateStateSet()->getAttribute( osg::StateAttribute::POLYGONMODE ));
					//if(  !polygon_mode )
					//{
						osg::ref_ptr<osg::PolygonMode> polygon_mode = new osg::PolygonMode();
						geode->getOrCreateStateSet()->setAttribute( polygon_mode );	
					//}
					polygon_mode->setMode(  osg::PolygonMode::FRONT_AND_BACK, osg::PolygonMode::LINE );
				}
			}
#endif
#endif
		}

		shared_ptr<ItemData> input_data_second_operand( new ItemData() );
		convertIfcBooleanOperand( second_operand, pos, input_data_second_operand );

		std::vector<shared_ptr<carve::mesh::MeshSet<3> > > polyhedrons_second_operand( input_data_second_operand->polyhedrons );
		for( unsigned int i=0; i<input_data_second_operand->closed_shell_data.size(); ++i )
		{
			shared_ptr<carve::input::PolyhedronData>& polyhedron_data = input_data_second_operand->closed_shell_data[i];
			if( polyhedron_data->getVertexCount() < 3 )
			{
				continue;
			}

			carve::input::Options carve_options;
			polyhedrons_second_operand.push_back( shared_ptr<carve::mesh::MeshSet<3> >(polyhedron_data->createMesh(carve_options) ) );
		}

		// for every first operands, apply all second operands
		std::vector<shared_ptr<carve::mesh::MeshSet<3> > >::iterator it_first_operands;
		for( it_first_operands=polyhedrons_first_operand.begin(); it_first_operands!=polyhedrons_first_operand.end(); ++it_first_operands )
		{
			shared_ptr<carve::mesh::MeshSet<3> >& first_operand_poly = (*it_first_operands);

			std::vector<shared_ptr<carve::mesh::MeshSet<3> > >::iterator it_second_operands;
			for( it_second_operands=polyhedrons_second_operand.begin(); it_second_operands!=polyhedrons_second_operand.end(); ++it_second_operands )
			{
				shared_ptr<carve::mesh::MeshSet<3> >& second_operand = (*it_second_operands);

#ifdef _DEBUG
				shared_ptr<carve::poly::Polyhedron> first_op_polyhedron( carve::polyhedronFromMesh(first_operand_poly.get(), -1 ) ); // -1 takes all meshes
				std::stringstream strs;
				for( int mani=0; mani<first_op_polyhedron->manifoldCount(); ++mani )
				{
					if( !first_op_polyhedron->manifold_is_closed[mani] )
					{
						strs << "!first_operand_poly->manifold_is_closed[mani]";
					}
					if( first_op_polyhedron->manifold_is_negative[mani] )
					{
						strs << "!first_operand_poly->manifold_is_negative[mani]";
					}
				}

				if( m_debug_viewer )
				{
					osg::Node* root_node = m_debug_viewer->getSceneData();
					osg::Group* root_node_group = dynamic_cast<osg::Group*>( root_node );
					if( root_node_group )
					{
						osg::ref_ptr<osg::Geode> geode = new osg::Geode();
						ConverterOSG carve_converter;
						carve_converter.drawPolyhedron( first_op_polyhedron, geode );
						
						//carve_converter.drawMeshSet( second_operand, geode );
						root_node_group->addChild(geode);

						m_debug_viewer->frame();
						osg::BoundingSphere bs = root_node_group->computeBound();

						//osgGA::TrackballManipulator* manip = (osgGA::TrackballManipulator*)debug_viewer->getCameraManipulator();
						osgGA::StandardManipulator* manip = (osgGA::StandardManipulator*)m_debug_viewer->getCameraManipulator();

						osg::Vec3d eye_before;
						osg::Vec3d lookat_before;
						osg::Vec3d up_before;
						manip->getTransformation( eye_before, lookat_before, up_before );

						osg::Vec3d lookat_new = bs.center();
						osg::Vec3d eye_new = lookat_new - (lookat_before-eye_before);
						manip->setTransformation( eye_new, lookat_new, up_before );

						//manip->setCenter( bs.center() );

						//zoomToBoundingSphere( m_debug_viewer, bs );
						//m_debug_viewer->frame();
						//zoomToBoundingSphere( m_debug_viewer, bs );

						
					}
					do
					{
						m_debug_viewer->frame();
					}
					while( !m_debug_viewer->done() );
					m_debug_viewer->setDone( false );
				}

				shared_ptr<carve::poly::Polyhedron> second_op_polyhedron( carve::polyhedronFromMesh(second_operand.get(), -1 ) ); // -1 takes all meshes
				for( unsigned int mani=0; mani<second_op_polyhedron->manifoldCount(); ++mani )
				{
					if( !second_op_polyhedron->manifold_is_closed[mani] )
					{
						strs << "!second_operand->manifold_is_closed[mani]";
					}
					if( second_op_polyhedron->manifold_is_negative[mani] )
					{
						strs << "!second_operand->manifold_is_negative[mani]";
					}
				}
				
				detailedReport( strs );
#endif
				bool csg_failed = false;
				carve::csg::CSG csg;
				try
				{
					// TODO: switch off std::cerr output in carve in release mode
					if( first_operand_poly->meshes.size() > 0 && second_operand->meshes.size() > 0 )
					{
						shared_ptr<carve::mesh::MeshSet<3> > result_poly( csg.compute( first_operand_poly.get(), second_operand.get(), csg_operation, NULL, carve::csg::CSG::CLASSIFY_NORMAL) );
						if( result_poly->meshes.size() > 0 )
						{
							first_operand_poly = result_poly;
						}
					}
					else
					{
#ifdef _DEBUG
						std::cout << "second_operand->meshes.size() == 0" << std::endl;
#endif
					}
				}
				catch( carve::exception& ce )
				{
					csg_failed = true;
					err << ce.str();
				}
				catch(std::exception& e)
				{
					csg_failed = true;
					err << e.what();
				}
				catch(...)
				{
					csg_failed = true;
					err << "convertIfcProduct: csg operation failed" << std::endl;
				}

#ifdef _DEBUG
#ifndef IFCPP_OPENMP
				if( csg_failed )
				{
					osg::ref_ptr<osg::Geode> geode = new osg::Geode();
					ConverterOSG carve_converter;
					carve_converter.drawMeshSet( first_operand_poly, geode );
					osg::ref_ptr<osg::MatrixTransform> mt = new osg::MatrixTransform( osg::Matrix::translate(0, 0, failed_geom_offset ) );
					mt->addChild(geode);
					failed_geom_offset += 3;

					carve_converter.drawMeshSet( second_operand, geode );
					
					if( m_debug_viewer )
					{
						osg::Node* root_node = m_debug_viewer->getSceneData();
						osg::Group* root_node_group = dynamic_cast<osg::Group*>( root_node );
						if( root_node_group )
						{
							root_node_group->addChild(mt);
						}
						do
						{
							m_debug_viewer->frame();
						}
						while( !m_debug_viewer->done() );
						m_debug_viewer->setDone( false );
					}
				}
#endif
#endif
			}
		}

		// now copy processed first operands to result input data
		for( it_first_operands=polyhedrons_first_operand.begin(); it_first_operands!=polyhedrons_first_operand.end(); ++it_first_operands )
		{
			shared_ptr<carve::mesh::MeshSet<3> >& first_operand_poly = (*it_first_operands);
			item_data->polyhedrons.push_back(first_operand_poly);
		}
	}

	if( err.tellp() > 0 )
	{
		detailedReport( err );
		//throw IfcPPException( err.str().c_str() );
	}
}

void RepresentationConverter::convertIfcBooleanOperand( const shared_ptr<IfcBooleanOperand>& operand, const carve::math::Matrix& pos, shared_ptr<ItemData> item_data )
{
	shared_ptr<IfcSolidModel> solid_model = dynamic_pointer_cast<IfcSolidModel>(operand);
	if( solid_model )
	{
		convertIfcSolidModel( solid_model, pos, item_data );
		return;
	}
	double length_factor = m_unit_converter->getLengthInMeterFactor();

	shared_ptr<IfcHalfSpaceSolid> half_space_solid = dynamic_pointer_cast<IfcHalfSpaceSolid>(operand);
	if( half_space_solid )
	{
		//ENTITY IfcHalfSpaceSolid SUPERTYPE OF(ONEOF(IfcBoxedHalfSpace, IfcPolygonalBoundedHalfSpace))
		shared_ptr<IfcSurface> base_surface = half_space_solid->m_BaseSurface;
		bool agreement = half_space_solid->m_AgreementFlag;
		
		shared_ptr<carve::input::PolylineSetData> surface_data ( new carve::input::PolylineSetData() );
		convertIfcSurface( base_surface, pos, surface_data );
		std::vector<carve::geom3d::Vector>& points = surface_data->points;

		// If the agreement flag is TRUE, then the subset is the one the normal points away from
		if( !agreement )
		{
			std::reverse( points.begin(), points.end() );
		}
		carve::geom3d::Vector plane_normal = computePolygonNormal( points );

		// TODO: optimize: classify against plane instead of box
		shared_ptr<carve::input::PolyhedronData> box_data( new carve::input::PolyhedronData() );
		item_data->closed_shell_data.push_back(box_data);
		std::vector<int> face_top, face_bottom;
		const int num_vertices = points.size();

		// create geometry
		double box_depth = 10000.f;
		int begin_face_index;
		for( int k=0; k<num_vertices; ++k )
		{
			carve::geom3d::Vector& point = points.at(k);
			carve::geom3d::Vector point_extruded = point - plane_normal*(box_depth);

			box_data->addVertex( point );
			box_data->addVertex( point_extruded );

			face_bottom.push_back( num_vertices*2 - 1 - k*2 );
			face_top.push_back( k*2 );

			begin_face_index = k*2;
			if( k < num_vertices - 1 )
			{
				box_data->addFace( begin_face_index, begin_face_index + 1, begin_face_index + 3, begin_face_index + 2 );
			}
		}
		box_data->addFace( num_vertices*2-2, num_vertices*2-1, 1, 0 );
		box_data->addFace(face_top.begin(), face_top.end());
		box_data->addFace(face_bottom.begin(), face_bottom.end());

		//group->setName("HalfSpaceSolid");
		
		if( dynamic_pointer_cast<IfcBoxedHalfSpace>(half_space_solid) )
		{
			shared_ptr<IfcBoxedHalfSpace> boxed_half_space = dynamic_pointer_cast<IfcBoxedHalfSpace>(half_space_solid);
			shared_ptr<IfcBoundingBox> bbox = boxed_half_space->m_Enclosure;

		}
		else if( dynamic_pointer_cast<IfcPolygonalBoundedHalfSpace>(half_space_solid) )
		{
			shared_ptr<IfcPolygonalBoundedHalfSpace> polygonal_half_space = dynamic_pointer_cast<IfcPolygonalBoundedHalfSpace>(half_space_solid);
			shared_ptr<IfcAxis2Placement3D>& primitive_placement = polygonal_half_space->m_Position;

			carve::math::Matrix primitive_placement_matrix( carve::math::Matrix::IDENT() );
			if( primitive_placement )
			{
				PlacementConverter::convertIfcAxis2Placement3D( primitive_placement, primitive_placement_matrix, length_factor );
				primitive_placement_matrix = pos*primitive_placement_matrix;
			}

			shared_ptr<IfcBoundedCurve> bounded_curve = polygonal_half_space->m_PolygonalBoundary;
			std::vector<carve::geom::vector<3> > loops;
			std::vector<carve::geom::vector<3> > segment_start_points;
			m_curve_converter->convertIfcCurve( bounded_curve, loops, segment_start_points );

			shared_ptr<carve::input::PolyhedronData> box_data( new carve::input::PolyhedronData() );
			item_data->closed_shell_data.push_back(box_data);

			// apply parent position
			for( unsigned int i=0; i<loops.size(); ++i )
			{
				carve::geom::vector<3>& vertex = loops.at(i);
				vertex = primitive_placement_matrix*vertex;
				box_data->addVertex( vertex );
			}

			// TODO: create faces

			std::cout << "IfcPolygonalBoundedHalfSpace: not implemented" << std::endl;
		}
		return;
	}
	
	shared_ptr<IfcBooleanResult> boolean_result = dynamic_pointer_cast<IfcBooleanResult>(operand);
	if( boolean_result )
	{
		convertIfcBooleanResult( boolean_result, pos, item_data );
		return;
	}

	shared_ptr<IfcCsgPrimitive3D> csg_primitive3D = dynamic_pointer_cast<IfcCsgPrimitive3D>(operand);
	if( csg_primitive3D )
	{
		convertIfcCsgPrimitive3D( csg_primitive3D, pos, item_data );
		return;
	}

	UnhandledRepresentationException unhadled_abstract;
	unhadled_abstract.m_select = operand;
	throw unhadled_abstract;
}

void RepresentationConverter::convertIfcExtrudedAreaSolid( const shared_ptr<IfcExtrudedAreaSolid>& extruded_area, const carve::math::Matrix& pos, shared_ptr<ItemData> item_data )
{
	if( !extruded_area->m_ExtrudedDirection )
	{
		return;
	}

	if( !extruded_area->m_Depth )
	{
		return;
	}
	double length_factor = m_unit_converter->getLengthInMeterFactor();

	// check if local coordinate system is specified for extrusion
	carve::math::Matrix extrusion_pos_matrix( pos );
	if( extruded_area->m_Position )
	{
		shared_ptr<IfcAxis2Placement3D> extrusion_position = extruded_area->m_Position;
		PlacementConverter::convertIfcAxis2Placement3D( extrusion_position, extrusion_pos_matrix, length_factor );
		extrusion_pos_matrix = pos*extrusion_pos_matrix;
	}

	// direction and length of extrusion
	const double depth = extruded_area->m_Depth->m_value*length_factor;
	carve::geom3d::Vector extrusion_vector;
	std::vector<double>& vec_direction = extruded_area->m_ExtrudedDirection->m_DirectionRatios;
	if( vec_direction.size() > 2 )
	{
		extrusion_vector = carve::geom::VECTOR( vec_direction[0]*depth, vec_direction[1]*depth, vec_direction[2]*depth );
	}
	else if( vec_direction.size() > 1 )
	{
		extrusion_vector = carve::geom::VECTOR( vec_direction[0]*depth, vec_direction[1]*depth, 0 );
	}

	// swept area
	shared_ptr<IfcProfileDef>	swept_area = extruded_area->m_SweptArea;
	shared_ptr<ProfileConverter> profile_converter = getProfileConverter(swept_area);

	const std::vector<std::vector<carve::geom::vector<3> > >& paths = profile_converter->getCoordinates();
	shared_ptr<carve::input::PolyhedronData> poly_data( new carve::input::PolyhedronData );
	extrude( paths, extrusion_vector, *(poly_data.get()) );

	std::vector<carve::geom3d::Vector>& points = poly_data->points;
	for( int i=0; i<points.size(); ++i )
	{
		points[i] = extrusion_pos_matrix*points[i];
	}

	item_data->closed_shell_data.push_back(poly_data);
}

void RepresentationConverter::convertIfcRevolvedAreaSolid( const shared_ptr<IfcRevolvedAreaSolid>& revolved_area, const carve::math::Matrix& pos, shared_ptr<ItemData> item_data )
{
	if( !revolved_area->m_SweptArea )
	{
		return;
	}
	double length_factor = m_unit_converter->getLengthInMeterFactor();
	
	// local placement of revolved object
	carve::math::Matrix revolution_pos_matrix( pos );
	if( revolved_area->m_Position )
	{
		shared_ptr<IfcAxis2Placement3D> position = revolved_area->m_Position;
		PlacementConverter::convertIfcAxis2Placement3D( position, revolution_pos_matrix, length_factor );
		revolution_pos_matrix = pos*revolution_pos_matrix;
	}

	// angle and axis
	double angle_factor = m_unit_converter->getAngleInRadianFactor();
	shared_ptr<IfcProfileDef> swept_area_profile = revolved_area->m_SweptArea;
	double revolution_angle = revolved_area->m_Angle->m_value*angle_factor;

	carve::geom3d::Vector axis_location;
	carve::geom3d::Vector axis_direction;
	if(revolved_area->m_Axis)
	{
		shared_ptr<IfcAxis1Placement> axis_placement = revolved_area->m_Axis;

		if( axis_placement->m_Location )
		{
			shared_ptr<IfcCartesianPoint> location_point = axis_placement->m_Location;
			m_curve_converter->convertIfcCartesianPoint( location_point, axis_location );
		}

		if( axis_placement->m_Axis )
		{
			shared_ptr<IfcDirection> axis = axis_placement->m_Axis;
			axis_direction = carve::geom::VECTOR( axis->m_DirectionRatios[0], axis->m_DirectionRatios[1], axis->m_DirectionRatios[2] );
		}
	}

	// rotation base point is the one with the smallest distance on the rotation axis
	carve::geom3d::Vector origin;
	carve::geom3d::Vector base_point;
	closestPointOnLine( base_point, origin, axis_location, axis_direction );
	base_point *= -1;

	// swept area
	shared_ptr<ProfileConverter> profile_converter = getProfileConverter(swept_area_profile);
	const std::vector<std::vector<carve::geom::vector<3> > >& profile_coords = profile_converter->getCoordinates();

	if( profile_coords.size() == 0 )
	{
		std::stringstream strs;
		strs << "#" << revolved_area->getId() << " = IfcRevolvedAreaSolid: convertIfcRevolvedAreaSolid: num_loops == 0";
		detailedReport( strs );
		return;
		//throw IfcPPException("RepresentationConverter::convertIfcRevolvedAreaSolid: num_loops == 0");
	}
	if( profile_coords[0].size() < 3 )
	{
		std::stringstream strs;
		strs << "#" << revolved_area->getId() << " = IfcRevolvedAreaSolid: convertIfcRevolvedAreaSolid: num_polygon_points < 3";
		detailedReport( strs );
		//throw IfcPPException("RepresentationConverter::convertIfcRevolvedAreaSolid: num_polygon_points < 3");
	}

	if( revolution_angle > M_PI*2 ) revolution_angle = M_PI*2;
	if( revolution_angle < -M_PI*2 ) revolution_angle = M_PI*2;

	// TODO: calculate num segments according to length/width/height ratio and overall size of the object
	const int num_segments = m_num_vertices_per_circle*(abs(revolution_angle)/(2.0*M_PI));
	double angle = 0.0;
	double d_angle = revolution_angle/num_segments;

	// check if we have to change the direction
	carve::geom3d::Vector polygon_normal = computePolygonNormal( profile_coords[0] );
	carve::geom3d::Vector pt0 = carve::math::Matrix::ROT(d_angle, axis_direction )*(profile_coords[0][0]+base_point);
	if( polygon_normal.z*pt0.z > 0 )
	{
		angle = revolution_angle;
		d_angle = -d_angle;
	}

	shared_ptr<carve::input::PolyhedronData> polyhedron_data( new carve::input::PolyhedronData() );
	item_data->closed_shell_data.push_back(polyhedron_data);

	// create vertices
	carve::math::Matrix m;
	for( int i = 0; i <= num_segments; ++i )
	{
		m = carve::math::Matrix::ROT( angle, -axis_direction );
		for( int j=0; j<profile_coords.size(); ++j )
		{
			const std::vector<carve::geom::vector<3> >& loop = profile_coords[j];
			
			for( int k=0; k<loop.size(); ++k )
			{
				carve::geom3d::Vector vertex= m*(loop[k]+base_point) - base_point;
				polyhedron_data->addVertex( revolution_pos_matrix*vertex );
			}
		}
		angle += d_angle;
	}

	// front cap
	std::vector<int> front_face_loop;
	int num_polygon_points = 0;
	for( int j=0; j<profile_coords.size(); ++j )
	{
		const std::vector<carve::geom::vector<3> >& loop = profile_coords[j];

		for( int k=0; k<loop.size(); ++k )
		{
			front_face_loop.push_back( j*loop.size() + k );
			++num_polygon_points;
		}
	}
	polyhedron_data->addFace( front_face_loop.rbegin(), front_face_loop.rend() );

	// end cap
	std::vector<int> end_face_loop;
	const int end_face_begin = num_segments*num_polygon_points;
	for( int j = 0; j < num_polygon_points; ++j )
	{
		end_face_loop.push_back( end_face_begin + j );
	}
	polyhedron_data->addFace( end_face_loop.begin(), end_face_loop.end() );

	// faces of revolved shape
	for( int i = 0; i < num_polygon_points-1; ++i )
	{
		int i_offset_next = i + num_polygon_points;
		for( int j = 0; j < num_segments; ++j )
		{
			int j_offset = j*num_polygon_points;
			polyhedron_data->addFace( j_offset+i, j_offset+i+1, j_offset+1+i_offset_next, j_offset+i_offset_next );
		}
	}

	for( int j = 0; j < num_segments; ++j )
	{
		int j_offset = j*num_polygon_points;
		polyhedron_data->addFace( j_offset+num_polygon_points-1, j_offset, j_offset+num_polygon_points, j_offset+num_polygon_points+num_polygon_points-1 );
	}
}

void RepresentationConverter::convertIfcCsgPrimitive3D(	const shared_ptr<IfcCsgPrimitive3D>& csg_primitive,	const carve::math::Matrix& pos, shared_ptr<ItemData> item_data )
{
	shared_ptr<carve::input::PolyhedronData> polyhedron_data( new carve::input::PolyhedronData() );
	
	double length_factor = m_unit_converter->getLengthInMeterFactor();

	// ENTITY IfcCsgPrimitive3D  ABSTRACT SUPERTYPE OF(ONEOF(IfcBlock, IfcRectangularPyramid, IfcRightCircularCone, IfcRightCircularCylinder, IfcSphere
	shared_ptr<IfcAxis2Placement3D>& primitive_placement = csg_primitive->m_Position;

	carve::math::Matrix primitive_placement_matrix( pos );
	if( primitive_placement )
	{
		PlacementConverter::convertIfcAxis2Placement3D( primitive_placement, primitive_placement_matrix, length_factor );
		primitive_placement_matrix = pos*primitive_placement_matrix;
	}

	shared_ptr<IfcBlock> block = dynamic_pointer_cast<IfcBlock>(csg_primitive);
	if( block )
	{
		double x_length = length_factor;
		double y_length = length_factor;
		double z_length = length_factor;

		if( block->m_XLength )
		{
			x_length = block->m_XLength->m_value*0.5*length_factor;
		}
		if( block->m_YLength )
		{
			y_length = block->m_YLength->m_value*0.5*length_factor;
		}
		if( block->m_ZLength )
		{
			z_length = block->m_ZLength->m_value*0.5*length_factor;
		}

		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR( x_length, y_length, z_length));
		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR(-x_length, y_length, z_length));
		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR(-x_length,-y_length, z_length));
		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR( x_length,-y_length, z_length));
		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR( x_length, y_length,-z_length));
		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR(-x_length, y_length,-z_length));
		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR(-x_length,-y_length,-z_length));
		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR( x_length,-y_length,-z_length));

		polyhedron_data->addFace(0,	1, 2, 3);
		polyhedron_data->addFace(7, 6, 5, 4);
		polyhedron_data->addFace(0,	4, 5, 1);
		polyhedron_data->addFace(1, 5, 6, 2);
		polyhedron_data->addFace(2, 6, 7, 3);
		polyhedron_data->addFace(3, 7, 4, 0);
		
		item_data->closed_shell_data.push_back( polyhedron_data );
		return;
	}

	shared_ptr<IfcRectangularPyramid> rectangular_pyramid = dynamic_pointer_cast<IfcRectangularPyramid>(csg_primitive);
	if( rectangular_pyramid )
	{
		double x_length = length_factor;
		double y_length = length_factor;
		double height = length_factor;

		if( rectangular_pyramid->m_XLength )
		{
			x_length = rectangular_pyramid->m_XLength->m_value*0.5*length_factor;
		}
		if( rectangular_pyramid->m_YLength )
		{
			y_length = rectangular_pyramid->m_YLength->m_value*0.5*length_factor;
		}
		if( rectangular_pyramid->m_Height )
		{
			height = rectangular_pyramid->m_Height->m_value*0.5*length_factor;
		}

		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR(0, 0, height) );
		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR( x_length,-y_length, 0.0) );
		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR(-x_length,-y_length, 0.0) );
		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR(-x_length, y_length, 0.0) );
		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR( x_length, y_length, 0.0) );

		polyhedron_data->addFace(1,	2, 3, 4);
		polyhedron_data->addFace(0,	2, 1);
		polyhedron_data->addFace(0,	1, 4);
		polyhedron_data->addFace(0,	4, 3);
		polyhedron_data->addFace(0,	3, 2);

		item_data->closed_shell_data.push_back( polyhedron_data );
		return;
	}

	shared_ptr<IfcRightCircularCone> right_circular_cone = dynamic_pointer_cast<IfcRightCircularCone>(csg_primitive);
	if( right_circular_cone )
	{
		double height = length_factor;
		double radius = length_factor;
		if( right_circular_cone->m_Height )
		{
			height = right_circular_cone->m_Height->m_value*length_factor;
		}
		if( right_circular_cone->m_BottomRadius )
		{
			radius = right_circular_cone->m_BottomRadius->m_value*length_factor;
		}

		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR(0.0, 0.0, height) ); // top
		polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR(0.0, 0.0, 0.0) ); // bottom center

		//const int num_segments = 24;
		double angle = 0;
		double d_angle = 2.0*M_PI/double(m_num_vertices_per_circle);	// TODO: adapt to model size and complexity
		for( int i = 0; i < m_num_vertices_per_circle; ++i )
		{
			polyhedron_data->addVertex( primitive_placement_matrix*carve::geom::VECTOR(sin(angle)*radius, cos(angle)*radius, 0.0) );
			angle += d_angle;
		}

		// outer shape
		for( int i = 0; i < m_num_vertices_per_circle-1; ++i )
		{
			polyhedron_data->addFace(0, i+3, i+2);
		}
		polyhedron_data->addFace( 0, 2, m_num_vertices_per_circle+1 );

		// bottom circle
		for( int i = 0; i < m_num_vertices_per_circle-1; ++i )
		{
			polyhedron_data->addFace(1, i+2, i+3 );
		}
		polyhedron_data->addFace(1, m_num_vertices_per_circle+1, 2 );

		item_data->closed_shell_data.push_back( polyhedron_data );
		return;
	}

	shared_ptr<IfcRightCircularCylinder> right_circular_cylinder = dynamic_pointer_cast<IfcRightCircularCylinder>(csg_primitive);
	if( right_circular_cylinder )
	{
		// TODO: implement

		//input_data.closed_shell_data.push_back( polyhedron_data );
		return;
	}

	shared_ptr<IfcSphere> sphere = dynamic_pointer_cast<IfcSphere>(csg_primitive);
	if( sphere )
	{
		// TODO: implement

		//input_data.closed_shell_data.push_back( polyhedron_data );
		return;
	}
	throw UnhandledRepresentationException(csg_primitive);
}



void RepresentationConverter::convertIfcPropertySet( const shared_ptr<IfcPropertySet>& prop_set, osg::Group* group )
{
	std::vector<shared_ptr<IfcProperty> >& vec_hasProperties = prop_set->m_HasProperties;

	std::vector<shared_ptr<IfcProperty> >::iterator it;
	for( it=vec_hasProperties.begin(); it!=vec_hasProperties.end(); ++it )
	{
		shared_ptr<IfcProperty> prop = (*it);

		shared_ptr<IfcSimpleProperty> simple_property = dynamic_pointer_cast<IfcSimpleProperty>(prop);
		if( simple_property )
		{
			
			shared_ptr<IfcIdentifier> name = simple_property->m_Name;
			shared_ptr<IfcText> description = simple_property->m_Description;

			//ENTITY IfcSimpleProperty
			//ABSTRACT SUPERTYPE OF(ONEOF(
			//IfcPropertyBoundedValue,
			//IfcPropertyEnumeratedValue,
			//IfcPropertyListValue,
			//IfcPropertyReferenceValue,
			//IfcPropertySingleValue,
			//IfcPropertyTableValue))
			continue;
		}
		
		shared_ptr<IfcComplexProperty> complex_property = dynamic_pointer_cast<IfcComplexProperty>(prop);
		if( complex_property )
		{
			std::vector<shared_ptr<IfcProperty> >& vec_HasProperties = complex_property->m_HasProperties;
			if( !complex_property->m_UsageName ) continue;
			if( complex_property->m_UsageName->m_value.compare( "Color" ) == 0 )
			{

#ifdef IFCPP_OPENMP
				omp_set_lock(&m_writelock_styles_converter);
				osg::ref_ptr<osg::StateSet> stateset = m_styles_converter->convertIfcComplexPropertyColor( complex_property );
				omp_unset_lock(&m_writelock_styles_converter);
#else
				osg::ref_ptr<osg::StateSet> stateset = m_styles_converter->convertIfcComplexPropertyColor( complex_property );
#endif

				if( stateset.valid() )
				{
					group->setStateSet( stateset );
				}
			}
		}
	}
}

void RepresentationConverter::convertIfcSurface( const shared_ptr<IfcSurface>& surface, const carve::math::Matrix& pos, shared_ptr<carve::input::PolylineSetData>& polyline_data )
{
	double length_factor = m_unit_converter->getLengthInMeterFactor();
	//ENTITY IfcSurface ABSTRACT SUPERTYPE OF(ONEOF(IfcBoundedSurface, IfcElementarySurface, IfcSweptSurface))

	shared_ptr<IfcBoundedSurface> bounded_surface = dynamic_pointer_cast<IfcBoundedSurface>(surface);
	if( bounded_surface )
	{
		// ENTITY IfcBoundedSurface ABSTRACT SUPERTYPE OF(ONEOF(IfcBSplineSurface, IfcCurveBoundedPlane, IfcCurveBoundedSurface, IfcRectangularTrimmedSurface))
		if( dynamic_pointer_cast<IfcBSplineSurface>(bounded_surface) )
		{
			if( dynamic_pointer_cast<IfcRationalBSplineSurfaceWithKnots>(bounded_surface) )
			{
				shared_ptr<IfcRationalBSplineSurfaceWithKnots> nurbs_surface = dynamic_pointer_cast<IfcRationalBSplineSurfaceWithKnots>(bounded_surface);
				convertIfcBSplineSurface( nurbs_surface, pos, polyline_data );
			}
		}
		else if( dynamic_pointer_cast<IfcCurveBoundedPlane>(bounded_surface) )
		{
			// ENTITY IfcCurveBoundedPlane SUBTYPE OF IfcBoundedSurface;
			shared_ptr<IfcCurveBoundedPlane> curve_bounded_plane = dynamic_pointer_cast<IfcCurveBoundedPlane>(bounded_surface);
			carve::math::Matrix curve_bounded_plane_matrix( pos );
			shared_ptr<IfcPlane>& basis_surface = curve_bounded_plane->m_BasisSurface;
			if( basis_surface )
			{
				shared_ptr<IfcAxis2Placement3D>& basis_surface_placement = basis_surface->m_Position;
				
				if( basis_surface_placement )
				{
					PlacementConverter::convertIfcAxis2Placement3D( basis_surface_placement, curve_bounded_plane_matrix, length_factor );
					curve_bounded_plane_matrix = pos*curve_bounded_plane_matrix;
				}
			}
			shared_ptr<IfcCurve>& outer_boundary = curve_bounded_plane->m_OuterBoundary;
			if( outer_boundary )
			{
				//convertIfcCurve( outer_boundary, target,  );
				// TODO: implement boundary
			}
			std::vector<shared_ptr<IfcCurve> >& vec_inner_boundaries = curve_bounded_plane->m_InnerBoundaries;
			for( unsigned int i=0; i<vec_inner_boundaries.size(); ++i )
			{
				shared_ptr<IfcCurve>& inner_curve = vec_inner_boundaries[i];
				//convertIfcCurve( outer_boundary)
				// TODO: implement boundary
			}
		}
		else if( dynamic_pointer_cast<IfcCurveBoundedSurface>(bounded_surface) )
		{
			shared_ptr<IfcCurveBoundedSurface> curve_bounded_surface = dynamic_pointer_cast<IfcCurveBoundedSurface>(bounded_surface);
			shared_ptr<IfcSurface>& basis_surface = curve_bounded_surface->m_BasisSurface;
			if( basis_surface )
			{
				convertIfcSurface( basis_surface, pos, polyline_data );
			}

			std::vector<shared_ptr<IfcBoundaryCurve> >& vec_boundaries = curve_bounded_surface->m_Boundaries;
			bool implicit_outer = curve_bounded_surface->m_ImplicitOuter;
			// TODO: implement
		}
		else if( dynamic_pointer_cast<IfcRectangularTrimmedSurface>(bounded_surface) )
		{
			shared_ptr<IfcRectangularTrimmedSurface> rectengular_trimmed_surface = dynamic_pointer_cast<IfcRectangularTrimmedSurface>(bounded_surface);

			shared_ptr<IfcSurface>& basis_surface = rectengular_trimmed_surface->m_BasisSurface;
			if( basis_surface )
			{
				convertIfcSurface( basis_surface, pos, polyline_data );
			}

			shared_ptr<IfcParameterValue>& u1 = rectengular_trimmed_surface->m_U1;
			shared_ptr<IfcParameterValue>& v1 = rectengular_trimmed_surface->m_V1;
			shared_ptr<IfcParameterValue>& u2 = rectengular_trimmed_surface->m_U2;
			shared_ptr<IfcParameterValue>& v2 = rectengular_trimmed_surface->m_V2;
			bool u_sense = rectengular_trimmed_surface->m_Usense;
			bool v_sense = rectengular_trimmed_surface->m_Vsense;
			// TODO: implement
		}
		return;
	}

	shared_ptr<IfcElementarySurface> elementary_surface = dynamic_pointer_cast<IfcElementarySurface>(surface);
	if( elementary_surface )
	{
		//ENTITY IfcElementarySurface	ABSTRACT SUPERTYPE OF(ONEOF(IfcCylindricalSurface, IfcPlane))
		shared_ptr<IfcAxis2Placement3D>& elementary_surface_placement = elementary_surface->m_Position;

		carve::math::Matrix elementary_surface_matrix( pos );
		if( elementary_surface_placement )
		{
			PlacementConverter::convertIfcAxis2Placement3D( elementary_surface_placement, elementary_surface_matrix, length_factor );
			elementary_surface_matrix = pos*elementary_surface_matrix;
		}
	
		shared_ptr<IfcPlane> elementary_surface_plane = dynamic_pointer_cast<IfcPlane>(elementary_surface);
		if( elementary_surface_plane )
		{
			//  1----0     create big rectangular plane
			//  |    |     ^ y
			//  |    |     |
			//  2----3     ---> x
			{
#ifdef _DEBUG
				float plane_span = 10.f;
#else
				float plane_span = 100000.f;
#endif

				polyline_data->beginPolyline();
				polyline_data->addVertex( elementary_surface_matrix*carve::geom::VECTOR( plane_span,  plane_span, 0.0 ));
				polyline_data->addVertex( elementary_surface_matrix*carve::geom::VECTOR(-plane_span,  plane_span, 0.0 ));
				polyline_data->addVertex( elementary_surface_matrix*carve::geom::VECTOR(-plane_span, -plane_span, 0.0 ));
				polyline_data->addVertex( elementary_surface_matrix*carve::geom::VECTOR( plane_span, -plane_span, 0.0 ));

				polyline_data->addPolylineIndex(0);
				polyline_data->addPolylineIndex(1);
				polyline_data->addPolylineIndex(2);
				polyline_data->addPolylineIndex(3);
			}
			return;
		}

		shared_ptr<IfcCylindricalSurface> cylindrical_surface = dynamic_pointer_cast<IfcCylindricalSurface>(elementary_surface);
		if( cylindrical_surface )
		{
			shared_ptr<IfcPositiveLengthMeasure> cylindrical_surface_radius = cylindrical_surface->m_Radius;
			double circle_radius = cylindrical_surface_radius->m_value;

			int num_segments = m_num_vertices_per_circle;	// TODO: adapt to model size and complexity
			double start_angle = 0.0;
			double opening_angle = M_PI*2.0;
			const double circle_center_x = 0.0;
			const double circle_center_y = 0.0;

			std::vector<carve::geom::vector<3> > circle_points;
			ProfileConverter::addArcWithEndPoint( circle_points, circle_radius, start_angle, opening_angle, circle_center_x, circle_center_y, num_segments );

			// apply position and insert points
			polyline_data->beginPolyline();
			for( int i=0; i<circle_points.size(); ++i )
			{
				carve::geom::vector<3> point = circle_points.at(i);
				polyline_data->addVertex( elementary_surface_matrix*point );
				polyline_data->addPolylineIndex(i);
			}
			return;
		}

		throw UnhandledRepresentationException(surface);
	}
	
	shared_ptr<IfcSweptSurface> swept_surface = dynamic_pointer_cast<IfcSweptSurface>(surface);
	if( dynamic_pointer_cast<IfcSweptSurface>(surface) )
	{
		// ENTITY IfcSweptSurface	ABSTRACT SUPERTYPE OF(ONEOF(IfcSurfaceOfLinearExtrusion, IfcSurfaceOfRevolution))
		shared_ptr<IfcProfileDef>& swept_surface_profile = swept_surface->m_SweptCurve;
		shared_ptr<IfcAxis2Placement3D>& swept_surface_placement = swept_surface->m_Position;

		carve::math::Matrix swept_surface_matrix( pos );
		if( swept_surface_placement )
		{
			PlacementConverter::convertIfcAxis2Placement3D( swept_surface_placement, swept_surface_matrix, length_factor );
			swept_surface_matrix = pos*swept_surface_matrix;
		}

		shared_ptr<IfcSurfaceOfLinearExtrusion> linear_extrusion = dynamic_pointer_cast<IfcSurfaceOfLinearExtrusion>(swept_surface);
		if( linear_extrusion )
		{
			shared_ptr<IfcDirection>& linear_extrusion_direction = linear_extrusion->m_ExtrudedDirection;
			shared_ptr<IfcLengthMeasure>& linear_extrusion_depth = linear_extrusion->m_Depth;
			// TODO: implement
			return;
		}
		
		shared_ptr<IfcSurfaceOfRevolution> suface_of_revolution = dynamic_pointer_cast<IfcSurfaceOfRevolution>(swept_surface);
		if( suface_of_revolution )
		{
			// TODO: implement
			return;
		}

		throw UnhandledRepresentationException(surface);
	}
	throw UnhandledRepresentationException(surface);
}

void RepresentationConverter::convertIfcFaceList( const std::vector<shared_ptr<IfcFace> >& faces, const carve::math::Matrix& pos, shared_ptr<ItemData> item_data )
{
	shared_ptr<carve::input::PolyhedronData> poly_data( new carve::input::PolyhedronData() );

	// TODO: check if std::unordered_map is faster, hash value is concatenated string of coordinates with a certain precision
	std::map<carve::geom3d::Vector, size_t> vert_idx;
	std::map<carve::geom3d::Vector, size_t>::iterator vert_it;

	enum FaceProjectionPlane
	{
		UNDEFINED,
		XY_PLANE,
		YZ_PLANE,
		XZ_PLANE
	};

	std::vector<shared_ptr<IfcFace> >::const_iterator it_ifc_faces;
	for( it_ifc_faces=faces.begin(); it_ifc_faces!=faces.end(); ++it_ifc_faces )
	{
		const shared_ptr<IfcFace>& face = (*it_ifc_faces);
		std::vector<shared_ptr<IfcFaceBound> >& vec_bounds = face->m_Bounds;

		std::vector<std::vector<carve::geom2d::P2> > face_loops_2d;
		std::vector<std::vector<carve::geom3d::Vector> > face_loops;
		std::vector<std::vector<double> > face_loop_3rd_dim;
		bool face_loop_reversed = false;

		int i_bound = 0;
		FaceProjectionPlane face_plane = UNDEFINED;

		std::vector<shared_ptr<IfcFaceBound> >::iterator it_bounds;
		for( it_bounds=vec_bounds.begin(); it_bounds!=vec_bounds.end(); ++it_bounds, ++i_bound )
		{
			shared_ptr<IfcFaceBound> face_bound = (*it_bounds);

			std::vector<carve::geom2d::P2> path_loop;
			std::vector<double> path_loop_3rd_dim;

			// ENTITY IfcLoop SUPERTYPE OF(ONEOF(IfcEdgeLoop, IfcPolyLoop, IfcVertexLoop))
			shared_ptr<IfcLoop> loop = face_bound->m_Bound;
			if( !loop )
			{
				continue;
			}

			bool orientation = face_bound->m_Orientation;

			const shared_ptr<IfcPolyLoop> poly_loop = dynamic_pointer_cast<IfcPolyLoop>( loop );
			if( poly_loop )
			{
				const std::vector<shared_ptr<IfcCartesianPoint> >&    ifc_points = poly_loop->m_Polygon;
				std::vector<carve::geom3d::Vector> vertices_bound;

				const int num_loop_points = ifc_points.size();
				if( num_loop_points == 3 )
				{
					// TODO: insert triangle and continue
				}
				else if( num_loop_points == 4 )
				{
					// TODO: insert two triangles and continue
				}

				m_curve_converter->convertIfcCartesianPointVectorSkipDuplicates( ifc_points, vertices_bound );
				//convertIfcCartesianPointVectorSkipDuplicates( ifc_points, vertices_bound );

				// if first and last point have same coordinates, remove last point
				while( vertices_bound.size() > 2 )
				{
					carve::geom3d::Vector& first = vertices_bound.front();
					carve::geom3d::Vector& last = vertices_bound.back();

					if( abs(first.x-last.x) < 0.00000001 )
					{
						if( abs(first.y-last.y) < 0.00000001 )
						{
							if( abs(first.z-last.z) < 0.00000001 )
							{
								vertices_bound.pop_back();
								continue;
							}
						}
					}
					break;
				}


				if( vertices_bound.size() < 3 )
				{
					if( it_bounds == vec_bounds.begin() )
					{
						break;
					}
					else
					{
						continue;
					}
				}

				if( !orientation )
				{
					std::reverse( vertices_bound.begin(), vertices_bound.end() );
				}
				carve::geom3d::Vector normal = computePolygonNormal( vertices_bound );

				if( it_bounds == vec_bounds.begin() )
				{
					double nx = abs(normal.x);
					double ny = abs(normal.y);
					double nz = abs(normal.z);
					if( nz > nx && nz >= ny )
					{
						face_plane = XY_PLANE;
					}
					else if( nx >= ny && nx >= nz )
					{
						face_plane = YZ_PLANE;
					}
					else if( ny > nx && ny >= nz )
					{
						face_plane = XZ_PLANE;
					}
					else
					{
						std::stringstream strs;
						strs << "#" << poly_loop->getId() << " = IfcPolyLoop: " << poly_loop->getId() << " unable to project to plane: nx" << nx << " ny " << ny << " nz " << nz << std::endl;
						for( int i=0; i<vertices_bound.size(); ++i )
						{
							carve::geom3d::Vector& point = vertices_bound.at(i);
							strs << "bound vertex i " << i << "=(" << point.x << "," << point.y << "," << point.z << ")\n";
						}

						detailedReport( strs );
						continue;
						//throw IfcPPException( strs.str().c_str() );
					}
				}

				// project face into 2d plane
				for( int i=0; i<vertices_bound.size(); ++i )
				{
					carve::geom3d::Vector& point = vertices_bound.at(i);

					if( face_plane == XY_PLANE )
					{
						path_loop.push_back( carve::geom::VECTOR(point.x, point.y ));
						path_loop_3rd_dim.push_back(point.z);
					}
					else if( face_plane == YZ_PLANE )
					{
						path_loop.push_back( carve::geom::VECTOR(point.y, point.z ));
						path_loop_3rd_dim.push_back(point.x);
					}
					else if( face_plane == XZ_PLANE )
					{
						path_loop.push_back( carve::geom::VECTOR(point.x, point.z ));
						path_loop_3rd_dim.push_back(point.y);
					}
				}
				
				// check winding order
				carve::geom3d::Vector normal_2d = computePolygon2DNormal( path_loop );
				if( it_bounds == vec_bounds.begin() )
				{
					if( normal_2d.z < 0 )
					{
						std::reverse( path_loop.begin(), path_loop.end() );
						face_loop_reversed = true;
					}
				}
				else
				{
					if( normal_2d.z > 0 )
					{
						std::reverse( path_loop.begin(), path_loop.end() );
					}
				}
				face_loops_2d.push_back(path_loop);
				face_loop_3rd_dim.push_back(path_loop_3rd_dim);
				continue;
			}

			shared_ptr<IfcEdgeLoop> edge_loop = dynamic_pointer_cast<IfcEdgeLoop>( loop );
			if( edge_loop )
			{
				std::vector<shared_ptr<IfcOrientedEdge> >& edge_list = edge_loop->m_EdgeList;
				std::vector<shared_ptr<IfcOrientedEdge> >::iterator it_edge;
				for( it_edge=edge_list.begin(); it_edge!=edge_list.end(); ++it_edge )
				{
					shared_ptr<IfcOrientedEdge> oriented_edge = (*it_edge);
					shared_ptr<IfcEdge> edge = oriented_edge->m_EdgeElement;

					shared_ptr<IfcVertex> edge_start = edge->m_EdgeStart;
					shared_ptr<IfcVertexPoint> edge_start_point = dynamic_pointer_cast<IfcVertexPoint>(edge_start);
					if( edge_start_point )
					{
						if( edge_start_point->m_VertexGeometry )
						{
							shared_ptr<IfcPoint> edge_start_point_geometry = edge_start_point->m_VertexGeometry;
							shared_ptr<IfcCartesianPoint> ifc_point = dynamic_pointer_cast<IfcCartesianPoint>(edge_start_point_geometry);
							if( !ifc_point )
							{
								// TODO: could be also  IfcPointOnCurve, IfcPointOnSurface
								continue;
							}



							// TODO: implement

						}
					}
					shared_ptr<IfcVertex> edge_end = edge->m_EdgeEnd;
					shared_ptr<IfcVertexPoint> edge_end_point = dynamic_pointer_cast<IfcVertexPoint>(edge_end);
					if( edge_end_point )
					{
						if( edge_end_point->m_VertexGeometry )
						{
							shared_ptr<IfcPoint> edge_point_geometry = edge_end_point->m_VertexGeometry;
							shared_ptr<IfcCartesianPoint> ifc_point = dynamic_pointer_cast<IfcCartesianPoint>(edge_point_geometry);

							if( !ifc_point )
							{
								// TODO: could be also  IfcPointOnCurve, IfcPointOnSurface
								continue;
							}

							// TODO: implement
						}
					}
				}
				face_loops_2d.push_back(path_loop);
				continue;
			}

			shared_ptr<IfcVertexLoop> vertex_loop = dynamic_pointer_cast<IfcVertexLoop>( loop );
			if( vertex_loop )
			{
				continue;

				shared_ptr<IfcVertex> v = vertex_loop->m_LoopVertex;

				shared_ptr<IfcVertexPoint> vp = dynamic_pointer_cast<IfcVertexPoint>(v);
				if( vp )
				{
					if( vp->m_VertexGeometry )
					{
						shared_ptr<IfcPoint> point = vp->m_VertexGeometry;
						shared_ptr<IfcCartesianPoint> cp = dynamic_pointer_cast<IfcCartesianPoint>(point);
						// could be also  IfcPointOnCurve, IfcPointOnSurface
					}
				}
			}
		}

		if( face_loops_2d.size() == 0 )
		{
			continue;
		}

		std::vector<std::pair<size_t, size_t> > result; // first is loop index, second is vertex index in loop
		std::vector<carve::geom2d::P2> merged;
		std::vector<carve::geom3d::Vector> merged_3d;
		std::vector<carve::triangulate::tri_idx> triangulated;

		// TODO: apply this triangulation also in ProfileConverter and ExtrudedAreaSolid

		try
		{
			result = carve::triangulate::incorporateHolesIntoPolygon(face_loops_2d);
			merged.reserve(result.size());
			for( size_t i = 0; i < result.size(); ++i )
			{
				int loop_number = result[i].first;
				int index_in_loop = result[i].second;
				carve::geom2d::P2& loop_point = face_loops_2d[loop_number][index_in_loop];
				merged.push_back( loop_point );

				// restore 3rd dimension
				if( face_loop_reversed )
				{
					index_in_loop = face_loops_2d[loop_number].size() - index_in_loop - 1;
				}

				carve::geom3d::Vector v;
				if( face_plane == XY_PLANE )
				{
					double z = face_loop_3rd_dim[loop_number][index_in_loop];
					v = carve::geom::VECTOR(	loop_point.x,	loop_point.y,	z);
				}
				else if( face_plane == YZ_PLANE )
				{
					double x = face_loop_3rd_dim[loop_number][index_in_loop];
					v = carve::geom::VECTOR(	x,	loop_point.x,	loop_point.y);
				}
				else if( face_plane == XZ_PLANE )
				{
					double y = face_loop_3rd_dim[loop_number][index_in_loop];
					v = carve::geom::VECTOR(	loop_point.x,	y,	loop_point.y);
				}
				merged_3d.push_back( pos * v );
			}
			carve::triangulate::triangulate(merged, triangulated);
			carve::triangulate::improve(merged, triangulated);

		}
		catch(...)
		{
			std::stringstream strs;
			strs << "convertIfcFaceList: carve::triangulate::incorporateHolesIntoPolygon failed " << std::endl;
			strs << "IfcFace id: " << face->getId() << std::endl;

			std::vector<std::vector<carve::geom2d::P2> >::iterator it_face_looops_2d;
			for( it_face_looops_2d = face_loops_2d.begin(); it_face_looops_2d!=face_loops_2d.end(); ++it_face_looops_2d )
			{
				std::vector<carve::geom2d::P2>& single_loop_2d = *it_face_looops_2d;
				std::vector<carve::geom2d::P2>::iterator it_face_loop;
				strs << "loop:\n";
				for( it_face_loop = single_loop_2d.begin(); it_face_loop!=single_loop_2d.end(); ++it_face_loop )
				{
					carve::geom2d::P2& loop_point = *it_face_loop;
					strs << "	bound vertex (" << loop_point.x << "," << loop_point.y << ")\n";
				}
			}
			detailedReport( strs );
			//throw IfcPPException( strs.str().c_str() );
			continue;
		}

		// now insert points to polygon, avoiding points with same coordinates
		std::map<int,int> map_merged_idx;
		for( size_t i = 0; i != merged.size(); ++i )
		{
			carve::geom3d::Vector v = merged_3d[i];
			// TODO: check if this could become a bottleneck with large meshes. try maybe string based map (x,y,z as string key)
			vert_it = vert_idx.find(v);
			if( vert_it == vert_idx.end() )
			{
				poly_data->addVertex(v);
				int vertex_id = poly_data->getVertexCount()-1;
				vert_idx[v] = vertex_id;
				map_merged_idx[i] = vertex_id;
			}
			else
			{
				// vertex already exists in polygon. remember its index for triangles
				map_merged_idx[i]=(*vert_it).second;
			}
		}
		for( size_t i = 0; i != triangulated.size(); ++i )
		{
			carve::triangulate::tri_idx triangle = triangulated[i];
			int a = triangle.a;
			int b = triangle.b;
			int c = triangle.c;

			int vertex_id_a = map_merged_idx[a];
			int vertex_id_b = map_merged_idx[b];
			int vertex_id_c = map_merged_idx[c];

#ifdef _DEBUG
			const carve::poly::Vertex<3>& v_a = poly_data->getVertex(vertex_id_a);
			const carve::poly::Vertex<3>& v_b = poly_data->getVertex(vertex_id_b);

			double dx = v_a.v[0] - v_b.v[0];
			if( abs(dx) < 0.0000001 )
			{
				double dy = v_a.v[1] - v_b.v[1];
				if( abs(dy) < 0.0000001 )
				{
					double dz = v_a.v[2] - v_b.v[2];
					if( abs(dz) < 0.0000001 )
						std::cerr << "abs(dx) < 0.00001 && abs(dy) < 0.00001 && abs(dz) < 0.00001\n";
				}
			}
#endif

			if( face_loop_reversed )
			{
				poly_data->addFace( vertex_id_a, vertex_id_c, vertex_id_b );
			}
			else
			{
				poly_data->addFace( vertex_id_a, vertex_id_b, vertex_id_c );
			}
		}
	}

	// IfcFaceList can be a closed or open shell, so let the calling function decide where to put it
	item_data->open_or_closed_shell_data.push_back( poly_data );
}


shared_ptr<ProfileConverter> RepresentationConverter::getProfileConverter( shared_ptr<IfcProfileDef>& ifc_profile )
{
	const int profile_id = ifc_profile->getId();
	
	std::map<int,shared_ptr<ProfileConverter> >::iterator it_profile_cache = m_profile_cache.find(profile_id);
	if( it_profile_cache != m_profile_cache.end() )
	{
		return it_profile_cache->second;
	}

	shared_ptr<ProfileConverter> profile_converter = shared_ptr<ProfileConverter>( new ProfileConverter( m_unit_converter ) );
	profile_converter->setNumVerticesPerCircle( m_num_vertices_per_circle );
	profile_converter->setProfile( ifc_profile );
#ifdef IFCPP_OPENMP
	omp_set_lock(&m_writelock_profile_cache);
	m_profile_cache[profile_id] = profile_converter;
	omp_unset_lock(&m_writelock_profile_cache);
#else
	m_profile_cache[profile_id] = profile_converter;
#endif
		
	return profile_converter;
}


void RepresentationConverter::detailedReport( std::stringstream& strs )
{
#ifdef IFCPP_OPENMP
	omp_set_lock(&m_writelock_detailed_report);
	m_detailed_report << strs.str().c_str() << std::endl;
	omp_unset_lock(&m_writelock_detailed_report);
#else
	m_detailed_report << strs.str().c_str() << std::endl;
#endif
}