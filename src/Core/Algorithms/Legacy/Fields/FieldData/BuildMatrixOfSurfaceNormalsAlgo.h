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


#ifndef CORE_ALGORITHMS_FIELDS_FIELDDATA_BUILDMATRIXOFSURFACENORMALSALGO_H
#define CORE_ALGORITHMS_FIELDS_FIELDDATA_BUILDMATRIXOFSURFACENORMALSALGO_H 1

#include <Core/Algorithms/Base/AlgorithmBase.h>
#include <Core/Datatypes/DatatypeFwd.h>
#include <Core/Algorithms/Legacy/Fields/share.h>

namespace SCIRun {
namespace Core {
namespace Algorithms {
namespace Fields {

  class SCISHARE BuildMatrixOfSurfaceNormalsAlgo : public AlgorithmBase
  {
  public:
			BuildMatrixOfSurfaceNormalsAlgo();
			bool runImpl(FieldHandle input, Datatypes::DenseMatrixHandle& output) const;
			AlgorithmOutput run(const AlgorithmInput& input) const override;
  };

}}}}

#endif
