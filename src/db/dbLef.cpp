/**
 * @file   dbLef.cpp
 * @brief  Technology configuration from Lef file
 * @author Hao Chen
 * @date   09/12/2019
 *
 **/

#include "dbLef.hpp"

PROJECT_NAMESPACE_START


void LefDB::setVersionStr(const String_t& v) {
  _versionStr = v;
}

void LefDB::setVersion(const Real_t v) {
  _version = v;
}

void LefDB::setDividerChar(const String_t& v) {
  _dividerChar = v;
}

void LefDB::setManufacturingGrid(const Real_t v) {
  _manufacturingGrid = v;
}

void LefDB::setClearanceMeasure(const String_t& v) {
  _clearanceMeasure = v;
}

void LefDB::setBusbitChars(const String_t& v) {
  _busbitChars = v;
}

void LefDB::addImplantLayer(const LefImplantLayer& l) {
  _mStr2ImplantLayerIdx[l.name()] = _vImplantLayers.size();
  _vAllLayers.emplace_back(LayerType_t::IMPLANT, _vImplantLayers.size());
  _vImplantLayers.emplace_back(l);
}

void LefDB::addMastersliceLayer(const LefMastersliceLayer& l) {
  _mStr2MastersliceLayerIdx[l.name()] = _vMastersliceLayers.size();
  _vAllLayers.emplace_back(LayerType_t::MASTERSLICE, _vMastersliceLayers.size());
  _vMastersliceLayers.emplace_back(l);
} 

void LefDB::addCutLayer(const LefCutLayer& l) {
  _mStr2CutLayerIdx[l.name()] = _vCutLayers.size();
  _vAllLayers.emplace_back(LayerType_t::CUT, _vCutLayers.size());
  _vCutLayers.emplace_back(l);
}

void LefDB::addRoutingLayer(const LefRoutingLayer& l) {
  _mStr2RoutingLayerIdx[l.name()] = _vRoutingLayers.size();
  _vAllLayers.emplace_back(LayerType_t::ROUTING, _vRoutingLayers.size());
  _vRoutingLayers.emplace_back(l);
}

void LefDB::addOverlapLayer(const LefOverlapLayer& l) {
  _mStr2OverlapLayerIdx[l.name()] = _vOverlapLayers.size();
  _vAllLayers.emplace_back(LayerType_t::OVERLAP, _vOverlapLayers.size());
  _vOverlapLayers.emplace_back(l);
}

void LefDB::logInfo() const {
  //for (Index_t i = 0; i < _vCutLayers.size(); ++i) {
    //_vCutLayers[i].logInfo();
  //}
  //for (Index_t i = 0; i < _vRoutingLayers.size(); ++i) {
    //_vRoutingLayers[i].logInfo();
  //}
}

PROJECT_NAMESPACE_END
