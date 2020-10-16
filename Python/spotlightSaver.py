# -*- coding: utf-8 -*-
"""
Created on Fri Oct  9 10:35:47 2020

@author: igorm
"""

import os
import shutil

source = "/Users/igorm/AppData/Local/Packages/Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy/LocalState/Assets/"
dest = "/Spotlights/"

files = os.listdir(source)
files.sort()
for f in files:
    src = source + f
    if os.path.getsize(src) > 150000:
        shutil.copy(src,dest)
files = os.listdir(dest)

count = 1
for x in files:
    src = dest + x
    os.rename(src, dest + str(count) + '.jpg')
    count += 1