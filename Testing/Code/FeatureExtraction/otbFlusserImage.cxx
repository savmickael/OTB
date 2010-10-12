/*=========================================================================

  Program:   ORFEO Toolbox
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
  See OTBCopyright.txt for details.


  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

#include <iostream>
#include <iomanip>
#include <fstream>
#include "itkExceptionObject.h"
#include "itkImage.h"

#include "otbImageFileReader.h"
#include "otbFlusserImageFunction.h"

int otbFlusserImage(int argc, char * argv[])
{
  const char * inputFilename  = argv[1];
  const char * outputFilename  = argv[2];

  typedef unsigned char InputPixelType;
  const unsigned int Dimension = 2;

  typedef itk::Image<InputPixelType,  Dimension>                  InputImageType;
  typedef otb::ImageFileReader<InputImageType>                    ReaderType;
  typedef std::complex<float>                                     ComplexType;
  typedef otb::FlusserImageFunction<InputImageType>               FunctionType;
  typedef FunctionType::RealType                                  RealType;

  ReaderType::Pointer   reader         = ReaderType::New();
  FunctionType::Pointer function       = FunctionType::New();

  reader->SetFileName(inputFilename);
  reader->Update();
  function->SetInputImage(reader->GetOutput());

  InputImageType::IndexType index;
  index[0] = 10;
  index[1] = 10;

  function->SetNeighborhoodRadius(3);  
  RealType Result;
  Result = function->EvaluateAtIndex(index);

  std::ofstream outputStream(outputFilename);
  outputStream << std::setprecision(10) << "Flusser Image moments: [10]" << std::endl;

  for (unsigned int j = 1; j < 12; j++)
    {
    outputStream << "Flusser(" << j << ") = " << Result[j-1] << std::endl;
    }

  outputStream.close();

  return EXIT_SUCCESS;
}
