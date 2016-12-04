from smop.core import *

    
@function
def get_ssd(texture=None,texturepos1=None,texturepos2=None,targetposnew=None,patchsize=None,*args,**kwargs):
    varargin = get_ssd.varargin
    nargin = get_ssd.nargin

    temparr=texture[texturepos1:texturepos1 + patchsize - 1,texturepos2:texturepos2 + patchsize - 1,:] - targetposnew
# ../../ImageQuilting/get_ssd.m:3
    temparr=multiply(temparr[:,:,:],temparr[:,:,:])
# ../../ImageQuilting/get_ssd.m:4
    cost=sum(sum(sum(temparr)))
# ../../ImageQuilting/get_ssd.m:6