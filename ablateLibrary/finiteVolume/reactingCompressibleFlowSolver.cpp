#include "reactingCompressibleFlowSolver.hpp"

#include <utility>
#include "finiteVolume/processes/tChemReactions.hpp"
#include "utilities/vectorUtilities.hpp"

ablate::finiteVolume::ReactingCompressibleFlowSolver::ReactingCompressibleFlowSolver(std::string solverId, std::shared_ptr<domain::Region> region, std::shared_ptr<parameters::Parameters> options,
                                                                                     const std::shared_ptr<eos::EOS>& eosIn, std::shared_ptr<parameters::Parameters> parameters,
                                                                                     std::shared_ptr<eos::transport::TransportModel> transport,
                                                                                     std::shared_ptr<fluxCalculator::FluxCalculator> fluxCalculatorIn,
                                                                                     std::vector<std::shared_ptr<boundaryConditions::BoundaryCondition>> boundaryConditions,
                                                                                     std::vector<std::shared_ptr<processes::Process>> additionalProcesses, bool computePhysicsTimeStep)
    : CompressibleFlowSolver(std::move(solverId), std::move(region), std::move(options), eosIn, std::move(parameters), std::move(transport), std::move(fluxCalculatorIn),
                             ablate::utilities::VectorUtilities::Merge(
                                 {std::make_shared<ablate::finiteVolume::processes::TChemReactions>(
                                     std::dynamic_pointer_cast<eos::TChem>(eosIn) ? std::dynamic_pointer_cast<eos::TChem>(eosIn) : throw std::invalid_argument("The eos must of type eos::TChem"))},
                                 additionalProcesses),
                             std::move(boundaryConditions), computePhysicsTimeStep) {}

#include "registrar.hpp"
REGISTER(ablate::solver::Solver, ablate::finiteVolume::ReactingCompressibleFlowSolver, "reacting compressible finite volume flow", ARG(std::string, "id", "the name of the flow field"),
         OPT(ablate::domain::Region, "region", "the region to apply this solver.  Default is entire domain"), OPT(ablate::parameters::Parameters, "options", "the options passed to PETSc"),
         ARG(ablate::eos::EOS, "eos", "the TChem v1 equation of state used to describe the flow"),
         ARG(ablate::parameters::Parameters, "parameters", "the compressible flow parameters cfl, gamma, etc."),
         OPT(ablate::eos::transport::TransportModel, "transport", "the diffusion transport model"),
         OPT(ablate::finiteVolume::fluxCalculator::FluxCalculator, "fluxCalculator", "the flux calculator (defaults to AUSM)"),
         OPT(std::vector<ablate::finiteVolume::boundaryConditions::BoundaryCondition>, "boundaryConditions", "the boundary conditions for the flow field"),
         OPT(std::vector<ablate::finiteVolume::processes::Process>, "additionalProcesses", "any additional processes besides euler/yi/ev transport and rxn"),
         OPT(bool, "computePhysicsTimeStep", "determines if a physics based time step is used to control the FVM time stepping (default is false)"));