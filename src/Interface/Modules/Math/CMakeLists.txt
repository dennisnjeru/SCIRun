#
#  For more information, please see: http://software.sci.utah.edu
#
#  The MIT License
#
#  Copyright (c) 2020 Scientific Computing and Imaging Institute,
#  University of Utah.
#
#  Permission is hereby granted, free of charge, to any person obtaining a
#  copy of this software and associated documentation files (the "Software"),
#  to deal in the Software without restriction, including without limitation
#  the rights to use, copy, modify, merge, publish, distribute, sublicense,
#  and/or sell copies of the Software, and to permit persons to whom the
#  Software is furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included
#  in all copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
#  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
#  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
#  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
#  DEALINGS IN THE SOFTWARE.
#


SET(Interface_Modules_Math_FORMS
  SelectSubMatrix.ui
  AppendMatrix.ui
  CreateGeometricTransform.ui
  CreateMatrix.ui
  CreateComplexMatrix.ui
  EvaluateLinearAlgebraBinary.ui
  EvaluateLinearAlgebraGeneral.ui
  EvaluateLinearAlgebraUnary.ui
  GetMatrixSlice.ui
  ReportMatrixInfo.ui
  ReportComplexMatrixInfo.ui
  SolveLinearSystem.ui
  SolveComplexLinearSystem.ui
  ConvertMatrixType.ui
  BuildNoiseColumnMatrix.ui
  ReportColumnMatrixMisfit.ui
  CollectMatrices.ui
  ReportMatrixSliceMeasureDialog.ui
  SetSubmatrix.ui
  BooleanCompareDialog.ui
  DisplayHistogram.ui
  BasicPlotter.ui
  AdvancedPlotter.ui
  ResizeMatrixDialog.ui
  CreateStandardMatrixDialog.ui
  ComputeTensorUncertainty.ui
)

SET(Interface_Modules_Math_HEADERS
  SelectSubMatrixDialog.h
  AppendMatrixDialog.h
  CreateGeometricTransformDialog.h
  CreateMatrixDialog.h
  CreateComplexMatrixDialog.h
  EvaluateLinearAlgebraBinaryDialog.h
  EvaluateLinearAlgebraGeneralDialog.h
  EvaluateLinearAlgebraUnaryDialog.h
  GetMatrixSliceDialog.h
  ReportMatrixInfoDialog.h
  ReportComplexMatrixInfoDialog.h
  share.h
  SolveLinearSystemDialog.h
  ConvertMatrixTypeDialog.h
  BuildNoiseColumnMatrixDialog.h
  ReportColumnMatrixMisfitDialog.h
  CollectMatricesDialog.h
  ReportMatrixSliceMeasureDialog.h
  SetSubmatrixDialog.h
  SolveComplexLinearSystemDialog.h
  BooleanCompareDialog.h
  DisplayHistogramDialog.h
  BasicPlotterDialog.h
  AdvancedPlotterDialog.h
  PlotDialog.h
  ResizeMatrixDialog.h
  CreateStandardMatrixDialog.h
  ComputeTensorUncertaintyDialog.h
)

SET(Interface_Modules_Math_SOURCES
  SelectSubMatrixDialog.cc
  AppendMatrixDialog.cc
  CreateGeometricTransformDialog.cc
  CreateMatrixDialog.cc
  CreateComplexMatrixDialog.cc
  EvaluateLinearAlgebraBinaryDialog.cc
  EvaluateLinearAlgebraGeneralDialog.cc
  EvaluateLinearAlgebraUnaryDialog.cc
  GetMatrixSliceDialog.cc
  ReportMatrixInfoDialog.cc
  ReportComplexMatrixInfoDialog.cc
  SolveLinearSystemDialog.cc
  ConvertMatrixTypeDialog.cc
  BuildNoiseColumnMatrixDialog.cc
  ReportColumnMatrixMisfitDialog.cc
  CollectMatricesDialog.cc
  ReportMatrixSliceMeasureDialog.cc
  SetSubmatrixDialog.cc
  SolveComplexLinearSystemDialog.cc
  BooleanCompareDialog.cc
  DisplayHistogramDialog.cc
  BasicPlotterDialog.cc
  AdvancedPlotterDialog.cc
  PlotDialog.cc
  ResizeMatrixDialog.cc
  CreateStandardMatrixDialog.cc
  ComputeTensorUncertaintyDialog.cc
)

QT_WRAP_UI(Interface_Modules_Math_FORMS_HEADERS "${Interface_Modules_Math_FORMS}")
QT_WRAP_CPP(Interface_Modules_Math_HEADERS_MOC "${Interface_Modules_Math_HEADERS}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../Base/CustomWidgets/CTK)

SCIRUN_ADD_LIBRARY(Interface_Modules_Math
  ${Interface_Modules_Math_HEADERS}
  ${Interface_Modules_Math_FORMS_HEADERS}
  ${Interface_Modules_Math_HEADERS_MOC}
  ${Interface_Modules_Math_SOURCES}
)

TARGET_LINK_LIBRARIES(Interface_Modules_Math
  Algorithms_Math
  Modules_Math
  Modules_Legacy_Math
  Interface_Modules_Base
  ${SCI_BOOST_LIBRARY}
  ${QT_LIBRARIES}
  ${SCI_QWT_LIBRARY}
  )


ADD_DEFINITIONS(-DQWT_DLL)

IF(BUILD_SHARED_LIBS)
  ADD_DEFINITIONS(-DBUILD_Interface_Modules_Math)
ENDIF(BUILD_SHARED_LIBS)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
