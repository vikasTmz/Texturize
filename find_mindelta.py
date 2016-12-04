from smop.core import *
import numpy as np
import cv2
import scipy
import math
from scipy import ndimage
from random import randint

@function
def find_mindelta(texture=None,target=None,targetpos=None,patchsize=None,tol=None):

    sizetexture=size(texture)
    sizetexture=sizetexture[1:2]

    ssdarr=zeros(sizetexture[1] - patchsize + 1,sizetexture[2] - patchsize + 1)

    targetposnew = target[targetpos[0]:targetpos[0]+patchsize-1, targetpos[1]:targetpos[1]+patchsize-1, :]

    if (size(targetposnew)[2] != patchsize-1):
        temptargetposnew = np.zeros((patchsize-1,patchsize-1,3))
        temptargetposnew[0:size(targetposnew)[1],0:size(targetposnew)[2],:] = targetposnew
        targetposnew = temptargetposnew

    if (size(targetposnew)[1] != patchsize-1):
        temptargetposnew = np.zeros((patchsize-1,patchsize-1,3))
        temptargetposnew[0:size(targetposnew)[1],0:size(targetposnew)[2],:] = targetposnew
        targetposnew = temptargetposnew
    
    for i in xrange(0,sizetexture[1] - patchsize + 1):
        for j in xrange(0,sizetexture[2] - patchsize + 1):

            temparr=texture[i:i + patchsize-1,j:j + patchsize-1,:] - targetposnew
            temparr=multiply(temparr[:,:,:],temparr[:,:,:])
            cost=sum(sum(sum(temparr)))


            if cost == 0:
                ssdarr[i,j]=10000000000

            else:
                ssdarr[i,j]=cost


    sizessd = size(ssdarr)
    sizessd = [int(x) for x in np.nditer(sizessd)]

    minssd=min(min(ssdarr))

    min_mat=np.tile(minssd,sizessd)

    d_mat=dot(min_mat,(1 + tol)) - ssdarr

    temp_x,temp_y=find(d_mat > 0,nargout=2)
    
    randindex= randint(1,int(size(temp_x)[1]))
    
    return matlabarray(cat(temp_x[randindex],temp_y[randindex]))
