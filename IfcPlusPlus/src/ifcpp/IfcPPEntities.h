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
#include "IFC4//include/IfcActionRequest.h"
#include "IFC4//include/IfcActor.h"
#include "IFC4//include/IfcActorRole.h"
#include "IFC4//include/IfcActuator.h"
#include "IFC4//include/IfcActuatorType.h"
#include "IFC4//include/IfcAddress.h"
#include "IFC4//include/IfcAdvancedBrep.h"
#include "IFC4//include/IfcAdvancedBrepWithVoids.h"
#include "IFC4//include/IfcAdvancedFace.h"
#include "IFC4//include/IfcAirTerminal.h"
#include "IFC4//include/IfcAirTerminalBox.h"
#include "IFC4//include/IfcAirTerminalBoxType.h"
#include "IFC4//include/IfcAirTerminalType.h"
#include "IFC4//include/IfcAirToAirHeatRecovery.h"
#include "IFC4//include/IfcAirToAirHeatRecoveryType.h"
#include "IFC4//include/IfcAlarm.h"
#include "IFC4//include/IfcAlarmType.h"
#include "IFC4//include/IfcAnnotation.h"
#include "IFC4//include/IfcAnnotationFillArea.h"
#include "IFC4//include/IfcApplication.h"
#include "IFC4//include/IfcAppliedValue.h"
#include "IFC4//include/IfcApproval.h"
#include "IFC4//include/IfcApprovalRelationship.h"
#include "IFC4//include/IfcArbitraryClosedProfileDef.h"
#include "IFC4//include/IfcArbitraryOpenProfileDef.h"
#include "IFC4//include/IfcArbitraryProfileDefWithVoids.h"
#include "IFC4//include/IfcAsset.h"
#include "IFC4//include/IfcAsymmetricIShapeProfileDef.h"
#include "IFC4//include/IfcAudioVisualAppliance.h"
#include "IFC4//include/IfcAudioVisualApplianceType.h"
#include "IFC4//include/IfcAxis1Placement.h"
#include "IFC4//include/IfcAxis2Placement2D.h"
#include "IFC4//include/IfcAxis2Placement3D.h"
#include "IFC4//include/IfcBSplineCurve.h"
#include "IFC4//include/IfcBSplineCurveWithKnots.h"
#include "IFC4//include/IfcBSplineSurface.h"
#include "IFC4//include/IfcBSplineSurfaceWithKnots.h"
#include "IFC4//include/IfcBeam.h"
#include "IFC4//include/IfcBeamStandardCase.h"
#include "IFC4//include/IfcBeamType.h"
#include "IFC4//include/IfcBlobTexture.h"
#include "IFC4//include/IfcBlock.h"
#include "IFC4//include/IfcBoiler.h"
#include "IFC4//include/IfcBoilerType.h"
#include "IFC4//include/IfcBooleanClippingResult.h"
#include "IFC4//include/IfcBooleanResult.h"
#include "IFC4//include/IfcBoundaryCondition.h"
#include "IFC4//include/IfcBoundaryCurve.h"
#include "IFC4//include/IfcBoundaryEdgeCondition.h"
#include "IFC4//include/IfcBoundaryFaceCondition.h"
#include "IFC4//include/IfcBoundaryNodeCondition.h"
#include "IFC4//include/IfcBoundaryNodeConditionWarping.h"
#include "IFC4//include/IfcBoundedCurve.h"
#include "IFC4//include/IfcBoundedSurface.h"
#include "IFC4//include/IfcBoundingBox.h"
#include "IFC4//include/IfcBoxedHalfSpace.h"
#include "IFC4//include/IfcBuilding.h"
#include "IFC4//include/IfcBuildingElement.h"
#include "IFC4//include/IfcBuildingElementPart.h"
#include "IFC4//include/IfcBuildingElementPartType.h"
#include "IFC4//include/IfcBuildingElementProxy.h"
#include "IFC4//include/IfcBuildingElementProxyType.h"
#include "IFC4//include/IfcBuildingElementType.h"
#include "IFC4//include/IfcBuildingStorey.h"
#include "IFC4//include/IfcBuildingSystem.h"
#include "IFC4//include/IfcBurner.h"
#include "IFC4//include/IfcBurnerType.h"
#include "IFC4//include/IfcCShapeProfileDef.h"
#include "IFC4//include/IfcCableCarrierFitting.h"
#include "IFC4//include/IfcCableCarrierFittingType.h"
#include "IFC4//include/IfcCableCarrierSegment.h"
#include "IFC4//include/IfcCableCarrierSegmentType.h"
#include "IFC4//include/IfcCableFitting.h"
#include "IFC4//include/IfcCableFittingType.h"
#include "IFC4//include/IfcCableSegment.h"
#include "IFC4//include/IfcCableSegmentType.h"
#include "IFC4//include/IfcCartesianPoint.h"
#include "IFC4//include/IfcCartesianPointList.h"
#include "IFC4//include/IfcCartesianPointList3D.h"
#include "IFC4//include/IfcCartesianTransformationOperator.h"
#include "IFC4//include/IfcCartesianTransformationOperator2D.h"
#include "IFC4//include/IfcCartesianTransformationOperator2DnonUniform.h"
#include "IFC4//include/IfcCartesianTransformationOperator3D.h"
#include "IFC4//include/IfcCartesianTransformationOperator3DnonUniform.h"
#include "IFC4//include/IfcCenterLineProfileDef.h"
#include "IFC4//include/IfcChiller.h"
#include "IFC4//include/IfcChillerType.h"
#include "IFC4//include/IfcChimney.h"
#include "IFC4//include/IfcChimneyType.h"
#include "IFC4//include/IfcCircle.h"
#include "IFC4//include/IfcCircleHollowProfileDef.h"
#include "IFC4//include/IfcCircleProfileDef.h"
#include "IFC4//include/IfcCivilElement.h"
#include "IFC4//include/IfcCivilElementType.h"
#include "IFC4//include/IfcClassification.h"
#include "IFC4//include/IfcClassificationReference.h"
#include "IFC4//include/IfcClosedShell.h"
#include "IFC4//include/IfcCoil.h"
#include "IFC4//include/IfcCoilType.h"
#include "IFC4//include/IfcColourRgb.h"
#include "IFC4//include/IfcColourRgbList.h"
#include "IFC4//include/IfcColourSpecification.h"
#include "IFC4//include/IfcColumn.h"
#include "IFC4//include/IfcColumnStandardCase.h"
#include "IFC4//include/IfcColumnType.h"
#include "IFC4//include/IfcCommunicationsAppliance.h"
#include "IFC4//include/IfcCommunicationsApplianceType.h"
#include "IFC4//include/IfcComplexProperty.h"
#include "IFC4//include/IfcComplexPropertyTemplate.h"
#include "IFC4//include/IfcCompositeCurve.h"
#include "IFC4//include/IfcCompositeCurveOnSurface.h"
#include "IFC4//include/IfcCompositeCurveSegment.h"
#include "IFC4//include/IfcCompositeProfileDef.h"
#include "IFC4//include/IfcCompressor.h"
#include "IFC4//include/IfcCompressorType.h"
#include "IFC4//include/IfcCondenser.h"
#include "IFC4//include/IfcCondenserType.h"
#include "IFC4//include/IfcConic.h"
#include "IFC4//include/IfcConnectedFaceSet.h"
#include "IFC4//include/IfcConnectionCurveGeometry.h"
#include "IFC4//include/IfcConnectionGeometry.h"
#include "IFC4//include/IfcConnectionPointEccentricity.h"
#include "IFC4//include/IfcConnectionPointGeometry.h"
#include "IFC4//include/IfcConnectionSurfaceGeometry.h"
#include "IFC4//include/IfcConnectionVolumeGeometry.h"
#include "IFC4//include/IfcConstraint.h"
#include "IFC4//include/IfcConstructionEquipmentResource.h"
#include "IFC4//include/IfcConstructionEquipmentResourceType.h"
#include "IFC4//include/IfcConstructionMaterialResource.h"
#include "IFC4//include/IfcConstructionMaterialResourceType.h"
#include "IFC4//include/IfcConstructionProductResource.h"
#include "IFC4//include/IfcConstructionProductResourceType.h"
#include "IFC4//include/IfcConstructionResource.h"
#include "IFC4//include/IfcConstructionResourceType.h"
#include "IFC4//include/IfcContext.h"
#include "IFC4//include/IfcContextDependentUnit.h"
#include "IFC4//include/IfcControl.h"
#include "IFC4//include/IfcController.h"
#include "IFC4//include/IfcControllerType.h"
#include "IFC4//include/IfcConversionBasedUnit.h"
#include "IFC4//include/IfcConversionBasedUnitWithOffset.h"
#include "IFC4//include/IfcCooledBeam.h"
#include "IFC4//include/IfcCooledBeamType.h"
#include "IFC4//include/IfcCoolingTower.h"
#include "IFC4//include/IfcCoolingTowerType.h"
#include "IFC4//include/IfcCoordinateOperation.h"
#include "IFC4//include/IfcCoordinateReferenceSystem.h"
#include "IFC4//include/IfcCostItem.h"
#include "IFC4//include/IfcCostSchedule.h"
#include "IFC4//include/IfcCostValue.h"
#include "IFC4//include/IfcCovering.h"
#include "IFC4//include/IfcCoveringType.h"
#include "IFC4//include/IfcCrewResource.h"
#include "IFC4//include/IfcCrewResourceType.h"
#include "IFC4//include/IfcCsgPrimitive3D.h"
#include "IFC4//include/IfcCsgSolid.h"
#include "IFC4//include/IfcCurrencyRelationship.h"
#include "IFC4//include/IfcCurtainWall.h"
#include "IFC4//include/IfcCurtainWallType.h"
#include "IFC4//include/IfcCurve.h"
#include "IFC4//include/IfcCurveBoundedPlane.h"
#include "IFC4//include/IfcCurveBoundedSurface.h"
#include "IFC4//include/IfcCurveStyle.h"
#include "IFC4//include/IfcCurveStyleFont.h"
#include "IFC4//include/IfcCurveStyleFontAndScaling.h"
#include "IFC4//include/IfcCurveStyleFontPattern.h"
#include "IFC4//include/IfcCylindricalSurface.h"
#include "IFC4//include/IfcDamper.h"
#include "IFC4//include/IfcDamperType.h"
#include "IFC4//include/IfcDerivedProfileDef.h"
#include "IFC4//include/IfcDerivedUnit.h"
#include "IFC4//include/IfcDerivedUnitElement.h"
#include "IFC4//include/IfcDimensionalExponents.h"
#include "IFC4//include/IfcDirection.h"
#include "IFC4//include/IfcDiscreteAccessory.h"
#include "IFC4//include/IfcDiscreteAccessoryType.h"
#include "IFC4//include/IfcDistributionChamberElement.h"
#include "IFC4//include/IfcDistributionChamberElementType.h"
#include "IFC4//include/IfcDistributionCircuit.h"
#include "IFC4//include/IfcDistributionControlElement.h"
#include "IFC4//include/IfcDistributionControlElementType.h"
#include "IFC4//include/IfcDistributionElement.h"
#include "IFC4//include/IfcDistributionElementType.h"
#include "IFC4//include/IfcDistributionFlowElement.h"
#include "IFC4//include/IfcDistributionFlowElementType.h"
#include "IFC4//include/IfcDistributionPort.h"
#include "IFC4//include/IfcDistributionSystem.h"
#include "IFC4//include/IfcDocumentInformation.h"
#include "IFC4//include/IfcDocumentInformationRelationship.h"
#include "IFC4//include/IfcDocumentReference.h"
#include "IFC4//include/IfcDoor.h"
#include "IFC4//include/IfcDoorLiningProperties.h"
#include "IFC4//include/IfcDoorPanelProperties.h"
#include "IFC4//include/IfcDoorStandardCase.h"
#include "IFC4//include/IfcDoorStyle.h"
#include "IFC4//include/IfcDoorType.h"
#include "IFC4//include/IfcDraughtingPreDefinedColour.h"
#include "IFC4//include/IfcDraughtingPreDefinedCurveFont.h"
#include "IFC4//include/IfcDuctFitting.h"
#include "IFC4//include/IfcDuctFittingType.h"
#include "IFC4//include/IfcDuctSegment.h"
#include "IFC4//include/IfcDuctSegmentType.h"
#include "IFC4//include/IfcDuctSilencer.h"
#include "IFC4//include/IfcDuctSilencerType.h"
#include "IFC4//include/IfcEdge.h"
#include "IFC4//include/IfcEdgeCurve.h"
#include "IFC4//include/IfcEdgeLoop.h"
#include "IFC4//include/IfcElectricAppliance.h"
#include "IFC4//include/IfcElectricApplianceType.h"
#include "IFC4//include/IfcElectricDistributionBoard.h"
#include "IFC4//include/IfcElectricDistributionBoardType.h"
#include "IFC4//include/IfcElectricFlowStorageDevice.h"
#include "IFC4//include/IfcElectricFlowStorageDeviceType.h"
#include "IFC4//include/IfcElectricGenerator.h"
#include "IFC4//include/IfcElectricGeneratorType.h"
#include "IFC4//include/IfcElectricMotor.h"
#include "IFC4//include/IfcElectricMotorType.h"
#include "IFC4//include/IfcElectricTimeControl.h"
#include "IFC4//include/IfcElectricTimeControlType.h"
#include "IFC4//include/IfcElement.h"
#include "IFC4//include/IfcElementAssembly.h"
#include "IFC4//include/IfcElementAssemblyType.h"
#include "IFC4//include/IfcElementComponent.h"
#include "IFC4//include/IfcElementComponentType.h"
#include "IFC4//include/IfcElementQuantity.h"
#include "IFC4//include/IfcElementType.h"
#include "IFC4//include/IfcElementarySurface.h"
#include "IFC4//include/IfcEllipse.h"
#include "IFC4//include/IfcEllipseProfileDef.h"
#include "IFC4//include/IfcEnergyConversionDevice.h"
#include "IFC4//include/IfcEnergyConversionDeviceType.h"
#include "IFC4//include/IfcEngine.h"
#include "IFC4//include/IfcEngineType.h"
#include "IFC4//include/IfcEvaporativeCooler.h"
#include "IFC4//include/IfcEvaporativeCoolerType.h"
#include "IFC4//include/IfcEvaporator.h"
#include "IFC4//include/IfcEvaporatorType.h"
#include "IFC4//include/IfcEvent.h"
#include "IFC4//include/IfcEventTime.h"
#include "IFC4//include/IfcEventType.h"
#include "IFC4//include/IfcExtendedProperties.h"
#include "IFC4//include/IfcExternalInformation.h"
#include "IFC4//include/IfcExternalReference.h"
#include "IFC4//include/IfcExternalReferenceRelationship.h"
#include "IFC4//include/IfcExternalSpatialElement.h"
#include "IFC4//include/IfcExternalSpatialStructureElement.h"
#include "IFC4//include/IfcExternallyDefinedHatchStyle.h"
#include "IFC4//include/IfcExternallyDefinedSurfaceStyle.h"
#include "IFC4//include/IfcExternallyDefinedTextFont.h"
#include "IFC4//include/IfcExtrudedAreaSolid.h"
#include "IFC4//include/IfcExtrudedAreaSolidTapered.h"
#include "IFC4//include/IfcFace.h"
#include "IFC4//include/IfcFaceBasedSurfaceModel.h"
#include "IFC4//include/IfcFaceBound.h"
#include "IFC4//include/IfcFaceOuterBound.h"
#include "IFC4//include/IfcFaceSurface.h"
#include "IFC4//include/IfcFacetedBrep.h"
#include "IFC4//include/IfcFacetedBrepWithVoids.h"
#include "IFC4//include/IfcFailureConnectionCondition.h"
#include "IFC4//include/IfcFan.h"
#include "IFC4//include/IfcFanType.h"
#include "IFC4//include/IfcFastener.h"
#include "IFC4//include/IfcFastenerType.h"
#include "IFC4//include/IfcFeatureElement.h"
#include "IFC4//include/IfcFeatureElementAddition.h"
#include "IFC4//include/IfcFeatureElementSubtraction.h"
#include "IFC4//include/IfcFillAreaStyle.h"
#include "IFC4//include/IfcFillAreaStyleHatching.h"
#include "IFC4//include/IfcFillAreaStyleTiles.h"
#include "IFC4//include/IfcFilter.h"
#include "IFC4//include/IfcFilterType.h"
#include "IFC4//include/IfcFireSuppressionTerminal.h"
#include "IFC4//include/IfcFireSuppressionTerminalType.h"
#include "IFC4//include/IfcFixedReferenceSweptAreaSolid.h"
#include "IFC4//include/IfcFlowController.h"
#include "IFC4//include/IfcFlowControllerType.h"
#include "IFC4//include/IfcFlowFitting.h"
#include "IFC4//include/IfcFlowFittingType.h"
#include "IFC4//include/IfcFlowInstrument.h"
#include "IFC4//include/IfcFlowInstrumentType.h"
#include "IFC4//include/IfcFlowMeter.h"
#include "IFC4//include/IfcFlowMeterType.h"
#include "IFC4//include/IfcFlowMovingDevice.h"
#include "IFC4//include/IfcFlowMovingDeviceType.h"
#include "IFC4//include/IfcFlowSegment.h"
#include "IFC4//include/IfcFlowSegmentType.h"
#include "IFC4//include/IfcFlowStorageDevice.h"
#include "IFC4//include/IfcFlowStorageDeviceType.h"
#include "IFC4//include/IfcFlowTerminal.h"
#include "IFC4//include/IfcFlowTerminalType.h"
#include "IFC4//include/IfcFlowTreatmentDevice.h"
#include "IFC4//include/IfcFlowTreatmentDeviceType.h"
#include "IFC4//include/IfcFooting.h"
#include "IFC4//include/IfcFootingType.h"
#include "IFC4//include/IfcFurnishingElement.h"
#include "IFC4//include/IfcFurnishingElementType.h"
#include "IFC4//include/IfcFurniture.h"
#include "IFC4//include/IfcFurnitureType.h"
#include "IFC4//include/IfcGeographicElement.h"
#include "IFC4//include/IfcGeographicElementType.h"
#include "IFC4//include/IfcGeometricCurveSet.h"
#include "IFC4//include/IfcGeometricRepresentationContext.h"
#include "IFC4//include/IfcGeometricRepresentationItem.h"
#include "IFC4//include/IfcGeometricRepresentationSubContext.h"
#include "IFC4//include/IfcGeometricSet.h"
#include "IFC4//include/IfcGrid.h"
#include "IFC4//include/IfcGridAxis.h"
#include "IFC4//include/IfcGridPlacement.h"
#include "IFC4//include/IfcGroup.h"
#include "IFC4//include/IfcHalfSpaceSolid.h"
#include "IFC4//include/IfcHeatExchanger.h"
#include "IFC4//include/IfcHeatExchangerType.h"
#include "IFC4//include/IfcHumidifier.h"
#include "IFC4//include/IfcHumidifierType.h"
#include "IFC4//include/IfcIShapeProfileDef.h"
#include "IFC4//include/IfcImageTexture.h"
#include "IFC4//include/IfcIndexedColourMap.h"
#include "IFC4//include/IfcIndexedTextureMap.h"
#include "IFC4//include/IfcIndexedTriangleTextureMap.h"
#include "IFC4//include/IfcInterceptor.h"
#include "IFC4//include/IfcInterceptorType.h"
#include "IFC4//include/IfcInventory.h"
#include "IFC4//include/IfcIrregularTimeSeries.h"
#include "IFC4//include/IfcIrregularTimeSeriesValue.h"
#include "IFC4//include/IfcJunctionBox.h"
#include "IFC4//include/IfcJunctionBoxType.h"
#include "IFC4//include/IfcLShapeProfileDef.h"
#include "IFC4//include/IfcLaborResource.h"
#include "IFC4//include/IfcLaborResourceType.h"
#include "IFC4//include/IfcLagTime.h"
#include "IFC4//include/IfcLamp.h"
#include "IFC4//include/IfcLampType.h"
#include "IFC4//include/IfcLibraryInformation.h"
#include "IFC4//include/IfcLibraryReference.h"
#include "IFC4//include/IfcLightDistributionData.h"
#include "IFC4//include/IfcLightFixture.h"
#include "IFC4//include/IfcLightFixtureType.h"
#include "IFC4//include/IfcLightIntensityDistribution.h"
#include "IFC4//include/IfcLightSource.h"
#include "IFC4//include/IfcLightSourceAmbient.h"
#include "IFC4//include/IfcLightSourceDirectional.h"
#include "IFC4//include/IfcLightSourceGoniometric.h"
#include "IFC4//include/IfcLightSourcePositional.h"
#include "IFC4//include/IfcLightSourceSpot.h"
#include "IFC4//include/IfcLine.h"
#include "IFC4//include/IfcLocalPlacement.h"
#include "IFC4//include/IfcLoop.h"
#include "IFC4//include/IfcManifoldSolidBrep.h"
#include "IFC4//include/IfcMapConversion.h"
#include "IFC4//include/IfcMappedItem.h"
#include "IFC4//include/IfcMaterial.h"
#include "IFC4//include/IfcMaterialClassificationRelationship.h"
#include "IFC4//include/IfcMaterialConstituent.h"
#include "IFC4//include/IfcMaterialConstituentSet.h"
#include "IFC4//include/IfcMaterialDefinition.h"
#include "IFC4//include/IfcMaterialDefinitionRepresentation.h"
#include "IFC4//include/IfcMaterialLayer.h"
#include "IFC4//include/IfcMaterialLayerSet.h"
#include "IFC4//include/IfcMaterialLayerSetUsage.h"
#include "IFC4//include/IfcMaterialLayerWithOffsets.h"
#include "IFC4//include/IfcMaterialList.h"
#include "IFC4//include/IfcMaterialProfile.h"
#include "IFC4//include/IfcMaterialProfileSet.h"
#include "IFC4//include/IfcMaterialProfileSetUsage.h"
#include "IFC4//include/IfcMaterialProfileSetUsageTapering.h"
#include "IFC4//include/IfcMaterialProfileWithOffsets.h"
#include "IFC4//include/IfcMaterialProperties.h"
#include "IFC4//include/IfcMaterialRelationship.h"
#include "IFC4//include/IfcMaterialUsageDefinition.h"
#include "IFC4//include/IfcMeasureWithUnit.h"
#include "IFC4//include/IfcMechanicalFastener.h"
#include "IFC4//include/IfcMechanicalFastenerType.h"
#include "IFC4//include/IfcMedicalDevice.h"
#include "IFC4//include/IfcMedicalDeviceType.h"
#include "IFC4//include/IfcMember.h"
#include "IFC4//include/IfcMemberStandardCase.h"
#include "IFC4//include/IfcMemberType.h"
#include "IFC4//include/IfcMetric.h"
#include "IFC4//include/IfcMirroredProfileDef.h"
#include "IFC4//include/IfcMonetaryUnit.h"
#include "IFC4//include/IfcMotorConnection.h"
#include "IFC4//include/IfcMotorConnectionType.h"
#include "IFC4//include/IfcNamedUnit.h"
#include "IFC4//include/IfcObject.h"
#include "IFC4//include/IfcObjectDefinition.h"
#include "IFC4//include/IfcObjectPlacement.h"
#include "IFC4//include/IfcObjective.h"
#include "IFC4//include/IfcOccupant.h"
#include "IFC4//include/IfcOffsetCurve2D.h"
#include "IFC4//include/IfcOffsetCurve3D.h"
#include "IFC4//include/IfcOpenShell.h"
#include "IFC4//include/IfcOpeningElement.h"
#include "IFC4//include/IfcOpeningStandardCase.h"
#include "IFC4//include/IfcOrganization.h"
#include "IFC4//include/IfcOrganizationRelationship.h"
#include "IFC4//include/IfcOrientedEdge.h"
#include "IFC4//include/IfcOuterBoundaryCurve.h"
#include "IFC4//include/IfcOutlet.h"
#include "IFC4//include/IfcOutletType.h"
#include "IFC4//include/IfcOwnerHistory.h"
#include "IFC4//include/IfcParameterizedProfileDef.h"
#include "IFC4//include/IfcPath.h"
#include "IFC4//include/IfcPcurve.h"
#include "IFC4//include/IfcPerformanceHistory.h"
#include "IFC4//include/IfcPermeableCoveringProperties.h"
#include "IFC4//include/IfcPermit.h"
#include "IFC4//include/IfcPerson.h"
#include "IFC4//include/IfcPersonAndOrganization.h"
#include "IFC4//include/IfcPhysicalComplexQuantity.h"
#include "IFC4//include/IfcPhysicalQuantity.h"
#include "IFC4//include/IfcPhysicalSimpleQuantity.h"
#include "IFC4//include/IfcPile.h"
#include "IFC4//include/IfcPileType.h"
#include "IFC4//include/IfcPipeFitting.h"
#include "IFC4//include/IfcPipeFittingType.h"
#include "IFC4//include/IfcPipeSegment.h"
#include "IFC4//include/IfcPipeSegmentType.h"
#include "IFC4//include/IfcPixelTexture.h"
#include "IFC4//include/IfcPlacement.h"
#include "IFC4//include/IfcPlanarBox.h"
#include "IFC4//include/IfcPlanarExtent.h"
#include "IFC4//include/IfcPlane.h"
#include "IFC4//include/IfcPlate.h"
#include "IFC4//include/IfcPlateStandardCase.h"
#include "IFC4//include/IfcPlateType.h"
#include "IFC4//include/IfcPoint.h"
#include "IFC4//include/IfcPointOnCurve.h"
#include "IFC4//include/IfcPointOnSurface.h"
#include "IFC4//include/IfcPolyLoop.h"
#include "IFC4//include/IfcPolygonalBoundedHalfSpace.h"
#include "IFC4//include/IfcPolyline.h"
#include "IFC4//include/IfcPort.h"
#include "IFC4//include/IfcPostalAddress.h"
#include "IFC4//include/IfcPreDefinedColour.h"
#include "IFC4//include/IfcPreDefinedCurveFont.h"
#include "IFC4//include/IfcPreDefinedItem.h"
#include "IFC4//include/IfcPreDefinedProperties.h"
#include "IFC4//include/IfcPreDefinedPropertySet.h"
#include "IFC4//include/IfcPreDefinedTextFont.h"
#include "IFC4//include/IfcPresentationItem.h"
#include "IFC4//include/IfcPresentationLayerAssignment.h"
#include "IFC4//include/IfcPresentationLayerWithStyle.h"
#include "IFC4//include/IfcPresentationStyle.h"
#include "IFC4//include/IfcPresentationStyleAssignment.h"
#include "IFC4//include/IfcProcedure.h"
#include "IFC4//include/IfcProcedureType.h"
#include "IFC4//include/IfcProcess.h"
#include "IFC4//include/IfcProduct.h"
#include "IFC4//include/IfcProductDefinitionShape.h"
#include "IFC4//include/IfcProductRepresentation.h"
#include "IFC4//include/IfcProfileDef.h"
#include "IFC4//include/IfcProfileProperties.h"
#include "IFC4//include/IfcProject.h"
#include "IFC4//include/IfcProjectLibrary.h"
#include "IFC4//include/IfcProjectOrder.h"
#include "IFC4//include/IfcProjectedCRS.h"
#include "IFC4//include/IfcProjectionElement.h"
#include "IFC4//include/IfcProperty.h"
#include "IFC4//include/IfcPropertyAbstraction.h"
#include "IFC4//include/IfcPropertyBoundedValue.h"
#include "IFC4//include/IfcPropertyDefinition.h"
#include "IFC4//include/IfcPropertyDependencyRelationship.h"
#include "IFC4//include/IfcPropertyEnumeratedValue.h"
#include "IFC4//include/IfcPropertyEnumeration.h"
#include "IFC4//include/IfcPropertyListValue.h"
#include "IFC4//include/IfcPropertyReferenceValue.h"
#include "IFC4//include/IfcPropertySet.h"
#include "IFC4//include/IfcPropertySetDefinition.h"
#include "IFC4//include/IfcPropertySetTemplate.h"
#include "IFC4//include/IfcPropertySingleValue.h"
#include "IFC4//include/IfcPropertyTableValue.h"
#include "IFC4//include/IfcPropertyTemplate.h"
#include "IFC4//include/IfcPropertyTemplateDefinition.h"
#include "IFC4//include/IfcProtectiveDevice.h"
#include "IFC4//include/IfcProtectiveDeviceTrippingUnit.h"
#include "IFC4//include/IfcProtectiveDeviceTrippingUnitType.h"
#include "IFC4//include/IfcProtectiveDeviceType.h"
#include "IFC4//include/IfcProxy.h"
#include "IFC4//include/IfcPump.h"
#include "IFC4//include/IfcPumpType.h"
#include "IFC4//include/IfcQuantityArea.h"
#include "IFC4//include/IfcQuantityCount.h"
#include "IFC4//include/IfcQuantityLength.h"
#include "IFC4//include/IfcQuantitySet.h"
#include "IFC4//include/IfcQuantityTime.h"
#include "IFC4//include/IfcQuantityVolume.h"
#include "IFC4//include/IfcQuantityWeight.h"
#include "IFC4//include/IfcRailing.h"
#include "IFC4//include/IfcRailingType.h"
#include "IFC4//include/IfcRamp.h"
#include "IFC4//include/IfcRampFlight.h"
#include "IFC4//include/IfcRampFlightType.h"
#include "IFC4//include/IfcRampType.h"
#include "IFC4//include/IfcRationalBSplineCurveWithKnots.h"
#include "IFC4//include/IfcRationalBSplineSurfaceWithKnots.h"
#include "IFC4//include/IfcRectangleHollowProfileDef.h"
#include "IFC4//include/IfcRectangleProfileDef.h"
#include "IFC4//include/IfcRectangularPyramid.h"
#include "IFC4//include/IfcRectangularTrimmedSurface.h"
#include "IFC4//include/IfcRecurrencePattern.h"
#include "IFC4//include/IfcReference.h"
#include "IFC4//include/IfcRegularTimeSeries.h"
#include "IFC4//include/IfcReinforcementBarProperties.h"
#include "IFC4//include/IfcReinforcementDefinitionProperties.h"
#include "IFC4//include/IfcReinforcingBar.h"
#include "IFC4//include/IfcReinforcingBarType.h"
#include "IFC4//include/IfcReinforcingElement.h"
#include "IFC4//include/IfcReinforcingElementType.h"
#include "IFC4//include/IfcReinforcingMesh.h"
#include "IFC4//include/IfcReinforcingMeshType.h"
#include "IFC4//include/IfcRelAggregates.h"
#include "IFC4//include/IfcRelAssigns.h"
#include "IFC4//include/IfcRelAssignsToActor.h"
#include "IFC4//include/IfcRelAssignsToControl.h"
#include "IFC4//include/IfcRelAssignsToGroup.h"
#include "IFC4//include/IfcRelAssignsToGroupByFactor.h"
#include "IFC4//include/IfcRelAssignsToProcess.h"
#include "IFC4//include/IfcRelAssignsToProduct.h"
#include "IFC4//include/IfcRelAssignsToResource.h"
#include "IFC4//include/IfcRelAssociates.h"
#include "IFC4//include/IfcRelAssociatesApproval.h"
#include "IFC4//include/IfcRelAssociatesClassification.h"
#include "IFC4//include/IfcRelAssociatesConstraint.h"
#include "IFC4//include/IfcRelAssociatesDocument.h"
#include "IFC4//include/IfcRelAssociatesLibrary.h"
#include "IFC4//include/IfcRelAssociatesMaterial.h"
#include "IFC4//include/IfcRelConnects.h"
#include "IFC4//include/IfcRelConnectsElements.h"
#include "IFC4//include/IfcRelConnectsPathElements.h"
#include "IFC4//include/IfcRelConnectsPortToElement.h"
#include "IFC4//include/IfcRelConnectsPorts.h"
#include "IFC4//include/IfcRelConnectsStructuralActivity.h"
#include "IFC4//include/IfcRelConnectsStructuralMember.h"
#include "IFC4//include/IfcRelConnectsWithEccentricity.h"
#include "IFC4//include/IfcRelConnectsWithRealizingElements.h"
#include "IFC4//include/IfcRelContainedInSpatialStructure.h"
#include "IFC4//include/IfcRelCoversBldgElements.h"
#include "IFC4//include/IfcRelCoversSpaces.h"
#include "IFC4//include/IfcRelDeclares.h"
#include "IFC4//include/IfcRelDecomposes.h"
#include "IFC4//include/IfcRelDefines.h"
#include "IFC4//include/IfcRelDefinesByObject.h"
#include "IFC4//include/IfcRelDefinesByProperties.h"
#include "IFC4//include/IfcRelDefinesByTemplate.h"
#include "IFC4//include/IfcRelDefinesByType.h"
#include "IFC4//include/IfcRelFillsElement.h"
#include "IFC4//include/IfcRelFlowControlElements.h"
#include "IFC4//include/IfcRelInterferesElements.h"
#include "IFC4//include/IfcRelNests.h"
#include "IFC4//include/IfcRelProjectsElement.h"
#include "IFC4//include/IfcRelReferencedInSpatialStructure.h"
#include "IFC4//include/IfcRelSequence.h"
#include "IFC4//include/IfcRelServicesBuildings.h"
#include "IFC4//include/IfcRelSpaceBoundary.h"
#include "IFC4//include/IfcRelSpaceBoundary1stLevel.h"
#include "IFC4//include/IfcRelSpaceBoundary2ndLevel.h"
#include "IFC4//include/IfcRelVoidsElement.h"
#include "IFC4//include/IfcRelationship.h"
#include "IFC4//include/IfcReparametrisedCompositeCurveSegment.h"
#include "IFC4//include/IfcRepresentation.h"
#include "IFC4//include/IfcRepresentationContext.h"
#include "IFC4//include/IfcRepresentationItem.h"
#include "IFC4//include/IfcRepresentationMap.h"
#include "IFC4//include/IfcResource.h"
#include "IFC4//include/IfcResourceApprovalRelationship.h"
#include "IFC4//include/IfcResourceConstraintRelationship.h"
#include "IFC4//include/IfcResourceLevelRelationship.h"
#include "IFC4//include/IfcResourceTime.h"
#include "IFC4//include/IfcRevolvedAreaSolid.h"
#include "IFC4//include/IfcRevolvedAreaSolidTapered.h"
#include "IFC4//include/IfcRightCircularCone.h"
#include "IFC4//include/IfcRightCircularCylinder.h"
#include "IFC4//include/IfcRoof.h"
#include "IFC4//include/IfcRoofType.h"
#include "IFC4//include/IfcRoot.h"
#include "IFC4//include/IfcRoundedRectangleProfileDef.h"
#include "IFC4//include/IfcSIUnit.h"
#include "IFC4//include/IfcSanitaryTerminal.h"
#include "IFC4//include/IfcSanitaryTerminalType.h"
#include "IFC4//include/IfcSchedulingTime.h"
#include "IFC4//include/IfcSectionProperties.h"
#include "IFC4//include/IfcSectionReinforcementProperties.h"
#include "IFC4//include/IfcSectionedSpine.h"
#include "IFC4//include/IfcSensor.h"
#include "IFC4//include/IfcSensorType.h"
#include "IFC4//include/IfcShadingDevice.h"
#include "IFC4//include/IfcShadingDeviceType.h"
#include "IFC4//include/IfcShapeAspect.h"
#include "IFC4//include/IfcShapeModel.h"
#include "IFC4//include/IfcShapeRepresentation.h"
#include "IFC4//include/IfcShellBasedSurfaceModel.h"
#include "IFC4//include/IfcSimpleProperty.h"
#include "IFC4//include/IfcSimplePropertyTemplate.h"
#include "IFC4//include/IfcSite.h"
#include "IFC4//include/IfcSlab.h"
#include "IFC4//include/IfcSlabElementedCase.h"
#include "IFC4//include/IfcSlabStandardCase.h"
#include "IFC4//include/IfcSlabType.h"
#include "IFC4//include/IfcSlippageConnectionCondition.h"
#include "IFC4//include/IfcSolarDevice.h"
#include "IFC4//include/IfcSolarDeviceType.h"
#include "IFC4//include/IfcSolidModel.h"
#include "IFC4//include/IfcSpace.h"
#include "IFC4//include/IfcSpaceHeater.h"
#include "IFC4//include/IfcSpaceHeaterType.h"
#include "IFC4//include/IfcSpaceType.h"
#include "IFC4//include/IfcSpatialElement.h"
#include "IFC4//include/IfcSpatialElementType.h"
#include "IFC4//include/IfcSpatialStructureElement.h"
#include "IFC4//include/IfcSpatialStructureElementType.h"
#include "IFC4//include/IfcSpatialZone.h"
#include "IFC4//include/IfcSpatialZoneType.h"
#include "IFC4//include/IfcSphere.h"
#include "IFC4//include/IfcStackTerminal.h"
#include "IFC4//include/IfcStackTerminalType.h"
#include "IFC4//include/IfcStair.h"
#include "IFC4//include/IfcStairFlight.h"
#include "IFC4//include/IfcStairFlightType.h"
#include "IFC4//include/IfcStairType.h"
#include "IFC4//include/IfcStructuralAction.h"
#include "IFC4//include/IfcStructuralActivity.h"
#include "IFC4//include/IfcStructuralAnalysisModel.h"
#include "IFC4//include/IfcStructuralConnection.h"
#include "IFC4//include/IfcStructuralConnectionCondition.h"
#include "IFC4//include/IfcStructuralCurveAction.h"
#include "IFC4//include/IfcStructuralCurveConnection.h"
#include "IFC4//include/IfcStructuralCurveMember.h"
#include "IFC4//include/IfcStructuralCurveMemberVarying.h"
#include "IFC4//include/IfcStructuralCurveReaction.h"
#include "IFC4//include/IfcStructuralItem.h"
#include "IFC4//include/IfcStructuralLinearAction.h"
#include "IFC4//include/IfcStructuralLoad.h"
#include "IFC4//include/IfcStructuralLoadCase.h"
#include "IFC4//include/IfcStructuralLoadConfiguration.h"
#include "IFC4//include/IfcStructuralLoadGroup.h"
#include "IFC4//include/IfcStructuralLoadLinearForce.h"
#include "IFC4//include/IfcStructuralLoadOrResult.h"
#include "IFC4//include/IfcStructuralLoadPlanarForce.h"
#include "IFC4//include/IfcStructuralLoadSingleDisplacement.h"
#include "IFC4//include/IfcStructuralLoadSingleDisplacementDistortion.h"
#include "IFC4//include/IfcStructuralLoadSingleForce.h"
#include "IFC4//include/IfcStructuralLoadSingleForceWarping.h"
#include "IFC4//include/IfcStructuralLoadStatic.h"
#include "IFC4//include/IfcStructuralLoadTemperature.h"
#include "IFC4//include/IfcStructuralMember.h"
#include "IFC4//include/IfcStructuralPlanarAction.h"
#include "IFC4//include/IfcStructuralPointAction.h"
#include "IFC4//include/IfcStructuralPointConnection.h"
#include "IFC4//include/IfcStructuralPointReaction.h"
#include "IFC4//include/IfcStructuralReaction.h"
#include "IFC4//include/IfcStructuralResultGroup.h"
#include "IFC4//include/IfcStructuralSurfaceAction.h"
#include "IFC4//include/IfcStructuralSurfaceConnection.h"
#include "IFC4//include/IfcStructuralSurfaceMember.h"
#include "IFC4//include/IfcStructuralSurfaceMemberVarying.h"
#include "IFC4//include/IfcStructuralSurfaceReaction.h"
#include "IFC4//include/IfcStyleModel.h"
#include "IFC4//include/IfcStyledItem.h"
#include "IFC4//include/IfcStyledRepresentation.h"
#include "IFC4//include/IfcSubContractResource.h"
#include "IFC4//include/IfcSubContractResourceType.h"
#include "IFC4//include/IfcSubedge.h"
#include "IFC4//include/IfcSurface.h"
#include "IFC4//include/IfcSurfaceCurveSweptAreaSolid.h"
#include "IFC4//include/IfcSurfaceFeature.h"
#include "IFC4//include/IfcSurfaceOfLinearExtrusion.h"
#include "IFC4//include/IfcSurfaceOfRevolution.h"
#include "IFC4//include/IfcSurfaceReinforcementArea.h"
#include "IFC4//include/IfcSurfaceStyle.h"
#include "IFC4//include/IfcSurfaceStyleLighting.h"
#include "IFC4//include/IfcSurfaceStyleRefraction.h"
#include "IFC4//include/IfcSurfaceStyleRendering.h"
#include "IFC4//include/IfcSurfaceStyleShading.h"
#include "IFC4//include/IfcSurfaceStyleWithTextures.h"
#include "IFC4//include/IfcSurfaceTexture.h"
#include "IFC4//include/IfcSweptAreaSolid.h"
#include "IFC4//include/IfcSweptDiskSolid.h"
#include "IFC4//include/IfcSweptDiskSolidPolygonal.h"
#include "IFC4//include/IfcSweptSurface.h"
#include "IFC4//include/IfcSwitchingDevice.h"
#include "IFC4//include/IfcSwitchingDeviceType.h"
#include "IFC4//include/IfcSystem.h"
#include "IFC4//include/IfcSystemFurnitureElement.h"
#include "IFC4//include/IfcSystemFurnitureElementType.h"
#include "IFC4//include/IfcTShapeProfileDef.h"
#include "IFC4//include/IfcTable.h"
#include "IFC4//include/IfcTableColumn.h"
#include "IFC4//include/IfcTableRow.h"
#include "IFC4//include/IfcTank.h"
#include "IFC4//include/IfcTankType.h"
#include "IFC4//include/IfcTask.h"
#include "IFC4//include/IfcTaskTime.h"
#include "IFC4//include/IfcTaskTimeRecurring.h"
#include "IFC4//include/IfcTaskType.h"
#include "IFC4//include/IfcTelecomAddress.h"
#include "IFC4//include/IfcTendon.h"
#include "IFC4//include/IfcTendonAnchor.h"
#include "IFC4//include/IfcTendonAnchorType.h"
#include "IFC4//include/IfcTendonType.h"
#include "IFC4//include/IfcTessellatedFaceSet.h"
#include "IFC4//include/IfcTessellatedItem.h"
#include "IFC4//include/IfcTextLiteral.h"
#include "IFC4//include/IfcTextLiteralWithExtent.h"
#include "IFC4//include/IfcTextStyle.h"
#include "IFC4//include/IfcTextStyleFontModel.h"
#include "IFC4//include/IfcTextStyleForDefinedFont.h"
#include "IFC4//include/IfcTextStyleTextModel.h"
#include "IFC4//include/IfcTextureCoordinate.h"
#include "IFC4//include/IfcTextureCoordinateGenerator.h"
#include "IFC4//include/IfcTextureMap.h"
#include "IFC4//include/IfcTextureVertex.h"
#include "IFC4//include/IfcTextureVertexList.h"
#include "IFC4//include/IfcTimePeriod.h"
#include "IFC4//include/IfcTimeSeries.h"
#include "IFC4//include/IfcTimeSeriesValue.h"
#include "IFC4//include/IfcTopologicalRepresentationItem.h"
#include "IFC4//include/IfcTopologyRepresentation.h"
#include "IFC4//include/IfcTransformer.h"
#include "IFC4//include/IfcTransformerType.h"
#include "IFC4//include/IfcTransportElement.h"
#include "IFC4//include/IfcTransportElementType.h"
#include "IFC4//include/IfcTrapeziumProfileDef.h"
#include "IFC4//include/IfcTriangulatedFaceSet.h"
#include "IFC4//include/IfcTrimmedCurve.h"
#include "IFC4//include/IfcTubeBundle.h"
#include "IFC4//include/IfcTubeBundleType.h"
#include "IFC4//include/IfcTypeObject.h"
#include "IFC4//include/IfcTypeProcess.h"
#include "IFC4//include/IfcTypeProduct.h"
#include "IFC4//include/IfcTypeResource.h"
#include "IFC4//include/IfcUShapeProfileDef.h"
#include "IFC4//include/IfcUnitAssignment.h"
#include "IFC4//include/IfcUnitaryControlElement.h"
#include "IFC4//include/IfcUnitaryControlElementType.h"
#include "IFC4//include/IfcUnitaryEquipment.h"
#include "IFC4//include/IfcUnitaryEquipmentType.h"
#include "IFC4//include/IfcValve.h"
#include "IFC4//include/IfcValveType.h"
#include "IFC4//include/IfcVector.h"
#include "IFC4//include/IfcVertex.h"
#include "IFC4//include/IfcVertexLoop.h"
#include "IFC4//include/IfcVertexPoint.h"
#include "IFC4//include/IfcVibrationIsolator.h"
#include "IFC4//include/IfcVibrationIsolatorType.h"
#include "IFC4//include/IfcVirtualElement.h"
#include "IFC4//include/IfcVirtualGridIntersection.h"
#include "IFC4//include/IfcVoidingFeature.h"
#include "IFC4//include/IfcWall.h"
#include "IFC4//include/IfcWallElementedCase.h"
#include "IFC4//include/IfcWallStandardCase.h"
#include "IFC4//include/IfcWallType.h"
#include "IFC4//include/IfcWasteTerminal.h"
#include "IFC4//include/IfcWasteTerminalType.h"
#include "IFC4//include/IfcWindow.h"
#include "IFC4//include/IfcWindowLiningProperties.h"
#include "IFC4//include/IfcWindowPanelProperties.h"
#include "IFC4//include/IfcWindowStandardCase.h"
#include "IFC4//include/IfcWindowStyle.h"
#include "IFC4//include/IfcWindowType.h"
#include "IFC4//include/IfcWorkCalendar.h"
#include "IFC4//include/IfcWorkControl.h"
#include "IFC4//include/IfcWorkPlan.h"
#include "IFC4//include/IfcWorkSchedule.h"
#include "IFC4//include/IfcWorkTime.h"
#include "IFC4//include/IfcZShapeProfileDef.h"
#include "IFC4//include/IfcZone.h"