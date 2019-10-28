/**
 * @file   dbBlk.hpp
 * @brief  Circuit Element - Blkage
 * @author Hao Chen
 * @date   09/20/2019
 *
 **/

#ifndef _DB_BLOCK_HPP_
#define _DB_BLOCK_HPP_

#include "src/global/global.hpp"
#include "src/geo/box.hpp"

PROJECT_NAMESPACE_START

class Blk {
  friend class Parser;
 public:
  Blk()
    : _layerIdx(MAX_UINT) {}
  Blk(const UInt_t i, const Box<Int_t>& b)
    : _layerIdx(i), _box(b) {}
  ~Blk() {}
  
  ////////////////////////////////////////
  //   Getter                           //
  ////////////////////////////////////////
  UInt_t                          layerIdx()                const { return _layerIdx; }
  const Box<Int_t>&               box()                     const { return _box; }
  Int_t                           xl()                      const { return _box.xl(); } 
  Int_t                           yl()                      const { return _box.yl(); } 
  Int_t                           xh()                      const { return _box.xh(); } 
  Int_t                           yh()                      const { return _box.yh(); }
  const Point<Int_t>&             bl()                      const { return _box.bl(); }
  const Point<Int_t>&             tr()                      const { return _box.tr(); }
  const Point<Int_t>&             min_corner()              const { return _box.min_corner(); }
  const Point<Int_t>&             max_corner()              const { return _box.max_corner(); }

 private:
  UInt_t                _layerIdx;
  Box<Int_t>            _box;
  
  ////////////////////////////////////////
  //   Setter                           //
  ////////////////////////////////////////
  void setLayerIdx(const UInt_t i) { _layerIdx = i; }
  void setBox(const Box<Int_t>& b) { _box = b; }
};

PROJECT_NAMESPACE_END

#endif /// _DB_BLOCK_HPP_