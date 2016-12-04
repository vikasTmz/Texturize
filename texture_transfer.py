from smop.core import *
import numpy as np
import cv2
import scipy
import math
from scipy import ndimage
from find_mindelta import find_mindelta
from cut import cut

    
@function
def texture_transfer(texture,target,patchsize,overlap,tol):

    outsize= size(target)
    outsize= [outsize[1],outsize[2]]

    xtrim = patchsize - ( outsize[1] - ((patchsize-overlap) * math.floor((outsize[1]-patchsize)/(patchsize-overlap)) + 1 + patchsize-overlap) );
    ytrim = patchsize - ( outsize[0] - ((patchsize-overlap) * math.floor((outsize[0]-patchsize)/(patchsize-overlap)) + 1 + patchsize-overlap) );


    outsize_ = outsize
    outsize_[0] = outsize_[0] + ytrim ; outsize_[1] = outsize_[1] + xtrim;

    if (size(target)[3] == 1):
        imout = np.zeros((outsize_))

    else:
        imout= np.zeros((int(outsize_[0]),int(outsize_[1]),int(size(target)[3])))

    for i in xrange(0, outsize_[0]-patchsize+1 ,patchsize-overlap):
        print i
        for j in xrange(0, outsize_[1]-patchsize+1 ,patchsize-overlap):
            if (i == 0 and j == 0):
                pos=find_mindelta(texture,target,[0,0],patchsize,tol)
                imout[i:i + patchsize - 1,j:j + patchsize - 1,:] = texture[int(pos[1]):int(pos[1]) + patchsize - 1,int(pos[2]):int(pos[2]) + patchsize - 1,:]

            else:
                if (i > outsize[0] - patchsize + 1):
                    i_new=outsize[0] - patchsize + 1

                else:
                    i_new=copy(i)

                if (j > outsize[1] - patchsize + 1):
                    j_new=outsize[1] - patchsize + 1

                else:
                    j_new=copy(j)

                currentpos=[i_new,j_new]

                patchpos=find_mindelta(texture,target,currentpos,patchsize,tol)

                imout=cut(texture,patchsize,overlap,imout,patchpos,currentpos)

    # imout=imout[1:outsize[1],1:outsize[2],:]
    return imout