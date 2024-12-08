#ifndef _TYPES_H_
#define _TYPES_H_
// The MIT License (MIT)

// Copyright (c) 2024 Liao-QiHua

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

#include <string>
#include <type_traits>

namespace gvw {

// The attribute class starts with 'G' and is followed by
// the type name defined in Graphviz.
// Please refer to https://graphviz.org/doc/info/attrs.html

// xdot is a custom Graphviz language invented by Emden Gansner,
// describing ellipses, polygons, polylines, beziers, text, images,
// colors, gradients, fonts, and styles.
// Example: c 7 -#ff0000 p 4 4 4 36 4 36 36 4 36 renders a red square.
using GXdot = std::string;

class GArrowType {
 public:
  enum ArrowType {
    kNormal,
    kInv,
    kDot,
    kInvdot,
    kOdot,
    kInvodot,
    kNone,
    kTee,
    kEmpty,
    kInvempty,
    kDiamond,
    kOdiamond,
    kEdiamond,
    kCrow,
    kBox,
    kObox,
    kOpen,
    kHalfopen,
    kVee
  };
  GArrowType(ArrowType arrow_type) : arrow_type_(arrow_type) {}

 private:
  ArrowType arrow_type_;
};

class GRect {
 public:
  GRect(float llx, float lly, float urx, float ury)
      : llx_(llx), lly_(lly), urx_(urx), ury_(ury) {}
  ~GRect() = default;
  void set_llx(float llx) { llx_ = llx; }
  void set_lly(float lly) { lly_ = lly; }
  void set_urx(float urx) { urx_ = urx; }
  void set_ury(float ury) { ury_ = ury; }
  std::string ToString() {
    std::string("\"") + std::to_string(llx_) + std::string(",") +
        std::to_string(lly_) + std::string(",") + std::to_string(urx_) +
        std::string(",") + std::to_string(ury_) + std::string("\"");
  }

 private:
  // The rectangle llx,lly,urx,ury gives the coordinates, in points,
  // of the lower-left corner (llx,lly) and the upper-right corner (urx,ury).
  float llx_;
  float lly_;
  float urx_;
  float ury_;
};

using GColor = std::string;

using GColorList = std::string;

class GClusterMode {
 public:
  enum ClusterMode { kLocal, kGlobal, kNone };
  GClusterMode(ClusterMode cluster_mode) : cluster_mode_(cluster_mode) {}

 private:
  ClusterMode cluster_mode_;
};

class GDirType {
 public:
  enum DirType { kForward, kBack, kBoth, kNone };
  GDirType(DirType dir_type) : dir_type_(dir_type) {}

 private:
  DirType dir_type_;
};

using GLayerRange = std::string;

using GLayerList = std::string;

using GPoint = std::string;

class GOutputMode {
 public:
  enum OutputMode { kBreakthfirst, kNodesfirst, kEdgesfirst };
  GOutputMode(OutputMode output_mode) : output_mode_(output_mode) {}

 private:
  OutputMode output_mode_;
};

class GPageDir {
 public:
  enum PageDir { kBl, kBr, kTl, kTr, kRb, kRt, kLb, kLt };
  GPageDir(PageDir page_dir) : page_dir_(page_dir) {}

 private:
  PageDir page_dir_;
};

using GSplineType = std::string;

class GQuadType {
 public:
  enum Quadtype { kNormal, kFast, kNone };
  GQuadType(Quadtype quad_type) : quad_type_(quad_type) {}

 private:
  Quadtype quad_type_;
};

class GRankType {
 public:
  enum RankType { kSame, kMin, kSource, kMax, kSink };
  GRankType(RankType rank_type) : rank_type_(rank_type) {}

 private:
  RankType rank_type_;
};

class GRankDir {
 public:
  enum RankDir { kTb, kLr, kBt, kRl };
  GRankDir(RankDir rank_dir) : rank_dir_(rank_dir) {}

 private:
  RankDir rank_dir_;
};

using GAddDouble = std::string;

using GAddPoint = std::string;

using GShape = std::string;

using GStyle = std::string;

using GEscString = std::string;

using GViewPort = std::string;

using GLblString = std::string;

using GDouble = double;

using GInt = int;

using GBool = bool;

using GString = std::string;

using GPortPos = std::string;

using GPointList = std::string;

template<typename T>
struct used_by_cluster : std::false_type {};

template<typename T>
struct used_by_edge : std::false_type {};

template<typename T>
struct used_by_graph : std::false_type {};

template<typename T>
struct used_by_node : std::false_type {};

template<typename T>
struct used_by_subgraph : std::false_type {};

class GAttribute {
public:
  GAttribute(std::string key, std::string value) : key_(key), value_(value) {}
  ~GAttribute() = default;
  std::string to_string() {
    return key_ + "=\"" + value_ + "\"";
  }
protected:
  std::string key_;
  std::string value_;
};

class GAttributeList {
public:
  GAttributeList() {}
  ~GAttributeList() = default;
  void AddAttr(std::string key, std::string value) {
    attr_list_.push_back(GAttribute(key, value));
  }
  std::string to_string() {
    std::string attr_list_str('[');
    if (!attr_list_.empty()) {
      attr_list_str += attr_list_.front().to_string();
    }
    for (auto i = 1u; i < attr_list_.size(); i++) {
      attr_list_str += ', ';
      attr_list_str += attr_list_[i].to_string();
    }
    attr_list_str += "]\0";
    return attr_list_str;
  }
private:
  std::vector<GAttribute> attr_list_;
};

}  // namespace gvw

#endif  // _TYPES_H_