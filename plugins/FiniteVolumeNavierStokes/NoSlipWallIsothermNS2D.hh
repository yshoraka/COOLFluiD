#ifndef COOLFluiD_Numerics_FiniteVolume_NoSlipWallIsothermNS2D_hh
#define COOLFluiD_Numerics_FiniteVolume_NoSlipWallIsothermNS2D_hh

//////////////////////////////////////////////////////////////////////////////

#include "FiniteVolume/FVMCC_BC.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {
  
  namespace Physics {
    namespace NavierStokes {
      class Euler2DVarSet;
    }
  }
  
  namespace Numerics {
    
    namespace FiniteVolume {
          
//////////////////////////////////////////////////////////////////////////////

  /**
   * This class represents a command that applies the mirror bc 
   * 
   * @author Andrea Lani 
   *
   */
class NoSlipWallIsothermNS2D : public FVMCC_BC { 

public: 

  /**
   * Defines the Config Option's of this class
   * @param options a OptionList where to add the Option's
   */
  static void defineConfigOptions(Config::OptionList& options);
  
  /**
   * Constructor
   */
  NoSlipWallIsothermNS2D(const std::string& name);
  
  /**
   * Default destructor
   */
  ~NoSlipWallIsothermNS2D();
  
  /**
   * Set up private data and data of the aggregated classes 
   * in this command before processing phase
   */
  void setup();
  
  /**
   * Apply boundary condition on the given face
   */
  void setGhostState(Framework::GeometricEntity *const face);

  /**
   * Compute the flux in the current face
   */
  void computeFlux(RealVector& result);
  
 private:
    
  /// physical model var set
  Common::SafePtr<Physics::NavierStokes::Euler2DVarSet> _varSet;
  
  /// physical model data
  RealVector _dataInnerState;
  
  /// physical model data
  RealVector _dataGhostState;
  
  /// temperature at the wall
  CFreal _wallTemp;
  
  /// temporary node
  RealVector _tempNode;
  
  /// temporary middle node
  RealVector _midNode;
  
  /// temporary ghost node
  RealVector _tempGhostNode;
  
}; // end of class NoSlipWallIsothermNS2D

//////////////////////////////////////////////////////////////////////////////

 } // namespace FiniteVolume

  } // namespace Numerics

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#endif // COOLFluiD_Numerics_FiniteVolume_NoSlipWallIsothermNS2D_hh
