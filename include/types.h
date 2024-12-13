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
#include <vector>

namespace graphvizwrapper {

// The attribute class starts with 'G' and is followed by
// the type name defined in Graphviz.
// Please refer to https://graphviz.org/doc/info/attrs.html

// xdot is a custom Graphviz language invented by Emden Gansner,
// describing ellipses, polygons, polylines, beziers, text, images,
// colors, gradients, fonts, and styles.
// Example: c 7 -#ff0000 p 4 4 4 36 4 36 36 4 36 renders a red square.

using GXdot = std::string;

class ArrowType {
 public:
  enum Type {
    kNormal = 0,
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
    kVee,
    kNum
  };
  ArrowType(Type arrow_type) : arrow_type_(arrow_type) {}
  std::string to_string() { return type_str_[arrow_type_]; }

 private:
  Type arrow_type_;
  const char *type_str_[kNum] = {
      "normal"
      "inv",
      "dot",
      "invdot",
      "odot",
      "invodot",
      "none",
      "tee",
      "empty",
      "invempty",
      "diamond",
      "odiamond",
      "ediamond",
      "crow",
      "box",
      "obox",
      "open",
      "halfopen",
      "vee"};
};

class Rect {
 public:
  Rect(float llx, float lly, float urx, float ury)
      : llx_(llx), lly_(lly), urx_(urx), ury_(ury) {}
  ~Rect() = default;
  void set_llx(float llx) { llx_ = llx; }
  void set_lly(float lly) { lly_ = lly; }
  void set_urx(float urx) { urx_ = urx; }
  void set_ury(float ury) { ury_ = ury; }
  std::string to_string() {
    return std::string("\"") + std::to_string(llx_) + std::string(",") +
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

using Color = std::string;

using ColorList = std::vector<std::string>;

class ClusterMode {
 public:
  enum Mode { kLocal, kGlobal, kNone };
  ClusterMode(ClusterMode::Mode cluster_mode) : cluster_mode_(cluster_mode) {}

 private:
  Mode cluster_mode_;
};

class DirType {
 public:
  enum Type { kForward, kBack, kBoth, kNone };
  DirType(DirType::Type dir_type) : dir_type_(dir_type) {}

 private:
  Type dir_type_;
};

using LayerRange = std::string;

using LayerList = std::string;

using Point = std::string;

class OutputMode {
 public:
  enum Mode { kBreakthfirst, kNodesfirst, kEdgesfirst };
  OutputMode(OutputMode::Mode output_mode) : output_mode_(output_mode) {}

 private:
  Mode output_mode_;
};

class PageDir {
 public:
  enum Dir { kBl, kBr, kTl, kTr, kRb, kRt, kLb, kLt };
  PageDir(PageDir::Dir page_dir) : page_dir_(page_dir) {}

 private:
  Dir page_dir_;
};

using SplineType = std::string;

class QuadType {
 public:
  enum Type { kNormal, kFast, kNone };
  QuadType(QuadType::Type quad_type) : quad_type_(quad_type) {}

 private:
  Type quad_type_;
};

class RankType {
 public:
  enum Type { kSame, kMin, kSource, kMax, kSink };
  RankType(RankType::Type rank_type) : rank_type_(rank_type) {}

 private:
  Type rank_type_;
};

class RankDir {
 public:
  enum Dir { kTb, kLr, kBt, kRl };
  RankDir(RankDir::Dir rank_dir) : rank_dir_(rank_dir) {}

 private:
  Dir rank_dir_;
};

using AddDouble = std::string;

using AddPoint = std::string;

using Shape = std::string;

using Style = std::string;

using EscString = std::string;

using ViewPort = std::string;

using LblString = std::string;

using Double = double;

using Int = int;

using Bool = bool;

using String = std::string;

using PortPos = std::string;

using PointList = std::vector<std::string>;

using PackMode = std::string;

template <typename T>
struct used_by_cluster : std::false_type {};

template <typename T>
struct used_by_edge : std::false_type {};

template <typename T>
struct used_by_graph : std::false_type {};

template <typename T>
struct used_by_node : std::false_type {};

template <typename T>
struct used_by_subgraph : std::false_type {};


}  // namespace graphvizwrapper

#endif  // _TYPES_H_