/**
 * @file   writer.hpp
 * @brief  Output file writer
 * @author Hao Chen
 * @date   10/18/2019
 *
 **/

#ifndef _WRITER_HPP_
#define _WRITER_HPP_

#include "wrGds.hpp"
#include "wrGrGuide.hpp"
#include "wrLayout.hpp"

PROJECT_NAMESPACE_START

class Writer {
 public:
  Writer(const CirDB& c)
    : _cir(c),
      _grGuidew(c),
      _layoutw(c)
    {}
  ~Writer() {}

  // result
  void writeLayoutGds(const String_t& placementFilename, const String_t& outputFilename);
  
  // guide
  void writeGrGuide(const String_t& filename) const;
  void writeGrGuideGds(const String_t& netName, const String_t& filename) const;
    
 private:
  const CirDB&  _cir;
  GrGuideWriter _grGuidew;
  LayoutWriter  _layoutw;

};

PROJECT_NAMESPACE_END

#endif /// _WRITER_HPP_
