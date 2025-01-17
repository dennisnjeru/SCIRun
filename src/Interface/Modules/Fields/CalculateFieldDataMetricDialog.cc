/*
   For more information, please see: http://software.sci.utah.edu

   The MIT License

   Copyright (c) 2020 Scientific Computing and Imaging Institute,
   University of Utah.

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/


#include <Interface/Modules/Fields/CalculateFieldDataMetricDialog.h>
#include <Modules/Legacy/Fields/CalculateFieldDataMetric.h>
#include <Interface/Modules/Base/CustomWidgets/CodeEditorWidgets.h>
#include <Core/Algorithms/Base/AlgorithmVariableNames.h>

using namespace SCIRun::Gui;
using namespace SCIRun::Dataflow::Networks;
using namespace SCIRun::Core::Algorithms;
using namespace SCIRun::Core::Algorithms::Fields;

CalculateFieldDataMetricDialog::CalculateFieldDataMetricDialog(const std::string& name, ModuleStateHandle state,
  QWidget* parent /* = 0 */)
  : ModuleDialogWithParserHelp(state, parent)
{
  setupUi(this);
  setWindowTitle(QString::fromStdString(name));
  fixSize();

  addComboBoxManager(metricComboBox_, Variables::Method,
    {{"Minimum", "min"},
    {"Maximum", "max"},
    {"Median", "median"},
    {"Value-mean", "value-mean"},
    {"Geometry-mean", "geom-mean"},
    {"Sum", "sum"},
    {"Integral", "integral"},
    {"Volthreshold", "volthreshold"}
  });
  addCheckBoxManager(enableFunctionCheckBox_, Parameters::EnableFunction);
  connectParserHelpButton(parserHelpButton_);

  {
    codeEdit_ = new CodeEditor(this);
    qobject_cast<QVBoxLayout*>(expressionGroupBox_->layout())->insertWidget(0, codeEdit_);
    addPlainTextEditManager(codeEdit_, Variables::FunctionString);
  }
}
