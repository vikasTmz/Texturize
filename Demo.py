from smop.core import *
import numpy as np
import cv2
import scipy
from scipy import ndimage
from texture_transfer import texture_transfer

texture=cv2.imread('../MyTextures/code.png')
target= cv2.imread('../Targetimages/data/martinimgs/0.png')

texture = scipy.misc.imresize(texture, 0.2)
texture = cv2.normalize(texture.astype('float'), None, 0.0, 1.0, cv2.NORM_MINMAX)
target = scipy.misc.imresize(target, 0.2)
target = cv2.normalize(target.astype('float'), None, 0.0, 1.0, cv2.NORM_MINMAX)

# texture=double(texture)
patchsize=10
overlap=3
tol=0.1

print size(texture) , size(target)
    
imout3 = texture_transfer(texture,target,patchsize,overlap,tol)

imout3 = imout3 * 255;

cv2.imwrite( "./OUTImage.png", imout3 );

# imwrite(imout3,'0014_helix.png')
