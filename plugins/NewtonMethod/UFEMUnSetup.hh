// Copyright (C) 2012 von Karman Institute for Fluid Dynamics, Belgium
//
// This software is distributed under the terms of the
// GNU Lesser General Public License version 3 (LGPLv3).
// See doc/lgpl.txt and doc/gpl.txt for the license text.

#ifndef COOLFluiD_Numerics_NewtonMethod_UFEMUnSetup_hh
#define COOLFluiD_Numerics_NewtonMethod_UFEMUnSetup_hh

//////////////////////////////////////////////////////////////////////////////

#include "Framework/DataSocketSink.hh"
#include "NewtonIteratorData.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Numerics {

    namespace NewtonMethod {

//////////////////////////////////////////////////////////////////////////////

/// This class represents a NumericalCommand action to be
/// to be executed in order to deallocate data specific to the
/// method to which it belongs.
/// @author Tamas Banyai
class UFEMUnSetup : public NewtonIteratorCom {
public:

  /// Constructor.
  explicit UFEMUnSetup(std::string name);
  /// Destructor.
  ~UFEMUnSetup();

  /// Returns the DataSocket's that this command needs as sinks
  /// @return a vector of SafePtr with the DataSockets
  std::vector<Common::SafePtr<Framework::BaseDataSocketSink> > needsSockets();

  /// Execute Processing actions
  void execute();

protected:

  /// socket for the inter states
  Framework::DataSocketSink<Framework::State*> socket_interStates;

  /// socket for the past states
  Framework::DataSocketSink<Framework::State*> socket_pastStates;

  /// socket for the past past states
  Framework::DataSocketSink<Framework::State*> socket_pastpastStates;

}; // class Setup

//////////////////////////////////////////////////////////////////////////////

    } // namespace NewtonMethod

  } // namespace Numerics

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#endif // COOLFluiD_Numerics_NewtonMethod_UFEMUnSetup_hh
