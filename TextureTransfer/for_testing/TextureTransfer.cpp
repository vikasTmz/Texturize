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

#include <stdio.h>
#define EXPORTING_TextureTransfer 1
#include "TextureTransfer.h"

static HMCRINSTANCE _mcr_inst = NULL;


#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
  return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
  int written = 0;
  size_t len = 0;
  len = strlen(s);
  written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
  if (len > 0 && s[ len-1 ] != '\n')
    written += mclWrite(2 /* stderr */, "\n", sizeof(char));
  return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_TextureTransfer_C_API
#define LIB_TextureTransfer_C_API /* No special import/export declaration */
#endif

LIB_TextureTransfer_C_API 
bool MW_CALL_CONV TextureTransferInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
  if (_mcr_inst != NULL)
    return true;
  if (!mclmcrInitialize())
    return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream((void *)(TextureTransferInitializeWithHandlers));
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(   &_mcr_inst,
                                                                error_handler, 
                                                                print_handler,
                                                                ctfStream);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
  return true;
}

LIB_TextureTransfer_C_API 
bool MW_CALL_CONV TextureTransferInitialize(void)
{
  return TextureTransferInitializeWithHandlers(mclDefaultErrorHandler, 
                                               mclDefaultPrintHandler);
}

LIB_TextureTransfer_C_API 
void MW_CALL_CONV TextureTransferTerminate(void)
{
  if (_mcr_inst != NULL)
    mclTerminateInstance(&_mcr_inst);
}

LIB_TextureTransfer_C_API 
void MW_CALL_CONV TextureTransferPrintStackTrace(void) 
{
  char** stackTrace;
  int stackDepth = mclGetStackTrace(&stackTrace);
  int i;
  for(i=0; i<stackDepth; i++)
  {
    mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
    mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
  }
  mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_TextureTransfer_C_API 
bool MW_CALL_CONV mlxCut(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "cut", nlhs, plhs, nrhs, prhs);
}

LIB_TextureTransfer_C_API 
bool MW_CALL_CONV mlxDemo(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "Demo", nlhs, plhs, nrhs, prhs);
}

LIB_TextureTransfer_C_API 
bool MW_CALL_CONV mlxFind_mindelta(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "find_mindelta", nlhs, plhs, nrhs, prhs);
}

LIB_TextureTransfer_C_API 
bool MW_CALL_CONV mlxGet_ssd(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "get_ssd", nlhs, plhs, nrhs, prhs);
}

LIB_TextureTransfer_C_API 
bool MW_CALL_CONV mlxTexture_transfer(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[])
{
  return mclFeval(_mcr_inst, "texture_transfer", nlhs, plhs, nrhs, prhs);
}

LIB_TextureTransfer_CPP_API 
void MW_CALL_CONV cut(int nargout, mwArray& imout, const mwArray& sample, const mwArray& 
                      patchsize, const mwArray& overlap, const mwArray& imout_in1, const 
                      mwArray& samplepos, const mwArray& imoutpos)
{
  mclcppMlfFeval(_mcr_inst, "cut", nargout, 1, 6, &imout, &sample, &patchsize, &overlap, &imout_in1, &samplepos, &imoutpos);
}

LIB_TextureTransfer_CPP_API 
void MW_CALL_CONV Demo(int nargout, mwArray& imout3)
{
  mclcppMlfFeval(_mcr_inst, "Demo", nargout, 1, 0, &imout3);
}

LIB_TextureTransfer_CPP_API 
void MW_CALL_CONV find_mindelta(int nargout, mwArray& mintexturepos, const mwArray& 
                                texture, const mwArray& target, const mwArray& targetpos, 
                                const mwArray& patchsize, const mwArray& tol)
{
  mclcppMlfFeval(_mcr_inst, "find_mindelta", nargout, 1, 5, &mintexturepos, &texture, &target, &targetpos, &patchsize, &tol);
}

LIB_TextureTransfer_CPP_API 
void MW_CALL_CONV get_ssd(int nargout, mwArray& cost, const mwArray& texture, const 
                          mwArray& texturepos1, const mwArray& texturepos2, const 
                          mwArray& targetposnew, const mwArray& patchsize)
{
  mclcppMlfFeval(_mcr_inst, "get_ssd", nargout, 1, 5, &cost, &texture, &texturepos1, &texturepos2, &targetposnew, &patchsize);
}

LIB_TextureTransfer_CPP_API 
void MW_CALL_CONV texture_transfer(int nargout, mwArray& imout, const mwArray& texture, 
                                   const mwArray& target, const mwArray& patchsize, const 
                                   mwArray& overlap, const mwArray& tol)
{
  mclcppMlfFeval(_mcr_inst, "texture_transfer", nargout, 1, 5, &imout, &texture, &target, &patchsize, &overlap, &tol);
}

