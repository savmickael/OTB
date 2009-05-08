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
#ifndef __otbRenderingFunction_h
#define __otbRenderingFunction_h

#include "itkObject.h"
#include "itkObjectFactory.h"
#include "itkVariableLengthVector.h"
#include "itkRGBPixel.h"
#include "itkRGBAPixel.h"

namespace otb
{
namespace Function
{
/**\class RenderingFunction
 * \brief Base class for rendering functions.
 *  Please note that this class is pure virtual, and should be
 *  subclassed.
 *  \ingroup Visualization
 */
template <class TPixelPrecision, class TRGBPixel>
class RenderingFunction
  : public itk::Object
{
public:
  /** Standard class typedefs */
  typedef RenderingFunction             Self;
  typedef itk::Object                   Superclass;
  typedef itk::SmartPointer<Self>       Pointer;
  typedef itk::SmartPointer<const Self> ConstPointer;

  /** type macro */
  itkTypeMacro(RenderingFunction,Object);

  /** PixelType macros */
  typedef TRGBPixel                                  OutputPixelType;
  typedef TPixelPrecision                            PixelType;
  typedef typename itk::NumericTraits<PixelType>::ValueType ScalarType;
  typedef itk::VariableLengthVector<ScalarType>       VectorPixelType;
  typedef itk::RGBPixel<ScalarType> RGBPixelType;
  typedef itk::RGBAPixel<ScalarType> RGBAPixelType;

  /** Extrema vector */
  typedef std::vector<ScalarType>               ExtremaVectorType;

  /** Evaluate method (scalar version) */
  virtual const OutputPixelType Evaluate(ScalarType spixel) const = 0;

  /** Evaluate method (vector version) */
  virtual const OutputPixelType Evaluate(const VectorPixelType & vpixel) const = 0;

  /** Evaluate method (RGB pixel version) */
  virtual const OutputPixelType Evaluate(const RGBPixelType & vpixel) const = 0;

  /** Evaluate method (RGBA pixel version) */
  virtual const OutputPixelType Evaluate(const RGBAPixelType & vpixel) const = 0;

  /** Get a string description of a pixel  (scalar version) */
  virtual const std::string Describe(PixelType spixel) const = 0;

  /** Get a string description of a pixel (vector version) */
  virtual const std::string Describe(const VectorPixelType& vpixel) const = 0;

  /** This method is available to allow implementation of
   * preprocessing.
   */
  virtual void Initialize() = 0;

  /** Set the minimum (scalar version) */
  virtual void SetMinimum(ScalarType spixel)
  {
    m_Minimum.clear();
    m_Minimum.push_back(spixel);
  }

  /** Set the maximum (scalar version) */
  virtual void SetMaximum(ScalarType spixel)
  {
    m_Maximum.clear();
    m_Maximum.push_back(spixel);
  }

 /** Set minimum (vector version) */
  virtual void SetMinimum(const VectorPixelType & vpixel)
  {
    m_Minimum.clear();
    for(unsigned int i = 0; i < vpixel.Size();++i)
      {
      m_Minimum.push_back(vpixel[i]);
      }
  }

  /** Set maximum (vector version) */
  virtual void SetMaximum(const VectorPixelType & vpixel)
  {
    m_Maximum.clear();
    for(unsigned int i = 0; i < vpixel.Size();++i)
      {
      m_Maximum.push_back(vpixel[i]);
      }
  }

  /** Set minimum (std::vector version) */
  virtual void SetMinimum(const ExtremaVectorType & vpixel)
  {
    m_Minimum = vpixel;
  }

  /** Set maximum (std::vector version) */
  virtual void SetMaximum(const ExtremaVectorType & vpixel)
  {
    m_Maximum = vpixel;
  }

protected:
  /** Constructor */
  RenderingFunction() : m_Minimum(), m_Maximum()  {}
  /** Destructor */
  virtual ~RenderingFunction() {}

  /** Extrema values */
  ExtremaVectorType m_Minimum;
  ExtremaVectorType m_Maximum;

private:
  RenderingFunction(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};
} // end namespace Function
} // end namepsace otb

#endif


