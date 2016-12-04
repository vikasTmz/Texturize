//
// MATLAB Compiler: 6.0 (R2015a)
// Date: Sat Dec  3 21:27:28 2016
// Arguments: "-B" "macro_default" "-W" "cpplib:TextureTransfer" "-T"
// "link:lib" "-d"
// "/home/vikas/Documents/MATLAB/ImageQuilting/TextureTransfer/for_testing"
// "-v" "/home/vikas/Documents/MATLAB/ImageQuilting/cut.m"
// "/home/vikas/Documents/MATLAB/ImageQuilting/Demo.m"
// "/home/vikas/Documents/MATLAB/ImageQuilting/find_mindelta.m"
// "/home/vikas/Documents/MATLAB/ImageQuilting/get_ssd.m"
// "/home/vikas/Documents/MATLAB/ImageQuilting/texture_transfer.m" 
//

#ifndef __TextureTransfer_h
#define __TextureTransfer_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_TextureTransfer
#define PUBLIC_TextureTransfer_C_API __global
#else
#define PUBLIC_TextureTransfer_C_API /* No import statement needed. */
#endif

#define LIB_TextureTransfer_C_API PUBLIC_TextureTransfer_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_TextureTransfer
#define PUBLIC_TextureTransfer_C_API __declspec(dllexport)
#else
#define PUBLIC_TextureTransfer_C_API __declspec(dllimport)
#endif

#define LIB_TextureTransfer_C_API PUBLIC_TextureTransfer_C_API


#else

#define LIB_TextureTransfer_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_TextureTransfer_C_API 
#define LIB_TextureTransfer_C_API /* No special import/export declaration */
#endif

extern LIB_TextureTransfer_C_API 
bool MW_CALL_CONV TextureTransferInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_TextureTransfer_C_API 
bool MW_CALL_CONV TextureTransferInitialize(void);

extern LIB_TextureTransfer_C_API 
void MW_CALL_CONV TextureTransferTerminate(void);



extern LIB_TextureTransfer_C_API 
void MW_CALL_CONV TextureTransferPrintStackTrace(void);

extern LIB_TextureTransfer_C_API 
bool MW_CALL_CONV mlxCut(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_TextureTransfer_C_API 
bool MW_CALL_CONV mlxDemo(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_TextureTransfer_C_API 
bool MW_CALL_CONV mlxFind_mindelta(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_TextureTransfer_C_API 
bool MW_CALL_CONV mlxGet_ssd(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_TextureTransfer_C_API 
bool MW_CALL_CONV mlxTexture_transfer(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_TextureTransfer
#define PUBLIC_TextureTransfer_CPP_API __declspec(dllexport)
#else
#define PUBLIC_TextureTransfer_CPP_API __declspec(dllimport)
#endif

#define LIB_TextureTransfer_CPP_API PUBLIC_TextureTransfer_CPP_API

#else

#if !defined(LIB_TextureTransfer_CPP_API)
#if defined(LIB_TextureTransfer_C_API)
#define LIB_TextureTransfer_CPP_API LIB_TextureTransfer_C_API
#else
#define LIB_TextureTransfer_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_TextureTransfer_CPP_API void MW_CALL_CONV cut(int nargout, mwArray& imout, const mwArray& sample, const mwArray& patchsize, const mwArray& overlap, const mwArray& imout_in1, const mwArray& samplepos, const mwArray& imoutpos);

extern LIB_TextureTransfer_CPP_API void MW_CALL_CONV Demo(int nargout, mwArray& imout3);

extern LIB_TextureTransfer_CPP_API void MW_CALL_CONV find_mindelta(int nargout, mwArray& mintexturepos, const mwArray& texture, const mwArray& target, const mwArray& targetpos, const mwArray& patchsize, const mwArray& tol);

extern LIB_TextureTransfer_CPP_API void MW_CALL_CONV get_ssd(int nargout, mwArray& cost, const mwArray& texture, const mwArray& texturepos1, const mwArray& texturepos2, const mwArray& targetposnew, const mwArray& patchsize);

extern LIB_TextureTransfer_CPP_API void MW_CALL_CONV texture_transfer(int nargout, mwArray& imout, const mwArray& texture, const mwArray& target, const mwArray& patchsize, const mwArray& overlap, const mwArray& tol);

#endif
#endif
