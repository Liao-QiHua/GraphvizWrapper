#ifndef _ATTRIBUTES_H_
#define _ATTRIBUTES_H_
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
#include <vector>

#include "include/types.h"

namespace graphvizwrapper {

class Attribute {
 public:
  Attribute(std::string key, std::string value) : key_(key), value_(value) {}
  ~Attribute() = default;
  std::string to_string() { return key_ + " = \"" + value_ + "\""; }

 protected:
  std::string key_;
  std::string value_;
};

class AttributeList {
 public:
  AttributeList() {}
  ~AttributeList() = default;
  void AddAttr(std::string key, std::string value) {
    attr_list_.push_back(Attribute(key, value));
  }
  void AddAttr(Attribute &attr) { attr_list_.push_back(attr); }
  // "c 7 -#ff0000 p 4 4 4 36 4 36 36 4 36"
  void Set_Background(std::string value) {}
  void SetArea(std::string value) {}
  void SetArrowhead(ArrowType value) {}
  void SetArrowsize(Double value) {}
  void SetArrowtail(ArrowType value) {}
  void SetBb(Rect value) {}
  void SetBeautify(Bool value) {}
  void SetBgcolor(Color value) {}
  void SetBgcolor(ColorList value) {}
  void SetCenter(Bool value) {}
  void SetCharset(String value) {}
  void SetClass(String value) {}
  void SetCluster(Bool value) {}
  void SetClusterrank(ClusterMode value) {}
  void SetColor(Color value) {}
  void SetColor(ColorList value) {}
  void SetColorscheme(String value) {}
  void SetComment(String value) {}
  void SetCompound(Bool value) {}
  void SetConcentrate(Bool value) {}
  void SetConstraint(Bool value) {}
  void SetDamping(Double value) {}
  void SetDecorate(Bool value) {}
  void SetDefaultdist(Double value) {}
  void SetDim(Int value) {}
  void SetDimen(Int value) {}
  void SetDiredgeconstraints(Int value) {}
  void SetDistortion(Double value) {}
  void SetDpi(Double value) {}
  void SetEdgehref(EscString value) {}
  void SetEdgetarget(EscString value) {}
  void SetEdgetooltip(EscString value) {}
  void SetEdgeUrl(EscString value) {}
  void SetEpsilon(Double value) {}
  void SetEsep(AddDouble value) {}
  // void SetEsep(AddPoint value) {}
  void SetFillcolor(Color valur) {}
  void SetFillcolor(ColorList valur) {}
  void SetFixedsize(Bool value) {}
  void SetFixedsize(String value) {}
  void SetFontname(String value) {}
  void SetFontnames(String value) {}
  void SetFontpath(String value) {}
  void SetFontsize(Double value) {}
  void SetForcelabels(Bool value) {}
  void SetGradientangle(Int value) {}
  void SetGroup(String value) {}
  void SetHead_lp(Point value) {}
  void SetHeadclip(Bool value) {}
  void SetHeadhref(EscString value) {}
  void SetHeadLabel(LblString value) {}
  void Setheadport(PortPos value) {}
  void SetHeadtarget(EscString value) {}
  void SetHeadtooltip(EscString value) {}
  void SetHeadUrl(EscString value) {}
  void SetHeight(Double value) {}
  void SetHref(EscString value) {}
  void SetId(EscString value) {}
  void SetImage(String value) {}
  void SetImagepath(String value) {}
  void SetImagepos(String value) {}
  void SetImagescale(Bool value) {}
  void SetInputscale(Double value) {}
  void SetK(Double value) {}
  void SetLabel(LblString value) {}
  void SetLabel_scheme(Int value) {}
  void SetLabelangle(Double value) {}
  void SetLabelfloat(Bool value) {}
  void SetLabelfontcolor(Color value) {}
  void SetLabelfontname(String value) {}
  void SetLabelfontsize(Double value) {}
  void SetLabelhref(EscString value) {}
  void SetLabeljust(String value) {}
  void Setlabelloc(String value) {}
  void SetLabeltarget(EscString value) {}
  void SetLabeltooltip(EscString value) {}
  void SetLabelUrl(EscString value) {}
  void SetLandscape(Bool value) {}
  void SetLayer(LayerRange value) {}
  void SetLayerlistsep(String value) {}
  void SetLayers(LayerList value) {}
  void SetLayerselect(LayerRange value) {}
  void SetLayersep(String valur) {}
  void SetLayout(String value) {}
  void SetLen(Double value) {}
  void SetLevels(Int value) {}
  void SetLevelsgap(Double value) {}
  void SetLhead(String value) {}
  void SetLheight(String value) {}
  void SetLinelength(Int value) {}
  void SetLp(Point value) {}
  void SetLtail(String value) {}
  void SetLwidth(Double value) {}
  void SetMargin(Double value) {}
  void SetMargin(Point value) {}
  void SetMaxiter(Int value) {}
  void SetMclimit(Double value) {}
  void SetMindist(Double value) {}
  void SetMinlen(Int value) {}
  void SetMode(String value) {}
  void SetModel(String value) {}
  void SetNewrank(Bool value) {}
  void SetNodesep(Double value) {}
  void SetNojustify(Bool value) {}
  void SetNormalize(Double value) {}
  void SetNormalize(Bool value) {}
  void SetNotranslate(Bool value) {}
  void SetNslimit(Double value) {}
  void SetNslimit1(Double value) {}
  void SetOneblock(Bool value) {}
  void SetOrdering(String value) {}
  void SetOrientation(Double value) {}
  void SetOrientation(String value) {}
  void SetOutputorder(OutputMode value) {}
  void SetOverlap(String value) {}
  void SetOverlap(Bool value) {}
  void SetOverlap_scaling(Double value) {}
  void SetOverlap_shrink(Bool value) {}
  void SetPack(Bool value) {}
  void SetPack(Int value) {}
  void SetPackmode(PackMode value) {}
  void SetPad(Double value) {}
  void SetPad(Point value) {}
  void SetPage(Double value) {}
  void SetPage(Point value) {}
  void SetPageDir(PageDir value) {}
  void SetPencolor(Color value) {}
  void SetPenwidth(Double value) {}
  void SetPeripheries(Int value) {}
  void SetPin(Bool value) {}
  void SetPos(Point value) {}
  // void SetPos(SplineType value) {}
  void SetQuadtree(QuadType value) {}
  void SetQuantum(Double value) {}
  void SetRank(RankType value) {}
  void SetRankdir(RankDir value) {}
  void SetRanksep(Double value) {}
  // void SetRanksep(DoubleList value) {}
  void setRatio(Double value) {}
  void SetRatio(String value) {}
  void SetRects(Rect value) {}
  void SetRegular(Bool value) {}
  void SetRemincross(Bool value) {}
  void SetRepulsiveforce(Double value) {}
  void SetResolution(Double value) {}
  void SetRoot(String value) {}
  void SetRoot(Bool value) {}
  void SetRotate(Int value) {}
  void SetRotation(Double value) {}
  void SetSamehead(String value) {}
  void SetSametail(String value) {}
  void SetSamplepoints(Int value) {}
  void SetScale(Double value) {}
  void SetScale(Point value) {}
  void SetSearchsize(Int value) {}
  void SetSep(AddDouble value) {}
  // void SetSep(AddPoint value) {}
  void SetShape(Shape value) {}
  void SetShapefile(String value) {}
  void SetShowboxes(Int value) {}
  void SetSides(Int value) {}
  void SetSize(Double value) {}
  void SetSize(Point value) {}
  void SetSkew(Double value) {}
  void SetTail_lp(Point value) {}
  void SetTailclip(Bool value) {}
  void SetTailhref(EscString value) {}
  void SetTaillabel(LblString value) {}
  void SetTailport(PortPos value) {}
  void SetTailtarget(EscString value) {}
  void SetTailtooltip(EscString value) {}
  void SetTailURL(EscString value) {}
  void SetTarget(EscString value) {}
  // void SetTarget(String value) {}
  void SetTBbalance(String value) {}
  void SetTooltip(EscString value) {}
  void SetTruecolor(Bool value) {}
  void SetURL(EscString value) {}
  void SetVertices(PointList value) {}
  void SetViewport(ViewPort value) {}
  void SetVoro_margin(Double value) {}
  void SetWeight(Double value) {}
  void SetWeight(Int value) {}
  void SetWidth(Double value) {}
  void SetXdotversion(String value) {}
  void SetXlabel(LblString value) {}
  void SetXlp(Point value) {}
  void SetZ(Double value) {}
  bool Empty() { return attr_list_.empty(); }
  std::string to_string();

 protected:
  std::vector<Attribute> attr_list_;
};
}  // namespace graphvizwrapper

#endif  // _ATTRIBUTES_H_