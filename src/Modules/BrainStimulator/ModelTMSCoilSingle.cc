/*
   For more information, please see: http://software.sci.utah.edu

   The MIT License

   Copyright (c) 2015 Scientific Computing and Imaging Institute,
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
#include <Modules/BrainStimulator/ModelTMSCoilSingle.h>
#include <iostream>
#include <Core/Datatypes/String.h>
#include <Core/Datatypes/Scalar.h>
#include <Core/Algorithms/BrainStimulator/ModelGenericCoilAlgorithm.h>
#include <Core/Datatypes/Legacy/Field/Field.h>
#include <Core/Datatypes/DenseMatrix.h>
#include <Core/Datatypes/MatrixTypeConversions.h>
#include <Core/Algorithms/Base/AlgorithmPreconditions.h>
#include <vector>

using namespace SCIRun::Modules::BrainStimulator;
using namespace SCIRun::Core::Datatypes;
using namespace SCIRun::Core::Algorithms;
using namespace SCIRun::Core::Algorithms::BrainStimulator;
using namespace SCIRun::Dataflow::Networks;

MODULE_INFO_DEF(ModelTMSCoilSingle, BrainStimulator, SCIRun)

ModelTMSCoilSingle::ModelTMSCoilSingle() : Module(ModuleLookupInfo("ModelTMSCoilSingle", "BrainStimulator", "SCIRun"),true)
{
 INITIALIZE_PORT(Mesh);
}

void ModelTMSCoilSingle::setStateDefaults()
{
  auto state = get_state();
  setStateIntFromAlgo(Parameters::FigureOf8CoilShape);
  setStateDoubleFromAlgo(Parameters::Current);
  setStateDoubleFromAlgo(Parameters::Radius);
  setStateDoubleFromAlgo(Parameters::Distance);
  setStateIntFromAlgo(Parameters::Layers);
  setStateDoubleFromAlgo(Parameters::LayerStepSize);
  setStateIntFromAlgo(Parameters::LevelOfDetail);
}

void ModelTMSCoilSingle::execute()
{
  AlgorithmOutput output;
   
 if (needToExecute())  //newStatePresent
 {   
   auto state = get_state();
   setAlgoIntFromState(Parameters::FigureOf8CoilShape);
   setAlgoDoubleFromState(Parameters::Current);
   setAlgoDoubleFromState(Parameters::Radius);
   setAlgoDoubleFromState(Parameters::Distance);
   setAlgoIntFromState(Parameters::Layers);
   setAlgoDoubleFromState(Parameters::LayerStepSize);
   setAlgoIntFromState(Parameters::LevelOfDetail);
   
   output = algo().run(AlgorithmInput()); 
   
   sendOutputFromAlgorithm(Mesh, output);
 }

}