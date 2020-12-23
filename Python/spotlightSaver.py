# -*- coding: utf-8 -*-
"""
Created on Fri Oct  9 10:35:47 2020

@author: igorm
"""

import os
import shutil
from PIL import Image

def getPixels(fpath):
    width, height = Image.open(fpath).size
    return width, height

source = "/Users/igorm/AppData/Local/Packages/Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy/LocalState/Assets/"
dest = "/Spotlights/"

files = os.listdir(source)
files.sort()

for f in files:
    src = source + f
    if Image.open(src).size == (1920,1080): #checks if the image is correct orientation before copying it over
        shutil.copy(src,dest)

files = os.listdir(dest)
files.sort()

#getcount from largest filename in spotlights folder
count = 1
for x in files:
    src = dest + x
    if os.path.isfile(dest + str(count)):
        while(os.path.isfile(dest + str(count))):
            count += 1
    os.rename(src, dest + str(count) + '.jpg')
    count += 1
    
"""
TODO:
    remove dupe images
"""