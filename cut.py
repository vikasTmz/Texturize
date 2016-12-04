from smop.core import *
import numpy as np
import cv2
import scipy
import math
from scipy import ndimage

    
@function
def cut(sample,patchsize,overlap,imout,samplepos,imoutpos):

    samplesz=size(sample)
    sampledms=length(samplesz)


    line15junk = sample[samplepos[1] + overlap-1:samplepos[1] + patchsize - 2,samplepos[2] + overlap-1:samplepos[2] + patchsize - 2,:]

    imout[imoutpos[0] + overlap-1:imoutpos[0] + patchsize - 2,imoutpos[1] + overlap-1:imoutpos[1] + patchsize - 2,:] = line15junk

    imoutsz=size(imout)

    imoutdms=length(imoutsz)

    samplet=np.zeros((patchsize,overlap))

    imoutt=np.zeros((patchsize,overlap))

    delta=np.zeros((patchsize,overlap))


    if sampledms == 2:
        samplet[:,:]=sample[samplepos[1]-1:samplepos[1] + patchsize - 1,samplepos[2]-1:samplepos[2] + overlap - 1]

    else:
        for k in xrange(0,samplesz[3]):
            samplet[:,:]=samplet[:,:] + sample[samplepos[1]-1:samplepos[1] + patchsize - 1,samplepos[2]-1:samplepos[2] + overlap - 1,k]

    
    if imoutdms == 2:
        imoutt[:,:]=imout[imoutpos[0]-1:imoutpos[0] + patchsize - 1,imoutpos[1]-1:imoutpos[1] + overlap - 1]

    else:
        for p in xrange(0,imoutsz[3]):
            imoutt[:,:]=imoutt[:,:] + imout[imoutpos[0]:imoutpos[0] + patchsize ,imoutpos[1]:imoutpos[1] + overlap,p]

    
    delta[:,:]=samplet[:,:] - imoutt[:,:]

    delta[:,:]=abs(delta[:,:])

    ddelta=np.zeros((patchsize,overlap))

    ddelta[1,:]=delta[1,:]

    for i in xrange(1,patchsize):
        for j in xrange(0,overlap):
            if j == 1:
                ddelta[i,1]=delta[i,0] + numpy.minimum( delta[i - 1,1], delta[i - 1,1])

            else:
                if j == overlap-1:
                    ddelta[i,overlap-1]=delta[i,overlap-1] + numpy.minimum(delta[i - 1,overlap - 2],delta[i - 1,overlap-1])

                else:
                    ddelta[i,j]=delta[i,j] + numpy.minimum(numpy.minimum(delta[i - 1,j - 1],delta[i - 1,j]),delta[i - 1,j + 1])

    
    cutarr=np.zeros((patchsize,1))


    cutarr[patchsize-1]=find(ddelta[patchsize-1,:] == np.amin(ddelta[patchsize-1,:]),0)

    for i in xrange(patchsize-1,0,-1):
        if cutarr[i,0] == 1:
            temp=matlabarray(ddelta[i - 1,0],ddelta[i - 1,1])

            cutarr[i - 1]=find(temp == np.amin(temp),0)

        else:
            if cutarr[i] == overlap-1:
                temp=matlabarray(ddelta[i - 1,overlap-1],ddelta[i - 1,overlap - 2])

                cutarr[i - 1]=overlap + 1 - find(temp == np.amin(temp),0)

            else:
                temp=matlabarray(ddelta[i - 1, int(cutarr[i]) - 3], ddelta[i - 1,int(cutarr[i])-2])
                cutarr[i - 1]=cutarr[i] - 2 + find(temp == np.amin(temp),0)

    
    for i in xrange(0,patchsize):
        imout[imoutpos[0] + i-1,imoutpos[1] + cutarr[i] - 1:imoutpos[1] + overlap - 1,:]=sample[samplepos[1] + i-1,samplepos[2] + cutarr[i] - 1:samplepos[2] + overlap - 1,:]

    
    samplet=np.zeros((overlap,patchsize))

    imoutt=np.zeros((overlap,patchsize))

    delta=np.zeros((overlap,patchsize))

    if sampledms == 2:
        samplet[:,:]=sample[samplepos[1]-1:samplepos[1] + overlap - 1,samplepos[2]-1:samplepos[2] + patchsize - 1]

    else:
        for k in xrange(0,samplesz[3]):
            samplet[:,:]=samplet[:,:] + sample[samplepos[1]-1:samplepos[1] + overlap - 1,samplepos[2]-1:samplepos[2] + patchsize - 1,k]

    
    if imoutdms == 2:
        imoutt[:,:]=imout[imoutpos[0]:imoutpos[0] + overlap - 1,imoutpos[1]:imoutpos[1] + patchsize - 1]

    else:
        for p in xrange(0,imoutsz[3]):
            imoutt[:,:]=imoutt[:,:] + imout[imoutpos[0]:imoutpos[0] + overlap ,imoutpos[1]:imoutpos[1] + patchsize,p]

    
    delta[:,:]=samplet[:,:] - imoutt[:,:]

    delta[:,:]=abs(delta[:,:])

    ddelta=np.zeros((overlap,patchsize))

    ddelta[:,1]=delta[:,1]

    for i in xrange(1,patchsize):
        for j in xrange(0,overlap):
            if j == 1:
                ddelta[1,i]=delta[1,i] + numpy.minimum(delta[1,i - 1],delta[2,i - 1])

            else:
                if j == overlap-1:
                    ddelta[overlap-1,i]=delta[overlap-1,i] + numpy.minimum(delta[overlap - 2,i - 1],delta[overlap-1,i - 1])

                else:
                    ddelta[j,i]=delta[j,i] + numpy.minimum(numpy.minimum(delta[j - 1,i - 1],delta[j,i - 1]),delta[j + 1,i - 1])

    
    cutarr=np.zeros((patchsize,1))

    cutarr[patchsize-1]=find(ddelta[:,patchsize-1] == np.amin(ddelta[:,patchsize-1]),0)

    for i in xrange(patchsize-1,0,-1):
        if cutarr[i] == 1:
            temp=matlabarray(ddelta[1,i - 1],ddelta[2,i - 1])

            cutarr[i - 1]=find(temp == np.amin(temp),0)

        else:
            if cutarr[i] == overlap-1:
                temp=matlabarray(ddelta[overlap-1,i - 1],ddelta[overlap - 2,i - 1])

                cutarr[i - 1]=overlap + 1 - find(temp == np.amin(temp),0)

            else:
                temp=matlabarray(ddelta[int(cutarr[i]) - 2,i - 1],ddelta[int(cutarr[i])-1,i - 1])

                cutarr[i - 1]=cutarr[i] - 2 + find(temp == np.amin(temp),0)

    
    for i in xrange(0,patchsize-1):
        imout[imoutpos[0] + cutarr[i] - 1:imoutpos[0] + overlap - 1,imoutpos[1] + i,:]=sample[samplepos[1] + cutarr[i] - 1:samplepos[1] + overlap - 1,samplepos[2] + i,:]

    return imout