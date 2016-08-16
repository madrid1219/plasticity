/*FE parameters*/
#define feOrder   1 // Basis function interpolation order (1-linear)
#define quadOrder 2 // Quadrature point order n^3 (2->8 quadrature points)

/*Mesh parameters*/
//Set the length of the domain in all three dimensions
//Each axes spans from zero to the specified length
#define spanX 1.0
#define spanY 1.0
#define spanZ 1.0
// The number of elements in each direction is 2^(refineFactor) * subdivisions
// For optimal performance, use meshRefineFactor primarily to determine the element size
#define subdivisionsX 1
#define subdivisionsY 1
#define subdivisionsZ 1
#define meshRefineFactor 3 // 2^n*2^n*2^n elements(3->8*8*8 =512 elements)
#define writeMeshToEPS  true //Only written for serial runs and if number of elements < 10000

/*Solution output parameters*/
#define writeOutput true // flag to write output vtu and pvtu files
#define outputDirectory "."
#define skipOutputSteps 0
#define output_Eqv_strain true
#define output_Eqv_stress true
#define output_Grain_ID   true

/*Solver parameters*/
#define linearSolverType PETScWrappers::SolverCG // Type of linear solver
#define totalNumIncrements 1 // No. of increments
#define maxLinearSolverIterations 50000 // Maximum iterations for linear solver
#define relLinearSolverTolerance  1.0e-10 // Relative linear solver tolerance
#define maxNonLinearIterations 5 // Maximum no. of non-linear iterations
#define absNonLinearTolerance 1.0e-18 // Non-linear solver tolerance
#define relNonLinearTolerance 1.0e-6 // Relative non-linear solver tolerance
#define stopOnConvergenceFailure false // Flag to stop problem if convergence fails

/*Adaptive time-stepping parameters*/
#define enableAdaptiveTimeStepping true
#define adaptiveLoadStepFactor 0.5
#define adaptiveLoadIncreaseFactor 1.25
#define succesiveIncForIncreasingTimeStep 10

//Elastic Parameters
double elasticStiffness[6][6]={{170.0e3, 124.0e3, 124.0e3, 0, 0, 0},
				   {124.0e3, 170.0e3, 124.0e3, 0, 0, 0},
				   {124.0e3, 124.0e3, 170.0e3, 0, 0, 0},
				   {0, 0, 0, 75.0e3, 0, 0},
				   {0, 0, 0, 0, 75.0e3, 0}, 
				   {0, 0, 0, 0, 0, 75.0e3}}; // 	Elastic Stiffness Matrix -Voigt Notation (MPa)



//Crystal Plasticity parameters
#define numSlipSystems 12 // generally 12 for FCC
#define latentHardeningRatio 1.4  //q1

double initialSlipResistance[numSlipSystems]= {16.0, 16.0, 16.0, 16.0, 16.0, 16.0, 16.0, 16.0, 16.0, 16.0, 16.0, 16.0};
double initialHardeningModulus[numSlipSystems]= {180.0, 180.0, 180.0, 180.0, 180.0, 180.0, 180.0, 180.0, 180.0, 180.0, 180.0, 180.0};
double powerLawExponent[numSlipSystems]= {2.25, 2.25, 2.25, 2.25, 2.25, 2.25, 2.25, 2.25, 2.25, 2.25, 2.25, 2.25};
double saturationStress[numSlipSystems]= {148.0, 148.0, 148.0, 148.0, 148.0, 148.0, 148.0, 148.0, 148.0, 148.0, 148.0, 148.0};


// Crystal Plasticity Constitutive model parameters
#define modelStressTolerance 1.0e-6 // Stress tolerance for the yield surface (MPa)
#define modelMaxSlipSearchIterations 20 // Maximum no. of active slip search iterations
#define modelMaxSolverIterations 10 // Maximum no. of iterations to achieve non-linear convergence
#define modelMaxPlasticSlipL2Norm 0.8 // L2-Norm of plastic slip strain-used for load-step adaptivity


//Read Input Microstructure
unsigned int numPts[3]={20, 20, 22}; // No. of voxels in x,y and z directions






