#ifndef COOLFluiD_Numerics_SpectralFV_RoeFlux_hh
#define COOLFluiD_Numerics_SpectralFV_RoeFlux_hh

//////////////////////////////////////////////////////////////////////////////

#include "Framework/BaseMethodStrategyProvider.hh"
#include "SpectralFV/SpectralFVMethodData.hh"
#include "SpectralFV/RiemannFlux.hh"
#include "Framework/JacobianLinearizer.hh"
#include "Framework/VarSetTransformer.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace SpectralFV {

//////////////////////////////////////////////////////////////////////////////

/**
 * This class represent a Roe flux
 *
 * @author Kris Van den Abeele
 * @author Tiago Quintino
 */
class RoeFlux : public RiemannFlux {

public:  // methods

  /// Constructor
  RoeFlux(const std::string& name);

  /// Destructor
  ~RoeFlux();

  /// Compute the Riemann flux, from left and right states and a normal vector
  virtual RealVector& computeFlux(Framework::State& lState, RealVector& lExtraVars,
                                  Framework::State& rState, RealVector& rExtraVars,
                                  const RealVector& normal);

  /// Compute the Riemann flux, from a vector of left and right states and a normal vector
  /// States data must be computed before calling this function!!!
  virtual std::vector< RealVector >& computeFlux(std::vector< Framework::State* >& lState,
                                                 std::vector< Framework::State* >& rState,
                                                 const std::vector< RealVector >& normal,
                                                 const CFuint nbrFlxPnts);

  /// Compute the numerical damping term in the Riemann flux,
  /// from left and right states and a normal vector
  virtual RealVector& computeNumDamping(Framework::State& lState, RealVector& lExtraVars,
                                        Framework::State& rState, RealVector& rExtraVars,
                                        const RealVector& normal);

  /// Compute the numerical damping term in the Riemann flux,
  /// from a vector of left and right states and a normal vector
  /// States data must be computed before calling this function!!!
  virtual std::vector< RealVector >& computeNumDamping(std::vector< Framework::State* >& lState,
                                                       std::vector< Framework::State* >& rState,
                                                       const std::vector< RealVector >& normal,
                                                       const CFuint nbrFlxPnts);

  /// Gets the Class name
  static std::string getClassName()
  {
    return "RoeFlux";
  }

  /// Set up private data and data
  virtual void setup();

private: // helper function

  /**
   * Set the absolute value of the eigen values. Entropy and carbuncle fixes can be implemented in this function
   */
  virtual void SetAbsEigenValues();

private: // data

  /// jacobian linearizer
  Common::SelfRegistPtr<Framework::JacobianLinearizer> m_linearizer;

  /// variable set transformer from solution to linearization variables
  Common::SelfRegistPtr<Framework::VarSetTransformer> m_solutionToLinearVarTrans;

  /// variable set transformer from update to solution variables
  Common::SelfRegistPtr<Framework::VarSetTransformer> m_updateToSolutionVarTrans;

  /// array storing the sum of the right and left flux
  RealVector   m_sumFlux;

  /// matrix of right eigenvectors
  RealMatrix   m_rightEv;

  /// matrix of left eigenvectors
  RealMatrix   m_leftEv;

  /// vector of eigenvalues
  RealVector   m_eValues;

  /// vector of right state eigenvalues
  RealVector   m_rightEvalues;

  /// vector of left state eigenvalues
  RealVector   m_leftEvalues;

  /// vector of eigenvalues
  RealVector   m_absEvalues;

  /// abs of the jacobian matrix
  RealMatrix   m_absJacob;

  /// vector storing the left and right update states
  std::vector<Framework::State*> m_updateStates;

  /// vector storing the left and right update states in one flux point
  std::vector<Framework::State*> m_updateStatesInFlxPnt;

  /// vector storing left and right extra variables in one flux point
  std::vector< RealVector* > m_extraVarsInFlxPnt;

  /// vector storing the left and right solution states
  std::vector<Framework::State*>* m_solStates;

  /// vector storing the left and right solution states in one flux point
  std::vector<Framework::State*> m_solStatesInFlxPnt;

  /// vector storing the left and right linear states
  std::vector<Framework::State*>* m_linStates;

}; // class RoeFlux

//////////////////////////////////////////////////////////////////////////////

  }  // namespace SpectralFV

}  // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#endif  // COOLFluiD_Numerics_SpectralFV_RoeFlux_hh
