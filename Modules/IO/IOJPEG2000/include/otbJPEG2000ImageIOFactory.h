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
#ifndef otbJPEG2000ImageIOFactory_h
#define otbJPEG2000ImageIOFactory_h

#include "itkObjectFactoryBase.h"

namespace otb
{
/** \class JPEG2000ImageIOFactory
 * \brief Create instances of JPEG2000ImageIO objects using an object factory.
 *
 * \ingroup OTBIOJPEG2000
 */
class ITK_EXPORT JPEG2000ImageIOFactory : public itk::ObjectFactoryBase
{
public:
  /** Standard class typedefs. */
  typedef JPEG2000ImageIOFactory        Self;
  typedef itk::ObjectFactoryBase        Superclass;
  typedef itk::SmartPointer<Self>       Pointer;
  typedef itk::SmartPointer<const Self> ConstPointer;

  /** Class methods used to interface with the registered factories. */
  const char* GetITKSourceVersion(void) const ITK_OVERRIDE;
  const char* GetDescription(void) const ITK_OVERRIDE;

  /** Method for class instantiation. */
  itkFactorylessNewMacro(Self);
  static JPEG2000ImageIOFactory * FactoryNew() { return new JPEG2000ImageIOFactory; }

  /** Run-time type information (and related methods). */
  itkTypeMacro(JPEG2000ImageIOFactory, itk::ObjectFactoryBase);

  /** Register one factory of this type  */
  static void RegisterOneFactory(void)
  {
    JPEG2000ImageIOFactory::Pointer JPEG2000Factory = JPEG2000ImageIOFactory::New();
    itk::ObjectFactoryBase::RegisterFactory(JPEG2000Factory);
  }

protected:
  JPEG2000ImageIOFactory();
  ~JPEG2000ImageIOFactory() ITK_OVERRIDE;

private:
  JPEG2000ImageIOFactory(const Self &); //purposely not implemented
  void operator =(const Self&); //purposely not implemented

};

} // end namespace otb

#endif
